/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amacarul <amacarul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/03 14:08:23 by amacarul          #+#    #+#             */
/*   Updated: 2025/11/03 17:26:00 by amacarul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

#define RED "\033[31m"
#define RESET "\033[0m"


int main()
{
    Span mySpan(3);
    mySpan.addNumber(5);
    mySpan.addNumber(5);
    mySpan.addNumber(7);
    //full span
    try
    {
        mySpan.addNumber(8);
    }
    catch(const std::exception& e)
    {
        std::cerr << RED << e.what() << RESET << std::endl;
    }
    //printSpan
    mySpan.printSpan();
    //shortestSpan
    try
    {
        std::cout << "shortest span: " << mySpan.shortestSpan() << std::endl;;
    }
    catch(const std::exception& e)
    {
        std::cerr << RED << e.what() << RESET << std::endl;
    }
    //longestSpan
    try
    {
        std::cout << "longest span: " << mySpan.longestSpan() << std::endl;;
    }
    catch(const std::exception& e)
    {
        std::cerr << RED << e.what() << RESET << std::endl;
    }
    
    std::cout << std::endl;
    Span mySpan2(5);
    int array[] = {5, 6, 8, 10, 3};
    try
    {
        mySpan2.addRange(array, array + 5);
        mySpan2.printSpan();
    }
    catch(const std::exception& e)
    {
        std::cerr << RED << e.what() << RESET << std::endl;
    }

}