#ifndef SPLAY_H
#define SPLAY_H
#include "if.h"
#include "rotations.h"

template <typename node>
struct splay_left
{
	typedef typename left_rotation<node>::result result;
};

template <typename node>
struct splay_right
{
	typedef typename right_rotation<node>::result result;
};


#endif