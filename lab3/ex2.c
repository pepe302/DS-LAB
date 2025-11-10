//string functions without string handling functions

#include<stdio.h>

int str_len(char s[]){
    int n=0;
    int i=0;    
    while(s[i]!='\0'){
        n++;
        i++;
    }
    return n;
}

void concatenate(char s[],int n){
    for(int i=0;i<n;i++){
        if(s[i]==' '){
            for(int j=i;j<n;j++){
                s[j]=s[j+1];
            }
        }
    }
    printf("\nconcatenated string: %s",s);
}

int compare(char s[],int n){
    char s2[25];
    int i=0;
    printf("\nenter string 2: ");
    gets(s2);
    while(s[i]!='\0' && s2[i]!='\0'){
        if(s[i]!=s2[i]){
            return s[i]-s2[i];
        }
        i++;
    }
    return  s[i]-s2[i];
}

void insert_sub(char s[],int n){
    char s3[25];
    int pos;
    printf("\nenter substring: ");
    gets(s3);
    printf("\nenter position to insert at: ");
    scanf("%d", &pos);
    int m=str_len(s3);
    for(int i=n;i>pos;i--){
        s[i+m]=s[i];
    }
    for(int j=0;j<m;j++){
        s[pos+j]=s3[j];
    }
    printf("New string: %s",s);
}


void delete(char s[],int n){

      int pos, len, str_len_s;
    printf("Enter position to delete from: ");
    scanf("%d", &pos);
    printf("Enter length of substring to delete: ");
    scanf("%d", &len);

    str_len_s = str_len(s);

    for (int i = pos + len; i <= str_len_s; i++) {
        s[i - len] = s[i];   
    }
}

int main(){
    char str[50];
    int n;
    printf("enter string: ");
    gets(str);

    n=str_len(str);
    printf("length of string is: %d",n);

    concatenate(str,n);
    printf("String comparison= %d", compare(str,n));
    insert_sub(str,n);
    delete(str,n);
    return 0;
}
