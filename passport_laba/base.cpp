#include "base.h"



bool base::check_name(string name)
{
	for (int i = 0; i < name.length(); i++)
	{
		char a = name[i];
		if ((a <= 90 and a >= 65) or (a >= 97 and a <= 122)) {

		}
		else {
			cout << "wrong!Repit" << endl;
			return false;
		}
	}
	return true;
}

bool base::check_passport(string passport)
{
	if (!(passport.length() == 10))
	{
		cout << "wrong!Repit" << endl;
		return false;
	}
	for (int i = 0; i < passport.length(); i++)
	{
		char a = passport[i];
		if ((a <= 57 and a >= 48)) {

		}
		else {
			cout << "wrong!Repit" << endl;
			return false;
		}
	}
	return true;
}

void base::add_file(string buff)
{
	outfile.open("data.txt", ios::out | ios::app);
	if (id != 0)
	{
		outfile << endl;
	}
	outfile << buff;
	outfile.close();
}

void base::find(string name)
{
	int p = 0;
	char buffer[1000];
	string a;
	infile.open(data);
	while (!infile.eof())
	{
		infile.getline(buffer, sizeof(buffer));
		a = string(buffer);
		if (a.find(name) != -1)
		{
			cout << a << endl;
			p = 1;
		}
	}
	if (p == 0)
	{
		cout << "not found";
	}
	infile.close();
}

void base::delet(int id_delet)
{
	outfile.open("buffer.txt");
	int del = 0;
	int id_time;
	infile.open(data);
	char last[1000];
	while (!infile.eof())
	{
		infile.getline(last, sizeof(last));
		int a = 4;
		string buf;
		while (last[a] >= '0' and last[a] <= '9')
		{
			buf += last[a];
			a += 1;
		}
		id_time = atoi(buf.c_str());
		buf = string(last);
		if (id_time == id_delet)
		{
			del = 1;
		}
		else
		{
			if (id_time != 0)
			{
				outfile << endl;
			}
			outfile << buf;
		}
		buf.clear();
	}
	infile.close();
	outfile.close();

	if (del == 0)
	{
		cout << "id not found,delete not sucsesfull";
	}
	else {
		infile.open("buffer.txt");
		outfile.open(data);
		copy();
		cout << "delete sucsesfull" << endl;
	}
}

void base::change()
{
	string type;
	int id_id;
	cout << "input id to change" << endl;
	cin >> id_id;
	cout << "input name of change" << endl;
	cin >> type;
	if (type == "name")
	{
		string temp;
		cin >> temp;
		outfile.open("buffer.txt");
		int del = 0;
		int id_time;
		infile.open(data);
		char last[1000];
		while (!infile.eof())
		{
			infile.getline(last, sizeof(last));
			int a = 4;
			string buf;
			while (last[a] >= '0' and last[a] <= '9')
			{
				buf += last[a];
				a += 1;
			}
			id_time = atoi(buf.c_str());
			buf = string(last);
			if (id_time == id_id)
			{
				int p = 0;
				int time;
				time = buf.find("name =");
				while (!(buf[time + 6 + p] == ' '))
				{
					buf[time + 6 + p] == temp[p];
					p += 1;
				}
				if (id_time != 0)
				{
					outfile << endl;
				}
				outfile << buf;
				del = 1;
			}
			else
			{
				if (id_time != 0)
				{
					outfile << endl;
				}
				outfile << buf;
			}
			buf.clear();
		}
		infile.close();
		outfile.close();
		if (del == 0)
		{
			cout << "id not found,change not successfully" << endl;
		}
		else
		{
			infile.open("buffer.txt");
			outfile.open(data);
			copy();
			cout << "id change successfully" << endl;
		}
	}
	else if (type == "second name")
	{

	}
	else if (type == "passport")
	{

	}
}

void base::start()
{
	string inpt;
	cin >> inpt;
	if (inpt == "exit")
	{
		rab = false;
	}
	else if (inpt == "add")
	{

		add();

	}
	else if (inpt == "help")
	{

	}
	else if (inpt == "change")
	{
		change();
	}
	else if (inpt == "show")
	{
		show();
	}
	else if (inpt == "find")
	{
		string name;
		cin >> name;
		find(name);

	}
	else if (inpt == "delete")
	{
		int id_1;
		cout << "input id deleting file";
		cin >> id_1;
		delet(id_1);
	}
}

void base::copy()
{
	char buffer[1000];          

	while (!infile.eof())
	{
		infile.getline(buffer, sizeof(buffer));
		outfile << buffer << endl;                  
	}

	infile.close();    
	outfile.close();
	remove("buffer.txt");
}

void base::add()
{
	string name;
	string second_name;
	string passport;
	cout << "input name -";
	cin >> name;
	if (!check_name(name))
	{
		add();
	}
	cout << "input second name -";
	cin >> second_name;
	if (!check_name(second_name))
	{
		do {
			cout << "input second name -";
			cin >> second_name;
		} while (!check_name(second_name));
	}
	cout << "input passport(10 namber) -";
	cin >> passport;
	if (!check_passport(passport))
	{
		do {
			cout << "input passport(10 namber) -";
			cin >> passport;
		} while (!check_passport(passport));
	}
	string buff = example(id, name, second_name, passport);
	add_file(buff);
	id += 1;
	cout << "successfully" << endl;
}

void base::show()
{
	char buffer[1000];
	infile.open(data);
	while (!infile.eof())
	{
		infile.getline(buffer, sizeof(buffer));
		cout << buffer << endl;
	}
	infile.close();
}

string base::example(int id, string name, string second_name, string passport)
{
	string exam = "id =" + to_string(id) + "| name =" + name + " | second_name =" + second_name + " | passport =" + passport + " | sha = |";
	return exam;
}

base::base()
{
	infile.open(data);
	if (!infile.is_open())
	{
		infile.close();
		outfile.open(data);
		outfile.close();
	}
	else
	{
		char last[1000];
		while (!infile.eof())
		{
			infile.getline(last, sizeof(last));
		}
		int a = 4;
		string buf;
		while (last[a] >= '0' and last[a] <= '9')
		{
			buf += last[a];
			a += 1;
		}
		if (!(buf == ""))
		{
			id = atoi(buf.c_str()) + 1;
		}
		infile.close();
	}


}
base::~base()
{
}