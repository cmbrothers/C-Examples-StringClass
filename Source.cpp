/*
Name: Caleb Brothers
Class: CS132
Section: s
Program: DLL Test
Description: Program for testing double linked list class alongside 
             CBString class. Reads from 2 files and constructs a doubly 
             linked list from each. Copies list into another then strips 
             words from the second file and vise versa. Outputs total 
             string in each list to console at various stages before 
             writing results to output files.
*/

#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <fstream>
#include <vector>
#include "CBString.h"
#include "DoubleLinkedList.h"

using namespace std;

template <typename T>
//read strings from file and inserts them into lists
void fileread(const char file[], T&dll);
//strips words that exist in one list from another
template <typename T>
void striplists(T&modify, 
     const T&source);
//display contents of lists to console
template <typename T>
void display(const T&list1, 
     const T&list2,
     const T&modList1, 
     const T&modList2);
//copies list and adds a couple words(tests copy constructor)
template <typename T>
void changer(T list);
//writes list to specified output file
template <typename T>
void filewrite(const char file[], const T&dll);

//exists soley for the purpose of allowing the printing of created 
//and current string counts.
const CBString nothing;

int main() {
   DoubleLinkedList<CBString> list1;
   DoubleLinkedList<CBString> list2;
   DoubleLinkedList<CBString> modList1;
   DoubleLinkedList<CBString> modList2;
    
   cout << "Double-Linked List test program." << endl << endl;

   cout << "Attempting to open infile1: ";
   ::fileread("infile1.txt", list1);

   cout << "Attempting to open infile2: ";
   ::fileread("infile2.txt", list2);

   ::display(list1, list2, modList1, modList2);

   cout << endl << "Setting modList1 and 2 equal to list1 and 2 "
        << "respectively.\n\nNew list contents." << endl;
   modList1 = list1;
   modList2 = list2;
   
   ::display(list1, list2, modList1, modList2);

   cout << endl << "Stripping words contained in list 2 from modlis1,\n";
   cout << "and those contained in list 1 from modlist 2.\n" << endl;
   ::striplists(modList1, list2);
   ::striplists(modList2, list1);

   ::display(list1, list2, modList1, modList2);
   
   cout << "Modlist1"; 
   ::changer(modList1);
   cout << "Modlist2"; 
   ::changer(modList2);
   cout << endl;

   cout << "Outside changer." << endl;

   ::display(list1, list2, modList1, modList2);
   cout << endl << "Total created CBStrings: ";
   cout << nothing.getcreatedcount()-1;
   cout << endl << "Total current CBStrings: ";
   cout << nothing.getcurrentcount()-1;
   cout << endl << endl;

   ::filewrite("outfile1.txt", modList1);
   ::filewrite("outfile2.txt", modList2);

   cout << "Program finished." << endl;

   system("pause");
   return 0;
}

template <typename T>
void fileread(const char file[], T&dll) {
   ifstream readIn;
   CBString temp;

   readIn.open(file);
   if (readIn.fail()) {
      cout << "File does not exist, is corrupted or otherwise couldn't\n"
           << "be opened. Program terminating, please try again." << endl;
      system("pause");
      exit (0);
   }
   cout << "File OPEN" << endl <<endl;
   while (readIn >> temp) {  
      dll.insert(temp);
   }
   readIn.close();
}
template <typename T>
void striplists(T&modify, 
     const T&source) {
   source.resetIteration();
   while (source.hasNext()) {
      modify.remove(source.next());
   }
   modify.remove(source.next());
}
template <typename T>
void display(const T&list1, 
     const T&list2,
     const T&modList1, 
     const T&modList2) {
   cout << "Current list contents." << endl;
   cout << "Total strings, List1: " << list1.getNodeCount() << endl;
   cout << "Total strings, List2: " << list2.getNodeCount() << endl;
   cout << "Total strings, modList1: " << modList1.getNodeCount() << endl;
   cout << "Total strings, modList2: " << modList2.getNodeCount() << endl;
}
template <typename T>
void changer(T list) {
   CBString zip("ZIP");
   CBString zap("ZAP");

   list.insert(zip);
   list.insert(zap);

   cout << " contains " << list.getNodeCount() << "words within changer "
        << "function." << endl;
}
template <typename T>
void filewrite(const char file[], const T&dll) {
   ofstream writeOut;

   writeOut.open(file, ios::trunc);

   writeOut << dll;

   writeOut.close();
}



/*
Console Output:
Double-Linked List test program.

Attempting to open infile1: File OPEN

Attempting to open infile2: File OPEN

Current list contents.
Total strings, List1: 1104
Total strings, List2: 1040
Total strings, modList1: 0
Total strings, modList2: 0

Setting modList1 and 2 equal to list1 and 2 respectively.

New list contents.
Current list contents.
Total strings, List1: 1104
Total strings, List2: 1040
Total strings, modList1: 1104
Total strings, modList2: 1040

Stripping words contained in list 2 from modlis1,
and those contained in list 1 from modlist 2.

Current list contents.
Total strings, List1: 1104
Total strings, List2: 1040
Total strings, modList1: 759
Total strings, modList2: 695
Modlist1 contains 761words within changer function.
Modlist2 contains 697words within changer function.

Outside changer.
Current list contents.
Total strings, List1: 1104
Total strings, List2: 1040
Total strings, modList1: 759
Total strings, modList2: 695

Total created CBStrings: 9579
Total current CBStrings: 3598

Program finished.
Press any key to continue . . .
*/