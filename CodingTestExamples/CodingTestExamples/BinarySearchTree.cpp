#include <iostream>
#include <vector>
using namespace std;

class Node
{
public:
	Node(int k) : key(k), left(nullptr), right(nullptr) {}
	int key;
	Node* left;
	Node* right;
};

class BST
{
public:
	void Insert(int key)
	{
		root = InsertNode(root, key);
	}
	bool Search(int key)
	{
		return SearchNode(root, key);
	}

private:
	Node* InsertNode(Node* curNode, int key)
	{
		if (!curNode)
		{
			return new Node(key);
		}

		if (key < curNode->key)
		{
			curNode->left = InsertNode(curNode->left, key);
		}
		else
		{
			curNode->right = InsertNode(curNode->right, key);
		}

		return curNode;
	}

	bool SearchNode(Node* curNode, int key)
	{
		if (!curNode)
		{
			return false;
		}

		if (key == curNode->key)
		{
			return true;
		}
		else if (key < curNode->key)
		{
			return SearchNode(curNode->left, key);
		}
		else
		{
			return SearchNode(curNode->right, key);
		}
	}

private:
	Node* root = nullptr;
};

vector<bool> solution(vector<int> lst, vector<int> search_lst)
{
	vector<bool> answer;
	BST bst;
	for (auto e : lst)
	{
		bst.Insert(e);
	}
	for (auto e : search_lst)
	{
		answer.push_back(bst.Search(e));
	}
	return answer;
}

int main()
{
	//vector<int> lst = { 5,3,8,4,2,1,7,10 };
	vector<int> lst = { 1,3,5,7,9 };
	//vector<int> search_lst = { 1,2,5,6 };
	vector<int> search_lst = { 2,4,6,8,10 };
	const vector<bool>& answer = solution(lst, search_lst);
	for (auto b : answer)
	{
		if (b)
		{
			cout << "true ";
		}
		else
		{
			cout << "false ";
		}
	}
	return 0;
}