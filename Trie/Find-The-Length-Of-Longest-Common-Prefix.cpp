/*

Problem 3043: Length of Longest Common Prefix (Medium)

Explanation:
TrieNode Class:

This class defines the structure of a Trie node, where each node contains pointers to child nodes for the digits 0-9. This helps represent numbers as prefixes.
TrieNode Creation (TrieNode()):

This function initializes a new Trie node with all child pointers set to NULL, meaning there are no digits stored yet.
Insert Function:

The insert function adds a number into the Trie, one digit at a time. It ensures that each digit is stored at the appropriate level in the Trie, creating new nodes as needed.
Search Function (searchInTrie):

This function searches the Trie for the longest common prefix of a given number. It starts from the root and traverses through the Trie as long as the digits of the number match the digits stored in the Trie.
Longest Common Prefix (longestCommonPrefix):

The main function computes the longest common prefix between two arrays of integers by first inserting all the numbers from arr1 into the Trie and then checking for the longest common prefix with the numbers in arr2.

Time Complexity:
Insert Function: Inserting a number into the Trie takes O(d) time, where d is the number of digits in the number. Inserting all numbers from arr1 will take O(m * d), where m is the number of elements in arr1.
Search Function: Searching for the longest prefix takes O(d) time for each number. Searching for all numbers in arr2 will take O(n * d), where n is the number of elements in arr2.

Space Complexity:
The Trie stores all the digits of the numbers in arr1, so the space complexity depends on the number of nodes created, which is O(m * d) where m is the number of elements in arr1 and d is the number of digits in each number.

*/

// Definition of a Trie node class
class trieNode {
public:
    trieNode* children[10];  // Array to store pointers to child nodes, one for each digit (0-9)
};

// Function to create a new Trie node
trieNode* TrieNode() {
    trieNode* newNode = new trieNode();  // Allocate memory for the new node

    // Initialize all child pointers to NULL
    for (int i = 0; i <= 9; i++) {
        newNode->children[i] = NULL;
    }

    return newNode;
}

// Function to insert a number into the Trie
void insert(trieNode* root, int num) {
    trieNode* crawler = root;  // Start from the root of the Trie
    string word = to_string(num);  // Convert the number to a string for easier character manipulation

    // Iterate through each digit of the number (now represented as a string)
    for (auto &ch : word) {
        int idx = ch - '0';  // Convert the character to its integer value

        // If the current digit is not yet in the Trie, create a new Trie node
        if (crawler->children[idx] == NULL) {
            crawler->children[idx] = TrieNode();
        }

        // Move the crawler to the child node corresponding to the current digit
        crawler = crawler->children[idx];
    }
}

// Function to search the longest prefix of a number present in the Trie
int searchInTrie(int num, trieNode* root) {
    trieNode* crawler = root;  // Start from the root of the Trie
    string word = to_string(num);  // Convert the number to a string
    int length = 0;  // To track the length of the common prefix

    // Iterate through each digit of the number (as a string)
    for (auto &ch : word) {
        int idx = ch - '0';  // Convert the character to its integer value

        // If the digit exists in the Trie, increase the length of the common prefix
        if (crawler->children[idx]) {
            length++;
            crawler = crawler->children[idx];  // Move to the next node
        }
        else {
            break;  // Stop when there is no matching digit in the Trie
        }
    }
    return length;  // Return the length of the longest common prefix found
}

// Definition of a Trie node class
class trieNode {
public:
    trieNode* children[10];  // Array to store pointers to child nodes, one for each digit (0-9)
};

// Function to create a new Trie node
trieNode* TrieNode() {
    trieNode* newNode = new trieNode();  // Allocate memory for the new node

    // Initialize all child pointers to NULL
    for (int i = 0; i <= 9; i++) {
        newNode->children[i] = NULL;
    }

    return newNode;
}

// Function to insert a number into the Trie
void insert(trieNode* root, int num) {
    trieNode* crawler = root;  // Start from the root of the Trie
    string word = to_string(num);  // Convert the number to a string for easier character manipulation

    // Iterate through each digit of the number (now represented as a string)
    for (auto &ch : word) {
        int idx = ch - '0';  // Convert the character to its integer value

        // If the current digit is not yet in the Trie, create a new Trie node
        if (crawler->children[idx] == NULL) {
            crawler->children[idx] = TrieNode();
        }

        // Move the crawler to the child node corresponding to the current digit
        crawler = crawler->children[idx];
    }
}

// Function to search the longest prefix of a number present in the Trie
int searchInTrie(int num, trieNode* root) {
    trieNode* crawler = root;  // Start from the root of the Trie
    string word = to_string(num);  // Convert the number to a string
    int length = 0;  // To track the length of the common prefix

    // Iterate through each digit of the number (as a string)
    for (auto &ch : word) {
        int idx = ch - '0';  // Convert the character to its integer value

        // If the digit exists in the Trie, increase the length of the common prefix
        if (crawler->children[idx]) {
            length++;
            crawler = crawler->children[idx];  // Move to the next node
        }
        else {
            break;  // Stop when there is no matching digit in the Trie
        }
    }
    return length;  // Return the length of the longest common prefix found
}

class Solution {
public:
    // Function to find the longest common prefix between two arrays of integers
    int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) {
        trieNode* root = TrieNode();  // Create a Trie root node

        // Insert all numbers from the first array (arr1) into the Trie
        for (auto &num : arr1) {
            insert(root, num);
        }

        int result = 0;  // Variable to store the maximum length of the common prefix

        // For each number in the second array (arr2), check for the longest common prefix in the Trie
        for (auto &num : arr2) {
            result = max(result, searchInTrie(num, root));  // Update result with the maximum prefix length
        }

        return result;  // Return the maximum length of the longest common prefix
    }
};
