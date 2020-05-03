//
// Created by Pop Rosian on 27/04/2020.
//

#include <iostream>
#include "SkipList.h"

SkipList::SkipList(int maxLevel) {
    this->maxLevel = maxLevel;
    for(int i=0;i<maxLevel;i++){
        Node* newNode = new Node();
        newNode->setNext(nullptr);
        if(i==0){
            newNode->setBelow(nullptr);
        } else {
            newNode->setBelow(this->lastAdded);
        }
        newNode->setKey(-1);
        this->lastAdded = newNode;
        this->sentinel.push_back(newNode);
    }
    this->head = lastAdded;
}

int SkipList::getRandomLevels() const { //This basically simulates a coin flip.
    int level = 0;
    srand(time(NULL) + rand());
    int randomValue = rand() % 2; //Gets a random value between 0-1 (0-heads, 1-tails)
    while(randomValue == 1 and level < maxLevel-1){ //If it lands on tails
        level++;//Increases the number of levels the node is on.
        srand(time(NULL) + rand());
        randomValue = rand() % 2; //Flips again.
    }
    return level;
}

bool SkipList::insert(int key, const string& reservationName) {
    Node* current = this->head;
    this->lastAdded = nullptr;
    int insertLevels = getRandomLevels(); //Gets the levels the node will be inserted on
    for(int i=maxLevel-1;i>=0;i--){ //For each level, it does the insertion
        if(i <= insertLevels){ //Checks if the node should be inserted on that level
            while (true){
                if(current->getNext() == nullptr or current->getNext()->getKey() > key){
                    Node* newNode = new Node();
                    newNode->setKey(key);
                    newNode->setName(reservationName);
                    newNode->setNext(current->getNext());
                    current->setNext(newNode);
                    if(this->lastAdded != nullptr){
                        lastAdded->setBelow(newNode);
                    }
                    this->lastAdded = newNode;
                    break;
                } else if(current->getNext()->getKey() == key) {
                    return false;
                    break;
                } else {
                    current = current->getNext();
                }
            }

        }

        current = current->getBelow();
    }
    return true;
}

void SkipList::printSkipList() const {
    cout<<"*** SKIP LIST ***\n";
    for(int i=this->maxLevel-1;i>=0;i--){
        Node* current = this->sentinel[i];
        cout<<"LEVEL "<<i<<": ";
        while(current->getNext() != nullptr){
            cout<<current->getKey()<<" ";
            current = current->getNext();
        }
        cout<<current->getKey()<<" ";
        cout<<endl;
    }
}

void SkipList::printList() const {
    Node* current = this->sentinel[0];
    while(current->getNext() != nullptr){
        if(current->getKey() != -1){
            cout<<"Seat #: "<<current->getKey()<<", Passenger: "<<current->getName()<<endl;
        }

        current = current->getNext();
    }
    cout<<"Seat #: "<<current->getKey()<<", Passenger: "<<current->getName()<<endl;
}

Node * SkipList::search(int key) const{ //Searching by key is as fast as it can be.
    Node* current = this->head;
    for(int i=maxLevel-1;i>=0;i--){
            while (true){
                if(current->getKey() == key){
                    return current;
                } else if (current->getNext() == nullptr){
                    break;
                } else if (current->getNext() != nullptr and current->getNext()->getKey() <= key) {
                    current = current->getNext();
                } else {
                    break;
                }
            }
        current = current->getBelow();
    }
    return nullptr;
}

Node * SkipList::remove(int key) {
    Node* current = this->head;

    Node* prev;
    for(int i=maxLevel-1;i>=0;i--){
        while (true){
            if(current->getKey() == key){
                current = prev;
                Node* toDelete = current->getNext();
                current->setNext(current->getNext()->getNext());
                delete toDelete;
                break;
            } else if (current->getNext() == nullptr){
                break;
            } else if (current->getNext() != nullptr and current->getNext()->getKey() <= key) {
                prev = current;
                current = current->getNext();
            } else {
                break;
            }
        }
        current = current->getBelow();
    }
    return nullptr;


}

bool SkipList::reserveTicket(string name) {

}

Node* SkipList::getFirstEmptyKey(int length) const {
    Node* node;
    for(int i=1;i<=length;i++){
        node = this->search(i);
        if(node->getName() == "None"){
            return node;
        }
    }
    return nullptr;
}

Node *SkipList::search(string name) { //Searching by name is not that efficient.
    for(int i=this->maxLevel-1;i>=0;i--){
        Node* current = this->sentinel[i];
        while(current->getNext() != nullptr){
            if(current->getKey() != -1){
                if(current->getName() == name){
                    return current;
                }
            }

            current = current->getNext();
        }
        if(current->getKey() != -1){
            if(current->getName() == name){
                return current;
            }
        }
    }
    return nullptr;
}

