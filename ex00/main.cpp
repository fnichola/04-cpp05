/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnichola <fnichola@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/15 01:47:40 by fnichola          #+#    #+#             */
/*   Updated: 2022/12/12 06:18:25 by fnichola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Bureaucrat.hpp"
#include "debugPrint.hpp"

int main()
{
	debugPrint("Bureaucrat b(\"Bob\");");
	Bureaucrat b("Bob");
	std::cout << b << std::endl;

	debugPrint("b.setGrade(1);");
	b.setGrade(1);
	std::cout << b << std::endl;

	debugPrint("b.setGrade(42);");
	b.setGrade(42);
	std::cout << b << std::endl;

	debugPrint("b.incrementGrade();");
	b.incrementGrade();
	std::cout << b << std::endl;

	debugPrint("b.decrementGrade();");
	b.decrementGrade();
	std::cout << b << std::endl;

	debugPrint("b.setGrade(0);");
	b.setGrade(0);
	std::cout << b << std::endl;

	debugPrint("b.setGrade(151);");
	b.setGrade(151);
	std::cout << b << std::endl;

	debugPrint("b.setGrade(150);");
	b.setGrade(150);
	std::cout << b << std::endl;

	debugPrint("b.decrementGrade();");
	b.decrementGrade();
	std::cout << b << std::endl;

	debugPrint("b.setGrade(1);");
	b.setGrade(1);
	std::cout << b << std::endl;

	debugPrint("b.incrementGrade();");
	b.incrementGrade();
	std::cout << b << std::endl;
	return 0;
}
