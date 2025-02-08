#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>
#include <string>
using namespace std;

/// 1부터 n까지 서로 다른 정수 5개로 이루어진 코드 찾기 (n>=1, n<=30)
/// 코드는 오름차순 정렬
/// m 번 시도 후 찾아낼 수 있는 코드의 개수 출력
/// 한번 시도할 때 임의의 숫자 5개를 넣어본다.
/// ans[i] 는 i-1번째 시도로 넣어본 코드 중 맞는 숫자의 개수
/// q.size() = m 이다

int counts[31];
unordered_set<string> codes;

void BackTrack(int tryCount, int index, int chooseCount, const vector<vector<int>>& q, const vector<int>& ans)
{
	if (tryCount == q.size() + 1)
	{
		string temp = "";
		for (int i = 0; i < 31; i++)
		{
			if (counts[i] > 0)
			{
				temp += to_string(i);
			}
		}
		if (temp.size() == 5)
		{
			codes.insert(temp);
		}
		return;
	}

	for (int i = index; i < q[tryCount - 1].size(); i++)
	{
		counts[q[tryCount - 1][i]]++;
		if (chooseCount + 1 == ans[tryCount - 1])
		{
			BackTrack(tryCount + 1, 0, 0, q, ans);
		}
		else
		{
			BackTrack(tryCount, i + 1, chooseCount + 1, q, ans);
		}
		counts[q[tryCount - 1][i]]--;
	}
}

int solution(int n, vector<vector<int>> q, vector<int> ans)
{
	BackTrack(1, 0, 0, q, ans);	
	return codes.size();
}

int main()
{
	int n = 10;
	vector<vector<int>> q = { {1,2,3,4,5}, {3,6,7,8,9}, {1,6,7,8,9}, {1,3,5,7,9}, {2,4,6,8,10} };
	vector<int> ans = { 2,3,4,3,1 };
	cout << solution(n, q, ans);
	return 0;
}