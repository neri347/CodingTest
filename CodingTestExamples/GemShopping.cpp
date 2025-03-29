/// ���� ����
/// https://school.programmers.co.kr/learn/courses/30/lessons/67258
#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <unordered_set>

using namespace std;

vector<int> solution(vector<string> gems) {
    vector<int> answer = { 0, 0 };
    int sz = gems.size();
    int minLength = 99999999;

    // ���� ������ ���� ����
    unordered_set<string> s;
    for (int i = 0; i < sz; i++)
    {
        s.insert(gems[i]);
    }
    int kind = s.size();

    // �������͸� �̿��� Ž��
    // ���� ���� ���� ���ڶ�� right ��ġ�� ���� �߰�
    // ���� ���� ���� �ʿ��� ���� �� ��ŭ ������ left ��ġ�� ���� ����
    // �߰�, ���� �� ���� ���� ���� �ʿ��� ���� �� ��ŭ �ִٸ� ���� ª�� �������� üũ�ؼ� ���� ���� ����
    unordered_map<string, int> um;
    int left = 0;
    int right = 0;
    while (true)
    {
        if (um.size() >= kind)
        {
            um[gems[left]]--;
            if (um[gems[left]] == 0)
            {
                um.erase(gems[left]);
            }
            left++;
        }
        else if (right == sz)
        {
            break;
        }
        else
        {
            um[gems[right]]++;
            right++;
        }

        if (um.size() == kind)
        {
            if (right - left < minLength)
            {
                minLength = right - left;
                answer[0] = left + 1;
                answer[1] = right;
            }
        }
    }

    return answer;
}

int main()
{
	vector<string> gems = { "DIA", "RUBY", "RUBY", "DIA", "DIA", "EMERALD", "SAPPHIRE", "DIA" };
	solution(gems);
	return 0;
}