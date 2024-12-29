/// 정수 내림차순으로 배치하기
/// https://school.programmers.co.kr/learn/courses/30/lessons/12933
/// 매우 큰 수는 문자열로 다룰 수 있는지 고려해볼 것.
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