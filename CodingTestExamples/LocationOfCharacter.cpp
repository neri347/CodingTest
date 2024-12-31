/// 캐릭터의 좌표
/// https://school.programmers.co.kr/learn/courses/30/lessons/120861
#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<string> keyinput, vector<int> board) {
	//가로길이 = -board[0]/2 ~ board[0]/2
	//세로길이 = board[1]/2 ~ -board[1]/2
	int cx = 0, cy = 0;
	int minX = -board[0] / 2;
	int maxX = board[0] / 2;
	int minY = -board[1] / 2;
	int maxY = board[1] / 2;
	for (const auto& input : keyinput)
	{
		if (input == "left")
		{
			--cx;
			if (cx < minX)
			{
				cx = minX;
			}
		}
		else if (input == "right")
		{
			++cx;
			if (cx > maxX)
			{
				cx = maxX;
			}
		}
		else if (input == "up")
		{
			++cy;
			if (cy > maxY)
			{
				cy = maxY;
			}
		}
		else
		{
			--cy;
			if (cy < minY)
			{
				cy = minY;
			}
		}
	}
	return { cx, cy };
}

int main()
{

	return 0;
}