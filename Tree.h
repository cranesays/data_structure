#pragma once
#include<iostream>
#include<cstdlib>
#include <string>
#include <algorithm>
using namespace std;

template<class T>class Stack
{
private:
	struct Node
	{
		T data;
		Node* next;
	};
	Node* head;
	Node* p;
	int length;

public:
	Stack(Node* head=nullptr,int length=0):head(head),length(length){}
	void push(T n)//入栈
	{
		Node* q = new Node;
		q->data = n;
		if (head == NULL)
		{
			q->next = head;
			head = q;
			p = q;
		}
		else
		{
			q->next = p;
			p = q;
		}
		length++;
	}

	T pop()//出栈并且将出栈的元素返回
	{
		if (length <= 0)
		{
			abort();
		}
		Node* q;
		T data;
		q = p;
		data = p->data;
		p = p->next;
		delete(q);
		length--;
		return data;
	}
	int size()//返回元素个数
	{
		return length;
	}
	T top()//返回栈顶元素
	{
		return p->data;
	}
	bool isEmpty()//判断栈是不是空的
	{
		if (length == 0)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
	void clear()//清空栈中的所有元素
	{
		while (length > 0)
		{
			pop();
		}
	}
};

class TreeNode 
{
public:
	char data;
	TreeNode* lchild;
	TreeNode* rchild;
	TreeNode* right;
public:
	TreeNode(char e=' ', TreeNode* p1 = nullptr, TreeNode* p2 = nullptr,TreeNode* p3=nullptr) :data(e), lchild(p1), rchild(p2),right(p3) {}
};
class BinaryTree 
{
public:
	TreeNode* root;
	int level;
public:
	BinaryTree();
	string InOrderTraverse();
};
