// treetest.cpp
// (C) 2014 splashinn

#include "tree.h"
#include <iostream>

template<class T>
void print(Tree<T> const & t, int offset = 0)
{
	if (!t.isEmpty())
	{
		for (int i = 0; i < offset; ++i)
			std::cout << " ";
		std::cout << t.root() << std::endl;
		print(t.left(), offset);
		print(t.right(), offset + 4);
	}
}

void testHigher()
{
	Tree<int> t0;
	auto t = t0.insert(2).insert(4).insert(3).insert(5).insert(6).insert(1);
	forEach(t, [](int x)
	{
		std::cout << x << " ";
	});
	std::cout << std::endl;
}

void testInit()
{
	Tree<int> t{ 50, 40, 30, 10, 20, 30, 100, 0, 45, 55, 25, 15 };
	forEach(t, [](int x)
	{
		std::cout << x << " ";
	});
	std::cout << std::endl;
}

void main()
{
	testInit();
	auto t = Tree<int>().insert(2).insert(4).insert(3).insert(5).insert(6).insert(1);
	std::cout << "Is member 1? " << t.member(1) << std::endl;
	std::cout << "Is member 10? " << t.member(10) << std::endl;

	testHigher();
}
