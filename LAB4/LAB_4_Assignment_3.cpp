/*Author : RAJ ROY*/
/*Scholar Id = 2212002*/

#include<iostream>
using namespace std;

int main() {
    /*
            (a) Name the operators that cannot be overloaded.
        --> The operators that cannot be overloaded are :: (scope resolution),
            .* (member pointer-to-object), and ?: (ternary conditional).


            (b) What is the difference between the two statements return this; and return *this;?
        --> return this; and return *this; both return a pointer to the current object.
            However, there's a difference in what they represent. return this; returns a pointer 
            to the current object as it is, while return *this; 
            dereferences the pointer and returns the object itself.


            (c) What is the difference between a friend function of a class and a member function of
            a class?
        --> A member function of a class is a function that is part of the class
            and can access the class's private members. 
            A friend function, on the other hand, is not a member of the class but is declared as a friend of the class. 
            It can access the private and protected members of the class.



            (d) Which operators must be overloaded as members of a class?
        -->  Operators like assignment (=), subscript ([]), function call (()), 
            and member access (->) must be overloaded as members of a class.



            (e) What is a virtual function and why do we need it?
        --> A virtual function is a function in a base class that is declared using the virtual keyword 
            and is intended to be overridden by derived classes. It allows polymorphism, 
            enabling a program to choose the appropriate function implementation at runtime based on the actual type of the object.
        


            (f) Explain, with an example, how you would create space for an array of objects using
            pointers.
        --> To create space for an array of objects using pointers, 
            you can dynamically allocate memory using the new keyword.


            (g) What does this pointer point to?
        --> The this pointer points to the object for which the member function is called. 
            It is a constant pointer that holds the memory address of the current object.



            (h) What are the applications of this pointer?
        -->  Applications of the this pointer:
            1.Differentiating between local and member variables in member functions.
            2.Returning the object itself from a member function for chaining method calls.
            3.Enabling the comparison of an object with itself within the class.
            4.Facilitating the implementation of overloaded assignment operators.
        
    */



}
