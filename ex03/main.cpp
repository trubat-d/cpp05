#include "Bureaucrat.h"
#include "Intern.h"

int main()
{
	Intern someRandomIntern;
	Form* form;
	Bureaucrat mike("mike", 1);
	form = someRandomIntern.makeForm("presidential pardon", "The world");

	mike.signForm(*form);
	mike.executeForm(*form);
}