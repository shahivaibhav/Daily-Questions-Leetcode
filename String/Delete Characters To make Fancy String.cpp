/*

Leetcode 1957:- Delete Characters to Make Fancy String(Easy)

# Intuition
Problem statement is pretty straight forward. We do not need to do anything extra, i.e., we have to delete character if it is repeated 3 time consecutively.

# Approach
1. By problem statement, we understand we have to track previous characters.
2. We also need to track their count.

So we will define two variables -> ch & count (ch will track previous repeated character and count will track its count)

We will traverse the string and if count == 3 then we will not add that character in our resultant string.
Else we will keep updating new character in ch variable and keep adding it to resultant answer string.

Example dry run:-

Input: s = "aaabaaaa"

Initially ch is empty and count is 1(because every character will appear once so count will be 1).

We start traversing string:-

1.) i = 0, ch = ' ', count = 1 , ans = "", s[i] = 'a' -> ch is empty so we will add current character in ans and ch = 'a'

2.) i = 1, ch = 'a', count = 2 , ans = "a", s[i] = 'a' -> count is 2 so we will add current character in ans and ch = 'a'

3.)  i = 2, ch = 'a', count = 3 , ans = "aa", s[i] = 'a' -> count is 3 so we will not add current character in ans and ch = 'a' and decrease count as we have not added current character.

4.)  i = 3, ch = 'a', count = 2 , ans = "aa", s[i] = 'b' -> count is 2 so we will add current character in ans and ch = 'b' as ch changes so count = 1

5.)  i = 4, ch = 'b', count = 1 , ans = "aab", s[i] = 'a' -> count is 1 so we will add current character in ans and ch = 'a' as ch changes so count = 1

6.)  i = 5, ch = 'a', count = 1 , ans = "aaba", s[i] = 'a' -> count is 2 so we will add current character in ans and ch = 'a' 

7.)  i = 6, ch = 'a', count = 2 , ans = "aabaa", s[i] = 'a' -> count is 3 so we will not add current character in ans and ch = 'a' and decrease count as we have not added current character. 

8.)  i = 7, ch = 'a', count = 2 , ans = "aabaa", s[i] = 'a' -> count is 3 so we will not add current character in ans and ch = 'a' and decrease count as we have not added current character.

Traversal is over and our ans is "aabaa"

# Complexity
- Time complexity:
 O(n)

- Space complexity:
 O(n)[Resultant string space]

*/

class Solution {
public:

    string makeFancyString(string s) {
        
        int n = s.length();

        char ch   = ' ';
        int count = 1;

        string res = "";

        for(int i = 0; i < n; i++){ 

            if(ch != ' ' && ch == s[i]){
                count++;
            }

            if(count == 3){
                count = 2;
                continue;
            }

            res += s[i];

            if(ch != s[i]){
                ch = s[i];
                count = 1;
            }
            
        }

        return res;

    }
};
