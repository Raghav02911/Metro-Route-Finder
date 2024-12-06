
# Metro-Route-Finder

This is a simple C++ program to find the shortest metro route between a source and destination. A metro netwok is initialized as a graph data structure and the Breadth First Search(BFS) algorithm is used to find the shotest distance. In this program a short segment of the Delhi Metro Netwok has been initialized as the graph.




## Features
- **Graph Representation**: The Delhi Metro stations are represented as nodes, and the connections between them are edges in an adjacency list.
- **Shortest Path Calculation**: Uses BFS to find the shortest route between the source and destination stations.
- **Customizable Network**: The metro network is easily expandable by adding more stations and connections.
## Program Structure

**MetroGraph Class**
- addEdge(string station1, string station2): Adds a bidirectional connection between two metro stations.
- findRoute(string src, string dest): Implements BFS to find the shortest path between the source and destination stations

**Main Function**
- Initializes the graph with Delhi Metro connections.
- Accepts user input for source and destination.
- Outputs the shortest path.

## Example Input/Output
Enter source station: Kashmere Gate  
Enter destination station: AIIMS  
Shortest route from Kashmere Gate to AIIMS is:
Kashmere Gate -> Rajiv Chowk -> Central Secretariat -> Hauz Khas -> AIIMS


## Expanding the Metro Network  
**You can add more stations and connections by modifying the main function:**    
metro.addEdge("Station A", "Station B");  
metro.addEdge("Station B", "Station C");  
