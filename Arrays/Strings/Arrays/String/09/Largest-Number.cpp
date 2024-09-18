/*
Problem 179: Largest Number(Medium)
The task is to arrange the numbers in such a way that they form the largest possible number. Given an array of non-negative integers, concatenate them in a specific order to form the largest possible number.

Custom Comparator:

We create a custom comparator function myComparator to decide the order of numbers when sorting.
For two numbers num1 and num2, we compare two concatenated strings:
s1 + s2: which represents num1 followed by num2
s2 + s1: which represents num2 followed by num1
If s1 + s2 is lexicographically greater than s2 + s1, then num1 should come before num2.
Sorting:

The sort function is used to sort the vector nums according to our custom comparator. This arranges the numbers in such a way that their concatenation forms the largest possible number.
Edge Case:

If the largest number in the sorted array is 0, it implies that all numbers are zero (e.g., [0, 0]). In this case, we directly return "0" because multiple zeroes should not lead to a result like "000".
Final Concatenation:

After sorting, we concatenate all the numbers in the vector nums into a single string ans, which represents the largest number.

Overall Time Complexity:
O(nlogn⋅k).

Overall Space Complexity:
O(n⋅k).

*/

class Solution {
public:
    string largestNumber(vector<int>& nums) {
        // Custom comparator to define the sorting order
        auto myComparator = [](int num1, int num2) {
            // Convert both integers to strings
            string s1 = to_string(num1);
            string s2 = to_string(num2);

            // Compare the concatenated results of (num1 + num2) and (num2 + num1)
            // If s1+s2 is greater, num1 should come before num2
            return s1 + s2 > s2 + s1;
        };

        // Sort the array of numbers based on the custom comparator
        sort(nums.begin(), nums.end(), myComparator);

        // Edge case: if the largest number is '0', return "0"
        // This handles cases like [0, 0] where the result should be "0" and not "00"
        if (nums[0] == 0) {
            return "0";
        }

        // Concatenate all numbers to form the final result
        string ans = "";
        for (auto &num : nums) {
            ans += to_string(num);
        }

        // Return the final concatenated string as the largest number
        return ans;
    }
};
