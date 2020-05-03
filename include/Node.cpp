//
// Created by Pop Rosian on 27/04/2020.
//

#include "Node.h"


void Node::setKey(int key) {
    this->key = key;
}

int Node::getKey() {
    return this->key;
}

void Node::setNext(Node * newNode) {
    this->next = newNode;
}

Node * Node::getNext() {
    return this->next;
}

void Node::setBelow(Node * newNode) {
    this->below = newNode;
}

Node * Node::getBelow() {
    return this->below;
}

void Node::setName(string personName) {
    this->reservationName = personName;
}

string Node::getName() {
    return this->reservationName;
}
