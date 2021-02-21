//
//  intSet.cpp
//  CS_204_HW5
//
//  Created by Ege Berk Yurtkoruyan on 4.04.2020.
//  Copyright © 2020 Ege Berk Yurtkoruyan. All rights reserved.
//

#include "intSet.h"


/*////////////////////////////////////////////////////////////////////////////////////////////////////////////////////*/

//  Default constructor.
IntegerSet::IntegerSet(){
    
    int_count = 0;
    integer_array = NULL;
}

/*////////////////////////////////////////////////////////////////////////////////////////////////////////////////////*/

//  This function will return the number of integers in the array.
int IntegerSet::int_count_value() const{ return int_count; }

/*////////////////////////////////////////////////////////////////////////////////////////////////////////////////////*/

//  This will return us the integer value at the given point of the array.
int IntegerSet::Array_value(int i) const{ return integer_array[i];}

/*////////////////////////////////////////////////////////////////////////////////////////////////////////////////////*/

//  Deep copy constructor.
IntegerSet::IntegerSet (const IntegerSet & copy){
    
    int_count = copy.int_count_value();
    if (int_count > 0){
        integer_array = new int[copy.int_count_value()];
        for(int i = 0 ; i < int_count ; i ++){
            integer_array[i] = copy.Array_value(i);
        }
    }else{
        integer_array = NULL;
    }
}

/*////////////////////////////////////////////////////////////////////////////////////////////////////////////////////*/

//  Constructor with an int as referance. will push the integers up to the given integer.
IntegerSet::IntegerSet(int num){
    
    if(num > 0){
        int_count = num;
        integer_array = new int[num];
        for(int i = 0 ; i < num ; i++)
            integer_array[i] = i;
    }else{
        int_count = 0;
        integer_array = NULL;
    }
}

/*////////////////////////////////////////////////////////////////////////////////////////////////////////////////////*/

//  Destructor.
IntegerSet::~IntegerSet(){
    delete[] integer_array;
}

/*////////////////////////////////////////////////////////////////////////////////////////////////////////////////////*/

// this function will return true if the element is in the integer set. this will help me with my other functions.
bool IntegerSet::included(int element){
    
    for(int i = 0 ; i < int_count ; i++){
        if(integer_array[i] == element)
            return true;
    }
    return false;
}

/*////////////////////////////////////////////////////////////////////////////////////////////////////////////////////*/

//  This will return an output stream  which includes the whole set in order to print the Set.
ostream& operator << (ostream & os , IntegerSet & rhs){
    
    os << "{";
    
    for(int i = 0 ; i < rhs.int_count_value() ; i++){
        
        os << rhs.Array_value(i);
        if(i != rhs.int_count_value()-1)
            os <<  ", ";
    }
    
    os << "}";
    return os;
}

/*////////////////////////////////////////////////////////////////////////////////////////////////////////////////////*/

// adds the given integer to the set.
IntegerSet& IntegerSet::operator + (int element){
    
    if(!included(element)){
        int* temp;
        temp = new int[++int_count];
        
        for(int i = 0 ; i < int_count-1 ; i++){
            temp[i] = integer_array[i];
        }
        
        temp[int_count-1] = element;
        
        int* garbage = integer_array;
        integer_array = temp;
        delete[] garbage;
        
        return *this;
    }

    return *this;
}

/*////////////////////////////////////////////////////////////////////////////////////////////////////////////////////*/

//  adds two arrays together to form a bigger array and return it.
const IntegerSet operator + (const IntegerSet & lhs , const IntegerSet & rhs) {
     
    IntegerSet temp(lhs);
    
    for(int i = 0 ; i < rhs.int_count_value() ; i++){
        temp = temp + rhs.Array_value(i);
    }
    
    return temp;
}

/*////////////////////////////////////////////////////////////////////////////////////////////////////////////////////*/

//  return true if the two sets are different.
bool IntegerSet::operator != (const IntegerSet & rhs){
    
    if(int_count != rhs.int_count_value())
        return true;
    
    for(int i = 0 ; i < int_count ; i++){
        if(!included(rhs.Array_value(i)))
            return true;
    }
    return false;
}

/*////////////////////////////////////////////////////////////////////////////////////////////////////////////////////*/

//  return the set of values both sets have.
const IntegerSet IntegerSet::operator * (IntegerSet & rhs){
    
    IntegerSet temp;
    
    for(int i = 0 ; i < int_count ; i ++){
        if(rhs.included(integer_array[i]))
            temp = temp + integer_array[i];
    }
    
    return temp;
}

/*////////////////////////////////////////////////////////////////////////////////////////////////////////////////////*/

//  change left hand side to be same as right hand side. and return the set.
const IntegerSet& IntegerSet::operator = (const IntegerSet & rhs){
    
    if(this != &rhs){
        
        int_count = rhs.int_count_value();
        int* temp = integer_array;
        
        integer_array = new int[int_count];
        
        delete [] temp;
        
        for(int i = 0 ; i < int_count ; i ++){
            integer_array[i] = rhs.Array_value(i);
        }
        
    }
    
    return *this;
    
}

/*////////////////////////////////////////////////////////////////////////////////////////////////////////////////////*/

//  add right hand side to the left hand side.
IntegerSet& IntegerSet::operator += (const IntegerSet & rhs){
    *this = *this + rhs;
    return *this;
}

/*////////////////////////////////////////////////////////////////////////////////////////////////////////////////////*/

//  check if the given integer is included in the set.
bool operator <= (int i, IntegerSet & rhs){
    return rhs.included(i);
}

/*////////////////////////////////////////////////////////////////////////////////////////////////////////////////////*/

//  check if all the elements of left set are in the right set.
bool operator <= (IntegerSet & lhs, IntegerSet & rhs){
    for(int i = 0 ; i < lhs.int_count_value() ; i++){
        if(!rhs.included(lhs.Array_value(i))){
            return false;
        }
    }
    return true;
}

/*////////////////////////////////////////////////////////////////////////////////////////////////////////////////////*/

