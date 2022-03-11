#include <vector>

#define WHITE 0
#define GRAY 1
#define BLACK 2

using namespace std;

class Vertex {
public:
    int id;
    int color;
    vector<int> neighbors;
    
    Vertex(int id) {
        this -> id = id;
    }
};

class Graph {
public:
    vector<Vertex> vertices;
    
    Graph(int nVertices) {
        for (int i = 0; i < nVertices; i ++) {
            this -> vertices.push_back(Vertex(i));
            this -> vertices[i].color = WHITE;
        }
    }
    
    void add_edge(vector<int> edge) {
        this -> vertices[edge[0]].neighbors.push_back(edge[1]);
    }
};

class Solution {
    /*
        Title: 310. Minimum Height Trees
        Time Complexity: O(|V| + |E|)
        Algorithm: 
            1. Two times DFS
        
        Note:
            1. "Find the root constructing the minimum height tree"
               => "Find the middle point of the longest edge"
            
            2. Pick any vertex u, find the farthest vertex v from u.
               Then v must be one of the two endpoints of the longest edge.
               
            3. Using DFS two times to find the longest edge.

        Date: 12/24/2021 08:27							
        Time: 168 ms  -- beat 10.65%
        Memory: 64.6 MB  -- beat 5.00%
    */
public:
    void find_farest_endpoint(Graph& graph, int vertex_id, 
                              int cur_len, int& max_len, int& max_endpoint) {
        vector<int>& neighbors = graph.vertices[vertex_id].neighbors;
        graph.vertices[vertex_id].color = GRAY;
        
        int leaf = 1;
        for (int i = 0; i < neighbors.size(); i ++) {
            if (graph.vertices[neighbors[i]].color == WHITE) {
                leaf = 0;
                find_farest_endpoint(graph, neighbors[i], cur_len + 1, max_len, max_endpoint);
            }
        }
        
        if (leaf) {
            if (cur_len > max_len) {
                max_len = cur_len;
                max_endpoint = vertex_id;
            }
        }
        graph.vertices[vertex_id].color = WHITE;
    }
    
    void find_farest_path(Graph& graph, int vertex_id, int cur_len, int& max_len, 
                        vector<int>& path, vector<int>& max_path) {
        vector<int>& neighbors = graph.vertices[vertex_id].neighbors;
        graph.vertices[vertex_id].color = GRAY;
        
        int leaf = 1;
        for (int i = 0; i < neighbors.size(); i ++) {
            if (graph.vertices[neighbors[i]].color == WHITE) {
                leaf = 0;
                path.push_back(neighbors[i]);
                find_farest_path(graph, neighbors[i], cur_len + 1, max_len, path, max_path);
                path.pop_back();
            }
        }
        
        if (leaf) {
            if (cur_len > max_len) {
                max_len = cur_len;
                max_path = path;
            }
        }
        graph.vertices[vertex_id].color = BLACK;
    }
    
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        Graph graph(n);
        for (auto edge : edges) {
            graph.add_edge(edge);
            vector<int> rev_edge = {edge[1], edge[0]};
            graph.add_edge(rev_edge);
        }
        
        int left;
        int max_len = 0;
        find_farest_endpoint(graph, 0, 1, max_len, left);
        
        vector<int> path = {left};
        vector<int> max_path = {left};
        max_len = 0;
        find_farest_path(graph, left, 1, max_len, path, max_path);
        
        vector<int> mid;
        int mid_pos = max_path.size() / 2;
        
        if (max_path.size() % 2 == 0) {
            mid.push_back(max_path[mid_pos - 1]);
            mid.push_back(max_path[mid_pos]);
        } else {
            mid.push_back(max_path[mid_pos]);
        }
        return mid;
    }
};