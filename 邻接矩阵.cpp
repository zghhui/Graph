#include<iostream>
using namespace std;
const int MaxN =100;
const int INEX = 65535;
struct GNode {
	int n;	//点数
	int e;	//边数
	int G[MaxN][MaxN];
	int Data[MaxN];
};
typedef GNode* Graph;

struct ENode {
	int V1; //顶点1
	int V2;	//顶点2
	int Weight;
};
typedef ENode* Edge;

//创建一个只有顶点的空图
Graph CreatGraph(int n)
{
	Graph G;
	G = (Graph)malloc(sizeof(GNode));
	G->n = n;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			G->G[i][j] = INEX;
		}
	}
	return G;
}

//添加边的信息
void InsertEdge(Graph G, Edge E)
{
	G->G[E->V1][E->V2] = E->Weight;
	G->G[E->V2][E->V1] = E->Weight;
}

Graph BulidGraph()
{
	Edge E;
	Graph G;
	int n, e;

	cin >> n;
	G=CreatGraph(n);
	cin >> G->e;
	if (G->e != 0)
	{
		E = (Edge)malloc(sizeof(ENode));
		for (int i = 1; i <= G->e; i++)
		{
			cin >> E->V1 >> E->V2 >> E->Weight;
			InsertEdge(G, E);
		}
	}
	

	//如果顶点有数据 读入顶点数据
	for (int i = 0; i < G->n; i++)
	{
		cin >> G->Data[i];
	}

}


