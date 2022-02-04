#include "student.h"
#include <vector>
#include <iostream>

class Student::pimpl{
public:
	pimpl(std::string name, std::string surname) : 
	m_name{std::move(name)},
	m_surname{std::move(surname)} {}

	void add_grade(int grade)
	{
		m_grades.emplace_back(grade);
	}

	void print() const
	{
		std::cout << "name    : " << m_name << '\n'
			<< "surname : " << m_surname << '\n'
			<< "grades : ";
		for (auto grade : m_grades)
			std::cout << grade << ' ';

		std::cout << '\n';
	}
private:
	std::string m_name;
	std::string m_surname;
	std::vector<int> m_grades;
	// other private members & private functions
};

Student::Student(std::string name, std::string surname) :
	p{ std::make_unique<pimpl>(std::move(name), std::move(surname)) } {}

Student::Student(Student&&) = default;

Student& Student::operator=(Student&&) = default;

Student::~Student() = default;

void Student::add_grade(int grade)
{
	p->add_grade(grade);
}

void Student::print()const
{
	p->print();
}
