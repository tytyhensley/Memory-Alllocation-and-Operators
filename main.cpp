//
//  main.cpp
//  Homework1
//
//  Created by Ty-Ty Hensley on 3/1/18.
//  Copyright © 2018 NYUAD. All rights reserved.
//
#include "SET.h"
#include "SET functions.h"

int main() {
    Set a; //default constructor
    Set b(5); //constructor with argument
    
    b.AddElem(3); //add element function
    b.AddElem(5);
    std::cout<<b.Card()<<std::endl;//card function (result should be 2)
    
    b.Copy(a); //copy function
    std::cout<<a.Equal(b)<<std::endl;//equal function (result should be 1)
    
    a.AddElem(6);
    a.RmvElem(); //remove element fucntion
    std::cout<<a.Member(3)<<std::endl;//member function (result should be 0)
    
    Set c;
    c=a.Intersect(b);//intersect function (result should be {5})
    c.Print();//print function
    
    
    c=a.Union(b); //union function (result should be {6,3,5})
    c.Print();
    
    Set d(a);//copy constrcutor
    Set e;
    e=b;//assignment operator
    
    std::cout<<(a==d)<<std::endl; //== operator overload (result should be 1)
    std::cout<<(e!=b)<<std::endl; //!= operator overload (result should be 0)
    
    b>>9;//>> operator overload
    std::cout<<(b&9)<<std::endl; //& operator overload (result should be 1)
    
    std::cout<<(e<=b)<<std::endl;// <= operator overload (result should be 1)
    
    Set p;
    p=a-b;// - operator overload
    p<<(p);// << operator overload (result should be {3,6,9})
    
    p=e*d;// * operator overload (result should be {5} )
    p.Print();
    
    p=e+d;// + overload operator (result should be {6, 3, 5} )
    p.Print();
    
}
