/**
 * Autogenerated by Thrift
 *
 * DO NOT EDIT UNLESS YOU ARE SURE THAT YOU KNOW WHAT YOU ARE DOING
 *  @generated
 */
#pragma once

#include <thrift/lib/cpp2/frozen/Frozen.h>
#include "src/gen-cpp2/include2_types.h"
namespace apache { namespace thrift { namespace frozen {

FROZEN_TYPE( ::some::ns::IncludedB,
  FROZEN_FIELD(i32Field, 1, int32_t)
  FROZEN_FIELD(strField, 2, std::string)
  FROZEN_VIEW(
    FROZEN_VIEW_FIELD(i32Field, int32_t)
    FROZEN_VIEW_FIELD(strField, std::string))
  FROZEN_SAVE_INLINE(
    FROZEN_SAVE_FIELD(i32Field)
    FROZEN_SAVE_FIELD(strField))
  FROZEN_LOAD_INLINE(
    FROZEN_LOAD_FIELD(i32Field, 1)
    FROZEN_LOAD_FIELD(strField, 2)));

}}} // apache::thrift::frozen
