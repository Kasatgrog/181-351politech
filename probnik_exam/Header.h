#pragma once
class myClass {

private:
	int length;
	char *p;
public:
	myClass();
	myClass(char *p1);
	myClass(std::string &sl);
	~myClass();

	void clear();
	void add(char *p1);
	void add(std::string sl);
	void insert(int pos, char *p1);
	void cut(int pos, int num);
	void input();
	void print();
};
