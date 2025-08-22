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
Why This Works:
In ASCII, each character has a numeric code. For example:

'a' = 97

'b' = 98

'c' = 99

...

'z' = 122

'A' = 65

'B' = 66

...

'Z' = 90

Now, the difference between 'a' and 'A' is:

'a' - 'A' = 97 - 65 = 32
This difference (32) is constant for all lowercase-uppercase letter pairs. So to convert 'd' (100) to 'D' (68), you subtract 'a' and add 'A':

'd' - 'a' + 'A' = 100 - 97 + 65 = 68 = 'D'

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

//Harder question based on the above question - https://leetcode.com/problems/remove-all-adjacent-duplicates-in-string-ii/description/
//1209. Remove All Adjacent Duplicates in String II
//bad soution ...
class Solution {
public:
    string removeDuplicates(string s, int k) {
        stack<pair<char, int>> st;

        for (char ch : s) {
            if (!st.empty() && st.top().first == ch) {
                st.top().second++;
            } else {
                st.push({ch, 1});
            }

            // If count == k, pop that group
            if (st.top().second == k) {
                st.pop();
            }
        }

        // Reconstruct the result string
        string result = "";
        while (!st.empty()) {
            result = string(st.top().second, st.top().first) + result;
            st.pop();
        }

        return result;
    }
};




//1910. Remove All Occurrences of a Substring
https://leetcode.com/problems/remove-all-occurrences-of-a-substring/description/
//the below code is not the best 
Keep looping as long as the substring part exists in s.

s.find(part) tries to find the first occurrence of part in the string s.

If part is found, find() returns the starting index of where it occurs.

If part is NOT found, find() returns a special value: string::npos.

What is string::npos?
string::npos is a constant that represents "no position".

It’s defined as the largest possible value for size_t (typically 4294967295 or -1 cast to size_t).

So if s.find(part) == string::npos, it means part was not found in s.


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

  KNV questions  //any other algos to find patterns in a string ?
            //time complexity and implemntation of the erase function
            //find funtion time complexity 

//680. Valid Palindrome II
https://leetcode.com/problems/valid-palindrome-ii/description/
//O(n) Time complexity for worst case 
 class Solution {
public:
    bool checkPalindrome(string s, int i, int j) {
        while( i<= j) {
            if(s[i] != s[j] ) {
                return false;
            }
            else {
                i++;
                j--;
            }
        }
        return true;
    }

    bool validPalindrome(string s) {
        int i = 0;
        int j = s.length()- 1;

        while( i <= j) {
            if(s[i] == s[j]) {
                i++;
                j--;
            }
            else{
                //s[i]!=s[j]
                //1 removal allowed
                //check plaindrome for remaining string after removal

                //ith character -> remove
                bool ans1 = checkPalindrome(s, i+1, j); //to remove i charecter so we user i+1
                //jth character -> remove
                bool ans2 = checkPalindrome(s, i, j-1); //we want to remove j and then check if palindrome 

                return ans1 || ans2; //depending on which bool is true then we return the ans
            }
        }
        //agar yha tk pohoche ho
        //iska matlab valid palindrome hai
        //iska matlab -> 0 removal
        return true;
    }
};


//another question i should do - 539. Minimum Time Difference
//https://leetcode.com/problems/minimum-time-difference/description/
//Hint convert all time to minutes then compare 
//get the hours and minutes seperately with sub str then stoi funtion need to convert string to integer 
//then get total minutes then sort the array 
//edge case ?

////My solution ....In the end the circular difference part .....was bad ..it is what it is 
class Solution {
public:
    int findMinDifference(vector<string>& timePoints) {
        //convert the time to minutes 
        vector<int> totalminutes;
        
        for(int i = 0;i<timePoints.size();i++)
            {
               string temphours = timePoints[i];
               int hours = stoi(temphours.substr(0,2));
               int minutes = stoi(temphours.substr(3,5)); 
               if(hours == 0 && minutes == 0)
                {
                    totalminutes.push_back((1440)+minutes);
                } 
                else{    
                totalminutes.push_back((hours*60)+minutes);
                }
                //cout<<totalminutes[i]<<endl;
            }
        //sort the leements is ascendeing order
        sort(totalminutes.begin(),totalminutes.end());
        //find minimum difference between all the elements 

        int minDiff = INT_MAX;
        for (int i = 0; i < totalminutes.size() - 1; ++i) {
            minDiff = min(minDiff, totalminutes[i + 1] - totalminutes[i]);
        }

        // Consider the circular difference between last and first element
        minDiff = min(minDiff, 24 * 60 - totalminutes.back() + totalminutes.front());
        
        return minDiff; 
    }
};


//647. Palindromic Substrings
//https://leetcode.com/problems/palindromic-substrings/description/
//VV IMP
/*Why ODD and EVEN?
Palindromes can be:

Odd-length: e.g. "aba" — center is the middle character (b)

Even-length: e.g. "abba" — center is between two characters (bb)

Odd Palindromes:

int oddKaAns = expand(s, i, i);
The center is one character (e.g. i = j = 2 for "aba")

Expands outward: s[i-1] == s[j+1]

Even Palindromes:

int evenKaAns = expand(s, i, i+1);
The center is between two characters (e.g. "abba" between b and b)

Starts with i and i+1, expands outward: s[i-1] == s[j+1]

The expand() Function

int expand(string s, int i, int j)
This function tries to expand outward from the center as long as the characters match.


while(i >= 0 && j < s.length() && s[i] == s[j]) {
    count++;
    i--;
    j++;
}
Example: s = "abba", starting at i=1, j=2
s[1]='b', s[2]='b' → match → count++

Move out: i=0, j=3 → s[0]='a', s[3]='a' → match → count++

Move out: i=-1, j=4 → i is out of bounds → stop

This found "bb" and "abba".

*/
class Solution {
public:
    int expand(string s,int i, int j) {
        int count = 0;

        while(i >= 0 && j < s.length() && s[i] == s[j] ) {
            count++;
            i--;
            j++;
        }
        return count;
    }
    int countSubstrings(string s) {
        int totalCount = 0;
        for(int i = 0; i < s.length(); i++ ) {
            //ODD
            int j = i;
            int oddKaAns = expand(s, i, j);  
            //EVEN
            j = i+1;
            int evenKaAns = expand(s, i, j);
            totalCount = totalCount + oddKaAns + evenKaAns;
        }
        return totalCount;
    }
};

//////////Level 4 array and string 
////////////////////////////////////////

 //2325. Decode the Message
 https://leetcode.com/problems/decode-the-message/description/

class Solution {
public:
    string decodeMessage(string key, string message) {
        char start = 'a';
        char mapping[280] = {0}; 

        for(auto ch:key) //this loop same as for(int i = 0;i<key.length();i++) 
            {    
                if(ch != ' ' && mapping[ch] == 0){ //this is why we inserted 0 to make sure mapping is only inserted once 
                mapping[ch] = start; //adding corrosponding alphabet in map for the key 
                start++; //iterate through a,b,c,d,e,
                }     
            }
        string ans;
        for(auto ch: message)
            {
                
                if(ch == ' ')
                    {
                        ans.push_back(' ');
                    }
                else{
                    
                     char decodechar = mapping[ch]; // What ???
                     //cout<<ch<<decodechar<<endl;
                     ans.push_back(decodechar);

                }
                    
            }
        return ans;
    }
}; 

//2391. Minimum Amount of Time to Collect Garbage
//https://leetcode.com/problems/minimum-amount-of-time-to-collect-garbage/description/
//this is a brute force solution and its not the best 
 class Solution {
public:
    int garbageCollection(vector<string>& garbage, vector<int>& travel) {

            int pickp = 0;
            int pickm = 0;
            int pickg = 0;

            int travelp = 0;
            int travelg = 0;
            int travelm = 0;

            int lastp = 0;
            int lastg = 0;
            int lastm = 0;

        for(int i = 0;i<garbage.size();i++)
            {
                string curr = garbage[i];
                for(int j = 0;j<curr.length();j++)
                    {
                        char ch = curr[j];

                        if(ch == 'P')
                            {
                                pickp++;
                                lastp = i;
                            }
                        
                        else if(ch == 'G')
                            {
                                pickg++;
                                lastg = i;
                            }
                        else if(ch == 'M')
                            {
                                pickm++;
                                lastm = i;
                            }
                } 
            }
        //calculate travel time 
        for(int i = 0;i<lastp;i++) 
            {
                travelp += travel[i];
            }
        for(int i = 0;i<lastg;i++) 
            {
                travelg += travel[i];
            }

        for(int i = 0;i<lastm;i++) 
            {
                travelm += travel[i];
            } 
    
        int ans = (pickp+travelp) + (pickg +travelg) + (pickm+travelm);
        return ans;
    }
};

//791. Custom Sort String
//https://leetcode.com/problems/custom-sort-string/description/


class Solution {
public:
    static string str;

    static bool compare(char char1, char char2)
        {   
            //This will return true if position of char 1 in str string is less than the position of char 2 in str string 
            //when true is returned then cahr 1 will be placed before cahr 2
            return(str.find(char1)<str.find(char2)); //this compares the given char order with the 2 chars paseed from sort ...checks their position in the char1 then moves accordingly
        }
    string customSortString(string order, string s) {
        str = order;
        sort(s.begin(), s.end(), compare); //compare function gets sent 2 chars each time ..then the compare function decides with of the 2 to keep ahead 
        return s;
    }
};
string Solution::str;

//890. Find and Replace Pattern
https://leetcode.com/problems/find-and-replace-pattern/description/

createmapping() turns any string into its normalized pattern (like "abb").

It’s called:

Once on the pattern

Once for each word

If both normalized forms match, the word follows the same character structure as the pattern.

Let me know if you'd like a visual walk-through of a specific example!



class Solution {
public:
    //this function normalizes all the words and patterns into a similar format 
    //so that we can compare them and find the solution
    void createmapping(string& str)
        {
            char start = 'a';
            char mapping[300] = {0};

            for(auto ch:str){
                if(mapping[ch] == 0)
                    {
                        mapping[ch] = start;
                        start ++;
                    }
            }

            for(int i =0;i<str.length();i++)
                {
                    char ch = str[i];
                    str[i] = mapping[ch];
                } 
        }

    vector<string> findAndReplacePattern(vector<string>& words, string pattern) {
        // normalize the patter
        vector<string> ans;
        createmapping(pattern);

        // word?
        for(string s:words)
            {
                string tempString = s;
                
                createmapping(tempString);
            
        
        if(tempString == pattern)
            {
                ans.push_back(s);
            }
        }
       return ans; 
    }

    

};

//Look into custom comparator
//Look into the extra questions given above 
