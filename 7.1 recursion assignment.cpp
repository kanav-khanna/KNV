
Last occurance of a char 

Method 1 - learch from left to right
Method 2 - search from right to left since we need the last occurance 
Method 3 - STL strrchr() out of the box strig function that gives the last occurance of a char



//STRRCHR()
The function returns a pointer to the last location of chr in the string if the chr is found.
If chr is not found, it returns a NULL pointer.
char* ch = strrchr(str, 'i');
Time Complexity: O(n),
Space Complexity: O(1),


//We will implement method 1 and 2 recursively 
But time complexity of these solutions will be 
//Method 1 - 
#include<iostream>
using namespace std;

void lastoccrltr(string&s,char x,int &ans,int i) //by refrence so that the ans in main gets edited
{
    //base case
    if(i >=s.size())
    {
        return; 
    }
    //solve 1 case
    if(s[i] == x)
    {
        ans = i;
    }
    lastoccrltr(s,x,ans,i+1);
}

int main() {
    string s = "aabbssddf";
    int ans = -1;
    char x = 'd'; //the char i need to find
        
    lastoccrltr(s,x,ans,0);
    cout<<ans<<endl;
    return 0;
}

//Method 2 
#include<iostream>
using namespace std;

void lastoccrrtl(string&s,char x,int &ans,int i) //by refrence so that the ans in main gets edited
{
    //base case
    if(i < 0)
    {
        return; 
    }
    //solve 1 case
    if(s[i] == x)
    {
        ans = i;
        return;
    }
    lastoccrltr(s,x,ans,i-1);
}

int main() {
    string s = "aabbssddf";
    int ans = -1;
    char x = 'd'; //the char i need to find
        
    lastoccrrtl(s,x,ans,s.size()-1);
    cout<<ans<<endl;
    return 0;
}

//Reverse a trring using recursion 

void reverse(string&s,int start, int end)
    {
        if(start>=end)
            {
                return 0;
            }
        //ek case
        swap(s[start],s[end]);

        reverse(s,start+1,end-1);
    }
int main()
{
    string s;
    cin>>s;
    cout<<reverse(s,0,size()-1);
    return 0;

}

415. Add Strings - recursion poor solution
https://leetcode.com/problems/add-strings/

class Solution {
public:

    void addre(string&num1,int p1,string&num2, int p2, int carry, string&ans)
        {
          //base case
          if(p1<0&&p2<0)
            {
                if(carry!=0)
                    {   
                      ans.push_back(carry+'0');
                        
                    }
                return;
            }

           //solve 1 case
           int n1 = (p1>=0 ? num1[p1] : '0') -'0';
           int n2 = (p2>=0 ? num2[p2] : '0') -'0';
           int csum = n1+n2+carry;
           int digit = csum%10;
           carry = csum/10;
           ans.push_back(digit+'0');
           addre(num1,p1-1,num2,p2-1,carry,ans); //because answer will be sum of all recursive calls
         
        }
    string addStrings(string num1, string num2) {
            
            string ans ="";
            addre(num1, num1.size()-1,num2,num2.size()-1,0,ans);
            reverse(ans.begin(),ans.end());
            return ans;
    }
};