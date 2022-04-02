#include<stdio.h>
#include <string.h>
#include <ctype.h>

struct item{
    char item_name[10];
    int price;
};

struct item items[10];
int index_no = 0;
int strong_password=-1 ;

void check_strong_password(char password[20]){
    if(strlen(password)>=8){
        strong_password = 0;
        char number[10] = {'0','1','2','3','4','5','6','7','8','9'};
        char special_character[25] = {'!','@','#','$','^','&','*','(',')','-','_','=','+','{','}',
        '[',']'};
        int i;
        int j;
        for (i=0;i<=strlen(password)-1;i++){
            for (j=0;j<=9;j++){
                if (number[j]==password[i]){
                    strong_password++;
                    i = 0;
                    j = 0;
                    for (i=0;i<=strlen(password)-1;i++){
                        if(isupper(password[i])){
                            strong_password++;
                            i=0;
                            for (i=0;i<=strlen(password)-1;i++){
                                for (j=0;j<=17;j++){
                                    if (special_character[j]==password[i]){
                                        strong_password++;
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }

}

void insert_item(){
    printf("\nEnter the product:");
    scanf("%s",items[index_no].item_name);
    printf("\nEnter the price :");
    scanf("%d",&items[index_no].price);
    index_no++;

}

void print_item(){
    int i;
    int sno = 0;
    for(i = 0; i < index_no; i++ ){
        printf("\nSno no: %d,Name of the product: %s, Price: %d",sno,items[i].item_name,items[i].price);
        sno++;
    }

}

void sum(){
    int sum = 0;
    int value;
    int loop = 0;
    int i;
    int sno = 0;
    int no_of_items;
    for(i = 0; i < index_no; i++ ){
        printf("\nSno no: %d,Name of the product: %s, Price: %d\n",sno,items[i].item_name,items[i].price);
        sno++;
    }
    while (loop>-1){
        printf("\nEnter the index no to add or Enter invaid index no to exit\n");
        scanf("%d",&value);
        if (value>index_no){
            break;
        }
        else{
            printf("\nEnter no of items\n");
            scanf("%d",&no_of_items);
            if(no_of_items==0){
                sum += items[value].price;
            }
            else{
                sum += items[value].price*no_of_items;
            }

        }
        printf("\nTotal amount is %d",sum);
    }
    sum = 0;
}

void edit_item(){
    print_item();
    int index_no;
    char new_item[20];
    int new_price;
    printf("\nEnter the index no to edit\n");
    scanf("%d",&index_no);
    printf("\nEnter the new item\n");
    scanf("%s",new_item);
    strcpy(items[index_no].item_name,new_item);
    printf("\nEnter the new price\n");
    scanf("%d",&new_price);
    items[index_no].price = new_price;
    printf("\nSucess fully Edited\n");
}

int main(){
    int loop = 0;
    int loop1 = 0;
    char name[20];
    char passcode[20];
    while (loop1<1){
        printf("\nPlease create account to Enter my Console screen application\n");
        printf("\nPlease Enter username \n");
        scanf("%s",name);
        printf("\nPlease Enter password\n");
        scanf("%s",passcode);
        check_strong_password(passcode);
        if(strong_password==-1){
            printf("\nPassword should contain more than 8 characters\n");
        }
        if(strong_password==0){
            printf("\nPassword Should contain a number\n");
        }
        if(strong_password==1){
            printf("\nPassword Should contain a upper case\n");
        }
        if (strong_password==2){
            printf("\nPassword should contain a special charater");
        }
        if(strong_password==3){
            loop1++;
        }
    }
    while (loop<1){
            int input;
            printf("\n-----------------------------------------------------\n");
            printf("\nEnter 1 to add items in the list\n");
            printf("\nEnter 2 to display avalible items in the list\n");
            printf("\nEnter 3 to sum the items \n");
            printf("\nEnter 4 to edit the items in the list\n");
            printf("\nEnter the invalid number to exit\n");
            printf("\n-------------------------------------------------------\n");
            scanf("%d",&input);
            switch(input){
                case 1:
                    insert_item();
                    break;
                case 2:
                    print_item();
                    break;
                case 3:
                    sum();
                    break;
                case 4:
                    edit_item();
                    break;
                default:
                    printf("\nThanku visite again\n");
                    loop++;
            }
        }
    }
