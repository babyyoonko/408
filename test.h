#pragma once

#define maxSize 100

typedef struct LNode
{
	int data;
	struct LNode* next;
}LNode;

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