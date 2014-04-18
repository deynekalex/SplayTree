#ifndef FIND_H
#define FIND_H
#include "if.h"
#include "splay.h"

//-------------------------------------------------------------
template <typename node, int value>
struct find_node;

template <typename node, int value>
struct find_next_node
{
	typedef typename If<(node::data > value), 
						typename find_node<typename node::left, value>::result, 
						typename find_node<typename node::right, value>::result 
					  >::result result;
};

//if there is no this in tree
template <int value>
struct find_node<nil, value>
{
	typedef nil result;
};

template <typename node, int value>
struct find_node
{
	typedef typename If<node::data == value, 
						node, 
						typename find_next_node<node, value>::result
					 >::result result;
};
//-------------------------------------------------------------

//finding and then splay
template <typename node, int value>
struct find_and_splay;

template <typename node, int value>
struct find_left
{
	typedef Node<node::data, typename find_and_splay<typename node::left, value>::result, typename node::right> result1;
	typedef typename splay_left<result1>::result result;
};

template <typename node, int value>
struct find_right
{
	typedef Node<node::data, typename node::left, typename find_and_splay<typename node::right, value>::result> result1;
	typedef typename splay_right<result1>::result result;
};


template <typename node, int value>
struct find_and_splay_next
{
	typedef typename If<(node::data > value),
						typename find_left<node, value>::result,
						typename find_right<node, value>::result
					 >::result result; 
};

template <int value>
struct find_and_splay<nil, value>
{
	typedef nil result;
};

template <typename node, int value>
struct find_and_splay
{
	typedef typename If<node::data == value,
						node,
						typename find_and_splay_next<node,value>::result
					  >::result result;
};
#endif