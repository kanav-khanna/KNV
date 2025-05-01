//find unique element
//Each element occurs twice except one 

//Approch is we XOR all the elements together then all the same one will cancel out and you will only be left with the unique one 
//540. Single Element in a Sorted Array (did it but this is not the optimized approch)
You are given a sorted array consisting of only integers where every element appears exactly twice, except for one element which appears exactly once.
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
        for(int j=0;j<3;j++){  //or(int j=i;j<3;j++)  in the same question if we start j with i then this helps remove duplicates like you wont get 12 then 21
            cout<<nums[i]<<nums[j]<<endl;
        }
    }
    
}

//////////output 
for(int j=0;j<3;j++)
11
12
13
21
22
23
31
32
33
for(int j=i;j<3;j++)
11
12
13
22
23
33



//play around with loops and set them to run till 1/2 on i and j ...just to see what happens 
//did try this got only 1 element for the first 3 elements if i was 3/2 and j was 3

 //Question pair sum or two sum  //i may need to look at a better solution for this one
 //Given an array of integers nums and an integer target, return indices of the two numbers such that they add up to target.
 class Solution {
    public:
        vector<int> twoSum(vector<int>& nums, int target) {
            vector<int> answer;
            int sizeOfArray = nums.size();
            for(int i = 0; i < sizeOfArray; i++) {
                for (int j = i + 1; j < sizeOfArray; j++) {
                    if (nums[i] + nums[j] == target) {
                        answer.push_back(i);
                        answer.push_back(j);
                        return answer;
                    }
                }
            }
            return answer; //so i return an vector it just automatically takes all the values from it 
        }
    };

 ///Question - print all triplets in an array 
 //pair of 3 
 //burte force solution

 #include<iostream>
 using namespace std;
 
 int main() {
    
    int nums[] = {1,2,3,4};
    
     for(int i = 0;i<4;i++)
     {  
         for(int j=i;j<4;j++){  //j = i and k = j in order to remove duplicates //pretty much the same as print pairs but with another loop now 
             for(int k =j;k<4;k++){
             cout<<nums[i]<<nums[j]<<nums[k]<<endl;
             }
             }
     }
     
 }
//another question i should look at similart to the above one - 3 Sum – Triplet Sum in Array

//Question sort 0s and 1s in the array all 0 first then 1s
 //could just use sort
//283. Move Zeroes
Given an integer array nums, move all 0's to the end of it while maintaining the relative order of the non-zero elements.

//Brute force solution by me - O(n) time complexity for this solution but space is not the best 
class Solution {
    public:
        void moveZeroes(vector<int>& nums) {
            int j = 0;
            int count = 0;
            for (int i = 0; i < nums.size(); i++) {
                if (nums[i] == 0) {
                    count++;
                }
                if (nums[i] > 0 || nums[i]<0) { //<0 taken to handle cases with negative numbers //If number is non zero then we place it at start of array
                    nums[j] = nums[i];
                    j++;
                }
            }
            cout<<nums.size()-count;
            for(int i = nums.size()-1;i>(nums.size()-count)-1;i--)
                {   
                    //cout<<nums[i];
                    nums[i] = 0;
                    
                }
        }
    };

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
//print diagonal and secondary diagonal     
// C++ Program to print the Diagonals of a Matrix
//Time Complexity: O(n). 
#include <bits/stdc++.h>
using namespace std;

const int MAX = 100;
// Function to print the Principal Diagonal
void printPrincipalDiagonal(int mat[][MAX], int n)
{
    cout << "Principal Diagonal: ";
 
    for (int i = 0; i < n; i++) {
        // Printing principal diagonal
        cout << mat[i][i] << ", ";
    }
    cout << endl;
}
//Formula The row-column condition is row = numberOfRows - column -1.
void printSecondaryDiagonal(int mat[][MAX], int n)
{
    cout << "Secondary Diagonal: ";
    int k = n - 1;
    for (int i = 0; i < n; i++) {
        // Printing secondary diagonal
        cout << mat[i][k--] << ", "; //the k-- is equal to n - i - 1 from the formula with each I iteration the k-- is done this ensure the diagonal is printed from top right corner to inwards
    }
    cout << endl;
}

// Driver code
int main()
{
	int n = 4;
	int a[][MAX] = { { 1, 2, 3, 4 },
					{ 5, 6, 7, 8 },
					{ 1, 2, 3, 4 },
					{ 5, 6, 7, 8 } };

	printPrincipalDiagonal(a, n);
	printSecondaryDiagonal(a, n);
	return 0;
}




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
Question input array has apositive and negative numbers the output should be negative numbers of left side and positive on right side 
//move all the negative numbers to the left side of the array 
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
        cout<<arr[index]<<endl; //print output
    }
     
}

75. Sort Colors
// easiest solution just sort this thing lol
/// brute force solution 
//the below solution has the time complexity of O(n) so even though its broot force its pretty good 
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
    
/// @brief ///////////// bubble sort best case TC is O(n) ans worst case is O(n2)
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
FORMULA INDEX + k %  n;  (index is the current iteration, K is the number of steps that its being shifted and n is the size)

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
                        ans[newindex] = nums[index]; //keep the new arrangement in the new ans array 
                    }
        
                nums = ans; //copy temp to the original vector
                
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
class Solution { //ignore this solution
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

//the blow is not the best most optimized solution but it works lol
class Solution {
    public:
        vector<int> rowAndMaximumOnes(vector<vector<int>>& mat) { //2d vector declaration
            int n = mat.size();
            int onecount = INT_MIN;
            int rownum = 0;
            vector<int> ans;
            
    
            for(int i =0;i<n;i++)
                {
                    int count = 0; //count 0 before every row start
                    for(int j = 0; j<mat[i].size();j++) //i row then size is the size of row ///*****the size thing is import ant ofr 2 d vector traversal and not having this casued my initial issues
                        {    
                            if(mat[i][j] == 1)
                                {
                                    count++; //if 1 found then increment count 
                                }
    
                        }
                    //after row comletion compare count with onecount
                    if(count>onecount)
                        {
                            onecount = count;
                        rownum = i;
                        }
    
                }
            ans.push_back(rownum);
            ans.push_back(onecount);
    
            return ans;
        }
    };

/////////48. Rotate Image ////babar has seen this question alot and its VVVVVV important 
https://leetcode.com/problems/rotate-image/description/ 


// this is a 2 step proccess 
1. transpose the matrix //i think i did this question above were ...we take the upper triangle and change the values  
2. then reverse it 

class Solution {      //time complexity 
    public: 
        void rotate(vector<vector<int>>& matrix) { 
    
         int n = matrix.size();
         //transpose
        
        for(int i = 0;i<n;i++)
            {
                for(int j =i;j<matrix[i].size();j++)
                    {
                        swap(matrix[i][j], matrix[j][i]);    //n square time complexity 
                    }
            }
    
        //reverse all the rows 
    
        for(int i = 0; i<n; i++)
            { 
                reverse(matrix[i].begin(), matrix[i].end());  ...n square time complexity ....so overall this is n square time complexity 
            }
           
        } 
    
        
    };
 
//// function to reverse a vector 
void reverseVector(vector<int>& arr) {
        int n = arr.size();
        int start = 0;
        int end = n-1;

        while(start < end) {
            swap(arr[start], arr[end]);
            start++;
            end--;
        }

//Assignment- 

//////1. Two Sum/////////////////
//Given an array of integers nums and an integer target, return indices of the two numbers such that they add up to target.

class Solution {
    public:
        vector<int> twoSum(vector<int>& nums, int target) {
            vector<int> answer;
            int sizeOfArray = nums.size();
            for(int i = 0; i < sizeOfArray; i++) {
                for (int j = i + 1; j < sizeOfArray; j++) {
                    if (nums[i] + nums[j] == target) {
                        answer.push_back(i);
                        answer.push_back(j);
                        return answer;
                    }
                }
            }
            return answer; //so i return an vector it just automatically takes all the values from it 
        }
    };

///////724. Find Pivot Index


/////75. Sort Colors
for(int i = 0; i<n-1;i++ )
{
    //cout<<"i="<<i<<endl;
    for(int j=0;j<n-i-1;j++)
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

///268. Missing Number
class Solution {
    public:
        int missingNumber(vector<int>& nums) {
    
            int ans = 0;
            //xor all array
            for(int i = 0; i<nums.size();i++)  ///XOR the whole array 
                {
                    ans^=nums[i];
                }
            //xor all range 
            int n = nums.size();
    
            for(int i = 0; i<=n ;i++)
                {
                    ans^=i; //then xor with i ...which should be each number in the array ..canncells ou t and only leaves the number missing 
                }
            return ans;
        }
    };

//////////////287. Find the Duplicate Number
place each number at its index solution -
we place the number at its position and we swap with the number at its position
when we try  to move a duplicate to its position we will notice its already at its position so then a duplicate can be found  
class Solution {
    public:
        int findDuplicate(vector<int>& nums) {
         while(nums[0] != nums[nums[0]])  //while the element is not at its index in the array if it is stop and return --nums[nums[0]] index position of the number we are checking 
         {
             swap(nums[0],nums[nums[0]]);
         }
         return nums[0];
        }
    }
