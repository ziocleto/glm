///////////////////////////////////////////////////////////////////////////////////////////////////
// OpenGL Mathematics Copyright (c) 2005 - 2013 G-Truc Creation (www.g-truc.net)
///////////////////////////////////////////////////////////////////////////////////////////////////
// Created : 2013-03-21
// Updated : 2013-03-21
// Licence : This source is under MIT licence
// File    : test/core/core_amp.cpp
///////////////////////////////////////////////////////////////////////////////////////////////////

#include <iostream>
#include <amp.h>
#include <glm/glm.hpp>

using namespace concurrency; 

int test(int a, int b) restrict(amp, cpu)
{
	return a + b;
}

int main() 
{ 
	int v[11] = {'G', 'd', 'k', 'k', 'n', 31, 'v', 'n', 'q', 'k', 'c'};

	array_view<int> av(11, v); 
	parallel_for_each(av.extent, [=](index<1> idx) restrict(amp) 
	{
		av[idx] += 1; 
		av[idx] = glm::clamp(av[idx], 0, 255);
	});

	for(unsigned int i = 0; i < 11; i++) 
		std::cout << static_cast<char>(av[i]); 

	return 0;
}

