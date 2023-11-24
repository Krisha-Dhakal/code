#include <stdio.h>
#include <limits.h>
#define MAX_NODES 100
#define INF INT_MAX

int n, i, j , k;
int dist[MAX_NODES][MAX_NODES];
int graph[MAX_NODES][MAX_NODES];

void floydWarshall(){

    for (i = 0; i < n; i++){
        for (j = 0; j < n; j++){
            if (i == j){
                dist[i][j] = 0;
            }
            else if (graph[i][j]){
                dist[i][j] = graph[i][j];
            }
            else{
                dist[i][j] = INF;
            }
        }
    }


    for (k = 0; k < n; k++){
        for ( i = 0; i < n; i++){
            for ( j = 0; j < n; j++){
                if (dist[i][k] != INF && dist[k][j] != INF && dist[i][k] + dist[k][j] < dist[i][j])
                {
                    dist[i][j] = dist[i][k] + dist[k][j];
                }
            }
        }
    }
}

int main(){
    printf("Enter number of nodes: ");
    scanf("%d", &n);
    printf("Enter the adjacency matrix:\n");
    for (i = 0; i < n; i++){
        for (j = 0; j < n; j++){
            scanf("%d", &graph[i][j]);
        }
    }

    floydWarshall();

    printf("Shortest distances between all pairs of nodes:\n");
    for (i = 0; i < n; i++){
        for (j = 0; j < n; j++)
        {
            if (dist[i][j] == INF)
            {
                printf("INF ");
            }
            else
            {
                printf("%d ", dist[i][j]);
            }
        }
        printf("\n");
    }
	printf("\nName: Krisha Dhakal\tRoll no:8");
    return 0;
}

