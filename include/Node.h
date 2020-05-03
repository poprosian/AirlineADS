//
// Created by Pop Rosian on 27/04/2020.
//

#ifndef HOMEWORK2_NODE_H
#define HOMEWORK2_NODE_H

#include <string>
using namespace std;

class Node {
    private:
        int key; //Holds the index
        Node* next; //Holds the next node
        Node* below; //Holds the node below it
        string reservationName; //Holds the name of the person
    public: //Getters and setters
        void setKey(int);
        int getKey();
        void setNext(Node*);
        Node* getNext();
        void setBelow(Node*);
        Node* getBelow();
        void setName(string personName);
        string getName();
};


#endif //HOMEWORK2_NODE_H
