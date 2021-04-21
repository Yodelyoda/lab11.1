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
		for (unsigned i = 0; i < s.length(); i++) // скануємо введений рядок
		{
			fout << s[i];
		}
		k++;
	} while (k < 0);
	cout << endl;
	fout.close();
}

void PrintBinary(string fname) // виведення файлу на екран
{
	ifstream fin(fname, ios::binary); // відкрили файл для зчитування
	if (!fin)
	{
		cerr << "Error opening file '" << fname << "'" << endl;
		return;
	}
	string c; // прочитаний символ
	while (!fin.eof())
	{
		fin >> c;
		cout << c + " "; // виводимо його на екран
	}
	cout << endl;
	fin.close();
}

void ProcessBinary(string fname, string gname) // переписати із файлу f
{ // у файл g символи-цифри
	ifstream f(fname, ios::binary); // відкрили файл для зчитування
	ofstream g(gname, ios::binary); // відкрили файл для запису
	char s[100];
	char* w;
	int l,ah,bj;
	double k = 0;
	double b = 0;
	double a = 0;
	double h = 0;
	double j = 0;
	while (f.getline(s, sizeof(s))) // поки можна прочитати рядок
	{
		w = strtok(s, " .,:;!?-'"); // початок циклу виокремлення слів

		while (w != NULL) // поки можна виокремити слово
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
			k++; // збільшуємо лічильник слів
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
	CreateBinary(fname); // ввели рядки файлу з клавіатури
	PrintBinary(fname); // вивели вміст першого файлу на екран

	string gname; // ім'я другого файлу
	cout << "Enter file name 2: "; cin >> gname;
	ProcessBinary(fname, gname);
	PrintBinary(gname);
	return 0;
}
