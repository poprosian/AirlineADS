//
// Created by Pop Rosian on 27/04/2020.
//

#ifndef HOMEWORK2_SKIPLIST_H
#define HOMEWORK2_SKIPLIST_H


#include "Node.h"
#include <vector>
#include <cstdlib>
#include <ctime>
using namespace std;

class SkipList {
    private:
        vector<Node*> sentinel; //A vector of sentinels for each level
        Node* head; // Head node, will always be at the sentinel of the highest level
        Node* lastAdded; // A node to check which node was last added in a level, useful for insertion
        int maxLevel; // The max level of the list
    public:
        explicit SkipList(int); // Constructor, creates a list of int levels
        int getRandomLevels() const; // For each insert operation, tells you on what levels will the node appear
        bool insert(int, const string&);
        Node* search(int) const;
        Node* search(string);
        Node* remove(int);
        void printSkipList() const; //Prints the skip list, with the levels.


        //Reservation-Related
        void printList() const; //Prints the lowest level
        //If we have 5 seats, Seat 1,2,3 are occupied. Seat 2 cancels. getFirstEmptyKey will get seat 2 to place the next reservation.
        Node* getFirstEmptyKey(int) const;
        bool reserveTicket(string name);
};


#endif //HOMEWORK2_SKIPLIST_H
