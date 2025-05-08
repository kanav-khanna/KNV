532. K-diff Pairs in an Array //https://leetcode.com/problems/k-diff-pairs-in-an-array/description/

//approch 
1. Brute force //just have 2 loops that iterate through each index and if diff is equal to k then count ++ for the answer 
2. 2 pointer approch //We just use 1 loop and a sorted array 
 i == 0 j == 1 if diff == k then i++ and j++ else if(diff >k) ..i++ elseif(diff<k)..j++ if i ==k the j ++//they are at same index dont find diff
 The above code wont give distinct solution ...so we need to use a pair data structure to fix that 

 //2 pointer approch
    /*int findPairs(vector<int>& nums, int k) {
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

//Binary search Solution which has the best time complexity 
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