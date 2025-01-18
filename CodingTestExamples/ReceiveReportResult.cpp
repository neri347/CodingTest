/// 신고 결과 받기
/// https://school.programmers.co.kr/learn/courses/30/lessons/92334
#include <string>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <sstream>

using namespace std;

vector<int> solution(vector<string> id_list, vector<string> report, int k) {
	vector<int> answer(id_list.size(), 0);
	unordered_map<string, unordered_set<string>> reported; // 신고당한 유저, 신고한 유저들
	unordered_map<string, int> userNumber;
	for (int i = 0; i < id_list.size(); ++i)
	{
		userNumber[id_list[i]] = i;
	}

	for (string str : report)
	{
		stringstream ss(str);
		string userId, reportId;
		ss >> userId >> reportId;
		reported[reportId].insert(userId);
	}

	for (int i = 0; i < id_list.size(); ++i)
	{
		// k명 이상의 유저에게 신고받은 경우
		if (reported[id_list[i]].size() >= k)
		{
			for (const string& id : reported[id_list[i]])
			{
				int num = userNumber[id];
				answer[num]++;
			}
		}
	}

	return answer;
}

int main()
{
	vector<string> id_list = { "muzi", "frodo", "apeach", "neo" };
	vector<string> report = { "muzi frodo","apeach frodo","frodo neo","muzi neo","apeach muzi" };
	int k = 2;
	solution(id_list, report, k);
	return 0;
}