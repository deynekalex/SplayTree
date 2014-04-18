#ifndef IS_NIL_H
#define IS_NIL_H
#include "node.h"

template <typename node>
struct is_nil;

template <>
struct is_nil<nil>
{
	static const bool result = true;
};

template <typename node>
struct is_nil
{
	static const bool result = false;
};


#endif