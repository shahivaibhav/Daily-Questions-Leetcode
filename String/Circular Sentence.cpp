/*

Leetcode 2490:- Circular Sentence(Easy)

Intuition:-

Understanding problem conditions:-
1. The last character of a word is equal to the first character of the next word.
    Example:- "leetcode exercises"
    Last character of "leetcode" is 'e' and first character of next word of "leetcode" that is "exercises" is also 'e'.

2. The last character of the last word is equal to the first character of the first word.
    Example:- "leetcode exercises sound delightful"
    First word = "leetcode", last word = "delightful"
    First character of first word = 'l'
    Last character of last woord  = 'l'

    so both are equal

Approach:-

We will traverse in the given string and check for both conditions.
We can make function for checking first condition for every word in input string.
And for second condition we can do it by brute force as we just need to check first and last character of input string.

Time Complexity :- O(n)
Space Complexity:- O(n)[We will make vector<string> for storing words for our optimal use]


*/

class Solution {
public:

    bool isNextCharacterSame(string &word1, string &word2){
        int n = word1.length() - 1;
        
        return word1[n] == word2[0];
    }

    bool isCircularSentence(string sentence) {
        
        int n = sentence.length();

        if(sentence[0] != sentence[n-1]){
            return false;
        }

        vector<string> words;
        
        stringstream ss(sentence);
        string word = "";

        while(getline(ss, word, ' ')){
            words.push_back(word);
        }

        for(int i = 1; i < words.size(); i++){

            string word1 = words[i-1];
            string word2 = words[i];

            bool temp = isNextCharacterSame(word1, word2);

            if(!temp){
                return false;
            }
        }

        return true;

    }
};