#include "set.h"
#include <iostream>
#include <sstream>
using namespace std;
//default constructor
set::set()
{
  s = NULL;
  numElems = 0;
}
//destructor
/*
set::~set()
{
  if(numElems > 0)
    {
      delete s;
      numElems = 0;
    }
}
*/    

//populate
void set::populate()
{
  int num;
  string input, temp;
  stringstream ss;
  cout << "Please enter integers to populate a set, separated by spaces: ";
  getline(cin, input);
  ss << input;
  while(!ss.eof())
    {
      ss >> temp;
      if(stringstream(temp) >> num)
	{
	  ++numElems;
	}
    }
  if(numElems > 0)
    {
      stringstream ss;
      int i = 0;
      int* store = new int[numElems];
      int k = numElems;
      bool flag = false;

      ss << input;
      while(!ss.eof())
	{
	  flag = false;
	  ss >> temp;
	  if(stringstream(temp) >> num)
	    {
	      for(int j = 0; j < k; j++)
		{
		  if(store[j] == num)
		    {
		      flag = true;
		      --numElems;
		    }
		}
	    }
	  if(flag == false)
	    {
	      store[i] = num;
	      ++i;
	    }
	}
      s = new int[numElems];
      for(int i = 0; i < numElems; i++)
	{
	  s[i] = store[i];
	}
      
      // cout << "The value of numElems is :" << numElems << endl;
      cout << "Displaying the set: ";
      Display();
    }
}

void set::Display()
{
  if(numElems > 0)
    {
      cout << "{";
      for(int i = 0; i < numElems; i++)
	{
	  cout << s[i];
	  if(i+1 == numElems)
	    cout << "}\n";
	  else
	    cout << ", ";
	}
    }
  else
    cout << "{ }\n";
}

set set::operator+ (const set &temp)
{
  set result;
  if(temp.numElems + numElems == 0) 
      return result;
  else if(numElems == 0)
      return *this;
  else if(temp.numElems == 0)
      return temp;
  else
    {
      int index = 0;
      bool flag = false;
      //cout << "numElems from default constructor: " << result.numElems << endl;
      int* UN = new int[numElems+temp.numElems];
      int counter = numElems + temp.numElems;
      
      //cout << "counter from version2 union is...: " << counter << endl;
      for(; index < numElems; index++)
	{
	  UN[index] = s[index];
	}
      for(int i = 0; i < temp.numElems; i++)
	{
	  for(int j = 0; j < (numElems + temp.numElems); j++)
	    {
	      if(UN[j] == temp.s[i])
		{
		  flag = true;
		  counter--;
		}
	    }
	  if(!flag)
	    {
	      UN[index] = temp.s[i];
	      ++index;
	    }
	  flag = false;
	}
      result.numElems = counter;
      result.s = new int[counter];
      for(int i = 0; i < counter; i++)
	{
	  result.s[i] = UN[i];
	}
      delete UN;
      UN = NULL;
    }
  return result;
}

set set::operator- (const set& temp)
{
  set result;
  if(numElems == 0)
    return *this;
  else if(temp.numElems == 0)
    return temp;
  else
    {
      int size = numElems;
      bool flag = false;

      for(int i = 0; i < numElems; i++)
	{
	  for(int j = 0; j < temp.numElems; j++)
	    {
	      if(s[i] == temp.s[j])
		--size;
	    }
	}
      //cout << "The difference counter is " << size << endl;
      if(size > 0)
	{
	  result.s = new int[size];
	  result.numElems = size;
	  int index = 0;

	  for(int j = 0; j < numElems; j++)
	    {
	      for(int k = 0; k < temp.numElems; k++)
		{
		  if(s[j] == temp.s[k])
		    flag = true;
		}
	      if(flag == false)
		{
		  result.s[index] = s[j];
		  ++index;
		}
	      flag = false;
	    }
	}
    }//end if-else block
  return result;
}

//overloading intersection operator
set set::operator^ (const set& temp)
{
  set result;
  int size = 0;
  for(int i = 0; i < numElems; i++)
    {
      for(int j = 0; j < temp.numElems; j++)
	{
	  if(s[i] == temp.s[j])
	    ++size;
	}
    }
  cout << "The counter from intersection is : " << size << endl;
  if(size > 0)
    {
      result.s = new int[size];
      result.numElems = size;
      bool flag = false;
      int index = 0;
      int i = 0;
      for(int j = 0; j < numElems; j++)
	{
	  for(int k = 0; k < temp.numElems; k++)
	    {
	      if(s[j] == temp.s[k])
		{
		  flag = true;
		  index = j;
		}
	    }
	  if(flag)
	    {
	      result.s[i] = s[index];
	      flag = false;
	      ++i;
	    }
	}
    }//end if-else block
  return result;
}
