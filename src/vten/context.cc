#include <vten/context.h>

namespace vten {

Context::Context(VkDevice device, VmaAllocator allocator) : device_(device), allocator_(allocator) {}

Context::Context(VkInstance instance, VkPhysicalDevice physicalDevice, VkDevice device) : device_(device) {
  VmaAllocatorCreateInfo allocatorInfo = {};
  allocatorInfo.flags = VMA_ALLOCATOR_CREATE_KHR_DEDICATED_ALLOCATION_BIT;
  allocatorInfo.physicalDevice = physicalDevice;
  allocatorInfo.device = device;
  allocatorInfo.instance = instance;
  allocatorInfo.vulkanApiVersion = VK_API_VERSION_1_3;
  vmaCreateAllocator(&allocatorInfo, &allocator_);
  allocatorCreated_ = true;
}

Context::~Context() {
  if (allocatorCreated_) vmaDestroyAllocator(allocator_);
}

}  // namespace vten
