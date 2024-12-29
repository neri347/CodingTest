/// ���� ū ��
/// https://school.programmers.co.kr/learn/courses/30/lessons/42746
/// �� ���� ��Ʈ�� ��
/// ��Ʈ���� �ٿ��� (str1+str2), (str2+str1)
/// �� ū ��츦 ã�Ƴ�
#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

bool Compare(const string& a, const string& b)
{
    // �� ���ڸ� �ٿ����� �� ū ��츦 ��ȯ
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