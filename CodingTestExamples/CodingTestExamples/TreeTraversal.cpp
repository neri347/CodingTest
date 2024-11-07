/// p.366 문제 28. 트리 순회
#include <iostream>
#include <vector>
#include <string>
using namespace std;

string Preorder(const vector<int>& nodes, int index)
{
	if (index < nodes.size())
	{
		string ret = ""; 
		ret += to_string(nodes[index]);
		ret += Preorder(nodes, index * 2 + 1);
		ret += Preorder(nodes, index * 2 + 2);
		return ret;
	}
	return "";
}

string Inorder(const vector<int>& nodes, int index)
{
	if (index < nodes.size())
	{
		string ret = "";
		ret += Inorder(nodes, index * 2 + 1);
		ret += to_string(nodes[index]);
		ret += Inorder(nodes, index * 2 + 2);
		return ret;
	}
	return "";
}

string Postorder(const vector<int>& nodes, int index)
{
	if (index < nodes.size())
	{
		string ret = "";
		ret += Postorder(nodes, index * 2 + 1);
		ret += Postorder(nodes, index * 2 + 2);
		ret += to_string(nodes[index]);
		return ret;
	}
	return "";
}

vector<string> solution(vector<int> nodes)
{
	vector<string> answer;
	answer.push_back(Preorder(nodes, 0));
	answer.push_back(Inorder(nodes, 0));
	answer.push_back(Postorder(nodes, 0));
	return answer;
}

int main()
{
	vector<int> nodes = { 1, 2, 3, 4, 5, 6, 7 };
	const vector<string>& answer = solution(nodes);
	for (auto& s : answer)
	{
		for (auto& c : s)
		{
			cout << c << " ";
		}
		cout << endl;
	}
	return 0;
}