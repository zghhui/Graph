#include<iostream>
using namespace std;
const int MaxNum = 100;

//边
struct ENode {
	int V1, V2;
	int Weight;
};
typedef ENode* Edge;

//邻接点
struct Node {
	int ID;	//邻接点下标
	int Weight;
	Node* Next; //指向下一个邻接点
};
typedef struct Node* ProTo;

//表头结点
struct VNode {
	int data;
	ProTo ProPoint;
};
typedef struct VNode VList[MaxNum];

struct GNode {
	int n;
	int e;
	VList G;
};
typedef GNode* Graph;

Graph Creat(int n)
{
	Graph G;
	G = (Graph)malloc(sizeof(GNode));
	G->n = n;
	for (int i = 0; i < n; i++)
	{
		G->G[i].ProPoint=NULL;
	}

	return G;
}

void InsertEdge(Graph G, Edge E)
{
	ProTo temP;
	temP = (ProTo)malloc(sizeof(Node));
	temP->ID = E->V2;
	temP->Weight = E->Weight;
	temP->Next = G->G[E->V1].ProPoint;
	G->G[E->V1].ProPoint = temP;
}

Graph BuildGraph()
{
	Graph G;
	Edge E;
	int n;

	cin >> n;
	G = (Graph)malloc(sizeof(GNode));
	G = Creat(n);
	cin >> G->e;
	if (G->e != 0)
	{
		E = (Edge)malloc(sizeof(ENode));
		cin >> E->V1 >> E->V2 >> E->Weight;
		InsertEdge(G, E);
	}
	return G;
}
int main()
{
	return 0;
}