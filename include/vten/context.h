#ifndef VTEN_CONTEXT_H
#define VTEN_CONTEXT_H

#include <vulkan/vulkan.h>
#include <vk_mem_alloc.h>

namespace vten {

class Context {
public:
  Context() = delete;
  Context(VkDevice device, VmaAllocator allocator = nullptr);
  Context(VkInstance instance, VkPhysicalDevice physicalDevice, VkDevice device);
  ~Context();

private:
  VkDevice device_ = VK_NULL_HANDLE;
  VmaAllocator allocator_ = nullptr;
  bool allocatorCreated_ = false;
};

}  // namespace vten

#endif  // VTEN_CONTEXT_H