#include<stdio.h>
# define size 5

class list{
    int arr[size];
    int cur;

    public:
    list(){
        cur = -1;
    }
    int insBeg(int);
    int insEnd(int);
    int insPos(int, int);
    int delBeg();
    int delEnd();
    int delPos(int);
    void display();
};

int main(){
    int choice, num, pos;
    list l;

    printf("MENU\n1. Insert Beginning\n2. Insert End\n3. Insert pos \n4. Delete begining\n5. Delete End\n6. Delete pos\n7. Display\n\nYour Choice: ");
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
            l.display();
        }
        

        else
        {
            break;
        }
        
        printf("\n\nMENU\n1. Insert Beginning\n2. Insert End\n3. Insert pos \n4. Delete begining\n5. Delete End\n6. Delete pos\n7. Display\n\nYour Choice: ");
        scanf("%d",&choice);
        
        
    }
    
}

int list::insBeg(int n){
    if(cur == size-1)
    {
        return 0;
    }

    else if(cur == -1)
    {
        cur = 0;
        arr[0] = n;
        return 1;
    }

    else
    {
        for(int i = cur; 0 <= i; i--)
        {
            arr[i+1]=arr[i];
        }
        cur = cur + 1;
        arr[0]=n;
        return 1;

    }
}

int list::insEnd(int num){
    if (cur == -1)
    {
        cur = 0;
        arr[0] = num;
        return 1;
    }
    
    else if(cur == size-1)
    {
        return 0;
    }

    else{
        cur += 1;
        arr[cur] = num;
        return 1;
    }
}

int list::insPos(int num, int pos){
    if (cur == -1)
    {
        return 0;
    }

    else if(cur == size-1)
    {
        return 0;
    }
    
    else{
        for(int i = cur; pos <= i; i--)
        {
            arr[i+1]=arr[i];
        }
        arr[pos] = num;
        cur++;
        return 1;
    }
}

int list::delBeg(){
    int temp = 0;
    if(cur == -1)
    {
        return 0;
    }
    else
    {
        temp = arr[0];
        for(int i = 0; i <= cur; i++)
        {
            arr[i]=arr[i+1];
        }
        cur = cur - 1;
        return temp;
    }
}

int list::delEnd(){
    if(cur == -1)
    {
        return 0;
    }

    else
    {
        int temp = arr[cur];
        cur --;
        return temp;
    }
    
}

int list::delPos(int pos){
    if(cur == -1)
    {
        return 0;
    }

    else{
        int temp = arr[pos];
        for(int i = pos; i <= cur; i++)
        {
            arr[i]=arr[i+1];
        }
        cur = cur - 1;
        return temp;
    }
}

void list::display(){
        printf("[");
        for (int i = 0; i <= cur; i++)
        {
            printf(" %d",arr[i]);
            if (i < cur){
                printf(",");
            }
        }
        printf("]");
}