#include "Bureaucrat.h"

Bureaucrat::Bureaucrat() : _name(""), _grade(1)
{

}

Bureaucrat::~Bureaucrat()
{

}

Bureaucrat::Bureaucrat(const std::string name, int grade) : _name(name)
{
	try
	{
		if(grade <= 0)
		{
			throw Bureaucrat::GradeTooHighException();
		}
		else if (grade > 150)
		{
			throw Bureaucrat::GradeTooLowException();
		}
		else
		{
			this->_grade = grade;
		}
	}
	catch(std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}
}

std::ostream& operator<<(std::ostream& os, const Bureaucrat& dt)
{
	os << dt.getName() << ", bureaucrat grade " << dt.getGrade();
	return os;
}

Bureaucrat::Bureaucrat(const Bureaucrat &src) : _name(src._name), _grade(src._grade)
{

}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &src)
{
	this->_grade = src._grade;
	return (*this);
}

const char *Bureaucrat::GradeTooHighException::what() const throw()
{
	return ("The grade is too high, values goes from 150 to 1 and the value you are trying to set will be under grade 1");
}

const char *Bureaucrat::GradeTooLowException::what() const throw()
{
	return ("The grade is too low, values goes from 150 to 1 and the value you are trying to set will be over grade 150");
}

const std::string Bureaucrat::getName() const
{
	return (this->_name);
}

int Bureaucrat::getGrade() const
{
	return (this->_grade);
}

void Bureaucrat::gradeUp()
{
	try
	{
		if(this->_grade - 1 <= 0)
		{
			throw Bureaucrat::GradeTooHighException();
		}
		else
		{
			this->_grade--;
		}
	}
	catch(Bureaucrat::GradeTooHighException e)
	{
		std::cout << e.what() << std::endl;
	}
}

void Bureaucrat::gradeDown()
{
	try
	{
		if(this->_grade + 1 > 150)
		{
			throw Bureaucrat::GradeTooLowException();
		}
		else
		{
			this->_grade++;
		}
	}
	catch(Bureaucrat::GradeTooLowException e)
	{
		std::cout << e.what() << std::endl;
	}
}

void Bureaucrat::signForm(Form &form)
{
	try
	{
		form.beSigned( *this);
		std::cout << this->_name << " signed " << form.getName() << std::endl;
	}
	catch(std::exception& e)
	{
		std::cout << this->_name << " couldn't sign " << form.getName() << " because " << e.what() << std::endl;
	}
}

void Bureaucrat::executeForm(const Form &form)
{
	try
	{
		form.execute(*this);
		std::cout << this->_name << " executed " << form.getName() << std::endl;
	}
	catch (std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}
}
