#include "Form.h"

Form::Form() : _name(""), _is_signed(false), _sign(1), _execute(1)
{

}

Form::Form(const std::string name, int sign, int execute) : _name(name), _is_signed(false), _sign(sign), _execute(execute)
{
		if(sign <= 0 || execute <= 0)
		{
			throw Form::GradeTooHighException();
		}
		else if (sign > 150 || execute > 150)
		{
			throw Form::GradeTooLowException();
		}
}

Form::~Form()
{

}

Form::Form(const Form &src) : _name(src._name), _is_signed(src._is_signed), _sign(src._sign), _execute(src._execute)
{

}

Form &Form::operator=(const Form &src)
{
	this->_is_signed = src._is_signed;
	return (*this);
}

void Form::beSigned(Bureaucrat &e)
{
	if(e.getGrade() > this->_sign)
		throw Bureaucrat::GradeTooLowException();
	else
	{
		if (this->_is_signed)
		{
			std::cout << "Form is already signed !" << std::endl;
			return ;
		}
		this->_is_signed = true;
	}
}

const char *Form::GradeTooHighException::what() const throw()
{
	return ("The grade is too high (0 or under) to do any action");
}

const char *Form::GradeTooLowException::what() const throw()
{
	return ("The grade is too low (over 150) to do any action");
}

const char *Form::UnsignedFormException::what() const throw()
{
	return ("The form isn't signed and cannot be executed");
}

const char *Form::ExecuteGradException::what() const throw()
{
	return ("The grad is too low to execute this form");
}


const std::string Form::getName() const
{
	return (this->_name);
}

bool Form::isSigned() const
{
	return this->_is_signed;
}

int Form::getSign() const
{
	return this->_sign;
}

int Form::getExecute() const
{
	return this->_execute;
}

std::ostream& operator<<(std::ostream& os, const Form& dt)
{
	os << std::boolalpha << dt.getName() << ", form is signed : " << dt.isSigned() << " , grade to sign : " << dt.getSign() << " , grade to execute " << dt.getExecute() << std::endl;
	return os;
}