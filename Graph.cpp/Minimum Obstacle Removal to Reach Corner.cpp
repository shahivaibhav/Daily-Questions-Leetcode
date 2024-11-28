/*

Leetcode 2290:- Minimum Obstacle Removal to Reach Corner(Hard)

# Intuition
The basic idea was to consider the **obstacles as weight** in graph. So, we wanted to find the **shortest path between a source and destination** in undirected weighted graph. The algorithm best suited for such problem is **"Dijkstra's ALgorithm".**

# Approach

1.) As per ideal Dikjshtra's approach, we will use a **"distance" vector** for finding lowest cost path.

    vector<vector<int>> dist(n, vector<int>(m, INT_MAX));

2.) We will insert 3 things in our priority queue, **distance from source, x co-ordinate, y co-ordinate.**

        priority_queue<pair<int, P>, vector<pair<int, P>>,greater<pair<int, P>>> q;

        q.push({grid[0][0], {0, 0}});

3.) We will find the minimum distance from source to destination by Dijkstra's algo. This algo will contain 3 steps:-

**a.)** If any point of time we reached the destination, we will return the distance.

            int steps = q.top().first;
            int x     = q.top().second.first;
            int y     = q.top().second.second;
            q.pop();

            if(x == n-1 && y == m-1){
                return steps;
            }

**b.)** Traverse in all 4 directions, **{up, down, right, left}**. To make things easy in traversal, I have made a separate directions vector.

    vector<vector<int>> directions = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
                                      //Up    //Down    //Right  //Left

**c.)** Check for out of bound condition and if **we can reach to current co-ordinates with minimum distance, then insert into priority_queue**.

For checking of **out of bound conditions**, i have made a separate **isValid** function. 

# Complexity
- Time complexity:
O((m * n)log(m * n))

- Space complexity:
O(m * n)



*/

# Code
```cpp []
class Solution {
public:

    typedef pair<int, int> P;

    //Checking out of boundary conditions
    bool isValid(int row, int col, int n, int m){
        
        if(row < 0 || row >= n || col < 0 || col >= m){
            return false;
        }

        return true;
    }

    int minimumObstacles(vector<vector<int>>& grid) {
        
        vector<vector<int>> directions = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

        int n = grid.size();
        int m = grid[0].size();

        //For calculating minimum distance
        vector<vector<int>> dist(n, vector<int>(m, INT_MAX));

        //Dijkstra's Algo
        priority_queue<pair<int, P>, vector<pair<int, P>>,greater<pair<int, P>>> q;

        q.push({grid[0][0], {0, 0}});

        dist[0][0] = grid[0][0];//First cell can also have obstacle

        while(!q.empty()){

            int steps = q.top().first;
            int x     = q.top().second.first;
            int y     = q.top().second.second;
            q.pop();

            if(x == n-1 && y == m-1){//We are at our destination
                return steps;
            }

            for(auto &dir: directions){

                int new_x = x + dir[0];
                int new_y = y + dir[1];

                if(isValid(new_x, new_y, n, m) && dist[new_x][new_y] > steps + grid[new_x][new_y]){
                    dist[new_x][new_y] = steps + grid[new_x][new_y];// new minium distance

                    q.push({dist[new_x][new_y], {new_x, new_y}});
                }

            }
        }

        return -1;
    }
};
```