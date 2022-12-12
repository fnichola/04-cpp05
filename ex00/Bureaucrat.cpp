/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnichola <fnichola@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 03:08:59 by fnichola          #+#    #+#             */
/*   Updated: 2022/12/12 06:20:19 by fnichola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "debugPrint.hpp"

Bureaucrat::Bureaucrat(const std::string& name, const int grade)
	: m_name(name), m_grade(grade)
{
	debugPrint("Bureaucrat constructor called", BLU);
}

Bureaucrat::Bureaucrat(const Bureaucrat& src)
{
	debugPrint("Bureaucrat copy constructor called", BLU);
	*this = src;
}

Bureaucrat::~Bureaucrat()
{
	debugPrint("Bureaucrat destructor called", BLU);
}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& rhs)
{
	debugPrint("Bureaucrat copy assignment operator called", BLU);
	(void)rhs;
	return *this;
}

std::string Bureaucrat::getName() const
{
	return m_name;
}

int Bureaucrat::getGrade() const
{
	return m_grade;
}

void Bureaucrat::setGrade(const int newGrade)
{
	try
	{
		if (newGrade < m_gradeMax)
			throw(Bureaucrat::GradeTooHighException());
		else if (newGrade > m_gradeMin)
			throw(Bureaucrat::GradeTooLowException());
		else
			m_grade = newGrade;
	}
	catch(const std::exception& e)
	{
		std::cerr << "[Exception!] " << e.what() << '\n';
	}
}

void Bureaucrat::incrementGrade()
{
	setGrade(m_grade - 1);
}

void Bureaucrat::decrementGrade()
{
	setGrade(m_grade + 1);
}

std::ostream& operator<<(std::ostream& os, const Bureaucrat& b)
{
	os << b.getName() + ", bureaucrat grade " << b.getGrade() << ".";
	return os;
}

const char * Bureaucrat::GradeTooHighException::what() const throw()
{
	return "Grade too high";
}

const char * Bureaucrat::GradeTooLowException::what() const throw()
{
	return "Grade too low";
}
