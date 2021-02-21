//
//  intSet.h
//  CS_204_HW5
//
//  Created by Ege Berk Yurtkoruyan on 4.04.2020.
//  Copyright © 2020 Ege Berk Yurtkoruyan. All rights reserved.
//

#ifndef intSet_h
#define intSet_h
#include <iostream>

using namespace std;

class IntegerSet {
    
public:
    IntegerSet();
    ~IntegerSet();
    IntegerSet(const IntegerSet &);
    IntegerSet(int);
    IntegerSet& operator + (int);
    bool operator != (const IntegerSet &);
    const IntegerSet& operator =  (const IntegerSet &);
    const IntegerSet operator *  (IntegerSet &);
    IntegerSet& operator += (const IntegerSet & rhs);
    
    bool included(int);
    
    int Array_value(int)const;
    int int_count_value()const;
    
private:
    
    int int_count;
    int *integer_array;
    
};
    
    const IntegerSet operator + (const IntegerSet & lhs , const IntegerSet & rhs)  ;
    ostream & operator << (ostream&, IntegerSet &);
    bool operator <= ( IntegerSet & lhs ,  IntegerSet & rhs);
    bool operator <= (int , IntegerSet & rhs);

#endif /* intSet_h */
