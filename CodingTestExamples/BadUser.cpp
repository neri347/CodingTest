/// �ҷ� �����
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
		// �ִ� �������� Ȯ��
		for (int i = 0; i < ids.size(); ++i)
		{
			if (set == ids[i]) // �ִ� �����̸� ���� �ʰ� ����
			{
				return;
			}
		}
		++result;
		ids.push_back(set);
		return;
	}

	// ���� �ε����� banned_id�� user_id�� �ִ��� Ȯ��
	string bannedId = banned_id[cur];
	for (int i = 0; i < user_id.size(); ++i)
	{
		if (!isChecked[i])
		{
			string userId = user_id[i];
			if (userId.size() == bannedId.size()) // ���̰� ���� ��츸 üũ
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
	// user_id�� banned_id�� ���ٸ�,
	// 1. ���̰� ����
	// 2. * ������ �κ��� ���ڿ� ������ ����
	unordered_set<string> set;
	FindId(0, set, user_id, banned_id);
	return result;
}

int main()
{
	cout << solution({ "frodo", "fradi", "crodo", "abc123", "frodoc" }, { "fr*d*", "abc1**" });

	return 0;
}