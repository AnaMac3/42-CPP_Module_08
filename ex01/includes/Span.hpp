/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: root <root@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/03 14:08:27 by amacarul          #+#    #+#             */
/*   Updated: 2025/11/04 18:17:43 by root             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef Span_HPP
# define Span_HPP

# include <iostream>
# include <vector>
# include <algorithm>
# include <iterator>

# define BLUE "\033[34m"
# define RESET "\033[0m"

/**
 * @class	Span
 * @brief	Stores up to N integer values and allows computation of the
 * 			shortest and longest spans (differences) between stored numbers.
 * 			The Span class internally uses a std::vector<int> as its
 * 			container, because:
 * 			- It supports reserving memory using reserve()
 * 			- It allows element insertion with push_back() and insert()
 * 			- It provides size() for tracking the number of stored elements
 * 			- It works well with <algorithm> functions such as std::sort, 
 * 			std::min_element, std::max_element
 * 			
 * 			The class can:
 * 			- Store up to N elements
 * 			- Add individual or multiple numbers (via iterator range)
 * 			- Compute the shortest and longest span between stored numnbers
 * 			- Throw exceptions when limits are exceeded or insufficient
 * 			elements exist (for calculating shortest/longest span)
 */
class Span
{
	private:
		unsigned int _N;
		std::vector<int> _data;
		
	public:
		Span();
		Span(unsigned int n);
		Span(const Span& other);
		Span& operator=(const Span& other);
		~Span();

		//Member functions
		void	addNumber(int value);
		int		shortestSpan() const;
		int		longestSpan() const;
		void	printSpan() const;

		/**
		 * @brief	Adds multiple numbers at one using a range of iterators.
		 * 			The function inserts all elements between two iterators
		 * 			(begin, end). 
		 * 			It checks whether the number of elements being inserted
		 * 			would exceed the Span's capacity
		 * 
		 * @tparam T	Iterator type
		 * @param begin	Iterator pointing to the first element of the range
		 * @param last	Iterator pointing to the last element of the range
		 * @throws LimitMaxException	If inserting would exceed the maximum
		 * 								capacity
		 */
		template <typename T>
		void	addRange(T begin, T last)
		{
			size_t range = std::distance(begin, last);
			if (_data.size() + range > _N)
				throw LimitMaxException();
			for (T it = begin; it != last; ++it)
			{
				_data.push_back(*it);
			}
		}

		/**
		 * @class	LimitMaxException
		 * @brief	Thrown when attempting to add an element beyond the Span's
		 * 			maximum capacity	
		 */
		class	LimitMaxException : public std::exception
		{
			public:
				const char* what() const throw();
		};
		
		/**
		 * @class	NotEnoughElementException
		 * @brief	Thrown when attempting to calculate a span with fewer than
		 * 			two stored elements	
		 */
		class	NotEnoughElementsException : public std::exception
		{
			public:
				const char* what() const throw();
		};
		
};

#endif
