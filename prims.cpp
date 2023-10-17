#include <iostream>
#include <vector>
#include <queue>
#include <climits>

using namespace std;

// Structure to represent an edge in the graph
struct Edge {
    int destination;
    int weight;
};

class Graph {
public:
    int V; // Number of vertices
    vector<vector<Edge>> adjList; // Adjacency list to store the graph

    Graph(int V) {
        this->V = V;
        adjList.resize(V);
    }

    // Function to add an edge to the graph
    void addEdge(int src, int dest, int weight) {
        Edge edge;
        edge.destination = dest;
        edge.weight = weight;
        adjList[src].push_back(edge);
        // For undirected graph, add an edge from dest to src as well
        edge.destination = src;
        adjList[dest].push_back(edge);
    }

    // Function to find the Minimum Spanning Tree using Prim's algorithm
    void primMST() {
        // Priority queue to store edges along with their weights
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        vector<int> key(V, INT_MAX); // Key values to pick minimum weight edge
        vector<int> parent(V, -1); // To store the MST

        // Start with the first node
        int src = 0;
        pq.push(make_pair(0, src));
        key[src] = 0;

        while (!pq.empty()) {
            int u = pq.top().second;
            pq.pop();

            // Visit all adjacent vertices of u
            for (const Edge& edge : adjList[u]) {
                int v = edge.destination;
                int weight = edge.weight;

                // If v is not yet included in MST and the weight of u-v is less than key value of v
                if (key[v] > weight) {
                    key[v] = weight;
                    pq.push(make_pair(key[v], v));
                    parent[v] = u;
                }
            }
        }

        // Print the MST
        for (int i = 1; i < V; ++i) {
            cout << "Edge: " << parent[i] << " - " << i << " Weight: " << key[i] << endl;
        }
    }
};

int main() {
    Graph g(5); // Create a graph with 5 vertices
    g.addEdge(0, 1, 2);
    g.addEdge(0, 3, 1);
    g.addEdge(1, 2, 3);
    g.addEdge(1, 3, 3);
    g.addEdge(2, 4, 4);
    g.addEdge(3, 4, 5);

    cout << "Minimum Spanning Tree using Prim's algorithm:\n";
    g.primMST();

    return 0;
}
