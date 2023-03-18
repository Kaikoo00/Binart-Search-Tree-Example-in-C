//Edrico Putra Pramana
//LB20 - 2602078133

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct vertice{
    int x;
    struct vertice *greater;
    struct vertice *lower;
};

struct vertice *root; int data_count=0;

void inorderTraversal(struct vertice* head) {
  if (head == NULL) return;
  inorderTraversal(head->lower);
  printf("| %d | -> ", head->x);
  inorderTraversal(head->greater);
  return;
}

void reverseTraversal(struct vertice *head){
  if(head == NULL) return;
  reverseTraversal(head->greater);
  printf("| %d | -> ", head->x);
  reverseTraversal(head->lower);
  return;
}

struct vertice *createNode(int value){
  struct vertice *newnode = malloc(sizeof(struct vertice));
  newnode->x=value; newnode->greater=NULL; newnode->lower=NULL;
  data_count++;
  return newnode;
}

void addValue(int value){
  if(data_count==0){
    root = createNode(value);
    return;
  }

  struct vertice *newnode = createNode(value);
  struct vertice *curr = root;
  struct vertice *parent, *next;

  while(true){
    parent = curr;
    if(curr->x > value){
      curr=curr->lower;
      if(curr == NULL){
        parent->lower = newnode; parent->lower->greater = NULL; parent->lower->lower = NULL;
        data_count++;
        return;
      }
    }
    else{
      curr = curr->greater;
      if(curr==NULL){
        parent->greater = newnode; parent->greater->lower = NULL; parent->greater->greater = NULL;
        data_count++;
        return;
      }
    }
  }
}

void search_valueInTree(int search_value){
  bool found = false;
  struct vertice *curr = root;
  int i = 0;
  while(true){
    if(curr == NULL){
      break;
    }
    i++;
    printf("| %d | -> ", curr->x);
    
    if(curr->x == search_value){
      printf("<Item Found>\n");
      printf("Total loops of search : %d\n", i);
      found = true;
      return;
    }

    if(search_value>curr->x){
      curr = curr->greater;
    }else if(search_value<curr->x){
      curr = curr->lower;
    }
  }
  if(!found){
    printf("Item doesn't exist in the Tree\n");
    return;
  }
}

void print_menu(){
  printf("====================<Main Menu>====================\n");
  printf("1. Add Value to the Binary Tree\n");
  printf("2. Print in order from the LARGEST to SMALLEST\n");
  printf("3. Print in order from the SMALLEST to the LARGEST\n");
  printf("4. Search Value in the Tree\n");
  printf("5. Exit the Program\n");
  printf(">>");
}

void main_menu(){
  while(true){
    print_menu();
    int ch; scanf("%d", &ch);
    if(ch==1){
      int input_choice;
      while(true){
        system("cls");
        printf("==========Value Input==========\n");
        printf("1. Random System Input (0 - 150)\n2. User Inputted Value\n>>");
        scanf("%d", &input_choice);
        if(input_choice==1 || input_choice==2){
          break;
        }else{
          printf("Invalid Input\n");
        }
      }
      int value;
      if(input_choice==1){
        value=rand()%150;
      }else{
        printf("Input the Value : ");
        scanf("%d", &value);
      }
      addValue(value);
      printf("\nInputted Value: %d\n", value);
      system("pause");system("cls");
    }
    
    else if(ch==2){
      system("cls");
      printf("Here's the tree sorted L to S:\n");
      reverseTraversal(root);printf("<NULL>\n\n");
      system("pause");
      system("cls");
    }
    
    else if(ch==3){
      system("cls");
      printf("Here's the tree sorted S to L:\n");
      inorderTraversal(root);printf("<NULL>\n\n");
      system("pause");
      system("cls");
    }
    
    else if(ch==4){
      system("cls");
      int search_choice;
      while(true){
        system("cls");
        printf("==========Value Input==========\n");
        printf("1. Random System Input (0 - 150)\n2. User Inputted Value\n>>");
        scanf("%d", &search_choice);
        if(search_choice==1 || search_choice==2){
          break;
        }
        else{
          printf("Invalid Input\n");
        }
      }

      int input_value;
      if(search_choice==1){
        input_value = rand()%150;
        system("cls");
      }
      else{
        printf("Input the value to Search: ");
        scanf("%d", &input_value);
        system("cls");
      }

      printf("Inputted Value : %d\n\n", input_value);
      search_valueInTree(input_value);
      printf("\n");
      system("pause");
      system("cls");
    }

    else if(ch==5){
      system("cls");
      printf("========================================");
      printf("\n||  Thankyou for using the program !  ||\n");
      printf("========================================");
      exit(0);
    }else{
      system("cls");
      printf("Invalid Input\n");
      system("pause");
      system("cls");
    }
  } 
}

int main(){
  main_menu();
  return 0;
}
