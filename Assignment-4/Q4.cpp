#include<iostream>
using namespace std;
class Queue{
    char arr[50];
    int front, rear;
    public:
    Queue(){
        front = 0;
        rear = - 1;
    }
    void enqueue(char x){
        rear++ ;
        arr[rear] = x;
    }
    void dequeue(){
        if(!isEmpty()){
            front++ ;
        }
    }
    char getfront(){
        if(!isEmpty())
        return arr[front];
    return '\0';
    }
    bool isEmpty(){
        return front > rear;
    }
};
void firstnonrepeating(string str){
    int freq[256] = {0};
    Queue q;

    for(char ch:str){
        freq[(int)ch]++;
        q.enqueue(ch);
        while(!q.isEmpty() && freq[(int)q.getfront()]>1){
            q.dequeue();
        }
        if(q.isEmpty()){
            cout<< -1 <<" ";
        }
        else{
            cout<<q.getfront()<<" ";
        }
    }
    cout<<endl;
}
int main(){
    string s = "aabc";
    cout<<"Input: "<<s<<endl;
    cout<<"Output: "<<endl;
    firstnonrepeating(s);
    return 0;
}