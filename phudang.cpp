#include <iostream>
#include <cmath>
using namespace std;
int getReady(int &HP,int ID,int &M, int E1)
{
  if (E1<100 || E1>500) return -999;
  else
    { double n =0;// biến kiểm tra nguyên
      int WP1  =300,WP2  =200;
      int MG  =190,dao  =300,thuong  =500;
      bool o = M%2;//biến kiểm tra chẵn lẻ
      if (HP >1000) HP  =1000;else if (HP<0) HP  =0;//reset
      if (M >1000) M  =1000; else if (M<0) M  =0;//reset
      if (E1 >=100 && E1 <=199) //---Trường hợp 1---
      {
        if (ID ==1) HP+=75;//nếu là vua mua 2 món đồ với giá 0 đồng
        else if  (ID==2) return HP+M;//nếu là Ngô Lương thì không mua
        else {
               int h=(E1-100)%64,J =HP%100;
               if (h<J && M>=WP2) //đủ đk phù hợp với vũ khí và tiền phải lơn hơn ít nhất là WP2
               {
                 if (!o)//thỏa số lẻ thì bán WP2
                 {
                   M-=WP2;
                   HP+=25;
                 }
                 else if(M>=WP1 && HP>=500) //thỏa số chẵn và lớn hơn WP1 thì bán WP1
                      {
                        M-=WP1;
                        HP+=50;
                      }
               }
             }
         cout <<HP<<" "<<M<<" "; //test
      }
      else if (E1>=200 && E1<=299 && M>=MG) //---Trường hợp 2---
           {
             int i =E1%4+1,MGi;//đòi mua MGi
             MGi=(i-1)*5+MG;//giá của món đồ thứ i
             if (M>MGi)
               if ((o&&i%2!=0)||(!(o||i%2!=0)) || ID==1|| ID==2) //phải thỏa điều kiện là tiền nhiều và lẻ nếu không phải là vua hoặc tướng
               {
                 M-=MGi;
                 HP =HP+5+2*(i-1);
               }
             cout <<HP<<" "<<M<<" "; //test
           }
      else if (E1>=300 && E1<=399 && HP>=600 && M>=dao) //---Trường hợp 3---
           {
             int a =E1%10,c =HP%10;
             if (a==2 || a==3 || a==5 || a==7) a*=2; else a =1;
             if (c==2 || c==3 || c==5 || c==7) //nếu là số nguyên tố tức muốn mua thương kiểm tra tiềm>thương
               if (M>=thuong)
               {
                 M-=thuong;
                 n=(double)HP+(double)(HP*2*a)*0.01;
               }
               else return HP+M;//nếu không lớn hơn kết thúc chương trình
             else {
                    M-=dao;
                    n=(double)HP+(double)(HP*a)*0.01;
                  }
             if (n!=(int)n) HP=(int)n+1; else HP=(int)n;
              cout <<HP<<" "; //test
                }
      else if(E1>=400 && E1<=499 && E1%5==0) //---Trường hợp 4---
           {
             n=(double)HP*0.9;
             if (n!=(int)n) HP=(int)n+1; else HP=(int)n;//kiểm tra nguyên
           }
      else if (E1==500) //---Trường hợp 5---
           {
             n=(double)HP/4;
             if (n!=(int)n) HP =(int)n+1; else HP =(int)n;//kiểm tra nguyên
             n=(double)M/4;
             if (n!=(int)n) HP =(int)n+1; else HP =(int)n;//kiểm tra nguyên
           }
      if (HP>1000) HP =1000;//reset
      cout <<HP<<" "<<M<<" "; //test

      return HP+M;
    }
}
int main()
{
    int a,b,c,d;
    cin>> a>>b>>c>>d;
    cout << getReady(a,b,c,d);
    return 0;
}

