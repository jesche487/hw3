#include<iostream>
#include "stack.h"
using namespace std;

int main(){
  Stack<int> intStack;
  //Stack<string> stringStack;
  intStack.push(4);
  intStack.push(5);
  intStack.push(6);

  cout << intStack.size() << endl;

  cout << intStack.top() << endl;
  intStack.pop();
  cout << intStack.top() << endl;
  intStack.pop();
  cout << intStack.top() << endl;
  intStack.pop();

  if(intStack.empty()) cout << "Stack is empty" << endl;
  
  try {
    intStack.pop();
  }
  catch (std::underflow_error e) {
    cout << e.what() <<endl;
  }

  try {
    intStack.top();
  }
  catch (std::underflow_error e) {
    cout << e.what() <<endl;
  }

}