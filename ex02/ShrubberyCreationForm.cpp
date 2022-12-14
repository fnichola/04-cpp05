/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnichola <fnichola@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 05:03:45 by fnichola          #+#    #+#             */
/*   Updated: 2022/12/14 02:51:04 by fnichola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fstream>
#include "ShrubberyCreationForm.hpp"
#include "debugPrint.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(const std::string& target)
	: AForm("Shrubbery Creation Form", 145, 137), m_target(target)
{
	debugPrint("ShrubberyCreationForm constructor called", BLU);
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& src)
	: AForm("Shrubbery Creation Form", 145, 137), m_target(src.m_target)
{
	debugPrint("ShrubberyCreationForm copy constructor called", BLU);
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
	debugPrint("ShrubberyCreationForm destructor called", BLU);
}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(
	const ShrubberyCreationForm& rhs)
{
	debugPrint("ShrubberyCreationForm assignment operator called", BLU);
	(void)rhs;
	return *this;
}

void ShrubberyCreationForm::execute(Bureaucrat const & executor) const
{
	debugPrint("ShrubberyCreationForm execute called", BLU);
	try
	{
		AForm::execute(executor);
		std::cout << "EXECUTING!" << std::endl;
		std::ofstream outFile;
		outFile.exceptions(std::ofstream::failbit);
		const std::string filename = m_target + std::string("_shrubbery");
		outFile.open(filename.c_str());
		outFile << \
"                          # #### ####\n"
"                        ### \\/#|### |/####\n"
"                       ##\\/#/ \\||/##/_/##/_#\n"
"                     ###  \\/###|/ \\/ # ###\n"
"                   ##_\\_#\\_\\## | #/###_/_####\n"
"                  ## #### # \\ #| /  #### ##/##\n"
"                   __#_--###`  |{,###---###-~\n"
"                             \\ }{\n"
"                              }}{\n"
"                              }}{\n"
"                         ejm  {{}\n"
"                        , -=-~{ .-^- _\n"
"                              `}\n"
"                               {\n";
		outFile.close();
	}
	catch(const std::exception& e)
	{
		std::cerr << "Couldn't execute because " << e.what() << std::endl;
	}
}
