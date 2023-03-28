#ifndef CPP_INTERN_H
#define CPP_INTERN_H

#include "Form.h"
#include "ShrubberyCreationForm.h"
#include "RobotomyRequestForm.h"
#include "PresidentialPardonForm.h"

class Intern
{
public:
	Intern();
	Intern(const Intern &src);
	~Intern();
	Intern &operator=(const Intern &src);
	Form*		makeForm(std::string const name, std::string const target) const;
};


#endif //CPP_INTERN_H
