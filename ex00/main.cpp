/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amacarul <amacarul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/31 10:29:56 by root              #+#    #+#             */
/*   Updated: 2025/11/03 12:30:48 by amacarul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "easyfind.hpp"
# include <vector>
# include <list>
# include <deque>

# define RED "\033[31m"
# define GREEN "\033[32m"
# define RESET "\033[0m"


int main()
{
	//------------------------ VECTOR ------------------------
	std::cout << std::endl;
	std::cout << "=== VECTOR ===" << std::endl;
	std::vector<int> myVector;
	//Add elements to myVector
	myVector.push_back(3); //adds the elment to the end
	myVector.push_back(4);
	myVector.push_back(5);
	myVector.insert(myVector.begin(), 2); //inserts a value in the given pos
	int arr[] = {10, 20, 30};
	myVector.insert(myVector.end(), arr, arr + sizeof(arr) / sizeof(int)); //inserts  a range of elements in the given pos
	//size
	std::cout << "myVector size: " << myVector.size() << std::endl;
	//print elements
	std::cout << "myVector content: ";
	for (std::vector<int>::iterator it = myVector.begin(); it != myVector.end(); it ++)
    {
        std::cout << *it << " ";
    }
	std::cout << std::endl;
	//easyfind()
	std::cout << "try to find 4: " << std::endl;
	try
	{
		std::vector<int>::iterator res = easyfind(myVector, 4);
		std::cout << GREEN << "result: " << *res << RESET << std::endl;
		
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
	std::cout << "try to find 100: " << std::endl;
	try
	{
		std::vector<int>::iterator res = easyfind(myVector, 100);
		std::cout << "result: " << *res << std::endl;
		
	}
	catch(const std::exception& e)
	{
		std::cerr << RED << e.what() << RESET << std::endl;
	}

	//------------------------ LIST ------------------------
	std::cout << std::endl;
	std::cout << "=== LIST ===" << std::endl;
	std::list<int> myList;
	//Add elements to myList
	myList.push_back(30);
	myList.push_back(40);
	myList.push_back(50);
	//add an element in concrete position
	std::list<int>::iterator iter;
	for (iter = myList.begin(); *iter != 50; ++iter);
	myList.insert(iter, 45);
	myList.insert(myList.begin(), 23);
	std::cout << "myList content: " << std::endl;
	for (std::list<int>::iterator it = myList.begin(); it != myList.end(); it ++)
    {
        std::cout << *it << " ";
    }
	std::cout << std::endl;
	//easyfind()
	std::cout << "try to find 40: " << std::endl;
	try
	{
		std::list<int>::iterator res = easyfind(myList, 40);
		std::cout << GREEN << "result: " << *res << RESET << std::endl;
		
	}
	catch(const std::exception& e)
	{
		std::cerr << RED << e.what() << RESET << std::endl;
	}
	std::cout << "try to find 2: " << std::endl;
	try
	{
		std::list<int>::iterator res = easyfind(myList, 2);
		std::cout << GREEN << "result: " << *res << RESET << std::endl;
		
	}
	catch(const std::exception& e)
	{
		std::cerr << RED << e.what() << RESET << std::endl;
	}
	
	//------------------------ DEQUE ------------------------
	std::cout << std::endl;
	std::cout << "=== DEQUE ===" << std::endl;
	std::deque<int> myDeque;
	myDeque.push_back(12);
	myDeque.push_back(13);
	myDeque.push_back(14);
	std::cout << "myDeque content: " << std::endl;
	for (std::deque<int>::iterator it = myDeque.begin(); it != myDeque.end(); it ++)
    {
        std::cout << *it << " ";
    }
	std::cout << std::endl;
	//easyfind()
	std::cout << "try to find 13: " << std::endl;
	try
	{
		std::deque<int>::iterator res = easyfind(myDeque, 13);
		std::cout << GREEN << "result: " << *res << RESET << std::endl;
		
	}
	catch(const std::exception& e)
	{
		std::cerr << RED << e.what() << RESET << std::endl;
	}
	std::cout << "try to find 30: " << std::endl;
	try
	{
		std::deque<int>::iterator res = easyfind(myDeque, 300);
		std::cout << GREEN << "result: " << *res << RESET << std::endl;
		
	}
	catch(const std::exception& e)
	{
		std::cerr << RED << e.what() << RESET << std::endl;
	}
}