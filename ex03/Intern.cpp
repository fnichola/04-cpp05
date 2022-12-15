/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnichola <fnichola@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 09:09:15 by fnichola          #+#    #+#             */
/*   Updated: 2022/12/15 13:26:08 by fnichola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "debugPrint.hpp"

Intern::Intern()
{
	debugPrint("Intern default constructor called", BLU);
}

Intern::Intern(const Intern& src)
{
	debugPrint("Intern copy constructor called", BLU);
	*this = src;
}

Intern::~Intern()
{
	debugPrint("Intern destructor called", BLU);
}

Intern& Intern::operator=(const Intern& rhs)
{
	debugPrint("Intern copy assignment operator called", BLU);
	(void)rhs;
	return *this;
}

AForm* Intern::makeForm(const std::string& name, const std::string& target)
{
	typedef struct {
		std::string name;
		AForm* (Intern::*func)(const std::string&);
	} functionTable;

	const functionTable ft[3] = {
		{"presidential pardon", &Intern::makePresidentialPardonForm},
		{"robotomy request", &Intern::makeRobotomyRequestForm},
		{"shrubbery creation", &Intern::makeShrubberyCreationForm}
	};

	for (size_t i = 0; i < (sizeof(ft) / sizeof(functionTable)); ++i)
	{
		if (ft[i].name == name)
			return (this->*ft[i].func)(target);
	}

	std::cout << "The form called " + name + " doesn't exist." << std::endl;
	return NULL;
}

AForm* Intern::makePresidentialPardonForm(const std::string& target)
{
	std::cout << "Intern creates presidential pardon form" << std::endl;
	return new PresidentialPardonForm(target);
}

AForm* Intern::makeRobotomyRequestForm(const std::string& target)
{
	std::cout << "Intern creates robotomy request form" << std::endl;
	return new RobotomyRequestForm(target);
}

AForm* Intern::makeShrubberyCreationForm(const std::string& target)
{
	std::cout << "Intern creates shrubbery creation form" << std::endl;
	return new ShrubberyCreationForm(target);
}
