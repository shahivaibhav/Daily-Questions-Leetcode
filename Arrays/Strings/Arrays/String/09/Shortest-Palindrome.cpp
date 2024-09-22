/*

Problem 214- Shortest Palindrome(Hard)

Explanation for the Code
This solution is for the Shortest Palindrome problem, where you are tasked with finding the shortest palindrome by adding characters in front of a given string s.

Key Steps in the Solution:
1. Prefix Function (lps function):
The lps function computes the Longest Prefix Suffix (LPS) array for a given string, which is crucial for solving this problem. It uses the KMP (Knuth-Morris-Pratt) algorithm to find the longest palindrome that starts at the beginning of the string.
It initializes i and j as pointers. The v array keeps track of the length of the longest prefix that is also a suffix for each prefix of the string.
If characters at i and j match, it increments both i and j and updates the LPS value.
If there's no match, the function tries a shorter prefix by updating j to v[j - 1].
The function returns j, which gives the length of the longest prefix that is also a suffix.

2. String Manipulation:
The function shortestPalindrome creates a new string by concatenating s, a special delimiter (#), and the reverse of s. This helps in determining the part of the string that needs to be added to the front to make the entire string a palindrome.
The LPS value (from the lps function) gives the longest palindrome prefix. Based on this, we determine the characters that are not part of the palindrome, reverse them, and prepend them to the original string s to form the shortest palindrome.
3. Final Output:
The substring of s that needs to be reversed is found using the LPS value. That substring is reversed and concatenated to s to form the shortest palindrome.
Example Walkthrough:
Let’s assume s = "aacecaaa". The steps are as follows:

Reverse the string: "aaacecaa".
Concatenate the original and reversed strings with a delimiter:
oppo = "aacecaaa#aaacecaa".
Compute LPS:
The LPS of the string oppo will give us the length of the longest palindromic prefix in s.
Form the shortest palindrome:
Based on the LPS, we know that the last part of the string needs to be reversed and added to the front.
Time Complexity:
O(n), where n is the length of the input string s. This is due to the KMP preprocessing of the string.
Space Complexity:
O(n) for storing the LPS array and additional string manipulations.
Why This Works:
The core idea is to treat the problem as finding the longest prefix of s that is a palindrome. Once we identify this prefix, the remaining part of the string is reversed and prepended to the original string to make it a palindrome. Using the KMP algorithm helps efficiently find this longest palindrome prefix.

This is a smart application of the KMP prefix function to solve a string problem!

*/

class Solution {
public:
    static int lps(string str){
        int i=1,j=0;
        int n=str.size();
        vector<int>v(n);
        while(i<n){
            if(str[i]==str[j]){
                v[i]=++j;
                i++;
            }
            else{
                if(j!=0) j = v[j - 1];
                else i++;
            }
        }
        return j;
    }
    
    string shortestPalindrome(string s) {
        string oppo=s;
        reverse(oppo.begin(),oppo.end());
        oppo=s+'#'+oppo;
        int in=lps(oppo);
        string temp=s.substr(in);
        reverse(temp.begin(),temp.end());
        
        return temp+s;
    }
};