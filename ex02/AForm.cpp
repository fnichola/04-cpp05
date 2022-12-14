/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnichola <fnichola@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 03:08:59 by fnichola          #+#    #+#             */
/*   Updated: 2022/12/13 03:27:17 by fnichola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include "debugPrint.hpp"

AForm::AForm(const std::string& name, const int signGrade, const int executeGrade)
	: m_name(name), m_isSigned(false), m_signGrade(signGrade),
	  m_executeGrade(executeGrade)
{
	debugPrint("AForm constructor called", BLU);
	if (signGrade < m_gradeMax || executeGrade < m_gradeMax)
		throw AForm::GradeTooHighException();
	else if (signGrade > m_gradeMin || executeGrade > m_gradeMin)
		throw AForm::GradeTooLowException();
}

AForm::AForm(const AForm& src)
	: m_name(src.m_name), m_isSigned(src.m_isSigned), m_signGrade(src.m_signGrade),
	  m_executeGrade(src.m_executeGrade)
{
	debugPrint("AForm copy constructor called", BLU);
}

AForm::~AForm()
{
	debugPrint("AForm destructor called", BLU);
}

AForm& AForm::operator=(const AForm& rhs)
{
	debugPrint("AForm assignment operator called", BLU);
	(void)rhs;
	return *this;
}

void AForm::beSigned(const Bureaucrat& signer)
{
	debugPrint("AForm beSigned called", BLU);
	if (signer.getGrade() > m_signGrade)
		throw AForm::GradeTooLowException();
	else if (m_isSigned)
		throw AForm::AlreadySignedException();
	else
		m_isSigned = true;
}

void AForm::execute(Bureaucrat const & executor) const
{
	debugPrint("AForm execute called", BLU);
	if (!m_isSigned)
		throw AForm::NotSignedException();
	else if (executor.getGrade() > m_executeGrade)
		throw AForm::GradeTooLowException();
}

std::string AForm::getName() const { return m_name; }

bool AForm::isSigned() const { return m_isSigned; }

int AForm::getSignGrade() const { return m_signGrade; }

int AForm::getExecuteGrade() const { return m_executeGrade; }

std::ostream& operator<<(std::ostream& os, const AForm& f)
{
	os << "Name: " + f.getName() << std::endl;
	os << "Status: " << (f.isSigned() ? "signed" : "not signed") << std::endl;
	os << "Sign Grade: " << f.getSignGrade() << std::endl;
	os << "Execute Grade: " << f.getExecuteGrade() << std::endl;
	return os;
}

const char * AForm::GradeTooHighException::what() const throw()
{
	return "grade is too high";
}

const char * AForm::GradeTooLowException::what() const throw()
{
	return "grade is too low";
}

const char * AForm::AlreadySignedException::what() const throw()
{
	return "form is already signed";
}

const char * AForm::NotSignedException::what() const throw()
{
	return "form is not signed";
}
