// #include <stdio.h>
// #include <string.h>
// #include <stdlib.h>
// #include <cmath>
// char * GetMemeory(char *p)
// {
//     p = (char *)malloc(100);
// return p;
// }
// void Test() {
//     // char str2[] = "abcde";
//     // char *str = "chine";
//     // char *str = str2;
//     char *str = NULL;
//     str = GetMemeory(str);
//     //  str = (char *)malloc(100);
//     strcpy(str, "Thunder");
//     strcat(str + 5, "Downloader");
//     printf(str);
// }
// int main()
// {
//   int a,b,c,d=0;
//   char str1[4] = "123";
//   printf(str1);
//   printf("hello china");
//   a < b ? a : c < d ? c : d;
//     char arr[2][4];
//     strcpy (arr[0],"you");
//     strcpy (arr[1],"me");
//     // arr[0][3]='&';
//     printf("%s \n",arr);
//     Test();
//   return 0;
// }

#include <stdio.h>
#include <iostream>
using namespace std;
int main()
{
    // int i,j,t,n;
    // printf("please input n:");
    // scanf("%d",&n);
    // int a[n];
    // for(i=0;i<n;i++)
    // {
    // scanf("%d",&a[i]);
    // printf("\n");
    // }
    // int *p=a;
    // for(i=0;i<n-1;i++)
    // {
    //     for(j=0;j<n-1;j++)
    //     {
    //         if(*(p+j)>*(p+j+1))
    //         {
    //             t=*(p+j);
    //             *(p+j)=*(p+j+1);
    //             *(p+j+1)=t;
    //         }
    //     }
    // }
    // for(i=0;i<n;i++)
    //     printf("%5d",*(p+i));
    // int x = 3;
    // do
    // {
    //     cout << (x == 2) << "   ";
    // } while (!(--x));
    // char c = 129;
    // int i0 = c;
    // int i1 = (unsigned char)c;
    int k=1;
    int d = k--||k, k++;
    // printf("%d, %d\n", i0, i1);
    cout<<d;
    return 0;
}

// 暂停