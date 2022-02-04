#pragma once

#include <string>
#include <memory>

class PStudent {
public:
	PStudent(std::string name, std::string surname);
	PStudent(PStudent &&);
	PStudent& operator=(PStudent &&);
	~PStudent();
	void add_grade(int);
	void print()const;
private:
	class pimpl;
	std::unique_ptr<pimpl> p;
};