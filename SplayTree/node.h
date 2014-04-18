#ifndef NODE_H
#define NODE_H

#define INF 1000000000

template < int value, typename Left, typename Right>
struct Node
{
	static const int data = value;
	typedef Left left;
	typedef Right right;
};

struct nil
{
	static const int data = -INF;
	typedef nil left;
	typedef nil right;
};

#endif