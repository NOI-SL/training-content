// Binary Search Tree implementation using an array 
// to represent the tree

#include <bits/stdc++.h>
using namespace std;

#define rep(a,b) for(int a=0;a<b;a++)

#define left(a) ((a<<1)+1) // is equivalent to  2*a + 1
#define right(a) ((a<<1)+2) // is equivalent to 2*a + 2
#define parent(a) ((a-1)>>1) // is equivalent to (a-1) / 2

// max size of the tree
const int MX = 1000;

int tree[MX]; // to store the values
bool taken[MX]; // mark if there's a value in the node
int lastIndex = -1; // index of the last element in tree


void insert(int value){
  int iterator = 0;
  while(true) {
    if(!taken[iterator]) break;
  
    if(tree[iterator] > value) iterator = left(iterator);
    else if(tree[iterator] < value) iterator = right(iterator);
    else throw "Duplicate value!"; 
  }

  tree[iterator] = value;
  taken[iterator] = true;
  lastIndex = max(lastIndex, iterator);
}

void remove(int value){
  // implement ;)
}

bool exists(int value){
  int iterator = 0;
  while(true){
    if(!taken[iterator]) return false;
    if(value == tree[iterator]) return true;

    if(value > tree[iterator]) iterator = right(iterator);
    else iterator = left(iterator);
  }
}

int main(){
  while(true){
    int choice = 0, input;

    // printing the current tree
    if(lastIndex >=0){
      printf("Tree: ");
      rep(i,lastIndex+1) printf("%d ", tree[i]);
      printf("\n");
    }

    printf("Enter 1 to insert, 2 to find if value exists 0 to exit\n");
    scanf("%d", &choice);
    
    printf("Enter the value: ");
    scanf("%d", &input);
    
    switch(choice){
      case 1:
        insert(input);
        break;
      case 2:
        if(exists(input)) printf("Value exists!\n");
        else printf("Value does not exist!\n");
        break;
      default:
        exit(0);
    }

    printf("\n\n");
  }

  return 0;
}