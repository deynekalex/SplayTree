#ifndef ROTATIONS_H
#define ROTATIONS_H


//Node<value, left, right>

template <typename node>
struct left_rotation
{
	typedef Node<node::left::data, typename node::left::left, Node<node::data, typename node::left::right, typename node::right> > result; 
};

template <typename node>
struct right_rotation
{
	typedef Node<node::right::data, Node<node::data, typename node::left, typename node::right::left>, typename node::right::right> result;
};

#endif