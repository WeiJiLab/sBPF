#include <gtest/gtest.h>

#include "../include/vm/hashmap.h"

TEST(HashMap_Test, ShouldCreateHashMap){
     HashMap_t hashMap = createHashMap(defaultHashCode,defaultEqual);
     ASSERT_EQ(hashMap->size, 0);
}

TEST(HashMap_Test, ShouldCreateHashMapIterator){
     HashMap_t hashMap = createHashMap(defaultHashCode,defaultEqual);
     HashMapIterator_t iterator = createHashMapIterator(hashMap);
     ASSERT_EQ(iterator->count, 0);
     ASSERT_EQ(iterator->hashCode, -1);
     ASSERT_EQ(iterator->hashMap,hashMap);
}