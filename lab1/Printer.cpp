#include "Printer.h"


Printer::Printer() {
	std::vector<std::string> lst;
	list = lst;
}
void Printer::print() {
	for( auto el : list) {
		std::cout << el << std::endl;
	}
	list.clear();
}
void Printer::add(std::string a) {
	list.push_back(a);
}

void Printer::clean(){
	list.clear();
}

void Printer::add(Printer other)
{
	for (auto el : other.list) this->list.push_back(el);
}
