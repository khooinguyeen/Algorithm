#include "GraphStruct.h"
#include <stack>
void dfs(graph* g, int start) {
    stack<int> s;
    int v, y;
    edgeNode* p;

    vector<bool> discovered(MAXV, false);

    s.push(start);
    discovered[start] = true;

    while (!s.empty()) {
        v = s.top();
        s.pop();

        cout << v << " ";

        p = g->edges[v];
        while (p != NULL) {
            y = p->y;

            if (!discovered[y]) {
                s.push(y);
                discovered[y] = true;
            }

            p = p->next;
        }
    }
}
