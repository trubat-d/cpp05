#include "RobotomyRequestForm.h"

RobotomyRequestForm::RobotomyRequestForm() : Form("Default robot form", 72, 45)
{
	this->_target = "default_target";
}

RobotomyRequestForm::RobotomyRequestForm(const std::string target) : Form("Main robot form", 72, 45)
{
	this->_target = target;
}

RobotomyRequestForm::~RobotomyRequestForm()
{

}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &src) : Form(src.getName(), src.getSign(), src.getExecute())
{
	this->_target = src._target;
}

RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm &src)
{
	this->_target = src._target;
	return (*this);
}

void RobotomyRequestForm::execute(const Bureaucrat &src) const
{
	if(!this->isSigned())
		throw Form::UnsignedFormException();
	else if (src.getGrade() > this->getExecute())
		throw Form::ExecuteGradException();
	int random = std::rand()%2;
	if(random)
	{
		std::cout << this->_target << " has been robotomised !" << std::endl;
	}
	else
	{
		std::cout << this->_target << " has not been robotomised, process failed !" << std::endl;
	}
}