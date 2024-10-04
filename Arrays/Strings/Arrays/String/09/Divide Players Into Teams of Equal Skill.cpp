/*
Leetcode 2491:- Divide Players Into Teams of Equal Skill(Medium) 04-10-24

Explanation of the Code

The problem this code is solving involves grouping players based on their skills such that the sum of skills in each group is the same. The goal is to return the sum of products of the skills in each group or -1 if such grouping is not possible.

Initial Setup:

int n = skills.size();
ll sum = 0;
n = skills.size(): We get the size of the skills vector, which represents the number of players.
ll sum = 0: Initialize a variable sum to store the total sum of all the skill levels.

 Summing the Skills:
 for(int i = 0; i < n; i++) {
    sum += (ll)skills[i];
}

This loop iterates over the skills array and adds each skill value to the sum. Casting each skill to ll ensures that no overflow occurs for large skill values.

Group Check:

int m = n / 2;

if (sum % m != 0) {
    return -1;
}
m = n / 2: Since the problem requires dividing the players into pairs, m is the number of pairs we can form (half the total number of players).
If the total sum of the skills (sum) is not divisible by m, then it is impossible to divide the players into pairs with equal skill sums. In that case, the function returns -1.

Target Sum Per Pair:
ll find = sum / m;
find = sum / m: This calculates the target sum that each pair of players should have. Each pair of players must have a combined skill value equal to find.

Sorting the Skills:
sort(skills.begin(), skills.end());
Sorting the skills array helps to efficiently pair players with complementary skills. The idea is to pair the smallest skill player (skills[i]) with the largest one (skills[j]).

Two-Pointer Approach:
int i = 0;
int j = n - 1;
ll ans = 0;

i is initialized to the first player (smallest skill after sorting), and j is initialized to the last player (largest skill).
ans is initialized to store the sum of the products of the skills for each valid pair.

Forming Pairs and Checking Conditions:
while (i < j) {
    ll newSum = (ll)skills[i] + (ll)skills[j];

    if (newSum == find) {
        ans = (ll)ans + (ll)((ll)skills[i] * (ll)skills[j]);
        i++;
        j--;
    } else {
        return -1;
    }
}

The loop runs while i < j, meaning that we still have pairs to check.
newSum = skills[i] + skills[j]: This is the sum of the smallest skill (skills[i]) and the largest skill (skills[j]).
If the sum of the two skills (newSum) equals the target find, we calculate their product and add it to the answer (ans), then increment i and decrement j to move to the next pair.
If newSum does not equal find, the function returns -1 because it is impossible to form valid pairs that all sum up to find.

Returning the Result:
return ans;
If all pairs are valid, the function returns the sum of the products of the skills in each pair (ans).

*/

class Solution {
public:
    // Shorthand for long long to avoid overflow issues
    typedef long long ll;

    long long dividePlayers(vector<int>& skills) {
        int n = skills.size();  // Number of players

        ll sum = 0;  // Variable to store the total sum of all skill values

        // Calculate the sum of all skills
        for (int i = 0; i < n; i++) {
            sum += (ll)skills[i];  // Add each skill to the sum (cast to ll for safety)
        }

        int m = n / 2;  // The number of pairs that need to be formed

        // If the total sum is not divisible by the number of pairs, return -1
        if (sum % m != 0) {
            return -1;
        }

        // Find the target sum that each pair must have
        ll find = sum / m;

        // Use two-pointer approach: i for the smallest skill, j for the largest
        int i = 0;
        int j = n - 1;

        // Sort the skills to facilitate pairing
        sort(skills.begin(), skills.end());

        ll ans = 0;  // Variable to store the final result (sum of products of skills)

        // Loop through the players and form pairs
        while (i < j) {
            // Calculate the sum of the current pair (smallest and largest skill)
            ll newSum = (ll)skills[i] + (ll)skills[j];

            // If the sum of the pair matches the target sum
            if (newSum == find) {
                // Add the product of the current pair to the answer
                ans = (ll)ans + (ll)((ll)skills[i] * (ll)skills[j]);
                // Move to the next pair
                i++;
                j--;
            } else {
                // If the pair's sum doesn't match, return -1 (invalid grouping)
                return -1;
            }
        }
        // Return the final answer (sum of products of valid pairs)
        return ans;
    }
};
