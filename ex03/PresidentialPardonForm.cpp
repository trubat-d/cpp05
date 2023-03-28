#include "PresidentialPardonForm.h"

PresidentialPardonForm::PresidentialPardonForm() : Form("default presidential form", 25, 5)
{
	this->_target = "default target";
}

PresidentialPardonForm::PresidentialPardonForm(std::string target) : Form("main presidential form", 25, 5)
{
	this->_target = target;
}

PresidentialPardonForm::~PresidentialPardonForm()
{

}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &src) : Form(src.getName(), src.getSign(), src.getExecute())
{
	this->_target = src._target;
}

PresidentialPardonForm &PresidentialPardonForm::operator=(const PresidentialPardonForm &src)
{
	this->_target = src._target;
	return (*this);
}

void PresidentialPardonForm::execute(const Bureaucrat &src) const
{
	if(!this->isSigned())
		throw Form::UnsignedFormException();
	else if (src.getGrade() > this->getExecute())
		throw Form::ExecuteGradException();
	std::cout << this->_target << " has been pardonned by PannJambonx" << std::endl;
}