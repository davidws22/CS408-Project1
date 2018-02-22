#include "version1.h"
#include <sstream>
#include <iostream>

void version1()
{
  string input;
  int *set1;
  int *set2;
  int m = 0;
  int n = 0;
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
	      if(m > 0)
		{
		  delete set1;
		  set1 = NULL;
		}
	      if(n > 0)
		{
		  delete set2;
		  set2 = NULL;
		}
	      m = 0;
	      n = 0;

	    }
	  createSet(set1, set2, m, n);
	  target = false;
	  break;
	case '2':
	  if(target)
	    {
	      cout << "Please enter set information first...\n";
	      break;
	    }
	  Union(set1, set2, m, n);
	  break;
	case '3':
	  if(target)
	    {
	      cout << "Please enter set information first...\n";
	      break;
	    }
	  Difference(set1, set2, m, n);
	  break;
	case '4':
	  if(target)
	    {
	      cout << "Please enter set information first...\n";
	      break;
	    }
	  Intersection(set1, set2, m, n);
	  break;
	case '5':
	  cout << "Exiting version 1...\n";
	  flag = false;
	  if(m > 0)
	    {
	      delete set1;
	      set1 = NULL;
	    }
	  if(n > 0)
	    {
	      delete set2;
	      set2 = NULL;
	    }
	  break;
	default:
	  cout << "Invalid selection. Please try again...\n";
	}
    }
}


void createSet(int* &x, int* &y, int &m, int &n)
{
  bool flag = true;
  int counter = 1;
  string input;
  string temp;
  int num = 0;
  string input2;
  //counting number of integers are given for both set 1 and set 2 and assigning
  // them to m and n respectively
  while(flag)
    {
      stringstream ss;
      
      cout << "Please enter integers for set " << counter << " separated by spaces: ";
      if(counter == 1)
	{
	  getline(cin, input);
	  ss << input;
	}
      if(counter == 2)
	{
	  getline(cin, input2);
	  ss << input2;
	}
      while(!ss.eof())
	{
	  ss >> temp;
	  if(stringstream(temp) >> num)
	    {
	      if(counter == 1)
		m++;
	      if(counter == 2)
		n++;
	    }
	}
      ++counter;
      if(counter == 3)
	flag = false;
    }
  //cout << "m has a value of : " << m << " input has a value of " << input << endl;
  //cout << "n has a value of : " << n << " input2 has a value of " << input2 << endl;
  
  //populating set 1
  if(m > 0)
    {
      stringstream ss;
      int i = 0;
      int* store = new int[m];
      int k = m;
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
		      --m;
		    }
		}
	    }
	  if(flag == false)
	    {
	      store[i] = num;
	      ++i;
	    }
	}
      x = new int[m];
      for(int i = 0; i < m; i++)
	{
	  x[i] = store[i];
	}
    }
  
  //populating set 2
  if(n > 0)
    {
      stringstream ss;
      int i = 0;
      int* storage = new int[n];
      int k = n;
      bool flag = false;
 
      ss << input2;
      while(!ss.eof())
	{
	  flag = false;
	  ss >> temp;
	  if(stringstream(temp) >> num)
	    {
	      for(int j = 0; j < k; j++)
		{
		  if(storage[j] == num)
		    {
		      flag = true;
		      --n;
		    }
		}
	    }
	  if(flag == false)
	    {
	      storage[i] = num;
	      ++i;
	    }
	}
      y = new int[n];
      for(int i = 0; i < n; i++)
	{
	  y[i] = storage[i];
	}      
    }
  
  //display sets
  cout << "Set 1 contains: {";
  for(int i = 0; i < m; i++)
    {
      cout << x[i];
      if(i + 1 == m);
      else
	cout << ", ";
    }
  cout << "}" << endl;
  cout << "Set 2 contains: {";
  for(int i = 0; i < n; i++)
    {
      cout << y[i];
      if(i + 1 == n);
      else
	cout << ", ";
    }
  cout << "}"<< endl;
  
}
  

void Union(int* x, int* y, int m, int n)
{
  if(m+n == 0)
    {
      cout << "The Union of set 1 and set 2 is { }\n";
      return;
    }
  else if(m == 0)
    {
      cout << "The Union of set 1 and set 2 is {";
      for(int i = 0; i < n; i++)
	{
	  cout << y[i] << ", ";
	}
      cout << "}\n";
      return;
    }
  else if(n == 0)
    {
      cout << "The Union of set 1 and set 2 is {";
      for(int i = 0; i < m; i++)
	{
	  cout << x[i] << ", ";
	}
      cout << "}\n";
    }
  else
    {
      //cout << "m is equal to " << m << endl;
      //cout << "n is equal to " << n << endl;
      int index = 0;
      bool flag = false;
      int* UN = new int[m+n];
      int counter = m+n;
      for(; index < m; index++)
	{
	  UN[index] = x[index];
	}

      for(int i = 0; i < n; i++)
	{
	  for(int j = 0; j < (m+n); j++)
	    {
	      if(UN[j] == y[i])
		{
		  flag = true;
		  counter--;
		}
	    }
	  if(!flag)
	    {
	      UN[index] = y[i];
	      ++index;
	    }
	  flag = false;
	}

      cout << "The Union of set 1 and set 2 is: {";
      for(int i = 0; i < counter; i++)
	{
	  cout << UN[i];
	  if(i+1 == counter)
	    cout << "}";
	  else
	    cout << ", ";
	}
      cout << endl;
    }
}

void Difference(int* x, int* y, int m, int n)
{
  if(m == 0)
    {
      cout << "The Difference between set 1 and set 2 is: {";
      for(int i = 0; i < n; i++)
	{
	  cout << y[i];
	  if(i+1 == n)
	    cout << "}";
	  else
	    cout << ", ";
	}
      cout << endl;
    }
  else if(n == 0)
    {
      cout << "The Difference between set 1 and set 2 is: {";
      for(int i = 0; i < m; i++)
	{
	  cout << x[i];
	  if(i+1 == m)
	    cout << "}";
	  else
	    cout << ", ";
	}
      cout << endl;
    }
  else if(m == 0 && n == 0)
    cout << "The Difference between set 1 and set 2 is : { }";
  else
    {
      int size = m;
      int* DF;
      bool flag = false;
      
      for(int i = 0; i < m; i++)
	{
	  for(int j = 0; j < n; j++)
	    {
	      if(x[i] == y[j])
		--size;
	    }
	}
      //cout << "The difference counter is " << size << endl;
      if(size > 0)
	{
	  DF = new int[size];
	  int index = 0;
	
	  for(int j = 0; j < m; j++)
	    {
	      for(int k = 0; k < n; k++)
		{
		  if(x[j] == y[k])
		    flag = true;
		}
	      if(flag == false)
		{
		  DF[index] = x[j];
		  ++index;
		}
	      flag = false;
	    }
	
	  cout << "The set difference of set 1 and set 2 is: {"; 
	  for(int i = 0; i < size; i++)
	    {
	      cout << DF[i];
	      if(i+1 == size)
		cout << "}";
	      else
		cout << ", ";
	    }
	  cout << endl;
	}
        else
	  {
	    cout << "The set difference of set 1 and set 2 is: { }" << endl;
	  }
    }//end if-else block
}

void Intersection(int* x, int* y, int m, int n)
{
  int* temp;
  int counter = 0;
  for(int i = 0; i < m; i++)
    {
      for(int j = 0; j < n; j++)
	{
	  if(x[i] == y[j])
	    ++counter;
	}
    }
  //cout << "The counter from intersection is : " << counter << endl;
  if(counter == 0)
    {
      cout << "The intersection of set 1 and set 2 is : { }\n";
    }
  else
    {
      bool flag = false;
      int index = 0;
      int i = 0;
      temp = new int[counter];
      
      for(int j = 0; j < m; j++)
	{
	  for(int k = 0; k < n; k++)
	    {
	      if(x[j] == y[k])
		{
		  flag = true;
		  index = j;
		}
	    }
	  if(flag)
	    {
	      temp[i] = x[index];
	      flag = false;
	      ++i;
	    }
	}
      cout << "The intersection of set 1 and set 2 is {";
      for(int i = 0; i < counter; i++)
	{
	  cout << temp[i];
	  if((i+1) == counter)
	    cout << "}\n";
	  else
	    cout << ", ";
	}	 
    }  
}

