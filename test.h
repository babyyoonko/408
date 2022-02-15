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