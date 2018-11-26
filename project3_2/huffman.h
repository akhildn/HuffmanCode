#include "Common.h"
#include "MinHeap.h"
#include "MinHeapNode.h"


class HuffmanCodes {

public:
	ofstream ofile;

public:
	void swap(MinHeapNode** a, MinHeapNode** b)
	{
		MinHeapNode* t = *a;
		*a = *b;
		*b = t;
	}
	void minHeapify(MinHeap* minHeap, int index)
	{
		int svIndex = index;
		int left = 2 * index + 1;
		int right = 2 * index + 2;

		if (left < minHeap->currentHeapSize &&
			minHeap->heap[left]->count < minHeap->heap[svIndex]->count)
			svIndex = left;

		if (right < minHeap->currentHeapSize &&
			minHeap->heap[right]->count < minHeap->heap[svIndex]->count)
			svIndex = right;

		if (svIndex != index)
		{
			swap(&minHeap->heap[svIndex], &minHeap->heap[index]);
			minHeapify(minHeap, svIndex);
		}
	}

	
	MinHeapNode* getMinNode(MinHeap* minHeap)
	{
		MinHeapNode* minNode = minHeap->heap[0];
		minHeap->heap[0] = minHeap->heap[minHeap->currentHeapSize - 1];
		minHeap->currentHeapSize--;
		minHeapify(minHeap, 0);
		return minNode;
	}

	void insertMinHeap(MinHeap* minHeap, MinHeapNode* minHeapNode)
	{
		minHeap->currentHeapSize++;
		int i = minHeap->currentHeapSize - 1;
		while (i && minHeapNode->count < minHeap->heap[(i - 1) / 2]->count)
		{
			minHeap->heap[i] = minHeap->heap[(i - 1) / 2];
			i = (i - 1) / 2;
		}
		minHeap->heap[i] = minHeapNode;
	}
	
	MinHeapNode* buildHuffmanTree(char cchar[], int count[], int currentHeapSize)
	{
		MinHeapNode *left, *right, *top;
		MinHeap* minHeap = new MinHeap(currentHeapSize);
		for (int i = 0; i < currentHeapSize; ++i)
			minHeap->heap[i] = new MinHeapNode(cchar[i], count[i]);
		
		minHeap->currentHeapSize = currentHeapSize;

		int start = minHeap->currentHeapSize - 1;
		for (int i = (start - 1) / 2; i >= 0; i--)
			minHeapify(minHeap, i);

		while (minHeap->currentHeapSize != 1)
		{
			left = getMinNode(minHeap);
			right = getMinNode(minHeap);

			top = new MinHeapNode(' ', left->count + right->count);
			top->left = left;
			top->right = right;
			insertMinHeap(minHeap, top);
		}

		return getMinNode(minHeap);
	}


	void codeTable(MinHeapNode* root, string str)
	{
		if (!root)
			return;

		if (root->left == NULL || root->right == NULL) {
			if ((int)root->cchar == 10) {
				ofile << "LF" << ": " << str << "\n";
			}
			else {
				ofile << root->cchar << ": " << str << "\n";
			}
			
			}

			codeTable(root->left, str + "0");
			codeTable(root->right, str + "1");
		}


	void runHuffmanCodes(char cchar[], int count[], int currentHeapSize)
	{
		ofile.open("codetable.txt");
		MinHeapNode* root = buildHuffmanTree(cchar, count, currentHeapSize);
		int arr[128], top = 0;
		char* code = "";
		codeTable(root,code);
		ofile.close();
		cout << "codetable.txt created" << endl;
	}
};


