#include<stdio.h>
#include<stdlib.h>
#define MAXVEX 100
#define GRAPH_INFINITY 100000

typedef char VertexType;
typedef int EdgeType;
typedef struct
{
	VertexType vexs[MAXVEX];
	EdgeType arc[MAXVEX][MAXVEX];
	int numNodes,numEdges;
}MGraph;

void CreateMGraph(MGraph *G)
{
	int i, j;

	G->numEdges=15;
	G->numNodes=9;

	/* 读入顶点信息，建立顶点表 */
	G->vexs[0]='A';
	G->vexs[1]='B';
	G->vexs[2]='C';
	G->vexs[3]='D';
	G->vexs[4]='E';
	G->vexs[5]='F';
	G->vexs[6]='G';
	G->vexs[7]='H';
	G->vexs[8]='I';


	for (i = 0; i < G->numNodes; i++)/* 初始化图 */
	{
		for ( j = 0; j < G->numNodes; j++)
		{
			G->arc[i][j]=GRAPH_INFINITY;
		}
	}

	G->arc[0][1]=1;
	G->arc[0][5]=1;

	G->arc[1][2]=1; 
	G->arc[1][8]=1; 
	G->arc[1][6]=1; 
	
	G->arc[2][3]=1; 
	G->arc[2][8]=1; 
	
	G->arc[3][4]=1;
	G->arc[3][7]=1;
	G->arc[3][6]=1;
	G->arc[3][8]=1;

	G->arc[4][5]=1;
	G->arc[4][7]=1;

	G->arc[5][6]=1; 
	
	G->arc[6][7]=1; 

	
	for(i = 0; i < G->numNodes; i++)
	{
		for(j = i; j < G->numNodes; j++)
		{
			G->arc[j][i] =G->arc[i][j];
		}
	}

}
int locate(MGraph G,char V)
{
	for(int i=0;i<G.numNodes;i++)
	{
		if(G.vexs[i]==V)
			return i;
		else 
			return -1;
	}
}

int FirstAdj(MGraph G,char V)
{
	int v=locate(G,V);
	if(v==-1)
	return -1;
	for(int i=0;i<G.numNodes;i++)
	{
		if(G.arc[v][i]!=GRAPH_INFINITY)
			return i;
	}
	return -1; 
}

int NextAdj(MGraph G,char V,int w)
{
	int v=locate(G,V);
	if(v==-1)
	return -1;
	for(int i=w+1;i<G.numNodes;i++)
	{
		if(G.arc[v][i]!=GRAPH_INFINITY)
			return i;
	}
	return -1;
}
short visited[MAXVEX];
void DFS(MGraph G,int v)
{
	visited[v]=true;
	printf("V%c ",G.vexs[v]);
	for(int j=FirstAdj(G,v);j!=-1;j=NextAdj(G,G.vexs[v],j))
	{
		if(visited[j]!=true)
		DFS(G,j);
	}	
}

void DFSTraverse(MGraph G)
{
	for(int i=0;i<G.numNodes;i++)
	visited[i]=false;
	for(int i=0;i<G.numNodes;i++)
	if(!visited[i])
	DFS(G,i);
}
#define MAXSIZE 10
typedef int QElemType;
typedef struct
{
	QElemType *base;
	int front; //头指针 
	int rear; //尾指针 
}SqQueue;

//初始化一个空队列
int InitQueue(SqQueue &Q)
{
	Q.base=(QElemType*)malloc(MAXSIZE *sizeof(QElemType));
	if(!Q.base)
	return 0;
	Q.front=0;
	Q.rear=0;
	return 1;	
} 
//销毁队列
int DestroyQueue(SqQueue &Q)
{
	if(Q.base)
	{
		free(Q.base);
	Q.base=NULL;
	Q.front=Q.rear=0;
	}
	return 1;
}

//清空队列
int ClearQueue(SqQueue Q)
{
	Q.rear=Q.front;
	return 1;
}

//判空
int QueueEmpty(SqQueue Q)
{
	if(Q.front==Q.rear)
		return 1;
	else
		return 0;
}

//求长度
int QueueLength(SqQueue Q)
{
	return (Q.rear-Q.front+MAXSIZE)%MAXSIZE;
} 

//求队头元素
int GetTop(SqQueue Q,int &e)
{
	e=Q.base[Q.front];
	return 1;
}

//插入
int EnQueue(SqQueue &Q,int e)
{
	if((Q.rear+1)%MAXSIZE==Q.front)//判断是否栈满 
	{
	Q.base=(QElemType*)malloc(MAXSIZE*2*sizeof(QElemType));
	for(int i=0;i<=QueueLength(Q);i++)
	{
		
		Q.base[i]=Q.base[Q.front];
		Q.front=(Q.front+1)%MAXSIZE;
	}
	Q.rear=Q.front;
	Q.front=0; 
	}//扩充队列 
	Q.base[Q.rear]=e;
	Q.rear=(Q.rear+1)%MAXSIZE;//若到最后则转到数组头部 
	return 1; 
} 

//删除
int DeQueue(SqQueue &Q,int &e) 
{
	if(Q.front==Q.rear)//判空
	return 0;
	e=Q.base[Q.front];
	Q.front=(Q.front+1)%MAXSIZE;
	return 1; 
}
void BFSTraverse(MGraph G)
{
	int e;
	SqQueue Q;
	for(int i=0;i<G.numNodes;i++)
	visited[i]=false;
	InitQueue(Q);
	for(int i=0;i<G.numNodes;i++)
	{
		if(!visited[i])
		{
			printf("V%c ",G.vexs[i]);
			visited[i]=true;
			EnQueue(Q,i);
			while(!QueueEmpty(Q))
			{
				DeQueue(Q,e);
				for(int j=0;j<G.numNodes;j++)
				{
					if(G.arc[e][j]!=GRAPH_INFINITY&&visited[j]==false)
					{
					printf("V%c ",G.vexs[j]);
					visited[j]=true;
					EnQueue(Q,j);
					}
				}
			}
		}
	}
}	
int main()
{
	MGraph G;
	CreateMGraph(&G);
	printf("深度优先搜索的序列为："); 
	DFSTraverse(G);
	printf("\n");
	printf("广度优先搜索的序列为：");
	BFSTraverse(G); 
	return 0;
}




















