// A Min Heap implementation using an array 
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
int treeSize; // to store the current size of tree

void insert(int value){
  if(treeSize == MX) throw new overflow_error("Max size of heap reached!");
  
  int iterator = treeSize;
  tree[treeSize] = value;
  treeSize++;
  
  while(iterator > 0 && tree[iterator] < tree[parent(iterator)]){
    int temp = tree[iterator]; 
    tree[iterator] = tree[parent(iterator)];
    tree[parent(iterator)] = temp;
    iterator = parent(iterator);
  }
}

int peekTop(){
  if(treeSize == 0) throw new logic_error("Heap does not contain any elements!");
  return tree[0];
}

void removeTop(){
  if(treeSize == 0) throw new logic_error("Heap does not contain any elements!");
  
  treeSize--;
  if(treeSize == 0) return; // only one element had been in heap

  tree[0] = tree[treeSize];
  int iterator = 0;

  while(true){
    int smallest = iterator;
    int lft = left(iterator);
    int rgt = right(iterator);

    if(lft < treeSize && tree[iterator] > tree[lft]) smallest = lft;
    if(rgt < treeSize && tree[smallest] > tree[rgt]) smallest = rgt;

    if(smallest == iterator) break;

    int temp = tree[smallest];
    tree[smallest] = tree[iterator];
    tree[iterator] = temp;
    iterator = smallest;
  }
}

int main(){
  while(true){
    int choice = 0, input;

    // printing the current tree
    if(treeSize){
      printf("Tree: ");
      rep(i,treeSize) printf("%d ", tree[i]);
      printf("\n");
    }

    printf("Enter 1 to insert, 2 to get minimum value, 3 to remove minimum, 0 to exit\n");
    scanf("%d", &choice);
    
    switch(choice){
      case 1:
        printf("Enter the value: ");
        scanf("%d", &input);
        insert(input);
        break;
      case 2:
        printf("The minimum is %d\n\n", peekTop());
        break;
      case 3: 
        removeTop();
        break;
      default:
        exit(0);
    }

    printf("\n\n");
  }

  return 0;
}