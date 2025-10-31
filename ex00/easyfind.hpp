/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: root <root@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/31 10:29:49 by root              #+#    #+#             */
/*   Updated: 2025/10/31 11:47:44 by root             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASYFIND_HPP
# define EASYFIND_HPP

# include <iostream>
# include <exception> //exception
# include <algorithm> //find

/**
 * @class   notFoundException
 * @brief   Thrown when the toFind element is not found in the container
 *          in the function easyfind().
 */

class   notFoundException : public std::exception
{
    public:
        const char* what() const throw()
        {
            return ("Number not found in the container.");
        }
};

/**
 * @brief   Function template that accepts a type T. 
 *          It takes two parameters: the first one is of type T, and
 *          the second one is an integer
 *          La función tiene que encontrar la primera ocurrencia del
 *          segundo parámetro en el primer parámetro - hacemos que devuelva
 *          un puntero lógico al elemento encontrado dentro del contenedor,
 *          es decir, tiene que devolver un T::iterator.
 *          Además, std::find devuelve un iterador...
 *          Si no hay concidencias, se puede throwear una excepción o
 *          devolver un error value
 * 
 *          
 */

template <typename T>
typename T::iterator   easyfind(T &container, int toFind)
{
	typename T::iterator it;
	it = std::find(container.begin(), container.end(), toFind);
	if (it == container.end())
		throw (::notFoundException());
	return (it);
}

#endif