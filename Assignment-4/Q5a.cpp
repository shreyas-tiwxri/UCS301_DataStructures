#include<iostream>
#include<queue>
using namespace std;
class StackTwoQueues{
    queue<int> q1, q2;
    public:
    void push(int x){
        q1.push(x);
    }
    void pop(){
        if(q1.empty()){
            cout<<"Stack is empty. \n";
            return;
        }
    while(q1.size()>1){
        q2.push(q1.front());
        q1.pop();
    }
    cout<<"Popped: "<<q1.front()<<endl;
    q1.pop();
    swap(q1,q2);
    }
    int top(){
        if(q1.empty()){
            cout<<"Stack is empty. \n";
            return -1;
        }
        while(q1.size()>1){
            q2.push(q1.front());
            q1.pop();
        }
        int result = q1.front();
        q2.push(result);
        q1.pop();
        swap(q1,q2);
        return result;
    }
    bool empty(){
        return q1.empty();
    }
};
int main(){
    StackTwoQueues st;
    st.push(10);
    st.push(20);
    st.push(30);

    cout<<"Top: "<<st.top()<<endl;
    st.pop();
    cout<<"Top: "<<st.top()<<endl;
    st.pop();
    cout<<"Top: "<<st.top()<<endl;
    st.pop();
    st.pop();

    return 0;
}