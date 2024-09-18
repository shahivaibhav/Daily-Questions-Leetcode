/*

Problem  884- Uncommon Words from Two Sentences(Easy)

Problem Explanation:
Given two sentences s1 and s2, you are tasked with finding all words that appear exactly once in either of the two sentences but not in both. In other words, a word is considered "uncommon" if it appears in only one sentence and has a frequency of 1.

For example:

Input:
s1 = "apple banana apple",
s2 = "banana orange".
Output:
["orange"],
since "orange" appears only once in s2, and "apple" and "banana" appear more than once between both sentences.

Detailed Breakdown:

Using unordered_map<string, int>:

We use an unordered map to store the frequency of each word across both sentences. The key is the word itself, and the value is the count of occurrences.
The map will store the word and its frequency as we split and process the sentences.
Splitting Sentences Using stringstream:

stringstream is a useful C++ class that allows us to split a string by whitespace. In this case, we use it to separate the words in both s1 and s2.
getline(ss, res, ' '): This function reads from the stringstream until it encounters a space ' ' and stores the word in the res variable. This process repeats for each word in the sentence.
Counting Word Frequencies:

For each word encountered, we increment its count in the unordered_map using mp[res]++. This step is done separately for s1 and s2, meaning words from both sentences are counted in the same map.
Finding Uncommon Words:

Once both sentences have been processed, we iterate over the map. If a word has a frequency of exactly 1, we add it to our result list (ans.push_back(word.first)).
A word with a frequency of 1 means it appears in only one of the two sentences.
Returning the Result:

Finally, the function returns the result vector, which contains all the uncommon words.


Time and Space Complexity:
Time Complexity:
O(n + m): The function processes two sentences, s1 and s2, of lengths n and m, respectively. Splitting the sentences into words and updating the frequency map takes linear time, i.e., O(n + m). Iterating through the map also takes O(n + m), so the overall complexity is linear with respect to the number of words in both sentences.

Space Complexity:
O(n + m): The space complexity is determined by the space used to store the words in the unordered_map and the result vector. In the worst case, all words are unique, and the map stores all words from both sentences, resulting in space usage proportional to the number of words in s1 and s2.

*/


class Solution {
public:
    vector<string> uncommonFromSentences(string s1, string s2) {
        // Step 1: Create an unordered_map (hashmap) to store word frequencies
        unordered_map<string, int> mp;

        // Step 2: Split the first sentence (s1) into words and store the frequency of each word
        stringstream ss(s1);  // stringstream to split the sentence by spaces
        string res = "";      // Temporary variable to store each word

        // Use getline to extract each word separated by spaces
        while (getline(ss, res, ' ')) {
            mp[res]++;  // Increment the count of the word in the map
        }

        // Step 3: Split the second sentence (s2) into words and store their frequencies
        stringstream dd(s2);  // Another stringstream to split the second sentence
        string temp = "";     // Temporary variable to store each word

        // Use getline to extract each word in s2 and update its frequency
        while (getline(dd, temp, ' ')) {
            mp[temp]++;  // Increment the count of the word in the map
        }

        // Step 4: Prepare a vector to store the result (uncommon words)
        vector<string> ans;

        // Step 5: Iterate over the map to find words that have a frequency of exactly 1
        for (auto &word : mp) {
            // If the word's frequency is 1, it is uncommon, so we add it to the result
            if (word.second == 1) {
                ans.push_back(word.first);  // Add the word to the result vector
            }
        }

        // Step 6: Return the result vector containing the uncommon words
        return ans;
    }
};
