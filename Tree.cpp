#include"Tree.h"
BinaryTree::BinaryTree() :level(0)
{
	cin >> level;
	root = new TreeNode;
	for (int i = 1; i <= level; i++)
	{
		char a;
		TreeNode* p = root;
		int j = 1;
		while (root->right != nullptr)
		{
			root->lchild = new TreeNode;
			root->rchild = new TreeNode;
			cout <<i<<"." << j << ".";
			cin.clear();
			cin.ignore();
			cin.get(a);
			if (a == ' ')a = NULL;
			root->data = a;
			root->lchild->right = root->rchild;
			root->rchild->right = root->right->lchild;
			root = root->right;
			j++;
		}
			root->lchild = new TreeNode;
			root->rchild = new TreeNode;
			cout <<i<<"." << j << ".";
			cin.clear();
			cin.ignore();
			cin.get(a);
			if (a == ' ')a = NULL;
			root->data = a;
			root->lchild->right = root->rchild;
			//TreeNode* node = new TreeNode;
			//p->lchild = node;
			root = p->lchild;
	}
}
string BinaryTree::InOrderTraverse()
{
	TreeNode* p = root;
	Stack<char>d;
	Stack<TreeNode*>s;
	while (p||!d.isEmpty()) {
		if (p) {
			s.push(p);
			//d.push(p->data);
			p = p->lchild;
		}
		else {
			p = s.pop();
			s.push(p);
			p = p->rchild;
			//d.pop()
		}
	}
	string a;
	for (int i = 0; i < s.size(); i++)
	{
		a += s.pop()->data;
	}
	reverse(a.begin(), a.end());
	return a;
}