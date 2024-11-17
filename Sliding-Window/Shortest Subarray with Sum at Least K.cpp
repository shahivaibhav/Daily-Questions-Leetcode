/*

Leetcode 862 :- Shortest Subarray with Sum at Least K[Hard]
Inution :-

This problem is a classic sliding window problem but we can not use it directly as our input array may contain negative numbers.
Before moving to what else will be required to solve this problem, first we should know what we can use already:-
-- We need to keep track of cummulative sum to compare with "k"

Now  understanding what else is required:-

Example:-nums = [84,-37,32,40,95], k = 167
        index = [0, 1,  2, 3, 4]

    sum  = 0;

    1.)index = 0, sum = 84
    2.)index = 1, sum = 37**[Problem arised here]
    3.)index = 2, sum = 69
    4.)index = 3, sum = 129
    5.)index = 4, sum = 224

    So if we use our typical sliding window our minimum Length will be 5[index 0 to 4] with sum 224
    But our actual answer should be 3[index 2 to 4] with sum 167

    So we can see that problem arised when our sum became less than previous sum{step 2}

    So basically we want our sum to be increasing.
    In such cases we use monotonic stack/deque/queue when we need something in a particular order.

Approach:- 

1.) cummulativeSum Vector for storing cummulative sum.
2.) Deque for keeping in check that our sum is strictly increasing(we will store indexes here)
3.) We will use sliding window for finding minimum Length answer.
4.) We will check cases if our curr sum is less than or equal to previous case then:-
    We will pop elements from back of deque[as new indexes are stored in back]
5.) We will also see if current minimum length can be decreased by checking if particular range sum is greater or equal to k by:-
    cummulativeSum[j] - cummulativeSum[dq.front()] >= k
6.) Return answer.

Time complexity:-  O(n)
Space complexity:-  O(n)

*/

class Solution {
public:
    int shortestSubarray(vector<int>& nums, int k) {
        
        int j = 0;
        int n = nums.size();

        deque<int> dq;
        vector<long long> cummulativeSum(n, 0);

        int minL = INT_MAX;

        while(j < n){

            if(j == 0){
                cummulativeSum[j] = nums[j];
            }else{
                cummulativeSum[j] = cummulativeSum[j-1] + nums[j];
            }

            if(cummulativeSum[j] >= k){
                minL = min(minL, j+1);
            }

            while(!dq.empty() && cummulativeSum[j] - cummulativeSum[dq.front()] >= k){
                minL = min(minL, j - dq.front());
                dq.pop_front();
            }

            while(!dq.empty() && cummulativeSum[j] <= cummulativeSum[dq.back()]){
                dq.pop_back();
            }

            dq.push_back(j);

            j++;
        }

        return (minL == INT_MAX) ? -1 : minL;
    }
};