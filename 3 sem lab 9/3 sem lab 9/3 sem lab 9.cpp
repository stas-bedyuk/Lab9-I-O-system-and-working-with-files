// 3 sem lab 9.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "fstream"
#include <limits>
using namespace std;

class Turist
{
public:
	char name[30];
	int age;
	char country[20];
	Turist() {};
	Turist(const char* a, const char*b,int c) : age(c)
	{
		strcpy(name,a);
		strcpy(country, b);
	}
	~Turist() {};
	Turist(const Turist& s)    
	{                            
		strcpy(name, s.name);             
		strcpy(country, s.country);
		age = s.age;
	}
	friend void write(Turist a, Turist b, Turist c, Turist d, Turist e);
	friend void show();
	friend void write2(Turist a, Turist b, Turist c, Turist d, Turist e);
	friend void show2();
	friend void write3(Turist a, Turist b, Turist c, Turist d, Turist e);
	friend void show3();
};
ostream& operator<<(ostream& out, const Turist obj)

{
	out << obj.name <<" " << obj.country<<" " << dec<< obj.age << endl;
	return out;
}

istream& operator>>(istream& in, Turist& obj)

{
	in >> obj.name >> obj.country >>dec  >>obj.age;
	return in;
}
void write(Turist a, Turist b, Turist c, Turist d, Turist e)
{
	ofstream out("baboo");
	try
	{
		if (!out) throw 1;
	}
	catch (int)
	{
		cout << "\nFILE IS NOT OPEN!!!\n";
		return;
	}
	out << a << b << c << d << e << endl;
	out.close();
}
void show()
{
	Turist a;
	ifstream in("baboo");
	try
	{
		if (!in) throw 1;
	}
	catch (int)
	{
		cout << "\nFILE IS NOT OPEN!!!\n";
		exit(1);
	}
	while (in >> a)
	{
		cout.setf(ios::showpos);
		cout << a << endl;
	}
	in.close();
}
void reverse()
{
	Turist a;
	int i = 0;
	int y = 0;
	ifstream in1("baboo");
	try
	{
		if (!in1) throw 1;
	}
	catch (int)
	{
		cout << "\nFILE IS NOT OPEN!!!\n";
	}
	while (in1 >> a) i++;
	in1.close();
	ifstream in2("baboo");
	try
	{
		if (!in2) throw 1;
	}
	catch (int)
	{
		cout << "\nFILE IS NOT OPEN!!!\n";
	}
	while (i > 0)
	{
		in2.seekg(0, ios::beg);
		while (y < i)
		{
			in2 >> a;
			y++;
		}
		cout << a << endl;
		y = 0;
		i--;
	}
	in2.close();
}
void search()
{
	Turist a;
	char word[30];
	int i = 0;
	cout << endl << "Enter the name for searching: ";
	cin >> word;
	ifstream in1("baboo");
	try
	{
		if (!in1) throw 1;
	}
	catch (int)
	{
		cout << "\nFILE IS NOT OPEN!!!\n";
	}
	while (in1 >> a)
	{
		if (strcmp(a.name, word) == 0)
		{
			cout<<endl << a << endl;
			i = 1;
		}
	}
	if (i == 0) cout << "\nNot found!\n";
	in1.close();
}
void del()
{
	Turist a[6];
	char word[30];
	int i = 0;
	int j = 0;
	int flag = 0;
	cout << endl << "Enter the name for deleting: ";
	cin >> word;
	ifstream in("baboo");
	try
	{
		if (!in) throw 1;
	}
	catch (int)
	{
		cout << "\nFILE IS NOT OPEN!!!\n";
	}
	while (in >> a[i]) i++;
	in.close();
	ofstream out("baboo", ios::out | ios::trunc);
	try
	{
		if (!out) throw 1;
	}
	catch (int)
	{
		cout << "\nFILE IS NOT OPEN!!!\n";
	}
	while (j<i)
	{
		if (strcmp(word, a[j].name) !=0)
		{
			out << a[j] << endl;
			flag = 1;
	    }	
		j++;
	}
	if (flag == 0) cout << "\n\nNot found for delete!";
	out.close();
}
void write3(Turist a, Turist b, Turist c, Turist d, Turist e)
{
	ofstream out("baboo3.bin", ios::out | ios::binary | ios::trunc);
	try
	{
		if (!out) throw 1;
	}
	catch (int)
	{
		cout << "\nFILE IS NOT OPEN!!!\n";
	}
	out.write((char*)&a, sizeof(a));
	out.write((char*)&b, sizeof(b));
	out.write((char*)&c, sizeof(c));
	out.write((char*)&d, sizeof(d));
	out.write((char*)&e, sizeof(e));
	out.close();
}
void show3()
{
	Turist a;
	ifstream in("baboo3.bin", ios::in | ios::binary);
	try
	{
		if (!in) throw 1;
	}
	catch (int)
	{
		cout << "\nFILE IS NOT OPEN!!!\n";
	}
	while (!in.read((char*)&a, sizeof(a)).eof()) {
		
		cout << a << endl;
	}
	in.close();
}
void reverse3()
{
	Turist a;
	int i = 0;
	int y = 0;
	ifstream in1("baboo3.bin", ios::in | ios::binary);
	try
	{
		if (!in1) throw 1;
	}
	catch (int)
	{
		cout << "\nFILE IS NOT OPEN!!!\n";
	}
	while (!in1.read((char*)&a, sizeof(a)).eof()) i++;
	in1.close();
	ifstream in2("baboo3.bin", ios::in | ios::binary);
	try
	{
		if (!in2) throw 1;
	}
	catch (int)
	{
		cout << "\nFILE IS NOT OPEN!!!\n";
	}
	while (i > 0)
	{
		in2.seekg(0, ios::beg);
		while (y < i)
		{
			in2.read((char*)&a, sizeof(a));
			y++;
		}
		cout << a << endl;
		y = 0;
		i--;
	}
	in2.close();
}
void search3()
{
	Turist a;
	char word[30];
	int i = 0;
	cout << endl << "Enter the name for searching: ";
	cin >> word;
	ifstream in1("baboo3.bin", ios::in | ios::binary);
	try
	{
		if (!in1) throw 1;
	}
	catch (int)
	{
		cout << "\nFILE IS NOT OPEN!!!\n";
	}
	while (!in1.read((char*)&a, sizeof(a)).eof())
	{
		if (strcmp(a.name, word) == 0)
		{
			cout << endl << a << endl;
			i = 1;
		}
	}
	if (i == 0) cout << "\nNot found!\n";
	in1.close();
}
void del3()
{
	Turist a[6];
	char word[30];
	int i = 0;
	int j = 0;
	int flag = 0;
	cout << endl << "Enter the name for deleting: ";
	cin >> word;
	ifstream in("baboo3.bin" , ios::in | ios::binary);
	try
	{
		if (!in) throw 1;
	}
	catch (int)
	{
		cout << "\nFILE IS NOT OPEN!!!\n";
	}
	while (!in.read((char*)&a[i], sizeof(a[i])).eof()) i++;
	in.close();
	ofstream out("baboo3.bin", ios::out | ios::binary | ios::trunc);
	try
	{
		if (!out) throw 1;
	}
	catch (int)
	{
		cout << "\nFILE IS NOT OPEN!!!\n";
	}
	while (j < i)
	{
		if (strcmp(word, a[j].name) != 0)
		{
			out.write((char*)&a[j], sizeof(a[j]));
			flag = 1;
		}
		j++;
	}
	if (flag == 0) cout << "\n\nNot found for delete!";
	out.close();
}
void write2(Turist a, Turist b, Turist c, Turist d, Turist e)
{
	ofstream out("baboo2");
	try
	{
		if (!out) throw 1;
	}
	catch (int)
	{
		cout << "\nFILE IS NOT OPEN!!!\n";
	}
	out.write((char*)&a.name, sizeof(a.name));
	out.write((char*)&a.country, sizeof(a.country));
	out.write((char*)&a.age, sizeof(a.age));

	out.write((char*)&b.name, sizeof(b.name));
	out.write((char*)&b.country, sizeof(b.country));
	out.write((char*)&b.age, sizeof(b.age));

	out.write((char*)&c.name, sizeof(c.name));
	out.write((char*)&c.country, sizeof(c.country));
	out.write((char*)&c.age, sizeof(c.age));

	out.write((char*)&d.name, sizeof(d.name));
	out.write((char*)&d.country, sizeof(d.country));
	out.write((char*)&d.age, sizeof(d.age));

	out.write((char*)&e.name, sizeof(e.name));
	out.write((char*)&e.country, sizeof(e.country));
	out.write((char*)&e.age, sizeof(e.age));
}
void show2()
{
	Turist a;
	ifstream in("baboo2");
	try
	{
		if (!in) throw 1;
	}
	catch (int)
	{
		cout << "\nFILE IS NOT OPEN!!!\n";
	}
	while (!in.read((char*)&a.name, sizeof(a.name)).eof() && !in.read((char*)&a.country, sizeof(a.country)).eof() && !in.read((char*)&a.age, sizeof(a.age)).eof()) {

		cout << a << endl;
	}
	in.close();
}
void reverse2()
{
	Turist a;
	int i = 0;
	int y = 0;
	ifstream in1("baboo2");
	try
	{
		if (!in1) throw 1;
	}
	catch (int)
	{
		cout << "\nFILE IS NOT OPEN!!!\n";
	}
	while (!in1.read((char*)&a.name, sizeof(a.name)).eof() && !in1.read((char*)&a.country, sizeof(a.country)).eof() && !in1.read((char*)&a.age, sizeof(a.age)).eof()) i++;
	in1.close();
	ifstream in2("baboo2");
	try
	{
		if (!in2) throw 1;
	}
	catch (int)
	{
		cout << "\nFILE IS NOT OPEN!!!\n";
	}
	while (i > 0)
	{
		in2.seekg(0, ios::beg);
		while (y < i)
		{
			in2.read((char*)&a.name, sizeof(a.name));
			in2.read((char*)&a.country, sizeof(a.country));
			in2.read((char*)&a.age, sizeof(a.age));
			y++;
		}
		cout << a << endl;
		y = 0;
		i--;
	}
	in2.close();
}
void search2()
{
	Turist a;
	char word[30];
	int i = 0;
	cout << endl << "Enter the name for searching: ";
	cin >> word;
	ifstream in1("baboo2");
	try
	{
		if (!in1) throw 1;
	}
	catch (int)
	{
		cout << "\nFILE IS NOT OPEN!!!\n";
	}
	while (!in1.read((char*)&a.name, sizeof(a.name)).eof() && !in1.read((char*)&a.country, sizeof(a.country)).eof() && !in1.read((char*)&a.age, sizeof(a.age)).eof())
	{
		if (strcmp(a.name, word) == 0)
		{
			cout << endl << a << endl;
			i = 1;
		}
	}
	if (i == 0) cout << "\nNot found!\n";
	in1.close();
}
void del2()
{
	Turist a[6];
	char word[30];
	int i = 0;
	int j = 0;
	int flag = 0;
	cout << endl << "Enter the name for deleting: ";
	cin >> word;
	ifstream in("baboo2");
	try
	{
		if (!in) throw 1;
	}
	catch (int)
	{
		cout << "\nFILE IS NOT OPEN!!!\n";
	}
	while (!in.read((char*)&a[i].name, sizeof(a[i].name)).eof() && !in.read((char*)&a[i].country, sizeof(a[i].country)).eof() && !in.read((char*)&a[i].age, sizeof(a[i].age)).eof()) i++;
	in.close();
	ofstream out("baboo2");
	try
	{
		if (!out) throw 1;
	}
	catch (int)
	{
		cout << "\nFILE IS NOT OPEN!!!\n";
	}
	while (j < i)
	{
		if (strcmp(word, a[j].name) != 0)
		{
			out.write((char*)&a[j].name, sizeof(a[j].name));
			out.write((char*)&a[j].country, sizeof(a[j].country));
			out.write((char*)&a[j].age, sizeof(a[j].age));
			flag = 1;
		}
		j++;
	}
	if (flag == 0) cout << "\n\nNot found for delete!";
	out.close();
}
void sort()
{
	Turist a[6];
	Turist b;
	int x[6];
	int temp;
	int j;
	int i = 0;
	int y = 0;

	cout << "\n\nCHOOSE THE FIELD TO SORT: \n" << "1--NAME\n" << "2--COUNTRY\n" << "3--AGE\n";
	cin >>j;
	ifstream in("baboo");
	try
	{
		if (!in) throw 1;
	}
	catch (int)
	{
		cout << "\nFILE IS NOT OPEN!!!\n";
	}
	while (in >> a[i]) i++;
	in.close();
	ofstream out("baboo");
	try
	{
		if (!out) throw 1;
	}
	catch (int)
	{
		cout << "\nFILE IS NOT OPEN!!!\n";
	}
	switch (j)
	{
	case 1:
		for (int k = 0; k < 5; k++)
				x[k] = a[k].name[0];
		for (int k = 0; k < 4; k++)
		{
			for (int z = k + 1; z < 5; z++)
			{
				if (x[k]>x[z])
				{
					temp = x[z];
					x[z] = x[k];
					x[k] = temp;
				}
			}
		}
		for (int k = 0; k < 5; k++)
		{
			for (int z = 0; z < 5; z++)
			{
				if (a[z].name[0] == x[k])
					cout << a[z] << endl;
			}
		}
		break;
	case 2:
		for (int k = 0; k < 5; k++)
			x[k] = a[k].country[0];
		for (int k = 0; k < 4; k++)
		{
			for (int z = k + 1; z < 5; z++)
			{
				if (x[k] > x[z])
				{
					temp = x[z];
					x[z] = x[k];
					x[k] = temp;
				}
			}
		}
		for (int k = 0; k < 5; k++)
		{
			for (int z = 0; z < 5; z++)
			{
				if (a[z].country[0] == x[k])
					cout << a[z] << endl;
			}
		}
		break;
	case 3:
		
		for (int k = 0; k < 4; k++)
		{
			for (int z = k + 1; z < 5; z++)
			{
				if (a[k].age > a[z].age)
				{
					b = a[z];
					a[z] = a[k];
					a[k] = b;
				}
			}
		}
		for (int k = 0; k < 5; k++)
			out << a[k] << endl;	//cout << a[k] << endl;
	
		break;
	}
	out.close();
}
int main()
{
	Turist a("Maxim", "Belarus", 32);
	Turist b("Ivan", "Russia", 25);
	Turist c("Grisha", "Ukraine", 19);
	Turist d("Dasha", "Poland", 28);
	Turist e("Lera", "Germany", 34);
	int j;
	cout << "TEXT FILE IN TEXT MODE:\n\n";
	cout << "Do you like write information or only read???(1/0): ";
	cin>> j;
	if(j==1) write(a, b, c, d, e);
	show();
	cout<<"-------------------------\n\n";         //текстовый файл в текстовом режиме
	reverse();
	//search();
	//del();
	sort();
	cout << endl;
	show();

	cout << "\n\n\n\n";

	cout << "TEXT FILE IN BIN MODE:\n\n";
	cout << "Do you like write information or only read???(1/0): ";
	cin >> j;
	cout << "\n\n\n";
	if (j == 1) write2(a, b, c, d, e);
	show2();
	cout << "-------------------------\n\n";        //Текстовый файл в бинарном режиме
	reverse2();
	search2();
	del2();
	cout << endl;
	show2();

	cout << "\n\n\n\n";

	cout << "BIN FILE IN BIN MODE:\n\n";
	cout << "Do you like write information or only read???(1/0): ";
	cin >> j;
	cout << "\n\n\n";
	if (j == 1) write3(a, b, c, d, e);
	show3();
	cout << "-------------------------\n\n";        //Бинарный файл в бинарном режиме
	reverse3();
	search3();
	del3();
	cout << endl;
	show3();

	return 0;
}

