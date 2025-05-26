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

//////////////205. Isomorphic Strings/
https://leetcode.com/problems/isomorphic-strings/description/

class Solution {
public:
    bool isIsomorphic(string s, string t) {
        int hash[256] = {0};
        bool istcharsmapped[256] ={0};

        for(int i =0;i<s.size();i++)
            {   cout<<s[i]<<endl;
                cout<<hash[s[i]]<<endl;

                if(hash[s[i]] == 0 && istcharsmapped[t[i]] == 0)
                    {   
                        cout<<"true";
                        hash[s[i]] = t[i];
                        istcharsmapped[t[i]] = true;
                    }
            }
        
        for(int i =0;i<s.size();i++){
            cout<<char(hash[s[i]]);
            if(char(hash[s[i]]) != t[i]) //hash is a int has so needs to be converted ....
                {
                    return false;
                }
        }

    return true;
    }
};


///Group Anagram 
//https://leetcode.com/problems/group-anagrams/
2 trings are anagram when the numeber of chars and its number of occurances is the same 

method 1 
if i sort all the strings then the 2 strigs that are an anagram will become equal ...
//This is not the most optimized solution
//TC - we have 2 loops + sorting + unordered map O(n k log k)

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        
        map <string, vector<string> > mp;

        for(int i = 0;i<strs.size();i++)
            {   
                string temp = strs[i];
                sort(temp.begin(),temp.end());
                mp[temp].push_back(strs[i]);
            }
        vector<vector<string>>ans;

        for(auto it = mp.begin();it!=mp.end();it++)
            {
                ans.push_back(it->second);
            }
    
        return ans;
    }
};

//2nd solution 
we need to reduce time comlexity by removing the storting 

we use a hash[256];
we make a hash map for a and a hach map for b if both are the same then they are anagram
TC- O(n*k)
class Solution {
public:
    std::array<int, 256> hash (string s)
        {
            std::array<int, 256> hash ={0};

            for(int i = 0;i<s.size();i++)
                {
                    hash[s[i]]++;
                }

            return hash;
        }
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        
        map <std::array<int,256>, vector<string> >mp;


        for(int i = 0;i<strs.size();i++)
            {      string temp = strs[i];
                mp[hash(temp)].push_back(strs[i]);
            }
        vector<vector<string>>ans;

        for(auto it = mp.begin();it!=mp.end();it++)
            {
                ans.push_back(it->second);
            }
    
        return ans;
    }
};  

///////////////

class Solution {
public:
    int compress(vector<char>& chars) {
        int index = 0; 
        int count = 1;
        int prev = chars[0];

        for(int i =1;i<chars.size();i++)
            {
                if(chars[i] == prev)
                    {
                        count++;
                    }
                else{
                    chars[index++] = prev;

                    if(count>1)
                        {   int start = index;
                            while(count)
                                {
                                    chars[index++] = count%10 + '0'; //This is because each digit needs to be stored in a ////different index and the + '0' is to convert an int to string 
                                    count /=10;
                                }
                                reverse(chars.begin()+start,chars.begin()+index); //we have to reverse becasue when we devide to seperate the digits
                                                                                  //the answer is the right side digit...so reverse is the right ans 
                        }
                    prev = chars[i];
                    count = 1;
                }
            }  

        chars[index++] = prev; //this part is just to handle cases where the loop ends by the final values were not written 
       if(count>1)
                        {   int start = index;
                            while(count)
                                {
                                    chars[index++] = count%10 + '0'; //This is because each digit needs to be stored in a ////different index and the + '0' is to convert an int to string 
                                    count /=10;
                                }
                                reverse(chars.begin()+start,chars.begin()+index);
                                    
                        }
        

        return index; 
    }
};

//12. Integer to Roman
https://leetcode.com/problems/integer-to-roman/

Map iterate bigger to smaller


class Solution {
public:
    string intToRoman(int num) {
        string romansymbols[] = {"M","CM","D","CD","C","XC","L","XL","X","IX","V","IV","I"};
        
        int values[] = {1000,900,500,400,100,90,50,40,10,9,5,4,1};

        string ans="";

        for(int i =0;i<13;i++)
        {
                    while(num>=values[i])
                        {
                            ans+=romansymbols[i];
                            num-=values[i];
                        }
        }

    return ans;
    }
};

///6. Zigzag Conversion
https://leetcode.com/problems/zigzag-conversion/description/

class Solution {
    public:
        string convert(string s, int numRows) {
    
            if (numRows == 1) {
                return s;
            }
    
            vector<string>zigzag(numRows);
    
            int i = 0, row = 0;
            bool direction = 1; // 1 means top to bottom
    
            while (true) {
                if (direction == 1) {
                    while (row < numRows && i < s.size()) {
                        zigzag[row].push_back(s[i]);
                        i++;
                        row++;
                    }
                    row = numRows - 2;
                }
    
                else {
                    while (row >= 0 && i < s.size()) {
                        zigzag[row].push_back(s[i]);
                        i++;
                        row--;
                    }
    
                    row = 1;
                }
    
                if (i >= s.size()) {
                    break;
                    
                }
                direction = !(direction);//i messed up here ...i was setting it to 0 but need to use ! so the  value is flipped 
            }
    
            string ans = "";
            for (int i = 0; i < zigzag.size(); i++) {
                ans += zigzag[i];
            }
    
            return ans;
        }
    };


//////179. Largest Number
https://leetcode.com/problems/largest-number/description/

class Solution {
public:

    static bool decrease(string a, string b)
        {   
            string t1 = a+b;
            string t2 = b+a;
            return t1>t2;
        }
    
    string largestNumber(vector<int>& nums) {
        vector<string>snums;
        string ans = "";

        for(auto n:nums)
            {   cout<<n;
                snums.push_back(to_string(n));
            }   
        
        sort(snums.begin(),snums.end(),decrease);
    
        if(snums[0] == "0")
            {
                    return "0";
            }
        for(auto str:snums)
        {
            ans+=str;
            //cout<<str;
        }
        return ans;
    }
};

767. Reorganize String
//https://leetcode.com/problems/reorganize-string/description/

//Method 1 
Using priority queue ....O(nlogn) //This should be revisited later when i story priority queue.

//Method 2 Greedy 

class Solution {
public:
    string reorganizeString(string s) {
        int hash[26] = {0};

        for(int i =0;i<s.size();i++)
            {
                hash[s[i]-'a']++;
            }
        
        char max_freq_char;
        int max_freq = INT_MIN;
        for(int i =0;i<26;i++)
            {
                if(hash[i]>max_freq)
                    {
                        max_freq= hash[i];
                        max_freq_char = i + 'a';
                    }
            }
        int index = 0;

        while(max_freq>0 && index <s.size())
                {
                    s[index] = max_freq_char;
                    max_freq--;
                    index +=2; 
                }
            if(max_freq != 0)
                {
                    return "";
                }
            hash[max_freq_char - 'a'] = 0;

        //place the rest of the chars 
        for(int i = 0;i<26;i++){
            while(hash[i]>0)
            {
                index = index >=s.size()?1:index;
                s[index] = i+'a';
                hash[i]--;
                index +=2;
            }
        }
        return s;
    }
};