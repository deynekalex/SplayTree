#include <iostream>
#include <cstdio>
#include <conio.h>
#include "tree.h"

using namespace std;

int main()
{
	typedef Node<1, nil, nil> root;
	typedef insert<2, root>::result node;
	typedef insert<-100, node>::result node100;

	cout << "Testing order" << endl;
	print<node100>();
	cout << endl;

	
	typedef insert<3, node>::result node1;
	typedef insert<-1, node1>::result node2;

	/*
	// print<node2>();
	// std::cout << "this" << " " << node2::data << std::endl;
	// std::cout << std::endl;
	// print<node1>();
	// std::cout << std::endl;
	// print<node>();
	// std::cout << std::endl;
	// print<root>();

	// typedef find_node<node2, -1>::result node3;
	// std::cout << std::endl;
	// std::cout << std::endl;
	// std::cout << node3::data << std::endl;
	//typedef delete_node<node2, 5>::result node4;
	//print<node4>();
	// std::cout << std::endl;
	// std::cout << std::endl;
	// std::cout << std::endl;
	// typedef delete_node<node2, -1>::result node3;
	// print<node3>();
	// std::cout << std::endl;
	// std::cout << std::endl;
	*/

	cout << "testing deletions" << endl;
	typedef delete_node<node2, -1>::result node3;
	print<node3>();
	cout << endl;
	typedef delete_node<node3, 2>::result node4;
	print<node4>();
	cout << endl;
	typedef delete_node<node4, 1>::result node5;
	print<node5>();
	cout << endl;
	cout << endl;

	cout << "Testing merging" << endl;
	
	cout << "left" << endl;

	print<node2>();

	
	
	cout << endl;

	cout << "right" << endl;
	typedef Node< -50, nil, nil> root2;
	typedef insert< -40, root2>::result node200;
	typedef insert< -200, node200>::result noder;
	print<noder>();
	cout << endl;

	typedef merge<noder, node2>::result nodeMerge;

	cout << "merged" << endl;
	print<nodeMerge>();
	cout << endl;

	

	_getch(); 
}

