//C++ STL implementation

#include<stack>

stack<int> st;
st.push(10);
st.pop();
st.size();
st.top();

//Stack implementation without STL

//implement stack using dynamic array

//Remember to handle overflow and underlow 

#include <iostream>
using namespace std;

class Stack {
  public:
    int* arr;
    int size;
    int top;

    Stack(int size) {
      arr = new int[size];
      this->size = size;
      this->top = -1;
    }

    void push(int data) {
      if(top == size-1) {
        cout << "Stack overflow" << endl;
        return;
      }
      else {
        top++;
        arr[top] = data;
      }
    }

    void pop() {
      if(top == -1) {
        cout << "Stack underflow" << endl;
        return;
      }
      else {
        top--;
      }
    }

    bool isEmpty() {
      if(top == -1) {
        return true;
      }
      else {
        return false;
      }
    }

    int getTop() {
      if(top == -1) {
        cout << "Stack is empty" << endl;
        return -1;
      }
      else {
        return arr[top];
      }   
    }

    int getSize() {
      return top+1;
    }

    void print() {
      cout << "Top:  " << top << endl;
      cout << "Top element: " << getTop() << endl; 
      cout << "Stack: ";
      for(int i=0; i<getSize(); i++) {
        cout << arr[i] << " ";
      }  cout << endl << endl;
    }
};

int main() {

  //creation 
  Stack st(8);

  //push
  st.push(10);
  //st.print();

  st.push(20);
  st.print();

  cout<< endl << "Top elemet: " << st.getTop() << endl;
  cout << endl << "Size of stack: " << st.getSize() << endl;

  st.pop();
  st.pop();
  if(st.isEmpty()) 
  {
    cout << "Empty" << endl;
  }
  else {
    cout << "Not empty" << endl;
  }

//   st.push(30);
//   st.print();

//     st.push(10);
//   st.print();

//   st.push(20);
//   st.print();



//   st.push(30);
//   st.print();
//     st.push(10);
//   st.print();

//   st.push(20);
//   st.print();

//   st.push(30);
 // st.print();

//   st.pop();
//   st.print();
//   st.pop();
//   st.print();
//   st.pop();
//   st.print();

  return 0;
}


//Stack using STL 

#include <iostream>
#include<stack>
using namespace std;

int main() {

  //creation
  stack<int> st;

  //insertion
  st.push(10);
  st.push(20);
  st.push(30);

  //size check
  cout << "Size of stack is: " << st.size() << endl;

  //remove 
  st.pop(); 

  //check empty
  if(st.empty()) {
    cout << "Stack is empty" << endl;
  }
  else {
    cout << "stack is non empty" << endl;
  }


  //top element
  cout << st.top() << endl;


  return 0;
}

//Reverse a string using stack 

#include <iostream>
#include<stack>
using namespace std;

int main() {
  string str = "hellojee";
  stack<char> st;

  for(int i=0; i<str.length(); i++) {
    char ch = str[i];
    st.push(ch);
  }

  cout << endl;
  while( !st.empty() ) {
    cout << st.top()  ;
    st.pop();
  }cout << endl;

  return 0;
}


///wat ra
#include <iostream>
#include<stack>
using namespace std;

void solve(stack<int> &st, int& pos, int &ans) {
  //base case
  if(pos == 1) {
    //ans =  st.top();
    cout << "Deleting "<< st.top() << endl;
    st.pop();
    return;
  }
  //1 case hum solve krenge
  pos--;
  int temp = st.top();
  st.pop();
  //recursion
  solve(st,pos,ans);
  //backtracjk
  st.push(temp);
}

int getMiddleElement(stack<int> &st) {
  int size = st.size();
  if(st.empty()){
    cout << "Stack is empty, no middle element" << endl;
    return -1;
  }
  else {
    //stack is not empty
    //odd
    int pos = 0;
    if(size & 1) {
      pos = size/2 + 1;
    }
    else {
      //even
      pos = size/2;
    }
    int ans = -1;
    solve(st,pos,ans);
    return ans;
  }
}

int main() {
  stack<int> st;
  st.push(10);
  st.push(20);
  st.push(30);
  st.push(50);
  st.push(60);

  cout << "before size" << st.size() << endl; 
  int mid = getMiddleElement(st);
  cout << "Middle element: " << mid << endl;

  cout << "after size" << st.size() << endl; 
  return 0;
}

/////

#include <iostream>
#include<stack>
using namespace std;

void insertAtBottom(stack<int> &st, int &element) {
  //base case
  if(st.empty()) {
    st.push(element);
    return;
  }

  //1 case main solve karunga
  int temp = st.top();
  st.pop();

  //baaaki recursion
  insertAtBottom(st, element);

  //backTrack
  st.push(temp);
}

void reverseStack(stack<int> &st) {
  //base case
  if(st.empty()) {
    return;
  }
  //1 case main solve krega
  int temp = st.top();
  st.pop();
  //refcursion
  reverseStack(st);
  //backtrack
  insertAtBottom(st,temp);
}

void insertSorted(stack<int> &st, int element) {
  //base case
  if(st.empty() || element > st.top()) {
    st.push(element);
    return;
  }

  //1 case sambhalna h
  int temp = st.top();
  st.pop();
  //recursion sambhalega
  insertSorted(st,element);
  //backtrack
  st.push(temp);
}

void sortStack(stack<int> &st) {
  //base case
  if(st.empty()) {
    return;
  }

  //1 case
  int temp = st.top();
  st.pop();

  //recursion
  sortStack(st);

  //backtrack
  insertSorted(st, temp);
}

int main() {

  stack<int> st;
  st.push(10);
  st.push(7);
  st.push(12);
  st.push(5);
  st.push(11);
//   int element = 400;
//   insertAtBottom(st,element);

// without reverse: 
// 30 20 10 

//   reverseStack(st);
// //   with reverse: 
// //   10 20 30
  
//   cout << "with reverse: " << endl;
//insertSorted(st,35);
  sortStack(st);
  while(!st.empty()) {
    cout << st.top() << " ";
    st.pop();
  }


  return 0;
}
 