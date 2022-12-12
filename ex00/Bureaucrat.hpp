/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnichola <fnichola@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 05:16:30 by fnichola          #+#    #+#             */
/*   Updated: 2022/12/12 05:46:58 by fnichola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
# define ANIMAL_HPP

#include <string>
#include <iostream>

class Bureaucrat
{
public:
	Bureaucrat();
	Bureaucrat(const std::string& name, const int grade = 150);
	Bureaucrat(const Bureaucrat& src);
	~Bureaucrat();
	Bureaucrat& operator=(const Bureaucrat& rhs);

	std::string getName() const;
	int getGrade() const;
	void setGrade(const int newGrade);
	void incrementGrade();
	void decrementGrade();

	class GradeTooHighException : public std::exception
	{
	public:
		const char *what() const throw();
	};
	class GradeTooLowException : public std::exception
	{
	public:
		const char *what() const throw();
	};

private:
	const std::string m_name;
	int m_grade;
	static const int m_gradeMin = 150;
	static const int m_gradeMax = 1;
};

std::ostream& operator<<(std::ostream& os, const Bureaucrat& b);

#endif
