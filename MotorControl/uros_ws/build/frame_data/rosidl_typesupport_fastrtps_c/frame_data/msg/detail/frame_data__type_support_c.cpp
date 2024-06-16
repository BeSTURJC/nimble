// generated from rosidl_typesupport_fastrtps_c/resource/idl__type_support_c.cpp.em
// with input from frame_data:msg/FrameData.idl
// generated code does not contain a copyright notice
#include "frame_data/msg/detail/frame_data__rosidl_typesupport_fastrtps_c.h"


#include <cassert>
#include <limits>
#include <string>
#include "rosidl_typesupport_fastrtps_c/identifier.h"
#include "rosidl_typesupport_fastrtps_c/wstring_conversion.hpp"
#include "rosidl_typesupport_fastrtps_cpp/message_type_support.h"
#include "frame_data/msg/rosidl_typesupport_fastrtps_c__visibility_control.h"
#include "frame_data/msg/detail/frame_data__struct.h"
#include "frame_data/msg/detail/frame_data__functions.h"
#include "fastcdr/Cdr.h"

#ifndef _WIN32
# pragma GCC diagnostic push
# pragma GCC diagnostic ignored "-Wunused-parameter"
# ifdef __clang__
#  pragma clang diagnostic ignored "-Wdeprecated-register"
#  pragma clang diagnostic ignored "-Wreturn-type-c-linkage"
# endif
#endif
#ifndef _WIN32
# pragma GCC diagnostic pop
#endif

// includes and forward declarations of message dependencies and their conversion functions

#if defined(__cplusplus)
extern "C"
{
#endif


// forward declare type support functions


using _FrameData__ros_msg_type = frame_data__msg__FrameData;

static bool _FrameData__cdr_serialize(
  const void * untyped_ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  if (!untyped_ros_message) {
    fprintf(stderr, "ros message handle is null\n");
    return false;
  }
  const _FrameData__ros_msg_type * ros_message = static_cast<const _FrameData__ros_msg_type *>(untyped_ros_message);
  // Field name: contador
  {
    cdr << ros_message->contador;
  }

  // Field name: frame_position
  {
    cdr << ros_message->frame_position;
  }

  // Field name: frame_speed
  {
    cdr << ros_message->frame_speed;
  }

  // Field name: sensor_dist
  {
    cdr << ros_message->sensor_dist;
  }

  // Field name: position_ref
  {
    cdr << ros_message->position_ref;
  }

  // Field name: speed_ref
  {
    cdr << ros_message->speed_ref;
  }

  return true;
}

static bool _FrameData__cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  void * untyped_ros_message)
{
  if (!untyped_ros_message) {
    fprintf(stderr, "ros message handle is null\n");
    return false;
  }
  _FrameData__ros_msg_type * ros_message = static_cast<_FrameData__ros_msg_type *>(untyped_ros_message);
  // Field name: contador
  {
    cdr >> ros_message->contador;
  }

  // Field name: frame_position
  {
    cdr >> ros_message->frame_position;
  }

  // Field name: frame_speed
  {
    cdr >> ros_message->frame_speed;
  }

  // Field name: sensor_dist
  {
    cdr >> ros_message->sensor_dist;
  }

  // Field name: position_ref
  {
    cdr >> ros_message->position_ref;
  }

  // Field name: speed_ref
  {
    cdr >> ros_message->speed_ref;
  }

  return true;
}  // NOLINT(readability/fn_size)

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_frame_data
size_t get_serialized_size_frame_data__msg__FrameData(
  const void * untyped_ros_message,
  size_t current_alignment)
{
  const _FrameData__ros_msg_type * ros_message = static_cast<const _FrameData__ros_msg_type *>(untyped_ros_message);
  (void)ros_message;
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;

  // field.name contador
  {
    size_t item_size = sizeof(ros_message->contador);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name frame_position
  {
    size_t item_size = sizeof(ros_message->frame_position);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name frame_speed
  {
    size_t item_size = sizeof(ros_message->frame_speed);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name sensor_dist
  {
    size_t item_size = sizeof(ros_message->sensor_dist);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name position_ref
  {
    size_t item_size = sizeof(ros_message->position_ref);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name speed_ref
  {
    size_t item_size = sizeof(ros_message->speed_ref);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  return current_alignment - initial_alignment;
}

static uint32_t _FrameData__get_serialized_size(const void * untyped_ros_message)
{
  return static_cast<uint32_t>(
    get_serialized_size_frame_data__msg__FrameData(
      untyped_ros_message, 0));
}

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_frame_data
size_t max_serialized_size_frame_data__msg__FrameData(
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

  // member: contador
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }
  // member: frame_position
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }
  // member: frame_speed
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }
  // member: sensor_dist
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }
  // member: position_ref
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }
  // member: speed_ref
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
    using DataType = frame_data__msg__FrameData;
    is_plain =
      (
      offsetof(DataType, speed_ref) +
      last_member_size
      ) == ret_val;
  }

  return ret_val;
}

static size_t _FrameData__max_serialized_size(char & bounds_info)
{
  bool full_bounded;
  bool is_plain;
  size_t ret_val;

  ret_val = max_serialized_size_frame_data__msg__FrameData(
    full_bounded, is_plain, 0);

  bounds_info =
    is_plain ? ROSIDL_TYPESUPPORT_FASTRTPS_PLAIN_TYPE :
    full_bounded ? ROSIDL_TYPESUPPORT_FASTRTPS_BOUNDED_TYPE : ROSIDL_TYPESUPPORT_FASTRTPS_UNBOUNDED_TYPE;
  return ret_val;
}


static message_type_support_callbacks_t __callbacks_FrameData = {
  "frame_data::msg",
  "FrameData",
  _FrameData__cdr_serialize,
  _FrameData__cdr_deserialize,
  _FrameData__get_serialized_size,
  _FrameData__max_serialized_size
};

static rosidl_message_type_support_t _FrameData__type_support = {
  rosidl_typesupport_fastrtps_c__identifier,
  &__callbacks_FrameData,
  get_message_typesupport_handle_function,
};

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, frame_data, msg, FrameData)() {
  return &_FrameData__type_support;
}

#if defined(__cplusplus)
}
#endif
