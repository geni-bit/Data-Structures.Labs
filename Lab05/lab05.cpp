/*

Program: To check if a string is a palindrome using Stack and Queue.

*/

#include <iostream>
#include <string>
#include <cctype> 

using namespace std; 

const int MAX_SIZE = 50;

//Stack Class for charcters
class Stack{
    private:
        int top_i;
        char arr[MAX_SIZE];

    public:
        Stack(){
            top_i = -1;
        }

    bool isEmpty(){
        return top_i == -1;
    }

    bool push(char letter){
        if (top_i >= MAX_SIZE -1){
            return false;
        }

        top_i = top_i + 1;

        arr[top_i] = letter; 

        return true;
    }

    char pop(){
        if(isEmpty()){
            return '\0';
        }
        char res =  arr[top_i];

        top_i = top_i - 1;

        return res;
    }

    int size(){
        return top_i + 1;
    }

    char top() {
        if (!isEmpty()) {
            return arr[top_i];  
        }
        return '\0';
    }

};

// Queue class to handle the characters 
class Queue{
    private:
        int front;
        int back; 
        int count;
        char arr[MAX_SIZE];
    
    public: 
        Queue(){
            front = 0;
            count = 0;
            back = MAX_SIZE - 1;
        }

        bool isEmpty(){
            return count == 0;
        }

        bool enqueue(char c){
            if(count == MAX_SIZE){
                return false;
            }

            back = (back + 1) % MAX_SIZE;

            arr[back] = c;

            count = count + 1;

            return true; 
        }

        char dequeue(){
            if(isEmpty()){
                return '\0';
            }

            char val = arr[front];

            front = (front + 1) % MAX_SIZE;

            count = count - 1;

            return val;
        }

        int size(){
            return count;
        }
};

bool isPalindrome(string pharse) {
    Stack s;  
    Queue q;

    for (size_t i = 0; i < pharse.length(); i++) {
        char pan_c = pharse[i];

        if (isalpha(pan_c)){
       
            char lowerChar = tolower(pan_c);
        
            s.push(lowerChar);
        
            q.enqueue(lowerChar);
        }

    }

    while (!s.isEmpty()) {
        if (s.pop() != q.dequeue()) {
            return false; 
        }
    }
    
    return true;
    
}

int main() {

    cout << "Test1 (Palindrome): Was it a cat I saw?" << endl;
    
    bool test1 = isPalindrome("Was it a cat I saw?");

    cout << "Test2 (Palindrome): Slime Not!" << endl;

    bool test2 = isPalindrome("Slime Not!");


    if (test1) {
        cout << "'Was it a cat I saw' is a palindrome!" << endl;
    } else {
        cout << "'Was it a cat I saw' is not a palindrome." << endl;
    }

    if (test2) {
        cout << "'Slime Not!' is a palindrome!" << endl;
    } else {
        cout << "'Slime Not!' is not a palindrome." << endl;
    }

    string user_input; 

    cout << "Enter a pharse: " << endl;

    getline(cin,user_input);

    if (isPalindrome(user_input)) {
        cout << "'"<< user_input << "'"<< " is a palindrome!" << endl;
    } else {
        cout << "'"<< user_input << "'"<< " is not a palindrome." << endl;
    }

    return 0;
}
