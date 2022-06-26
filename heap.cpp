#include<bits/stdc++.h>

using namespace std;

void ins(vector<int>& h, int val){
    h.push_back(val);
    int x=h.size()-1;
    while(x>0){
        if(h[x]>h[(x+1)/2 -1]){
            int temp=h[x];
            h[x]=h[(x+1)/2 -1];
            h[(x+1)/2 -1] = temp;
            x=(x+1)/2 - 1;
        }
        else return;
    }
} 

void del(vector<int>& h){
    int temp = h[0];
    h[0] = h[h.size()-1];
    h[h.size()-1]=temp;
    int x=0;
    h.pop_back();
    while(x<h.size()-2){
        if((x+1)*2 -1<h.size()-1 && h[x]<h[(x+1)*2 -1]){
            int temp=h[x];
            h[x] = h[(x+1)*2 -1];
            h[(x+1)*2 -1] = temp;
            x = (x+1)*2 -1;
        }
        else return;
    }
}

void hsr(vector<int>& h){
    int idx=h.size()-1;
    while(idx>0){
        int temp = h[0];
        h[0] = h[idx];
        h[idx]=temp;
        int x=0;
        while(x<idx){
            if((x+1)*2 -1<h.size()-1 && h[x]<h[(x+1)*2 -1]){
                int temp=h[x];
                h[x] = h[(x+1)*2 -1];
                h[(x+1)*2 -1] = temp;
                x = (x+1)*2 -1;
            }
            else break;
        }
        idx--;
    }
}

void printhp(vector<int>& h){
    cout<<endl;
    for(int i=0; i<h.size(); i++){
        cout<<h[i]<<" ";
    }
    cout<<endl;
}

int main(){
    vector<int> hp;
    int val;
    while(val!=0){
        cin>>val;
        ins(hp, val);
    }
    printhp(hp);
    hsr(hp);
    printhp(hp);
}
