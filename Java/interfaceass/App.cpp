/*
 *  Lassi Laitinen 2020
 */

#include <iostream>
#include <vector>

using namespace std;

class IntStack {
    public:
    virtual void push(int item);
    virtual int pop();
};

class OpenStack : public IntStack {
    public:
    virtual int ReadItem();
};

class FixedStack : public OpenStack {
    
    public:
    int pos;

    FixedStack(int size){
        m_vector.resize(size);
        pos = -1;
    };

    void push(int item){
        if(pos == m_vector.size() - 1) {
                cout << "Stack is full" << endl;
        } else {
            m_vector[++pos] = item;
        };
    };

    int pop(){
        if(pos < 0) {
            cout << "Stack underflow" << endl;
            return 0;
        } else {
            return m_vector[pos--];
        };
    };

    int ReadItem(){
        return m_vector[pos];
    };

    private:
    vector<int> m_vector;
};

int main(){
    FixedStack stack = FixedStack(7);

    stack.push(3);
    stack.push(2);
    stack.push(123);
    stack.push(355);

    cout << stack.pop() << endl;

    cout << stack.ReadItem() << endl;
};