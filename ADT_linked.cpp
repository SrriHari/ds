#include<stdlib.h>
#include<stdio.h>

class list{
    struct node
    {
        int data;
        struct node *next;
    }*head;
    
    public:
    list(){
        head = nullptr;
    };
    int insBeg(int);
    int insEnd(int);
    int insPos(int,int);
    int delBeg();
    int delEnd();
    int delPos(int);
    int search(int);
    void display();
};

int main(){
    int choice, num, pos;
    list l;

    printf("MENU\n1. Insert Beginning\n2. Insert End\n3. Insert pos \n4. Delete begining\n5. Delete End\n6. Delete pos\n7. Search\n8.Display\n\nYour Choice: ");
    scanf("%d",&choice);

    while (0 < choice < 8)
    {
        if (choice == 1)
        {
            printf("Enter Num: ");
            scanf("%d",&num);
            if (l.insBeg(num) == 1)
            {
                printf("Inserted at the beginning");
            }
            else
            {
                printf("Sorry not able to insert at the Beginning");
            }
            
        }

        else if (choice == 2)
        {
            printf("Enter Num: ");
            scanf("%d",&num);
            if (l.insEnd(num) == 1)
            {
                printf("Inserted at the End");
            }
            else
            {
                printf("Sorry not able to insert at the End");
            }
            
        }

        else if(choice == 3){
            printf("Enter Num: ");
            scanf("%d",&num);
            printf("Enter Position: ");
            scanf("%d",&pos);

            if (l.insPos(num, pos))
            {
                printf("Inserted %d at the %d",num,pos);
            }
            
            else{
                printf("Sorry not able to insert");
            }
        }

        else if(choice == 4){
            if (l.delBeg())
            {
                printf("Deleted at the Beginning");   
            }
            else{
                printf("Sorry Can't Delete");
            }
            
        }

        else if(choice == 5){
            if (l.delEnd())
            {
                printf("Deleted at the End");   
            }
            else{
                printf("Sorry Can't Delete");
            }
            
        }

        else if(choice == 6){
            printf("Enter Position: ");
            scanf("%d",&pos);

            if (l.delPos(pos))
            {
                printf("Deleted element at the %d",pos);
            }
            
            else{
                printf("Sorry not able to insert");
            }
        }

        else if (choice == 7)
        {
            printf("Enter Number to Search: ");
            scanf("%d",&num);

            if(l.search(num)){
                printf("Found");
            }

            else
            {
                printf("Not Found");
            }
            
        }
        

        else if (choice == 8)
        {
            l.display();
        }
        

        else
        {
            break;
        }
        
        printf("\n\nMENU\n1. Insert Beginning\n2. Insert End\n3. Insert pos \n4. Delete begining\n5. Delete End\n6. Delete pos\n7. Search\n8. Display\n\nYour Choice: ");
        scanf("%d",&choice);
        
        
    }
}

int list::insBeg(int num){
    struct node *newnode = (struct node*)malloc(sizeof(struct node));
    (*newnode).data = num;
    (*newnode).next = head;
    head = newnode;
    return 1;
}

int list::insPos(int num, int pos){
    struct node *newnode = (struct node*)malloc(sizeof(struct node));
    struct node *temp = (struct node*)malloc(sizeof(struct node));
    struct node *temp1 = (struct node*)malloc(sizeof(struct node));
    temp = head;
    while (temp->next != NULL)
    {
        if (temp->data == pos)
        {
            temp1 = temp->next;
            temp->next = newnode;
            newnode->data = num;
            newnode->next = temp1;
            return 1;
        } 
        temp = temp->next;
    }
    return 1;
}

int list::insEnd(int num){
    struct node *newnode = (struct node*)malloc(sizeof(struct node));
    struct node *temp = (struct node*)malloc(sizeof(struct node));
    newnode->data = num;
    temp = head;

    if (head == NULL)
    {
        (*newnode).data = num;
        (*newnode).next = head;
        head = newnode;
        return 1;
    }
    
    while (temp->next != NULL)
    {
        temp = temp->next;  
    }
    temp->next = newnode;
    newnode->next = NULL;
    return 1;
}

int list::delBeg(){
    if(head == NULL) return 0;
    else{
        head->data = head->next->data;
        head->next = head->next->next;
        return 1;
    }
}

int list::delPos(int pos){
    struct node *temp = (struct node*)malloc(sizeof(struct node));
    temp = head;
    int x = 0;
    while (temp->next != NULL)
    {
        if (temp->next->data == pos)
        {
            temp->next = temp->next->next;
            return x == 1;
        }
        temp = temp->next;
    }
    return 0;
}

int list::delEnd(){
    struct node *temp = (struct node*)malloc(sizeof(struct node));
    temp = head;
    if(head == NULL) return 0;

    else if (temp->next->next == NULL)
    {
        temp->next = NULL;
    }
    
    else{
        while (temp->next != NULL && temp->next->next!=NULL){
            temp = temp->next;
        }
        // struct node* t;
        // for (temp = head; temp->next != NULL && temp->next->next!=NULL; temp=temp->next);
        temp->next = NULL;
    }
    return 1;
}

int list::search(int num){
    struct node *temp = (struct node*)malloc(sizeof(struct node));
    temp = head;

    while (temp != NULL)
    {
        if (temp->data == num)
        {
            return 1;
        }
        temp = temp->next;
    }
    return 0;
}

void list::display(){
    struct node *temp = (struct node*)malloc(sizeof(struct node));
    temp = head;
    printf("[");
    while(temp != NULL){
        printf("%d",temp->data);
        if (temp->next != NULL)
        {
            printf(",");
        }
        
        temp = temp->next;
    }
    printf("]");
}