// #include <iostream>
// using namespace std;
// class animal
// {
// protected:
//     int age;
// public:
//     virtual void print_age(void) = 0;
// };
// class dog : public animal
// {
// public:
//     dog()
//     {
//         this->age = 2;
//     }
//     ~dog() {}
//     virtual void print_age(void)
//     {
//         cout << "wang. my age=" << this->age << endl;
//     }
// };
// class cat:public animal
// {
// public :
//     cat()
//     {
//         this->age = 1;
//     }
//     ~cat() {}
//     virtual void print_age(void)
//     {
//         cout << " Miao,my age= " << this->age << endl;
//     }
// };
// int main(void)
// {
//     cat kitty;
//     dog jd;
//     animal *pa;
//     pa = &kitty;
//     pa->print_age();
//     return 0;
// }

// #include "stdio.h"
// class A
// {
// public:
//     int _a;
//     A()
//     {
//         _a = 1;
//     }
//     void print()
//     {
//         printf("%d", _a);
//     }
// };
// class B: public A
// {
// public:
//     int _a;
//     B()
//     {
//         _a = 2;
//     }
// };
// int main()
// {
//     B b;
//     b.print();
//     printf("%d", b._a);
// }

// #include<bits/stdc++.h>
// using namespace std;
// vector<int>g[10];
// int ans = 0;
// void dfs(int x){
//     if(g[x].size() == 0){
//         ans++;
//         return;
//     }
//     for(int i = 0; i < g[x].size(); ++i){
//         dfs(g[x][i]);
//     }
// }
// int main(){
//     int n, x;
//     cout<<"请输入个数：";
//     scanf("%d", &n);
//     for(int i = 2; i <= n; ++i){
//         scanf("%d", &x);
//         g[x].push_back(i);
//     }
//     dfs(1);
//     cout<<ans<<endl;
//     return 0;
// }

// #include <iostream>
// using namespace std;
// class A {
// public :
//     void run(void) {
//         cout << "run()" << endl;
//     }
//     void run(int a){
//         cout << "run(A)" << endl;
//     }
// };
// class B : public A {
// public :
//     void run(int a) {
//         cout << "run(B)" << endl;
//     }
// };
// int main(void){
//     B b;
//     b.run(0);//语句1
//     b.A::run(1); //语句2
//     //b.run(); //语句3，问题语句
//     b.A::run(); //语句4
//     return 0;
// }

#include <iostream>
#include <fstream>
using namespace std;

void (*function)(float);
void One(float one) { cout << "1" << endl; }
void Two(float two) { cout << "2" << endl; }
void Three(float three) { cout << "3" << endl; }
int main() {
    float i = 1, j = 2, k = 3;
    function = One;
    function(i);
    function = Two;
    function(j);
    function = Three;
    function(k);
    cout<<sizeof(void)<<endl;
    const char * node="ABC";
    int a = 4;
    cout<<a;
    fstream fs;



}













































































//暂停