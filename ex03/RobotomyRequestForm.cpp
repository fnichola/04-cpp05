/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnichola <fnichola@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/14 02:55:19 by fnichola          #+#    #+#             */
/*   Updated: 2022/12/15 13:25:20 by fnichola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fstream>
#include "RobotomyRequestForm.hpp"
#include "debugPrint.hpp"

RobotomyRequestForm::RobotomyRequestForm(const std::string& target)
	: AForm("robotomy request form", 72, 45), m_target(target)
{
	debugPrint("RobotomyRequestForm constructor called", BLU);
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& src)
	: AForm("robotomy request form", 72, 45), m_target(src.m_target)
{
	debugPrint("RobotomyRequestForm copy constructor called", BLU);
}

RobotomyRequestForm::~RobotomyRequestForm()
{
	debugPrint("RobotomyRequestForm destructor called", BLU);
}

RobotomyRequestForm& RobotomyRequestForm::operator=(
	const RobotomyRequestForm& rhs)
{
	debugPrint("RobotomyRequestForm assignment operator called", BLU);
	(void)rhs;
	return *this;
}

void RobotomyRequestForm::execute(Bureaucrat const & executor) const
{
	debugPrint("RobotomyRequestForm execute called", BLU);
	AForm::execute(executor);

	// 50% random success/failure by checking if current unix time is even
	time_t now = time(0);
	std::cout << now << std::endl;;
	const bool isSuccessful = now % 2;
	if (isSuccessful)
	{
		std::cout << "Congratulations, " + m_target + ", you have been ";
		std::cout << "successffuly robotomized." << std::endl;
	}
	else
	{
		std::cout << "I'm sorry, " + m_target + ", you're robotomy has ";
		std::cout << "failed." << std::endl;
	}
}
