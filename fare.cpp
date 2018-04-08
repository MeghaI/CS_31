//
//  main.cpp
//  project2
//
//  Created by Megha Ilango on 10/15/17.
//  Copyright © 2017 Megha Ilango. All rights reserved.
//

#include <iostream>
#include <string>
using namespace std;


int main(){
    //setting precision for output statements
    cout.setf(ios::fixed);
    cout.precision(2);
    
    //collecting and storing user inputs
    cout << "Age of rider: ";
    int age;
    cin >> age;
    
    cin.ignore(10000, '\n');
    cout << "Student? (y/n): ";
    string student;
    getline(cin, student);
    
    cout << "Destination: ";
    string destination;
    getline(cin, destination);
    
    cout << "Number of zone boundaries crossed: ";
    int zoneBoundaries;
    cin >> zoneBoundaries;
    
    cout << "---\n";
    
    //calculating fare, determining what message to display
    
    double fare = 1.35 + 0.55*zoneBoundaries;
    if(age<0){
        cout << "The age must not be negative";
    }else if(student!="n" && student!="y"){
        cout << "You must enter y or n";
    }else if(destination==""){
        cout << "You must enter a destination";
    }else if (zoneBoundaries<0){
        cout << "The number of zone boundaries crossed must not be negative";
    }else if((age<18 || student=="y") && (zoneBoundaries==0 || zoneBoundaries==1)){ //this is before the age>=65, so if seniors are students they will get student discount
        fare = 0.65;
        if(age>=65 && zoneBoundaries==0) fare = 0.55;
        cout << "The fare to " << destination << " is $" << fare;
    }else if(age>=65){
        fare = 0.55 + 0.25*zoneBoundaries;
        if(zoneBoundaries==0) fare = 0.45;
        cout << "The fare to " << destination << " is $" << fare;
    }else{
        cout << "The fare to " << destination << " is $" << fare;
    }
}