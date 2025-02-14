/// 비밀 코드 해독
/// https://school.programmers.co.kr/learn/courses/30/lessons/388352
#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
using namespace std;

vector<vector<int>> combinations;
vector<int> nominations;

void DFS(int index, int count, vector<int>& code)
{
	if (count == 5)
	{
		combinations.push_back(code);
		return;
	}

	for (int i = index; i < nominations.size(); i++)
	{
		code.push_back(nominations[i]);
		DFS(i + 1, count + 1, code);
		code.pop_back();
	}
}

int solution(int n, vector<vector<int>> q, vector<int> ans) {
	int answer = 0;
	set<int> nomiSet;
	for (int i = 1; i <= n; i++)
	{
		nomiSet.insert(i);
	}
	// ans[i] == 0이면 q[i]의 요소들은 코드에 무조건 포함 안된다
	for (int i = 0; i < ans.size(); i++)
	{
		if (ans[i] == 0)
		{
			for (int j = 0; j < q[i].size(); j++)
			{
				nomiSet.erase(q[i][j]);
			}
		}
	}

	for (int n : nomiSet)
	{
		nominations.push_back(n);
	}

	vector<int> code;
	DFS(0, 0, code);

	for (int i = 0; i < combinations.size(); i++)
	{
		bool flag = true;
		for (int j = 0; j < q.size(); j++)
		{			
			int count = 0;
			// combinations[i]에 q[j] 벡터에 있는 원소가 ans[j]개 있으면 후보가 맞음
			for (int k = 0; k < combinations[i].size(); k++)
			{
				if (find(combinations[i].begin(), combinations[i].end(), q[j][k]) != combinations[i].end())
				{
					++count;
				}				
			}
			if (count != ans[j])
			{
				flag = false;
				break;
			}
		}

		if (flag)
		{
			++answer;
		}
	}
	return answer;
}

int main()
{
	/*int n = 10;
	vector<vector<int>> q = { {1,2,3,4,5}, {3,6,7,8,9}, {1,6,7,8,9}, {1,3,5,7,9}, {2,4,6,8,10} };
	vector<int> ans = { 2,3,4,3,1 };*/
	int n = 10;
	vector<vector<int>> q = { {1, 2, 3, 4, 5} ,{6, 7, 8, 9, 10},{3, 7, 8, 9, 10},{2, 5, 7, 9, 10},{3, 4, 5, 6, 7} };
	vector<int> ans = { 2,3,4,3,3 };
	/*int n = 15;
	vector<vector<int>> q = { {2, 3, 9, 12, 13} ,{1, 4, 6, 7, 9},{1, 2, 8, 10, 12},{6, 7, 11, 13, 15},{1, 4, 10, 11, 14} };
	vector<int> ans = { 2,1,3,0,1 };*/
	cout << solution(n, q, ans);
	return 0;
}