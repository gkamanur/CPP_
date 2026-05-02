/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkamanur <gkamanur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/28 14:40:44 by gkamanur          #+#    #+#             */
/*   Updated: 2026/05/02 15:04:06 by gkamanur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
# define PMERGEME_HPP

# include <vector>
# include <deque>
# include <string>
# include <utility>
# include <algorithm>
// # include <stdexcept>
#include <iostream>
#include <exception>

class PmergeMe
{
    public:
        PmergeMe();
        PmergeMe(const PmergeMe& other);
        PmergeMe& operator=(const PmergeMe& other);
        ~PmergeMe();

        void    parse(int ac, char** av);
        void    run();
    private:  
        std::vector<int>    _vec;
        std::deque<int>     _deq;
        
        size_t	_binarySearch(const std::vector<int>& seq, size_t hi, int target);
        size_t	_binarySearch(const std::vector<std::pair<int,int> >& seq, size_t hi, int target);
        size_t	_binarySearch(const std::deque<int>& seq, size_t hi, int target);
        size_t	_binarySearch(const std::deque<std::pair<int,int> >& seq, size_t hi, int target);
        //VECTOR
        std::vector<std::pair<int, int> > _buildPairs_vec(const std::vector<int>& v);
        void _sortPairs_vec(std::vector<std::pair<int, int> >& pairs);
        void _buildChains_vec(const std::vector<std::pair<int, int> >& pairs,
	            std::vector<int>& main,
	            std::vector<int>& pend);
        void _insertPend_vec(std::vector<int>& main, const std::vector<int>& pend);
        void _sortVector(std::vector<int>& v);
        void _insertVec(std::vector<int>& main, int value);
        //DEQUE
        std::deque<std::pair<int, int> > _buildPairs_dq(const std::deque<int>& v);
        void _sortPairs_dq(std::deque<std::pair<int, int> >& pairs);
        void _buildChains_dq(const std::deque<std::pair<int, int> >& pairs,
	            std::deque<int>& main,
	            std::deque<int>& pend);
        void _insertPend_dq(std::deque<int>& main, const std::deque<int>& pend);
        void _sortDeque(std::deque<int>& v);
        void _insertDeque(std::deque<int>& main, int value);

        std::vector<size_t> _jacobsthal_vec(size_t upTo);
        std::deque<size_t>  _jacobsthal_deq(size_t Upto);
};

template <typename Container>
bool isSorted(const Container& c)
{
    if (c.size() < 2)
        return true;
    for (size_t i = 0; i + 1 < c.size(); ++i)
        if (c[i] > c[i + 1])
            return false;
    return true;
}

#endif