/*
Name: Caleb Brothers
Class : CS132
Section : S
Description : Definitions for CBString class.
*/

#include <iostream>
#include <cstdlib>
#include <cctype>
#include "CBString.h"

using namespace std;

int CBString::createdCount = 0;
int CBString::currentCount = 0;

CBString::CBString() {
   len = 0;
   cap = 20;
   
   str = new char[capacity() + 1]; 

   buffer[0] = '\0';
   str[0] = '\0';
   createdCount++;
   currentCount++;
}

CBString::CBString(const char *ptr) {
   const char *temp;
   temp = ptr;
   while (*temp != NULL) {
      temp++;
      len++;
   }
   
   if (len / 20 > 0) {
      cap = (len / 20) * 20;
   }
   if (len % 20 > 0) {
      cap += 20;
   }

   str = new char[capacity() + 1];

   for (int index = 0; index < len; index++) {
      str[index] = *ptr;
      ptr++;
   } 
   str[len] = '\0';
   createdCount++;
   currentCount++;
}

CBString::CBString(const CBString & mstr) { 
   len = 0;
   cap = 0;
   buffer[0] = '\0';

   len = mstr.length();
   cap = mstr.capacity();
   for(int index = 0; index <= len; index++) {
      buffer[index] = mstr.str[index];
   }
   
   str = new char[capacity() + 1];

   for (int index = 0; index < len; index++) {
      str[index] = buffer[index];
   }
   str[len] = '\0';
   createdCount++;
   currentCount++;
}

CBString::~CBString() {
   
   delete[] str;
     
   currentCount--;
}

int CBString::length() const{
   return len;
}
int CBString::capacity() const{
   return cap;
}

istream& operator>>(istream& istr, CBString& argStr) {
   int indexTemp = 0;
   argStr.len = 0;
   argStr.cap = 0;
   istr >> argStr.buffer;

   while (argStr.buffer[indexTemp] != NULL) {
      argStr.len++;
      indexTemp++;
   }

   if (ispunct(argStr.buffer[argStr.len - 1])) {
      argStr.len--;
      argStr.buffer[argStr.len] = '\0';
   }

   if (argStr.len / 20 > 0) {
      argStr.cap = (argStr.len / 20) * 20;
   }
   if (argStr.len % 20 > 0) {
      argStr.cap += 20;
   }

   delete[] argStr.str;
   
   argStr.str = new char[argStr.cap + 1];

   for (int index = 0; index < argStr.len; index++) {
      argStr.str[index] = argStr.buffer[index];
   }
   argStr.str[argStr.len] = '\0';
   return istr;
}

ostream& operator<<(ostream& ostrm, const CBString& argStr) {
   
   ostrm << argStr.str;
   
   return ostrm;
}

const char* CBString::c_str() const{
   return str;
}

int CBString::compareTo(const CBString& argStr) const{
   int temp = 0;

   for (int index = 0; index <= len; index++) {
      temp = tolower(str[index]) - tolower(argStr.str[index]);
      if (temp != 0) {
         return temp;
      }
   }

   return 0;
}

char CBString::operator[](int index) const {
   char temp;
   if (index < 0 || index > len - 1) {
      cout << "Requested char does not exist or lies outside\n"
           << "the boundaries of the available location." << endl;
      return NULL;
   }
   temp = str[index - 1];
   return temp;
}

CBString& CBString::operator=(const CBString& argStr) {

   len = argStr.length();
   cap = argStr.capacity();
   for (int index = 0; index <= len; index++) {
      buffer[index] = argStr.str[index];
   }

   delete[] str;
   str = new char[capacity() + 1];

   for (int index = 0; index < len; index++) {
      str[index] = buffer[index];
   }
   str[len] = '\0';
   buffer[0] = '\0';

   return *this;
}

bool CBString::operator==(const CBString& argstr) const {
   if (compareTo(argstr) == 0) {
      return true;
   }
   else {
      return false;
   }
}

bool CBString::operator!=(const CBString& argStr) const {
   if (compareTo(argStr) != 0) {
      return true;
   }
   else {
      return false;
   }
}

bool CBString::operator<(const CBString& argstr) const{
   if (compareTo(argstr) < 0) {
      return true;
   }
   else {
      return false;
   }
}

bool CBString::operator>(const CBString& argstr) const{
   if (compareTo(argstr) > 0) {
      return true;
   }
   else {
      return false;
   }
}

CBString CBString::operator+(const CBString& argStr) const{
    
   CBString add;

   add.cap = 0;
     
   for (int index = 0; index < len; index++) {
      add.buffer[index] = str[index];
   }
   for (int index = len; index <= (len + argStr.len) - 1; index++) {
      add.buffer[index] = argStr.str[index - len];
   }

   add.len = len + argStr.len;

   if (add.len / 20 > 0) {
      add.cap = (add.len / 20) * 20;
   }
   if (add.len % 20 > 0) {
      add.cap += 20;
   } 

   delete[] add.str; 

   add.str = new char[add.cap + 1];

   for (int index = 0; index < add.len; index++) {
      add.str[index] = add.buffer[index];
   }

   add.str[add.len] = '\0';

   return add;
}

int CBString::getcreatedcount() {
   return createdCount;
}

int CBString::getcurrentcount() {
   return currentCount;
}