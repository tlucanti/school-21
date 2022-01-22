/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kostya <kostya@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/22 18:14:42 by kostya            #+#    #+#             */
/*   Updated: 2022/01/22 18:35:08 by kostya           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#if __cplusplus <= 199711L
# include <stdint.h>
#endif

namespace tlucanti
{
	struct Data
	{
		void	*data;
	};

	uintptr_t serialize(Data *ptr)
	{
		return reinterpret_cast<uintptr_t>(ptr);
	}

	Data *deserialize(uintptr_t raw)
	{
		return reinterpret_cast<Data *>(raw);
	}
}

int main()
{
	tlucanti::Data	data;
	data.data = (void *)0x4135;

	uintptr_t raw = tlucanti::serialize(&data);
	tlucanti::Data *ptr = tlucanti::deserialize(raw);

	std::cout << std::boolalpha;
	std::cout << "serialized value: " << raw << std::endl;
	std::cout << "pointer value: " << ptr << " == " << &data << " (" <<
		(ptr == &data) << ")\n";
	std::cout << "member value: " << data.data << " == " << ptr->data << " (" <<
		(data.data == ptr->data) << ")\n";
}
