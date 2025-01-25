/// 가장 많이 받은 선물
/// https://school.programmers.co.kr/learn/courses/30/lessons/258712
#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <sstream>

using namespace std;

int solution(vector<string> friends, vector<string> gifts) {
	// 누가 누구에게 몇 개의 선물을 주었는지
	vector<vector<int>> records(friends.size(), vector<int>(friends.size(), 0));
	vector<int> giveCounts(friends.size(), 0); // 준 선물
	vector<int> takeCounts(friends.size(), 0); // 받은 선물
	vector<int> scores(friends.size(), 0); // 선물지수
	vector<int> total(friends.size(), 0); // 다음달에 받을 선물개수
	unordered_map<string, int> numbers;

	for (int i = 0; i < friends.size(); i++)
	{
		numbers[friends[i]] = i;
	}

	for (auto& str : gifts)
	{
		stringstream ss(str);
		string from, to;
		ss >> from >> to;
		records[numbers[from]][numbers[to]]++;
		giveCounts[numbers[from]]++;
		takeCounts[numbers[to]]++;
	}

	// 선물지수 계산
	for (int i = 0; i < scores.size(); i++)
	{
		scores[i] = giveCounts[i] - takeCounts[i];
	}

	for (int i = 0; i < friends.size(); i++)
	{
		for (int j = i + 1; j < friends.size(); j++)
		{
			// 내가 상대방에게 선물을 더 많이 주었다면 다음달에 내가 선물 받는다
			if (records[i][j] > records[j][i])
			{
				total[i]++;
			}
			else if (records[i][j] == records[j][i]) // 주고받은 수 같으면
			{
				// 선물지수가 더 큰 사람이 선물 받는다                    
				if (scores[i] > scores[j])
				{
					total[i]++;
				}
				else if (scores[j] > scores[i])
				{
					total[j]++;
				}
			}
			else // 상대방보다 적게 주었다면
			{
				total[j]++;
			}
		}
	}

	return *max_element(total.begin(), total.end());
}

int main()
{

	return 0;
}