/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpicchio <tpicchio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/28 10:53:55 by tpicchio          #+#    #+#             */
/*   Updated: 2024/08/28 11:38:55 by tpicchio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include <fstream>

/*Create a program that takes three parameters in the following order: a filename and
two strings, s1 and s2.
It will open the file <filename> and copies its content into a new file
<filename>.replace, replacing every occurrence of s1 with s2.
Using C file manipulation functions is forbidden and will be considered cheating. All
the member functions of the class std::string are allowed, except replace. Use them
wisely!
You have to use the flag -Wall -Wextra -Werror -std=c++98.
Of course, handle unexpected inputs and errors. You have to create and turn in your
own tests to ensure your program works as expected.
10
*/

int	search_and_replace(std::string &lines, std::string filename, std::string s1, std::string s2);

int main(int ac, char **av)
{
	std::ifstream	inf;
	std::string		read;
	std::string		lines;
	
	if (ac != 4)
	{
		std::cout << "Wrong number of arguments." << std::endl;
		return (1);
	}
	inf.open(av[1]);
	if (inf.fail())
	{
		std::cout << "Error: can't open infile " << av[1] << std::endl;
		return (1);
	}
	while (!inf.eof() && !inf.fail())
	{
		std::getline(inf, read);
		lines += read;
		if (!inf.eof())
			lines += "\n";
	}
	inf.close();
	return (search_and_replace(lines, av[1], av[2], av[3]));
}

int	search_and_replace(std::string &lines, std::string filename, std::string s1, std::string s2)
{
	std::ofstream	ouf;
	size_t			pos = 0;
	size_t			len = s1.length();
	
	while ((pos = lines.find(s1, pos)) != std::string::npos)
	{
		lines.erase(pos, len);
		lines.insert(pos, s2);
		pos += s2.length();
	}
	ouf.open(std::string(filename + ".replace").c_str());
	if (ouf.fail())
	{
		std::cout << "Error: can't open outfile." << std::endl;
		return (1);
	}
	ouf << lines;
	ouf.close();
	return (0);
}
