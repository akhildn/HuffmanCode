#pragma once
#include "Common.h"
#include "MinHeapNode.h"

class MinHeap
{
public:
	int currentHeapSize;    
	int maxHeapSize;   
	MinHeapNode **heap;  
	private:
		MinHeap() {

	}

public:
	MinHeap(int maxHeapSize)
	{
		this->currentHeapSize = 0; 
		this->maxHeapSize = maxHeapSize;
		this->heap = new MinHeapNode*[maxHeapSize];
	}
};
