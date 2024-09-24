/*
Problem 2707 : Extra Character in a string(Medium)

Explanation of the Approach:
Dynamic Programming (DP):

The function solve uses recursion with dynamic programming to find the minimum number of extra characters that need to be removed.
The DP array dp stores results for each index, so if we encounter the same state again, we can return the stored result instead of recalculating it.
Recursive Logic:

At each index idx, the algorithm explores all possible substrings starting from idx and checks if the substring exists in the dictionary (st).
If the substring is found, we make a recursive call to process the remaining part of the string.
The worst-case scenario (if no valid substring is found) is to remove the character at idx, which is why the initial value of res is set to 1 + solve(s, idx + 1, st).
Dictionary Lookup:

The dictionary is stored in an unordered set (st) for fast lookups. This allows the algorithm to quickly determine if a substring is a valid word.
Base Case:

The recursion ends when idx reaches or exceeds the length of the string, meaning we’ve processed all characters.

Time Complexity:

The time complexity is roughly O(n^2), where n is the length of the string s. This is because we potentially check all substrings starting at each index i.

Space Complexity:

The space complexity is O(n) for storing the DP array and the recursion stack.
Example:
For s = "applebanana" and a dictionary containing words ["apple", "banana"], the function will find the best way to partition the string using words from the dictionary and minimize extra characters.

*/

class Solution {
public:
    // Declare the dp array of size 51 (as per the problem's constraints)
    int dp[51];

    // Recursive function to solve the problem
    int solve(string s, int idx, unordered_set<string>& st) {
        // Base case: if we reach the end of the string, return 0
        if (idx >= s.length()) {
            return 0;
        }

        // If we have already calculated the result for this index, return the cached result
        if (dp[idx] != -1) {
            return dp[idx];
        }

        // Initialize result by considering the worst case (removing this character)
        int res = 1 + solve(s, idx + 1, st);

        // Explore all substrings starting from index 'idx'
        for (int i = idx; i < s.length(); i++) {
            string curr = s.substr(idx, i - idx + 1);  // Generate the substring

            // If the current substring is found in the dictionary, 
            // calculate the minimum result by recursively solving for the remaining string
            if (st.count(curr)) {
                res = min(res, solve(s, i + 1, st));
            }
        }

        // Store the result in dp array for future reuse and return the result
        return dp[idx] = res;
    }

    // Function to find the minimum number of extra characters needed
    int minExtraChar(string s, vector<string>& dictionary) {
        // Insert all dictionary words into an unordered set for fast lookup
        unordered_set<string> st(dictionary.begin(), dictionary.end());

        // Initialize the dp array with -1 (to signify uncalculated states)
        memset(dp, -1, sizeof(dp));

        // Call the solve function starting from index 0
        return solve(s, 0, st);
    }
};
