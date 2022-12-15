/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnichola <fnichola@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 09:09:07 by fnichola          #+#    #+#             */
/*   Updated: 2022/12/15 13:05:21 by fnichola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_HPP
# define INTERN_HPP

#include <string>
#include <iostream>
class AForm;

class Intern
{
public:
	Intern();
	Intern(const Intern& src);
	~Intern();
	Intern& operator=(const Intern& rhs);

	AForm* makeForm(const std::string& name, const std::string& target);

private:
	AForm* makePresidentialPardonForm(const std::string& target);
	AForm* makeRobotomyRequestForm(const std::string& target);
	AForm* makeShrubberyCreationForm(const std::string& target);
};

std::ostream& operator<<(std::ostream& os, const Intern& b);

#endif
