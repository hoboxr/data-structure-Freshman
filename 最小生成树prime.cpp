#include<stdio.h>
#include<stdlib.h>
#define MAXEDGE 20
#define MAXVEX 20
#define GRAPH_INFINITY 100000

typedef struct
{
	int vexs[MAXVEX];
	int arc[MAXVEX][MAXVEX];
	int numNodes, numEdges;
}MGraph;

void CreateMGraph(MGraph *G)
{
	int i, j;

	G->numEdges=15;
	G->numNodes=9;

	for (i = 0; i < G->numNodes; i++)
	{
		for ( j = 0; j < G->numNodes; j++)
		{
			if (i==j)
				G->arc[i][j]=0;
			else
				G->arc[i][j] = G->arc[j][i] = GRAPH_INFINITY;
		}
	}

	G->arc[0][1]=10;
	G->arc[0][5]=11; 
	G->arc[1][2]=18; 
	G->arc[1][8]=12; 
	G->arc[1][6]=16; 
	G->arc[2][8]=8; 
	G->arc[2][3]=22; 
	G->arc[3][8]=21; 
	G->arc[3][6]=24; 
	G->arc[3][7]=16;
	G->arc[3][4]=20;
	G->arc[4][7]=7; 
	G->arc[4][5]=26; 
	G->arc[5][6]=17; 
	G->arc[6][7]=19; 

	for(i = 0; i < G->numNodes; i++)
	{
		for(j = i; j < G->numNodes; j++)
		{
			G->arc[j][i] =G->arc[i][j];
		}
	}

}
void Prime(MGraph G)
{
	int adjvex[MAXVEX];
	int lowcost[MAXVEX];
	adjvex[0]=0;
	lowcost[0]=0;
	for(int i=1;i<G.numNodes;i++)
	{
		lowcost[i]=G.arc[0][i];
		adjvex[i]=0;
	}
	for(int i=1;i<G.numNodes;i++)
	{
		int min=GRAPH_INFINITY;
		int j=1,k=0;
	 	for(int i=1;i<G.numNodes;i++)
	 	{
	 		if(lowcost[i]!=0&&lowcost[i]<min)
	 		{
	 			min=lowcost[i];
	 			k=i;
			}
		}
		printf("(%d %d)\n",adjvex[k],k);
		lowcost[k]=0;
		
		for(int j=1;j<G.numNodes;j++)
		{
			if(lowcost[j]!=0&&G.arc[k][j]<lowcost[j])
			{
				lowcost[j]=G.arc[k][j];
				adjvex[j]=k;	
			} 
		}
		
	}
}
int main()
{
	MGraph G;
	CreateMGraph(&G);
	Prime(G);
	return 0;
}





















