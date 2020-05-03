#include <iostream>
#include "include/SkipList.h"

using namespace std;
void reserveTicket(SkipList& reservationList){ //Function that makes a reservation.
    Node* firstAvailableSeat = reservationList.getFirstEmptyKey(50); //Gets the first seat
    if(firstAvailableSeat != nullptr){ //Checks if there are empty seats
        string name;
        cout<<"Enter your name: ";
        cin.ignore();
        getline(cin, name);
        if(reservationList.search(name) == nullptr){ //Checks if the name is unique
            while(firstAvailableSeat->getBelow() != nullptr){
                firstAvailableSeat->setName(name);
                firstAvailableSeat = firstAvailableSeat->getBelow();
            }
            firstAvailableSeat->setName(name);
        } else {
            cout<<"\n *** A reservation was already made on this name! *** \n\n";
        }

    } else {
        cout<<"\n *** All seats are occupied! ***\n\n";
    }



}

void checkReservation(SkipList& reservationList, bool deleteReservation){
    string input;
    Node* search;
    cout<<"Enter check method (name/id): ";
    cin.ignore();
    getline(cin, input);

    if(input == "name"){
        string nameInput;
        cout<<"Enter your name: ";
        getline(cin, nameInput);

        search = reservationList.search(nameInput);
    } else {
        int idInput;
        cout<<"Enter your id: ";
        cin>>idInput;
        search = reservationList.search(idInput);
    }
    if(search != nullptr and search->getName() != "None"){
        if(deleteReservation == false){ //Checks if the reservation exists, if it exists and delete is set to false, it will just print it.
            cout<<"\n*** Reservation found! Seat: "<<search->getKey()<<", Name: "<<search->getName()<<" ***\n\n";
        } else { //If DELETE is set to on, it removes the reservation.
            while(search->getBelow() != nullptr){
                search->setName("None");
                search = search->getBelow();
            }
            search->setName("None");
            cout<<"\n*** Reservation deleted! ***\n\n";
        }
    } else {
        cout<<"\n *** Reservation not found! ***\n\n";
    }


}

void reservationProgram(SkipList& reservationList){ //Main function of the program
    cout<<"*** Airline Reservation System ***\n";
    for(int i=1; i<=50;i++){
        reservationList.insert(i,"None"); //Creates 50 nodes in the list, each of them being a seat
    }
    int userInput;
    while(true){ //Main loop of the program where it takes user input.
        cout<<"1 - Reserve Ticket | 2 - Cancel Reservation | 3 - Check Reservation | 4 - List Passangers | 0 - Exit\n";
        cout<<"Chose an option: ";
        cin>>userInput;
        switch (userInput) {
            case 1:
                reserveTicket(reservationList);
                break;
            case 2:
                checkReservation(reservationList, true);
                break;
            case 3:
                checkReservation(reservationList, false);
                break;
            case 4:
                reservationList.printList();
                break;
            default:
                break;

        }
        if(userInput == 0){
            break;
        }

    }
}





int main() {
    SkipList reservationList(5); //Get a skip list.
    reservationProgram(reservationList); //Pass it by reference


}
