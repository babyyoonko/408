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
	for (i = m; i <= m+n-1; i++)	// ������A[]�ĺ�n��Ԫ��������뵽ǰm��Ԫ�ص��ʵ���λ��
	{
		int temp = A[i];	//���������������ݴ������Ԫ��
		int j;
		for (j = i - 1; j >= 0; j--)
		{
			// Ѱ�Ҵ�����λ�ã�����A[j]С�ڻ���ڴ�����Ԫ��ʱ����ѭ������ʱjָ�������λ�õ�ǰһλ
			if (temp < A[j])	
			{
				// ��ǰԪ�ش��ڴ�����Ԫ�أ��������һλ
				A[j + 1] = A[j];
			}
			else
			{
				break;
			}
		}
		// ��������Ԫ�ط���j+1������ѭ������jָ�������λ�õ�ǰһλ��������j+1��
		A[j+1] = temp;
	}
}


// A: H-1-2-3-4-5-6-7-
// B: H-1-3-7-8-
void chapter2_simulation2(LNode* A,LNode *B)
{
	if (A == nullptr || A->next == nullptr)	//��AΪ�����������������
	{
		return;
	}
	LNode* p = A;	// ��������ʱָ��p��qָ��A��B��ͷ��㣬����ʱָ��ָ����������ǰһ�����Ϊ�˷������ɾ����B�г��ֵĽ��
	LNode* q = B;
	LNode* temp = nullptr;	// tempָ������ָ���ɾ����㣬�Ա�ɾ���ý�㲢�ͷſռ�
	while (p->next != nullptr && q->next != nullptr)	// ��p��qָ�����������һ����㣬�����������㷨����
	{
		if (q->next->data == p->next->data)	// ��������A�з��ֽ����B�г���ʱ��ɾ������A�иý�㣬ָ��q��ǰ�ƶ�
		{
			temp = p->next;
			p->next = p->next->next;
			free(temp);
			q = q->next;

		}
		else if (q->next->data > p->next->data)	// ��A��B��������ָ��p��qָ��Ľ��ֵ��С�����ĸ�ָ����ǰ�ƶ�
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
// �����ͷ���
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
// ��ͷ���
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
// ��ͷ���
// L-4-12-9-0-3-2-1-6
// ͷ�巨��
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
//����ͷ���
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
int match(char exp[], int n)
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



int main()
{
	SqList L;
	//L.length = 0;
	for (int i = 0; i < 8; i++)
	{
		L.data[i] = i + 1;
		L.length++;
	}
	L.data[0] = 0;
	L.data[1] = 5;
	L.data[2] = 5;
	L.data[3] = 3;
	L.data[4] = 5;
	L.data[5] = 7;
	L.data[6] = 5;
	L.data[7] = 5;
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
	cout<< findPrimaryElem (L.data,8)<<endl;
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
	return 0;
}