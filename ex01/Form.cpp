/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnichola <fnichola@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 03:08:59 by fnichola          #+#    #+#             */
/*   Updated: 2022/12/13 05:15:51 by fnichola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"
#include "Bureaucrat.hpp"
#include "debugPrint.hpp"

Form::Form(const std::string& name, const int signGrade, const int executeGrade)
	: m_name(name), m_isSigned(false), m_signGrade(signGrade),
	  m_executeGrade(executeGrade)
{
	debugPrint("Form constructor called", BLU);
	if (signGrade < m_gradeMax || executeGrade < m_gradeMax)
		throw Form::GradeTooHighException();
	else if (signGrade > m_gradeMin || executeGrade > m_gradeMin)
		throw Form::GradeTooLowException();
}

Form::Form(const Form& src)
	: m_name(src.m_name), m_isSigned(src.m_isSigned), m_signGrade(src.m_signGrade),
	  m_executeGrade(src.m_executeGrade)
{
	debugPrint("Form copy constructor called", BLU);
	*this = src;
}

Form::~Form()
{
	debugPrint("Form destructor called", BLU);
}

Form& Form::operator=(const Form& rhs)
{
	debugPrint("Form assignment operator called", BLU);
	(void)rhs;
	return *this;
}

void Form::beSigned(const Bureaucrat& signer)
{
	if (signer.getGrade() > m_signGrade)
		throw Form::GradeTooLowException();
	else if (m_isSigned)
		throw Form::AlreadySignedException();
	else
		m_isSigned = true;
}

std::string Form::getName() const { return m_name; }

bool Form::isSigned() const { return m_isSigned; }

int Form::getSignGrade() const { return m_signGrade; }

int Form::getExecuteGrade() const { return m_executeGrade; }

std::ostream& operator<<(std::ostream& os, const Form& f)
{
	os << "Name: " + f.getName() << std::endl;
	os << "Status: " << (f.isSigned() ? "signed" : "not signed") << std::endl;
	os << "Sign Grade: " << f.getSignGrade() << std::endl;
	os << "Execute Grade: " << f.getExecuteGrade() << std::endl;
	return os;
}

const char * Form::GradeTooHighException::what() const throw()
{
	return "grade is too high";
}

const char * Form::GradeTooLowException::what() const throw()
{
	return "grade is too low";
}

const char * Form::AlreadySignedException::what() const throw()
{
	return "form is already signed";
}
