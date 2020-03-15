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

// �����ļ����ַ�����
void characterCount(string fileName) {
	int charNum = 0;		// ��¼�ַ���Ŀ
	char line[256];
	fstream file;				// �ļ���
	file.open(fileName, ios::in);			// ���ö�ȡ��ʽ���ļ�
	while (!file.eof())
	{
		file.getline(line, 256, '\n');	// �����ַ��ﵽ256�����������оͽ���
		int len = strlen(line);
		charNum += len;
		for (int i = 0; i < len; i++) {
			// �����������Ҫ��1����Ϊ��������˫�ֽ�
			if (line[i] < 0 && line[i + 1] < 0) {  
				charNum--;
				i++;
			}  
		}
	}
	file.close();
	cout << "���ļ�����" << charNum << "���ַ�" << endl;
};

// ���㵥�е��ʸ���
int getWordNumInLine(char* str) {
	int cnt = 0, i = 0;
	int len = strlen(str);
	for (i = 0; i < len - 1; i++) {
		// ��ĸ + ����ĸ ��Ϊһ�����ʵĽ���
		if (isalpha(str[i]) && (!isalpha(str[i + 1]))) cnt++;
	}
	// ��������ĸ���������
	if (isalpha(str[i])) cnt++;
	return cnt;
}

// �����ļ��ĵ��ʸ���
void wordCount(string fileName) {
	int wordNum = 0;		// ��¼������Ŀ
	char line[256];
	fstream file;				// �ļ���
	file.open(fileName, ios::in);			// ���ö�ȡ��ʽ���ļ�
	while (!file.eof())
	{
		file.getline(line, 256, '\n');	// �����ַ��ﵽ256�����������оͽ���
		cout << strlen(line) << endl;
		wordNum += getWordNumInLine(line);
	}
	file.close();
	cout << "���ļ�����" << wordNum << "������" << endl;
}

// �����ļ��ĵ�������
void lineCount(string fileName) {
	int lineNum = 0;		// ��¼����Ŀ
	char line[256];
	fstream file;				// �ļ���
	file.open(fileName, ios::in);			// ���ö�ȡ��ʽ���ļ�
	while (!file.eof())
	{
		file.getline(line, 256, '\n');	// �����ַ��ﵽ256�����������оͽ���
		lineNum++;
	}
	file.close();
	cout << "���ļ�����" << lineNum << "��" << endl;
}

// ȥ���ַ�����ͷβ�ո�
void trim(string& str) {
	str.erase(0, str.find_first_not_of("\r\t\n "));
	str.erase(str.find_last_not_of("\r\t\n ") + 1);
}

// �ж��ǲ�����ע����
// ����true��ʾ������ע����
bool judgeComment(string line, bool& isInComment) {
	regex pattern1("^[{}]?[\\s]*\\/\\/[^\\n]*");  // Ϊ"//"��"{...//"��"}...//"���м�ע��
	regex pattern2("^\\*\\/[//s]*[{}]?$");				// Ϊ"*/"��"*/...{"��"*/...}"
	regex pattern3("\\/\\*[^\\*^\\/]*\\*\\/");			// ƥ�� /**/
	regex pattern4("^[{}]?[//s]*\\/\\*[^\\n]*");	// ƥ�� "/*..."��"{/*..."��"}/*..."
	if (regex_match(line, pattern1)) return true;		// ���м�ע��
	if (regex_match(line, pattern2)) {
		isInComment = false;  // û��ע���ڵ��Ǹ�����ע��
		return true;					
	} 
	// �����ע���ڣ����Ҹ����Ҳ��� */ ��ע�ͽ�����
	if (isInComment && line.find("*/") == string::npos) {
		return true; 
	}
	string replaceStr = regex_replace(line, pattern3, "");  // ȥ���ַ��������� /**/��
	if (regex_match(replaceStr, pattern4)) {
		isInComment = true;
		return true;
	}
	return false;
}

// ���ظ����ӵ����ݣ������� / ���� / ע���У�
void complexLineCount(string fileName) {
	int codeLine = 0,						// ������
			emptyLine = 0,					// ����
			commentLine = 0;				// ע����
	bool isInComment = false;	  // �Ƿ���ע�Ϳ���
	bool isEmptyLine = false;		// �Ƿ��ǿ��еı�־
	regex isEmpty("^[{}]?$");   // �Ƿ��ǿ��е�����
	char line[256];
	fstream file;				// �ļ���
	file.open(fileName, ios::in);			// ���ö�ȡ��ʽ���ļ�
	while (!file.eof())
	{
		isEmptyLine = false;
		file.getline(line, 256, '\n');	// �����ַ��ﵽ256�����������оͽ���
		int len = strlen(line);
		string strLine(line);	   // ��char����תΪstring
		trim(strLine);
		// ע�Ϳ�����Ŀ��в�����
		if (!isInComment && regex_match(line, isEmpty)) {
			emptyLine++;	// ����ע�Ϳ����ҳ���С��1��Ϊ����
			isEmptyLine = true;
		} 
		// �����ע����
		if (judgeComment(strLine, isInComment)) {
			commentLine++;
		} else if(!isEmptyLine){
			// �������ע���ж��Ҳ��ǿ��У��Ǿ��Ǵ�����
			codeLine++;
		}
	}
	file.close();
	cout << "���ļ�����" << endl << codeLine << "������" << endl << emptyLine << "����" << endl << commentLine << "ע����" << endl;
}

