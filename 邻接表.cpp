#include<iostream>
using namespace std;
const int MaxNum = 100;

//��
struct ENode {
	int V1, V2;
	int Weight;
};
typedef ENode* Edge;

//�ڽӵ�
struct Node {
	int ID;	//�ڽӵ��±�
	int Weight;
	Node* Next; //ָ����һ���ڽӵ�
};
typedef struct Node* ProTo;

//��ͷ���
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