
When a function calls itself directly or indirectly that is termed as recursion

What to look in problem statements to validate if recursion can be used or not 
solution of bigger problem is dependent on solution of a smaller problem (of same type) then recursion can be applied. 

recursion Code usually contain the following points- 
1. base condition - This is mandatory 
2. recursive call - Also mandatory 
3. additional proccessing  - Optional ...depends on the program 

Time complexity - (no clue lol)

//to understand recursion you need to first understand recursion :)

//Factorial using recursion - 
#include<iostream>
using namespace std;


int factorial (int n)
{
    if(n==1)
    {
        return 1;
    }
    if(n==0)
    {
        return 1;
    }
    
    int recursionkaans = n*(factorial(n-1));
    //int finalans = n * recursionkaans; 
    return finalans;
    
}
int main() {
    cout<<factorial(5);
    return 0;
}


//70. Climbing Stairs
https://leetcode.com/problems/climbing-stairs/description/

I have done this question before with a better soluton
This below solution is only to learn recursion and will not actually work when submitted(TLE)
The recursive solution has exponential time compleity

**ways(n) = ways(n-1) + ways(n-2) .....below code is kinda like fibonacci series//////imp

class Solution {
public:
    int climbStairs(int n) {
        
       if(n == 0)
        {
            return 1;
        }
        if(n==1)
            {
                return 1;
            }
        int ans = climbStairs(n-1) + climbStairs(n-2);
        return ans;

    }
};

//********* If you ever want to store data in a variable thats passed as a fucntion parameter and return that value 
// it needs to be a pass by refrence & or else your answer will be stored in a local variable and not the one being returned */

traverse array using recursion and find max element 
given digits then return the number 


///////INCLUDE EXCLUDE pattern for recursion ////////////////

Q- print all sub sequences of a string 
n length string will have 2 ki power n sub sequences


https://www.geeksforgeeks.org/problems/cutted-segments1642/1
Maximize The Cut Segments
But again this solution will TLE because recursion is just that useless 

class Solution {
  public:
    // Function to find the maximum number of cuts.
    int maximizeTheCuts(int n, int x, int y, int z) {
        // Your code here
        if(n==0)
            {
                return 0;
            }
        if(n <0)
            {
                return INT_MIN;
            }
            
        int option1 = 1+maximizeTheCuts(n-x,x,y,z);
        int option2 = 1+maximizeTheCuts(n-y,x,y,z);
        int option3 = 1+maximizeTheCuts(n-z,x,y,z);
        
        int finalans = max(option1, max(option2,option3));
        return finalans;
    }
};


///////////
https://leetcode.com/problems/coin-change/description/

https://leetcode.com/problems/house-robber/description/

//binary search rec
int climbStairs(int arr[],int s,int e,int target) {
        
    if(s>e)
    {
        return -1;//element not found
    }
    
    int mid = s+(e-s)/2;
    if(arr[mid] == target)
        { 
        return mid;
        }
    else if(mid<target)
    {
        start = mid+1;
        return climbStairs(arr,mid,e,target);
    }
    
    else if(mid>target)
    {
        end = mid-1;
        return climbStairs(arr,s,end,target);
    }
    

    }

//sub sequence of string using rec

