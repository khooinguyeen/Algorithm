#include "GraphStruct.h"

void initialize_graph(graph *g, bool directed)
{
    int i;

    g->nvertices = 0;       // đỉnh
    g->nedges = 0;          // cạnh
    g->directed = directed;

    for (i = 1; i <= MAXV; i++)
        g->degree[i] = 0;
    
    for (i = 1; i <= MAXV; i++)
        g->edges[i] = NULL;
}

void insert_edge(graph *g, int x, int y, bool directed)
{
    edgeNode *p = new edgeNode;

    p->weight = 0;
    p->y = y;
    p->next = g->edges[x];
    g->edges[x] = p;            // insert at head of list
    g->degree[x]++;

    if (!directed)
        insert_edge(g, y, x, true);
    else
        g->nedges++;
}

void read_graph(graph *g, bool directed)
{
    int i;
    int m;                  // number of edges
    int x, y;               // vertices in edge

    initialize_graph(g, directed);
    cin >> g->nvertices >> m;
    for (i = 1; i <= m; i++)
    {
        cin >> x >> y;
        insert_edge(g, x, y, directed);
    }
}

void print_graph(graph *g)
{
    int i;
    edgeNode *p;

    for (i = 1; i <= g->nvertices; i++)
    {
        cout << i << " ";
        p = g->edges[i];
        while (p != NULL)
        {
            cout << " " << p->y;
            p = p->next;
        }
        cout << endl;
    }
}