#include<kv.h>

kv_t *kv_init(size_t capacity) {
  if (capacity == 0) return NULL;

  kv_t *table = malloc(sizeof(kv_t ));
  if(table == NULL){
    return NULL;
  }
  table->capacity = capacity;
  table->count = 0;
  table->entries = calloc(sizeof(kv_entry_t), capacity);
  if(table->entries == NULL){
    return NULL;
  }
  return table;
}

int kv_put(kv_t *db, const char *key, const char *value){
  printf("Nothing for now\n");
  return 0;
}
char *kv_get(kv_t *db, const char *key){
  printf("Nothing for now\n");
  return 0;
}
int kv_delete(kv_t *db, const char *key){
  printf("Nothing for now\n");
  return 0;
}
void kv_free(kv_t *db){
  printf("Nothing for now\n");
  return 0;
}