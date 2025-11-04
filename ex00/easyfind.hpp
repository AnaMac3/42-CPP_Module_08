/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: root <root@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/31 10:29:49 by root              #+#    #+#             */
/*   Updated: 2025/11/04 18:04:18 by root             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASYFIND_HPP
# define EASYFIND_HPP

# include <iostream>
# include <exception> //exception
# include <algorithm> //find

/**
 * @class   notFoundException
 * @brief   Exception thrown when the specified element is not found in the
 *          container.
 *          This exception is used by the easyfind() template function to
 *          indicate that the target integer value could not be located within
 *          the given container.
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
 * @brief   Searches for the first occurence of a given integer in a container.
 *          - Uses std::find to locate the first occurence of an integer
 *          value inside a container. This returns an iterator pointing to the
 *          found element. 
 *          - If the element is not found (std::find returns container.end() 
 *          iterator) this function throws an excetion
 * @tparam T    The container type. It must support begin(), end(), and
 *              the comparison operator (==) with int (be careful with associative
 *              containers)
 * @param container Reference to the container to be searched
 * @param toFind    The integer value to search for
 * @return  An iterator pointing to the first occurence of the searched value
 * @throws  notFoundException if the integer is not found in the container
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