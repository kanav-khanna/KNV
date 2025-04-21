Type Casting 

implicit - 
Allows you to change the data type of a variable from one type to another. 
Crucial when you need to perform operations involving data types of different types.
The compiler promotes one type to a larger type to maintain precision.

//Compiler promotes to larger type to prevent data loss 
example 
 int a = 10;
 float b = 5.5; 
 We could do INT +int but then we would loose data 
 So its better to do FLOAT +float = FLoat //and the compiler automatically does this

 int num1 = 10;
 float num2 = 5.5;
 float result = num+num2 //implicit conversion to float fo num 1

 ///
 int a = 97;
 char ch = a; in this  a will be casted to a char and this is a implict type casting 
 cout<<ch<<endl;

 Explicit type casting 

Manual type casting 
Allows you to explicity specify the desired data type during an assignment or operation 
you can use casting operator which is represented by parentheses containing the target data type 

int num1 = 10;
 float num2 = 5.5;
 float result = num1+(int)num2 // explicitly specified so that the float becomes an int.


 INT / int returns an int type ...even if the division is an decimal value then 

 int / int = int 
 int/ float = float 
 float / int = float 



 /////////////////////Switch Case /////////////////////////

 switch(expression) {
    case x:
      // code block
      break;
    case y:
      // code block
      break; //break needs to be used in switch case or else it will run all the code under it 
    default: //this is like the else case in c++
      // code block
  }

  int day = 4;
switch (day) {
  case 1:
    cout << "Monday";
    break;
  case 2:
    cout << "Tuesday";
    break;
  case 3:
    cout << "Wednesday";
    break;
  case 4:
    cout << "Thursday";
    break;
  case 5:
    cout << "Friday";
    break;
  case 6:
    cout << "Saturday";
    break;
  case 7:
    cout << "Sunday";
    break;
}