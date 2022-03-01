//
//  SET functions.h
//  Homework1
//
//  Created by KIOSK on 3/5/18.
//  Copyright © 2018 NYUAD. All rights reserved.
//

#ifndef SET_functions_h
#define SET_functions_h

#include "SET.h"

Set::Set () { // Default constructor
    MaxCard = 10;
    Elem= new int[MaxCard];
}

Set::Set(int n) { // Constructor with an argument
    MaxCard=n;
    Elem= new int[MaxCard];
}

Set::Set(Set const&a) {//Copy constructor
    MaxCard=a.MaxCard;
    Elem= new int[MaxCard];
    for(int i=0; i<a.count; i++){
        Elem[i]=a.Elem[i];
        count++;
    }
    
}

Set::~Set() { //Destructor
    delete [] Elem;
}

void Set:: AddElem( int n) { //Adds a member to the set
    if (count==MaxCard){
        std::cout<<"The set is full, "<<n<<" cannot be added"<<std::endl;
    }
    else{
        Elem[count]=n;
        count++;
    }
}

void Set:: RmvElem () { //Removes the first memeber from the set
    if (count==0) {
        std::cout<<"The set is empty, cannot remove anymore elements"<<std::endl;
    }
    else
    {
        for (int i=0; i<count; i++) {
            Elem[i]=Elem[i+1];
        }
    }
    count--;
}

int Set::Card () { //Returns the number of elements within a set
    return count;
}

bool Set::Member (int n) { //Tests if a number is a memeber of the set
    bool y=false;
    for (int i=0; i<count; i++) {
        if(Elem[i] == n){
            y=true;
            break;
        }
    }
    return y;
}

void Set::Copy(Set &n) { //Copies one set to another
    for (int i=0; i<count; i++) {
        n.AddElem(Elem[i]);
    }
}

bool Set::Equal (Set n) { //Tests if two sets are equal
    bool y;
    if(count==n.Card()){
        for (int i=0; i<count; i++){
            if(n.Member(Elem[i])==false) {
                y=false;
                break;
            }
            else{
                y=true;
            }
        }
    }
    return y;
}

Set Set::Intersect (Set n) {//Returns a set containing the intersection of two sets
    Set a(MaxCard);
    for (int i=0; i<count; i++){
        if(n.Member(Elem[i])==true) {
            a.AddElem(Elem[i]);
        }
    }
    return a;
}

Set Set::Union (Set n) {//Returns a set that contains the union of two sets
    Set a(count+n.count);
    for (int i=0; i<count; i++){
        if(n.Member(Elem[i])==false) {
            a.AddElem(Elem[i]);
        }
    }
    n.Copy(a);
    return a;
}

void Set::Print () {//Displays a set
    if (count==0){
        std::cout<<"{}"<<std::endl;
    }
    else {
        std::cout<<"{";
        for (int i=0; i<count; i++){
            std::cout<<Elem[i]<<",";
        }
        std::cout<<"}"<<std::endl;
    }
}

#endif /* SET_functions_h */
