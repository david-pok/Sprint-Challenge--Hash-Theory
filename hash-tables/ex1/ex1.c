#include <stdio.h>
#include <stdlib.h>
#include "hashtable.h"
#include "ex1.h"

Answer *get_indices_of_item_weights(int *weights, int length, int limit)
{
  HashTable *ht = create_hash_table(16);

  for (int i = 0; i < length; i++) {
    int complement = hash_table_retrieve(ht, limit - weights[i]);
    if (complement != -1) {
      //we found a match
      Answer *answer = malloc(sizeof(Answer));
      answer->index_1 = i;
      answer->index_2 = complement;
      return answer;
    } else {
      //insert into the hash table
      //the weight is the key and the array index is value
      hash_table_insert(ht, weights[i], i);
    }
  }
  return NULL;
}

void print_answer(Answer *answer)
{
  if (answer != NULL)
  {
    printf("%d %d\n", answer->index_1, answer->index_2);
  }
  else
  {
    printf("NULL\n");
  }
}