
#include "huffman.h"

using namespace std;

int main()
{
	int freq[128];
	char cchar[128];
	ifstream myfile("freq.txt");
	char ch;
	char arr[300];
	int ni = 0;
	string line;
	if (myfile.is_open()) {
		while (getline(myfile,line))
		{
			int position = line.find(" ");
			string temp =line.substr(0, position) ;
			if (temp=="LF" || temp=="lF" || temp == "Lf"|| temp=="lf") {
				cchar[ni] = 10;
			}
			else {
				cchar[ni] = line.substr(0, position)[0];
			}
			freq[ni]=stoi(line.substr(position + 1));
			ni++;
		}

	}
	ni--;

	for (int i = 0; i <= ni; i++)
		cout << (int)cchar[i] << "-" << freq[i] << endl;

	HuffmanCodes obj;
	obj.runHuffmanCodes(cchar, freq, ni + 1);
		//HuffmanCodes(cchar, freq, ni+1);
		int exit;
		cin >> exit;


	
		return 0;
}