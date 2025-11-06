/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amacarul <amacarul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/03 14:08:09 by amacarul          #+#    #+#             */
/*   Updated: 2025/11/06 17:02:29 by amacarul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

/**
 * @brief	Default constructor.
 * 			Initializes an empty Span.
 *
 */
Span::Span() :	_N(0),
				_data(0)
{
	//std::cout << "Span Default Constructor called" << std::endl;
}

/**
 * @brief	Constructs a Span with a given maximum capacity
 * 
 * @param n	The maximum number of integers that can be stored
 */
Span::Span(unsigned int n) :	_N(n)
{
	_data.reserve(_N);
}

/**
 * @brief	Copy constructor. Creates a new Span as a copy of another
 *
 * @param other	Reference to object to copy from
 */
Span::Span(const Span& other) : _N(other._N)
{
	*this = other;
}

/**
 * @brief	Assignment operator	
 * 			Replaces the current contents with those of another.
 * 			
 * 			Note: std::vector does shallow copy with = operator
 *
 * @param other	Reference to object to copy from
 * @return	Reference o the current object
 */
Span&	Span::operator=(const Span& other)
{
	if (this != &other)
	{
		this->_N = other._N;
		_data.reserve(this->_N);
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
 * @brief	Adds a single integer to the Span
 * 
 * @param value	The integer to add
 * @throws	LimitMaxWException	If the Span is already full
 */

void	Span::addNumber(int value)
{
	if (_data.size() >= _N)
		throw LimitMaxException();
	_data.push_back(value);
	std::cout << BLUE << value << " added. Span size = " << _data.size() << RESET << std::endl;
}

/**
 * @brief	Computes the shortest distance (smalles difference) between any two
 * 			stored numbers
 * 
 * @return	The smalles difference between two numbers
 * @throws NotEnoughElementsException	If fewer than two numbers are stored
 */
int Span::shortestSpan() const
{
	if (_data.size() < 2)
		throw NotEnoughElementsException();
	else
	{
		std::vector<int> sorted = _data;
		std::sort(sorted.begin(), sorted.end());
		int res = std::numeric_limits<int>::max();
		for (size_t i = 0; i < sorted.size(); i ++)
		{
			int diff = sorted[i + 1] - sorted[i];
			if (diff < res && diff >= 0)
				res = diff;
		}
		return (res);
	}
}

/**
 * @brief	Computes the longest distance (largest difference) between the
 * 			minimun and maximum stored numbers
 * 
 * @return	The largest difference between any two numbers
 * @throws NotEnoughElementsException	If fewer than two numbers are stored.
 */
int Span::longestSpan() const
{
	if (_data.size() < 2)
		throw NotEnoughElementsException();
	else
	{
		std::vector<int>::const_iterator maxIter = std::max_element(_data.begin(), _data.end());
		std::vector<int>::const_iterator minIter = std::min_element(_data.begin(), _data.end());
		int maxValue = *maxIter;
		int minValue = *minIter;
		
		return (maxValue - minValue);
	}
}

/**
 * @brief	Prints all stored numbers to standard output
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
	return("Cannot compute span: the container myst have at least two elements.");
}
