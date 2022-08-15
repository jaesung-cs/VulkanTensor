#ifndef VTEN_TENSOR_H
#define VTEN_TENSOR_H

#include <vulkan/vulkan.h>

namespace vten {

class TensorBase {
public:
  TensorBase() {}
  ~TensorBase() {}

private:
  VkBuffer buffer_;
};

template <typename T>
class Tensor2 : public TensorBase {
public:
  Tensor2() : TensorBase() {}

private:
  // base + i * stride[0] + j * stride[1]
  // ex) row major: stride[0] = size[1], stride[1] = 1 (contiguous)
  // ex) col major: stride[0] = 1, stride[1] = size[0] (non-contiguous)
  int size_[2];
  int stride_[2];
};

using Tensor2f = Tensor2<float>;

}  // namespace vten

#endif  // VTEN_TENSOR_H
