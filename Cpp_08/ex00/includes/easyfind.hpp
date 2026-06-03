
#pragma once

#include <algorithm>
#include <iostream>
#include <iterator>
#include <stdexcept>

template <typename T> void easyfind(T &haystack, int needle) {
	typename T::iterator it;
	it = std::find(haystack.begin(), haystack.end(), needle);
	if (it != haystack.end())
    {
		std::cout << "Element found : [" << needle << "] at index " << std::distance(haystack.begin(), it) << std::endl;
	}
	else
	{
		throw std::out_of_range("No element found");
	}
}
