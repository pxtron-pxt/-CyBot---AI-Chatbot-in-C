#include<stdio.h>
#include<string.h>

int  main()
{
char str[100];
int length = 0;
printf("Enter the string:");
gets(str);
while (str[length]!='\0'){
length++;
}
printf("Length of the string:%d\n",strlen(str));
return 0;
}
