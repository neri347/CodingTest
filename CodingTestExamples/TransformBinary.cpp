/// ���� ��ȯ
/// https://school.programmers.co.kr/learn/courses/30/lessons/70129
/// �������� ��ȯ�� ���� bitset�� �̿��ϸ� ���ϴ�.
#include <string>
#include <vector>
#include <algorithm>
#include <bitset>

using namespace std;

vector<int> solution(string s) {
	vector<int> answer;
	int zeroRemoveCount = 0;
	int changeCount = 0;
	// s�� "1"�� �� ������ ������ȯ
	while (s != "1")
	{
		// s���� 0 ���� ���� �ջ�
		zeroRemoveCount += count(s.begin(), s.end(), '0');
		// s���� 1 ���� ����
		int oneCount = count(s.begin(), s.end(), '1');
		// �������� ��ȯ �� ��Ʈ������ ����� ����
		s = bitset<32>(oneCount).to_string();
		// ó�� 1 ������ ���� �պκ��� ��� 0�� ���̱� ������ �߶���
		s = s.substr(s.find('1'));
		// ���� ��ȯ Ƚ�� ����
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