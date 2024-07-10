#include<stdio.h>
#include<conio.h>
int adj[10][10];
void main(){
	int n, i, j;
	printf("Enter the number of vertices\n");
	scanf("%d", &n);
	printf("Enter the adjacency matrix\n");
	for(i=1; i<=n; i++){
		for(j=1; j<=n; j++){
			scanf("%d",&adj[i][j]);
		}
	}
	warshall(adj, n);
	printf("\nTransitive Closure is:\n");
	for(i=1;i<=n;i++){
		for(j=1;j<=n;j++){
			printf("%d ",adj[i][j]);
		}
		printf("\n");
	}
}

void warshall(int cost[10][10], int n){
	int i, j, k;
	for(k=1;k<=n;k++){
		for(i=1; i<=n; i++){
			for(j=1; j<=n; j++){
				adj[i][j]=(adj[i][j]) || (adj[i][k]&&adj[k][j]);
			}
		}
	}
}