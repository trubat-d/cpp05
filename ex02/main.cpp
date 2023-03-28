#include "Bureaucrat.h"
#include "ShrubberyCreationForm.h"
#include "RobotomyRequestForm.h"
#include "PresidentialPardonForm.h"

int main()
{
	{
			try
			{
				ShrubberyCreationForm myform("test");
				Bureaucrat mike("mike", 130);
				mike.signForm(myform);
				mike.executeForm(myform);
			}
			catch (std::exception& e)
			{
				std::cout << e.what() << std::endl;
			}
	}
	{
		try
	 	{
			RobotomyRequestForm myform("test");
			Bureaucrat mike("mike", 1);
			mike.signForm(myform);
			for(int i = 0; i < 10; i++)
			{
				std::srand(std::time(0) * i);
				mike.executeForm(myform);
			}
			myform.execute(mike);
		}
		catch (std::exception& e)
		{
			std::cout << e.what() << std::endl;
		}
	}
	{
		try
		{
			PresidentialPardonForm sorrysorrymybad("trubat-d");
			Bureaucrat hradoux("hradoux", 1);
			hradoux.signForm(sorrysorrymybad);
			hradoux.executeForm(sorrysorrymybad);
		}
		catch (std::exception& e)
		{
			std::cout << e.what() << std::endl;
		}
	}
	{
		try
		{
			PresidentialPardonForm sorrysorrymybad("trubat-d");
			Bureaucrat hradoux("hradoux", 130);
			hradoux.signForm(sorrysorrymybad);
			hradoux.executeForm(sorrysorrymybad);
		}
		catch (std::exception& e)
		{
			std::cout << e.what() << std::endl;
		}
	}
}