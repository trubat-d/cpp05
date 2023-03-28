#include "Bureaucrat.h"


int main()
{
	Bureaucrat mike("mike the looser", 150);
	std::cout << mike << std::endl;
	mike.gradeDown();
	mike.gradeUp();
	std::cout << mike << std::endl;

	Bureaucrat steve("steve the boss", 1);
	std::cout << steve << std::endl;
	steve.gradeUp();
	steve.gradeDown();
	std::cout << steve << std::endl;

	Bureaucrat coffeeMachine("the coffee machine", 1000);
	Bureaucrat paperClip("the paperclip", -1);
}