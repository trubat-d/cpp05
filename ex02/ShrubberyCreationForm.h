#ifndef CPP_SHRUBBERYCREATIONFORM_H
#define CPP_SHRUBBERYCREATIONFORM_H

#include "Form.h"
#include "Bureaucrat.h"
#include <iostream>
#include <fstream>

class ShrubberyCreationForm : public Form
{
public:
	ShrubberyCreationForm();
	ShrubberyCreationForm(const ShrubberyCreationForm &src);
	ShrubberyCreationForm(std::string path);
	virtual ~ShrubberyCreationForm();
	ShrubberyCreationForm &operator=(const ShrubberyCreationForm &src);
	virtual void					execute(Bureaucrat const & src) const;
private:
	std::string			_filename;
};


#endif //CPP_SHRUBBERYCREATIONFORM_H
