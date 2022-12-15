/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnichola <fnichola@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 05:16:30 by fnichola          #+#    #+#             */
/*   Updated: 2022/12/13 03:25:27 by fnichola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AFORM_HPP
# define AFORM_HPP

#include <string>
#include <iostream>
class Bureaucrat;

class AForm
{
public:
	AForm();
	AForm(const std::string& name, const int signGrade, const int executeGrade);
	AForm(const AForm& src);
	virtual ~AForm() = 0;
	AForm& operator=(const AForm& rhs);

	std::string getName() const;
	bool isSigned() const;
	int getSignGrade() const;
	int getExecuteGrade() const;

	void beSigned(const Bureaucrat& signer);
	virtual void execute(Bureaucrat const & executor) const;

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

	class AlreadySignedException : public std::exception
	{
	public:
		const char *what() const throw();
	};

	class NotSignedException : public std::exception
	{
	public:
		const char *what() const throw();
	};

private:
	const std::string m_name;
	bool m_isSigned;
	const int m_signGrade;
	const int m_executeGrade;
	static const int m_gradeMin = 150;
	static const int m_gradeMax = 1;
};

std::ostream& operator<<(std::ostream& os, const AForm& f);

#endif
