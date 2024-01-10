#include "GraphStruct.h"

int main()
{
    graph g;
    bool directed;  

    cout << "Enter 1 for directed graph, 0 for undirected graph: ";
    cin >> directed;
    read_graph(&g, directed);

    cout << "\nGraph:\n";
    print_graph(&g);

    int start_vertex;
    cout << "\nEnter the starting vertex for BFS: ";
    cin >> start_vertex;

    cout << "\nBFS Traversal:\n";
    bfs(&g, start_vertex);

    cout << "\nDFS Traversal:\n";
    dfs(&g, start_vertex);

    return (0);
}