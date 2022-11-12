#include<iostream>
#include<string>
#include<vector>

class Printer {
private:
	std::vector<std::string> list;
public:
	Printer();
	void print();
	void add(std::string a);
	void add(Printer other);
	void clean();
	
};