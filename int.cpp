#include <iostream>
#include <vector>
#include <string>
#include<algorithm>
using namespace std;

int maxval(vector<int>Ar){
    int max=Ar[0];
    for(int i = 0 ; i<Ar.size();i++){

    if(Ar[i]>max){
        max = Ar[i];
    }
   

}
return max;
}
int minval(vector<int>A){
    int min=A[0];
    int b=0;
    for (int a = 0 ; a<A.size();a++){
        if(A[a]==maxval(A)){
            b=a;}
        }
    for (int i = 0 ; i<A.size();i++){

    if(A[i]<min&&b>i){
       
        min = A[i];
    }
}
return min;
}
int hodlr(vector<int>S){
    int max = maxval(S);
    int min = minval(S);
    return max-min;
    
}

int sell(vector<int>&as, int &profit, int &index, int &lot);
int buyy(vector<int>&as, int &profit, int &index,int &lot, bool &flag ){
        
        if(index+1<as.size()){
            
            if(flag == false){
                
                if(as[index]<as[index+1]){
                    profit -= as[index];
                    lot = 1;
                    
                    cout<<" I bought "<<index<<". day. And current profit: "<< profit<<" number of lots "<<lot<<endl;
                    index++;
                    
                    flag =true;
                    sell(as,profit,index,lot);
                    
                    
                }
                else{
                    profit-=as[index+1];
                    lot=1;
                    
                    cout<<" I bought "<<index+1<<". day. And current profit: "<< profit<<" number of lots "<<lot<<endl;
                    index +=2;
                  
                    flag =true;
                    sell(as,profit,index,lot);
                }
            }

            else{ 
                if(as[index]<as[index+1]){
                lot = profit / as[index];
                profit = profit % as[index];
                cout<<" I bought "<<index<<". day. And current profit: "<< profit<<" number of lots "<< lot<<endl;
                index++;
                
                sell(as,profit,index,lot);
            }
            else{
                lot = profit / as[index+1];
                profit = profit % as[index+1];
                cout<<" I bought "<<index+1<<". day. And current profit: "<< profit<<" number of lots "<<lot<<endl;
                index+=2;

                sell(as,profit,index,lot);
            }
            }
        }
        else{
            return sell(as,profit,index,lot);}

            
}
int sell(vector<int>&as, int &profit, int &index, int &lot){
    bool flag = true;
    if(index<as.size()){
        if(as[index]>as[index+1]){
                profit = profit + (lot * as[index]);
                lot = 0;
                cout<<" I sold "<<index<<". day. And current profit: "<< profit<<endl;
                index++;
                
                buyy(as,profit,index,lot,flag);
            }
            else{
                profit = profit + (lot * as[index+1]);
                lot= 0;
                cout<<" I sold "<<index+1<<". day. And current profit: "<< profit<<endl;
                index+=2;
                buyy(as,profit,index,lot,flag);
            }
    }
   return profit;

}
int daily_trader(vector<int>d){
    bool flag = false;
    int buy=0;
    int profit=0;
    int lot=0;
    int result = 0;
    result = buyy(d,profit,buy,lot,flag);
    return result;
}


int main(){



vector<int> arr={100,50, 200, 400, 20, 60, 10, 90, 300, 200};
vector<int> arr2={20,30, 40, 10, 5, 80, 100, 60};
vector<int> arr3={20, 10, 5, 30, 60, 90, 40, 50};
vector<int> arr4={20, 5, 15, 35, 10, 50, 80, 40};



 

int b = hodlr(arr4);

int a = daily_trader(arr4);

if(a>b){cout<<" Maximum profit: "<< a;}
else{cout<<" Maximum profit: "<< b;}


return 0;

}