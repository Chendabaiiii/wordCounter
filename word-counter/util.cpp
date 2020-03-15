#include <stdio.h>
#include "util.h"
#include <iostream>
#include <string>
#include <fstream>
#include <ctype.h>
#include <regex>
#include <io.h>
#include <vector>
using namespace std;

// 计算文件的字符个数
void characterCount(string fileName) {
	int charNum = 0;		// 记录字符数目
	char line[256];
	fstream file;				// 文件流
	file.open(fileName, ios::in);			// 采用读取方式打开文件
	while (!file.eof())
	{
		file.getline(line, 256, '\n');	// 该行字符达到256个或遇到换行就结束
		int len = strlen(line);
		charNum += len;
		for (int i = 0; i < len; i++) {
			// 如果是中文则要减1，因为中文算是双字节
			if (line[i] < 0 && line[i + 1] < 0) {  
				charNum--;
				i++;
			}  
		}
	}
	file.close();
	cout << "该文件共有" << charNum << "个字符" << endl;
};

// 计算单行单词个数
int getWordNumInLine(char* str) {
	int cnt = 0, i = 0;
	int len = strlen(str);
	for (i = 0; i < len - 1; i++) {
		// 字母 + 非字母 则为一个单词的结束
		if (isalpha(str[i]) && (!isalpha(str[i + 1]))) cnt++;
	}
	// 以两个字母结束的情况
	if (isalpha(str[i])) cnt++;
	return cnt;
}

// 计算文件的单词个数
void wordCount(string fileName) {
	int wordNum = 0;		// 记录单词数目
	char line[256];
	fstream file;				// 文件流
	file.open(fileName, ios::in);			// 采用读取方式打开文件
	while (!file.eof())
	{
		file.getline(line, 256, '\n');	// 该行字符达到256个或遇到换行就结束
		cout << strlen(line) << endl;
		wordNum += getWordNumInLine(line);
	}
	file.close();
	cout << "该文件共有" << wordNum << "个单词" << endl;
}

// 计算文件的单词行数
void lineCount(string fileName) {
	int lineNum = 0;		// 记录行数目
	char line[256];
	fstream file;				// 文件流
	file.open(fileName, ios::in);			// 采用读取方式打开文件
	while (!file.eof())
	{
		file.getline(line, 256, '\n');	// 该行字符达到256个或遇到换行就结束
		lineNum++;
	}
	file.close();
	cout << "该文件共有" << lineNum << "行" << endl;
}

// 去除字符串的头尾空格
void trim(string& str) {
	str.erase(0, str.find_first_not_of("\r\t\n "));
	str.erase(str.find_last_not_of("\r\t\n ") + 1);
}

// 判断是不是在注释内
// 返回true表示该行是注释行
bool judgeComment(string line, bool& isInComment) {
	regex pattern1("^[{}]?[\\s]*\\/\\/[^\\n]*");  // 为"//"、"{...//"、"}...//"的行级注释
	regex pattern2("^\\*\\/[//s]*[{}]?$");				// 为"*/"、"*/...{"、"*/...}"
	regex pattern3("\\/\\*[^\\*^\\/]*\\*\\/");			// 匹配 /**/
	regex pattern4("^[{}]?[//s]*\\/\\*[^\\n]*");	// 匹配 "/*..."、"{/*..."、"}/*..."
	if (regex_match(line, pattern1)) return true;		// 是行级注释
	if (regex_match(line, pattern2)) {
		isInComment = false;  // 没在注释内但是该行算注释
		return true;					
	} 
	// 如果在注释内，而且该行找不到 */ 块注释结束行
	if (isInComment && line.find("*/") == string::npos) {
		return true; 
	}
	string replaceStr = regex_replace(line, pattern3, "");  // 去除字符串中所有 /**/对
	if (regex_match(replaceStr, pattern4)) {
		isInComment = true;
		return true;
	}
	return false;
}

// 返回更复杂的数据（代码行 / 空行 / 注释行）
void complexLineCount(string fileName) {
	int codeLine = 0,						// 代码行
			emptyLine = 0,					// 空行
			commentLine = 0;				// 注释行
	bool isInComment = false;	  // 是否在注释块里
	bool isEmptyLine = false;		// 是否是空行的标志
	regex isEmpty("^[{}]?$");   // 是否是空行的正则
	char line[256];
	fstream file;				// 文件流
	file.open(fileName, ios::in);			// 采用读取方式打开文件
	while (!file.eof())
	{
		isEmptyLine = false;
		file.getline(line, 256, '\n');	// 该行字符达到256个或遇到换行就结束
		int len = strlen(line);
		string strLine(line);	   // 将char数组转为string
		trim(strLine);
		// 注释块里面的空行不包括
		if (!isInComment && regex_match(line, isEmpty)) {
			emptyLine++;	// 不在注释块内且长度小于1则为空行
			isEmptyLine = true;
		} 
		// 如果是注释行
		if (judgeComment(strLine, isInComment)) {
			commentLine++;
		} else if(!isEmptyLine){
			// 如果不是注释行而且不是空行，那就是代码行
			codeLine++;
		}
	}
	file.close();
	cout << "该文件共有" << endl << codeLine << "代码行" << endl << emptyLine << "空行" << endl << commentLine << "注释行" << endl;
}

