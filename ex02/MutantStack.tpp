/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.tpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: root <root@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/04 18:34:02 by root              #+#    #+#             */
/*   Updated: 2025/11/04 19:14:35 by root             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "MutantStack.hpp"

/**
 * @brief	Default constructor.
 *
 */
template <typename T>
MutantStack<T>::MutantStack() : std::stack<T>()
{

}

/**
 * @brief	Copy constructor. Creates a new MutantStack as a copy of another
 *
 * @param other	Reference to object to copy from
 */
template <typename T>
MutantStack<T>::MutantStack(const MutantStack& other) : std::stack<T>(other)
{

}

/**
 * @brief	Assignment operator	
 * 			Replaces the current contents with those of another.
 *
 * @param other	Reference to object to copy from
 * @return	Reference o the current object
 */
template <typename T>
MutantStack<T>&	MutantStack<T>::operator=(const MutantStack& other)
{
	if (this != &other)
	{
		std::stack<T>::operator=(other);
	}
	return (*this);
}

/**
 * @brief	Default destructor	
 *
 */
template <typename T>
MutantStack<T>::~MutantStack()
{
    
}

//--------------------------- Iterator               ---------------------------

/**
 * @brief   Returns an iterator to the first element in the stack
 * 
 * @return iterator to the beginning of the stack
 */
template <typename T>
typename MutantStack<T>::iterator MutantStack<T>::begin()
{
    return (this->c.begin());
}

/**
 * @brief   Returns an iterator to the last element in the stack
 * 
 * @return iterator to the end of the stack
 */
template <typename T>
typename MutantStack<T>::iterator MutantStack<T>::end()
{
    return (this->c.end());
}

//--------------------------- Reverse Iterator       ---------------------------

/**
 * @brief   Returns a reverse iterator to the last element in the stack
 * 
 * @return reverse_iterator to the reverse beginning
 */
template <typename T>
typename MutantStack<T>::reverse_iterator MutantStack<T>::rbegin()
{
    return (this->c.rbegin());
}

/**
 * @brief   Returns a reverse iterator to one before the first element in the stack
 * 
 * @return reverse_iterator to the reverse end
 */
template <typename T>
typename MutantStack<T>::reverse_iterator MutantStack<T>::rend()
{
    return (this->c.rend());
}

//--------------------------- Const Iterator         ---------------------------

/**
 * @brief   Returns an const iterator to the first element in the stack
 * 
 * @return const_iterator to the beginning of the stack
 */
template <typename T>
typename MutantStack<T>::const_iterator MutantStack<T>::begin() const
{
    return (this->c.begin());
}

/**
 * @brief   Returns an iterator to the last element in the stack
 * 
 * @return const_iterator to the end of the stack
 */
template <typename T>
typename MutantStack<T>::const_iterator MutantStack<T>::end() const
{
    return (this->c.end());
}

//--------------------------- Const Reverse Iterator ---------------------------

/**
 * @brief   Returns a const reverse iterator to the last element in the stack
 * 
 * @return const_reverse_iterator to the reverse beginning
 */
template <typename T>
typename MutantStack<T>::const_reverse_iterator MutantStack<T>::rbegin() const
{
    return (this->c.rbegin());
}

/**
 * @brief   Returns a const reverse iterator to one before the first element 
 *          in the stack
 * 
 * @return const_reverse_iterator to the reverse end
 */
template <typename T>
typename MutantStack<T>::const_reverse_iterator MutantStack<T>::rend() const
{
    return (this->c.rend());
}
