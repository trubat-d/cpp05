#ifndef CPP_BUREAUCRAT_H
#define CPP_BUREAUCRAT_H

#include <string>
#include <iostream>
#include <exception>
#include <ostream>
#include "Form.h"

class Form;

class Bureaucrat
{
public:
	Bureaucrat(const Bureaucrat &src);
	Bureaucrat(const std::string name, int grade);
	virtual ~Bureaucrat();
	Bureaucrat &operator=(const Bureaucrat &src);

	void				signForm(Form& e);
	void				executeForm(Form const & form);

	const std::string	getName(void) const;
	int					getGrade(void) const;
	void				gradeUp(void);
	void				gradeDown(void);

	class GradeTooHighException : public std::exception
	{
		public:
			virtual const char* what() const throw();
	};
	class GradeTooLowException : public std::exception
	{
		public:
			virtual const char* what() const throw();
	};

private:
	Bureaucrat();
	std::string const	_name;
	int					_grade;
};

std::ostream& operator<<(std::ostream& os, const Bureaucrat& dt);

#endif //CPP_BUREAUCRAT_H
