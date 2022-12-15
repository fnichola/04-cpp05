/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnichola <fnichola@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/15 01:47:40 by fnichola          #+#    #+#             */
/*   Updated: 2022/12/15 13:26:58 by fnichola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Bureaucrat.hpp"
#include "Intern.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "debugPrint.hpp"

int main()
{
	Bureaucrat b1("Sam Lowry", 22);
	std::cout << b1 << std::endl;
	Intern theIntern;

	debugPrint("\n------------------------------------------\n");

	AForm* s = theIntern.makeForm("shrubbery creation", "MyHouse");
	if (s)
	{
		std::cout << *s;
		b1.signForm(*s);
		b1.executeForm(*s);
		delete s;
	}

	debugPrint("\n------------------------------------------\n");

	AForm* r = theIntern.makeForm("robotomy request", "Bender");
	if (r)
	{
		std::cout << *r;
		b1.signForm(*r);
		b1.executeForm(*r);
		delete r;
	}

	debugPrint("\n------------------------------------------\n");

	AForm* p = theIntern.makeForm("presidential pardon", "Taylor Swift");
	if (p)
	{
		std::cout << *p;
		b1.signForm(*p);
		b1.executeForm(*p);
		delete p;
	}

	debugPrint("\n------------------------------------------\n");

	AForm* f = theIntern.makeForm("27b-6", "Harry Buttle");
	if (f)
	{
		std::cout << *f;
		b1.signForm(*f);
		b1.executeForm(*f);
		delete f;
	}
	return 0;
}
