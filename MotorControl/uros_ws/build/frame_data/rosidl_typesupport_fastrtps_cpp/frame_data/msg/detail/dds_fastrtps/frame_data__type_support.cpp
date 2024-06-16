// generated from rosidl_typesupport_fastrtps_cpp/resource/idl__type_support.cpp.em
// with input from frame_data:msg/FrameData.idl
// generated code does not contain a copyright notice
#include "frame_data/msg/detail/frame_data__rosidl_typesupport_fastrtps_cpp.hpp"
#include "frame_data/msg/detail/frame_data__struct.hpp"

#include <limits>
#include <stdexcept>
#include <string>
#include "rosidl_typesupport_cpp/message_type_support.hpp"
#include "rosidl_typesupport_fastrtps_cpp/identifier.hpp"
#include "rosidl_typesupport_fastrtps_cpp/message_type_support.h"
#include "rosidl_typesupport_fastrtps_cpp/message_type_support_decl.hpp"
#include "rosidl_typesupport_fastrtps_cpp/wstring_conversion.hpp"
#include "fastcdr/Cdr.h"


// forward declaration of message dependencies and their conversion functions

namespace frame_data
{

namespace msg
{

namespace typesupport_fastrtps_cpp
{

bool
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_frame_data
cdr_serialize(
  const frame_data::msg::FrameData & ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  // Member: contador
  cdr << ros_message.contador;
  // Member: frame_position
  cdr << ros_message.frame_position;
  // Member: frame_speed
  cdr << ros_message.frame_speed;
  // Member: sensor_dist
  cdr << ros_message.sensor_dist;
  // Member: position_ref
  cdr << ros_message.position_ref;
  // Member: speed_ref
  cdr << ros_message.speed_ref;
  return true;
}

bool
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_frame_data
cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  frame_data::msg::FrameData & ros_message)
{
  // Member: contador
  cdr >> ros_message.contador;

  // Member: frame_position
  cdr >> ros_message.frame_position;

  // Member: frame_speed
  cdr >> ros_message.frame_speed;

  // Member: sensor_dist
  cdr >> ros_message.sensor_dist;

  // Member: position_ref
  cdr >> ros_message.position_ref;

  // Member: speed_ref
  cdr >> ros_message.speed_ref;

  return true;
}

size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_frame_data
get_serialized_size(
  const frame_data::msg::FrameData & ros_message,
  size_t current_alignment)
{
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;

  // Member: contador
  {
    size_t item_size = sizeof(ros_message.contador);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: frame_position
  {
    size_t item_size = sizeof(ros_message.frame_position);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: frame_speed
  {
    size_t item_size = sizeof(ros_message.frame_speed);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: sensor_dist
  {
    size_t item_size = sizeof(ros_message.sensor_dist);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: position_ref
  {
    size_t item_size = sizeof(ros_message.position_ref);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: speed_ref
  {
    size_t item_size = sizeof(ros_message.speed_ref);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  return current_alignment - initial_alignment;
}

size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_frame_data
max_serialized_size_FrameData(
  bool & full_bounded,
  bool & is_plain,
  size_t current_alignment)
{
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  size_t last_member_size = 0;
  (void)last_member_size;
  (void)padding;
  (void)wchar_size;

  full_bounded = true;
  is_plain = true;


  // Member: contador
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }

  // Member: frame_position
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }

  // Member: frame_speed
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }

  // Member: sensor_dist
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }

  // Member: position_ref
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }

  // Member: speed_ref
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }

  size_t ret_val = current_alignment - initial_alignment;
  if (is_plain) {
    // All members are plain, and type is not empty.
    // We still need to check that the in-memory alignment
    // is the same as the CDR mandated alignment.
    using DataType = frame_data::msg::FrameData;
    is_plain =
      (
      offsetof(DataType, speed_ref) +
      last_member_size
      ) == ret_val;
  }

  return ret_val;
}

static bool _FrameData__cdr_serialize(
  const void * untyped_ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  auto typed_message =
    static_cast<const frame_data::msg::FrameData *>(
    untyped_ros_message);
  return cdr_serialize(*typed_message, cdr);
}

static bool _FrameData__cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  void * untyped_ros_message)
{
  auto typed_message =
    static_cast<frame_data::msg::FrameData *>(
    untyped_ros_message);
  return cdr_deserialize(cdr, *typed_message);
}

static uint32_t _FrameData__get_serialized_size(
  const void * untyped_ros_message)
{
  auto typed_message =
    static_cast<const frame_data::msg::FrameData *>(
    untyped_ros_message);
  return static_cast<uint32_t>(get_serialized_size(*typed_message, 0));
}

static size_t _FrameData__max_serialized_size(char & bounds_info)
{
  bool full_bounded;
  bool is_plain;
  size_t ret_val;

  ret_val = max_serialized_size_FrameData(full_bounded, is_plain, 0);

  bounds_info =
    is_plain ? ROSIDL_TYPESUPPORT_FASTRTPS_PLAIN_TYPE :
    full_bounded ? ROSIDL_TYPESUPPORT_FASTRTPS_BOUNDED_TYPE : ROSIDL_TYPESUPPORT_FASTRTPS_UNBOUNDED_TYPE;
  return ret_val;
}

static message_type_support_callbacks_t _FrameData__callbacks = {
  "frame_data::msg",
  "FrameData",
  _FrameData__cdr_serialize,
  _FrameData__cdr_deserialize,
  _FrameData__get_serialized_size,
  _FrameData__max_serialized_size
};

static rosidl_message_type_support_t _FrameData__handle = {
  rosidl_typesupport_fastrtps_cpp::typesupport_identifier,
  &_FrameData__callbacks,
  get_message_typesupport_handle_function,
};

}  // namespace typesupport_fastrtps_cpp

}  // namespace msg

}  // namespace frame_data

namespace rosidl_typesupport_fastrtps_cpp
{

template<>
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_EXPORT_frame_data
const rosidl_message_type_support_t *
get_message_type_support_handle<frame_data::msg::FrameData>()
{
  return &frame_data::msg::typesupport_fastrtps_cpp::_FrameData__handle;
}

}  // namespace rosidl_typesupport_fastrtps_cpp

#ifdef __cplusplus
extern "C"
{
#endif

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_cpp, frame_data, msg, FrameData)() {
  return &frame_data::msg::typesupport_fastrtps_cpp::_FrameData__handle;
}

#ifdef __cplusplus
}
#endif
