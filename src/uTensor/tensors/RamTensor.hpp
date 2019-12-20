#ifndef UTENSOR_RAM_TENSOR
#define UTENSOR_RAM_TENSOR

#include "memoryManagementInterface.hpp"

namespace uTensor {

class RawDataHandle : public Handle {
 public:
  RawDataHandle(size_t req_ram_size) {
    _ptr = Context::DefaultRamDataAllocator::allocate(req_ram_size);
    Context::DefaultRamDataAllocator::bind(this, _ptr);
  }
  ~RawDataHandle() { Context::DefaultRamDataAllocator::deallocate(_ptr); }
  // void* operator new(size_t sz) { // Have to delegate this size from tensors
  // somehow + sizeof(Tensor)
  //  void* p = Context::DefaultTensorMetaDataAllocator::allocate(sz);
  //  return p;
  //}
  // void operator delete(void* p) {
  //  Context::DefaultTensorMetaDataAllocator::deallocate(p);
  //}
  // Ignore this, use the constructor to specify the data space
  //  void* operator new(size_t sz, size_t req_ram_size){
  //    void* p = Context::DefaultTensorMetaDataAllocator::allocate(sz);
  //    _ptr = Context::DefaultRamDataAllocator::allocator(req_ram_size);
  //    return p;
  //  }
};

}
#endif