#pragma once

#include <string>
#include <vector>
// other include files

class Student {
public:
	Student(std::string name, std::string surname);
	void add_grade(int);
	void print()const;
	
private:
	std::string m_name;
	std::string m_surname;
	std::vector<int> m_grades;
	// other private members & private functions
};