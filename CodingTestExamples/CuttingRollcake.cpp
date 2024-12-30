/// ������ũ �ڸ���
/// https://school.programmers.co.kr/learn/courses/30/lessons/132265
/// �ϳ��� �迭�� �ִ� ���� ���������ٴ� ����
/// ������ ��������ŭ �ٸ� �ʿ��� ���ٴ� ���̴�.
#include <string>
#include <vector>
#include <unordered_set>
#include <unordered_map>

using namespace std;

int solution(vector<int> topping) {
	int answer = 0;
	unordered_map<int, int> remainToppings; // type, count
	unordered_set<int> brotherToppings;

	for (int i = 0; i < topping.size(); ++i)
	{
		remainToppings[topping[i]]++;
	}

	for (int i = 0; i < topping.size(); ++i)
	{
		brotherToppings.insert(topping[i]);
		remainToppings[topping[i]]--;
		if (remainToppings[topping[i]] == 0)
		{
			remainToppings.erase(topping[i]);
		}
		if (remainToppings.size() == brotherToppings.size())
		{
			++answer;
		}
	}

	return answer;
}

int main()
{

	return 0;
}