Back tracking 
its when the recursive function returns ...when it returns and goes through the function call stack ..this is back tracking 
Like if you do a action doing recorusion and then nuliffy it while going back ....back tracking 

Backtracking has pretty bad time complexity 

Q- permutations of a string 

void printpermutation(string &str, int index) //this code breaks when i do pass by refrence why ?
{                                            //since in my refrence changes are made to the original string then when we do swapping this causes it to not work 
                                             //but while going back from each recursive call if we re swap the elements it would nullify our changes
    if(index >= str.length()){               //and this is what back tracking is pretty much ....we make changs before going back to old recursive calls 
        cout<<str<<" ";
        return;
    }

    for(int j = index; j<str.length();j++)
        {
            swap(str[index],str[j]);
            //recursion
            printpermutation(str,index+1);
            //back tracking
            swap(str[index],str[j]);
            
        }
}


int main()
    {
        string str = "abc";
        int index = 0;
        printpermutation(str, index);
    }