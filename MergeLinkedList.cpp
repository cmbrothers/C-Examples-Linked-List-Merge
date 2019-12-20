/*
Name: Caleb Brothers
Class : CS132
Program: 7 Templates
Description : Adaptation of doubly linked list merge program to utilize
class templates to build lists of varying data types and merge/ operate 
upon them. Additional test added at end to verify operation.
*/


#include <iostream>
#include <iomanip>
#include "LkList.h"
#include "CBString.h"

using namespace std;

int main() {
   
   LkList<int> list;
   LkList<int> list2;
   

	//------------------------

	list.merge(list2);
	//
	cout << "Merge #1 (empty merge): \n" << list << endl;
	cout << "List size after merge: " << list.size() << endl;
	cout << endl << endl;


	//------------------------


	list2.insert( { 0, 10, 20, 30, 40 } );

	list.merge(list2);

	cout << "Merge #2 (into an empty list): \n" << list << endl;
	cout << "List size after merge: " << "List 1: "<< list.size() << " " 
        << "List 2: " << list2.size() << endl;
	cout << endl << endl;

	list.clear();
	list2.clear();


	cout << endl << endl;
	//------------------------


	//
	list.insert( { 0, 5, 10, 15, 20, 25, 30, 35, 40} );
	//
	//
	list.merge(list2);
	//
	cout << "Merge #3 (from an empty list): \n" << list << endl;
	cout << "List size after merge: " << list.size() << endl;
	cout << endl << endl;
	//
	list.clear();
	list2.clear();
	//
	//------------------------




	list.insert( { 1, 3, 40, 47, 54, 61, 68 } );
	//
	list2.insert( { 0, 3, 6, 9, 12, 15, 18 } );



   list.merge(list2);

	cout << "Merge #4(source before destination): \n" << list << endl;
	cout << "List size after merge: " << list.size() << endl;
	cout << endl << endl;
	//
	list.clear();
	list2.clear();
	//

	//------------------------

	list.insert( { 10, 17, 21, 28 } );
	//
	list2.insert( { 50, 53, 56, 59, 62, 65 } );	
	//
	list.merge(list2);
	//
	cout << "Merge #5(source after destination): \n" << list << endl;
	cout << "List size after merge: " << list.size() << endl;
	cout << endl << endl;
	//
	list.clear();
	list2.clear();

	//------------------------

	list.insert( { 0, 9, 18, 27 } );
	//
	list2.insert( { -6, -4, -2, 0, 2, 4, 6, 8, 10, 12, 16, 
	                 18, 20, 22, 24, 26, 28, 30, 32, 34 } );	
	//


   list.merge( list2 );
	//
	cout << "Merge #6(source overlaps destination):\n" << list << endl;
	cout << "List size after merge: " << list.size() << endl;
	cout << endl << endl;
	//
	list.clear();
	list2.clear();


	//------------------------


   list.insert( { -6, 2, 10, 18, 26, 34 } );
	//
	list2.insert( { 10, 13, 16, 19, 22, 25 } );	
	//
	list.merge( list2 );
	//
	cout << "Merge #7(source within destination):\n" << list << endl;
	cout << "List size after merge: " << list.size() << endl;
	cout << endl << endl;
	
	list.clear();
	list2.clear();


	//------------------------

   LkList<double> dblList;
   for (double i = 10.9; i > 0; i -= .57)
      dblList.insert(i);

   cout << "dblList: " << dblList << "  size:" 
        << dblList.size() << endl << endl;

   LkList<CBString> strList;  // or string
   strList.insert(CBString("foo")); strList.insert(CBString("bar"));
   strList.insert(CBString("zip")); strList.insert(CBString("ftl"));

   cout << "strList: " << strList << "  size : " << strList.size() 
        << endl << endl;

	system("pause");
	return 0;
}
/*
Merge #1 (empty merge):

List size after merge: 0


Merge #2 (into an empty list):
0  10  20  30  40
List size after merge: List 1: 5 List 2: 0




Merge #3 (from an empty list):
0  5  10  15  20  25  30  35  40
List size after merge: 9


Merge #4(source before destination):
0  1  3  6  9  12  15  18  40  47  54  61  68
List size after merge: 13


Merge #5(source after destination):
10  17  21  28  50  53  56  59  62  65
List size after merge: 10


Merge #6(source overlaps destination):
-6  -4  -2  0  2  4  6  8  9  10  12  16  18  
20  22  24  26  27  28  30  32  34
List size after merge: 22


Merge #7(source within destination):
-6  2  10  13  16  18  19  22  25  26  34
List size after merge: 11


dblList: 10.9  10.33  9.76  9.19  8.62  8.05  7.48  
6.91  6.34  5.77  5.2  4.63  4.06  3.49  2.92  2.35  
1.78  1.21  0.64  0.07    size:20

strList: foo  bar  zip  ftl    size : 4

Press any key to continue . . .
*/
