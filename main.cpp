// ============================================================================
// file: main.cpp
// ============================================================================
// Programmer: David Shin
// Date: 2/22/2018
// Class: CS 408 ("Programming Languages")
// Time: TR 1:00 - 2:50pm
// Instructor: Dr. Raheja
// Project: Sets
//
// Description:
//      This program implements two versions of sets and performs the union,
//      difference, and intersection operations on each version. Version 1 is
//      implemented using pointers to ints to store each set, while Version 2
//      uses its own ADT, found in "set.h" to store each set.
// Compilation instructions:
//      1) g++ main.cpp version1.cpp set.cpp
//      2) ./a.out
//
// ============================================================================
#include <iostream>
#include <string>
#include "set.h"
#include "version1.h"

using namespace std;
void version2();

int main()
{
  string input;
  while(true)
    {
      cout << "1. Version 1\n";
      cout << "2. Version 2\n";
      cout << "3. Exit\n";
      cout << "Please choose a selection: ";
      getline(cin, input);
      if(input[0] == '1')
	{
	  cout << "calling function 1" << endl;
	  version1();
	}
      else if(input[0] == '2')
	{
	  cout << "calling function 2" << endl;
	  version2();
	}
      else if(input[0] == '3')
	{
	  cout << "Exiting program...\n";
	  break;
	}
      else
	{
	  cout << "Invalid selection. Please try again...\n";
	}
    }//end while  
  return 0;
}

void version2()
{
  set s1;
  set s2;
  string input;
  bool target = true;
  bool flag = true;

  while(flag)
    {
      cout << "1. Enter sets\n";
      cout << "2. Union\n";
      cout << "3. Difference\n";
      cout << "4. Intersection\n";
      cout << "5. Return to main menu\n";
      cout << "Please choose a selection: ";
      getline(cin, input);
      switch(input[0])
	{
	case '1':
	  if(target == false)
	    {
	      //deallocating used memory, if any.
	      s1.~set();
	      s2.~set();
	    }
	  s1.populate();
	  s2.populate();
	  target = false;
	  break;
	case '2':
	  {
	    if(target)
	      {
		cout << "Please enter set information first...\n";
		break;
	      }
	    set temp = s1 + s2;
	    cout << "The Union of set 1 and set 2 is: ";
	    // cout << "temp.numElems = " << temp.getElems() << endl;
	    temp.Display();
	  }
	  break;
	case '3':
	  {
	    if(target)
	      {
		cout << "Please enter set information first...\n";
		break;
	      }
	    set temp = s1 - s2;
	    cout << "The Difference of set 1 and set 2 is: ";
	    temp.Display();
	  }
	  break;
	case '4':
	  {
	    if(target)
	      {
		cout << "Please enter set information first...\n";
		break;
	      }
	    set temp = s1 ^ s2;
	    cout << "The Intersection of set 1 and set 2 is: ";
	    temp.Display();
	  }
	  break;
	case '5':
	  cout << "Exiting version 2...\n";
	  flag = false;
	  break;
	default:
	  cout << "Invalid selection. Please try again...\n";
	}
    }
}

  
