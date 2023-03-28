#ifndef CPP_FORM_H
#define CPP_FORM_H

#include "Bureaucrat.h"
#include <string>

class Bureaucrat;

class Form
{
public:
	Form(const std::string name, int sign, int execute);
	Form(const Form &src);
	virtual ~Form();
	Form &operator=(const Form &src);

	std::string const	getName(void) const;
	int					getSign(void) const;
	int					getExecute(void) const;


	bool				isSigned(void) const;

	void				beSigned(Bureaucrat& e);

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

	class UnsignedFormException : public std::exception
	{
	public:
		virtual const char* what() const throw();
	};

	class ExecuteGradException : public std::exception
	{
	public:
		virtual const char* what() const throw();
	};


	virtual void				execute(Bureaucrat const & src) const = 0;
private:
	Form();
	std::string const	_name;
	bool				_is_signed;
	int			const	_sign;
	int			const	_execute;
};

std::ostream& operator<<(std::ostream& os, const Form& dt);

#endif //CPP_FORM_H
