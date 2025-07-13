/*

Program: This program will conduct a simple Caesar cipher to any enterted string
	
*/

#include <iostream>
using namespace std;

// converts character array to string and returns it
// may be helpful going from c-string to a string for using string functions
string convertToString(char * a, int size)
{
    int i;
    string s = "";
    for (i = 0; i < size; i++) {
        s = s + a[i];
    }
    return s;
}

// convert each character and return it to be added to a string or character array
// if c is not a letter, return it unchanged
char convert(char c, int key) {

    if ( c >= 'A' && c <= 'Z'){
        return (c - 'A' + key) % 26 + 'A';
    }

    if ( c >= 'a' && c <= 'z'){
        return (c - 'a' + key) % 26 + 'a';
    }

    return c;  
} // convert


int main() {

	// get the plain text message
	// This is necessary to get a whole line that may include spaces. STARTER CODE!
	string plain_text = "";
    cout << "Enter the message to be encrypted:" << endl;
	getline(cin, plain_text);
	
	// get the desired key (positive number)
    int key; 
    cout << "Enter the number of positions to shift (positive number):  ";
    cin >> key;
	
    int n = plain_text.length(); 

    char message[n + 1];
	// convert each character of the message and save it into a  char array or string
	for(int i = 0; i < n; i++){
        char letter  = convert(plain_text[i], key);

        message[i] = letter;

        message[n] = '\0';
    }

    string message_s = convertToString(message,n + 1);
	// print both the original and encrypted messages

    cout << "Before encryption: " << plain_text << endl;

    cout << "After encryption: " << message_s << endl;

	return 0;
}
