#ifndef MERGE_H
#define MERGE_H
#include "if.h"
#include "find.h"


template <typename node>
struct find_max_node;

template <typename node>
struct find_max_node
{
	typedef typename If<node::right::data != nil::data,
						typename find_max_node<typename node::right>::result,
						node
					  >::result result;
};

template<>
struct find_max_node<nil>
{
	typedef nil result;
};

template < typename left, typename right>
struct merge;

//right is bigger
template < typename left, typename right>
struct merge
{
	typedef typename find_max_node<left>::result max_node;
	typedef typename If<left::data != nil::data,
						typename find_and_splay<left, max_node::data>::result,
						right
					  >::result result1;
	typedef typename If<left::data != nil::data,
						Node<result1::data, typename result1::left, right>,
						result1>::result result;
};


#endif