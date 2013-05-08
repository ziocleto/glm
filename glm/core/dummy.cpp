///////////////////////////////////////////////////////////////////////////////////
/// OpenGL Mathematics (glm.g-truc.net)
///
/// Copyright (c) 2005 - 2013 G-Truc Creation (www.g-truc.net)
/// Permission is hereby granted, free of charge, to any person obtaining a copy
/// of this software and associated documentation files (the "Software"), to deal
/// in the Software without restriction, including without limitation the rights
/// to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
/// copies of the Software, and to permit persons to whom the Software is
/// furnished to do so, subject to the following conditions:
/// 
/// The above copyright notice and this permission notice shall be included in
/// all copies or substantial portions of the Software.
/// 
/// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
/// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
/// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
/// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
/// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
/// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
/// THE SOFTWARE.
///
/// @ref core
/// @file glm/core/dummy.cpp
/// @date 2011-01-19 / 2011-06-15
/// @author Christophe Riccio
///
/// GLM is a header only library. There is nothing to compile. 
/// dummy.cpp exist only a wordaround for CMake file.
///////////////////////////////////////////////////////////////////////////////////

#define GLM_MESSAGES
#include "../glm.hpp"

#include <vector>
#include <cstdio>

#define square(X) X*X;

int test()
{
	int u = square(2 + 3);

	std::vector<int> v;
	for(int i = 0; i < 5; ++i)
		v.push_back(i);

	std::vector<int>::iterator itA = v.begin();
	std::vector<int>::iterator itB = v.begin();

	std::vector<int>::iterator itX = itA++;
	std::vector<int>::iterator itY = ++itB;

	return 0;
}

int main()
{
	//auto d = 90.0_deg;

	//int t = 2 * 3 % 10;

	int Error(0);

	test();
	{
		int (*ptr)[10];
		int* gni[10];

		int Array[10];

		ptr = &Array;
		gni[0] = &Array[0];
	}

	{
		int s1 = 3;
		int s2 = 3;

		int sA = s1++;
		int sB = ++s2;

		glm::ivec2 v1(3);
		glm::ivec2 v2(3);

		glm::ivec2 vA = v1++;
		glm::ivec2 vB = ++v2;

		Error += 0;
	}

	{
		int x = -2<<2;

		int j = 2;
		printf("%d, %d\n", ++j, ++j);

		Error += 0;

		char c=48;
		int i, mask=01;
		for(i=1; i<=5; i++)
		{
			printf("%c", c|mask);
			mask = mask<<1;
		}
		return 0;
	}

	//glm::vec3 v{0, 1, 2};
	return 0;
}
