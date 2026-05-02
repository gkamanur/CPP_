/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkamanur <gkamanur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/12 19:57:01 by gkamanur          #+#    #+#             */
/*   Updated: 2026/04/16 19:57:04 by gkamanur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
#define ARRAY_HPP

# include <iostream>
# include <stdexcept>

template <typename T>
class Array
{
    private:
        T* _elements;
        unsigned int _size;
    public:
        Array(): _elements(NULL), _size(0){}
        Array(unsigned int n): _elements(new T[n]()), _size(n){}
        Array(const Array& other): _elements(NULL), _size(0)
        {
            *this = other;
        }
        Array& operator=(const Array& rhs)
        {
            if (this != &rhs)
            {
                delete[] _elements;
                _size = rhs._size;
                _elements = new T[_size];
                for (unsigned int i = 0; i < _size; i++)
                    _elements[i] = rhs._elements[i];
            }
            return (*this);
        }
        ~Array()
        {
            delete[] _elements;
        }
        
        T& operator[](unsigned int index)
        {
            if (index >= _size)
                throw std::out_of_range("Index out of range");
            return _elements[index];
        }

        const T& operator[](unsigned int index) const
        {
            if (index >= _size)
                throw std::out_of_range("Index out of bounds");
            return _elements[index];
        }
        
        unsigned int size() const
        {
            return (_size);
        }
};
#endif