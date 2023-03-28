#include "ShrubberyCreationForm.h"

ShrubberyCreationForm::ShrubberyCreationForm() : Form("Default Shrub", 145, 137)
{
	this->_filename = "default";
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string path) : Form("Shrubbery Form", 145, 137)
{
	this->_filename = path;
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{

}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &src) : Form(src.getName(), src.getSign(), src.getExecute())
{
	this->_filename = src._filename;
}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm &src)
{
	this->_filename = src._filename;
	return (*this);
}

void ShrubberyCreationForm::execute(const Bureaucrat &src) const
{
	if(!this->isSigned())
	{
		throw Form::UnsignedFormException();
	}
	else if (src.getGrade() > this->getExecute())
	{
		throw Form::ExecuteGradException();
	}
	std::ofstream file;
	file.open((this->_filename + "_shruberry"));
	std::string tab[20]= {"                     .o00o\n",
	"                   o000000oo\n",
	"                  00000000000o\n",
	"                 00000000000000\n",
	"              oooooo  00000000  o88o\n",
	"           ooOOOOOOOoo  ```''  888888\n",
	"         OOOOOOOOOOOO'.qQQQQq. `8888'\n",
	"        oOOOOOOOOOO'.QQQQQQQQQQ/.88'\n",
	"        OOOOOOOOOO'.QQQQQQQQQQ/ /q\n",
	"         OOOOOOOOO QQQQQQQQQQ/ /QQ\n",
	"           OOOOOOOOO `QQQQQQ/ /QQ'\n"
	"             OO:F_P:O `QQQ/  /Q'\n",
	"                \\\\. \\ |  // |\n",
	"                d\\ \\\\\\|_////\n",
	"                qP| \\\\ _' `|Ob\n",
	"                   \\  / \\  \\Op\n",
	"                   |  | O| |\n",
	"           _       /\\. \\_/ /\\\n",
	"            `---__/|_\\\\   //|  __\n",
	"                  `-'  `-'`-'-'"};

	for(int i = 0; i < 20; i++)
		file << tab[i];
	file.close();
	std::cout << "File has been created as : " << this->_filename + "_shruberry" << std::endl;
}