/// 튜플
/// https://school.programmers.co.kr/learn/courses/30/lessons/64065
/// 계수정렬
#include <string>
#include <vector>
#include <algorithm>
#include <ctype.h>

using namespace std;

int counts[100001] = { 0, };

void CountSort(const string& s)
{
    string numStr = "";
    for (const char& ch : s)
    {
        if (isdigit(ch))
        {
            numStr += ch;
            continue;
        }
        else
        {
            if (!numStr.empty())
            {
                counts[stoi(numStr)]++;
                numStr = "";
            }
        }
    }
}

vector<int> solution(string s) {
    vector<int> answer;
    CountSort(s);

    vector<pair<int, int>> countAndNumPairs;
    for (int i = 0; i < 100000; ++i)
    {
        if (counts[i] > 0)
            countAndNumPairs.push_back({ counts[i], i });
    }
    // 오름차순 정렬
    sort(countAndNumPairs.rbegin(), countAndNumPairs.rend());

    for (int i = 0; i < countAndNumPairs.size(); ++i)
    {
        answer.push_back(countAndNumPairs[i].second);
    }
    return answer;
}

int main()
{

	return 0;
}