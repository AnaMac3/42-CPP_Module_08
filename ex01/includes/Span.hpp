/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amacarul <amacarul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/03 14:08:27 by amacarul          #+#    #+#             */
/*   Updated: 2025/11/03 17:22:26 by amacarul         ###   ########.fr       */
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
 * @brief	can store a max of N integers. 
 * 			N is unsigned int 
 * 			UTILIZAR UN CONTAINER, CUÁL ME CONVIENE? 
 * 			COSAS QUE TIENE QUE PODER HACER:
 * 			- RESERVAR MEMORIIA PARA N ELEMENTOS (?)
 * 			- AÑADIR ELEMENTOS
 * 			- COMPROBAR EL TAMAÑO ACTUAL DEL CONTAINER (CUÁNTOS ELEMENTOS HAY
 * 			DENTRO DEL CONTAINER)
 * 			- COMPARAR LOS VALORES DE LOS ELEMENTOS, ENCONTRAR EL MENOR Y MAYOR SPAN ?
 * 
 * 			TESTEARLO CON AL MENOS 10.000 NÚMEROS
 * 			
 * 			USAR RANGE OF ITERATORS -> OTRA MEMBER FUNCTION PARA ADD MULTIPLE NUMBERS
 *		
 * 			Se elige el container vector porque:
 * 			- Permite hacer reserve()
 * 			- Permite añadir elementos mediante push_back, insert
 * 			- tiene size()
 * 			- Permite buscar minimos y máximos con <algorithm>
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
		 * @brief	Añadir range of iterators, multiples numbers a la vez
		 * 			NO ESTOY SEGURA SID DEBERIA PASARSELE CON ARRAY DE INTS
		 * 			COMO ES ESO DE RANGE OF ITERATORS?
		 * 			dudas:
		 * 				- por qué se aumenta it antes y no después? esto no hace que el primer elemento del rango no se añada?
		 * 				- en c++98 no se puede usar insert¿?
		 */
		template <typename T>
		void	addRange(T begin, T end)
		{
			size_t range = std::distance(begin, end);
			if (_data.size() + range > _N)
				throw LimitMaxException();
			for (T it = begin; it != end; ++it)
			{
				_data.push_back(*it);
			}
		}
		//Exceptions
		/**
		 * @class	FullSpanException
		 * @brief	Thrown when trying to add a number when the span is full	
		 */
		class	LimitMaxException : public std::exception
		{
			public:
				const char* what() const throw();
		};
		/**
		 * @class	FullSpanException
		 * @brief	Thrown when trying to add a number when the span is full	
		 */
		class	NotEnoughElementsException : public std::exception
		{
			public:
				const char* what() const throw();
		};
		
};

#endif
