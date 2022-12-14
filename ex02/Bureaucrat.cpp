/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnichola <fnichola@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 03:08:59 by fnichola          #+#    #+#             */
/*   Updated: 2022/12/13 05:54:55 by fnichola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"
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

void Bureaucrat::signForm(AForm& form)
{
	try
	{
		form.beSigned(*this);
		std::cout << m_name + " signed " + form.getName() << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cout << m_name + " couldn't sign " + form.getName() + " because ";
		std::cout << e.what() << std::endl;
	}
}

void Bureaucrat::executeForm(AForm const& form)
{
	form.execute(*this);
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
	if (newGrade < m_gradeMax)
		throw(Bureaucrat::GradeTooHighException());
	else if (newGrade > m_gradeMin)
		throw(Bureaucrat::GradeTooLowException());
	else
		m_grade = newGrade;
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
