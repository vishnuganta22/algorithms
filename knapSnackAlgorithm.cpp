#include <iostream>
#include <cstring>
#include <math.h>

using namespace std;

long generateHash(string q, int size){
	long hashCode = 0;
	for(int i = 0; i < size; i++){
		hashCode += ((int(q[i]) - 96) * pow(24, size - i - 1));
	}
	return hashCode;
}

bool checkIfMatched(string mString, int mLength, string qString, int qLength, int start){
	bool isMatched = true;
	int j = 0;
	for(int i = start; i < start + qLength; i++){
		isMatched = isMatched && mString[i] == qString[j];
		if(!isMatched) return isMatched;
		j++;
	}
	return isMatched;
}

int findMatch(string mString, int mLength, string qString, int qLength, long hashCode){
	int count = 0;
	long sHash = 0;
	long temp = pow(24, qLength - 1);
	long fHash = ((int(mString[0]) - 96) * temp);
	for(int i = 0; i < qLength; i++){
		sHash += ((int(mString[i]) - 96) * pow(24, qLength - i - 1));
	}
	for(int i = 0; i < mLength - qLength; i++){
		if(hashCode == sHash && checkIfMatched(mString, mLength, qString, qLength, i)) count++;
		sHash = ((sHash - fHash) * 24) + (int(mString[i + qLength]) - 96);
		fHash = (int(mString[i + 1]) - 96) * temp; 
	}
	return count;
}

int main(){
	string mString, qString;
	cin>>mString>>qString;
	int mLength = mString.length();
	int qLength = qString.length();
	long hashCode = generateHash(qString, qLength);
	int count = findMatch(mString, mLength, qString, qLength, hashCode);
	cout<<"Count :: "<<count<<endl;
	return 0;
}