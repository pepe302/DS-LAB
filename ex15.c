/*Make a stack using struct enter N ages split odd and even ones into EvenStack and OddStack find average*/

#include<stdio.h>

#define max 10
int n=max;

struct Stack{
    int arr[max];
    int top;
};

void push(struct Stack *s, int age){
    if(s->top==max-1){
        printf("stack overflow");
        return;
    }
    else{
        s->arr[++s->top]=age;
    }
}

void display(struct Stack s){
    if(s.top==-1){
        printf("empty stack");
        return;
    }
    for(int i=s.top;i>=0;i--){
        printf("%d ",s.arr[i]);
    }
    printf("\n");
}

void findAvg(struct Stack e, struct Stack o){
    int sum1=0,sum2=0;
    for(int i=e.top;i>=0;i--){
        sum1+=e.arr[i];
    }
    for(int i=o.top;i>=0;i--){
        sum2+=o.arr[i];
    }
    printf("\n Average of even ages: %0.2f",sum1/(e.top+1));
    printf("\n Average of od2 ages: %0.2f",sum1/(o.top+1));
}

int main(){
    int age;
    struct Stack evenStack,oddStack;
    evenStack.top=-1;
    oddStack.top=-1;
    printf("enter ages: ");
    for(int i=0;i<n;i++){
        scanf("%d",&age);

        if(age%2==0){
            push(&evenStack,age);
        }
        else{
            push(&oddStack,age);
        }
    }
    printf("\neven stack: ");
    display(evenStack);
    printf("\nodd stack: ");
    display(oddStack); 
    printf("\nAverage: ");
    findAvg(evenStack,oddStack);
    return 0;
}