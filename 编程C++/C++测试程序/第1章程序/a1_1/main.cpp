// �ļ�·����:a1_1\main.cpp
#include <iostream>					// ����Ԥ��������
#include <cstring>					// ��cstring���͡�string.h��ΪCͷ�ļ��������ַ�����غ���������
using namespace std;				// ʹ�������ռ�std 

int main()
{
	char dest[100] = "destination", src[100] = "source";	// �������
	strcpy(dest, src);				// ����strcpy()����
	cout << "strcpy(dest, src):" << " dest:" << dest << endl;	// ��ʾ�����Ϣ
	strncpy(dest, src, 4);			// ����strncpy()����
	dest[4] = '\0';					// �ֶ�������ֹ��
	cout << "strncpy(dest, src, 4):" << " dest:" << dest << endl;// ��ʾ�����Ϣ
	strcpy(dest, "Hello ");			// ���ƴ�"Hello "
	strcpy(src, "world");			// ���ƴ�"world"
	strcat(dest, src);				// ����strcat()����
	cout << "strcat(dest, src):" << " dest:" << dest << endl;	// ��ʾ�����Ϣ

	return 0;						// ����ֵ0, ���ز���ϵͳ
}
