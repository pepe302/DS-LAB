//multiple stacks ppt-70
/*You have been hired as a software developer for a library management system. One of the requirements is to
implement multiple stacks to manage the borrowing and returning of books. Each stack represents a bookshelf,
and books are added or removed from the corresponding shelves.
• Write the functions to implement multiple stacks using arrays. Your program should include the following
functions:
• Your functions should be able to handle the following scenarios:
• Insertion: Add at least 5 books to different stacks, representing different bookshelves.
• Deletion: Remove a book from a specific stack and display the updated stack.
  Display: Display all the books in a specific stack.
*/

#include<stdio.h>
#include<stdlib.h>

#define size 15
#define stack_size 5
#define num_of_stacks (size/stack_size)

struct Book{
    int bookId;
    char title[25];
};

struct Book arr[size];
int top[num_of_stacks]={-1,-1,-1};

int starting_index(int stack_num){
    return (stack_num*stack_size);
}

int check(int stack_num){
    return (stack_num>(num_of_stacks-1));
}
void push(int stack_num,struct Book b){
    int start=starting_index(stack_num);
    int end=start+stack_size-1;

    if(top[stack_num]==end){
        printf("shelf is full\n");
        return;
    }
    if(top[stack_num]==-1){
        top[stack_num]=start;
    }
    else{
        top[stack_num]++;
    }

    arr[top[stack_num]]=b;
    printf("Book %d has been pushed to shelf %d\n",b.bookId,stack_num);
}

void pop(int stack_num){
    int start=starting_index(stack_num);
    if(top[stack_num]==-1){
        printf("shelf is empty");
        return;
    }
    printf("book %d has been deleted from shelf %d\n",arr[top[stack_num]].bookId,stack_num);
    if(top[stack_num]==start){
        top[stack_num]=-1;
    }
    else{
        top[stack_num]--;
    }
}

void display(int stack_num){
    if(top[stack_num]==-1){
        printf("No books in shelf\n");
        return;
    }
    int start=starting_index(stack_num);
    int end=start+stack_size-1;
    for(int i=start;i<=top[stack_num];i++){
        printf("%d   %s\n",arr[i].bookId,arr[i].title);
    }
}

int main(){
    int choice,shelfID,next;
    int i=0;
    struct Book b[stack_size];

    do{
        printf("\nLibrary Menu Details");
        printf("\n1.Insert book into specific shelf");
        printf("\n2.Delete book from specific shelf");
        printf("\n3.Display all books from specific shelf");
        printf("\n4.Exit");
        printf("\nenter choice: ");
        scanf("%d",&choice);
        switch(choice){
            case 1:
                printf("enter shelf number: ");
                scanf("%d",&shelfID);
                if(check(shelfID)){
                    printf("no such shelf");
                    break;
                }
                do{
                    printf("enter 1 to exit : 0 to continue\n");
                    scanf("%d",&next);
                    if(next==1){
                        break;
                    }
                    printf("\nenter bookID: ");
                    scanf("%d",&b[i].bookId);
                    printf("\nenter title: ");
                    scanf(" %s",b[i].title);
                    push(shelfID,b[i]);
                    i++;
                }while(i<stack_size);
                display(shelfID);
                break;

            case 2:
                printf("enter shelf number: ");
                scanf("%d",&shelfID);
                if(check(shelfID)){
                    printf("no such shelf");
                    break;
                }
                pop(shelfID);
                display(shelfID);
                break;

            case 3:
                printf("enter shelf number: ");
                scanf("%d",&shelfID);
                if(check(shelfID)){
                    printf("no such shelf");
                    break;
                }
                display(shelfID);
                break;
            case 4:
                printf("exiting..");
                exit(0);

            default:
                printf("invalid choice");
        }
    }while(choice!=4);
    return 0;
}