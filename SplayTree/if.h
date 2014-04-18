#ifndef IF_H
#define IF_H

template <bool request, typename first, typename second>
struct If;
//------------------------

template <typename first, typename second>
struct If <true, first, second>
{
	typedef first result;
};

template <typename first, typename second>
struct If <false, first, second>
{
	typedef second result;
};


#endif