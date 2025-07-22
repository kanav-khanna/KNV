Bitwise operator 

//you will see questions from these alot in online test Bitwise ..and its usually a easy level question
//these operations are somwhat compiler dependent 

1. and &

7 & 4;

   1  1  1
&  1  0 0
   ------
   1  0 0
2. Or |
    7 | 4;

        1  1  1
    |   1  0 0
        ------
        1   1  1
3. NOT ~
  
 ~4;
~ 1 0 0
------
 0  1  1

4. Xor ^
    7 ^ 4; //0 on same value and 1 on different 

       1  1  1
    ^  1  0 0
       ------
        0  1  1

These do bit level operations. 

5. Left Shift (<<)  //n times left shit a*2^n  (2 power n) left shift is used to multiply 

Your original number was 5, and your new number is 20.

And indeed, 5×4=20.

So, by left-shifting the bits by 2, you multiplied the number by 4 (2^2). 
If you had shifted it by just 1, you would have gotten 00001010, which is 10 in decimal (5×2^1).
A shift by 3 would multiply it by 8 (2^3).

This is why left shifts are often used in low-level programming for fast multiplication by powers of 2. 
It's a single, very efficient operation for a computer's processor.

0 0 0 0 0 1 0 1 << 2
------------
0 0 0 1 0 1 0 0

int n = 5;
int k  = 5;
int ans =k<<n;

cout<<ans;

Output 160 ........becasue 5 X (2 to the power 5 which is 32)

6. Right Shift (>>)  when we shift by 1 divide my 2 ki power 1 sa will be the answer 
//if i am doing right shift of any number by N bits the number will be divided by 2 ki power n sa 
//But does not apply to negative numbers at times
// if negative number and signed integer (int and not using unsigned int) then compiler will handle right shift but when i used unsigned then i get random values 
// when we use unsigned int we get a positive large number when given a negative number as input 
// If you try to do a right shift with a negative number you will get a garbage value this applies to both left and right shift you will get a compiler warning aswell 


0 0 0 1 0 0 0 0 >> 2
------------
0 0 0 0 0 1 0 0 
The operation took your original number 16 and produced the number 4.

And indeed, 16÷4=4.

Every time you shift the bits one position to the right, you are effectively halving the number's value. Shifting by two positions halves it twice, which is the same as dividing by four.

A Quick Note on Remainders
The right shift operation performs integer division. This means it discards any remainder. For example, the number 17 is 00010001.

17 >> 1 (17 divided by 2) results in 00001000, which is 8. The .5 from the true result of 8.5 is dropped.


// VV important concept for MCQ////////////////////////////////
Pre/post increment decrement operator 
a++ a--

iPre increment - Phele stemal kere fir wishwas kara (first incriment then use)  int n = 5 cout<< (++n); Output = 6
Post increment - Phele use karo then increment karo (first use value then increment value) int n = 5 cout<< (n++); Output = 5
Pre decrement - Phele decrement then use
Post decrement - Use the value then decrement 
int a = 10
Cout<<(++a)*(a++) output = 121/132
Cout<<((a++)*(++a)) output = 120  //Need to look into why this is happening  ///endefined behavious casses these issues 
Your output is 120 because:

    a++ → 10

    ++a → 12 (after incrementing to 11 in between)

    So: 10 * 12 = 120

But: That’s relying on undefined behavior, and should be avoided.

Always split such expressions into separate lines for safe and reliable code.


Questions - 
n &= (n-1) what does this do ?

The expression:

c
Copy
Edit
n &= (n - 1);
is shorthand for:

c
Copy
Edit
n = n & (n - 1);
And just like before, it clears the rightmost set bit (1) in n.

// Break and continue /////////////////////////////////

Break- 
as soon as break statement is reached in a loop you will come out of the loop 

Continue- 
helps skip iterations in a loop 
for(int i = 0; i<10; i++)
   {
      if(i = 2)
         {
            continue  //the second iteration will be skipped and the lower code will be run on the next iteration 
         }
      //rest of the code of the loop
   }

//////// Variable scoping ///////////////// 

1. local variable 
   
for(int i = 0; i<10; i++)
   {
      cout<<i; //this will give the correct value of i;
   }
   cout<<i; // this will not work since i is a local variable 


2. globle variable 
created outside any loops or funtions and accessable everywhere

/////Expression//////////////

2*3+5/10-2  ///how i would solve this using BODMAS but the computer does not have that 
6+0.5-2
4.5
// the compiler uses a operator precidence table which is uses to accurately solve equations 
// We shoud use brackets for more accurate equations 
//The above equation should be written as this so that thier are no issues with inaccurate answers


((2*3)+(5/10))-2


/// odd even Bit wise solution/////////////////////////////////////IMP////////////////////////

the cpu stores numbers in its registers ...and the +- operations are done on these registers 

All even numbers in binary have their Least significan bit(lsb) set to 0 ...always 
even -> 1101010 ....Last digit is 0 so its even

if LSB set to 1 then its an odd number 

All the odd numbes have the LSB set to 1 

4 - 
0100
0001
-----
0000  -> did & operation with 1 on 4 got all zero which means its even

5- 
0101
0001
-----
0001  -> Did & operation with 1 on 5 then got 1 which means its an odd number 
 

 #include<iostream>
using namespace std;
    
bool evenodd(int b)
    {
    bool ans;
   if((b&1)== 0)
    {
       ans = true;
   }
    else
    {
        ans = false;
    }
    return ans;
}


    int main() {
        
            int num = 5;
            bool ans = evenodd(num);
            cout<<ans;
    }   

    