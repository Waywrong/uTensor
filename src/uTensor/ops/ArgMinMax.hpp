#ifndef UTENSOR_ARG_MIN_MAX_H
#define UTENSOR_ARG_MIN_MAX_H
#include "operatorBase.hpp"
#include "ArgMinMax_kernel.hpp"

namespace uTensor {

template <typename Tin, typename Tout>
class ArgMaxOperator : public OperatorInterface<2, 1>
{
public:
  enum names_in : uint8_t { input, axis};
  enum names_out : uint8_t { output };
protected:
  virtual void compute() {
    arg_min_max_kernel<Tin, Tout>(
      outputs[output].tensor(),
      inputs[input].tensor(),
      inputs[axis].tensor(),
      Max
    );
  }
};

template <typename Tin, typename Tout>
class ArgMinOperator : public OperatorInterface<2, 1>
{
public:
  enum names_in : uint8_t { input, axis};
  enum names_out : uint8_t { output };
protected:
  virtual void compute() {
    arg_min_max_kernel<Tin, Tout>(
      outputs[output].tensor(),
      inputs[input].tensor(),
      inputs[axis].tensor(),
      Min
    );
  }
};

} // namespace uTensor

#endif // UTENSOR_ARG_MIN_MAX_H