#include "GraphStruct.h"

bool processed[MAXV];
bool discovered[MAXV];
int parent[MAXV];

void process_vertex_late(int v) {
    cout << "processed vertex late " << v << endl; 
}
void process_vertex_early(int v)
{
    cout << "processed vertex " << v << endl;
}
void process_edge(int x, int y)
{
    cout << "processed edge (" << x << ", " << y << ")" << endl;
}

void initialize_search(graph *g)
{
    for (int i = 0; i <= g->nedges; i++)
    {
        processed[i] = false;
        discovered[i] = false;
        parent[i] = -1;
    }
}

void bfs(graph *g, int start)
{
    queue<int> q;
    int v;                  // current vertex
    int y;                  // successor vertex
    edgeNode *p;            // temp

    q.push(start);
    discovered[start] = true;
    while (!q.empty())
    {
        v = q.front();
        q.pop();
        process_vertex_early(v);
        processed[v] = true;
        p = g->edges[v];
        while (p != nullptr)
        {
            y = p->y;
            if ((!processed[y]) || g->directed)
                process_edge(v, y);
            if (!discovered[y])
            {
                q.push(y);
                discovered[y] = true;
                parent[y] = v;
            }
            p = p->next;
        }
        process_vertex_late(v);
    }

}

