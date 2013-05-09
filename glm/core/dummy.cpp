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
#include <functional>
#include <thread>

#define square(X) X*X;

class base
{
public: 
	typedef void (base::*method)() const;

	method do_method;

	void (base::*do_print)() const;

	void call_print()
	{
		do_print = &base::print;
		(this->*do_print)();
	}

	void call_method()
	{
		do_method = &base::print;
		(this->*do_method)();
	}

	virtual void print() const {printf("B\n");}
};

template <typename T>
class tmpl
{
public:
	template <typename U>
	void print(U const & u) const
	{
		printf("tmpl::print()\n");
	}
};

class derived : public base
{
public: 
	virtual void print(){printf("D\n");}
};

template<typename T>
void test_tmpl()
{
	tmpl<T> Tmpl;
	Tmpl.template print<float>(76.f);
}

int test_class()
{
	base Base;
	Base.print();

	derived Derived;
	Derived.print();

	base & Ref = Derived;
	Ref.print();

	base * Ptr = &Derived;
	Ptr->print();

	auto Auto = std::bind(&derived::print, Derived);
	Auto();

	Base.do_print = &base::print;
	(Base.*Base.do_print)();
	Base.call_print();
	Base.call_method();
	(Base.*Base.do_method)();

	return 0;
}

void bind_print(int i)
{
	printf("bind_print: %d\n", i);
}

void bind_print2(int i, int j)
{
	printf("bind_print2: %d, %d\n", i, j);
}

using namespace std::placeholders; 

int test_bind()
{
	auto A = std::bind(bind_print, _1);
	A(76);

	auto B = std::bind(bind_print2, _1, _2);
	B(76, 82);

	return 0;
}

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

	{
		int* a[10];
		int (*b)[10];
		int c;
		int d[10];
		int e[5][10];
		int (*f)[5][10];

		a[0] = &c;
		b = &d;
		b = &e[0];
		f = &e;
	}

	test();
	test_class();
	test_bind();
	test_tmpl<float>();

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
	}

	//glm::vec3 v{0, 1, 2};
	return 0;
}
