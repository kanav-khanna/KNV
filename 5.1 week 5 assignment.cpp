242. Valid Anagram
////////https://leetcode.com/problems/valid-anagram/description/
//TC O(n+m);

Initially i tried doing this with XOR but thats approach is wrong .. it fails when 1st has aa and second string has bb they are differnt but XOX all of them and you get 0

//Frequency table method 
     class Solution {
public:
    bool isAnagram(string s, string t) {
        
        int freqtable[256] = {0}; ///ascii table has this many chars so we take 256 //this is kinda like a hash table 
        int ans = 0;

        for(int i =0;i<s.size();i++)
            {
                freqtable[s[i]]++; //do ++ for each occurance of a char in freq table for the tring s 
            }
        for(int i =0;i<t.size();i++)
            {
                freqtable[t[i]]--; //we cehck in string t ...and at the index of all the same cahrs we do -- if its all the same then it should be 0 
    
            }
        
        for(int i = 0;i<256;i++)
            {
                if(freqtable[i] != 0) //we check if all the indexs are 0 if not then ...return false not an anagram
                    {return false; 
                    }
            }
        return true;
        
    }
};

//917. Reverse Only Letters
https://leetcode.com/problems/reverse-only-letters/description/

2 pinter approach 

How do we find if the given index is a char or a apecial char ?
if((ch >=97 && ch <=112)||(ch>=65 && ch<90)) //check is alphabet is on the index and the alphabet could be lower case or upper case 

But dont be stupid just use the c++ inbuilt function isalpha() ...EZZ PZZ

#include <iostream>
#include <cctype>
using namespace std;
class Solution {
public:
    string reverseOnlyLetters(string s) {
        
        int high = s.size()-1;
        int low = 0;

        while(low<high)
            {   

                if(isalpha(s[low]) && isalpha(s[high]))
                    {
                        swap(s[low],s[high]);
                        low++;
                        high--;
                    }
                    else if(!isalpha(s[low])){
                        low++;
                    }
                    else
                    {
                        high--; 
                    }
                    
            }

        return s;
    }
};

/////////////////14. Longest Common Prefix
//https://leetcode.com/problems/longest-common-prefix/description/

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
       string ans;
       int i = 0;
        
       while(true)
        {
            char currentch = 0;

            for(auto str : strs)
                {
                    if(currentch == 0)
                        {
                            currentch = str[i];
                        }
                    else if(currentch != str[i])
                        {
                            currentch = 0;
                            break;
                        }
                }
            if(currentch == 0)
                {
                    break;
                }
            ans.push_back(currentch);
            i++;
        }
    return ans;
    }
};

//////////////////

345. Reverse Vowels of a String
https://leetcode.com/problems/reverse-vowels-of-a-string/description/

class Solution {
public:
    bool isVowel(char ch)
        {   
            ch = tolower(ch);
            if(ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' ||ch == 'u')
                {
                    return true;
                }
            else{
                return false;
            }
        }
    string reverseVowels(string s) {
        int n = s.size();
        int low = 0;
        int high = n-1;

        while(low <high)
            {
                if(isVowel(s[low]) && isVowel(s[high]))
                    {
                        swap(s[low],s[high]);
                        low++;
                        high--;
                    }
                else if(isVowel(s[low]) == 0)
                {
                    low ++;
                }

            else{
                    high--;
                }
            }
        return s;
    }
};

///////////5. Longest Palindromic Substring
https://leetcode.com/problems/longest-palindromic-substring/description/

Return palindromic sub string with the highest lenght


class Solution {
public:

    bool palindrome(string&s, int start, int end)
        {
                while(start<end)
                {
                    if(s[start]!=s[end])
                        {
                            return false;
                        }
                        start++;
                        end--;
                    
                }
            return true;
        }

    string longestPalindrome(string s) {
        string ans="";
        
        for(int i =0;i<s.size();i++)
            {
                for(int j =i;j<s.size();j++)  //j = i this is important i forgot it initialy 
                    {
                        if(palindrome(s,i,j))
                            {
                                string t = s.substr(i,j-i+1);
                                //ans = t.size() >ans.size()? t:ans;
                                
                                if(t.size() >ans.size())
                                    {
                                        ans =t;
                                    }
                            }
                    }
            }
        return ans;
        
    }
};

8. String to Integer (atoi)
//https://leetcode.com/problems/string-to-integer-atoi/description/

So we do hae a inbuilt c++ function for this 
int integer = atoi(s.c_str());  //s.c_str() this was done to convert the string to char ...then atoi to convert the string to a int 

//but in this funciton we need to implement the ATOI unctionality our selves 
1.ignore leading white space 
2.determine sign 
3.if digit found then conver to int ..how ?
4.till next non digit char is found 
5.special handeling nums out of range of int max or int min then we return min or max 

class Solution {
public:
    int myAtoi(string s) {
        int nums = 0,i=0,sign=1; //+ve

        while(s[i] == ' ')
            {
                i++;
            }

        if(i<s.size()&&(s[i] == '-' || s[i] == '+'))
            {
                sign = s[i] == '+' ? 1 : -1;
                i++;
            }
        
        while(i<s.size()&&isdigit(s[i]))
            {   
                if(nums> INT_MAX/10 || (nums == INT_MAX/10 && s[i]>'7'))
                    {
                        return sign == -1? INT_MIN : INT_MAX;
                    }
                nums = nums*10 + (s[i]-'0'); //this converts from string to int //string - int 0 = a int 
                i++;
            }
        return nums*sign;

    }
};

28. Find the Index of the First Occurrence in a String
https://leetcode.com/problems/find-the-index-of-the-first-occurrence-in-a-string/description/
//not the solution in hte vid but i like this one better 

class Solution {
public:
    int strStr(string haystack, string needle) {
        int n = haystack.size();
        int m = needle.size();

        for(int i =0;i<=n -m;i++)
            {
                if(haystack.substr(i,m) == needle)
                    {
                        return i;
                    }
            }
        return -1;
    }
};