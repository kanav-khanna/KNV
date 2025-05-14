532. K-diff Pairs in an Array //https://leetcode.com/problems/k-diff-pairs-in-an-array/description/

//approch 
1. Brute force //just have 2 loops that iterate through each index and if diff is equal to k then count ++ for the answer 
2. 2 pointer approch //We just use 1 loop and a sorted array 
 i == 0 j == 1 if diff == k then i++ and j++ else if(diff >k) ..i++ elseif(diff<k)..j++ if i ==k the j ++//they are at same index dont find diff
 The above code wont give distinct solution ...so we need to use a pair data structure to fix that 

 2 pointer approch
    int findPairs(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int diff = 0;
        int i = 0;
        int j = 1;
        set<pair<int,int>> ans;

        while(j < nums.size())
        {
            int diff = nums[j] - nums[i];
            
            if(diff == k)
            {
                //print answer
                //cout<<nums[i]<<" "<<nums[j];
                ans.insert({nums[i], nums[j]});
                i++; 
                j++;
            } 
           else if(diff > k)
                {
                    i++;
                }     

           else if(diff < k)
                {
                    j++;
                } 
            if(i==j){
                j++;
            }

        }

        
        return ans.size();
    }

Binary search Solution which has the best time complexity 
O n*logn time complexity 
    int bs(vector<int>& nums,int start, int x) {
        int end = nums.size()-1;

        while(start<=end)
            {
                int mid = start +(end-start)/2;

                if(nums[mid] == x)
                    {
                        return mid;
                    }
                else if(x > nums[mid])
                    {
                        start = mid+1;
                    }
                else{
                    end = mid-1;
                }
            }
        return -1;
    }
    int findPairs(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        set<pair<int,int>> ans;

        for(int i = 0; i<nums.size();i++)
            {
                if(bs(nums, i+1, nums[i]+k) !=-1) //nums[i]+k is kinda our target here since we can write nums[i] -nums[j] =k or nums[i]+k same thing
                    {
                        ans.insert({nums[i], nums[i]+k}); //we insert into a set to remove any duplicates
                    }

            }
        return ans.size();
    }
};

//658. Find K Closest Elements https://leetcode.com/problems/find-k-closest-elements/description/

//Sort with respect to difference  ....brute force solution

//2 pointer approch 
In this we place pointers low and high at each end of the array then we move them forward based on if Low or High pointer has a 
Bigger value then we move it forward
This works because if we move forward from first index the difference decreases and if we move back from highest position same thing the Diff decreases 
while(high-low>=k)
if(x-a[l]>a[h]-x) //X is the number givven based on which we are findinf the diff 
    {
        Low++
    }
else{
    high--;
}

///2 pointer solution 
//TC - O(N-K) //Since we trverse the whole array till the k elements 
class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
    
        int low = 0;
        int high = arr.size()-1;

        while(high-low>=k)
            {
                if(x-arr[low]>arr[high]-x)
                    {
                        low++;
                    }
                else{
                    high--;
                }

            } 
        vector<int> ans;

        for(int i = low;i<=high;i++)
            {
                ans.push_back(arr[i]);
            }   
        return ans;
    }
};
//Binary search with 2 pointer 
In this method we take 2 pointers low and high.
High will point to the Lowest difference index = 0 
Low will point to the index next to high so high -1
We will move the pointers based on conditions to the K specified size to get the final answer

class Solution {
public:

    int lowerbound(vector<int>& arr, int x)
        {
            int start = 0;
            int end = arr.size()-1;
            int ans = end;


            while(start<=end){
                int mid = (start+end)/2; //check
                
                if(arr[mid]>=x)
                    {
                        ans = mid;
                        end = mid-1;
                    }
                else if(x>arr[mid])
                    {   

                        start = mid+1;
                    }
                else{
                    end = mid-1;
                }
            }
            return ans;
        }
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
    
        
        int high = lowerbound(arr, x);
        int low = high-1;

        while(k--)
            {   
                if(low<0)
                    {
                        high++;
                    }
                else if(high>=arr.size()){
                    low--;
                }
                else if(x-arr[low]>arr[high]-x)
                    {
                        high++;
                    }
                else{
                    low--;
                }

            } 
         
        return vector<int>(arr.begin()+low+1,arr.begin()+high);
    }
};
///////////////Exponential search ///doubling search///galloping search//straslic search///
Given a sorted array ...find x 
//Binary search has a time complexity of O(log n) exponential search aims to improve on this 
//If we search only on a sub part...we can improve time complexity since we are not searching on a larger array 

//in this we check if a[i] <= x if this confition is true then we do i =i*2 and keep checking till the condition is not true anymore
//then we can Give binary search the i index and the i/2 index as ending and starting points for its search thus making a sub array 

//Time complexity 
the exponential part would have a complexity of O(log m) ..the while loop (M being the position it goes up to)

int bs( int a[],int start, int end, int x)
    {   
        int mid = start+(end-start)/2;

        while (start<=end)
            {
                if(a[mid] == x)
                    {
                        return 0;
                    }
                else if(a[mid]<x)
                    {
                        start = mid+1;
                    }
                else if(a[mid]>x)
                    {
                        end = mid-1
                    }
                mid = start+(end-start)/2;
            }
        return -1;
    }


int expsearch(int a[],int n,int x){
            if(a[0] == x)
                {
                    return 0;
                }
            int i = 1;
            while(a[i] <= x && i<n]) //exponential search check for the number and increment the index by 2 each time 
                {
                    i=i*2;
                }
            return bs(a,i/2,min(i,n-i),x); //min function used to make sure we do not return an index larger than the array size ...it will return the minimum or the size of array by this 
}

int main()
{
    int arr = {3,4,5,6,11,13,14,56,70};
    int n = sizeof(a)/sizeof(int);
    int x = 13;
    int expsearch = (a,n,x);
    return 0;

}

///////Book allocation problem //////VVV IMP many different questions can be made from this one 
//Allocate number of pages hard on GFG ...but the problem has been changed 
//https://www.geeksforgeeks.org/problems/allocate-minimum-number-of-pages0937/1


Problem solved in the video 
we have an array of books with number of pages at each index 
M is given which is the number of students 
allocation on books needs to be contigous 
We need to distribute pages in a way that the difference is minimized ...so we look for 
the permutation where the maximum number of pages allocated to the students is minimum
//Return -1 if a valid ditribution is not possible like in the case of number of students > books then some wil be left without which is not valid 


//Brute force 
find all the permutations and then find the minimum of these and return the answer 
horrible time complexity 

//Better solution 
Define a search space 
In this the minimum will be 0 and the MAX will be the total number of pages since all allocations will always be less than the total number of books 
Then on this search space we can apply binary search  
Then try to find the sum 
if(not possible solution)
    start = mid+1
if(possible solution found then)
{
    //miminise the search space
}

//Code

bool ispossiblesolution(int arr[], int n , int m, int sol)
    {
        int pagesum = 0;
        int count =1;
        
        for(int i =0;i<n;i++)
            {
                if(A[i]>sol)
                    {
                        return false;
                    }
                if(pagesum +a[i] >sol){
                    count++;
                    pagesum=A[i];
                    if(c>M)
                        {
                            return false;

                        }
                }
                else{
                    pagesum+=A[i];
                }
            }
        return true;
    }


int findpages(int A[], int N, int M) //m is number of students and N is size of array 
    {
        if(m>n)     //Case where students are move and number of books is less 
            {
                return -1;   
            }
        int start = 0;
        int end = accumulate(A,A+N,0) //in built function to sum all array telements //start end and initial sum as parameters
        int ans = -1;

        while(start<=end)
            {
                int mid = (start+end)/2;

                if(ispossiblesolution(A,N,M,mid))
                    {
                        ans = mid; 
                        end = mid-1; //we look at left of search space

                    }
                else{
                    start = mid+1; we look at the right side of search space 
                }
            }
        return ans;
    }
