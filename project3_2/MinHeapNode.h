#pragma once
#include "Common.h"

/*
This is a custom node that holds character and its frequency count
*/
class MinHeapNode
{
public:
	char cchar;  
	int count; 
	MinHeapNode *left, *right;

public:
	MinHeapNode(char cchar, int count)
	{
		this->left = NULL;
		this->right = NULL;
		this->cchar = cchar;
		this->count = count;
	}
};

