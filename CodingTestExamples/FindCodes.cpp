#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>
#include <string>
using namespace std;

/// 1���� n���� ���� �ٸ� ���� 5���� �̷���� �ڵ� ã�� (n>=1, n<=30)
/// �ڵ�� �������� ����
/// m �� �õ� �� ã�Ƴ� �� �ִ� �ڵ��� ���� ���
/// �ѹ� �õ��� �� ������ ���� 5���� �־��.
/// ans[i] �� i-1��° �õ��� �־ �ڵ� �� �´� ������ ����
/// q.size() = m �̴�

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