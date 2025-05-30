
When a function calls itself directly or indirectly that is termed as recursion

What to look in problem statements to validate if recursion can be used or not 
solution of bigger problem is dependent on solution of a smaller problem (of same type) the recursion can be applied.

recursion Code usually contain the following points- 
1. base condition - This is mandatory 
2. recursive call - Also mandatory 
3. additional proccessing  - Optional ...depends on the program 

Time complexity - (other vid need to watch)


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
    int finalans = n * recursionkaans;
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
The recursive solution has exonential time compleity

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

//********* If you ever want to store data in a variable thats passed a a fucntion parameter and return that value 
// it needs to be a pass by refrence & or else your answer will be stored in a local variable and not the one being returned */

H/W traverse array using recursion and find max element 
h/W given digits then return the number 
