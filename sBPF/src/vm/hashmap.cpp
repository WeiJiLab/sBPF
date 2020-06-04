#include "../../include/vm/hashmap.h"
#include <malloc.h>


HashMapIterator_t createHashMapIterator(HashMap_t hashMap){

}

bool hasNextHashMapIterator(HashMapIterator_t iterator){

}

HashMapIterator_t nextHashMapIterator(HashMapIterator_t iterator){

}

void freeHashMapIterator(HashMapIterator_t *iterator){

}

HashMap_t createHashMap(HashCodeFunction_t hashCode, EqualFunction_t Equal){

}

void resetHashMap(HashMap_t hashMap,int listSize){

}

int defaultHashCode(HashMap_t hashMap, void *key){

}

bool defaultEqual(void *key1,void *key2){

}

void defaultPut(HashMap_t hashMap,void *key,void *value){

}

void defaultGut(HashMap_t hashMap,void *key){

}

bool defaultRemove(HashMap_t hashMap, void *key){

}

bool defaultExists(HashMap_t hashMap, void *key){

}

void defaultClear(HashMap_t hashMap){
    
}