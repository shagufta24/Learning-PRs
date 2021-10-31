#include <stdio.h>

#define INFINITY 9999
#define V 6 //Number of vertices

void sssp(int G[V][V], int startnode);

int main()
{
    int i, j, src = -1;

    //Adjacency matrix of graph
    int G[V][V] = {{0, 50, 45, 10, 0, 0},
                   {50, 0, 10, 15, 20, 0},
                   {45, 10, 0, 0, 30, 0},
                   {10, 15, 0, 0, 15, 0},
                   {0, 20, 30, 15, 0, 3},
                   {0, 0, 0, 0, 3, 0}};

    printf("Vertex set: ");
    for (i = 0; i < V; i++)
        printf("%d ", i);

    //Checking if source belongs to vertex set
    while (src < 0 || src > V - 1)
    {
        printf("\nEnter source node: ");
        scanf("%d", &src);
    }

    //Running function to solve SSSP Problem
    sssp(G, src);

    return 0;
}

void sssp(int G[V][V], int startnode)
{
    int cost[V][V];  // stores distances of all nodes from each other
    int distance[V]; // stores distances of nodes from source node
    int pred[V];     // stores the predecessor of each node
    int visited[V];  // remembers if a node was visited or not
    int count;       // number of nodes seen so far
    int mindistance, nextnode, i, j;

    //create the cost matrix
    for (i = 0; i < V; i++)
        for (j = 0; j < V; j++)
            if (G[i][j] == 0)
                cost[i][j] = INFINITY;
            else
                cost[i][j] = G[i][j];

    //initialize pred[], distance[] and visited[]
    for (i = 0; i < V; i++)
    {
        distance[i] = cost[startnode][i];
        pred[i] = startnode;
        visited[i] = 0;
    }

    //start node is visited by default
    distance[startnode] = 0;
    visited[startnode] = 1;
    count = 1;

    while (count < V - 1)
    {
        mindistance = INFINITY;

        //node that has minimum distance is visited next (nextnode)
        for (i = 0; i < V; i++)
            if (distance[i] < mindistance && !visited[i])
            {
                mindistance = distance[i]; //distance of nextnode
                nextnode = i;
            }

        //visiting next node
        visited[nextnode] = 1;

        //check if a better path exists to each unvisited node via nextnode
        for (i = 0; i < V; i++)
            if (!visited[i])
                if (mindistance + cost[nextnode][i] < distance[i])
                // dist from source to next + dist from next to i < dist from source to i
                {
                    distance[i] = mindistance + cost[nextnode][i];
                    pred[i] = nextnode;
                }
        count++;
    }

    //print the path and distance of each node
    for (i = 0; i < V; i++)
        if (i != startnode)
        {
            printf("\nNode %d:", i);
            printf("\nDistance = %d", distance[i]);
            printf("\nPath = %d", i);

            j = i;
            do
            {
                j = pred[j];
                printf(" <- %d", j);
            } while (j != startnode);
            printf("\n");
        }
        else
        {
            printf("\nNode %d (source node):", i);
            printf("\nDistance = 0\n");
        }
    printf("\n");
}
