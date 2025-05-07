
//this thing has pretty much no real world application lol
//even the inbuilt sorting function in C++ dpes not use this shit 

TC- O(n square) //the algo is good but the time complexity us horrible which is why its pretty much never used 

//SWAP the adjecents till we get a sorted array in bubble sort
//starting from the first element we will look at each adjcement element and check if the one next to it is bigger 
//if it is bigger then we will swap the numbers in the array to get the final answer 

//In the first interation the 1st largest will be at its position ...and with each next iteration the next largest will be at its position 

code

void bubblesort(vector <int> &v)
    {
        int n = v.size();
        
        for(int i  = 0;i<n-1;i++)
            {
                for(int j=0;j<n-i-1;j++)
                    {
                            if(v[j]>v[j+1]) //flip the sign here to cahnge the order of sorting
                                {
                                    swap(v[j],v[j+1]);
                                }
                    }
            }
    }