#include <iostream>
#include <fstream>
#include <string.h>
#include <cstring>
#include <unistd.h>

using namespace std;

int mod(int x, int y);
void encryption(char input[], int key);
void decryption(char input[], int key);

int main() {
	string temp = "";		//For print the file
	string dir = "";		//For input the directory of file
	ifstream myfile;		//Reading file
	int key = 0;			//Key for encryption and decryption

	cout << "Shift Cipher" << endl << endl;

	cout << "Input file location : ";
	getline(cin, dir);
	cout << "Input key : ";
	cin >> key;


	myfile.open (dir.c_str());

	if(myfile.is_open()) {
		while(!myfile.eof()) {
			getline(myfile, temp, '\0');
			cout << temp;
		}
	}
	cout << endl;

	myfile.close();

	char* c = new char[temp.length()+1];
	memcpy(c, temp.c_str(), temp.length()+1);

	cout << endl;
	usleep(10);
	cout << "Convert to char ..." << endl;
	cout << endl;

	cout << "Encryption result : "  << endl;
	encryption(c, key);
	cout << c;
	cout << endl;
	cout << "Decryption result : " << endl;
	decryption(c, key);
	cout << c;
	cout << endl;
	return 0;
}

//Used Functions
int mod(int x, int y) {
	return ((x % y) + y) % y;
}
void encryption(char input[], int key) {
	for(int i = 0; i < 200; i++) {
		if(input[i] != '\0') {
			char buffer;
			if(input[i] >= 'A' && input[i] <= 'Z') {
				buffer = mod((int)((input[i] - 'A') + key), 26);
				input[i] = buffer + 'A';
			}
			if(input[i] >= 'a' && input[i] <= 'z') {
				buffer = mod((int)((input[i] - 'a') + key), 26);
				input[i] = buffer + 'a';
			}
			else {
				continue;
			}
		}
		else {
			continue;
		}
	}
}
void decryption(char input[], int key) {
	for(int i = 0; i < 200; i++) {
		if(input[i] != '\0') {
			char buffer;
			if(input[i] >= 'A' && input[i] <= 'Z') {
				buffer = mod((int)((input[i] - 'A') - key), 26);
				input[i] = buffer + 'A';
			}
			if(input[i] >= 'a' && input[i] <= 'z') {
				buffer = mod((int)((input[i]- 'a') - key), 26);
				input[i] = buffer + 'a';
			}
			else {
				continue;
			}
		}
		else {
			continue;
		}
	}
}
