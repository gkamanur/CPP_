/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkamanur <gkamanur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/27 18:07:38 by gkamanur          #+#    #+#             */
/*   Updated: 2026/04/27 18:34:22 by gkamanur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RPN_HPP
# define RPN_HPP

# include <string>
# include <stack>

/*
RPN (Reverse Polish Notation)
    - push every number
    - when you see an operator. pop the top two values, apply operator
        and push the result
        
//"3 4 +"  →  3 + 4 = 7
//"5 1 2 + 4 * + 3 -" → 14
*/
class RPN
{
    private:
        std::stack<int> _stack;
        
        bool _isoperator(char c) const;
        int _applyOp(int a, int b, char op) const;
        
    public:
        RPN();
        RPN(const RPN& other);
        RPN& operator=(const RPN& rhs);
        ~RPN();
        
        int evaluate(const std::string& expression);
};
#endif