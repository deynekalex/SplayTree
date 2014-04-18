#ifndef PRINT_H
#define PRINT_H

template < typename node >
void print();

template<>
void print <nil>() {}

template < typename node >
void print()
{
	print<typename node::left>();
	std::cout << node::data << " ";
	print<typename node::right>();
}

#endif