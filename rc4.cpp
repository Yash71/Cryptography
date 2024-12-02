#include<bits/stdc++.h>
using namespace std;

int main(){
    int S[256];
    int K[256];

    int keySize = 0;
    cout<<"Enter the key size: ";
    cin>>keySize;

    int key[keySize];
    cout<<"Enter the key: ";
    for(int i = 0 ;i<keySize;i++){
        cin>>key[i];
    }

    // setup phase
    for(int i=0;i<256;i++){
        S[i] = i;
        K[i] = key[i % keySize];
    }
    // pseudo randomisation
    int j = 0;
    for(int i=0;i<256;i++){
        j = (j+S[i]+K[i]) % 256;
        swap(S[i],S[j]);
    }
    // continuous permutation of state, key gen and encryption
    int p(0),q(0),k(0);
    string plainText,cipherText;
    int keyStore[plainText.length()];
    cout<<"Enter the plain text: ";
    cin>>plainText;
    for(int i=0;i<plainText.length();i++){
        p = (p+1) %256;
        q = (q+S[p]) % 256;
        swap(S[p],S[q]);
        k = S[(S[p] + S[q]) % 256];
        keyStore[i] = k;
        cipherText+= char(int(plainText[i]) ^ k);
        
    }
    cout<<cipherText<<endl;
    
    // verification algo
    // for(int i=0;i<plainText.length();i++){
    //     cout<<keyStore[i] <<" ";
    //     cout<<(int(plainText[i]) ^ keyStore[i]) << " ";
    //     cout<<(int)(unsigned char)cipherText[i]<<endl;
    // }
    
    
    
    return 0;
}
