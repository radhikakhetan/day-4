#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <algorithm>
#include <fstream>
using namespace std;

const int NCHAR = 26;

void populateMap(string , map<int,string > & );
void printScoreMap(map<int,string> );
void fillWeightArray(int [] );
int scoreOfString(string , const int [] );


int main() {
	map<int,string> scoreToWordMap;
	populateMap("words.txt", scoreToWordMap);
	printScoreMap(scoreToWordMap);
}


void populateMap(string fileName, map<int,string> &scoreMap) {
	ifstream inputFile(fileName.c_str());
	string line;
	int currScore = 0;
	int alphaScoreArray[NCHAR];
	fillWeightArray(alphaScoreArray);
	
	while (inputFile >> line) {
		currScore = scoreOfString(line, alphaScoreArray);
		
		if (scoreMap.find(currScore) == scoreMap.end()) {
			scoreMap[currScore]	= "";
		}
		scoreMap[currScore]+=(line +" ");
	}
}

int scoreOfString(string str, const int alphaWeight[] ) {
	int wordScore = 0;

	for (unsigned int i = 0; i < str.length(); ++i) {
		int index = toupper(str[i])-'A';
		wordScore+=alphaWeight[index];
	}

	return wordScore;
}

void fillWeightArray(int alphaWeight[] ) {
	for (int i = 0; i < NCHAR; ++i) {
		alphaWeight[i] = i+1;
	}
}


void printScoreMap(map<int, string > scoreMap)
{
	for (map<int,string>::iterator mapit=scoreMap.begin(); mapit!=scoreMap.end(); ++mapit)
	cout << mapit -> first << " : "<< mapit -> second ;
	cout << endl;
}
