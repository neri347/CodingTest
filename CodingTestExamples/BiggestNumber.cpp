/// 가장 큰 수
/// https://school.programmers.co.kr/learn/courses/30/lessons/42746
/// 두 개의 스트링 비교
/// 스트링을 붙여서 (str1+str2), (str2+str1)
/// 더 큰 경우를 찾아냄
#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

bool Compare(const string& a, const string& b)
{
    // 두 숫자를 붙여보고 더 큰 경우를 반환
    return a + b > b + a;
}

string solution(vector<int> numbers) {
    string answer = "";
    vector<string> strs;
    for (const int& n : numbers)
    {
        strs.push_back(to_string(n));
    }
    sort(strs.begin(), strs.end(), Compare);

    for (const string& s : strs)
    {
        answer += s;
    }

    return answer[0] == '0' ? "0" : answer;
}

int main()
{

	return 0;
}