#include <stdio.h>
#include "test.h"
#include <iostream>
#include<math.h>
using namespace std;

// [1, 2, 3, 4, 5, 6, 7, 8]



int findElem(SqList L,int x)
{
	int i;
	for (i = 0; i < L.length; i++)
	{
		if (x < L.data[i]) {
			return i;
		}
	}
	return i;
}

int insertElem(SqList& L, int x, int index) 
{	
	if (index < 0 || index > L.length || L.length >= maxSize)
	{
		return 0;
	}
	int i;
	for (i = L.length; i > index; i--)
	{
		L.data[i] = L.data[i - 1];
	}
	L.data[index] = x;
	L.length++;
	return 1;
}

// [1, 2, 3, 4, 5, 6, 7, 8]
int deleteElem(SqList &L, int p, int &e)
{
	if (p < 0 || p >= L.length)
	{
		return 0;
	}
	int i;
	e = L.data[p];
	for (i = p; i < L.length - 1; i++)
	{
		L.data[i] = L.data[i + 1];
	}
	L.length--;
	return 1;
	//for (i = 0; i < L.length; i++)
	//{
	//	if (L.data[i] == x)
	//	{
	//		index = i;
	//		break;
	//	}
	//}
}

// 1-2-4
// 2-3-5-7-8
//=1-2-2-3-4-5-7-8
void merge(LNode *A, LNode *B, LNode *&C)
{
	C = A;
	LNode *p = A->next;
	LNode *q = B->next;
	free(B);
	LNode *c = C;
	C->next = nullptr;
	while (p != nullptr && q != nullptr)
	{
		if (p->data <= q->data)
		{
			c->next = p;
			p = p->next;
		}
		else
		{
			c->next = q;
			q = q->next;
		}
		c = c->next;
	}
	c->next = p != nullptr ? p : q;
}
// 4-3-2-2-1
// 1-2-4
// 2-3-5-7-8
//=8-7-5-4-3-2-2-1
void merge_reverse(LNode* A, LNode* B, LNode*& C)
{
	C = A;
	LNode* p = A->next;
	LNode* q = B->next;
	free(B);
	LNode* next = nullptr;
	C->next = nullptr;
	while (p != nullptr && q != nullptr)
	{
		if (p->data <= q->data)
		{
			next = p->next;
			p->next = C->next;
			C->next = p;
			p = next;
		}
		else
		{
			next = q->next;
			q->next = C->next;
			C->next = q;
			q = next;
		}
	}
	while (p != nullptr)
	{
		next = p->next;
		p->next = C->next;
		C->next = p;
		p = next;
	}
	while (q != nullptr)
	{
		next = q->next;
		q->next = C->next;
		C->next = q;
		q = next;
	}
}

int findAndDelete(LNode *c,int x)
{
	LNode* p = c;
	while (p->next != nullptr)
	{
		if (p->next->data == x)
		{
			LNode* q = p->next;
			p->next = p->next->next;
			free(q);
			return 1;
		}
		p = p->next;
	}
	return 0;
}

LNode* createList()
{
	LNode* headA = (LNode*)malloc(sizeof(LNode));
	headA->next = (LNode*)malloc(sizeof(LNode));
	LNode* A = headA;
	while (cin >> A->next->data)
	{
		LNode* next = (LNode*)malloc(sizeof(LNode));
		A->next->next = next;
		A = A->next;
	}
	cin.clear();
	cin.sync();
	free(A->next);
	A->next = nullptr;
	return headA;
}

// 1-2-3-4-5-6-7-8-9     9-8-7-6-5-4-3-2-1
// 1-2-3-4-5-6-7-8-9	 4-3-2-1-5-6-7-8-9	 9-8-7-6-5-1-2-3-4
// 1-2-3-4-5-6-7-8-9	 4-3-2-1-9-8-7-6-5   5-6-7-8-9-1-2-3-4

// 5 7 9 11 1 6 8 12 13
// 1 5 7 9 11 6 8 12 13
// 1 5 6 7 9 11 8 12 13
void chapter2_simulation1(int A[],int m,int n)
{
	int i;
	for (i = m; i <= m+n-1; i++)	// ??????A[]????n??????????????????m??????????????????
	{
		int temp = A[i];	//????????????????????????????
		int j;
		for (j = i - 1; j >= 0; j--)
		{
			// ????????????????????A[j]????????????????????????????????????j??????????????????????
			if (temp < A[j])	
			{
				// ????????????????????????????????????
				A[j + 1] = A[j];
			}
			else
			{
				break;
			}
		}
		// ????????????????j+1??????????????j??????????????????????????????j+1??
		A[j+1] = temp;
	}
}


// A: H-1-2-3-4-5-6-7-
// B: H-1-3-7-8-
void chapter2_simulation2(LNode* A,LNode *B)
{
	if (A == nullptr || A->next == nullptr)	//??A????????????????????
	{
		return;
	}
	LNode* p = A;	// ??????????????p??q????A??B??????????????????????????????????????????????????????????????B????????????
	LNode* q = B;
	LNode* temp = nullptr;	// temp????????????????????????????????????????????????
	while (p->next != nullptr && q->next != nullptr)	// ??p??q??????????????????????????????????????????
	{
		if (q->next->data == p->next->data)	// ????????A????????????B??????????????????A??????????????q????????
		{
			temp = p->next;
			p->next = p->next->next;
			free(temp);
			q = q->next;

		}
		else if (q->next->data > p->next->data)	// ??A??B??????????????p??q????????????????????????????????????
		{
			p = p->next;
		}
		else
		{
			q = q->next;
		}

	}

}

// 1 2 3 4 5 6 7 8
//1+2+3+...+n
//Sn = n(1+n)/2 ,* 1/n = (1+n)/2

// 1 2 3 4 5 6 7 8 
void chapter2_3_inversion(SqList &L)
{
	int i,j;
	int temp;
	for (int i = 0,j=L.length-1; i<j; ++i,++j)
	{
		temp = L.data[i];
		L.data[i] = L.data[j];
		L.data[j] = temp;
	}
}

// 1 2 3 4 5 6 7 8
// 3-5
void chapter2_4_removeRange(SqList& L,int i,int j)
{
	int index = i;
	int k;
	for (k = j+1; k < L.length; k++, index++)
	{
		L.data[index] = L.data[k];
	}
	L.length -= j - i + 1;
}

// 6 10 8 2 0 7 1 12 3
// 0 1 2 3 6 7 8 10 12
void chapter2_5_partition(SqList& L)
{
	if (L.length == 0)
	{
		return;
	}
	int pivot = L.data[0];
	int left = 0;
	int right = L.length - 1;
	while (left < right)
	{
		while (left < right && L.data[right] >= pivot)
		{
			right--;
		}
		L.data[left] = L.data[right];
		while (left < right && L.data[left] <= pivot)
		{
			left++;
		}
		L.data[right] = L.data[left];
	}
	L.data[left] = pivot;
}

// 1 1 2 3 3 3 4 4 7 7 7 9 9 9
// ????????????
void chapter2_6_deleteDuplicate(LNode *head)
{
	LNode* p = head->next;
	while (p->next != nullptr)
	{
		if (p->next->data == p->data)
		{
			LNode* q = p->next;
			p->next = p->next->next;
			free(q);
		}
		else
		{
			p = p->next;
		}
	}
}

// 6-1-2-3-0-9-12-4
// ????????
void chapter2_7_deleteMinNode(LNode* L)
{
	LNode* pre = L;
	LNode* p = L->next;
	LNode* minNode = p;
	LNode* minNodePre = pre;
	while (p != nullptr)
	{
		if (p->data < minNode->data)
		{
			minNode = p;
			minNodePre = pre;
		}
		p = p->next;
		pre = pre->next;
	}
	minNodePre->next = minNodePre->next->next;
	free(minNode);
}

// L-6-1-2-3-0-9-12-4
// ????????
// L-4-12-9-0-3-2-1-6
// ????????
// L-null
void chapter2_8_inverseList(LNode* L)
{
	LNode* p = L->next;
	LNode* next;
	L->next = nullptr;
	while (p != nullptr)
	{
		next = p->next;
		p->next = L->next;
		L->next = p;
		p = next;
	}
}

// A-6-1-2-3-0-9-12-4
// A-1-3-9
// B-6-2-0-12-4
//
// B-null
LNode* chapter2_9_split(LNode* A)
{
	LNode* B = (LNode*)malloc(sizeof(LNode));
	B->next = nullptr;
	LNode* p = A;
	LNode* q = B;
	LNode* temp = nullptr;
	while (p->next != nullptr)
	{
		if ((p->next->data & 1)==1)
		{
			p = p->next;
		}
		else
		{
			temp = p->next;
			p->next = p->next->next;
			temp->next = q->next;
			q->next = temp;
			q = q->next;
		}
	}
	return B;
}

// 5 2 8 9 7 3 4 6 
int chapter2_10_findMin(int A[], int N, int i)
{
	i = A[0];
	while (i/10 <= N-1)
	{
		if (i%10 > A[i/10])
		{
			i = i - i % 10;
			i = i + A[i / 10];
		}
		i = i + 10;
	}
	return i % 10;
}

// L
// |
// 6 - 1 - 2 - 3 - 0 - 9 - 12 - 4
//??????????
void chapter2_11_print_reversely(LNode* L)
{
	if (L == nullptr)
	{
		return;
	}
	chapter2_11_print_reversely(L->next);
	cout << L->data << endl;
}

//1 2 3 5 6 7
//1 2 4 5 6 7
int chapter2_13_compare(SqList2 A,SqList2 B)
{
	int i=0;
	while (i<A.length && i<B.length)
	{
		if (fabs(A.data[i] - B.data[i]) <= 10e-5)
		{
			i++;
		}
		else
		{
			break;
		}
	}
	if (i == A.length && i == B.length)
	{
		return 0;
	}
	else
	{
		if (i == A.length || i == B.length)
		{
			return i == A.length ? -1 : 1;
		}
		else
		{
			return A.data[i] < B.data[i] ? -1 : 1;
		}
	}
}

//head-1-2-3-5-6-7
int chapter2_14_findLastKNode(LNode *head,int k)
{
	LNode* p = head;
	LNode* q = head;
	for (int i = 0; i < k && q != nullptr; i++)
	{
		q = q->next;
	}
	while (q != nullptr)
	{
		p = p->next;
		q = q->next;
	}
	if (p == head)
	{
		return 0;
	}
	else
	{
		cout << p->data << endl;
		return 1;
	}
}

// 0 1 2 3 4 5 6 7 8 
// p=3
// 2 1 0 3 4 5 6 7 8
// 2 1 0 8 7 6 5 4 3
// 3 4 5 6 7 8 0 1 2


// 1-2-3-4
void reverse(SqList R,int left,int right)
{
	while (left < right)
	{
		int temp = R.data[left];
		R.data[left] = R.data[right];
		R.data[right] = temp;
		++left;
		--right;
	}
}

void chapter2_15_move(SqList R, int p)
{
	reverse(R, 0, p - 1);
	reverse(R, p, R.length - 1);
	reverse(R, 0, R.length - 1);
}

// 0 5 5 3 5 7 5 5
// 0 8 1 2 3 4 7 6 10
int findPrimaryElem(int A[],int n)
{
	int number;
	int votes = 0;
	for (int i = 0; i < n; i++)
	{
		if (votes == 0)
		{
			number = A[i];
		}
		votes += number == A[i] ? 1 : -1;
	}
	votes = 0;
	for (int i = 0; i < n; i++)
	{
		if (A[i] == number)
		{
			votes++;
		}
	}
	return votes > n / 2 ? number : -1;
}

// (((()()))
// ())()
int chapter3_match(char exp[], int n)
{
	char stack[maxSize];
	int top = -1;
	for (int i = 0; i < n; ++i)
	{
		if (exp[i] == '(')
		{
			stack[++top] = exp[i];
		}
		if (exp[i] == ')')
		{
			if (top == -1)
			{
				return 0;
			}
			else
			{
				top--;

			}

		}
	}
	return top == -1 ? 1 : 0;
}

int op(int a,int b,char op)
{
	switch (op)
	{
	case '*':
		return a * b;
	case '+':
		return a + b;
	case '-':
		return a - b;
	case '/':
	{
		if (b == 0)
		{
			cout << "error" << endl;
			return 0;
		}
		else
		{
			return a / b;
		}
	}
	default:
		break;
	}
}

// 1234*++5/
// (1+2+3*4)/5
int chapter3_valueOfRPN(char exp[])
{
	int stack[maxSize];
	int top = -1;
	int i;
	for (i = 0 ; exp[i] != '\0'; ++i)
	{
		if (exp[i] <= '9' && exp[i] >= '0')
		{
			stack[++top] = exp[i] - '0';
		}
		else
		{
			int a = stack[top--];
			int b = stack[top--];
			stack[++top] = op(b, a, exp[i]);
		}
	}
	return stack[top];
}

typedef struct SharedStack
{
	int elem[maxSize];
	int top0;
	int top1;
}SharedStack;

void chapter3_simulation1_initStack(SharedStack &s)
{
	s.top0 = -1;
	s.top1 = maxSize;
}

int chapter3_simulation1_push(SharedStack& s, int stNo, int x)
{
	if (s.top0 + 1 == s.top1)
	{
		return 0;
	}
	if (stNo == 0)
	{
		s.elem[++s.top0] = x;
		return 1;
	}
	else if (stNo == 1)
	{
		s.elem[--s.top1] = x;
		return 1;
	}
	else
	{
		return -1;
	}
}

int chapter3_simulation1_pop(SharedStack& s, int stNo, int &x)
{
	if (stNo == 0)
	{
		if (s.top0 == -1)
		{
			return 0;
		}
		else
		{
			x = s.elem[s.top0--];
			return 1;
		}
	}
	else if(stNo == 1)
	{
		if (s.top1 == maxSize)
		{
			return 0;
		}
		else
		{
			x = s.elem[s.top1++];
			return 1;
		}
	}
	else
	{
		return -1;
	}
}


int isEmpty(SqStack s)
{
	if (s.top == -1)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

void push(SqStack& ST, int x)
{
	if (ST.top + 1 == maxSize)
	{
		return;
	}
	else
	{
		ST.data[++ST.top] = x;
	}
}

void pop(SqStack& ST, int& x)
{
	if (isEmpty(ST))
	{
		return;
	}
	else
	{
		x = ST.data[ST.top--];
	}
}

int chapter3_simulation2_enqueue(SqStack& s1,SqStack& s2,int x)
{
	if (s1.top + 1 == maxSize && !isEmpty(s2)) // ????s2??????s1??????????????????????????
	{
		return 0;
	}
	else
	{
		if (s1.top + 1 == maxSize) //s1????????s2??????????s1????????????????????????s2??
		{
			while (!isEmpty(s1))
			{
				int temp;
				pop(s1,temp);
				push(s2,temp);
			}
			push(s1, x); // ????s1????????????????
		}
		else
		{
			push(s1, x); // s1????????????s1??????
		}
		return 1;
	}
}

int chapter3_simulation2_isQueueEmpty(SqStack s1,SqStack s2)
{
	if (isEmpty(s1) && isEmpty(s2)) //????s1??s2????????????????????
	{
		return 1;
	}
	else // ????s1??s2??????????????????????????
	{
		return 0;
	}
}

int chapter3_simulation2_dequeue(SqStack& s1, SqStack& s2, int &x)
{
	if (chapter3_simulation2_isQueueEmpty(s1,s2)) // ?? ????????????????????
	{
		return 0;
	}
	else
	{
		if (s2.top == -1) // ????s2????????s1??????????????????????s2??
		{

			while (!isEmpty(s1))
			{
				int temp;
				pop(s1, temp);
				push(s2, temp);
			}
			pop(s2, x); // ??????s2????????????????
		}
		else
		{
			pop(s2, x); //s2????????????????s2????????
		}
		return 1;
	}
}

// 4 3 5 6 1 2
int chapter3_3_3_judege(char ch[])
{
	int i = 0;
	int I = 0;
	int O = 0;
	while (ch[i] != '\0')
	{
		if (ch[i] == 'I')
		{
			++I;
		}
		else if(ch[i] == 'O')
		{
			++O;
			if (O > I)
			{
				return 0;
			}
		}
		++i;
	}
	if (I != O)
	{
		return 0;
	}
	else
	{
		return 1;
	}
}

void chapter3_6_enqueue(LNode*& rear,int x)
{
	LNode* p = (LNode*)malloc(sizeof(LNode));
	p->data = x;
	p->next = rear->next;
	rear->next = p;
	rear = p;
}

void chapter3_6_dequeue(LNode*& rear, int &x)
{
	if (rear->next == rear)
	{
		return;
	}
	LNode* head = rear->next;
	LNode* p = head->next;
	x = p->data;
	head->next = head->next->next;
	if (p == rear)
	{
		rear = head;
	}
	free(p);
}

typedef struct
{
	int data[maxSize];
	int front;
	int rear;
}chapter3_7_dbqueue;

int charpter3_7_dequeueFromRear(chapter3_7_dbqueue &q, int& x)
{
	if (q.front == q.rear)
	{
		return 0;
	}
	x = q.data[q.rear];
	q.rear = (q.rear - 1 + maxSize) % maxSize;
	return 1;
}

int charpter3_7_enqueueFromFront(chapter3_7_dbqueue& q, int x)
{
	if ((q.rear+1)%maxSize == q.rear)
	{
		return 0;
	}
	q.data[q.front] = x;
	q.front = (q.front - 1 + maxSize) % maxSize;
	return 1;
}

typedef struct
{
	int data[maxSize];
	int front;
	int rear;
	int tag;
}chapter_3_8_cycqueue;

void initCycqueue(chapter_3_8_cycqueue& q)
{
	q.front = 0;
	q.rear = 0;
	q.tag = 0;
}

int isQueueEmpty(chapter_3_8_cycqueue q)
{
	if (q.front == q.rear && q.tag == 0)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

int isQueueFull (chapter_3_8_cycqueue q)
{
	if (q.front == q.rear && q.tag == 1)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

int chapter_3_8_enqueue(chapter_3_8_cycqueue& q, int x)
{
	if (isQueueFull(q)==1)
	{
		return 0;
	}
	else
	{
		q.tag = 1;
		q.rear = (q.rear + 1) % maxSize;
		q.data[q.rear] = x;
		return 1;
	}
}

int chapter_3_8_dequeue(chapter_3_8_cycqueue& q, int &x)
{
	if (isQueueEmpty(q)==1)
	{
		return 0;
	}
	else
	{
		q.front = (q.front + 1) % maxSize;
		x = q.data[q.front];
		q.tag = 0;
		return 1;
	}
}

int transform(int N)
{
	int stack[maxSize];
	int top = -1;
	while (N != 0)
	{
		stack[++top] = N % 2;
		N = N / 2;
	}
	int result = 0;
	while (top != -1)
	{
		result = result * 10 + stack[top--];
	}
	return result;
}

int isEmpty2(SqStack2 s)
{
	if (s.top == -1)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

void push2(SqStack2& ST, char x)
{
	if (ST.top + 1 == maxSize)
	{
		return;
	}
	else
	{
		ST.data[++ST.top] = x;
	}
}

void pop2(SqStack2& ST, char& x)
{
	if (isEmpty2(ST))
	{
		return;
	}
	else
	{
		x = ST.data[ST.top--];
	}
}

void getTop(SqStack2 s, char& x)
{
	if (!isEmpty2(s))
	{
		x = s.data[s.top];
	}
}

int chapter_3_10_match(char c[])
{
	SqStack2 s;
	s.top = -1;
	int i = 0;
	while (c[i] != '\0')
	{
		if (c[i] == 39)
		{
			++i;
			while (c[i] != 39)
			{
				++i;
			}
			++i;
		}
		else if (c[i] == 34)
		{
			++i;
			while (c[i] != 34)
			{
				++i;
			}
			++i;
		}
		else if(c[i] == '(' || c[i] == '[' || c[i] == '{')
		{
			push2(s, c[i]);
		}
		else
		{
			char topElem;
			getTop(s, topElem);
			switch (c[i])
			{
			case ')':
				if (topElem != '(')
				{
					return 0;
				}
				else
				{
					pop2(s,topElem);
					break;
				}
			case '}':
				if (topElem != '{')
				{
					return 0;
				}
				else
				{
					pop2(s, topElem);
					break;
				}
			case ']':
				if (topElem != '[')
				{
					return 0;
				}
				else
				{
					pop2(s, topElem);
					break;
				}
			default:
				break;
			}
		}
		++i;
	}
	if (isEmpty2(s))
	{
		return 1;
	}
	else
	{
		return 0;
	}
}



int charpter_3_11_sqrt_recursively(float A, float p, float e)
{
	if (fabs(p * p - A) < e)
	{
		return p;
	}
	else
	{
		return charpter_3_11_sqrt_recursively(A, (p + A / p) / 2, e);
	}
}

int charpter_3_11_sqrt_nonrecursively(float A, float p, float e)
{
	float stack[maxSize];
	int top = -1;
	stack[++top] = (p + A / p) / 2;
	while (top != -1)
	{
		float pt = stack[top--];
		if (fabs(pt * pt - A) < e)
		{
			return pt;
		}
		else
		{
			stack[++top] = (pt + A / pt) / 2;
		}
	}
}

int charpter_3_11_sqrt_nonrecursively2(float A, float p, float e)
{
	while (fabs(p * p - A) >= e)
	{
		p = (p + A / p) / 2;
	}
	return p;
}

//A B C D E
int charpter_3_12_permutation(char c[], int k, int n)
{
	return 0;
}

void charpter_4_1_1_transform(Stra& str, char ch1, char ch2)
{
	if (str.ch == nullptr)
	{
		return;
	}
	for (int i = 0; i < str.length; i++)
	{
		if (str.ch[i] == ch1)
		{
			str.ch[i] = ch2;
		}
	}
}

// a b c d e
void charpter_4_1_1_reverse(Stra& str)
{
	if (str.ch == nullptr)
	{
		return;
	}
	for (int i = 0; i < str.length / 2; i++)
	{
		char temp = str.ch[i];
		str.ch[i] = str.ch[str.length - i - 1];
		str.ch[str.length - i - 1] = temp;
	}
}

void charpter_6_level(BTNode* p)
{
	if (p == nullptr)
	{
		return;
	}
	BTNode* queue[maxSize];
	int front = 0;
	int rear = 0;
	rear = (rear + 1) % maxSize;
	queue[rear] = p;
	while (front != rear)
	{
		front = (front + 1) % maxSize;
		BTNode* q = queue[front];
		cout << q->data << endl; // visit
		if (q->lchild != nullptr)
		{
			rear = (rear + 1) % maxSize;
			queue[rear] = q->lchild;
		}
		if (q->rchild != nullptr)
		{
			rear = (rear + 1) % maxSize;
			queue[rear] = q->rchild;
		}
	}
}

int charpter_6_maxWidth(BTNode* p)
{
	int maxWidth = 1;
	if (p == nullptr)
	{
		return 0;
	}
	BTNode* queue[maxSize];
	int front = 0;
	int rear = 0;
	rear = (rear + 1) % maxSize;
	queue[rear] = p;
	while (front != rear)
	{
		front = (front + 1) % maxSize;
		BTNode* q = queue[front];
		cout << q->data << endl; // visit
		if (q->lchild != nullptr)
		{
			rear = (rear + 1) % maxSize;
			queue[rear] = q->lchild;
		}
		if (q->rchild != nullptr)
		{
			rear = (rear + 1) % maxSize;
			queue[rear] = q->rchild;
		}
	}
}

// ????????????????????
void charpter_6_preorderNonrecursion(BTNode* bt)
{
	if (bt != nullptr)
	{
		BTNode* stack[maxSize];
		int top = -1;
		BTNode* p;
		stack[++top] = bt;
		while (top != -1)
		{
			p = stack[top--];
			cout << p->data << endl;
			if (p->rchild != nullptr)
			{
				stack[++top] = p->rchild;
			}
			if (p->lchild != nullptr)
			{
				stack[++top] = p->lchild;
			}
		}
	}
}

void charpter_6_inorderNonrecursion(BTNode* bt)
{
	if (bt != nullptr)
	{
		BTNode* stack[maxSize];
		int top = -1;
		BTNode* p = bt;
		while (top != -1 || p != nullptr)
		{
			while (p != nullptr)
			{
				stack[++top] = p;
				p = p->lchild;
			}
			p = stack[top--];
			cout << p->data << endl;
			p = p->rchild;

		}
	}
}

//??????
void charpter_6_postorderNonrecursion(BTNode* bt)
{
	if (bt != nullptr)
	{
		BTNode* stack[maxSize];
		int top = -1;
		BTNode* p = bt;
		BTNode* prev = nullptr;
		while (top != -1 || p != nullptr)
		{
			while (p != nullptr)
			{
				stack[++top] = p;
				p = p->lchild;
			}
			p = stack[top--];
			if (p->rchild == nullptr || p->rchild == prev)
			{
				cout << p->data << endl;
				prev = p;
				p = nullptr;
			}
			else
			{
				stack[++top] = p;
				p = p->rchild;
			}

		}
	}
}

int visit[maxSize];
void chapter_7_DFS(AGraph* G, int v)
{
	visit[v] = 1;
	cout << v << endl;
	ArcNode* p = G->adjlist[v].firstarc;

	while (p != nullptr)
	{
		if (visit[p->adjvex] == 0)
		{
			chapter_7_DFS(G,p->adjvex);
		}
		p = p->nextarc;
	}
	
}


void chapter_7_BFS(AGraph* G, int v, int visit[maxSize])
{
	int queue[maxSize];
	int front = 0;
	int rear = 0;
	rear = (rear + 1) % maxSize;
	queue[rear] = v;
	int temp;
	ArcNode* p;
	while (front != rear)
	{
		front = (front + 1) % maxSize;
		temp = queue[front];
		visit[temp] = 1;
		cout << temp << endl;
		p = G->adjlist[temp].firstarc;
		while (p != nullptr)
		{
			if (visit[p->adjvex] == 0)
			{
				rear = (rear + 1) % maxSize;
				queue[rear] = v;
			}
			p = p->nextarc;
		}
	}
}

// 1 4 7 8 9 12 14 15
int chapter_9_BinarySearch(int R[], int low, int high, int k)
{
	int mid;
	while (low <= high)
	{
		mid = (low + high) / 2;
		if (R[mid] == k)
		{
			return mid;
		}
		else if (R[mid] < k)
		{
			low = mid + 1;
		}
		else
		{
			high = mid - 1;
		}
	}
	return 0;
}

BTNode* chapter_9_BSTSearch(BTNode* bt,int key)
{
	if (bt == nullptr)
	{
		return nullptr;
	}
	else
	{
		if (bt->data == key)
		{
			return bt;
		}
		else if (bt->data < key)
		{
			return chapter_9_BSTSearch(bt->rchild,key);
		}
		else
		{
			return chapter_9_BSTSearch(bt->lchild, key);
		}
	}
}


int preValue = -1;
int hasInitPreValue = 0;
int chapter_9_judgeBST(BTNode* bt)
{
	if (bt == nullptr)
	{
		return 1;
	}
	if (chapter_9_judgeBST(bt->lchild) == 1)
	{
		if (hasInitPreValue == 0)
		{
			hasInitPreValue = 1;
		}
		else
		{
			if (preValue >= bt->data)
			{
				return 0;
			}
		}
		preValue = bt->data;
		return chapter_9_judgeBST(bt->rchild);
	}
	else
	{
		return 0;
	}
}

// 49 38 65 97 76 13 27 49
// 38 49 65 97 76
void charpte_8_InsertSort(int R[], int n)
{
	int temp;
	for (int i = 1; i < n; i++)
	{
		temp = R[i];
		int j;
		for (j = i; j > 0; j--)
		{
			if (R[j - 1] > temp)
			{
				R[j] = R[j - 1];
			}
			else
			{
				break;
			}
		}
		R[j] = temp;
	}
	for (int i = 0; i < n; i++)
	{
		cout << R[i] << ' ';
	}
}


// 49 38 65 97 76 13 27 49
// 38 49 65 76 13 27 49 97
void charpte_8_BubbleSort(int R[], int n)
{
	int swap;
	int temp;
	for (int i = 0; i < n-1; i++)
	{
		swap = 0;
		for (int j = 0; j < n - 1 - i; j++)
		{
			if (R[j] > R[j + 1])
			{
				swap = 1;
				temp = R[j];
				R[j] = R[j + 1];
				R[j + 1] = temp;

			}
		}
		if (swap == 0)
		{
			break;
		}
	}
	for (int i = 0; i < n; i++)
	{
		cout << R[i] << ' ';
	}
}


//			49
// 49 38 65 97 76 13 27 49
// 27 38 13 49 76 97 65 49
int charpte_8_partition(int R[], int low, int high)
{
	int pivot = R[low];
	while (low < high)
	{
		while (low < high && R[high] >= pivot)
		{
			--high;
		}
		R[low] = R[high];
		while (low < high && R[low] <= pivot)
		{
			++low;
		}
		R[high] = R[low];
	}
	R[low] = pivot;
	return low;
}

void quickSort(int R[], int low, int high)
{
	if (low < high)
	{
		int partitionIndex = charpte_8_partition(R, low, high);
		quickSort(R, low, partitionIndex - 1);
		quickSort(R, partitionIndex + 1, high);
	}
}


// 49 38 65 97 76 13 27 49
void charpte_8_SelectSort(int R[], int n)
{
	int minIndex;
	for (int i = 0; i < n-1; i++)
	{
		minIndex = i;
		for (int j = i+1; j < n; j++)
		{
			if (R[j] < R[minIndex])
			{
				minIndex = j;
			}
		}
		int temp = R[i];
		R[i] = R[minIndex];
		R[minIndex] = temp;
		for (int i = 0; i < n; i++)
		{
			cout << R[i] << ' ';
		}
		cout << endl;
	}
}

// ????????????????2 * i????????????????????0??????????2i+1.??????????????????????????????????
//void charpte_8_Sift(int R[], int low, int high)
//{
//	int i = low;
//	int j = 2 * i;
//	int temp;
//	while (j <= high)
//	{
//		if (j < high && R[j + 1] > R[j])
//		{
//			j++;
//		}
//		if (R[i] < R[j])
//		{
//			temp = R[i];
//			R[i] = R[j];
//			R[j] = temp;
//			i = j;
//			j = 2 * i;
//		}
//		else
//		{
//			break;
//		}
//	}
//	printArray(R, 8);
//
//}
//
//void charpte_8_HeapSort(int R[], int n)
//{
//	int siftIndex = n / 2;
//	if (n % 2 == 0)
//	{
//		siftIndex--;
//	}
//	// ????????
//	for (int i = siftIndex; i >= 0; i--)
//	{
//		charpte_8_Sift(R, i, n - 1);
//	}
//	int temp;
//	// ????????????????????????????????????????????????
//	for (int i = n-1; i>0 ; i--)
//	{
//		temp = R[i];
//		R[i] = R[0];
//		R[0] = temp;
//		charpte_8_Sift(R, 0, i - 1);
//	}
//}


void sift(int R[], int low, int high)
{
	int i = low;
	int j = 2 * i + 1;
	while (j <= high)
	{
		if (j < high && R[j + 1] > R[j])
		{
			++j;
		}
		if (R[i] < R[j])
		{
			int temp = R[i];
			R[i] = R[j];
			R[j] = temp;
			i = j;
			j = 2 * i + 1;
		}
		else
		{
			break;
		}
	}
}


//int R[8] = { 49, 38, 65, 97, 76, 13, 27, 49 };
void heapSort(int R[], int n)
{
	int siftIndex = n / 2 - 1;
	for (int i = siftIndex; i >= 0; --i)
	{
		sift(R, i, n - 1);
	}
	for (int i = n-1; i >= 1; --i)
	{
		int temp = R[0];
		R[0] = R[i];
		R[i] = temp;
		sift(R, 0, i - 1);
	}
}




int main()
{
	//SqList L;
	////L.length = 0;
	//for (int i = 0; i < 8; i++)
	//{
	//	L.data[i] = i + 1;
	//	L.length++;
	//}
	//L.data[0] = 0;
	//L.data[1] = 5;
	//L.data[2] = 5;
	//L.data[3] = 3;
	//L.data[4] = 5;
	//L.data[5] = 7;
	//L.data[6] = 5;
	//L.data[7] = 5;

	//char exp[10];
	//exp[0] = '1';
	//exp[1] = '2';
	//exp[2] = '3';
	//exp[3] = '4';
	//exp[4] = '*';
	//exp[5] = '+';
	//exp[6] = '+';
	//exp[7] = '5';
	//exp[8] = '/';
	//exp[9] = '\0';
	//L.length = 9;
	//insertElem(L, 5, findElem(L, 5));
	//chapter2_4_removeRange(L, 3, 5);
	//chapter2_5_partition(L);
	//for (int i = 0; i < L.length; i++)
	//{
	//	cout << L.data[i] << " " << endl;
	//}
	//int e;
	//deleteElem(L, 2, e);
	//cout << e << endl << endl;
	//int A[] = { 5, 7, 9, 11, 1, 6, 8, 12, 13 };
	//chapter2_simulation1(A,4,5);
	//for (int i = 0; i < 9; i++)
	//{
	//	cout << A[i] << " " << endl;
	//}
	//LNode* A = createList();
	//LNode* B = chapter2_9_split(A);
	//LNode* B = createList();
	//chapter2_simulation2(A, B);
	//cout<< chapter3_valueOfRPN(exp) << endl;
	//LNode* C = nullptr;
	//merge_reverse(A, B, C);
	//LNode* c = C->next;
	//LNode* a = A->next;
	//while (a != nullptr)
	//{
	//	cout << a->data << endl;
	//	a = a ->next;
	//}
	//LNode* b = B->next;
	//while (b != nullptr)
	//{
	//	cout << b->data << endl;
	//	b = b->next;
	//}
	//cout << findAndDelete(A, 2) << endl;
	//int A[] = { 5,2,8,9,7,3,4,6 };
	//cout << chapter2_10_findMin(A, 8, 1) << endl;
	//Stra* str = (Stra*)malloc(sizeof(Stra));
	//str->ch = (char*)malloc(sizeof(char));
	//str->ch[0] = 'a';
	//str->ch[1] = 'b';
	//str->ch[2] = 'c';
	//str->ch[3] = 'd';
	//str->ch[4] = 'e';
	//str->length = 5;
	//charpter_4_1_1_reverse(*str);
	//for (int i = 0; i < str->length; i++)
	//{
	//	cout << str->ch[i]<<' ';
	//}
	//int R[9] = { 49, 38, 65, 97, 76, 13, 27, 49, 88 };
	int R[5] = { 3,2,1,4,5 };
	//quickSort(R, 0,7);
	//charpte_8_SelectSort(R, 8);
	heapSort(R,5);
	printArray(R, 5);
	return 0;
}




