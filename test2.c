//Edrico Putra Pramana
//LB20 - 2602078133

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct vertice{ //node atau point yang akan digunakan dalam kode
    int x;
    struct vertice *greater;
    struct vertice *lower;
};

struct vertice *root; int data_count=0; //variabel root -> item pertama dalam tree, data_count -> jumlah data/leaf yang sudah diinput

int random_input(){
  int value = rand()%200;
  return value;
}

void inorderTraversal(struct vertice* head) { //fungsi rekursi untuk mencetak dengan urutan dari kecil ke besar
  if (head == NULL) return;
  inorderTraversal(head->lower);
  printf("| %d | -> ", head->x);
  inorderTraversal(head->greater);
  return;
}

void reverseTraversal(struct vertice *head){ //fungsi rekursi untuk mencetak dengan urutan dari besar ke kecil
  if(head == NULL) return;
  reverseTraversal(head->greater);
  printf("| %d | -> ", head->x);
  reverseTraversal(head->lower);
  return;
}

struct vertice *createNode(int value){ //fungsi untuk buat leaf atau node yang akan diinput ke dalam program
  struct vertice *newnode = malloc(sizeof(struct vertice));
  newnode->x=value; newnode->greater=NULL; newnode->lower=NULL;
  data_count++;
  return newnode;
}

void addValue(int value){ //fungsi untuk menginput leaf atau node ke dalam binary tree 
  if(data_count==0 || root == NULL){ //if statement untuk mengisi root apabila root kosong
    root = createNode(value);
    return;
  }

  struct vertice *newnode = createNode(value); //buat node baru
  struct vertice *curr = root; //variabel yang akan digunakan dalam loop 
  struct vertice *parent;
 
  while(true){ //loop input
    parent = curr;
    if(curr->x > value){ //if statement untuk mengecek apakah value pergi ke sisi kiri(lebih kecil dari curr)
      curr=curr->lower; //kode yang perlu dijalankan apabila nilai lebih kecil dari curr
      if(curr == NULL){ //if statement untuk mengecek apakah loop sudah sampai di ujung pohon
        parent->lower = newnode; //simpan node di sebelah kiri parent
        data_count++; //jumlah data + 1 karena data berhasil disimpan
        return; //keluar dari fungsi
      }
    }
    else{ //else statement untuk node yang akan pergi ke sisi kanan(lebih besar dari curr)
      curr = curr->greater; //kode yang perlu dijalankan apabila nilai lebih besar dari curr
      if(curr==NULL){ //if statement untuk mengecek apakah loop sudah sampai di ujung pohon
        parent->greater = newnode; //simpan node di sebelah kanan parent
        data_count++; //jumlah data + 1 karena data berhasil disimpan
        return; //keluar dari fungsi
      }
    }
  }
}

void search_valueInTree(int search_value){ //fungsi untuk mengecek apakah nilai di dalam parameter ada di dalam tree
  bool found = false; //status untuk menyatakan nilai tersebut sudah ditemukan atau belum
  struct vertice *curr = root; //variabel yang akan digunakan dalam loop
  int i = 0; //jumlah loop yang dilakukan untuk mencari nilai yang ada dalam parameter
  while(true){ //loop untuk mencari nilai tersebut
    if(curr == NULL){ //if statement untuk keluar dari loop apabila loop sudah mencapai ujung tree
      break;
    }
    i++;
    printf("| %d | -> ", curr->x); //print node yang dilalui untuk menemukan nilai yang dicari
    
    if(curr->x == search_value){ //if statement apabila nilai berhasil ditemukan
      printf("<Item Found>\n"); 
      printf("Total loops of search : %d\n", i); //print jumlah loop yang perlu dilakukan untuk menemukan node tersebut.
      found = true; //set status item telah ditemukan
      return; //keluar dari fungsi
    }

    if(search_value>curr->x){ //if statement apabila nilai yang dicari lebih besar daripada node saat ini
      curr = curr->greater; //curr pergi ke sisi kanan (sisi yang lebih besar)
    }else if(search_value<curr->x){ //if statement apabila nilai yang dicari lebih kecil daripada node saat ini
      curr = curr->lower; //curr pergi ke sisi kiri (sisi yang lebih kecil)
    }
  }
  if(!found){ //if statement apabila fungsi sudah keluar dari loop dan nilai masih belum ditemukan
    printf("Item doesn't exist in the Tree\n"); //pesan item tidak ditemukan
    return; //keluar dari program
  }
}

void print_menu(){ //sudah jelas tidak perlu diberi penjelasan kan?!
  printf("====================<Main Menu>====================\n");
  printf("1. Add Value to the Binary Tree\n");
  printf("2. Print in order from the LARGEST to SMALLEST\n");
  printf("3. Print in order from the SMALLEST to the LARGEST\n");
  printf("4. Search Value in the Tree\n");
  printf("5. Exit the Program\n");
  printf(">>");
}

void main_menu(){ //main menu dari program ini
  while(true){ //loop agar program tidak berhenti tanpa input yang sesuai
    print_menu();
    int ch; scanf("%d", &ch); //input menu keberapa yang ingin dijalankan oleh user
    if(ch==1){ //menu pertama (input node ke dalam binary tree)
      int input_choice; //tipe input yang ingin disimpan oleh user (random/input user)
      while(true){ //loop agar input yang masuk sesuai dan tidak menyebabkan crash apabila input tidak valid
        system("cls");
        printf("==========Value Input==========\n");
        printf("1. Random System Input (0 - 150)\n2. User Inputted Value\n>>");
        scanf("%d", &input_choice); //tipe input yang diinginkan oleh user
        if(input_choice==1 || input_choice==2){ //statement untuk keluar dari loop apabila input yang diberikan sudah valid
          break;
        }else{
          printf("Invalid Input\n");
        }
      }
      int value; //value yang akan disimpan kedalam tree
      if(input_choice==1){ //tipe pertama (random)
        value=random_input();
      }
      else{ //tipe kedua (input dari user)
        printf("Input the Value : "); 
        scanf("%d", &value);
      }
      addValue(value); //simpan value ke dalam tree
      printf("\nInputted Value: %d\n", value); //pesan untuk value sudah tersimpan
      system("pause");system("cls");
    }
    
    else if(ch==2){ //menu kedua (print dari besar ke kecil)
      system("cls");
      printf("Here's the tree sorted L to S:\n");
      reverseTraversal(root);printf("<NULL>\n\n");
      system("pause");
      system("cls");
    }
    
    else if(ch==3){ //menu ketiga (print dari kecil ke besar)
      system("cls");
      printf("Here's the tree sorted S to L:\n");
      inorderTraversal(root);printf("<NULL>\n\n");
      system("pause");
      system("cls");
    }
    
    else if(ch==4){ //menu keempat (cari data di dalam binary tree)
      system("cls");
      int search_choice; //tipe data yang ingin dicari (random atau input oleh user)
      while(true){ //loop agar input tipe yang dimasukkan user valid
        system("cls");
        printf("==========Value Input==========\n");
        printf("1. Random System Input (0 - 150)\n2. User Inputted Value\n>>");
        scanf("%d", &search_choice); 
        if(search_choice==1 || search_choice==2){ //if statement untuk keluar dari loop apabila input sudah valid
          break;
        }
        else{
          printf("Invalid Input\n");
        }
      }

      int input_value; //variabel untuk menyimpan nilai yang dicari
      if(search_choice==1){ //tipe input pertama (random)
        input_value = random_input(); 
        system("cls");
      }
      else{ //tipe input kedua (input user)
        printf("Input the value to Search: ");
        scanf("%d", &input_value);
        system("cls");
      }

      printf("Inputted Value : %d\n\n", input_value); //pesan berisi nilai yang dicari
      search_valueInTree(input_value);
      printf("\n");
      system("pause");
      system("cls");
    }

    else if(ch==5){ //keluar dari program secara total
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

int main(){ //main 
  main_menu();
  return 0;
}
