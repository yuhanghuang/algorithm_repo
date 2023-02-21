#include <iostream>

using namespace std;

class Solution {
public:
	void replaceSpace(char *str, int length) {
		// 0. 判断输入字符串字符有效
		if (str == NULL || length < 1)
			return;
		int i = 0;
		int inputStrLength = 0;		// 字符串长度
		int spaceCounts = 0;
		// 1. 计算字符串中空格数量
		while ('\0' != str[i])
		{
			++inputStrLength;
			if (' ' == str[i])
				++spaceCounts;
			++i;
		}
		// 2. 计算最终输出字符串的总长度
		int outputStrLength = inputStrLength + spaceCounts * 2;
		if (outputStrLength > length)
			return;
		// 3. 从后往前替换
		while (inputStrLength >= 0 && outputStrLength > inputStrLength)
		{
			if (str[inputStrLength] == ' ')	// 遇到空格，就替换
			{
				str[outputStrLength--] = '0';
				str[outputStrLength--] = '2';
				str[outputStrLength--] = '%';
			}
			else
			{
				str[outputStrLength--] = str[inputStrLength];
			}
			inputStrLength--;	// 向后移动
		}

	}
};

int main()
{
	const int length = 100;
	char inputStr[length] = "ABC CBA I LOVE YOU!";
	cout << "输入字符串:\t" << inputStr << endl;
	Solution sl;
	sl.replaceSpace(inputStr, length);
	cout << "输出字符串:\t" << inputStr << endl;
	system("pause");
	return 0;
}
