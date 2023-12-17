#ifndef GRAPHSTRUCT_H
# define GRAPHSTRUCT_H

#define MAXV 101

#include <iostream>
#include <queue>

using namespace std;

// for graph
struct edgeNode
{
    int y;                  // Adjacency info
    int weight;             // edge weight
    edgeNode *next;         //next edge in list
};

struct graph
{
    edgeNode *edges[MAXV];  // adjacency info
    int degree[MAXV];       // outdegree of each vertices
    int nvertices;          // number of vertices
    int nedges;             // number of edges
    int directed;           // is the graph directed
};

// for graph
void initialize_graph(graph *g, bool directed);
void insert_edge(graph *g, int x, int y, bool directed);
void read_graph(graph *g, bool directed);
void print_graph(graph *g);

// for BFS
void initialize_search(graph *g);
void bfs(graph *g, int start);
void process_vertex_late(int v);
void process_vertex_early(int v);
void process_edge(int x, int y);


#endif