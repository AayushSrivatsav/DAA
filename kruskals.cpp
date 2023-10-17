#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Structure to represent an edge in the graph
struct Edge {
    int src, dest, weight;
};

// Structure to represent a subset for union-find
struct Subset {
    int parent, rank;
};

class Graph {
public:
    int V; // Number of vertices
    vector<Edge> edges; // Edges of the graph

    Graph(int V) {
        this->V = V;
    }

    // Function to add an edge to the graph
    void addEdge(int src, int dest, int weight) {
        Edge edge;
        edge.src = src;
        edge.dest = dest;
        edge.weight = weight;
        edges.push_back(edge);
    }

    // Function to find the parent of a subset
    int find(vector<Subset>& subsets, int i) {
        if (subsets[i].parent != i)
            subsets[i].parent = find(subsets, subsets[i].parent);
        return subsets[i].parent;
    }

    // Function to perform union of two subsets
    void unionSets(vector<Subset>& subsets, int x, int y) {
        int xroot = find(subsets, x);
        int yroot = find(subsets, y);

        if (subsets[xroot].rank < subsets[yroot].rank)
            subsets[xroot].parent = yroot;
        else if (subsets[xroot].rank > subsets[yroot].rank)
            subsets[yroot].parent = xroot;
        else {
            subsets[yroot].parent = xroot;
            subsets[xroot].rank++;
        }
    }

    // Function to find the Minimum Spanning Tree using Kruskal's algorithm
    void kruskalMST() {
        // Sort edges by weight
        sort(edges.begin(), edges.end(), [](Edge a, Edge b) {
            return a.weight < b.weight;
        });

        vector<Subset> subsets(V);
        for (int i = 0; i < V; ++i) {
            subsets[i].parent = i;
            subsets[i].rank = 0;
        }

        vector<Edge> result; // Stores the MST edges

        for (Edge edge : edges) {
            int x = find(subsets, edge.src);
            int y = find(subsets, edge.dest);

            // If including this edge doesn't cause a cycle, add it to the result
            if (x != y) {
                result.push_back(edge);
                unionSets(subsets, x, y);
            }
        }

        // Print the MST
        cout << "Minimum Spanning Tree using Kruskal's algorithm:\n";
        for (Edge edge : result) {
            cout << "Edge: " << edge.src << " - " << edge.dest << " Weight: " << edge.weight << endl;
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

    cout << "Minimum Spanning Tree using Kruskal's algorithm:\n";
    g.kruskalMST();

    return 0;
}

