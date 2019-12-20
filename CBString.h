/*
Name: Caleb Brothers
Class: CS132
Section: S
Description: Custom implementation of string class V2. Class creates string
as char arrays whose actual length is tracked and capacity is maintained
in multimples of 20 + 1. The plus 1 being maintained to NULL terminate 
strings properly without the possibility of generating buffer overrun 
problems. 
*/

#ifndef CBSTRING_H
#define CBSTRING_H
#include <iostream>

using namespace std;


class CBString {
   friend istream& operator>>(istream& istr, CBString& argStr);
   //reads from istream to create string
   friend ostream& operator<<(ostream& ostrm, const CBString& argStr);
   //write contents of string to ostream
public:
   CBString(); //default constructor, intitalizes len/ cap to 0. no string.
   CBString(const CBString & mstr); //copy constructor
   CBString(const char* ptr); //constructs string from dynamic memory
   ~CBString(); //deconstructor, free dynamic memory
   int length() const; //returns string length.
   int capacity() const; //returns string capacity(memory reserved)
 
   const char* c_str() const; //returns a const iteration of stored string.
   char operator[](int index) const;//returns character at index value
   CBString& operator=(const CBString& argStr); //sets string equal to 
                                                //another
   bool operator==(const CBString& argstr) const;//returns true if strings 
                                                 //equal
   bool operator!=(const CBString& argStr) const;//Returns true if strings
                                                 //are not equal
   bool operator<(const CBString& argstr) const; //returns true if string 
                                                 //less then argStr
   bool operator>(const CBString& argstr) const; //returns true if string 
                                                 //greater then argStr
   CBString operator+(const CBString& argStr) const; //Adds argStr to end  
                                                     //of operand string
   static int getcreatedcount(); //returns int of total created instances
   static int getcurrentcount(); //returns current instance count
private:
   static int createdCount, currentCount;
   int len;
   int cap;
   char buffer[1000];
   char * str;
   int compareTo(const CBString& argStr) const; //compares two strings, 
                                                //returns 0 on equal, 
                                                //positive or negative
                                                //int on greater than or 
                                                //less than respectively
};
#endif
