#include <iostream>
#include <vector>

using namespace std;
struct data{
    float d;
    float w;

    data(float d, float w): d(d), w(w){}
};

void swap(vector<data> & v, int i, int j){ data t = v[i]; v[i] = v[j]; v[j] = t; }
float w_median(vector<data> & v, int s, int e){
    if(s > e) return -1;
    if(s == e) return v[s].d;
    if((e-s) == 1)
        if(v[s].w >= v[e].w) return v[s].d;
        else return v[e].d;

    float p = v[e].d;
    int i = s-1;
    int j=s;

    for(; j<e; ++j){
        if(v[j].d <= p)
            swap(v, ++i, j);
    }

    swap(v, ++i, e);
    
    float wl=0, wr=0;
    for(j=s; j<i; ++j)
        wl+=v[j].d;

    for(j=i+1; j<=e; ++j)
        wr+=v[j].d;

    if(wl<0.5 && wr<0.5) return v[i].d;
    else{
        if(wl>wr){ v[i].w += wr; return w_median(v, s, i);}
        else{ v[i].w += wl; return w_median(v, i, e);}
    }
}


int main(){
    vector<data> v;
    v.push_back(data(0.1,0.1));
    v.push_back(data(0.35,0.35));
    v.push_back(data(0.05,0.05));
    v.push_back(data(0.1,0.1));
    v.push_back(data(0.15,0.15));
    v.push_back(data(0.05,0.05));
    v.push_back(data(0.2,0.2));

    float m = w_median(v, 0, v.size()-1);
    cout<<m;

}
