#include <iostream>
#include <unordered_map>
#include <list>
#include <queue>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

// Graph class to represent the metro network
class MetroGraph {
private:
    // Adjacency list to store the metro stations and their connections
    unordered_map<string, list<string>> adjList;

public:
    // Method to add an edge between two stations
    void addEdge(const string& station1, const string& station2) {
        adjList[station1].push_back(station2);
        adjList[station2].push_back(station1);  // Because the metro is bidirectional
    }

    // Method to find the shortest path between source and destination
    vector<string> findRoute(const string& src, const string& dest) {
        unordered_map<string, bool> visited;
        unordered_map<string, string> parent;  // To store the path
        queue<string> q;

        // Start from the source station
        q.push(src);
        visited[src] = true;
        parent[src] = "";

        // BFS traversal
        while (!q.empty()) {
            string current = q.front();
            q.pop();

            // If destination is found, reconstruct the path
            if (current == dest) {
                vector<string> path;
                while (current != "") {
                    path.push_back(current);
                    current = parent[current];
                }
                reverse(path.begin(), path.end());  // Reverse the path to start from src
                return path;
            }

            // Visit all the adjacent stations
            for (const string& neighbor : adjList[current]) {
                if (!visited[neighbor]) {
                    q.push(neighbor);
                    visited[neighbor] = true;
                    parent[neighbor] = current;
                }
            }
        }

        // If no path found, return an empty vector
        return {};
    }
};

int main() {
    MetroGraph metro;

    // Initializing a small part of Delhi Metro network
    metro.addEdge("Rajiv Chowk", "Kashmere Gate");
    metro.addEdge("Rajiv Chowk", "Central Secretariat");
    metro.addEdge("Kashmere Gate", "Chandni Chowk");
    metro.addEdge("Chandni Chowk", "New Delhi");
    metro.addEdge("New Delhi", "Rajiv Chowk");
    metro.addEdge("Central Secretariat", "Hauz Khas");
    metro.addEdge("Hauz Khas", "AIIMS");
    metro.addEdge("AIIMS", "INA");

    string source, destination;
    cout << "Enter source station: ";
    getline(cin, source);
    cout << "Enter destination station: ";
    getline(cin, destination);

    // Find the route
    vector<string> route = metro.findRoute(source, destination);

    // Print the route
    if (!route.empty()) {
        cout << "Shortest route from " << source << " to " << destination << " is:" << endl;
        for (const string& station : route) {
            cout << station << " ";
        }
        cout << endl;
    } else {
        cout << "No route found from " << source << " to " << destination << "." << endl;
    }

    return 0;
}
