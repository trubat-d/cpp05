#ifndef CPP_PRESIDENTIALPARDONFORM_H
#define CPP_PRESIDENTIALPARDONFORM_H

#include "Form.h"

class PresidentialPardonForm : public Form
{
public:
	PresidentialPardonForm();
	PresidentialPardonForm(std::string target);
	PresidentialPardonForm(const PresidentialPardonForm &src);
	~PresidentialPardonForm();
	PresidentialPardonForm &operator=(const PresidentialPardonForm &src);
	virtual void					execute(Bureaucrat const & src) const;

private:
	std::string _target;
};


#endif //CPP_PRESIDENTIALPARDONFORM_H
