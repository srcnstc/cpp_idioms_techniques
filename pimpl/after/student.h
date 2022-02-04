#pragma once

#include <string>
#include <memory>

class Student {
public:
	Student(std::string name, std::string surname);
	Student(Student &&);
	Student& operator=(Student &&);
	~Student();
	void add_grade(int);
	void print()const;
private:
	class pimpl;
	std::unique_ptr<pimpl> p;
};
