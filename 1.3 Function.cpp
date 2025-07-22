
A function is a block of code that is linked to a well defined task 

In c++ you have to define a function before you call it. You cannot call it first and then have the definition under it.

Incase you do want to do the above you need to declare the function before ..then it can be defined later 

// function call stack 
    this tracks function call and its info 
    like function calls
    local variables 
    which function called which other function


    first entry in fucntion call stack will always be main then other funcctions that are called 
    when fucntion execution has stopped then remove the entry for that fucntion  from stack 

    oddly enought the return keyword can be used inside a void function ...as long aas you dont return any values 


///Functions call by refrence and call by value 

//refrence variable 
like a person can be called by multiple different names ...lassan adi ...


int n = 5;
int& K = n;  //this is a refrence variable to the N variable //this is sort of a alias for n we not call it as K

refrence variable can point to another variable but you cannot use it so set a value 
ma kisi vaiable ka nick name ban sakta hu kisi constent ka nahi 
if we print n or k the output will be the same 


//the normal function calls we do are call by value in this the actual value is sent over to the function

// call by refrence 
void incrementby1(int &n) //The & signifies call by refrence where if the value of N is updated it will also be updated where it was passed from 
    {
    }
// my code 
#include<iostream>
using namespace std;

 int max(int a, int b, int c)
    {
        if(a>=b&&a>=c)
        {return a;}
        
        else if(b>=a&&b>=c)
        {return b;}
        
        else if(c>=a&&c>=b)
        {return c;}
     return 0;
    }


int main() {
 
    int ans = max(10,30,30);
    cout<<ans;
}

#include<iostream>
using namespace std;
    
float circle(int a)
    {
    float ans = 3.14*a*a;
    //cout<< ans;
    return ans;    
}


    int main() {
        
            float rad = 5;
            float ans = circle(rad);
            cout<<ans;

    }   


//factorial 
#include<iostream>
using namespace std;
    
int factorial(int b)
{   
    long long int ans = 1;
    
    for(int i =1;i<=b;i++)
    {
        ans = ans*i;
    }
    return ans;
}


    int main() {
        
            int num = 13;
            long long int ans = factorial(num);
            cout<<ans;
    }   


// number is Prime or not 

#include<iostream>
using namespace std;
    
bool factorial(int b)
{   
    long long int ans = 1;
    int i = 2;
    for(i=2;i<b;i++) // optimized solution insted of running the code till N we run it till sqrt(n) .maths has proof that known prime will have a factor in less than square root of n 
    { 
        if(b%i == 0)
        {
            return false;
        }
        
    }
    return true;
}


    int main() {
        
            int num = 6;
            bool ans = factorial(num);
            cout<<ans;
    }   

////Print all prime form 1 to N
#include<iostream>
using namespace std;
    
bool factorial(int b)
{   
    long long int ans = 1;
    int i = 2;
    for(i=2;i<sqrt(b);i++)
    {
        if(b%i == 0)
        {
            return false;
        }
        
    }
    return true;
}


    int main() {
            

            int num = 6;
            
           for(int i = 2;i<num;i++)
            {
               bool ans = factorial(i);
               
               if(factorial)
                {
                   cout<<i<<" ";
               }
           }
    }     


	///https://www.geeksforgeeks.org/problems/set-kth-bit3724/1

	Set the K-th bit of a given number

	class Solution {
  public:
    int setKthBit(int n, int k) {
        // Code here
        int mask = 1<<k;               
        int ans = n|mask;
        return ans;
    }
};

Since we have to change the Kth bit we ceate a mask with 1 at the position of k ...so that only that bit is effected rest all zeros 
and then we do a OR operation this enables ...others to be uneffected



////////////////////2469. Convert the Temperature https://leetcode.com/problems/convert-the-temperature/description/
//For vectors use .push_back to avoid any issues of values being set 

class Solution {
public:
    vector<double> convertTemperature(double celsius) {
        vector <double> ans;
        double k = celsius+273.15;
        double f = celsius * 1.80 + 32.00;
        ans.push_back(celsius+273.15);
        ans.push_back(celsius * 1.80 + 32.00);
        //ans[0] = celsius+273.15;
        //ans[1] = celsius * 1.80 + 32.00;
        return ans;
    }
};

/// create number using digits 
num = num *10+digit

///////////////////////////Print all digits of an integer////////////////////////// 
#include<iostream>
using namespace std;
    
void digits(int n)
{   
   while(n>0)
   {
       int onesplace = n%10;
       n = n/10;
       cout<<onesplace;
   }
}


    int main() {            
        int n = 1234;
        digits(n);     
    }     


7. Reverse Integer

https://leetcode.com/problems/reverse-integer/description/

class Solution {
public:
    int reverse(int x) {
        int ans = 0; // Initialize the reversed number to 0
        while (x != 0) {
            int digit = x % 10; // Get the last digit of x
            
            // Check for overflow/underflow before updating ans
            if ((ans > INT_MAX / 10) || (ans < INT_MIN / 10)) {
                return 0; // Return 0 if reversing x would cause overflow/underflow
            }
            
            ans = ans * 10 + digit; // Append the digit to the reversed number
            x = x / 10; // Remove the last digit from x
        }
        return ans; // Return the reversed number
    }
};

////Given an integer count the number of set bits in it 

N= 34 binary = 100010 (Set bits means 1) 
So 34 has 2 set bits 
 
 1. how to convert any number to binary 
 2. the find the 1 if bit == 1 then count ++
 3. n = n/2 ....this is so you can keep deviding and not just deviding the same number


 #include<iostream>
using namespace std;
    
int setbit(int n)
{   
    
    int count = 0;
    while(n>0){
        int bit = n%2;
        if(bit==1)
        {
            count++;
        }
        n=n/2;
            
    }
    return count;
    
}


    int main() {
            
    int n = 34;
    int set = setbit(n);
        cout<<set;       
    }     

    
//169. Majority Element --this is solved but not the best solution i think 
https://leetcode.com/problems/majority-element/description/


//missing element from an array with duplicates 
//array should have elements from 1 to n but their are duplicates and 1 element is missing 

https://www.geeksforgeeks.org/find-missing-elements-from-an-array/ 

///visited method
//tc - O(n)
sc -O(1)
#include<iostream>
using namespace std;

void findmissing(int *arr, int n)
    {
    for(int i = 0;i<n;i++)
    {
        int index = abs(arr[i]); //we find the index
        
        if(arr[index-1]>0){ //if index is more than 0 that means its not visited
            arr[index-1] *= -1; //then we visit it by setting it to negative
        }
    }
    
    for(int i = 0;i<n;i++)
        {
        // all prositive indexes are missing 
        if(arr[i]>0)
        cout<<i+1<<" ";
    }
}


int main() {
   //
   int arr[] = {1,3,3,3,4};
   int n = sizeof(arr)/sizeof(int);
    findmissing(arr,n);
    return 0;
   
     
}

///Sorting + swapping method 
This solution was not fully running and i do not fully understand this thing - need to look at this tomorrow 
#include<iostream>
using namespace std;

void findmissing(int *arr, int n)
    {
    int i =0;
    while(i<n)
    {   int index = arr[i] -1;
       if(arr[i] != arr[index])
       {
           swap(arr[i], arr[index]);
       }
        else{
            i++;
        }
    
    }
    for(int j = 0;j<n;j++)
        {
        cout<<arr[j]<<" ";
    }
    for(int i = 0;i<n;i++)
        {
        // all prositive indexes are missing 
        if(arr[i] !=i+1){
           
        cout<<i+1<<" ";
 
        }    
    }
    }
    
    



int main() {
   //
   int arr[] = {1,3,3,3,4};
   int n = sizeof(arr)/sizeof(int);
    findmissing(arr,n);
    return 0;
   
     
}