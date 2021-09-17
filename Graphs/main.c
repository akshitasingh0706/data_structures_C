#include <stdio.h>
#include "Queue.h"

void BFS(int G[][7],int start,int len_graph)
{
    /* 1) Initialize a variable vis_node to the
          starting/root node
       2) Initialize an array of 7 elements
          (number of nodes in the graph) */
    int vis_node = start;
    int visited[7] = {0};

    /* 1) Print the value we select as the starting/root node
       2) For any node you visit (say the 4th node) you mark
          the corresponding index in the array (4th element)
          as visited
       3) Finally, enqueue that value */
    printf("%d ", vis_node);
    visited[vis_node] = 1;
    enqueue(vis_node);
    
    /* 1) While the Queue is not empty */
    while(!isEmpty())
    {
        /* 1)  Dequeue the visited element, which means
               Remove it from the queue AND return the value
               Thus changing i to newly dequeued node value
           2a) We identify all nodes that are adjacent to node
           2b) AND, that have not yet been visited
               3a) If so, we print the node
               3b) And, mark it as visted
               3c) And, enqueue it */
        vis_node = dequeue();
        for(int adj_node = 1; adj_node < len_graph; adj_node++)
        {
            if(G[vis_node][adj_node] == 1 && visited[adj_node] == 0)
            {
                printf("%d ", adj_node);
                visited[adj_node]=1;
                enqueue(adj_node);
            }
        }
    }
}

void DFS(int G[][7], int start, int len_node)
{
    /* Initialize an array of 7 elements
       (number of nodes in the graph) */
    static int visited[7] = {0};
    
    /* 1) Goal: visit a node, BUT
          Don't bother spanning all of its edges
       2) Just pick any one edge, and
          Check if it has any more adjacent edges
             3a) If it has more adjacent edges,
                 Repeat steps 1) and 2)
             3b) Start backtracking, and
                 Go to the nearest adjecent above, and
                 Repeat steps 1, 2, and 3a     */
    if(visited[start] == 0)
    {
        printf("%d ", start);
        visited[start] = 1;
        for(int adj_node = 1; adj_node < len_node; adj_node++)
        {
            if(G[start][adj_node] == 1 && visited[adj_node] == 0)
                DFS(G, adj_node, len_node);
        }
    }
}



int main() {
    int G[7][7] = {{0,0,0,0,0,0,0},
                  {0,0,1,1,0,0,0},
                  {0,1,0,0,1,0,0},
                  {0,1,0,0,1,0,0},
                  {0,0,1,1,0,1,1},
                  {0,0,0,0,1,0,0},
                  {0,0,0,0,1,0,0}};
    DFS(G, 4, 7);
    return 0;
}
