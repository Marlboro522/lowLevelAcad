#include <kv.h>
#include<string.h>
#include<stdlib.h>
#include<stdio.h>

kv_t *kv_init(size_t capacity) {
  if (capacity == 0)
    return NULL;

  kv_t *table = malloc(sizeof(kv_t));
  if (table == NULL) {
    return NULL;
  }
  table->capacity = capacity;
  table->count = 0;
  table->entries = calloc(sizeof(kv_entry_t), capacity);
  if (table->entries == NULL) {
    return NULL;
  }
  return table;
}

static size_t hash(const char* val, int capacity){
  size_t hash = 0x13371337deadbeef;
  while(*val){
    hash ^= *val;
    hash <<= 8;
    hash += *val;
    val++;
  }
  return hash % capacity;
}
int kv_put(kv_t *db, const char *key, const char *value) {
  if (!db || !key || !value){
    return -1;
  }
  //compute the hash
  size_t id = hash(key, db->capacity);
  // now we use the id index and insert the value there. 
  for (int i = 0; i < db->capacity - 1; i++) {
    // store the keya and value; 
    // key is hashed in the id above.
    size_t r_id = (id + 1) % db->capacity; //I'm not really sure why we need this though.
    kv_entry_t *entry = &db->entries[r_id];
    // if the key already exists, we just insert the current key value pair
    if(entry->key && entry->key !=(void*)TOMBSTONE && !strcmp(entry->key,key)){
      char *newval = strdup(value);
      if(!newval)
        return -1;
      entry->value = newval;
      printf("%zu", r_id);
      return r_id;
    }
    // right after it
    // if it is empty or empty by deletion
    if(!entry->key || entry->key == (void *)TOMBSTONE){
      char *newval = strdup(value);
      char *newkey = strdup(key);
      if(!newval || !newkey){
        free(newval);
        free(newkey);
        return -1;
      }
      entry->key = newkey;
      entry->value = newval;
      db->count++;
      printf("%zu", r_id);
      return r_id;
    }
    
  }
  return -2;
}
char *kv_get(kv_t *db, const char *key) {
  printf("Nothing for now\n");
  return 0;
}
int kv_delete(kv_t *db, const char *key) {
  printf("Nothing for now\n");
  return 0;
}
void kv_free(kv_t *db) {
  printf("Nothing for now\n");
  return ;
}