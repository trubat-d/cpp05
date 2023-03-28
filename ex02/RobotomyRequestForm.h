#ifndef CPP_ROBOTOMYREQUESTFORM_H
#define CPP_ROBOTOMYREQUESTFORM_H

#include "Form.h"

class RobotomyRequestForm : public Form
{
public:
	RobotomyRequestForm();
	RobotomyRequestForm(std::string const target);
	RobotomyRequestForm(const RobotomyRequestForm &src);
	~RobotomyRequestForm();
	RobotomyRequestForm &operator=(const RobotomyRequestForm &src);

	virtual void				execute(Bureaucrat const & src) const;
private:
	std::string _target;
};


#endif //CPP_ROBOTOMYREQUESTFORM_H
