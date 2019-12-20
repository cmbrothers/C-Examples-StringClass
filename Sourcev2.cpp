/*
Name: Caleb Brothers
Class: CS132
Section: s
Program: MyString V2
Description: Program for running a series of tests on the CBStringV2 class.
             Reads data from a file, in standard istream format, assigns 
             to instances of CBString, combinesinto 5string chucnks then
             bubble sorts into ASCII ascending order.
*/

#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <fstream>
#include <vector>
#include "CBString.h"

using namespace std;

//read strings from infile2.txt into vectored instances of CBString
void fileread(vector<CBString>&input);
//sort CBString instances by ASCII value, Low to High
void sort(vector<CBString>&strings);
//display contents on CBString vector to console
void display(vector<CBString>&display);

int main() {
   vector<CBString> fileString;

   

   cout << "MyStringV2 Testing." << endl << endl;
   
   cout << "Vector size before file read: ";
   cout << fileString.size() << endl << endl;

   fileread(fileString);

   cout << "String vector size after file read: ";
   cout << fileString.size() << endl << endl;
   cout << "Order before sorting: " << endl;

   display(fileString);

   sort(fileString);
   cout << "Order after sorting: " << endl;

   display(fileString);

   cout << "Total created strings: " << fileString[0].getcreatedcount() 
        << endl;
   cout << "Current strings used:  " << fileString[0].getcurrentcount()
        << endl;
   system("pause");
   return 0;
}

void fileread(vector<CBString>&input) {
   ifstream readIn;
   CBString bigString, temp;

   readIn.open("infile3.txt");
   if (readIn.fail()) {
      cout << "File does not exist, is corrupted or otherwise couldn't\n"
           << "be opened. Program terminating, please try again." << endl;
      system("pause");
      exit (0);
   }
   cout << "File OPEN" << endl;
   while (readIn.fail() != true) {  
      for (int incoming = 1; incoming <= 5; incoming++) {
         if (readIn >> temp) {
            if (incoming == 1) {
               bigString = temp;
            }
            else {
               bigString = (bigString + temp);
                
            }
         }
      } 
      input.push_back(bigString);      
   }
   readIn.close();
}

void sort(vector<CBString>&strings) {
   int sorted;
   CBString swap;

   do {
      sorted = 0;
      for (int sort = 0; sort < static_cast<int>(strings.size()) - 1; 
         sort++) {

         if (strings[sort] > strings[sort + 1]) {
            swap = strings[sort + 1];
            strings[sort + 1] = strings[sort];
            strings[sort] = swap;
            sorted++;
         }
      }
   } while (sorted > 0);
}

void display(vector<CBString>&display) {
   for (int temp = 0; temp < static_cast<int>(display.size()); temp++) {
      cout << setw(45) << left << display[temp] << " L" 
           << display[temp].length() << ":C" << display[temp].capacity() 
           << endl;
   }
   cout << endl;
}



/*
Program Output:
MyStringV2 Testing.

Vector size before file read: 0

File OPEN
String vector size after file read: 16

Order before sorting:
Theyseemedamazinglybusy.I                     L25:C40
begantoaskmyselfwhat                          L20:C20
theycouldbe.Werethey                          L20:C20
intelligentmechanisms?Suchathing              L32:C40
Ifeltwasimpossible.Or                         L21:C40
didaMartiansitwithin                          L20:C20
each,ruling,directing,using,much              L32:C40
asaman'sbrainsits                             L17:C20
andrulesinhisbody?                            L18:C20
Ibegantocomparethe                            L18:C20
thingstohumanmachines,to                      L24:C40
askmyselfforthefirst                          L20:C20
timeinmylifehow                               L15:C20
anironcladorasteam                            L18:C20
enginewouldseemtoan                           L19:C20
intelligentloweranimal.ThisIsMyAmazinglyLongStringToM
akeYourExtractionOperatorWorkCorrectly. L92:C100

Order after sorting:
Ibegantocomparethe                            L18:C20
Ifeltwasimpossible.Or                         L21:C40
Theyseemedamazinglybusy.I                     L25:C40
andrulesinhisbody?                            L18:C20
anironcladorasteam                            L18:C20
asaman'sbrainsits                             L17:C20
askmyselfforthefirst                          L20:C20
begantoaskmyselfwhat                          L20:C20
didaMartiansitwithin                          L20:C20
each,ruling,directing,using,much              L32:C40
enginewouldseemtoan                           L19:C20
intelligentloweranimal.ThisIsMyAmazinglyLongStringToM
akeYourExtractionOperatorWorkCorrectly. L92:C100
intelligentmechanisms?Suchathing              L32:C40
theycouldbe.Werethey                          L20:C20
thingstohumanmachines,to                      L24:C40
timeinmylifehow                               L15:C20

Total created strings: 183
Current strings used:  16
Press any key to continue . . .
*/