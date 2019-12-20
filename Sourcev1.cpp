/*
Name: Caleb Brothers
Class: CS132
Section: s
Description: Program for running a series of tests on the CBStringv1 class.
*/

#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <fstream>
#include <vector>
#include "CBString.h"

using namespace std;

//read strings from infile2.txt into vectored instances of CBString
int fileread(vector<CBString>&readIn);
//sort CBString instances by ASCII value, Low to High
void sort(vector<CBString>&strings);
//write vector of CBStrings to outfile.txt, 6 strings per line
void fileWrite(vector<CBString>&writeOut);

int main() {
   vector<CBString> fileString(100);

   cout << "MyStringv1 Testing." << endl << endl;
   cout << "String vector size before file read: ";
   cout << fileString.size() << endl << endl;

   fileString.resize(fileread(fileString));

   cout << "String vector size after file read: ";
   cout << fileString.size() << endl << endl;
   
   sort(fileString);
   fileWrite(fileString);

   cout << "See outfile.txt for ASCII sorted output(Low to High)." << endl;
   cout << endl;

   system("pause");
   return 0;
}

int fileread(vector<CBString>&input) {
   ifstream readIn;
   int temp = 0;

   readIn.open("infile2.txt");
   while (input[temp].read(readIn)) {
      temp++;
   }
   readIn.close();
   return temp;
}

void sort(vector<CBString>&strings) {
   int sorted;
   CBString swap;

   do {
      sorted = 0;
      for (int sort = 0; sort < static_cast<int>(strings.size()) - 1; sort++) {
         if (strings[sort] > strings[sort + 1]) {
            swap = strings[sort + 1];
            strings[sort + 1] = strings[sort];
            strings[sort] = swap;
            sorted++;
         }
      }
   } while (sorted > 0);
}

void fileWrite(vector<CBString>&writeOut) {
   ofstream output;

   int word = 0;

   output.open("outfile.txt", ios::trunc);
   for (int out = 0; out < static_cast<int>(writeOut.size()); out++) {
      
         writeOut[out].write(output);

         output << setw(13);
         
         if (word == 6) {
            output << endl;
            word = 0;
         }
         word++;
   }
   output.close();
}

/*
infile2.txt contents

They seemed amazingly busy. I began to ask myself what they could be.
Were they intelligent mechanisms? Such a thing I felt was impossible.
Or did a Martian sit within each, ruling, directing, using, much as
a man's brain sits and rules in his body? I began to compare the
things to human machines, to ask myself for the first time in my life
how an ironclad or a steam engine would seem to an intelligent lower
animal.


outfile.txt contents(Respaced for linewrap reasons)

I            I            I            Martian            
Or            Such
They            Were            a            a            a            a
amazingly            an            an            and            animal.            
as
ask            ask            be.            began            began            
body?
brain            busy.            compare            could            did            
directing,
each,            engine            felt            first            for            
his
how            human            impossible.            in            in            
intelligent
intelligent            ironclad            life            lower            
machines,            man's
mechanisms?            much            my            myself            
myself            or
rules            ruling,            seem            seemed            sit            
sits
steam            the            the            they            they           
thing
things            time            to            to            to            
to
to            using,            was            what            within            
would

*/