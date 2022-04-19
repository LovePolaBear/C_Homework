// �ļ�·����:a1_5\main.cpp
#include <iostream>					// ����Ԥ��������
#include <cstring>					// ��cstring���͡�string.h��ΪCͷ�ļ��������ַ�����غ���������
using namespace std;				// ʹ�������ռ�std

char *CStrCopy(char *target, const char *source)
// ���������C��񽫴�source���Ƶ���target
{
	char *tar = target;												// �ݴ�target
	while((*tar++ = *source++) != '\0');							// ����ַ����и��ƣ�ֱ��'\0'Ϊֹ
	return target;													// ����target
}

char *CStrCopy(char *target, const char *source, int n)
// ���������C��񽫴�source����n���ַ�����target 
{
	int len = (int)strlen(source) < n ? (int)strlen(source) : n;	// Ŀ�괮��
	for (int pos = 0; pos < len; pos++) target[pos] = source[pos];	// ����ַ����и���
	target[len] = '\0';												// ��������
	return target;													// ����target
}

char* CStrConcat(char *target, const char *source)
// ���������C��񽫴�source���ӵ���target�ĺ���
{
	char *tar = target + strlen(target);							// tarָ��target�Ľ�β��
	while((*tar++ = *source++) != '\0');							// ����ַ����ӵ�target�ĺ��棬ֱ��'\0'Ϊֹ
	return target;													// ����target
}

int main()
{
	char dest[100] = "destination", src[100] = "source";			// �������
	CStrCopy(dest, src);											// ����CStrCopy()����
	cout << "CStrCopy(dest, src):" << " dest:" << dest << endl;		// ��ʾ�����Ϣ
	CStrCopy(dest, src, 4);											// ����CStrCopy()����
//	dest[4] = '\0';													// �ֶ�������ֹ��, ��ʡ��
	cout << "CStrCopy(dest, src, 4):" << " dest:" << dest << endl;	// ��ʾ�����Ϣ
	CStrCopy(dest, "Hello ");										// ���ƴ�"Hello "
	CStrCopy(src, "world");											// ���ƴ�"world"
	CStrConcat(dest, src);											// ����CStrConcat()����
	cout << "CStrConcat(dest, src):" << " dest:" << dest << endl;	// ��ʾ�����Ϣ

	return 0;														// ����ֵ0, ���ز���ϵͳ
}