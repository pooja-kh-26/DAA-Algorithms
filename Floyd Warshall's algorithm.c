#include<stdio.h>
#include<conio.h>
#define INF 9999

void main(){
	int i, j, k, n, graph[10][10];
	printf("Enter the number of vertices\n");
	scanf("%d", &n);
	printf("Enter the adjacency matrix of the graph\n");
	for(i=0; i<n; i++){
		for(j=0; j<n; j++){
			scanf("%d", &graph[i][j]);
			if(graph[i][j]==INF && i!=j){
				graph[i][j]=INF;
			}
		}
	}
	floydWarshall(graph, n);
}

void floydWarshall(int graph[10][10], int n){
	int i, j, k, dist[10][10];
	for(i=1;i<=n;i++){
		for(j=1;j<n;j++){
			dist[i][j]=graph[i][j];
		}
	}
	for(k=1; k<=n; k++){
		for(i=1; i<=n; i++){
			for(j=1; j<=n; j++){
				if(dist[i][k]!=INF && dist[k][j]!=INF && (dist[i][k]+dist[k][j])<dist[i][j])
					dist[i][j]=dist[i][k]+dist[k][j];	
			}
		}
	}
	printf("\nShortest path is:\n");
	for(i=1;i<=n;i++){
		for(j=1;j<=n;j++){
			if(dist[i][j]==INF)
				printf("INF ");
			else
				printf("%d ", dist[i][j]);
		}
		printf("\n");
	}
	
}


