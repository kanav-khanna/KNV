//LIFO
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
      for(int i=0; i<getSize(); i++) {//no no no no 
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


///deleting an element from the middle (or bottom) of the stack
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

/////reverse a stack

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

//Sort stack
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

//Implement 2 stacks in a single array

//My first thought was to split the array in the middle and use the first half as stack one and other as stack 2
//That is not a good approach since it wastes memory in the case where one stack has alot of elements and the other has only 1 but the total fits the array size

top1 = -1 //underflow 
top2 = size;

// when top2-top1 == 1 //overflow 

class stack{
  public:
  int* arr;
  int size;
  int top1;
  int top2;

  stack(int size)
    {
      arr = new int[size];
      this->size = size;
      this->top1 = -1;
      this->top2 = size;
    }

    void push1(int data)
      { 
        if(top2-top1 == 1)
          {
            //no space
            cout<<"overflow"
          }
          else{
        top1++;
        arr[top1] = data;
          }
      }
    void push2(int data)
      {
        if(top2-top1 == 1)
          {
            //no space
            cout<<"overflow"
          }
        else{
        top2--;
        arr[top2] = data;
        }
      }
      void pop1(int data)
      {  
        if(top1 == -1)
          {
            cout<<"stack 1 is empty"
          }
        else{
        arr[top1] = 0;
        top1--;
        }

      }
      void pop2(int data)
      {  
         
        if(top2 == size)
          {
            cout<<"stack 2 is empty"
          }
        else{
        arr[top2] = 0;
        top2++;
        }
      }
};

int main(){

  stack st(6);

  return 0;
}


//20. Valid Parentheses
//https://leetcode.com/problems/valid-parentheses/description/
//O(n)
class Solution {
public:
    bool isValid(string s) {
        
        stack<char> st;

        for(int i = 0;i<s.size();i++)
            {
                char ch = s[i];
                //cout<<ch;
                if(ch == '(' || ch=='{' || ch == '[')
                    {
                            st.push(ch);                        
                    }
                else{
                    if(!st.empty()){
                    char temp = ')';
                    if(ch == ')')
                        {
                            temp = '(';
                        }
                    if(ch =='}')
                        {
                            temp = '{';
                        }
                    if(ch==']')
                        {
                            temp = '[';
                        }

                    if(temp == st.top())
                        {   
                            st.pop();
                        }
                    else if(temp != st.top()){
                       return false;
                    }
                    }

                    else{
                        return false;
                    }
                }
                
            }
        if(st.size() == 0) //i missed this part initially and it causes issues 
        {
        return true;
        }
        else{
            return false;
        }
    }
};

//Remove redundant brackets 
bool checkRedundantBracket(string s)
{
    stack<char> st;
    int n = s.size();
    for (int i = 0; i < n; i++)
    {
        char ch = s[i];
        if (ch == '(' || ch == '+' || ch == '-' || ch == '*' || ch == '/')
            st.push(ch);
        else if (ch == ')')
        {
            int operatorCount = 0;
            while (st.size() != 0 && st.top() != '(')
            {
                char temp = st.top();
                if (temp == '+' || temp == '-' || temp == '*' || temp == '/')
                    operatorCount++;
                st.pop(); //remove the operator
            }
            st.pop(); //i forgot this at first need to remove the opening bracket aswell
            if (operatorCount == 0)
                return 1;//return true ...bracket were redundant.
        }
    }
    return 0;
}

//Implement a min stack 
normal stacks time complexity for push and pop is O(1) but to find min element it would be O(n)
//Min stack allows to do all the operations in O(1)
//155. Min Stack
//https://leetcode.com/problems/min-stack/description/

class MinStack {
public:
    vector<pair<int,int>> st;

    MinStack() {
        //HUH?
    }
    
    void push(int val) {
        if(st.empty())
            {   //empty case
                pair<int,int> p;
                p.first = val;
                p.second = val;
                st.push_back(p);
            }
        else{
            //not empty case
            pair<int,int> p; //if i use make_pair ..need to provide values 
            p.first = val;
            int oldmin = st.back().second;
            p.second = min(oldmin, val);
            st.push_back(p);
        }
    }
    
    void pop() {
        
        st.pop_back();
        //check underflow ?
        
    }
    
    int top() {
        pair<int,int> rightmostpair = st.back();
        return rightmostpair.first;
    }
    
    int getMin() {
         pair<int,int> rightmostpair = st.back();
        return rightmostpair.second;
        
    }
};

//next smaller element 
//at the position of any element when we move forward ...if we find any element smaller than the current ...then thats the next smalles else we store -1
//2n
vector<int> nextSmallerElement(int *arr, int size)
  {
    stack<int> st;

    st.push(-1);

    for(int i = size-1;i>=0;i--) //left to right on the array 
      {
        int curr = arr[i];

        while(st.top()>= curr)
          {
            st.pop();
          }
          int ans = st.top();
          st.push(curr);
      }
      return ans;
  }

int main() 
  {
    int arr[5] = {8,4,6,2,3};
    int size = 5;
    vector<int> ans;

    ans = nextSmallerElement(arr,size,ans);

    for(auto i:ans)
        {
          cout<<i<<" ";
        }

    cout<< endl;
    return 0;
  }



//Prev smallest element
//same as above but  right to left this time 
vector<int> prevSmallerElement(int *arr, int size)
  {
    stack<int> st;

    st.push(-1);

    for(int i = 0;i<size-1;i++) //left to right on the array 
      {
        int curr = arr[i];

        while(st.top()>= curr) 
          {
            st.pop();
          }
          int ans = st.top();
          st.push(curr);
      }
      return ans;
  }

84. Largest Rectangle in Histogram
//https://leetcode.com/problems/largest-rectangle-in-histogram/description/
//can be done using the previous to codes of prev smallest + next smallest ....does need a bunch of changes 

class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        stack<int> stack;
        stack.push(-1);
        int max_area = 0;

        for (int i = 0; i < heights.size(); i++) {
            while (stack.top() != -1 && heights[i] <= heights[stack.top()]) {
                int height = heights[stack.top()];
                stack.pop();
                int width = i - stack.top() - 1;
                max_area = max(max_area, height * width);
            }
            stack.push(i);
        }

        while (stack.top() != -1) {
            int height = heights[stack.top()];
            stack.pop();
            int width = heights.size() - stack.top() - 1;
            max_area = max(max_area, height * width);
        }

        return max_area;        
    }
};

//Count the Reversals
https://www.geeksforgeeks.org/problems/count-the-reversals0401/1

//1. same char sequence means (( - 1 reveral needed
//2. different char )( - 2 reversal needed 
//3. () - valid 
//use the valid parentheses logic from previously done code

//if odd number string ...we cannot make pairs so return -1

class Solution {
  public:
    int countMinReversals(string s) {
        // code here
        //if odd size then cannot make pair
        if(s.size() & 1) return -1;
        
        int ans = 0;
        stack<char> st;
        
        for(char ch:s)
            {
                if(ch == '{')
                    {
                        st.push(ch);
                    }
                else{
                    if(!st.empty() && st.top() == '{')
                        {
                            st.pop();
                        }
                    else{
                        st.push(ch);
                    }
                }
            }
        //if stack is still not empty ...need to count reversals 
        
        while(!st.empty())
            {
                char a = st.top(); st.pop();
                char b = st.top(); st.pop();
                
                if(a == b) ans+=1;
                
                else{
                    ans+=2;
                }
            }
        return ans;
    }
};

//https://leetcode.com/problems/final-prices-with-a-special-discount-in-a-shop/description/?envType=problem-list-v2&envId=stack
