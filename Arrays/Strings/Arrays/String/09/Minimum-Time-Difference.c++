/*

16-09-24

1. Convert time strings to minutes:

The first part of the function loops through each time point in timePoints, extracting the hour and minute parts and converting the entire time into minutes.
For example, for the time 12:34, the conversion would be:
Hours: 12 * 60 = 720 minutes.
Minutes: 34 minutes.
Total: 720 + 34 = 754 minutes.

2. Sorting the times:
After converting all time points to minutes, the times are stored in the vector ans and sorted in ascending order.
Finding the minimum time difference:
The function then loops through the sorted times and calculates the difference between consecutive time points to find the smallest difference.

3.Since time is circular (e.g., the last minute of the day and the first minute of the next day can be close), it checks both the smallest difference between consecutive times and the difference between the first and last time points using (ans[0] + 1440 - ans[n-1]).

Time Complexity : O(nlog(n))
Space Complexity : O(n)
*/


class Solution {
public:
    int findMinDifference(vector<string>& timePoints) {
        // Vector to store converted time points in minutes
        vector<int> ans;

        // Loop through each time point string in the input
        for(auto &temp : timePoints){
            // Extract the hours part and convert it to an integer
            int a = temp[0] - '0';  // First digit of the hour
            int b = temp[1] - '0';  // Second digit of the hour

            // Combine a and b to get the total number of hours and convert to minutes
            int res = (a*10 + b) * 60; // Total minutes from hours

            // Extract the minutes part and convert it to an integer
            int c = temp[3] - '0';  // First digit of the minutes
            int d = temp[4] - '0';  // Second digit of the minutes

            // Combine c and d to get the total minutes
            int solve = c * 10 + d;

            // Add the minutes to the converted hours
            int result = solve + res;

            // Store the total minutes for the current time point
            ans.push_back(result);
        }

        // Sort the time points in ascending order of minutes
        sort(ans.begin(), ans.end());

        // Initialize the minimum difference to a large value
        int mini = INT_MAX;
        int n = ans.size();

        // Loop through the sorted time points to find the smallest difference between consecutive time points
        for(int i = 1; i < n; i++){
            mini = min(mini, abs(ans[i-1] - ans[i]));
        }

        // Return the smallest time difference, considering both consecutive times and the circular difference (between first and last time points in the day)
        return mini < (ans[0] + 1440 - ans[n-1]) ? mini : (ans[0] + 1440 - ans[n-1]);
    }
};
