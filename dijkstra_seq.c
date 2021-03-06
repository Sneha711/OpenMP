#include <stdio.h>
#include <limits.h>
#include<limits.h>
#include<sys/time.h>
#define INF 99999
int V;

int printSolution(int dist[], int n)
{
	int i;
	printf("Vertex   Distance from Source\n");
	for (i = 0; i < V; i++)
		printf("%d \t\t %d\n", i, dist[i]);
}

void dijkstra(int graph[V][V], int src)
{
	int u,i,v,count;
	int dist[V];     
	int sptSet[V]; 
	for (i = 0; i < V; i++)
		dist[i] = INF, sptSet[i] = 0;

	dist[src] = 0;
	int min;
	for (count = 0; count < V-1; count++)
	{
		for (v=0; v < V; v++)
		{	
			if(v==0)
			{
				min=INF;					
			}
				
			if (sptSet[v] == 0 && dist[v] <= min)
			{		
				min = dist[v];
				u = v;
			}
			
		}
		sptSet[u] = 1;

		for (v = 0; v < V; v++)
		{
			if (!sptSet[v] && graph[u][v] && dist[u] != INF && dist[u]+graph[u][v] < dist[v])
				dist[v] = dist[u] + graph[u][v];
		} 
	}
	printSolution(dist, V);
}

int main()
{

	struct timeval TimeValue_Start;
	struct timezone TimeZone_Start;
	struct timeval TimeValue_Final;
	struct timezone TimeZone_Final;
	long time_start,time_end;
	double time_overhead;
	int n;
	printf("Enter the number of vertices : ");
	scanf("%d",&n);
	V=n;
	int graph[n][n];
	int i,j;
	printf("Enter the adjacency matrix : \n");
	for(i=0;i<n;i++){
		for(j=0;j<n;j++){
			scanf("%d",&graph[i][j]);
		}
	}
	gettimeofday(&TimeValue_Start,&TimeZone_Start);
	dijkstra(graph, 0);
	gettimeofday(&TimeValue_Final,&TimeZone_Final);
	time_start=TimeValue_Start.tv_sec*1000000+TimeValue_Start.tv_usec;
	time_end=TimeValue_Final.tv_sec*1000000+TimeValue_Final.tv_usec;
	time_overhead=(time_end-time_start)/1000000.0;
	printf("\nTime in Seconds(t)  :%lf\n",time_overhead);
  
    return 0;
}
