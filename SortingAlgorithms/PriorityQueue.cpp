#define PQ_SIZE 10000
#include <iostream>

typedef struct
{
    int q[PQ_SIZE + 1]; // body of queue
    int n;              // number of elements
} priority_queue;

int pq_parent (int n)
{
    if (n == 1)
        return (-1);
    return ((int) n/2); // implicitly take floor (n/2)
}

int pq_young_child (int n)
{
    return (2 * n);
}

void pq_insert(priority_queue *q, int x)
{
    if (q->n >= PQ_SIZE)
    {
        std::cout << "Warning: priority queue overflow";
    }
    else
    {
        q->n = (q->n) + 1;
        q->q[q->n] = x;
        bubble_up(q, q->n);
    }
}

void bubble_up(priority_queue *q, int p)
{
    if (pq_parent(p) == -1)
    {
        return ;
    }

    if (q->q[pq_parent(p)] > q->q[p])
    {
        pq_swap(q, p, pq_parent(p));
        bubble_up(q, pq_parent(p));
    }
}

void pq_init(priority_queue *q)
{
    q->n = 0;
}

void make_heap(priority_queue *q, int s[], int n)
{
    int i;

    pq_init(q);
    for (int i = 0; i < n; i++)
        pq_insert(q, s[i]);
}

int extract_min(priority_queue *q)
{
    int min = -1;

    if (q->n <= 0) 
    {
        printf("Warning: empty priority queue");
    }
    else
    {
        min = q->q[1];

        q->q[1] = q->q[q->n];
        q->n = q->n - 1;
        bubble_down(q, 1);
    }
    return (min);
}

void bubble_down(priority_queue *q, int p)
{
    int c;
    int i;
    int min_index;

    c = pq_young_child(p);
    min_index = p;

    for (i = 0; i <= 1; i++)
    {
        if ((c + i) <= q->n)
        {
            if (q->q[min_index] > q->q[c + i])
                min_index = c + i;
        }
    }
    if (min_index != p)
    {
        pq_swap(q, p, min_index);
        bubble_down(q, min_index);
    }
}