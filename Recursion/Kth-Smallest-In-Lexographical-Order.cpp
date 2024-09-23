/*

Problem - 44- Kth smalles In Lexographical Order


Explanation:
countSteps Function:

This function calculates how many numbers there are between two prefixes in lexicographical order. The numbers between prefix1 and prefix2 at the same depth are counted. Then, the function goes deeper into the tree by multiplying the prefixes by 10 to count the numbers at the next level.
This is done until prefix1 exceeds n.
findKthNumber Function:

The main goal of this function is to find the k-th smallest number in lexicographical order between 1 and n.
We start at curr = 1 (the smallest number in lexicographical order) and decrement k because 1 is already considered as part of the result.
The algorithm checks how many numbers are between curr and curr + 1 using the countSteps function.
If there are fewer numbers than k, we skip over these numbers and move to the next sibling (i.e., curr + 1).
If k is within the subtree of the current number, we move deeper into the tree (i.e., curr * 10).
Efficiency:

The algorithm leverages the lexicographical tree structure and skips large chunks of numbers by calculating steps instead of brute-forcing the entire order, making it very efficient for large values of n.
Time Complexity:

The overall time complexity is O(log n), where n is the upper limit of the numbers. This is due to the fact that each call to countSteps explores the numbers in a logarithmic manner.
This approach is optimal and ensures that the problem of finding the k-th smallest number in lexicographical order is solved efficiently.

*/

class Solution {
public:
    // Helper function to count the number of steps between two prefixes in the lexicographical order.
    int countSteps(int n, long prefix1, long prefix2) {
        int steps = 0;
        
        // Iterate while the first prefix is within the range of numbers [1, n]
        while (prefix1 <= n) { // Time complexity: O(log(n))
            // Calculate the number of valid numbers between prefix1 and prefix2 at the current depth
            // The number of valid steps is the difference between prefix2 and prefix1, 
            // or the difference between prefix1 and (n + 1) if it exceeds n
            steps += min((long)(n + 1), prefix2) - prefix1;
            
            // Move deeper into the lexicographical tree by multiplying by 10
            // This explores the next level of numbers starting with the same prefix
            prefix1 *= 10;
            prefix2 *= 10;
        }
        
        return steps;
    }

    // Main function to find the k-th smallest number in lexicographical order.
    int findKthNumber(int n, int k) {
        int curr = 1; // Start from the first number in lexicographical order (i.e., 1)
        k--; // We already consider the first number as the current result, so decrement k
        
        // While k remains greater than 0, continue to search for the k-th number
        while (k) { // Time complexity: O(log(n))
            // Calculate the number of lexicographical steps between 'curr' and 'curr + 1'
            int step = countSteps(n, curr, curr + 1); // Calculate how many numbers fall between curr and curr+1
            
            if (step <= k) { // If the number of steps is less than or equal to k
                // Move to the next sibling in the current lexicographical order (i.e., curr + 1)
                curr++; 
                
                // Subtract the number of steps as we have skipped over these numbers
                k -= step; 
            } else { // If the k-th number lies within the subtree of the current number
                // Move deeper into the tree by going down one level (curr becomes curr * 10)
                curr *= 10; 
                
                // Decrement k as we have explored the current node
                k--;
            }
        }
        
        return curr; // Return the k-th number found in lexicographical order
    }
};
