Divide and conqure 

BAsic example of this is Merger Sort (using recursion)

in merger sort we devide the array in the middle creating 2 parts the then 1st part and the 2nd part are sorted.
the 2 big parts created at first and further devided with each iteration.
After both parts have been sorted then they are put togather again for the final output.

void merge(int arr[],int s,int e)
    {
        int mid = (s+e)/2;

        int lenleft = mid-s+1;
        int lenright = e-mid;

        //create left and right array
        int *left = new int[lenleft];
        int *right = new int[lenright];

        //copy values from original array to left array 
        int k = s; //pointer to start of left array 
        
        for(int i=0;i<lenleft;i++)
            {
                left[i] = arr[k];
                k++;
            }
        //copy values from right of original array 
        k = mid+1;

        for(int i = 0;i<lenright;i++)
            {
                right[i] = arr[k];
                k++;
            }
        //actual merge logic
        //left array is already sorted
        //right array is already sorted 
        int leftindex= 0;
        int rightindex = 0;
        //area where i made a mistake ...it needs to be set to =s 
        int mainarrayindex = s;

        while(leftindex<lenleft && rightindex<lenright)
            {
                if(left[leftindex]<right[rightindex])
                    {
                        arr[mainarrayindex] = left[leftindex];
                        mainarrayindex++;
                        leftindex++;
                    }
                    else{
                        arr[mainarrayindex] = rightindex[rightindex];
                        mainarrayindex++;
                        rightindex++;
                    }
            }
        //2 more cases we need to handle 
        //1 - left array exhausted but right array still has elements 
        //this can happen when we have a odd number of elemts in the starting array 

        //the left elements we copy as it is to the final array 
        while(rightindex<lenright)
            {
                 arr[mainarrayindex] = rightindex[rightindex];
                        mainarrayindex++;
                        rightindex++;
            }



        //2 - right array exhausted but left array still has elemets 
        while(leftindex<lenleft)
            {
                 arr[mainarrayindex] = left[leftindex];
                 mainarrayindex++;
                 leftindex++;
            }
        
            //one more step ...since this stuff was created using heap memory the elements should be deleted 
            delete[] left;
            delete[] right;

    }

void mergesort(int arr[],int s,int e)
    {
            if(s>e){
                //invalid array
                return;
            }
            if(s = e)
            {   
                //single element in array
                return;
            }
        //break the array 
        int mid = (s+e)/2;
        
        //sort the left array 
        mergesort(arr,s,mid);
        //sort the right array 
        mergesort(arr,mid,e);

        //combine both the arrays 
        merge(arr,s,e);

    }

int main()
{
    int arr{} = {2,1,6,9,4,5};
    int size = 6;
    int s = 0;
    int e = size-1;

    mergesort(arr,s,e);
    for(int i = 0;i<size;i++)
    {
    cout<<arr[i]<<endl;
    }   
    return 0;
}