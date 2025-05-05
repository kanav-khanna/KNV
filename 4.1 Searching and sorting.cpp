//Searching and sorting Level 1 

Linear search 
This algo checks each item one by one till the required item is found 

//TC - O(N) and n wil be the size of array 

Binary Search 
1. You can only do binary search on a sorted array (monotonic function) - which means either increasing or decreasing.
2. binary search requires the starting index ..ending index and the middle index of the.
3. MID = (start + end)/2; //or better method is to use int mid = start/2 + e/2;
4. With this the array gets devided into 3 parts left, mid and right.
5.Binary search first checks the middle index and if the number does not match target then it can choose to look at left part or
right part.
6. If the target number is bigger than the mid element then we look at the right side or else we look at the left side.
7. When ever we see a sorted array binary search needs to be considered as a possible answer.
***binary search advanced questions are mostly based on the understanding of saving the answer and going left and right based on it**

//Time complexity - With every iteration the array size becomes half 
O(Log base n) where n is the size of array


704. Binary Search (basic imlementation of binary search)
https://leetcode.com/problems/binary-search/description/

class Solution {
    public:
        int search(vector<int>& nums, int target) {
            int start = 0;
            int end = nums.size();
            int mid = (start+end)/2; //This line needs inprovement //integer can happen with this S+e-s/2; or int mid = start/2 + e/2
    
           if(nums.size() == 1) //this is to handle cases where start == end or size is 1 
                {
                    if(nums[0] == target)
                        {
                            return 0;
                        }
                    else{
                        return -1;
                    }
                }
    
           while(start<=end)    //A while loop needs to be used here and NOT a for loop  //dont do this shit for(start = 0;start<end;start++)
                {               //is not correct for binary search because binary search requires both start and end to move independently, 
                                //depending on the comparison with the target. A for loop increments start automatically each iteration, which breaks this control.
                    //found the element
                    if(nums[mid] == target)
                    {   //return index of found number
                        return mid;
                    }
                    //mid is smaller than target
                    else if(target>nums[mid])
                    { 
                        //go right
                        start = mid+1;
                        
                    }
    
                    //mid is bigger than target
                    else if(target<nums[mid])
                    {
                        //go left
                        end = mid-1;
    
                    }
    
                    //update mid value 
                    mid = (start+end)/2;
    
                }
            return -1;
        }
    };


//Find first occurance of a number in storted array 

arr = 10,20,30,30,30,30,40,50 //in this i would have to find the first occurance of 30 so target = 30 
ans = 2;

int start = 0;
int end = nums.size();
int mid = (start+end)/2;
int ans = -1; ///so if no element is found this just return -1


while(start<=end)
    {
        if(arr[mid] == target)
            {
                    ans = mid;
                    end = mid-1;  // this the same as normal left jao condition for binary search    

            }
        else if(target >arr[mid])
            {
                start = mid+1
            }
        else if(target < arr[mid])
            {
                end = mid-1;
            }
        mid = (start+end)/2;
    }
return ans;
//Last occurance of a number (similar code to above)
int start = 0;
int end = nums.size();
int mid = (start+end)/2;
int ans = -1; ///so if no element is found this just return -1


while(start<=end)
    {
        if(arr[mid] == target)
            {
                    ans = mid;
                    s = mid+1;  //Right jao becasue we looking for last occurance this time    

            }
        else if(target >arr[mid])
            {
                start = mid+1
            }
        else if(target < arr[mid])
            {
                end = mid-1;
            }
        mid = (start+end)/2;
    }
return ans;

//Find total occurance - total count of how amny times a element occurs in a array 

We can use the same code as above but the following formula needs to be used for total occurance 
//Total occurance = Last occurance - first occurance +1;

We need to usue the last to codes to find the first occrance and the last occurance then we can use the formula to ge the answer 


//Find missing element in a sorted array  //We did this answer before with XOR (leet code question is not a sorted array) - https://leetcode.com/problems/missing-number/submissions/1180595306/

//if we want a solution that runs less than O(n) then we use Binary search 

To solve this we look at a pattern the pattern being that the difference between the index and the number at that index will be 1
it will be 1 till the point we have all the right numbers ..after the missing number is reaced this pattern will break and it will become +2
This question does assume that the array is sorted and that the array holds number 1 to n not just some random nums


int start = 0;
int end = nums.size();
int mid = (start+end)/2;
int ans = -1; ///so if no element is found this just return -1


while(start<=end)
    {   
        int diff = arr[mid] - mid;

        if(diff == 1)
            {
                
                    s = mid+1;  //Right jao till diff not = 1    

            }
        else {
            ans = mid;
            end = mid-1;
        }
        mid = (start+end)/2;
    }

 if(ans+1 == 0)  //this code breaks on the last elements ...last element of array needs to handeled so if added 
    {
        return n+1;
    }
return ans+1; 

//peak element in a mountain array  // https://leetcode.com/problems/peak-index-in-a-mountain-array/submissions/1264882982/
If we break the array into 3 parts a , peak and b 
//Peak will be bigger than A and B 


class Solution {
    public:
        int peakIndexInMountainArray(vector<int>& arr) {
            int n = arr.size();
            int s=0;
            int e = n-1;
            int mid = s+(e-s)/2;
    
            while(s<e) //= removed here because in cases where e = mid ...not -1 ...can cause isues since e is in the while loop 
                {
                    if(arr[mid] < arr[mid+1])
                        {   //A wali line me hu 
                            //peak right ma exist karti hai 
                            s=mid+1;
                        }
                    else    
                    {   
                        //i am on B line or at the peak element 
                        e=mid; //...we move e to mid not mid -1 so we dont lose peak incase we are already on it 
                    }
                mid = s+(e-s)/2;
                }
            return s;
            
        }
    };


////5/5/2025 :)
VVVV imp question - 

Q- Find pivot element 

Pivot means - What ever is the maximum number in the rotated and storted array is the Pivot element

what a rotated and sorted array looks like - 12,14,16,2,4,6,8,10
Here the Pivot would be 16 
This array can be handles using binary search we can handle 12,14,16 as A then 2,4,6,8,10 as B then handle 16 and 2 seperately 

How to handle the pivot elements - 
When MID is at 2 then we can use the condition arr[mid] < arr[mid-1] since this condition will actually only be true for 2 and no other number in the array 
When MId is at 16 then we can use the condition arr[mid] >arr[mid+1] since this condition will only be true for 16 and no other number 
How to know if your on line A or B ? arr[start] > arr[mid] -> line b and if i am on line b the the answer exists on the left else case go right 

//this code will break in 1 case ....This code needs to handle the single element case  ...we can add if start == end return start  

//The below pivot element program is important becasue once we have the pivot element then we can apply binary search based on it
//Since binary search cannot be applied on pivot elements ...like 16 and 2 .....if we know the pivot we can apply binary search to A part and B
int find pivotindex(arr[], n)
    {
        int start = 0;
        int end = 0;
        int mid = (start+end)/2
        
        while(start<=end)
            {   
                if(arr[mid] < mid-1)
                    {
                        return mid-1;
                    }
                else if(arr[mid] > arr[mid+1]) //this code will break for cases with 2 indexes like [1,3] here this code tries to access a negative index
                    {                           //in the below code mid+1 < n was added to prevent this  
                        return mid+1;           //importnt these conditions are needed 
                    }
                else if(arr[start] > arr[mid]) //We compare with the first element to check out position //if this true then we on line B and we go left for pivot
                    {
                        end = mid-1; //left jao
                    }
                else{
                    start = mid+1; //right jao
                }
            }
        return -1
    }

33. Search in Rotated Sorted Array
https://leetcode.com/problems/search-in-rotated-sorted-array/submissions/1274961069/

class Solution {
    public:
    
       int findPivotIndex(vector<int>& arr) {
            int n = arr.size();
            int s = 0;
            int e = n-1;
            int mid = s + (e-s)/2;
    
            while(s <= e) {
                //corner case
                if(s == e) {
                    //single element
                    return s;
                }
    
                if(mid+1 < n && arr[mid] > arr[mid+1])
                    return mid;
                else if(mid-1 >=0 && arr[mid] < arr[mid-1])
                    return mid-1;
                else if(arr[s] > arr[mid] )  ///need to look into what happens if the past else if and else are exchanged we need = ?
                    e = mid - 1;
                else 
                    s = mid + 1;
                
                mid = s + (e-s)/2;
            }
            return -1;
    
        }
    
        int binarySearch(vector<int>& arr, int s, int e, int target) {
            int mid = s + (e-s)/2;
            while(s<=e) {
                if(arr[mid] == target) {
                    return mid;
                }
                if(target > arr[mid]) {
                    s = mid + 1;
                }
                else {
                    e = mid - 1;
                }
                mid = s + (e-s)/2;
            }
            return -1;
        }
    
        int search(vector<int>& nums, int target) {
            int pivotIndex = findPivotIndex(nums);
            cout << "Pivot Index us: " << pivotIndex << endl;
            int n = nums.size();
            int ans = -1;
    
            //search in A
            if(target >= nums[0] && target <= nums[pivotIndex]) {  //these if statements help decide which part A or B of the array should be searched 
                ans = binarySearch(nums, 0, pivotIndex, target);   //if target more than start and target less than pivot then we search from start to pivot
            }
            else {
                ans = binarySearch(nums, pivotIndex+1, n-1, target); //else we search from pivot +1 to the end 
            }
            return ans;
        }
    
    };

////////////////////69. Sqrt(x)
//Given a non-negative integer x, return the square root of x rounded down to the nearest integer. 
//The returned integer should be non-negative as well.
// do the below question but upto 3 deciaml places 
class Solution {
    public:
        int mySqrt(int x) {
            int start = 0;
            int end = x;
            long long int mid = start+(end-start)/2; //need to use this formula here because of the larger number after multiplication //long long used to hold the large number 
            int ans = -1;                             //initially i used the start/2 +end /2 formula this caused the progrm to exceed time 
    
            while(start<=end)
                {
                    //if mid is the answer
                    if(mid*mid == x)
                        {
                            return mid;
                        }
                    else if(mid*mid < x)
                        {   
                            ans = mid; //store the answer 
                            start = mid+1; //right jao
                        }
                    else{
                        end = mid-1; //left jao
                    }
                    mid = start+(end-start)/2;;
                }
            return ans;
    
        }
    };
    
//Binary search in a 2D array /////////////////////////////////////////
74. Search a 2D Matrix // https://leetcode.com/problems/search-a-2d-matrix/description/
//We just need to use the formula to convert 2d array to 1d array 
TC- log m*n
2d -> 1d c*i+j;

1d->2d i = mid/c
       j = mid%c

//code
       class Solution {
        public:
            bool searchMatrix(vector<vector<int>>& matrix, int target) {
                int row = matrix.size();
                int col = matrix[0].size();
                int n = row*col;
        
                int s = 0;
                int e = n-1;
                int mid = s + (e-s)/2;
        
                while(s <= e) {
                    int rowIndex = mid/col;
                    int colIndex = mid % col;
                    int currNumber = matrix[rowIndex][colIndex];
        
                    if(currNumber == target)
                        return true;
                    else if(target > currNumber ) {
                        //right;
                        s = mid + 1;
                    } 
                    else {
                        //left;
                        e = mid-1;
                    }
                    mid = s + (e-s)/2;
                }
                return false;
            }
        };