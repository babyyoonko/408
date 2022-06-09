#pragma once
#include<iostream>
using namespace std;
#define maxSize 100

typedef struct LNode
{
	int data;
	struct LNode* next;
}LNode;

typedef struct DLNode
{
	int data;
	struct DLNode* next;
	struct DLNode* prior;
}DLNode;

typedef struct SqList
{
	int data[maxSize];
	int length;
}SqList;

typedef struct SqList2
{
	float data[maxSize];
	int length;
}SqList2;

typedef struct
{
	int data[maxSize];
	int top;
}SqStack;

typedef struct
{
	char data[maxSize];
	int top;
}SqStack2;

typedef struct
{
	LNode* front;
	LNode* rear;
}LiQueue;

typedef struct
{
	char* ch;
	int length;
}Stra;

typedef struct
{
	char str[maxSize + 1];
	int length;
}Strb;


typedef struct BTNode
{
	int data;
	struct BTNode* lchild;
	struct BTNode* rchild;
}BTNode;



typedef struct
{
	int no;
}VertexType;

typedef struct
{
	int n;
	int e;
	int edges[maxSize][maxSize];
	VertexType vex[maxSize];
}MGraph;



typedef struct ArcNode
{
	int adjvex;
	struct ArcNode* nextarc;
}ArcNode;

typedef struct
{
	int data;
	ArcNode* firstarc;
}VNode;

typedef struct
{
	int n;
	int e;
	VNode adjlist[maxSize];
}AGraph;

void printArray(int R[], int n)
{
	for (int i = 0; i < n; i++)
	{
		std::cout << R[i] << ' ';
	}
	std::cout << std::endl;
}