/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: root <root@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/04 18:31:21 by root              #+#    #+#             */
/*   Updated: 2025/11/04 19:14:03 by root             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANTSTACK_HPP
# define MUTANTSTACK_HPP

# include <iostream>
# include <stack>

# define BLUE "\033[34m"
# define RESET "\033[0m"

/**
 * @class	MutantStack
 * @brief	A stack container that is iterable using standard iterators.
 * 			- MutantStack inhertis from std::stack. 
 * 			- std::stack does not provide iterators, 
 *			- but it is an adapter over an underlying container 
 * 			(by default std::deque) which has iterators. 
 * 			- MutantStack exposes these iterators as public member types:
 * 				* iterator
 * 				* const_iterator
 * 				* reverse_iterator
 * 				* const_reverse_iterator
 * 			- This allows using range-based algorithms and standard iterator
 * 			operations on a stack, without changing its LIFO behaviour
 * 
 * @tparam T	Type of elements stored in the stack
 */
template <typename T>
class MutantStack : public std::stack<T>
{
	private:
		
		
	public:
		MutantStack();
		MutantStack(const MutantStack& other);
		MutantStack& operator=(const MutantStack& other);
		~MutantStack();

		//Iterator types
		typedef typename std::stack<T>::container_type::iterator iterator;
		typedef typename std::stack<T>::container_type::reverse_iterator reverse_iterator;
		typedef typename std::stack<T>::container_type::const_iterator const_iterator;
		typedef typename std::stack<T>::container_type::const_reverse_iterator const_reverse_iterator;

		//Iterator
		iterator begin();
		iterator end();
		
		//Reverse Iterator
		reverse_iterator rbegin();
		reverse_iterator rend();

		//Const Iterator
		const_iterator begin() const;
		const_iterator end() const;
		
		//Const Reverse Iterator
		const_reverse_iterator rbegin() const;
		const_reverse_iterator rend() const;
	
		
};

# include "MutantStack.tpp"

#endif
