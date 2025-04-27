//find unique element
//Each element occurs twice except one 

//Approch is we XOR all the elements together then all the same one will cancel out and you will only be left with the unique one 
//540. Single Element in a Sorted Array (did it but this is not the optimized approch)
#include<iostream>
using namespace std;

int main() {
   
   int arr[] = {1,2,3,1,2,3,4,5,6,5,4};
   int ans = 0    //initalize with 0 is reccomended even though when i solved this i initialized with the first array element 
                  //when we xor anything with 0 we get the same number so ...yeah 0 works  
    for(int i = 1;i<11;i++)
    {
        ans = ans^arr[i];
    }
    cout<<ans;
}

/////find all pairs in an array

#include<iostream>
using namespace std;

int main() {
   
   int nums[] = {1,2,3};
   
    for(int i = 0;i<3;i++)
    {
        for(int j=0;j<3;j++){  //or(int j=i;j<3;j++)  in the same question if we start j with i then this helps remove duplicates 
            cout<<nums[i]<<nums[j]<<endl;
        }
    }
    
}

//play around with loops and set them to run till 1/2 on i and j ...just to see what happens 
 //Question pair sum or two sum 


 ///Question - print all triplets in an array 
 //pair of 3 
 //burte force solution

 #include<iostream>
 using namespace std;
 
 int main() {
    
    int nums[] = {1,2,3,4};
    
     for(int i = 0;i<4;i++)
     {  
         for(int j=i;j<4;j++){  //j = i and k = j in order to remove duplicates
             for(int k =j;k<4;k++){
             cout<<nums[i]<<nums[j]<<nums[k]<<endl;
             }
             }
     }
     
 }

 //Question sort 0s and 1s in the array all 0 first then 1s
 //could just use sort


 //shift arrays element by one

 #include<iostream>
using namespace std;

int main() {
   
   int nums[] = {1,2,3,4};
   int temp = nums[0]; 
    for(int i = 3-1;i>=0;i--)
    {
        nums[i] = nums[i-1];
    }
    
    nums[0] = temp;
    
    for(int i = 0;i<4;i++)
        {
            cout<<nums[i];
        }
}

//////////////Array level 3 vid///////////////////////////////////



second diagonal print...//print the other diagnoal how ?

//transpose of a matrix ...vonvert columns to rows and rows t columns 
in this we notice that [0,0] index is swapped with [0,0]
                 while [0,1] with [1,0]
                        [2,0]     0,2
                        2,1     1,2


    so arr[i][j]  = = arr[j][i]
    this is the solution of transpose 


    void transpose(int arr[][4], int row, int col ) {
  
        for(int i=0; i<row; i++) {
          
          for(int j=i; j<col; j++) {  //since only the right triangle of the 2d array needs to be changed then ....we can use loop conditions similar to pyramid and swap wvalues
            
            swap(arr[i][j], arr[j][i]);
                                                            //small code but nuonced     
          }
        }
      }
