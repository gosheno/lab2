#include "Field.h"

Field::Field(){
	point(0, 0);
	settings = point();
	std::vector < std::vector<Cell>> f;
	this->map = f;
}

#include "Field_wiev.h"
void Field::updtx(Point2D pos) {
	if (pos.X() < map.size() && pos.Y() < map[0].size()) {
		Cell& cur = map[pos.X()][pos.Y()];
		cur.upd();
		if (!cur.get_wall())
			data_history.back()->upd_out();
		if (data_history.back()->get_wall() )
			if (!cur.get_wall())
				data_history.back()->upd_out();
		if (data_history.back() != &cur)
			data_history.push_back(&cur);
	}
}
Cell Field::get_map(int x, int y) {
	return map[x][y];
}
Field::~Field() {
	for (int x = 0; x < X(); x++){
		for (int y = 0; y < Y(); y++) {
			this->map[x][y].event_free();
		}
	}
	
}
void Field::field_free() {
	
	for (int x = 0; x < X(); x++) {
		this->map.push_back(std::vector<Cell>());
		for (int y = 0; y < Y(); y++) {
			this->map[x][y].event_free();
		}
	}
}

Field::Field(const Field& other)
{
	this->settings = other.settings;
	this->point(settings);
	Point2D set;
	set.point(other.settings);
	this->init_map(set);
	for (int x = 0; x < std::max(set.X(), X()); x++) {
		
		for (int y = 0; y < std::max(set.Y(), Y()); y++) {
			map[x][y] = other.map[x][y];
		}
	}
	this->data_history = other.data_history;
}

void Field::operator = (const Field& other) {
	
	Point2D set;
	set.point(other.settings);
	for (int x = 0; x < std::max(set.X(), X()); x++) {
		if (map.size() < other.map.size()) 
			map.push_back(std::vector<Cell>());
		else if (map.size() > other.map.size())
			map.pop_back();

		for (int y = 0; y < std::max(set.Y(), Y()); y++) {
			if (map[x].size() < other.map[x].size()) 
				this->map[x].push_back(Cell());

			else if (map[x].size() > other.map.size())
				map[x].pop_back();
			
			map[x][y] = other.map[x][y];
		}		
	}
	this->data_history.clear();
	for (auto el : other.data_history)
		this->data_history.push_back(el);
	
	this->settings = other.settings;
	this->point(settings);
}

Event* Field::update_field(Point2D pos)
{
	Cell& cur = map[pos.X()][pos.Y()];
	cur.upd();
	return cur.get_event();
}

void Field::init_map(std::vector<std::vector<Cell>> fi)
{
	this->map = fi;
	data_history.push_back(&fi[0][0]);
}
void Field::init_map(Point2D seti) {
	settings = seti;
	point(seti);
	for (int y = 0; y < seti.X(); y++) {
		this->map.push_back(std::vector<Cell>());
		for (int x = 0; x < seti.Y(); x++) {
			this->map[y].push_back(Cell(new Skin_player_esc, Point2D(y, x)));
		}
	}
	data_history.push_back(&map[0][0]);
}

void Field::set_event(Event* ev, Point2D pos) {
	this->map[pos.X()][pos.Y()].set_event(ev);
}

void Field::set_cell(Cell a)
{
	map[a.X()][a.Y()] = a;
}

std::vector<std::vector<Cell>> Field::get_map()
{
	return this->map;
}

Printer Field::get_log() {
	Printer res;
	res.add("\n<field>\nsettings: ");
	res.add(point().point_to_string());
	res.add("\n\ncurent ");
	res.add(data_history.back()->get_log());
	return res;
}