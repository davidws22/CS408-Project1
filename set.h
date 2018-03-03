#ifndef SET_H
#define SET_H

class set
{
 private:
  int* s;
  int numElems;

 public:
  //constructor
  set();
  //destructor
  //  ~set();
  //populate a set
  void populate();
  //display a set
  void Display();
  //overloading the + operator for union
  set operator+ (const set &temp);
  //overloading the - operator for difference
  set operator- (const set &temp);
  //overloading the * opeator for intersection
  set operator^ (const set &temp);
 
};

#endif
