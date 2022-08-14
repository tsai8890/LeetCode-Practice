#include <vector>
#include <queue>

using namespace std;

/*
    Title: 210. Course Schedule II
    Time Complexity: O(|V| + |E|)
    Algorithm: 
        1. Topological Sort
        2. BFS
    
    Date: 01/16/2022 18:33					
    Time: 16 ms  -- beat 95.07%
    Memory: 15.7 MB  -- beat 13.46%
*/

class Vertex {
public:
    int id;
    int discover;
    int finish;
    vector<int> neighbors;
    
    Vertex(int id) {
        this -> id = id;
        this -> neighbors.clear();
    }
};

class Graph {
public:
    vector<Vertex> vertices;

    Graph(int nVertices) {
        for (int i = 0; i < nVertices; i ++) {
            this -> vertices.push_back(Vertex(i));
        }
    }
    
    void add_edge(vector<int> edge) {
        this -> vertices[edge[0]].neighbors.push_back(edge[1]);
    }
};

class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        Graph graph(numCourses);
        vector<int> in_degree(numCourses, 0);
        
        for (int i = 0; i < prerequisites.size(); i ++) {
            vector<int> edge = {prerequisites[i][1], prerequisites[i][0]};
            graph.add_edge(edge);
            in_degree[edge[1]] += 1;
        }
        
        vector<int> visited(numCourses, 0);
        int visited_nodes = 0;
        
        queue<int> q;
        for (int i = 0; i < numCourses; i ++) {
            if (in_degree[i] == 0) {
                q.push(i);
                visited[i] = 1;
                visited_nodes += 1;
            }
        }
        
        while (!q.empty()) {
            int top = q.front();
            q.pop();
            
            for (auto i : graph.vertices[top].neighbors) {
                if (!visited[i]) {
                    in_degree[i] -= 1;
                    if (in_degree[i] == 0) {
                        q.push(i);
                        visited[i] = 1;
                        visited_nodes += 1;
                    }
                }
            }
        }
        return (visited_nodes == numCourses);
    }
};




