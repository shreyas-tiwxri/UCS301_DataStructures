//a
// #include<iostream>
// #include<string>
// using namespace std;
// int main(){
//     string str1 = "Shreyas ";
//     string str2 = " Tiwari";
//     string result = str1 + str2;
//     cout<<result<<endl;
// }

//b
// #include<iostream>
// #include<string>
// #include<algorithm>
// using namespace std;
// int main(){
//     string str = "Hello world!";
//     reverse(str.begin(), str.end());
//     cout<<"Reversed string: "<<str<<endl;
// }

//c
// #include<iostream>
// #include<string>
// #include<algorithm>
// using namespace std;
// bool isVowel(char ch){
//     ch = tolower(ch);
//     return(ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u');
// }
// int main(){
//     string str = "My name is Shreyas";
//     string result;
//     for(char ch : str){
//         if(!isVowel(ch)){
//             result += ch;
//         }
//     }
//     cout<<"String without vowels: "<<result<<endl; 
// }

//d
// #include<iostream>
// #include<vector>
// #include<algorithm>
// using namespace std;
// int main(){
//     vector<string> words = {"banana", "apple", "watermelon", "grape", "peach"};
//     sort(words.begin(), words.end());
//     cout<<"Stored strings: "<<endl;
//     for(const string&word : words){
//         cout<<word<<endl;
//     }
// }

//e
#include<iostream>
using namespace std;
int main(){
    char ch;
    cout<<"Enter an uppercase character: "<<endl;
    cin>>ch;
    if(ch >= 'A' && ch<= 'Z'){
        char lower = ch + 32;
        cout<<"Lowercase: "<<lower<<endl;
    }
    else{
        cout<<"Invalid input."<<endl;
    }
}