/// 증가하는 수
/// https://www.notion.so/1a47be4a6cac8032b3fac7381a633ca4
#include <iostream>
#include <vector>
#include <string>
using namespace std;

int K;
int start;
string ret;

void DFS(int index, int maxCount, string& str)
{
	if (str.size() == maxCount)
	{
		start++;
		if (start == K)
		{
			ret = str;
			return;
		}
	}

	for (int i = index; i < 10; i++)
	{
		str += to_string(i);
		DFS(i + 1, maxCount, str);
		str.pop_back();
	}
}

string solution(int k)
{
	K = k;
	vector<int> dp(10, 0);
	vector<int> temp(10, 0);

	int sum = 0;
	// 한 자리수
	for (int i = 0; i < 10; i++)
	{
		dp[i] = 1;
		sum += dp[i];
		if (sum == K)
		{
			return to_string(i);
		}
	}

	// 두 자리수 이상
	for (int i = 2; i < 11; i++)
	{
		temp = dp;
		for (int j = 0; j < 10; j++)
		{
			dp[j] = 0;
		}

		for (int j = 0; j < 10; j++)
		{
			for (int m = j + 1; m < 10; m++)
			{
				dp[j] += temp[m];
				sum += temp[m];
				if (sum >= k)
				{
					start = sum - dp[j];
					string str = to_string(j);
					DFS(j + 1, i, str);
					return ret;
				}
			}
			// print
			//cout << dp[j] << " ";			
		}
		//cout << endl;
	}

	return "-1";
}

int main()
{
	int k;
	cin >> k;
	string answer = solution(k);
	cout << answer;

	return 0;
}