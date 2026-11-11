class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        unordered_map<int, vector<int>> adjList; // adjacency list: vertex, edge (connected vertices (prereqs))
        for (const auto& pre : prerequisites) {
            // build adjacency list with class pairs from class as node and prereqs as connected edges
            adjList[pre[0]].push_back(pre[1]);
        }

        unordered_set<int> visit; // keep track of a visited set for processed vertices
        unordered_set<int> cycle; // keep track of a cycle set for detecting cycles in our graph
        vector<int> output; // list for creating our valid order of classes to take

        // loop through all courses running dfs on each course
        for (int c = 0; c < numCourses; c++) {
            if (!dfs(c, adjList, visit, cycle, output)) {
                // if dfs returns false then we detected a cycle, return empty list
                return {};
            }
        }
        // if we made it through dfs on all the vertices and edges without a cycle, 
        // return our valid course order list
        return output;
    }

private:
    // dfs that operates on a course, pass in all our reference variables
    bool dfs(int course, unordered_map<int, vector<int>>& adjList,
            unordered_set<int>& visit, unordered_set<int>& cycle, vector<int>& output) 
    {
        // if the course we're checking is already in our cycle set, that mean we have detected a cycle in our graph,
        // so return false so we can return an empty list
        if (cycle.count(course)) return false; 
        // if the course we're checking is already in our visit set, the course has already been checked with dfs, 
        // so return true so we can continue 
        if (visit.count(course)) return true;

        // insert the course into our cycle set, so we can detect if it's seen again before 
        // we're done processing our path of vertices
        cycle.insert(course);
        for (int pre : adjList[course]) {
            if (!dfs(pre, adjList, visit, cycle, output)) {
                return false;
            }
        }
        cycle.erase(course);
        visit.insert(course);
        output.push_back(course);
        return true;
    }
};
