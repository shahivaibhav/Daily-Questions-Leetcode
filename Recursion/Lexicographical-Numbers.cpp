/*
Problem 386 : Lexicographical Numbers(Medium)
Problem Description:
The function lexicalOrder generates numbers from 1 to n in lexicographical (dictionary) order. This can be thought of as the order in which strings are arranged in a dictionary, but we are doing it for numbers.

Approach:
The approach uses Depth-First Search (DFS) to explore and build numbers in lexicographical order. The solve function recursively constructs numbers by appending digits (0-9) to the current number and stops when it exceeds the limit n.

Explanation of the Code:
solve Function:

Base case: If the number exceeds the limit (num > limit), the recursion stops.
Recursive step: For each valid number, it appends the digits from 0 to 9 to the current number (num), forms a new number (curr_num), and recurses if the new number is valid (i.e., does not exceed n).
This function ensures that all numbers are explored in lexicographical order.
lexicalOrder Function:

It initializes the result vector res.
It starts the DFS process by calling solve for the starting numbers 1 to 9 because lexicographical order starts with these digits.

Time Complexity:
The time complexity is O(n) because we are visiting each number between 1 and n once.

Space Complexity:
The space complexity is O(n) due to the result vector res which stores all the numbers from 1 to n. Additionally, the recursion stack can go as deep as the number of digits in n, but this is typically bounded by O(log(n)).

*/


class Solution {
public:
    // Recursive function to explore numbers in lexicographical order
    void solve(int num, vector<int> &res, int limit) {
        // If the current number exceeds the limit 'n', stop recursion
        if(num > limit) {
            return;
        }

        // Add the valid number to the result list
        res.push_back(num);

        // Loop through digits 0-9 to generate new numbers by appending to 'num'
        for(int i = 0; i <= 9; i++) {
            int curr_num = 10 * num + i;  // Form the new number

            // If the new number exceeds the limit, stop further recursion for this branch
            if(curr_num > limit) {
                return;
            }

            // Recur with the new number to continue generating lexicographically
            solve(curr_num, res, limit);   
        }
    }

    // Main function to generate numbers in lexicographical order up to 'n'
    vector<int> lexicalOrder(int n) {
        vector<int> res;  // Result vector to store the numbers

        // Start the DFS process for numbers starting with digits 1 to 9
        for(int i = 1; i <= 9; i++) {
            solve(i, res, n);
        }

        // Return the final result vector containing numbers in lexicographical order
        return res;
    }
};
