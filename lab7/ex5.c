//implementing multiple stack using fixed partition on single array

#include<stdio.h>

#define size 9
#define number_of_stacks 3
#define stack_size (size/number_of_stacks)

int arr[size];
int top[number_of_stacks]={-1,-1,-1};

int start_index(int stack_num){
    return stack_num*stack_size;
}

void push(int stack_num,int data){
    int start=start_index(stack_num);
    int end=start+stack_size-1;
    if(top[stack_num]==end){
        printf("stack overflow");
        return;
    }
    if(top[stack_num]==-1){
        top[stack_num]=start;
    }
    else{
        top[stack_num]++;
    }
    arr[top[stack_num]]=data;
    printf("%d pushed to stack %d\n",data,stack_num+1);
}

void pop(int stack_num){
    if(top[stack_num]==-1){
        printf("stack underflow");
        return;
    }
    printf("popped %d from stack %d\n",arr[top[stack_num]],stack_num+1);
    if(top[stack_num]==start_index(stack_num)){
        top[stack_num]=-1;
    }
    else{
        top[stack_num]--;
    }
}

void display(int stack_num){
    if(top[stack_num]==-1){
        printf("stack empty");
        return;
    }
    printf("stack %d elements: \n",stack_num+1);
    int start=start_index(stack_num);
    for(int i=start;i<=top[stack_num];i++){
        printf("%d ",arr[i]);
    }
    printf("\n");
}

int main() {
    push(0, 10);
    push(0, 20);
    push(1, 30);
    push(1, 40);
    push(2, 50);

    display(0);
    display(1);
    display(2);

    pop(1);
    display(1);

    return 0;
}