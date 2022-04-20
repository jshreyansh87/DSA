#include <bits/stdc++.h>
using namespace std;

class Stack{
    public:
        int *arr;
        int size;
        int top;

        Stack(int size){
            this -> size = size;
            top = -1;
            arr = new int[size];
        }

        void push(int ele){
            if(size - top > 1){
                top++;
                arr[top] = ele;
            }
            else{
                cout << "Stack Overflow" << endl;
            }
        }

        void pop(){
            if(top >= 0){
                int ans = arr[top];
                top--;
            }
            else{
                cout << "Stack Underflow" << endl;
            }
        }

        int peek(){
            if(top >= 0){
                return arr[top];
            }
            else{
                cout << "Stack is empty" << endl;
            }

            return -1;
        }

        bool isEmpty(){
            if(top >= 0){
                return false;
            }

            return true;
        }
};

int main(){
    
    Stack st(4);

    st.push(4);
    st.push(9);
    st.push(2);
    st.push(3);
    st.push(1);

    cout << st.peek() << endl;

    st.pop();
    st.pop();

    cout << st.peek() << endl;

    if(st.isEmpty()){
        cout << "Stack was empty" << endl;
    }
    else{
        cout << "Stack is not empty" << endl;
    }

    return 0;
}