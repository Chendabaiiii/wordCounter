#include <stdio.h>
#include <string>
using namespace std;
int getWordNumInLine(char* str);				// ���㵥�е��ʸ���
void trim(string& str);								  // ȥ���ַ�����ͷβ�ո�
void characterCount(string fileName);		// �����ַ�����
void wordCount(string fileName);				// ���㵥�ʸ���
void lineCount(string fileName);				// ��¼����	
void complexLineCount(string fileName); // ���ظ����ӵ����ݣ������� / ���� / ע���У�
bool judgeComment(string line, bool& isInComment);  // �ж��ǲ�����ע������
