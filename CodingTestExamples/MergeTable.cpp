/// ǥ ����
/// https://school.programmers.co.kr/learn/courses/30/lessons/150366
/// ���Ͽ� ���ε� �˰����� ���� ǥ�� ����/���� �ϴ� ������� �����Ͽ���.
#include <iostream>
#include <string>
#include <vector>
#include <sstream>

using namespace std;

vector<vector<string>> table;
vector<vector<pair<int, int>>> parent;

void UpdateValue(int r, int c, const string& value)
{
	table[parent[r][c].first][parent[r][c].second] = value;
}

void UpdateValue(const string& origin, const string& value)
{
	for (int i = 1; i < 51; i++)
	{
		for (int j = 1; j < 51; j++)
		{
			if (table[parent[i][j].first][parent[i][j].second] == origin)
			{
				table[parent[i][j].first][parent[i][j].second] = value;
			}
		}
	}
}

void Merge(int r1, int c1, int r2, int c2)
{
	pair<int, int> p1 = parent[r1][c1];
	pair<int, int> p2 = parent[r2][c2];
	if (p1 == p2)
	{
		return;
	}
	// p1�� �θ�� ������ �ִٸ� ��� p2�� �ٲ��ش�.
	// �� �� �� �� ���� ���� ������ �ִٸ� ���յ� ���� �� ���� ������ �ȴ�.
	// �� �� ��� ���� ������ �ִٸ� ���յ� ���� r1,c1 ��ġ�� �� ���� ������ �ȴ�.
	if (table[parent[r1][c1].first][parent[r1][c1].second] == "")
	{
		for (int i = 1; i < 51; i++)
		{
			for (int j = 1; j < 51; j++)
			{
				if (parent[i][j] == p1)
				{
					parent[i][j] = p2;
				}
			}
		}
	}
	else
	{
		for (int i = 1; i < 51; i++)
		{
			for (int j = 1; j < 51; j++)
			{
				if (parent[i][j] == p2)
				{
					parent[i][j] = p1;
				}
			}
		}
	}
}

void Unmerge(int r, int c)
{
	string value = table[parent[r][c].first][parent[r][c].second];
	pair<int, int> p = parent[r][c];
	//r,c ��ġ�� ���� ���� �θ� ������ �ִ� ���� ���� ����
	for (int i = 1; i < 51; i++)
	{
		for (int j = 1; j < 51; j++)
		{
			if (parent[i][j] == p)
			{
				table[i][j] = "";
				parent[i][j] = { i, j };
			}
		}
	}
	table[r][c] = value;
}

string Print(int r, int c)
{
	string ret = table[parent[r][c].first][parent[r][c].second];
	return ret == "" ? "EMPTY" : ret;
}

vector<string> solution(vector<string> commands) {
	vector<string> answer;
	table.assign(51, vector<string>(51, ""));
	parent.assign(51, vector<pair<int, int>>(51));
	// ó�� �θ�� �ڱ��ڽ�
	for (int i = 1; i < 51; i++)
	{
		for (int j = 1; j < 51; j++)
		{
			parent[i][j] = { i, j };
		}
	}

	for (auto& command : commands)
	{
		vector<string> cmd;
		string temp = "";
		stringstream ss(command);
		while (getline(ss, temp, ' '))
		{
			cmd.push_back(temp);
		}

		if (cmd[0] == "UPDATE")
		{
			if (cmd.size() == 4)
			{
				UpdateValue(stoi(cmd[1]), stoi(cmd[2]), cmd[3]);
			}
			else
			{
				UpdateValue(cmd[1], cmd[2]);
			}
		}
		else if (cmd[0] == "MERGE")
		{
			Merge(stoi(cmd[1]), stoi(cmd[2]), stoi(cmd[3]), stoi(cmd[4]));
		}
		else if (cmd[0] == "UNMERGE")
		{
			Unmerge(stoi(cmd[1]), stoi(cmd[2]));
		}
		else // PRINT
		{
			answer.push_back(Print(stoi(cmd[1]), stoi(cmd[2])));
		}
	}
	return answer;
}

int main()
{

	return 0;
}