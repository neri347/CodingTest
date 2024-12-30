/// 이진 변환
/// https://school.programmers.co.kr/learn/courses/30/lessons/70129
/// 이진수로 변환할 때는 bitset를 이용하면 편리하다.
#include <string>
#include <vector>
#include <algorithm>
#include <bitset>

using namespace std;

vector<int> solution(string s) {
	vector<int> answer;
	int zeroRemoveCount = 0;
	int changeCount = 0;
	// s가 "1"이 될 때까지 이진변환
	while (s != "1")
	{
		// s에서 0 개수 세고 합산
		zeroRemoveCount += count(s.begin(), s.end(), '0');
		// s에서 1 개수 세기
		int oneCount = count(s.begin(), s.end(), '1');
		// 이진수로 변환 후 스트링으로 만들어 저장
		s = bitset<32>(oneCount).to_string();
		// 처음 1 나오는 곳의 앞부분은 모두 0일 것이기 때문에 잘라줌
		s = s.substr(s.find('1'));
		// 이진 변환 횟수 세기
		++changeCount;
	}
	answer.push_back(changeCount);
	answer.push_back(zeroRemoveCount);
	return answer;
}

int main()
{

	return 0;
}