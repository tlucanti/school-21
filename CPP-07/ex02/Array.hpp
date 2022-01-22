/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kostya <kostya@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/22 22:07:43 by kostya            #+#    #+#             */
/*   Updated: 2022/01/22 23:37:04 by kostya           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <stdexcept>
#include <sstream>

#include "defs.h"

namespace tlucanti
{
	template <typename Tp>
	class Array
	{
	public:
		typedef		Tp			value_type;
		typedef		Tp *		pointer;
		typedef		size_t		size_type;

		Array()
			: M_size(0)
		{
			M_impl = new value_type[0];
		}

		explicit Array(size_type _n)
			: M_size(_n)
		{
			M_impl = new value_type[_n];
		}

		Array(const Array<value_type> &cpy)
			: M_size(cpy.M_size)
		{
			M_impl = M_copy(cpy.M_impl, M_size);
		}

		~Array()
		{
			M_deallocate(M_impl);
		}

		Array &operator =(const Array<value_type> &cpy)
		{
			if (this == &cpy)
				return *this;
			M_deallocate(M_impl);
			M_size = cpy.M_size;
			M_impl = M_copy(cpy.M_impl, M_size);
			return *this;
		}

		__WUR value_type &operator[](size_type _i)
		{
			if (_i >= M_size)
				_throw_out_of_range(_i);
			return *(M_impl + _i);
		}

		__WUR size_type size()
		{
			return M_size;
		}

	private:

		pointer M_allocate(size_type _n)
		{
			return _n != 0 ? new value_type[_n] : nullptr;
		}

		pointer M_copy(pointer cpy, size_type size)
		{
			pointer M_tmp = M_allocate(size);
			for (size_type i=0; i < M_size; ++i)
				M_tmp[i] = cpy[i];
			return M_tmp;
		}

		void M_deallocate(pointer M_p)
		{
			delete [] M_p;
		}

		void _throw_out_of_range(size_type _i)
		{
			std::ostringstream ss;

			ss.clear();
			ss << "Out of Range error: Array::operator[]: _i (which is " <<
				_i << ") >= this->size() (which is " << M_size << ")";
			throw std::out_of_range(ss.str());
		}

		pointer		M_impl;
		size_type	M_size;
	};
}
