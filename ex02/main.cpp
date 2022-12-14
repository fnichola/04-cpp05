/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnichola <fnichola@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/15 01:47:40 by fnichola          #+#    #+#             */
/*   Updated: 2022/12/14 03:29:48 by fnichola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "debugPrint.hpp"

int main()
{
	debugPrint("Bureaucrat b1(\"Sam Lowry\", 22);");
	Bureaucrat b1("Sam Lowry", 146);
	std::cout << b1 << std::endl;

	debugPrint("Bureaucrat b2(\"Mr. Kurtzmann\", 22);");
	Bureaucrat b2("Mr. Kurtzmann", 142);
	std::cout << b2 << std::endl;

	debugPrint("Bureaucrat b3(\"Harry Tuttle\", 22);");
	Bureaucrat b3("Harry Tuttle", 1);
	std::cout << b3 << std::endl;
	std::cout << std::endl;

	debugPrint("------------------------------------------");

	debugPrint("ShrubberyCreationForm s(\"home\");");
	ShrubberyCreationForm s("home");
	std::cout << s << std::endl;

	debugPrint("b1.signForm(s);");
	b1.signForm(s);
	std::cout << std::endl;

	debugPrint("b1.executeForm(s);");
	b1.executeForm(s);
	std::cout << std::endl;

	debugPrint("b2.signForm(s);");
	b2.signForm(s);
	std::cout << std::endl;

	debugPrint("b2.executeForm(s);");
	b2.executeForm(s);
	std::cout << std::endl;

	debugPrint("b3.signForm(s);");
	b3.signForm(s);
	std::cout << std::endl;

	debugPrint("b3.executeForm(s);");
	b3.executeForm(s);
	std::cout << std::endl;

	debugPrint("------------------------------------------");

	debugPrint("RobotomyRequestForm r(\"Ford Prefect\");");
	RobotomyRequestForm r("Ford Prefect");
	std::cout << r << std::endl;

	debugPrint("b1.signForm(r);");
	b1.signForm(r);
	std::cout << std::endl;

	debugPrint("b1.executeForm(r);");
	b1.executeForm(r);
	std::cout << std::endl;

	debugPrint("b2.signForm(r);");
	b2.signForm(r);
	std::cout << std::endl;

	debugPrint("b2.executeForm(r);");
	b2.executeForm(r);
	std::cout << std::endl;

	debugPrint("b3.signForm(r);");
	b3.signForm(r);
	std::cout << std::endl;

	debugPrint("b3.executeForm(r);");
	b3.executeForm(r);
	std::cout << std::endl;

	debugPrint("------------------------------------------");

	debugPrint("PresidentialPardonForm p(\"Arthur Dent\");");
	PresidentialPardonForm p("Arthur Dent");
	std::cout << p << std::endl;

	debugPrint("b1.signForm(p);");
	b1.signForm(p);
	std::cout << std::endl;

	debugPrint("b1.executeForm(p);");
	b1.executeForm(p);
	std::cout << std::endl;

	debugPrint("b2.signForm(p);");
	b2.signForm(p);
	std::cout << std::endl;

	debugPrint("b2.executeForm(p);");
	b2.executeForm(p);
	std::cout << std::endl;

	debugPrint("b3.signForm(p);");
	b3.signForm(p);
	std::cout << std::endl;

	debugPrint("b3.executeForm(p);");
	b3.executeForm(p);
	std::cout << std::endl;

return 0;
}
