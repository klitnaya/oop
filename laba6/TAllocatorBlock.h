#ifndef TALLOCATORBLOCK_H
#define TALLOCATORBLOCK_H

#include "TLinkedList.h"
#include "SpehelList.h"
#include <memory>

class TAllocationBlock {
 public:
  TAllocationBlock(size_t size, size_t count);
  void* allocate();
  void deallocate(void* pointer);
  bool has_free_blocks();

  virtual ~TAllocationBlock();

 private:
  size_t _size;
  size_t _count;
  char* _used_blocks;
  SpehelList<void*> vec_free_blocks;
  size_t _free_count;
};

#endif
