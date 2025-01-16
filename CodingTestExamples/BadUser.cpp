/// 불량 사용자
/// https://school.programmers.co.kr/learn/courses/30/lessons/64064
#include <string>
#include <vector>
#include <unordered_set>
#include <iostream>

using namespace std;

int result;
int start;
bool isChecked[8];
vector<unordered_set<string>> ids;

void FindId(int cur, unordered_set<string>& set, const vector<string>& user_id, const vector<string>& banned_id)
{
	if (cur == banned_id.size())
	{
		// 있는 조합인지 확인
		for (int i = 0; i < ids.size(); ++i)
		{
			if (set == ids[i]) // 있는 조합이면 세지 않고 종료
			{
				return;
			}
		}
		++result;
		ids.push_back(set);
		return;
	}

	// 현재 인덱스의 banned_id가 user_id에 있는지 확인
	string bannedId = banned_id[cur];
	for (int i = 0; i < user_id.size(); ++i)
	{
		if (!isChecked[i])
		{
			string userId = user_id[i];
			if (userId.size() == bannedId.size()) // 길이가 같을 경우만 체크
			{
				bool isSame = true;
				for (int j = 0; j < userId.size(); ++j)
				{
					if (bannedId[j] == '*')
						continue;
					if (userId[j] != bannedId[j])
					{
						isSame = false;
						break;
					}
				}
				if (isSame)
				{
					isChecked[i] = true;
					set.insert(userId);
					FindId(cur + 1, set, user_id, banned_id);
					isChecked[i] = false;
					set.erase(userId);
				}
			}
		}
	}
}

int solution(vector<string> user_id, vector<string> banned_id) {
	// user_id와 banned_id가 같다면,
	// 1. 길이가 같다
	// 2. * 제외한 부분의 문자와 순서가 같다
	unordered_set<string> set;
	FindId(0, set, user_id, banned_id);
	return result;
}

int main()
{
	cout << solution({ "frodo", "fradi", "crodo", "abc123", "frodoc" }, { "fr*d*", "abc1**" });

	return 0;
}