#include<iostream>
using namespace std;


struct SNode
{
	int data;
	SNode *next;
};

struct Stack
{
	SNode *top;
};

// khoi tao node stack
SNode* Create_SNode(int x);
// khoi tao stack rong
void Create_Stack(Stack &s);
// kiem tra stack rong khong?
bool isEmpty(Stack s);
// them 1 nut p vao dinh stack
void Push(Stack &s, SNode *p);
// lay ra va huy 1 nut o dinh stack
void Pop(Stack &s);
// lay ra xem gia tri nut o dinh stack
void Top(Stack s, int &x);
// doi co so
void DoiCoSo_10_Sang_X(Stack &s, int HeThapPhan, int x);


void main()
{
	Stack s;
	Create_Stack(s);
	int n, coso;
	do
	{
		cout << "\nHay nhap mot so he 10: ";
		cin >> n;
	} while (n <= 0);
	do
	{
		cout << "\nHay nhap co so muon doi: ";
		cin >> coso;
	} while (coso <= 0);
	DoiCoSo_10_Sang_X(s, n, coso);
	cout << "\nHe thap phan sang he " << coso << " la :";
	while (isEmpty(s) == false)
	{
		int data;
		Top(s, data);
		if (data < 10)
		{
			cout << data;
		}
		else
		{
			/*switch (data)
			{
			case 10:
				cout << 'A';
				break;
			case 11:
				cout << 'B';
				break;
			case 12:
				cout << 'C';
				break;
			case 13:
				cout << 'D';
				break;
			case 14:
				cout << 'E';
				break;
			case 15:
				cout << 'F';
				break;
			}*/
			cout << char(55 + data);
		}
		Pop(s);
	}
	cout << endl;
	system("pause");

}

// khoi tao node stack
SNode* Create_SNode(int x)
{
	SNode* p = new SNode;
	if (p == NULL)
		return NULL;
	p->data = x;
	p->next = NULL;
	return p;
}
// khoi tao stack rong
void Create_Stack(Stack &s)
{
	s.top = NULL;
}
// kiem tra stack rong khong?
bool isEmpty(Stack s)
{
	if (s.top == NULL)
		return true;
	return false;
}
// them 1 nut p vao dinh stack
void Push(Stack &s, SNode *p)
{
	if (p == NULL)
		return;
	if (s.top == NULL)
		s.top = p;
	else
	{
		p->next = s.top;
		s.top = p;
	}
}
// lay ra va huy 1 nut o dinh stack
void Pop(Stack &s)
{
	if (s.top != NULL)
	{
		SNode* p = s.top;
		s.top = s.top->next;
		p->next = NULL;
		delete p;
	}
}
// lay ra xem gia tri nut o dinh stack
void Top(Stack s, int &x)
{
	if (s.top != NULL)
	{
		x = s.top->data;
	}
}
// doi co so
void DoiCoSo_10_Sang_X(Stack &s, int HeThapPhan, int x)
{
	while (HeThapPhan != 0)
	{
		int du = HeThapPhan%x;
		HeThapPhan /= x;
		SNode* them = Create_SNode(du);
		Push(s, them);
	}
}