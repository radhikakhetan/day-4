#include <iostream>
#include <string>

using namespace std;

const int NCHAR = 26;

int score(string , const int [] );
void fillWeigthArray(int [] );

int main(int argc, char **argv) {

	if(argc < 3) {
		cerr << "USAGE " << argv[0] << " INPUTFILE OUTPUTFILE" << endl;
		return -1;
	}

	string inputFile = argv[1];
	string outputFile = argv[2];


	int alphaWeight[NCHAR];
	fillWeigthArray(alphaWeight);
	string str = "aZ";
	cout<<score(str,alphaWeight);

}



int score(string str, const int alphaWeight[] ) {
	int wordScore = 0;

	for (unsigned int i = 0; i < str.length(); ++i) {
		int index = toupper(str[i])-'A';
		wordScore+=alphaWeight[index];
	}

	return wordScore;
}

void fillWeigthArray(int alphaWeight[] ) {
	for (int i = 0; i < NCHAR; ++i) {
		alphaWeight[i] = i+1;
	}
}
