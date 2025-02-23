/// 표 병합
/// https://school.programmers.co.kr/learn/courses/30/lessons/150366
/// 유니온 파인드 알고리즘을 통해 표를 병합/해제 하는 방식으로 구현하였다.
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
	// p1을 부모로 가지고 있다면 모두 p2로 바꿔준다.
	// 두 셀 중 한 셀이 값을 가지고 있다면 병합된 셀은 그 값을 가지게 된다.
	// 두 셀 모두 값을 가지고 있다면 병합된 셀은 r1,c1 위치의 셀 값을 가지게 된다.
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
	//r,c 위치의 셀과 같은 부모를 가지고 있던 셀들 병합 해제
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
	// 처음 부모는 자기자신
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