#include "Intern.h"

Intern::Intern()
{

}

Intern::~Intern()
{

}

Intern::Intern(const Intern &src)
{
	(void)src;
}

Intern &Intern::operator=(const Intern &src)
{
	(void)src;
	return (*this);
}

Form* Intern::makeForm(const std::string name, const std::string target) const
{
	const int numOfForms = 3;
	Form* ret = 0;
	std::string possibleForms[numOfForms] = {"shrubbery creation", "robotomy request", "presidential pardon"};
	int form = -1;
	for(int i = 0; i < numOfForms; i++)
	{
		if(possibleForms[i] == name)
		{
			form = i;
			break;
		}
	}
	switch(form)
	{
		case 0:
			ret = new ShrubberyCreationForm(target);
			break;
		case 1:
			ret = new RobotomyRequestForm(target);
			break;
		case 2:
			ret = new PresidentialPardonForm(target);
			break;
		default:
			ret = 0;
			std::cout << "Intern has not foud the form named " << name << std::endl;
			return 0;
	}
	std::cout << "Intern creates " << ret->getName() << std::endl;
	return ret;
}