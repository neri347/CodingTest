#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>
#include <set>
#include <string>
using namespace std;

/// 1부터 n까지 서로 다른 정수 5개로 이루어진 코드 찾기 (n>=1, n<=30)
/// 코드는 오름차순 정렬
/// m 번 시도 후 찾아낼 수 있는 코드의 개수 출력
/// 한번 시도할 때 임의의 숫자 5개를 넣어본다.
/// ans[i] 는 i-1번째 시도로 넣어본 코드 중 맞는 숫자의 개수
/// q.size() = m 이다

vector<vector<int>> qVec;
vector<vector<bool>> isVisited;
vector<int> ansVec;
unordered_set<string> s;

void DFS(int tryCount, int pickCount, int curIndex, set<int> nomination, vector<int> code)
{
	if (tryCount == qVec.size())
	{
		if (nomination.size() >= 5)
		{
			sort(code.begin(), code.end());
			code.erase(unique(code.begin(), code.end()), code.end());
			for (int i = 0; i < code.size(); i++)
			{
				if (nomination.find(code[i]) == nomination.end())
				{
					return;
				}
			}

			string str = "";
			for (auto& e : nomination)
			{
				str += to_string(e);
			}
			s.insert(str);
		}
		return;
	}

	// ansVec[tryCount]만큼 선택
	// 선택되지 않은 숫자는 후보에서 제외

	if (pickCount == ansVec[tryCount])
	{
		for (int i = 0; i < qVec[tryCount].size(); i++)
		{
			if (!isVisited[tryCount][i])
			{
				nomination.erase(qVec[tryCount][i]);
			}
		}
		DFS(tryCount + 1, 0, 0, nomination, code);
		return;
	}

	for (int i = curIndex; i < qVec[tryCount].size(); i++)
	{
		int num = qVec[tryCount][i];
		code.push_back(num);
		isVisited[tryCount][i] = true;
		DFS(tryCount, pickCount + 1, i + 1, nomination, code);
		isVisited[tryCount][i] = false;
		code.pop_back();
	}
}

int solution(int n, vector<vector<int>> q, vector<int> ans) {
	qVec = q;
	ansVec = ans;
	isVisited.assign(q.size(), vector<bool>(q[0].size(), false));
	set<int> nomination;
	for (int i = 1; i <= n; i++)
	{
		nomination.insert(i);
	}

	DFS(0, 0, 0, nomination, {});
	for (auto& str : s)
	{
		cout << str << endl;
	}
	return s.size();
}

int main()
{
	/*int n = 10;
	vector<vector<int>> q = { {1,2,3,4,5}, {3,6,7,8,9}, {1,6,7,8,9}, {1,3,5,7,9}, {2,4,6,8,10} };
	vector<int> ans = { 2,3,4,3,1 };*/
	/*int n = 10;
	vector<vector<int>> q = { {1, 2, 3, 4, 5} ,{6, 7, 8, 9, 10},{3, 7, 8, 9, 10},{2, 5, 7, 9, 10},{3, 4, 5, 6, 7} };
	vector<int> ans = { 2,3,4,3,3 };*/
	/*int n = 15;
	vector<vector<int>> q = { {2, 3, 9, 12, 13} ,{1, 4, 6, 7, 9},{1, 2, 8, 10, 12},{6, 7, 11, 13, 15},{1, 4, 10, 11, 14} };
	vector<int> ans = { 2,1,3,0,1 };*/
	int n = 10;
	vector<vector<int>> q = { { 1,2,3,4,5 } };
	vector<int> ans = { 5 };
	cout << solution(n, q, ans);
	return 0;
}