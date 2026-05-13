#include <stdio.h>
#define MAX 100
#define INF 9999
#include <time.h>
int main() {
    int n, cost[MAX][MAX];
    int visited[MAX] = {0};
    int i, j, ne = 1;
    int min, a = 0, b = 0, u = 0, v = 0;
    int mincost = 0;
    double et;
    clock_t st,end;
    st=clock();
    printf("Enter number of vertices: ");
    scanf("%d", &n);
    printf("Enter the cost adjacency matrix:\n");
    for(i = 0; i < n; i++) {
        for(j = 0; j < n; j++) {
            scanf("%d", &cost[i][j]);
            if(cost[i][j] == 0)
                cost[i][j] = INF;
        }
    }
    visited[0] = 1;
    printf("\nEdges in MST:\n");
    while(ne < n) {
        min = INF;
        for(i = 0; i < n; i++) {
            if(visited[i]) {
                for(j = 0; j < n; j++) {
                    if(!visited[j] && cost[i][j] < min) {
                        min = cost[i][j];
                        a = u = i;
                        b = v = j;
                    }
                }
            }
        }
    printf("%d -> %d = %d\n", a, b, min);
    visited[b] = 1;
    mincost += min;
    ne++;
    }
    printf("\nMinimum Cost = %d\n", mincost);
    end=clock();
    et=(end-st)/CLOCKS_PER_SEC;
    printf("%f",et);
    return 0;
}
