//The standard template library provides a collection of template classes and functions the offer common data structures and and agorithm 

//a vector in c++ is a dynamic array that can grow or shrink in size 
 

// we can also dynamically create an array -
int *arr = new int[n];
new keyword is for dynamic memory allocation


//static memory allocation is when we pre define the size of a array
v.clear() to clear the vecotr 
print(v) to print the vector 
v.at(i) can also be used to print the matrix .single index 

vector<int> nums(5,100) ///this type of vector definition menans that its a vector of size 5 and every variable is initalized with a 100 in it

2D vector 
//Syntax- 
vector <vector<int>> arr

//interesting declaration method 
vector <vector<int>> arr(5, vector<int>(10,0))
2d arrat             //arr is the name  //5 is row size // row item initialized with vector of size 10 that has the value of 0 in all of them s