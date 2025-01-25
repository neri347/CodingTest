/// ���� ���� ���� ����
/// https://school.programmers.co.kr/learn/courses/30/lessons/258712
#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <sstream>

using namespace std;

int solution(vector<string> friends, vector<string> gifts) {
	// ���� �������� �� ���� ������ �־�����
	vector<vector<int>> records(friends.size(), vector<int>(friends.size(), 0));
	vector<int> giveCounts(friends.size(), 0); // �� ����
	vector<int> takeCounts(friends.size(), 0); // ���� ����
	vector<int> scores(friends.size(), 0); // ��������
	vector<int> total(friends.size(), 0); // �����޿� ���� ��������
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

	// �������� ���
	for (int i = 0; i < scores.size(); i++)
	{
		scores[i] = giveCounts[i] - takeCounts[i];
	}

	for (int i = 0; i < friends.size(); i++)
	{
		for (int j = i + 1; j < friends.size(); j++)
		{
			// ���� ���濡�� ������ �� ���� �־��ٸ� �����޿� ���� ���� �޴´�
			if (records[i][j] > records[j][i])
			{
				total[i]++;
			}
			else if (records[i][j] == records[j][i]) // �ְ���� �� ������
			{
				// ���������� �� ū ����� ���� �޴´�                    
				if (scores[i] > scores[j])
				{
					total[i]++;
				}
				else if (scores[j] > scores[i])
				{
					total[j]++;
				}
			}
			else // ���溸�� ���� �־��ٸ�
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