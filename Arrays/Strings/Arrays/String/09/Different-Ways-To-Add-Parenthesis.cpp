/*

Different Ways to Add Parentheses (LeetCode 241)(Medium)

You are given an arithmetic expression as a string (like "2*3-4*5"). The task is to compute all the possible results by adding parentheses in different ways. This leads to different ways of interpreting the expression, and thus different results.

Approach:
This problem can be solved using recursion with a divide and conquer approach. The key is to break the expression at every operator (+, -, *) and recursively solve the left and right sub-expressions. Then, combine the results of these sub-expressions based on the operator.

How the Code Works:
Breaking the Expression:

The code uses a loop to scan through the string. Whenever it encounters an operator (+, -, *), it breaks the expression into two parts: left and right.
Recursion:

The solve function is called recursively on the left and right parts of the expression.
For example, for the expression "2*3-4*5", the expression is broken down into sub-expressions like "2" and "3-4*5".
Combining the Results:

The results of the left and right parts are combined using the current operator. For instance, if the operator is *, the result is left * right.
Base Case:

If there are no operators in the string, the string is converted into an integer using stoi() and added to the result. This is the base case of the recursion.
Result:

The recursive calls return all possible results of the expression for different placements of parentheses.
Example Walkthrough:
Let's walk through the code with an example:

Input: "2*3-4*5"

Step 1: The string is broken at the first operator (*), and we recursively solve "2" and "3-4*5".
Step 2: "2" is a number, so the base case is reached and 2 is returned.
Step 3: "3-4*5" is broken again into "3" and "4*5". These are further split and solved.
Step 4: All results are combined and returned in a vector.
Output: [-34, -14, -10, -10, 10]

Time Complexity:
O(Catalan Number): The time complexity of this recursive approach is related to the number of ways you can parenthesize the expression, which is governed by the Catalan Number. For an expression of length n, the number of ways to split it is proportional to O(2^n).

Space Complexity:
O(n): The recursion stack can go as deep as the number of operators in the expression.

*/

class Solution {
public:

    // Recursive function to compute all possible results from the expression
    vector<int> solve(string s) {
        vector<int> ans;  // Vector to store the results of subexpressions

        // Loop through the expression to find operators
        for (int i = 0; i < s.length(); i++) {
            // If we encounter an operator, split the expression
            if (s[i] == '+' || s[i] == '-' || s[i] == '*') {
                
                // Recursively solve the left and right sub-expressions
                vector<int> left = solve(s.substr(0, i));   // Left part of the expression
                vector<int> right = solve(s.substr(i + 1)); // Right part of the expression

                // Combine the results of the left and right sub-expressions
                for (auto &x : left) {
                    for (auto &y : right) {
                        if (s[i] == '+') {
                            ans.push_back(x + y); // Add the results
                        } 
                        else if (s[i] == '*') {
                            ans.push_back(x * y); // Multiply the results
                        } 
                        else {
                            ans.push_back(x - y); // Subtract the results
                        }
                    }
                }
            }
        }

        // If no operators were found, convert the string to an integer and add it to the result
        if (ans.empty()) {
            ans.push_back(stoi(s));
        }

        return ans;  // Return the vector of all possible results
    }

    // Main function to compute all the possible ways to add parentheses
    vector<int> diffWaysToCompute(string expression) {
        return solve(expression);  // Call the recursive function
    }
};
