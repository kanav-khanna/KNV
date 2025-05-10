In a char array you do not need loops for input or output 
You can just take input once and that will fill the array 
and you can print without loop aswell 

chat ch[10];

cin>>ch ->takes input size of 10 at once 
cout<<ch ->prints all the indexes all at once 

//When we input a string into the array ..it will be terminated with a NULL char \0

So if we store dog in a char array then 0-2 index will contain DOG and then the 4th index will have a null char

If we use cin ...the only onput will be taken before tab or space 

If we want to take input with tabs or spaces then use the cin.getline function 

//Length of string 
count all the char till NULL ..that will be the if ch = \0 

If we try to find the size of a cin.getline(ch, 100) //in this case the spaces will also be counted

in built lenth function is strlen(ch) //String.h heaher file needed for this

//reverse a string 

int i = 0;
int j = n-1;

while(i<=j)
    {
        swap(arr[i], arr[j])
        i++;
        j--;

    }
//Convert to upper case 

Logic ...if we have any lower case char and the we do -a (minus itself) then + A(its capital) ..then we can get the capital of said char 

while(ch[index] != '\0'){
    ch currchar  = ch[index];

    if(currchar >= 'a' && currchar<='z')
        {
            ch[index] = currchar - 'a' + 'A'; //for everychar we add the A? yup :)
        }

}
index++

Q//Replace @ with a space 

Question - Check palendrome 


Strings - 
A string data type that holds char ....its size can be change dynamically during run time like an array 

//array and string class 2 
//1047. Remove All Adjacent Duplicates In String
//////////////////https://leetcode.com/problems/remove-all-adjacent-duplicates-in-string/

//approach new string where we build the answer 
//this can also be done using stack ...which is actually the better way  
//need to adabt this solution to use stack 

class Solution {
    public:
        string removeDuplicates(string s) {
            string ans = "";
            int index = 0;
    
            while(index<s.length())
                {
                    if(ans.length() >0 && ans[ans.length()-1] == s[index])
                    {
                        ans.pop_back();
                    }
                    else{
                        ans.push_back(s[index]);
                    }
                    index++;
                }
            return ans;
        }
    };

//Hardr question based on the above question - https://leetcode.com/problems/remove-all-adjacent-duplicates-in-string-ii/description/
//1209. Remove All Adjacent Duplicates in String II



//1910. Remove All Occurrences of a Substring
https://leetcode.com/problems/remove-all-occurrences-of-a-substring/description/
//the below code is not the best 

class Solution {
    public:
        string removeOccurrences(string s, string part) {
            
            while(s.find(part) != string::npos)  //npos is no poistion found //its value is ?
                {
                    //if inside loop that means the sub string does exist 
                    s.erase(s.find(part),part.length());
                }
            return s;
        }
    };

  Home work  ///what what named algos do we have in to find patterns in a string ?
            //time complexity and implemntation of the erase function and its time complexity 
            //find funtion time complexity 

            