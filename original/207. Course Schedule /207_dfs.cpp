#include <vector>
#include <stack>

#define WHITE 0
#define GRAY 1
#define BLACK 2

using namespace std;

/*
    Title: 207. Course Schedule
    Time Complexity: O(|V| + |E|)
    Algorithm: 
        1. Topological Sort
        2. DFS
    
    Date: 12/23/2021 22:53					
    Time: 20 ms  -- beat 75.78%
    Memory: 16.3 MB  -- beat 9.54%
*/

class Vertex {
public:
    int id;
    int discover;
    int finish;
    int color; 
    vector<int> neighbors;
    
    Vertex(int id) {
        this -> id = id;
        this -> color = WHITE;
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
    void dfs(Graph& graph, int vertex_id, stack<int>& st, int& valid, int& clock) {
        graph.vertices[vertex_id].color = GRAY;
        graph.vertices[vertex_id].discover = clock++;
        vector<int>& neighbors = graph.vertices[vertex_id].neighbors;
        
        for (int i = 0; i < neighbors.size(); i ++) {
            if (graph.vertices[neighbors[i]].color == GRAY) {
                valid = 0;
            }
            if (graph.vertices[neighbors[i]].color == WHITE) {
                dfs(graph, neighbors[i], st, valid, clock);
            } 
        }
        
        graph.vertices[vertex_id].color = BLACK;
        graph.vertices[vertex_id].finish = clock++;
        st.push(vertex_id);
    }
    
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        Graph graph(numCourses);
        for (int i = 0; i < prerequisites.size(); i ++) {
            vector<int> edge = {prerequisites[i][1], prerequisites[i][0]};
            graph.add_edge(edge);
        }
        
        stack<int> st;
        int valid = 1, clock = 0;
        for (int i = 0; i < graph.vertices.size(); i ++) {
            if (graph.vertices[i].color == WHITE) {
                dfs(graph, i, st, valid, clock);
            }
        }
        
        return (valid == 1);
    }
};




