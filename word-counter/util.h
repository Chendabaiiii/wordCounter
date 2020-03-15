#include <stdio.h>
#include <string>
using namespace std;
int getWordNumInLine(char* str);				// 计算单行单词个数
void trim(string& str);								  // 去除字符串的头尾空格
void characterCount(string fileName);		// 计算字符个数
void wordCount(string fileName);				// 计算单词个数
void lineCount(string fileName);				// 记录行数	
void complexLineCount(string fileName); // 返回更复杂的数据（代码行 / 空行 / 注释行）
bool judgeComment(string line, bool& isInComment);  // 判断是不是在注释行内
