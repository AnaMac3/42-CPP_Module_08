/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amacarul <amacarul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/03 14:08:09 by amacarul          #+#    #+#             */
/*   Updated: 2025/11/03 17:25:33 by amacarul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

/**
 * @brief	Default constructor	
 *
 */
Span::Span() :	_N(0),
				_data(0)
{
	//std::cout << "Span Default Constructor called" << std::endl;
}

/**
 * @brief	Constructor	with n parameter
 * 
 * @param n	Number of elements to allocate
 */
Span::Span(unsigned int n) :	_N(n)
{
	_data.reserve(_N);
}

/**
 * @brief	Copy constructor
 * 			???????¿?¿?¿?¿?¿ COMO DEBERIA HACER LA COPIA BIEN HECHA?
 *
 * @param other	Reference to object to copy from
 */
Span::Span(const Span& other) : _N(other._N)
{
	*this = other;
}

/**
 * @brief	Assignment operator	
 * 			Replaces the current Span contents with a deep copy of	
 * 			another Span
 *
 * @param other	Reference to object to copy from
 * @return	Reference o the current object
 */
Span&	Span::operator=(const Span& other)
{
	if (this != &other)
	{
		this->_N = other._N;
		this->_data = other._data;
	}
	return (*this);
}

/**
 * @brief	Default destructor	
 *
 */
Span::~Span()
{
}

//------------------------ Member functions             ------------------------

/**
 * @brief	añade un único número al Span
 * 			Si el tamaño actual de _data supera 
 * 			si ya hay N elements en el Span, throw an exception
 *
 */

void	Span::addNumber(int value)
{
	if (_data.size() >= _N)
		throw LimitMaxException();
	_data.push_back(value);
	std::cout << BLUE << value << " added. Span size = " << _data.size() << RESET << std::endl;
}

/**
 * @brief	returns la diferencia mínima entre los valores del span
 * 			si no hay dos numeros, devuelve error
 * 			NO ESTOY SEGURA DE SI DEBE EVITAR DEVOLVER 0 SI ES QUE LOS DOS VALORES MINIMOS SON EL MISMO
 * 
 */
int Span::shortestSpan() const
{
	if (_data.size() < 2)
		throw NotEnoughElementsException();
	else
	{
		std::vector<int> sorted = _data;
		std::sort(sorted.begin(), sorted.end());
		return (sorted[1] - sorted[0]);
	}
}

/**
 * @brief	
 * 
 */
int Span::longestSpan() const
{
	if (_data.size() < 2)
		throw NotEnoughElementsException();
	else
	{
		//ME SALE NO SUITABLE USER DEFINITION CONVERSION, POR QUÉ?=
		std::vector<int>::const_iterator maxIter = std::max_element(_data.begin(), _data.end());
		std::vector<int>::const_iterator minIter = std::min_element(_data.begin(), _data.end());
		int maxValue = *maxIter;
		int minValue = *minIter;
		
		return (maxValue - minValue);
	}
}

/**
 * @brief
 * 
 */
void	Span::printSpan() const
{
	for (size_t i = 0; i < _data.size(); i++)
	{
		std::cout << _data[i] << " ";
	}
	std::cout << std::endl;
}

//------------------------ Exceptions                   ------------------------
/**
 * @brief	
 */
const char* Span::LimitMaxException::what() const throw()
{
	return("Max number of elements reached.");
}

/**
 * @brief	
 */
const char* Span::NotEnoughElementsException::what() const throw()
{
	return("Less than two elements in the span. Cannot calculate span.");
}
