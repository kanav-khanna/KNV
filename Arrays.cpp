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
//array extra class 
//2 pointer approch questions 
Question imput array has apositive and negative numbers the output should be negative numbers of left side and positive on right side 

Approch - 
1.sorting 
2.2 pointer approch 
3. temp array ...bad because too much space 

2 pointer approch - 

#include<iostream>
using namespace std;

int main() {
   
   int arr[] = {23,-7,12,-10,-11,40,60};
    int n = 7;
    int j = 0;
    
    
    for(int index = 0;index<7;index++)  //index is one pointer while j is the other pointer
    {
        if(arr[index]<0){
            swap(arr[index],arr[j]);
            j++;
        }
    }
    
    for(int index = 0;index<7;index++)
    {
        cout<<arr[index]<<endl;
    }
     
}

75. Sort Colors
// easiest solution just sort this thing lol
/// brute force solution 

class Solution {
    public:
        void sortColors(vector<int>& nums) { // this good solution
            int n = nums.size();
            int index = 0;
            int left = 0;
            int right = n-1;
    
            while(index <= right) {
    
                if(nums[index] == 0) {
                    swap(nums[index], nums[left]);
                    left++;
                    index++;
                }
                else if(nums[index] == 2) {
                    swap(nums[index], nums[right]);
                    right--;
                    //catch -> no need of index++
                    //index++
                }
                else {
                    index++;
                }
    
    
            }
    
        }
    };
    
/// @brief /////////////
class Solution {   // this solution is actually bubble sort which is why i dont understand how the damn thing works lol
    public:
        void sortColors(vector<int>& nums) {
            int n = nums.size();
    
            for(int i = 0; i<n-1;i++ )
                {
                    //cout<<"i="<<i<<endl;
                    for(int j=0;j<n-i-1;j++)  //why the n-i-1 ?
                        {
                            //cout<<"j="<<j<<endl;
                            if(nums[j]>nums[j+1])
                                {
                                    swap(nums[j], nums[j+1]);
                                }
                        }
                }
            
        }
    };
    
///////189. Rotate Array//////////////////////////
https://leetcode.com/problems/rotate-array/

done using swapping 

*****************When ever in a question they talk about rotating value or rotation ...then the % method is the most probable solution for this 
FORMULA INDEX + k %  n;  

///The below is my horrible solution and does not pass all the test cases 
class Solution {
    public:
        void rotate(vector<int>& nums, int k) {
            vector<int> temp;
    
            if(nums.size() == 0)
                {
                    return;
                }
    
            for(int i = nums.size()-1;i>k-1;i--)
                {   
                    temp.push_back(nums[i]);
                }
            for(int i = nums.size()-k-1;i>=0;i--)
                {   
                    nums[i+k] = nums[i];
                }
            int j = k-1;
            for(int i =0;i<k;i++)
               {   
                nums.at(i) = temp[j];
                j--;
               }
            //cout<<temp.back()<<"back";
        }
    };

    ////Better soluton from the vid 

    class Solution {
        public:
            void rotate(vector<int>& nums, int k) {
                int n = nums.size();
                vector<int> ans(n);  //need to specify the N size of the vector or else i will get a run time error
        
                for(int index = 0; index<n; index++)
                    {
                        int newindex = (index + k) % n; // this is the important formula for rotating INDEX + k %  n
                        ans[newindex] = nums[index];
                    }
        
                nums = ans;
                
            }
        };
///Leetcode 268 Missing Number

Brute force solution-
class Solution {
    public:
        int missingNumber(vector<int>& nums) {
    
            sort(nums.begin(), nums.end());
            for(int i = 0; i<nums.size(); i++)
                {
                    if(nums[i] == i)
                        {
                            continue;
                        }
                    else{
                        return i;
                    }
                }
            return nums.size();
        }
    };

//another way to solve this is using the arithmatic progression sum formula  O()
class Solution {
    public:
        int missingNumber(vector<int>& nums) {
            int sum = 0;
            int n = nums.size();
            
            for(int index=0;index<n; index++) {
                sum = sum + nums[index];
            }
    
            int totalSum = ((n)*(n+1))/2; //this is the ap formula 
            int ans = totalSum - sum; // the total sum - the sum of the array we are checking against 
            return ans;
        }
    };

    ///Good solution XOR to remove duplicates  //Need to redo this one tomorrow
    class Solution {
        public:
            int missingNumber(vector<int>& nums) {
        
                int ans = 0;
                //xor all array
                for(int i = 0; i<nums.size();i++)
                    {
                        ans^=nums[i];
                    }
                //xor all range 
                int n = nums.size();
        
                for(int i = 0; i<=n ;i++)
                    {
                        ans^=i;
                    }
                return ans;
            }
        };


////////2149. Rearrange Array Elements by Sign  //
https://leetcode.com/problems/rearrange-array-elements-by-sign/description/




///////2643. Row With Maximum Ones
https://leetcode.com/problems/row-with-maximum-ones/description/

/   