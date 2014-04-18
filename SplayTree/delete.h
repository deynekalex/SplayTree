#ifndef DELETE_H
#define DElETE_H
#include "find.h"
#include "if.h"
#include "is_nil.h"
#include "merge.h"

template <typename node, int value>
struct delete_node
{
	typedef typename find_and_splay<node, value>::result result2;
	typedef typename merge<typename result2::left, typename result2::right>::result result;
};

#endif