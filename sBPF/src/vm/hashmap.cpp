#include "../../include/vm/hashmap.h"
#include <malloc.h>


HashMapIterator_t createHashMapIterator(HashMap_t hashMap){
    HashMapIterator_t iterator = (HashMapIterator_t) malloc(sizeof(HashMapIterator));
    iterator->count = 0;
    iterator->hashCode = -1;
    iterator->entry = NULL;
    iterator->hashMap = hashMap;
    return iterator;
}

bool hasNextHashMapIterator(HashMapIterator_t iterator){

}

HashMapIterator_t nextHashMapIterator(HashMapIterator_t iterator){

}

void freeHashMapIterator(HashMapIterator_t *iterator){

}

HashMap_t createHashMap(HashCodeFunction_t hashCode, EqualFunction_t equal){
    HashMap_t hashMap = (HashMap_t) malloc(sizeof(HashMap));
    hashMap->hashCodeFunction = hashCode;
    hashMap->equalFunc = equal;
    hashMap->size = 0;
    hashMap->listSize = 8;
    hashMap->hashCodeFunction = hashCode == NULL ? defaultHashCode:hashCode;
    hashMap->equalFunc = equal == NULL ? defaultEqual:equal;
    hashMap->putFunc=defaultPut;
    hashMap->getFunc=defaultGet;
    hashMap->removeFunc=defaultRemove;
    hashMap->clearFunc=defaultClear;
    hashMap->existsFunc=defaultExists;
    hashMap->autoAssign=true;

    hashMap->list = (Entry_t)malloc(hashMap->listSize*sizeof(Entry));
    for(int i =0 ;i<hashMap->listSize;i++){
        hashMap->list[i].key = hashMap->list[i].value = hashMap->list[i].next = NULL;
    }
    return hashMap;
}

void resetHashMap(HashMap_t hashMap,int listSize){

}

int defaultHashCode(HashMap_t hashMap, void *key){

}

bool defaultEqual(void *key1,void *key2){

}

void defaultPut(HashMap_t hashMap,void *key,void *value){

}

void* defaultGet(HashMap_t hashMap,void *key){

}

bool defaultRemove(HashMap_t hashMap, void *key){

}

bool defaultExists(HashMap_t hashMap, void *key){

}

void defaultClear(HashMap_t hashMap){

}