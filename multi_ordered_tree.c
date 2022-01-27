//
// AED, January 2022
//
// Solution of the second practical assignement (multi-ordered tree)
//
// Place your student numbers and names here
//Tomás Almeida - 103300/ Guilherme Dias - 103128

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "AED_2021_A02.h"


//
// the custom tree node structure
//
// we want to maintain three ordered trees (using the same nodes!), so we need three left and three right pointers
// so, when inserting a new node we need to do it three times (one for each index), so we will end upo with 3 three roots
//

typedef struct tree_node_s
{
  char name[MAX_NAME_SIZE + 1];                         // index 0 data item
  char zip_code[MAX_ZIP_CODE_SIZE + 1];                 // index 1 data item
  char telephone_number[MAX_TELEPHONE_NUMBER_SIZE + 1]; // index 2 data item
  char ssn[MAX_SSN_NUMBER_SIZE+1];                        // index 3 data item
  struct tree_node_s *left[4];                          // left pointers (one for each index) ---- left means smaller
  struct tree_node_s *right[4];                         // right pointers (one for each index) --- right means larger
  long depth;                                           // depth of the tree
}
tree_node_t;


//
// the node comparison function (do not change this)
//

int compare_tree_nodes(tree_node_t *node1,tree_node_t *node2,int main_idx)
{
  int i,c;

  for(i = 0;i < 3;i++)
  {
    if(main_idx == 0)
      c = strcmp(node1->name,node2->name);
    else if(main_idx == 1)
      c = strcmp(node1->zip_code,node2->zip_code);
    else if (main_idx == 2)
      c = strcmp(node1->telephone_number,node2->telephone_number);
    else
       c = strcmp(node1->ssn,node2->ssn);
    if(c != 0)
      return c; // different on this index, so return
    main_idx = (main_idx == 3) ? 0 : main_idx + 1; // advance to the next index
  }
  return 0;
}


//
// tree insertion routine (place your code here)
//

void tree_insert(tree_node_t **link, tree_node_t *node, int main_idx){
  
  if(*link == NULL)
    *link = node;
  else if(compare_tree_nodes(*link,node,main_idx) > 0)
    tree_insert(&((*link)->left[main_idx]),node,main_idx);
  else
    tree_insert(&((*link)->right[main_idx]),node,main_idx);
}


//
// tree search routine (place your code here)
//

tree_node_t *find(tree_node_t *link, tree_node_t *node, int main_idx) {
  if(link == NULL){
    return NULL;
  }
  int compare = compare_tree_nodes(link,node,main_idx);
  if(compare > 0)
    return find(link->left[main_idx], node, main_idx);
  else if (compare < 0)
    return find(link->right[main_idx], node, main_idx);
  else 
    return link;
}


//
// tree depdth
//

int tree_depth(tree_node_t *link, int main_idx){

  if (link == NULL)
    return 0;

  //Recursively calculates the depth
  
  int left_depth = tree_depth(link->left[main_idx], main_idx);
  int right_depth = tree_depth(link->right[main_idx], main_idx);


  if (left_depth > right_depth){
    return left_depth +1;
  }

  return right_depth+1 ;
}


int counter = 1;
void list(tree_node_t *link, int main_idx){

  if(link != NULL){
    list(link->left[main_idx],main_idx);
    printf("Person #%d\n",counter++);
    printf("    name --------------------- %s\n", link->name);
    printf("    zip code ----------------- %s\n", link->zip_code);
    printf("    telephone number --------- %s\n", link->telephone_number);
    printf("    social security number --- %s\n", link->ssn);
    list(link->right[main_idx],main_idx);
  }
}



void *find_zip_code(tree_node_t *link, char *zip){

  if(link != NULL){
    if (strcmp(link->zip_code, zip) == 0){
      find_zip_code(link->left[1],zip);
      printf("Person #%d\n",counter++);
      printf("    name --------------------- %s\n", link->name);
      printf("    zip code ----------------- %s\n", link->zip_code);
      printf("    telephone number --------- %s\n", link->telephone_number);
      printf("    social security number --- %s\n", link->ssn);
      find_zip_code(link->right[1],zip);
    }
    else{
      find_zip_code(link->left[1],zip);
      find_zip_code(link->right[1],zip);
    }
  }
}


//
// main program
//

int main(int argc,char **argv)
{
  double dt;

  // process the command line arguments
  if(argc < 4)
  {
    fprintf(stderr,"Usage: %s student_number number_of_persons [options ...]\n",argv[0]);
    fprintf(stderr,"Recognized options:\n");
    fprintf(stderr,"  -list[N]              # list the tree contents, sorted by key index N (the default is index 0)\n");
    // place a description of your own options here
    return 1;
  }
  int student_number = atoi(argv[1]);
  if(student_number < 1 || student_number >= 1000000)
  {
    fprintf(stderr,"Bad student number (%d) --- must be an integer belonging to [1,1000000{\n",student_number);
    return 1;
  }
  int n_persons = atoi(argv[2]);
  if(n_persons < 3 || n_persons > 10000000)
  {
    fprintf(stderr,"Bad number of persons (%d) --- must be an integer belonging to [3,10000000]\n",n_persons);
    return 1;
  }
  // generate all data
  tree_node_t *persons = (tree_node_t *)calloc((size_t)n_persons,sizeof(tree_node_t));
  if(persons == NULL)
  {
    fprintf(stderr,"Output memory!\n");
    return 1;
  }
  aed_srandom(student_number);
  for(int i = 0;i < n_persons;i++)
  {
    random_name(&(persons[i].name[0]));
    random_zip_code(&(persons[i].zip_code[0]));
    random_telephone_number(&(persons[i].telephone_number[0]));
    random_ssn(&(persons[i].ssn[0]));
    for(int j = 0;j < 4;j++)
      persons[i].left[j] = persons[i].right[j] = NULL; // make sure the pointers are initially NULL
  }
  // create the ordered binary trees
  dt = cpu_time();
  tree_node_t *roots[4]; // three indices, three roots
  for(int main_index = 0;main_index < 4;main_index++)
    roots[main_index] = NULL;
  for(int i = 0;i < n_persons;i++)
    for(int main_index = 0;main_index < 4;main_index++)
      tree_insert(&roots[main_index], &persons[i], main_index) ; // place your code here to insert &(persons[i]) in the tree with number main_index
  dt = cpu_time() - dt;
  printf("Tree creation time (%d persons): %.3es\n",n_persons,dt);
  // search the tree
  for(int main_index = 0;main_index < 4;main_index++)
  {
    dt = cpu_time();
    for(int i = 0;i < n_persons;i++)
    {
      tree_node_t n = persons[i]; // make a copy of the node data
      if(find(roots[main_index], &n , main_index) != &(persons[i])) // place your code here to find a given person, searching for it using the tree with number main_index
      {
        fprintf(stderr,"person %d not found using index %d\n",i,main_index);
        return 1;
      }
    }
    dt = cpu_time() - dt;
    printf("Tree search time (%d persons, index %d): %.3es\n",n_persons,main_index,dt);
  }
  // compute the largest tree depdth
  for(int main_index = 0;main_index < 4;main_index++)
  {
    dt = cpu_time();
    int depth = tree_depth(roots[main_index],main_index); // place your code here to compute the depth of the tree with number main_index
    dt = cpu_time() - dt;
    printf("Tree depth for index %d: %d (done in %.3es)\n",main_index,depth,dt);
  }
  // process the command line optional arguments
  for(int i = 3;i < argc;i++)
  {
    if(strncmp(argv[i],"-list",5) == 0)
    { // list all (optional)
      int main_index = atoi(&(argv[i][5]));
      if(main_index < 0)
        main_index = 0;
      if(main_index > 3)
        main_index = 3;
       printf("List of persons:\n");
       (void)list(roots[main_index], main_index); // place your code here to traverse, in order, the tree with number main_index
    } else if (strcmp(argv[i],"-find") == 0){
      printf("List of people with the zip code '%s' is: \n", argv[i+1]);
      find_zip_code(roots[i], argv[i+1]);

    }
    // place your own options here
  }
  // clean up --- don't forget to test your program with valgrind, we don't want any memory leaks
  free(persons);
  return 0;
}