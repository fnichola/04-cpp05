/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnichola <fnichola@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/14 02:55:19 by fnichola          #+#    #+#             */
/*   Updated: 2022/12/14 03:39:53 by fnichola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fstream>
#include "PresidentialPardonForm.hpp"
#include "debugPrint.hpp"

PresidentialPardonForm::PresidentialPardonForm(const std::string& target)
	: AForm("Presidental Pardon Form", 25, 5), m_target(target)
{
	debugPrint("PresidentialPardonForm constructor called", BLU);
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& src)
	: AForm("Presidential Pardon Form", 25, 5), m_target(src.m_target)
{
	debugPrint("PresidentialPardonForm copy constructor called", BLU);
}

PresidentialPardonForm::~PresidentialPardonForm()
{
	debugPrint("PresidentialPardonForm destructor called", BLU);
}

PresidentialPardonForm& PresidentialPardonForm::operator=(
	const PresidentialPardonForm& rhs)
{
	debugPrint("PresidentialPardonForm assignment operator called", BLU);
	(void)rhs;
	return *this;
}

void PresidentialPardonForm::execute(Bureaucrat const & executor) const
{
	debugPrint("PresidentialPardonForm execute called", BLU);
	AForm::execute(executor);
	std::cout << "Congratulations, " + m_target + ", you have been ";
	std::cout << "pardoned by Zaphod Beeblebrox." << std::endl;
}
