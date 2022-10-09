#include<stdio.h>
#define MAX 5
int top = -1;
int st[MAX];
void push(int value){
    if(top==(MAX-1))
        printf("Stack Overflow");
    else
	{
        top++;
        st[top]=value;
    }
}

void pop(){
    int val;
    if(top==-1){
        printf("Stack Underflow");
    }
    val = st[top];
    top--;
    printf("\nThe value popped is %d",val);
}
void display(){
	int i;
    for(i=0;i<=top;i++){
        printf("\t%d",st[i]);
    }
}
void peek(){
    int val=st[top];
    printf("\nThe peek value is %d",val);
}
void main(){
    int option,val;
    do{
        printf("\n****MAIN MENU*******");
        printf("\n1. PUSH");
        printf("\n2. POP");
        printf("\n3. PEEK");
        printf("\n4. DISPLAY");
        printf("\n5. EXIT");
        printf("\nEnter your choice");
        scanf("%d",&option);
        switch(option){
            case 1: printf("\nEnter the value to be pushed");
                    scanf("%d",&val);
                    push(val);
                    break;
            case 2: pop();
                    break;
            case 3: peek();
                    break;
            case 4: display();
                    break;
            case 5: printf("\nEXIT");
                    break;
            default: printf("\nInvalid choice");
        }
    }while(option!=5);
}
