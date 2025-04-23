/////////////////square pattern 
#include<iostream>
using namespace std;

int main() {
    for(int i = 0; i<4;i++) //row
    {   
        
           for(int j = 0; j<4;j++) //col
            {  
               cout<<"*";
           }
        cout<<endl;
    }  
    
}

/// hollow square 
#include<iostream>
using namespace std;

int main() {
    int n = 6;
    for(int i = 0; i<n;i++) //row
    {   
        
           for(int j = 0; j<n;j++) //col
            {  
               if(i==0||i== n-1||j==0||j==n-1)  //i is row so i ==n-1 is the bottom row
               {                                //j is col so j == n-1 is the last col printed so right side of square
                   cout<<"*";                   //i == 0 will be th top of the square  
               }                                //j == 0 will be the first column so lsft side
               else
               {
                   cout<<" ";
               }
              
           }
        cout<<endl; 
    }

// half pyramid hollow 
*
**
* *
*  *
*****  
//j == 1 → left edge

//j == i → right edge

//i == n → bottom row (filled with *)

//Else → print space in the middle

#include<iostream>
using namespace std;

int main() {
    int n = 5;
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= i; j++) {
            // Print star at the borders and on the last row
            if(j == 1 || j == i || i == n) { 
                cout << "*";
            } else {
                cout << " ";
            }
        }
        cout << endl;
    }
    return 0;
}

//Inverted pyramid code 

****
***
**
*

#include<iostream>
using namespace std;

int main() {
    int n = 8;
    for(int i = n; i>=1;i--) //row we keep dectreasing them 
    {       //cout<<"*"; 
           for(int j = 1; j<=i;j++) //col fill the column with one less each time 
            {  
               cout<<"*";
               
              }
              
           cout<<endl;     
    }   
}

//Hollow pyramid ///not sure how this fully works need fix

#include<iostream>
using namespace std;
int main() {
    int n = 8;
    for(int i = 0; i<n;i++) //row
    {       //cout<<"*"; 
           for(int j = 0; j<n;j++) //col
            {                                     //j == 0 is the left side col
                                                  //i == 0 is the right side row               
               if(i == 0 || j == 0 || j == n-i-1) ///j == n-rows-1 is just a formula that you need to remember created because of the corralation between the values of the triagle that need to be printed 
               {
                cout<<"*";
               }
               else{
                   cout<<" ";
               }
              }
              
      cout<<endl;
    }  
}

* * * * *  ////all the chars that need to be printed follow the rule cols == n-rows-1
*     *
*   * 
* *
*

/// full pyramid
If you have N number of rows then you need 2n-1 number of columns .....this is important 

Why 2n-1 columns ?? 
well if you lok at any full pyramid 
if i have 3 rows -> 5 columns
          4 rows -> 7 columns 
          5 rows -> 9 columns 
          6 rows -> 11 columns All of these follow the same formula and thats 2n-1  ////how to look at numbers and create equations ???

    1 2 3 4 5 6 7 8 9        
1            *                      
2          * * *             
3        * * * * *         
4      * * * * * * *       
5    * * * * * * * * *      

so in the for loops i will need n number of rows and 2n-1 numebr of columns
N is actually the midpoint since 2n-1 is the total columns
In the above figure if we look at the spots where we need to print Stars their is a pattern 
in the first row N is printed 
in second column N, N-1, and N+1 
in the third one N-2, n-1, n , n+1, N+2 are printed 
By the above logic we can use the formula N+(i-1) and N-(i+1) the i id just the column here 

#include<iostream>
using namespace std;

int main() {
    int n = 8;
    for(int i = 0; i<n;i++) 
    {    
        for(int j = 0; j<= 2*n-1; j++) //2n-1 is the formula to find the number of columns since only row is given 
        {
            if(j >= n - i && j <= n + i) //   For row i, you want to print * from: j = n - i to j = n + i
            {
                cout<<"*";
            }
            else{
                cout<<" ";
            }
        }
       cout<<endl; 
    }

}

// full pyramid but hollow 
i,j  1 2 3 4 5 6 7 8 9        
1            *                         
2          * * *             
3        * * * * *         
4      * * * * * * *       
5    * * * * * * * * *  

Since i need this to be hollow the following indexes need to be empty 
i,j

if (i == 1 || i == n || j == 
Should be printed- 
1,5 and 5 needs to be fully printed 
2,4  2,6  n-(i-1)
3,3  3,7
4,2  4,8

Should not be printed -  
2,5
3,4  3,5  3,6
4,3  4,4  4,5  4,6  4,7

//j == n - 1 - i → left edge of pyramid

//j == n - 1 + i → right edge of pyramid

//i == n - 1 → last row → fully filled with stars

#include<iostream>
using namespace std;

int main() {
    int n = 8;
    for(int i = 0; i<n;i++) 
    {    
        for(int j = 0; j< 2*n-1; j++) 
        {   
            if( i == n-1){ //prints the base of the pyrimid 
                cout<<"*";
            }
            else if(j ==n-i-1 || j==n+i-1) //this prints the edges//brackes removed to change output
            {
                
                cout<<"*";
                
            }
            else{
                cout<<" ";
            }
        }
       cout<<endl; 
    }

}

//Pyramid reverse 


#include<iostream>
using namespace std;

int main() {
    int n = 8;
    for(int i = 0; i < n; i++) 
    {    
        for(int j = 0; j < 2*n - 1; j++)
        {
            if(j >= i && j < 2*n - 1 - i) // <- this has been updated we start with max columns then they start reducting with every step
            {
                cout << "*";    
            }
            else{
                cout << " ";
            }
        }
        cout << endl; 
    }
}


// reverse hollow 

#include<iostream>
using namespace std;

int main() {
    int n = 8;

    for(int i = 0; i < n; i++) 
    {
        for(int j = 0; j < 2*n - 1; j++)
        {
            if(i == 0) {
                cout << "*"; // Top row is solid
            }
            else if(j == i || j == 2*n - 2 - i) { // in normal we use 2*n - 1 - i but here we use -2 since 1 row is solid   
                cout << "*"; // Sides of the inverted pyramid // j == i is the left side stars and j == 2*n-2-i is the right side stars while the i =0 is to print the solid first line
            }
            else {
                cout << " ";
            }
        }
        cout << endl;
    }

    return 0;
}

// Diamond pattern 
Pretty easy just combine the above 2 codes for a normal pyramid and a inverted pyramid

#include<iostream>
using namespace std;

int main() {
    int n = 8;

    // Top half (normal pyramid)
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < 2*n - 1; j++) {
            if(j >= n - 1 - i && j <= n - 1 + i)
                cout << "*";
            else
                cout << " ";
        }
        cout << endl;
    }

    // Bottom half (inverted pyramid without repeating middle line)
    for(int i = 1; i < n; i++) {
        for(int j = 0; j < 2*n - 1; j++) {
            if(j >= i && j < 2*n - 1 - i)
                cout << "*";
            else
                cout << " ";
        }
        cout << endl;
    }

    return 0;
}


// half pyramid pattern with numbers 

1
2*2
3*3*3
4*4*4*4

#include<iostream>
using namespace std;

int main() {
    int n = 4;
    for(int i = 1; i<=n;i++) //row we keep dectreasing them 
    {       //cout<<"*"; 
           for(int j = 1; j<=i;j++) //col fill the column with one less each time 
            {  
                cout<<i;
               if(j < i) { //we need to add starts between all the numbers but not at the end so we check for the end 
                cout << "*";
            }
           }   
              
              
           cout<<endl;     
    }   
}

// half pyramid with numbers 
0
12
345
6789

int main() {
    int n = 4;
    int numbs = 0;
    for(int i = 0; i<n;i++) //row we keep dectreasing them 
    {       //cout<<"*"; 
           for(int j = 0; j<=i;j++) //col fill the column with one less each time 
            {  
              cout<<numbs;
               numbs++;
              }
              
           cout<<endl;     
    }   
}

//
1
12
123
1234

int main() {
    int n = 4;
    char a[10] = "a";
    for(int i = 0; i<n;i++) //row we keep dectreasing them 
    {       //cout<<"*"; 
           for(int j = 0; j<=i;j++) //col fill the column with one less each time 
            {  
              cout<<j+1;
              }
              
           cout<<endl;     
    }   
}


// Alphabet pyramid 

A
AB
ABC
ABCD


int main() {
    int n = 8;
    
    for(int i = 0; i<n;i++) 
    {       //cout<<"*"; 
           for(int j = 0; j<=i;j++) 
            {  
              char ch = j+1+'A'-1;  // this is the important part  where we convert number to char
              cout<<ch;
            }
              
           cout<<endl;     
    }   
}

// numeric hollow half pyramid 
12345678
2     8 
3    8  
4   8   
5  8    
6 8     
78  
//GOOD :)
#include<iostream>
using namespace std;

int main() {
    int n = 8;
    int numb = 1;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            
            if( j == 0 ) {
                cout << numb;
            }
            else if(i == 0)
            {
                cout<<j+1;
                
            }
            else if(j == n-i-1)
            {
                cout<< n;
            }
                
             else {
                cout << " ";
            }
            
        
        }
        numb++;
        cout << endl;
    }
}

//Floyds triangle 
1
2 3
4 5 6
7 8 9 10
11 12 13 14 15
16 17 18 19 20 21
22 23 24 25 26 27 28

#include<iostream>
using namespace std;

int main() {
    int n = 8;
    int number = 1;
    for(int i = 0; i<n;i++) 
    {    
        for(int j = 0; j<i; j++)
        {   
            cout<<" ";
            cout<<number;
            number++;
        }
       
        cout<<endl;
    }
}

///Numeric palindrom pyramid  *** this needs to be revised ***
       1
      121
     12321
    1234321
   123454321
  12345654321
 1234567654321
123456787654321


#include<iostream>
using namespace std;

int main() {
    int n = 8;
    for(int i = 1; i <= n; i++) {
        // Print leading spaces
        for(int j = 1; j <= n - i; j++) {
            cout << " ";
        }

        // Print increasing numbers
        for(int j = 1; j <= i; j++) { //left half
            cout << j;
        }

        // Print decreasing numbers
        for(int j = i - 1; j >= 1; j--) {  //right half
            cout << j;
        }

        cout << endl;
    }
    return 0;
}


//Special pattern 
//This has 17 columns in every row 
//only works upto 9 ...not for more
********1********
*******2*2*******
******3*3*3******
*****4*4*4*4*****
****5*5*5*5*5****

#include<iostream>
using namespace std;

int main() {
    int n = 5;
    for(int i = 0; i<n;i++) 
    {   int start_num = 8-i;
        int num = i+1;
        int count = num;
        for(int j = 0;j<17;j++)
        {   
            if(j == start_num && count>0)
            {
                cout<<num;
                start_num+=2;
                count--;
            }
            else{
                cout<<"*";
            }
            
        }
        cout<<endl;
    }

}

//Special pattern 

1
2*3
4*5*6
7*8*9*10
7*8*9*10
4*5*6
2*3
1

#include<iostream>
using namespace std;

int main() {
    int n = 4;
    int num = 1;
    for(int i = 1; i<=n;i++) //row we keep dectreasing them 
    {       //cout<<"*"; 
           for(int j = 1; j<=i;j++) //col fill the column with one less each time 
            {  
               
               cout<<num;
               if(j<i){
               cout<<"*";
               }
              num++;
              }
              
           cout<<endl;     
    } 
    num = num-n;
    int start = num;
    
    for(int i = 0; i<n;i++) //row we keep dectreasing them 
    {       //cout<<"*"; 
        int k = start;
           for(int j = 0; j<=n-i-1;j++) //col fill the column with one less each time 
            {  
               cout<<k;
                
               if(j<n-i-1){
               cout<<"*";
               } 
              k++;
              }
              start = start -(n-i-1); //reset the number being printed...so it correctly prints from left to right 
           cout<<endl;     
    }   
}

/////////Fancy pattern #3

1
121
12321
121
1

//i = i , j = 2*i in the growing phase  

In the above pattern we have a growing phase and a shrinking phase and both need to be handeled with a condition
growing n/2 = 0->2



#include<iostream>
using namespace std;

int main() {
    int n = 5;
    
    for(int i = 0; i<n;i++)
    {   int cond = i<=n/2 ? 2*i: 2*(n-i-1);    // first condition is growing phase and second one is shrinking phase for ROW 
        for(int j = 0;j<=cond;j++)
        {
            
            if(j<=cond/2)
            {
                cout<<j+1;    //Column condition for growing
            }
            else{
                cout<<cond-j+1; //column condition for shrinking
            }
        }
        cout<<endl;
    }
}
/////////////Pascals triangle pattern 

1 
1 1 
1 2 1 
1 3 3 1 
1 4 6 4 1 

you start with a 1 and the sum of the 2 adjesent values will be the number under it 

pASCAL - binomial coefficent formula 
Formula - c = c *(i-j)/j;

#include<iostream>
using namespace std;

int main() {
    int n = 5;
    
    for(int i = 1; i<=n;i++)
    {int c = 1;
        for(int j = 1;j<=i; j++)
            {
            cout<<c<<" ";
            c = c*(i-j)/j; // this formula used to print 
        }
     cout<<endl;
    }
}


///butterfly pattern
// this question and the 2 before it no clue how the equations were derived for these i need to spend some time on how the equations were made so i can make them aswell


*        *
**      **
***    ***
****  ****
**********
**********
****  ****
***    ***
**      **
*        *

#include<iostream>
using namespace std;

int main() {
    int n = 5;
    for(int i = 0; i<2*n;i++) //2*n because 2 triangles being printed so n is double 
    {    
        int cond = i<n ? i : n+(n-i-1);
        int space = i < n ? 2*(n-cond-1): i-cond-1;
        for(int j = 0; j<2*n; j++)  
        {
            if(j<=cond)
            {
                cout<<"*";
            }
            
            else if(space >0)
            {
                cout<<" ";
                space--;
            }
            
            else
            {
                cout<<"*";
            }
        }
        cout<<endl;
    }

}