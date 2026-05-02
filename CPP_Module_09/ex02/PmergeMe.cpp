/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkamanur <gkamanur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/30 17:52:01 by gkamanur          #+#    #+#             */
/*   Updated: 2026/05/02 19:40:32 by gkamanur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"
#include <iostream>
#include <sstream>
#include <cstdlib>
#include <cctype>
#include <stdexcept>
#include <limits>
#include <ctime>
#include <iomanip>


PmergeMe::PmergeMe(){}

PmergeMe::PmergeMe(const PmergeMe& other)
    :_vec(other._vec),_deq(other._deq){}

PmergeMe& PmergeMe::operator=(const PmergeMe& rhs)
{
    if (this != &rhs)
    {
        _vec = rhs._vec;
        _deq = rhs._deq;
        
    }
    return *this;
}

PmergeMe::~PmergeMe() {}

void    PmergeMe::parse(int ac, char** av)
{
    if (ac < 2)
        throw std::runtime_error("ERROR: ");
    for (int i = 1; i < ac; ++i)
    {
        std::string s(av[i]);
        if(s.empty())
            throw std::runtime_error("ERROR: ");
        for (size_t k = 0; k < s.size(); ++k)
            if(!std::isdigit(static_cast<unsigned char>(s[k])))
                throw std::runtime_error("ERROR: ");
        
        char* endp = 0;
        long n = std::strtol(s.c_str(), &endp, 10);
        if (*endp != '\0' || n < 0 || n > std::numeric_limits<int>::max())
            throw std::runtime_error("Error");
        
        _vec.push_back(static_cast<int>(n));
        _deq.push_back(static_cast<int>(n));
    }
}
static  void printsequence(const char *tag, const std::vector<int>& v)
{
    std::cout << tag;
    for (size_t i = 0; i < v.size(); ++i)
    {
        std::cout << " " << v[i];
    }
    std::cout << std::endl;
}

static  void printsequence(const char *tag, const std::deque<int>& v)
{
    std::cout << tag;
    for (size_t i = 0; i < v.size(); ++i)
    {
        std::cout << " " << v[i];
    }
    std::cout << std::endl;
}

//---------------------------------------------------------------------------------------------------------JACOBSTHAL
std::vector<size_t> PmergeMe::_jacobsthal_vec(size_t Upto)
{
    std::vector<size_t> j;
    j.push_back(0);
    j.push_back(1);
    while (j.back() < Upto)
    {
        size_t next = j[j.size() - 1] + 2 * j[j.size() - 2];
        // size_t next = j[j.size() - 1] + j[j.size() - 2]; // fibonacci
        j.push_back(next);
    }
    return j;
    
}

std::deque<size_t> PmergeMe::_jacobsthal_deq(size_t Upto)
{
    std::deque<size_t> j;
    j.push_back(0);
    j.push_back(1);
    while (j.back() < Upto)
    {
        size_t next = j[j.size() - 1] + 2 * j[j.size() - 2];
        // size_t next = j[j.size() - 1] + j[j.size() - 2]; //fibonacci
        j.push_back(next);
    }
    return j;
    
}
//---------------------------------------------------------------------------------------------------------Binary Search
size_t	PmergeMe::_binarySearch(const std::vector<int>& seq, size_t hi, int target)
{
	size_t lo = 0;
	while (lo < hi)
	{
		size_t mid = (lo + hi) / 2;
		if (seq[mid] <= target)
			lo = mid + 1;
		else
			hi = mid;
	}
	return lo;
}

size_t	PmergeMe::_binarySearch(const std::vector<std::pair<int,int> >& seq, size_t hi, int target)
{
	size_t lo = 0;
	while (lo < hi)
	{
		size_t mid = (lo + hi) / 2;
		if (seq[mid].first < target)
			lo = mid + 1;
		else
			hi = mid;
	}
	return lo;
}
size_t	PmergeMe::_binarySearch(const std::deque<int>& seq, size_t hi, int target)
{
	size_t lo = 0;
	while (lo < hi)
	{
		size_t mid = (lo + hi) / 2;
		if (seq[mid] <= target)
			lo = mid + 1;
		else
			hi = mid;
	}
	return lo;
}

size_t	PmergeMe::_binarySearch(const std::deque<std::pair<int,int> >& seq, size_t hi, int target)
{
	size_t lo = 0;
	while (lo < hi)
	{
		size_t mid = (lo + hi) / 2;
		if (seq[mid].first < target)
			lo = mid + 1;
		else
			hi = mid;
	}
	return lo;
}
//---------------------------------------------------------------------------------------------------------VECTOR

void PmergeMe::_insertVec(std::vector<int>& main, int value)
{
    size_t pos = _binarySearch(main, main.size(), value);
    main.insert(main.begin() + pos, value);
}

std::vector<std::pair<int, int> >	PmergeMe::_buildPairs_vec(const std::vector<int>& v)
{
    std::vector<std::pair<int, int> > pairs;
    pairs.reserve(v.size() / 2);
    for (size_t i = 0; i < v.size(); i += 2)
    {
        if (v[i] > v[i + 1])
            pairs.push_back(std::make_pair(v[i], v[i + 1]));
        else
            pairs.push_back(std::make_pair(v[i + 1], v[i]));
    }
    return pairs;
}

void PmergeMe::_sortPairs_vec(std::vector<std::pair<int, int> >& pairs)
{
    for (size_t i = 1; i < pairs.size(); ++i)
    {
        std::pair<int, int> key = pairs[i];
        size_t pos = _binarySearch(pairs, i, key.first);
        for (size_t k = i; k > pos; --k)
            pairs[k] = pairs[k - 1];
        pairs[pos] = key;
    }
}

void PmergeMe::_buildChains_vec(const std::vector<std::pair<int, int> >& pairs,
                                std::vector<int>& main, std::vector<int>& pend)
{
    main.reserve(pairs.size() + 1);
    main.push_back(pairs[0].second);
    for (size_t i = 0; i < pairs.size(); ++i)
    {
        main.push_back(pairs[i].first);
    }
    pend.reserve(pairs.size());
    for (size_t i = 1; i < pairs.size(); ++i)
    {
        pend.push_back(pairs[i].second);
    }
}
void PmergeMe::_insertPend_vec(std::vector<int>& main, const std::vector<int>& pend)
{
    if (pend.empty())
        return ;
    std::vector<size_t> jac =_jacobsthal_vec(pend.size());
    std::vector<bool> done(pend.size(), false);
    for(size_t i = 2; i < jac.size(); ++i)
    {
        size_t hi = jac[i];
        size_t lo = jac[i - 1];
        if(hi > pend.size())
            hi = pend.size();
        for (size_t idx = hi; idx > lo; --idx)
        {
            if (idx >= pend.size() || done [idx])
                continue;
            _insertVec(main, pend[idx]);
            done[idx] = true;
            
        }
    }
    for (size_t i = 0; i < pend.size(); ++i)
    {
        if (!done[i])
            _insertVec(main, pend[i]);
    }
}

void PmergeMe::_sortVector(std::vector<int>& v)
{
    if(v.size() < 2)
        return ;
    
    bool isOdd = (v.size() % 2 == 1);
    int  straggler = 0;
    if(isOdd)
    {
        straggler = v.back();
        v.pop_back();
    }
    std::vector<std::pair<int, int> > pairs = _buildPairs_vec(v);
    _sortPairs_vec(pairs);
    
    std::vector<int> main, pend;
    _buildChains_vec(pairs, main, pend);
    _insertPend_vec(main, pend);
    if(isOdd)
        _insertVec(main, straggler);
    v = main;
}
//---------------------------------------------------------------------------------------------------------DEQUE
void PmergeMe::_insertDeque(std::deque<int>& main, int value)
{
    size_t pos = _binarySearch(main, main.size(), value);
    main.insert(main.begin() + pos, value);
}

std::deque<std::pair<int, int> >	PmergeMe::_buildPairs_dq(const std::deque<int>& v)
{
	std::deque<std::pair<int, int> > pairs;
	for (size_t i = 0; i < v.size(); i += 2)
	{
		if (v[i] > v[i + 1])
			pairs.push_back(std::make_pair(v[i],     v[i + 1]));
		else
			pairs.push_back(std::make_pair(v[i + 1], v[i]));
	}
	return pairs;
}

void PmergeMe::_sortPairs_dq(std::deque<std::pair<int, int> >& pairs)
{
    for (size_t i = 1; i < pairs.size(); ++i)
    {
        std::pair<int, int> key = pairs[i];
        size_t pos = _binarySearch(pairs, i, key.first);
        for (size_t k = i; k > pos; --k)
            pairs[k] = pairs[k - 1];
        pairs[pos] = key;
    }
}

void PmergeMe::_buildChains_dq(const std::deque<std::pair<int, int> >& pairs,
                                std::deque<int>& main, std::deque<int>& pend)
{
    // main.reserve(pairs.size() + 1);
    main.push_back(pairs[0].second);
    for (size_t i = 0; i < pairs.size(); ++i)
    {
        main.push_back(pairs[i].first);
    }
    // pend.reserve(pairs.size());
    for (size_t i = 1; i < pairs.size(); ++i)
    {
        pend.push_back(pairs[i].second);
    }
}

void PmergeMe::_insertPend_dq(std::deque<int>& main, const std::deque<int>& pend)
{
    if (pend.empty())
        return ;
    std::deque<size_t> jac =_jacobsthal_deq(pend.size());
    std::deque<bool> done(pend.size(), false);
    for(size_t i = 2; i < jac.size(); ++i)
    {
        size_t hi = std::min(jac[i], pend.size());
        size_t lo = jac[i - 1];
        for (size_t idx = hi; idx > lo; --idx)
        {
            if (idx >= pend.size() || done [idx])
                continue;
            _insertDeque(main, pend[idx]);
            done[idx] = true; 
        }
    }
    for (size_t i = 0; i < pend.size(); ++i)
    {
        if (!done[i])
            _insertDeque(main, pend[i]);
    }
}

void PmergeMe::_sortDeque(std::deque<int>& v)
{
    if(v.size() < 2)
        return ;
    
    bool isOdd = (v.size() % 2 == 1);
    int  straggler = 0;
    if(isOdd)
    {
        straggler = v.back();
        v.pop_back();
    }
    std::deque<std::pair<int, int> > pairs = _buildPairs_dq(v);
    _sortPairs_dq(pairs);
    
    std::deque<int> main, pend;
    _buildChains_dq(pairs, main, pend);
    _insertPend_dq(main, pend);
    if(isOdd)
        _insertDeque(main, straggler);
    v = main;
}

//---------------------------------------------------------------------------------------------------------RUN
void	PmergeMe::run()
{
	printsequence("Before Vector:", _vec);
    printsequence("Before Deque :", _deq);

	std::clock_t	t0 = std::clock();
	_sortVector(_vec);
	std::clock_t	t1 = std::clock();
	double vecUs = static_cast<double>(t1 - t0) * 1e6/ CLOCKS_PER_SEC;

	std::clock_t	t2 = std::clock();
	_sortDeque(_deq);  
	std::clock_t	t3 = std::clock();
	double deqUs = static_cast<double>(t3 - t2) * 1e6 / CLOCKS_PER_SEC;
    
    std::cout << std::endl;
	printsequence("After Vector:", _vec);
    printsequence("After Deque :", _deq);
    
    if(isSorted(_deq))
    {
        std::cout << std::endl << "Deque:- sorted" << std::endl;
    }
    if(isSorted(_vec))
    {
        std::cout << "Vector:- sorted" << std::endl << std::endl;
    }
    
	std::cout << std::fixed << std::setprecision(5);
	std::cout << "Time to process a range of " << _vec.size()
	          << " elements with std::vector : " << vecUs << " us" << std::endl;
	std::cout << "Time to process a range of " << _deq.size()
	          << " elements with std::deque  : " << deqUs << " us" << std::endl;
    
}