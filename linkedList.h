struct node {
    int age;
    struct node *next;
    struct node *before;
};
typedef struct node node_t;

void append( int age, node_t ** i, node_t **  f )
{
  node_t * nuevo  = (node_t *) malloc(sizeof(node_t));
  nuevo->age = age;
  //nuevo->name = name;
  nuevo->next = NULL;
  nuevo->before = NULL;
  if(*i == NULL && *f == NULL){
    *i = *f = nuevo;
  }else{
    (*f)->next = nuevo;
    nuevo->before = *f;
    *f = nuevo;
  }
}


void print(node_t * inicio){
  node_t * temp = inicio;
  printf("[");
  while(temp != NULL){
    printf("%d", temp->age);
    temp = temp->next;
  }
  printf("]");
}

void clearList(node_t * inicio){
  node_t * temp = inicio;
  //printf("[");
  while(temp != NULL){
    temp = temp->next;
    free(temp);
  }
  //printf("]");
}


void clear(node_t ** inicio, node_t ** fin){
  node_t * temp;
  //printf("[");
  while((*inicio)->next != NULL){
    temp = *inicio;
    *inicio = (*inicio)->next;
    free(temp);
  }
  *fin = NULL;
  *inicio = NULL;
  //printf("]");
}




