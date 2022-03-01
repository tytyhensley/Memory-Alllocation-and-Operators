//
//  SET.h
//  Homework1
//
//  Created by Ty-Ty Hensley on 3/5/18.
//  Copyright © 2018 NYUAD. All rights reserved.
//

#ifndef SET_h
#define SET_h

#include <iostream>

class Set{  // Set class
public:
    Set();
    Set(int n);
    Set(Set const &a);
    ~Set();
    int Card ();
    void AddElem (int n);
    void RmvElem();
    bool Member (int n);
    void Copy (Set &n);
    bool Equal (Set n);
    Set Intersect (Set n);
    Set Union (Set n);
    void Print ();
    
    Set& operator =(Set const& a) { // Assignment operator
        MaxCard=a.MaxCard;
        Elem= new int[MaxCard];
        for(int i=0; i<a.count; i++){
            Elem[i]=a.Elem[i];
            count++;
        }
        return *this;
    }
    
    bool operator &(int n) {//& operator declaration (verifies if member is in set)
        bool y;
        for (int i=0; i<count; i++) {
            if(Elem[i] == n){
                y=true;
                break;
            }
        }
        return y;
    }
    
    bool operator ==(Set n) {//== operator declaration (verifies if two sets are qual)
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
    
    bool operator !=(Set n){//!= operator declaration (verifies if two sets are unequal)
        bool y=true;
        if(count==n.Card()){
            for (int i=0; i<count; i++){
                if(n.Member(Elem[i])==false) {
                    y=true;
                    break;
                }
                else{
                    y=false;
                }
            }
        }
        return y;
    }
    
    Set operator *(Set n){ //* operator declaration (computes the inersection of two sets)
        Set a;
        for (int i=0; i<count; i++){
            if(n.Member(Elem[i])) {
                a.AddElem(Elem[i]);
            }
        }
        return a;
    }
    
    Set operator +(Set n){//+ operator declaration (computes the union of two sest)
        Set a;
        for (int i=0; i<count; i++){
            if(n.Member(Elem[i])==false) {
                a.AddElem(Elem[i]);
            }
        }
        n.Copy(a);
        return a;
    }
    
    Set operator -(Set n){ //- operator declaration (computes the differecne of two sets)
        Set a;
        for (int i=0; i<count; i++){
            if(n.Member(Elem[i])==false) {
                a.AddElem(Elem[i]);
            }
        }
        for (int i=0; i<n.count; i++){
            for(int x=0; x<count; x++){
                if((n.Elem[i])==Elem[x]) {
                    break;
                }
                if((n.Elem[i])!=Elem[x]) {
                    a.AddElem(n.Elem[i]);
                    break;
                }
            }
        }
        return a;
    }
    
    bool operator <=(Set &n){// <= operator declaration (verifies if a set is the subset of another)
        bool y=true;
        for (int i=0; i<count; i++){
            if(n.Member(Elem[i])==false) {
                y=false;
                break;
            }
        }
        return y;
    }
    
    void operator << (Set a) {// << operator declaration (display the content of set)
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
    
    Set& operator >>(int n){// >> operator declaration (add a member to a set)
        if (count==MaxCard){
            std::cout<<"The set is full"<<std::endl;
        }
        else{
            Elem[count]=n;
            count++;
        }
        return *this;
    }
private:
    int MaxCard;
    int* Elem;
    int count=0;
    
};



#endif /* SET_h */
