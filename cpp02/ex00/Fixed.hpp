/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpicchio <tpicchio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/30 11:47:58 by tpicchio          #+#    #+#             */
/*   Updated: 2024/08/30 12:02:20 by tpicchio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

#include <iostream>

class Fixed {

	private:
		int _value;
		static const int _fractional_bits = 8;

	public:
		Fixed(void);
		Fixed(const Fixed &src);
		~Fixed(void);

		Fixed &operator=(const Fixed &rhs);

		int getRawBits(void) const;
		void setRawBits(int const raw);
};

#endif