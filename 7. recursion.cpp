
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

