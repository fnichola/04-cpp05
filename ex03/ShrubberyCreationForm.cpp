/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnichola <fnichola@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 05:03:45 by fnichola          #+#    #+#             */
/*   Updated: 2022/12/15 13:25:30 by fnichola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fstream>
#include "ShrubberyCreationForm.hpp"
#include "debugPrint.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(const std::string& target)
	: AForm("shrubbery creation form", 145, 137), m_target(target)
{
	debugPrint("ShrubberyCreationForm constructor called", BLU);
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& src)
	: AForm("shrubbery creation form", 145, 137), m_target(src.m_target)
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
	AForm::execute(executor);
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
