#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <fstream>
#include <string>
#include <Windows.h>
#include <list>
#include <sstream>

using namespace std;

void CreateBinary(string fname)
{
	ofstream fout(fname, ios::binary);
	if (!fout)
	{
		cerr << "Error opening file '" << fname << "'" << endl;
		return;
	}
	char ch;
	string s;
	int k = 0;
	do
	{
		cin.get();
		cin.sync();
		cout << "Enter line: "; getline(cin, s);
		for (unsigned i = 0; i < s.length(); i++) // ������� �������� �����
		{
			fout << s[i];
		}
		k++;
	} while (k < 0);
	cout << endl;
	fout.close();
}

void PrintBinary(string fname) // ��������� ����� �� �����
{
	ifstream fin(fname, ios::binary); // ������� ���� ��� ����������
	if (!fin)
	{
		cerr << "Error opening file '" << fname << "'" << endl;
		return;
	}
	string c; // ���������� ������
	while (!fin.eof())
	{
		fin >> c;
		cout << c + " "; // �������� ���� �� �����
	}
	cout << endl;
	fin.close();
}

void ProcessBinary(string fname, string gname) // ���������� �� ����� f
{ // � ���� g �������-�����
	ifstream f(fname, ios::binary); // ������� ���� ��� ����������
	ofstream g(gname, ios::binary); // ������� ���� ��� ������
	char s[100];
	char* w;
	int l,ah,bj;
	double k = 0;
	double b = 0;
	double a = 0;
	double h = 0;
	double j = 0;
	while (f.getline(s, sizeof(s))) // ���� ����� ��������� �����
	{
		w = strtok(s, " .,:;!?-'"); // ������� ����� ������������ ���

		while (w != NULL) // ���� ����� ���������� �����
		{
			l = atoi(w);
			if (l % 2 == 0) {
				a = a+l;
				h++;
			}
			if (l % 2 != 0) {
				b = b+l;
				j++;
			}
			k++; // �������� �������� ���
			w = strtok(NULL, " .,:;!?-'");
		}
	}
	f.close();
	ah = a / h;
	bj = b / j;
	//cout <<"serednie aref parnih ="<< ah;
	//cout <<"serednie aref ne parnih =" << bj;
	g << "serednie aref parnih = " <<ah << endl;
	g << "serednie aref ne parnih = " << bj << endl;
	g.close();
}

int main()
{
	string fname;

	cout << "Enter file name 1: "; cin >> fname;
	CreateBinary(fname); // ����� ����� ����� � ���������
	PrintBinary(fname); // ������ ���� ������� ����� �� �����

	string gname; // ��'� ������� �����
	cout << "Enter file name 2: "; cin >> gname;
	ProcessBinary(fname, gname);
	PrintBinary(gname);
	return 0;
}
