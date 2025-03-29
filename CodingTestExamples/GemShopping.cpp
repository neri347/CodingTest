/// 보석 쇼핑
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

    // 보석 종류의 수를 센다
    unordered_set<string> s;
    for (int i = 0; i < sz; i++)
    {
        s.insert(gems[i]);
    }
    int kind = s.size();

    // 투포인터를 이용한 탐색
    // 보석 종류 수가 모자라면 right 위치의 보석 추가
    // 보석 종류 수가 필요한 가지 수 만큼 있으면 left 위치의 보석 제거
    // 추가, 제거 후 보석 종류 수가 필요한 가지 수 만큼 있다면 가장 짧은 구간인지 체크해서 저장 정보 갱신
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