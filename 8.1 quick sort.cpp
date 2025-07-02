//QUick SORT
BIG O n square time complexity .....which is not great ...in average case in nlog n
1. pick a pivot 
2. place pivot suck that the elements to the right of pivot > a[pivot];
3. element left of pivot element should be smaller than pivot 

//New way to do partition = 
Example- 
7,2,1,8,6,3,5,4

pivot = end;
pivot -> 7(7th index = 4)
2. i = start-1;
   j = start;

3. pivot now needs to be placed in a way that left of pivot shoud be smaller than pivot 
While(i<pivot)
    {
        if(a[j] < a[pivot])
            {
                i++;
            }
            swap(a[i],a[j]);
            
            j++;
    }


//code using re ursion 
//HE was going a GFG quick sort question (quick sort)

if(start>=end) return;
int pivot = start-1;
int j = start;

while(j<pivot)
    {
        if(a[i]<a[pivot])
            {
                i++;
                swap(a[i],a[j]);

            }
        j++
    }
    i++
    //i is the right position for the pivot element which is why we swap it 
    swap(a[i],a[pivot]);
    quicksort(a,start,i-1);
    quicksort(a,i+1,end);
