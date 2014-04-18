#ifndef insert_H
#define insert_H
#include "node.h"
#include "rotations.h"
#include "splay.h"
#include "if.h"
//------------------------
template <int value, typename node>
struct insert;


template <int value, typename node>
struct insert_left
{
	typedef Node<node::data, typename insert<value, typename node::left>::result, typename node::right> result1;
	typedef typename splay_left<result1>::result result;
};

template <int value,typename node>
struct insert_right
{
	typedef  Node<node::data, typename node::left, typename insert<value, typename node::right>::result> result1;
	typedef typename splay_right<result1>::result result;
};


template <int value> 
struct insert <value,nil>
{
	typedef Node <value,nil,nil> result;
};

//if<condition, if_true, if_false>
template < int value, typename node>
struct insert
{
	typedef typename If<(value < node::data), 
						typename insert_left<value,node>::result, 
						typename insert_right<value,node>::result
					  >::result result;		
};

#endif