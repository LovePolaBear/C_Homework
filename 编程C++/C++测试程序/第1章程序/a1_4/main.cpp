// �ļ�·����:a1_4\main.cpp
#include <iostream>					// ����Ԥ��������
#include <cstring>					// ��cstring���͡�string.h��ΪCͷ�ļ��������ַ�����غ���������
using namespace std;				// ʹ�������ռ�std

int main()
{
	char dest[100] = "destination", src[100] = "source";	// �������
	strcpy_s(dest, strlen(src) + 1, src);					// ����strcpy_s()����
	cout << "strcpy_s(dest, strlen(src) + 1, src):" << " dest:" << dest << endl;				// ��ʾ�����Ϣ
	strncpy_s(dest, strlen(src) + 1, src, 4);				// ����strncpy_s()����
	dest[4] = '\0';					// �ֶ�������ֹ��
	cout << "strncpy_s(dest, strlen(src) + 1, src, 4):" << " dest:" << dest << endl;			// ��ʾ�����Ϣ
	strcpy_s(dest, strlen("Hello ") + 1, "Hello ");			// ���ƴ�"Hello "
	strcpy_s(src, strlen("world") + 1, "world");			// ���ƴ�"world"
	strcat_s(dest, strlen(dest) + strlen(src) + 1, src);	// ����strcat_s()����
	cout << "strcat_s(dest, strlen(dest) + strlen(src) + 1, src):" << " dest:" << dest << endl;	// ��ʾ�����Ϣ

	return 0;						// ����ֵ0, ���ز���ϵͳ
}
