#include <gtest/gtest.h>
#include "../include/vm/instruction.h"
#include "../include/vm/vm.h"
#include "../include/vm/hashmap.h"

TEST(HashMap_Test, ShouldCreateHashMap){
     HashMap_t hashMap = createHashMap(defaultHashCode,defaultEqual);
     ASSERT_EQ(hashMap->size, 0);
     ASSERT_EQ(hashMap->listSize, 8);
}

TEST(HashMap_Test, ShouldCreateHashMapIterator){
     HashMap_t hashMap = createHashMap(defaultHashCode,defaultEqual);
     HashMapIterator_t iterator = createHashMapIterator(hashMap);
     ASSERT_EQ(iterator->count, 0);
     ASSERT_EQ(iterator->hashCode, -1);
     ASSERT_EQ(iterator->hashMap,hashMap);
}

TEST(HashMap_Test, ShouldResizeHashMap){
     HashMap_t hashMap = createHashMap(defaultHashCode,defaultEqual);
     HashMapIterator_t iterator = createHashMapIterator(hashMap);
     resetHashMap(hashMap,16);
     ASSERT_EQ(hashMap->listSize, 16);
}

int inKernelFunctionWrapper(VM_t vm){
     printf("InKernel WrapperFunction Invoked.\n");
     return 88;
}
TEST(HashMap_Test, ShouldPutHashMap){
     HashMap_t hashMap = createHashMap(defaultHashCode,defaultEqual);
     HashMapIterator_t iterator = createHashMapIterator(hashMap);
     resetHashMap(hashMap,16);
     u64 key = 0x60000;
     int(*wrapperFunc)(VM_t &vm);
     hashMap->putFunc(hashMap,(void*)&key,(void*)&inKernelFunctionWrapper);
     ASSERT_EQ(hashMap->listSize, 16);
}


bool equal(void *key1,void * key2){
     long uKey1 = *(long *)key1;
     long uKey2 = *(long *)key2;
     return uKey1==uKey2; 
}

TEST(HashMap_Test, ShouldGetHashMap){
     // note: default hash is for u64, so it's works.
     HashMap_t hashMap = createHashMap(defaultHashCode,defaultEqual);
     HashMapIterator_t iterator = createHashMapIterator(hashMap);
     resetHashMap(hashMap,16);
     u64 key = 0x60000;
     int(*wrapperFunc)(VM_t &vm);
     hashMap->equalFunc = equal;
     hashMap->putFunc(hashMap,(void*)&key,(void*)&inKernelFunctionWrapper);
     ASSERT_EQ(hashMap->listSize, 16);
     ASSERT_EQ(hashMap->size, 1);
     void *wrapper = hashMap->getFunc(hashMap,(void*)&key);
     VM_t vm;
     ASSERT_EQ(((int(*)(VM_t&))wrapper)(vm),88);
}

TEST(HashMap_Test, ShouldExistsHashMap){
     // note: default hash is for u64, so it's works.
     HashMap_t hashMap = createHashMap(defaultHashCode,defaultEqual);
     HashMapIterator_t iterator = createHashMapIterator(hashMap);
     resetHashMap(hashMap,16);
     u64 key = 0x60000;
     int(*wrapperFunc)(VM_t &vm);
     hashMap->equalFunc = equal;
     hashMap->putFunc(hashMap,(void*)&key,(void*)&inKernelFunctionWrapper);
     ASSERT_EQ(hashMap->listSize, 16);
     ASSERT_EQ(hashMap->size, 1);
     ASSERT_EQ(hashMap->existsFunc(hashMap,(void*)&key),true);
}

TEST(HashMap_Test, ShouldRemoveHashMap){
     // note: default hash is for u64, so it's works.
     HashMap_t hashMap = createHashMap(defaultHashCode,defaultEqual);
     HashMapIterator_t iterator = createHashMapIterator(hashMap);
     resetHashMap(hashMap,16);
     u64 key = 0x60000;
     int(*wrapperFunc)(VM_t &vm);
     hashMap->equalFunc = equal;
     hashMap->putFunc(hashMap,(void*)&key,(void*)&inKernelFunctionWrapper);
     ASSERT_EQ(hashMap->listSize, 16);
     ASSERT_EQ(hashMap->size, 1);
     ASSERT_EQ(hashMap->existsFunc(hashMap,(void*)&key),true);

     hashMap->removeFunc(hashMap,(void*)&key);
     ASSERT_EQ(hashMap->size, 0);
     ASSERT_EQ(hashMap->existsFunc(hashMap,(void*)&key),false);
}

TEST(HashMap_Test, ShouldClearHashMap){
     // note: default hash is for u64, so it's works.
     HashMap_t hashMap = createHashMap(defaultHashCode,defaultEqual);
     HashMapIterator_t iterator = createHashMapIterator(hashMap);
     resetHashMap(hashMap,16);
     u64 key = 0x60000;
     int(*wrapperFunc)(VM_t &vm);
     hashMap->equalFunc = equal;
     hashMap->putFunc(hashMap,(void*)&key,(void*)&inKernelFunctionWrapper);
     ASSERT_EQ(hashMap->listSize, 16);
     ASSERT_EQ(hashMap->size, 1);
     ASSERT_EQ(hashMap->existsFunc(hashMap,(void*)&key),true);

     hashMap->clearFunc(hashMap);
     ASSERT_EQ(hashMap->size, -1);
     ASSERT_EQ(hashMap->existsFunc(hashMap,(void*)&key),false);
}