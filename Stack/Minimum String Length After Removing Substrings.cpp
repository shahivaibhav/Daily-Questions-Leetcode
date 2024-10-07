/*
Leetcode 2696 :- Minimum String Length After Removing Substrings(Easy)

Data Structure Choice:

The solution uses a stack to store the characters while iterating through the string. The stack helps in managing the matching process for adjacent characters and makes it easy to "pop" or remove the pairs that match the pattern.
Main Logic:

The loop traverses the string character by character. At each step, it checks:
If the top of the stack is 'A' and the current character is 'B', it pops the 'A' off the stack, removing the pair "AB".
Similarly, if the top of the stack is 'C' and the current character is 'D', it pops the 'C', removing the pair "CD".
If neither of these conditions is met, the character is pushed onto the stack for further evaluation.
End Condition:

Once the entire string has been processed, the size of the stack represents the number of characters that remain after all possible removals.
Return Value:

The function returns the size of the stack, which is the length of the minimized string.

Time Complexity:
O(n), where n is the length of the string. Each character is pushed and popped from the stack at most once, resulting in linear time complexity.

Space Complexity:
O(n), for the stack that can potentially store all characters in the worst case if no pairs are removed.
*/

class Solution {
public:
    int minLength(string s) {
        stack<char> st; // A stack to store characters that we haven't matched with a pair.

        int i = 0; // Pointer to traverse the string
        int n = s.length(); // Length of the input string

        while(i < n){ // Loop through the entire string

            // If the stack is not empty and the top of the stack is 'A' and the current character is 'B', remove 'A' from the stack
            if(!st.empty() && st.top() == 'A' && s[i] == 'B'){
                st.pop();
            }
            // Similarly, if the top of the stack is 'C' and the current character is 'D', remove 'C' from the stack
            else if(!st.empty() && st.top() == 'C' && s[i] == 'D'){
                st.pop();
            }
            // If no matching pair is found, push the current character onto the stack
            else{
                st.push(s[i]);
            }
            i++; // Move to the next character in the string
        }

        // The size of the stack will be the length of the remaining string after all possible removals
        return st.size();
    }
};
