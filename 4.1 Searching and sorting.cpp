//Searching and sorting Level 1 

Linear search 
This algo checks each item one by one till the required item is found 

//TC - O(N) and n wil be the size of array 

Binary Search 
1. You can only do binary search on a sorted array (monotonic function) - which means either increasing or decreasing.
2. binary search requires the starting index ..ending index and the middle index of the.
3. MID = (start + end)/2;
4. With this the array gets devided into 3 parts left, mid and right.
5.Binary search first checks the middle index and if the number does not match target then it can choose to look at left part or
right part.
6. If the target number is bigger than the mid element then we look at the right side or else we look at the left side.
7. When ever we see a sorted array binary search needs to be considered as a possible answer.
***binary search advanced questions are mostly based on the understanding of saving the answer and going left and right based on it**

//Time complexity - With every iteration the array size becomes half 
O(Log base 2)


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
            e = mid-1;
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