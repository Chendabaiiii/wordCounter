#include <stdio.h>
#include "util.h"
#include <iostream>
#include <string>
#include <fstream>
#include <ctype.h>
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

// ���ظ����ӵ����ݣ������� / ���� / ע���У�
void complexLineCount(string fileName) {
	int codeLine = 0,					// ������
			emptyLine = 0,				// ����
			commentLine = 0;			// ע����
	bool isInComment = false;		// �Ƿ���ע�Ϳ���
	char line[256];
	fstream file;				// �ļ���
	file.open(fileName, ios::in);			// ���ö�ȡ��ʽ���ļ�
	while (!file.eof())
	{
		file.getline(line, 256, '\n');	// �����ַ��ﵽ256�����������оͽ���
		int len = strlen(line);
		string strLine(line);	   // ��char����תΪstring
		trim(strLine);
		if (!isInComment && strLine.length() <= 1) emptyLine++;	// ����ע�Ϳ����ҳ���С��1��Ϊ����
	}
	file.close();
	cout << "���ļ�����" << codeLine << "������" << endl << emptyLine << "����" << endl << commentLine << "ע����" << endl;
}
