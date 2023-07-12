#include<stdio.h>
#include<stdlib.h>
#define MAXEDGE 20
#define MAXVEX 20
#define GRAPH_INFINITY 100000

typedef struct
{
	int arc[MAXVEX][MAXVEX];
	int numNodes;
}MGraph;

void CreateMGraph(MGraph &G)//构建图
{
	int i, j;
	G.numNodes=9;

	for (i = 0; i < G.numNodes; i++)
	{
		for ( j = 0; j < G.numNodes; j++)
		{
			if (i==j)
				G.arc[i][j]=0;
			else
				G.arc[i][j] = G.arc[j][i] = GRAPH_INFINITY;
		}
	}

	G.arc[0][1]=10;
	G.arc[0][5]=11; 
	G.arc[1][2]=18; 
	G.arc[1][8]=12; 
	G.arc[1][6]=16; 
	G.arc[2][8]=8; 
	G.arc[2][3]=22; 
	G.arc[3][8]=21; 
	G.arc[3][6]=24; 
	G.arc[3][7]=16;
	G.arc[3][4]=20;
	G.arc[4][7]=7; 
	G.arc[4][5]=26; 
	G.arc[5][6]=17; 
	G.arc[6][7]=19; 

	for(i = 0; i < G.numNodes; i++)
	{
		for(j = i; j < G.numNodes; j++)
		{
			G.arc[j][i] =G.arc[i][j];
		}
	}

}

typedef int ShortPath[MAXVEX];
typedef int PathArc[MAXVEX];

void Dijkstra(MGraph G,int V0,ShortPath *D,PathArc *P)
{
	int final[MAXVEX];
	for(int i=0;i<G.numNodes;i++)
	{
		final[i]=0;
		(*D)[i]=G.arc[V0][i];
		(*P)[i]=-1;
	}
	(*D)[V0]=0;
	final[V0]=1;
	
	for(int j=0;j<G.numNodes;j++)
	{
		int k;
		int min=GRAPH_INFINITY;
		for(int i=0;i<G.numNodes;i++)
		{
			if(final[i]==0&&min>(*D)[i])
			{
				min=(*D)[i];
				k=i;
			}
		}
		final[k]=1;
		for(int i=0;i<G.numNodes;i++)
		{
			if(final[i]==0&&min+G.arc[k][i]<(*D)[i])
			{
				(*D)[i]=min+G.arc[k][i];
				(*P)[i]=k; 
			}
		}
	}
}

int main()
{
	int c[MAXVEX];
	MGraph G;
	CreateMGraph(G);
	ShortPath D;
	PathArc P;
	int V;
	printf("请输入要查询的节点：\n");
	scanf("%d",&V);
	Dijkstra(G,V,&D,&P);
	printf("节点路径及其最短路径长度为：\n");
	for(int i=0;i<G.numNodes;i++)
	{
		int t=0;
		printf("V%d--V%d :",V,i);
		int j;
		j=i;
		c[0]=i;
		while(P[j]!=-1)
		{
			c[++t]=P[j];		
			j=P[j];
		}
		c[++t]=V;
	for(int k=t;k>=0;k--)
	printf("V%d ",c[k]);
	printf("从%d节点到%d的最短路径为%d\n",V,i,D[i]);
	}
	return 0;
}


