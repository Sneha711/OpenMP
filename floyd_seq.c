#include<stdio.h>
#include<limits.h>
#include<sys/time.h>
#define INF 9999

int V;

void printSolution(int dist[][V]);

void floyd(int graph[][V])
{
	int dist[V][V], i, j, k;
	for (i = 0; i < V; i++)
		for (j = 0; j < V; j++)
			dist[i][j] = graph[i][j];
	for (k = 0; k < V; k++)
	{
		for (i = 0; i < V; i++)
		{
			for (j = 0; j < V; j++)
			{
				if (dist[i][k] + dist[k][j] < dist[i][j])
					dist[i][j] = dist[i][k] + dist[k][j];
			}
		}
	}
 
	printSolution(dist);
}

void printSolution(int dist[][V])
{
	printf ("Following matrix shows the shortest distances between every pair of vertices \n");
	for (int i = 0; i < V; i++)
	{
		for (int j = 0; j < V; j++)
		{
			if (dist[i][j] == INF)
				printf("%s    ", "INF");
			else
				printf ("%d      ", dist[i][j]);
		}
		printf("\n");
	}
}

int main()
{
	int i,j;
	struct timeval TimeValue_Start;
	struct timezone TimeZone_Start;
	struct timeval TimeValue_Final;
	struct timezone TimeZone_Final;
	long time_start,time_end;
	double time_overhead;	
	printf("Enter the number of vertices : ");
	scanf("%d",&V);
	printf("Enter the adjacency matrix : \n");
	int graph[V][V];
	for(i=0;i<V;i++){
		for(j=0;j<V;j++){
			scanf("%d",&graph[i][j]);
		
		}

	}
	gettimeofday(&TimeValue_Start,&TimeZone_Start);
	floyd(graph);	
	gettimeofday(&TimeValue_Final,&TimeZone_Final);
	time_start=TimeValue_Start.tv_sec*1000000+TimeValue_Start.tv_usec;
	time_end=TimeValue_Final.tv_sec*1000000+TimeValue_Final.tv_usec;
	time_overhead=(time_end-time_start)/1000000.0;
	printf("\nTime in Seconds(t)  :%lf\n",time_overhead);		
	return 0;
}
