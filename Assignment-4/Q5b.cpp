#include<iostream>
#include<queue>
using namespace std;
class StackOneQueue{
    queue<int> q;
public:
void push(int x){
    int size = q.size();
    q.push(x);

    for(int i = 0;i< size; i++){
        q.push(q.front());
        q.pop();
    }
}
void pop(){
    if(q.empty()){
        cout<<"Stack is empty."<<endl;
        return;
    }
    cout<<"Popped: "<<q.front()<<endl;
    q.pop();
}
int top(){
    if(q.empty()){
        cout<<"Stack is empty. \n";
        return -1;
    }
    return q.front();
}
bool empty(){
    return q.empty();
}
};
int main(){
    StackOneQueue st;
    st.push(10);
    st.push(20);
    st.push(30);

    cout << "Top: " << st.top() << endl;  
    st.pop();                             
    cout << "Top: " << st.top() << endl;  
    st.pop();                             
    cout << "Top: " << st.top() << endl;  
    st.pop();                             
    st.pop();                             

    return 0;
}