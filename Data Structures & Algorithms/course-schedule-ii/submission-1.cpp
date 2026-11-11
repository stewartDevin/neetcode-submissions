class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        unordered_map<int, vector<int>> adjList;
        for (const auto& pre : prerequisites) {
            adjList[pre[0]].push_back(pre[1]);
        }

        unordered_set<int> cycle, visit;
        vector<int> output;

        for (int c = 0; c < numCourses; c++) {
            if (!dfs(c, adjList, cycle, visit, output)) {
                return {};
            }
        }
        return output;
    }

private:
    bool dfs(int course, unordered_map<int, vector<int>>& adjList,
            unordered_set<int>& cycle, unordered_set<int>& visit, vector<int>& output) 
    {
        if (cycle.count(course)) return false;
        if (visit.count(course)) return true;

        cycle.insert(course);
        for (int prereq : adjList[course]) {
            if (!dfs(prereq, adjList, cycle, visit, output)) {
                return false;
            }
        } 
        cycle.erase(course);
        visit.insert(course);
        output.push_back(course);
        return true;
    }
};
