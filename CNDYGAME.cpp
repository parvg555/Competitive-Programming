#include<bits/stdc++.h>
using namespace std;
#define m 1000000007

int seteven(int n){
    if(n%2==0){
        return n;
    }else{
        return n-1;
    }
}

int setodd(int n){
    if(n%2==0){
        return n-1;
    }else{
        return n;
    }
}

void swapvalues(int* p1, int* p2){
    int temp = *p1;
    *p1 = *p2;
    *p2 = temp;
}

int printans(int a[],int r, int n){
    bool counter1 = true;
    bool counter2 = false;
    int chef = 1;
    int chefu = 2;
    int chef1 = 0;
    int chef2 = 0;
    int turn = 1;
    int isselected = 0;
    int qotient = r/n;
    int rem = r%n;

    for(int i=0;i<r && i<n;i++){
        int max = a[((turn-1)%n)];
        int next = a[((turn)%n)];
        //cout<<"max - "<<max<<" next - "<<next<<endl;
        if(max == 1){
            isselected = max%m;
        }else{
            if(turn == r){
                isselected = max;
            }else if(turn == r-1 || turn%n == n-1){
                if(turn%n == 0){
                    isselected = setodd(max);
                }else{
                    isselected = seteven(max);
                }
            }else{
                if(turn%n == 0){
                    if(next == 1){
                        isselected = seteven(max);
                    }else{
                        isselected = setodd(max);
                    }
                }else{
                    if(next == 1){
                        isselected = setodd(max);
                    }else{
                        isselected = seteven(max);
                    }
                }
            }
        }

        //cout<<"isselected - "<<isselected<<endl;
        if(counter1 == true){
            if(chef == 1){
                chef1 = (chef1 + isselected)%m;
            }else{
                chef2 = (chef2 + isselected)%m;
            }
        }else{
            if(chef == 2){
                chef1  = (chef1 + isselected)%m;
            }else{
                chef2  = (chef2 + isselected)%m;
            }
        }

        if(isselected%2!=0){
            swap(chef,chefu);
        }
        if(turn%n==0){
            counter1 = !counter1;
            counter2 = !counter2;
        }
        turn++;
    }
    
    if(r>=n){
        return chef1;
    }else{
        chef1 = (qotient*chef1)%m;
        chef1 = (chef1 + printans(a,rem,n))%m;
        return chef1;
    }
   
}

void solve(){
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    int q;
    cin>>q;
    for(int i=0;i<q;i++){
        int r;
        cin>>r;
        int ans = printans(a,r,n);
        cout<<ans<<endl;
    }
}


int main(void){
    int t;
    cin>>t;
    while(t--){
        solve();
    }
}