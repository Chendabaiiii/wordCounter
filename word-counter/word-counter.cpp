#include <stdio.h>
#include <iostream>
#include <string>
#include <fstream>
#include "util.h"   // 自己的函数集
#include <locale>
using namespace std;
// 主函数
// argc 是命令参数数目
// argv 接收命令参数字符串， argv[0] 默认为exe文件路径
int main(int argc, char** argv)
{
	if (argc < 3) {
		cout << "参数有误，请输入正确的参数" << endl;
		return 0;
	}
	// 需要外传入两个参数，一个是模式，一个是文件名
	string mode = argv[1];
	string fileName = argv[2];
	setlocale(LC_ALL, "chs");
	switch (mode[1]) {
		// 字符计数
		case 'c': {
			characterCount(fileName);		
			break;
		}
		// 单词计数
		case 'w': {
			wordCount(fileName);				
			break;
		}
		// 行数
		case 'l': {
			lineCount(fileName);				
			break;
		}
		// 返回更复杂的数据（代码行 / 空行 / 注释行）
		case 'a': {	
			complexLineCount(fileName);
			break;
		}
		default: {
			break;
		}
	}
	return 0;
}

// 运行程序: Ctrl + F5 或调试 >“开始执行(不调试)”菜单
// 调试程序: F5 或调试 >“开始调试”菜单

// 入门使用技巧: 
//   1. 使用解决方案资源管理器窗口添加/管理文件
//   2. 使用团队资源管理器窗口连接到源代码管理
//   3. 使用输出窗口查看生成输出和其他消息
//   4. 使用错误列表窗口查看错误
//   5. 转到“项目”>“添加新项”以创建新的代码文件，或转到“项目”>“添加现有项”以将现有代码文件添加到项目
//   6. 将来，若要再次打开此项目，请转到“文件”>“打开”>“项目”并选择 .sln 文件
