/// ���� ������������ ��ġ�ϱ�
/// https://school.programmers.co.kr/learn/courses/30/lessons/12933
/// �ſ� ū ���� ���ڿ��� �ٷ� �� �ִ��� ����غ� ��.
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

long long solution(long long n) {
    string str = to_string(n);
    sort(str.rbegin(), str.rend());
    return stoll(str);
}

int main()
{

	return 0;
}