/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnichola <fnichola@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/15 01:47:40 by fnichola          #+#    #+#             */
/*   Updated: 2022/12/13 05:15:31 by fnichola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Bureaucrat.hpp"
#include "Form.hpp"
#include "debugPrint.hpp"

int main()
{
	debugPrint("Bureaucrat b(\"Sam Lowry\");");
	Bureaucrat b("Sam Lowry");
	std::cout << b << std::endl;
	std::cout << std::endl;

	debugPrint("Form f(\"27b-6\", 42, 11);");
	Form f("27b-6", 42, 11);
	std::cout << f << std::endl;

	debugPrint("b.signForm(f);");
	b.signForm(f);
	std::cout << std::endl;

	debugPrint("b.setGrade(42);");
	b.setGrade(42);

	debugPrint("b.signForm(f);");
	b.signForm(f);

	debugPrint("b.signForm(f);");
	b.signForm(f);

	std::cout << std::endl;
	std::cout << f << std::endl;

	debugPrint("Form f2 = f;");
	Form f2 = f;
	std::cout << f2 << std::endl;
return 0;
}
