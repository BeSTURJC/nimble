// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from nimble_interfaces:msg/CartesianTrajectory.idl
// generated code does not contain a copyright notice

#ifndef NIMBLE_INTERFACES__MSG__DETAIL__CARTESIAN_TRAJECTORY__TRAITS_HPP_
#define NIMBLE_INTERFACES__MSG__DETAIL__CARTESIAN_TRAJECTORY__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "nimble_interfaces/msg/detail/cartesian_trajectory__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

// Include directives for member types
// Member 'header'
#include "std_msgs/msg/detail/header__traits.hpp"
// Member 'left_pelvis'
// Member 'right_pelvis'
// Member 'base_pelvis'
// Member 'left_hip'
// Member 'right_hip'
// Member 'left_knee'
// Member 'right_knee'
// Member 'left_ankle'
// Member 'right_ankle'
// Member 'left_heel'
// Member 'right_heel'
// Member 'left_toe'
// Member 'right_toe'
#include "geometry_msgs/msg/detail/point__traits.hpp"

namespace nimble_interfaces
{

namespace msg
{

inline void to_flow_style_yaml(
  const CartesianTrajectory & msg,
  std::ostream & out)
{
  out << "{";
  // member: header
  {
    out << "header: ";
    to_flow_style_yaml(msg.header, out);
    out << ", ";
  }

  // member: left_pelvis
  {
    if (msg.left_pelvis.size() == 0) {
      out << "left_pelvis: []";
    } else {
      out << "left_pelvis: [";
      size_t pending_items = msg.left_pelvis.size();
      for (auto item : msg.left_pelvis) {
        to_flow_style_yaml(item, out);
        if (--pending_items > 0) {
          out << ", ";
        }
      }
      out << "]";
    }
    out << ", ";
  }

  // member: right_pelvis
  {
    if (msg.right_pelvis.size() == 0) {
      out << "right_pelvis: []";
    } else {
      out << "right_pelvis: [";
      size_t pending_items = msg.right_pelvis.size();
      for (auto item : msg.right_pelvis) {
        to_flow_style_yaml(item, out);
        if (--pending_items > 0) {
          out << ", ";
        }
      }
      out << "]";
    }
    out << ", ";
  }

  // member: base_pelvis
  {
    if (msg.base_pelvis.size() == 0) {
      out << "base_pelvis: []";
    } else {
      out << "base_pelvis: [";
      size_t pending_items = msg.base_pelvis.size();
      for (auto item : msg.base_pelvis) {
        to_flow_style_yaml(item, out);
        if (--pending_items > 0) {
          out << ", ";
        }
      }
      out << "]";
    }
    out << ", ";
  }

  // member: left_hip
  {
    if (msg.left_hip.size() == 0) {
      out << "left_hip: []";
    } else {
      out << "left_hip: [";
      size_t pending_items = msg.left_hip.size();
      for (auto item : msg.left_hip) {
        to_flow_style_yaml(item, out);
        if (--pending_items > 0) {
          out << ", ";
        }
      }
      out << "]";
    }
    out << ", ";
  }

  // member: right_hip
  {
    if (msg.right_hip.size() == 0) {
      out << "right_hip: []";
    } else {
      out << "right_hip: [";
      size_t pending_items = msg.right_hip.size();
      for (auto item : msg.right_hip) {
        to_flow_style_yaml(item, out);
        if (--pending_items > 0) {
          out << ", ";
        }
      }
      out << "]";
    }
    out << ", ";
  }

  // member: left_knee
  {
    if (msg.left_knee.size() == 0) {
      out << "left_knee: []";
    } else {
      out << "left_knee: [";
      size_t pending_items = msg.left_knee.size();
      for (auto item : msg.left_knee) {
        to_flow_style_yaml(item, out);
        if (--pending_items > 0) {
          out << ", ";
        }
      }
      out << "]";
    }
    out << ", ";
  }

  // member: right_knee
  {
    if (msg.right_knee.size() == 0) {
      out << "right_knee: []";
    } else {
      out << "right_knee: [";
      size_t pending_items = msg.right_knee.size();
      for (auto item : msg.right_knee) {
        to_flow_style_yaml(item, out);
        if (--pending_items > 0) {
          out << ", ";
        }
      }
      out << "]";
    }
    out << ", ";
  }

  // member: left_ankle
  {
    if (msg.left_ankle.size() == 0) {
      out << "left_ankle: []";
    } else {
      out << "left_ankle: [";
      size_t pending_items = msg.left_ankle.size();
      for (auto item : msg.left_ankle) {
        to_flow_style_yaml(item, out);
        if (--pending_items > 0) {
          out << ", ";
        }
      }
      out << "]";
    }
    out << ", ";
  }

  // member: right_ankle
  {
    if (msg.right_ankle.size() == 0) {
      out << "right_ankle: []";
    } else {
      out << "right_ankle: [";
      size_t pending_items = msg.right_ankle.size();
      for (auto item : msg.right_ankle) {
        to_flow_style_yaml(item, out);
        if (--pending_items > 0) {
          out << ", ";
        }
      }
      out << "]";
    }
    out << ", ";
  }

  // member: left_heel
  {
    if (msg.left_heel.size() == 0) {
      out << "left_heel: []";
    } else {
      out << "left_heel: [";
      size_t pending_items = msg.left_heel.size();
      for (auto item : msg.left_heel) {
        to_flow_style_yaml(item, out);
        if (--pending_items > 0) {
          out << ", ";
        }
      }
      out << "]";
    }
    out << ", ";
  }

  // member: right_heel
  {
    if (msg.right_heel.size() == 0) {
      out << "right_heel: []";
    } else {
      out << "right_heel: [";
      size_t pending_items = msg.right_heel.size();
      for (auto item : msg.right_heel) {
        to_flow_style_yaml(item, out);
        if (--pending_items > 0) {
          out << ", ";
        }
      }
      out << "]";
    }
    out << ", ";
  }

  // member: left_toe
  {
    if (msg.left_toe.size() == 0) {
      out << "left_toe: []";
    } else {
      out << "left_toe: [";
      size_t pending_items = msg.left_toe.size();
      for (auto item : msg.left_toe) {
        to_flow_style_yaml(item, out);
        if (--pending_items > 0) {
          out << ", ";
        }
      }
      out << "]";
    }
    out << ", ";
  }

  // member: right_toe
  {
    if (msg.right_toe.size() == 0) {
      out << "right_toe: []";
    } else {
      out << "right_toe: [";
      size_t pending_items = msg.right_toe.size();
      for (auto item : msg.right_toe) {
        to_flow_style_yaml(item, out);
        if (--pending_items > 0) {
          out << ", ";
        }
      }
      out << "]";
    }
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const CartesianTrajectory & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: header
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "header:\n";
    to_block_style_yaml(msg.header, out, indentation + 2);
  }

  // member: left_pelvis
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    if (msg.left_pelvis.size() == 0) {
      out << "left_pelvis: []\n";
    } else {
      out << "left_pelvis:\n";
      for (auto item : msg.left_pelvis) {
        if (indentation > 0) {
          out << std::string(indentation, ' ');
        }
        out << "-\n";
        to_block_style_yaml(item, out, indentation + 2);
      }
    }
  }

  // member: right_pelvis
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    if (msg.right_pelvis.size() == 0) {
      out << "right_pelvis: []\n";
    } else {
      out << "right_pelvis:\n";
      for (auto item : msg.right_pelvis) {
        if (indentation > 0) {
          out << std::string(indentation, ' ');
        }
        out << "-\n";
        to_block_style_yaml(item, out, indentation + 2);
      }
    }
  }

  // member: base_pelvis
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    if (msg.base_pelvis.size() == 0) {
      out << "base_pelvis: []\n";
    } else {
      out << "base_pelvis:\n";
      for (auto item : msg.base_pelvis) {
        if (indentation > 0) {
          out << std::string(indentation, ' ');
        }
        out << "-\n";
        to_block_style_yaml(item, out, indentation + 2);
      }
    }
  }

  // member: left_hip
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    if (msg.left_hip.size() == 0) {
      out << "left_hip: []\n";
    } else {
      out << "left_hip:\n";
      for (auto item : msg.left_hip) {
        if (indentation > 0) {
          out << std::string(indentation, ' ');
        }
        out << "-\n";
        to_block_style_yaml(item, out, indentation + 2);
      }
    }
  }

  // member: right_hip
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    if (msg.right_hip.size() == 0) {
      out << "right_hip: []\n";
    } else {
      out << "right_hip:\n";
      for (auto item : msg.right_hip) {
        if (indentation > 0) {
          out << std::string(indentation, ' ');
        }
        out << "-\n";
        to_block_style_yaml(item, out, indentation + 2);
      }
    }
  }

  // member: left_knee
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    if (msg.left_knee.size() == 0) {
      out << "left_knee: []\n";
    } else {
      out << "left_knee:\n";
      for (auto item : msg.left_knee) {
        if (indentation > 0) {
          out << std::string(indentation, ' ');
        }
        out << "-\n";
        to_block_style_yaml(item, out, indentation + 2);
      }
    }
  }

  // member: right_knee
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    if (msg.right_knee.size() == 0) {
      out << "right_knee: []\n";
    } else {
      out << "right_knee:\n";
      for (auto item : msg.right_knee) {
        if (indentation > 0) {
          out << std::string(indentation, ' ');
        }
        out << "-\n";
        to_block_style_yaml(item, out, indentation + 2);
      }
    }
  }

  // member: left_ankle
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    if (msg.left_ankle.size() == 0) {
      out << "left_ankle: []\n";
    } else {
      out << "left_ankle:\n";
      for (auto item : msg.left_ankle) {
        if (indentation > 0) {
          out << std::string(indentation, ' ');
        }
        out << "-\n";
        to_block_style_yaml(item, out, indentation + 2);
      }
    }
  }

  // member: right_ankle
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    if (msg.right_ankle.size() == 0) {
      out << "right_ankle: []\n";
    } else {
      out << "right_ankle:\n";
      for (auto item : msg.right_ankle) {
        if (indentation > 0) {
          out << std::string(indentation, ' ');
        }
        out << "-\n";
        to_block_style_yaml(item, out, indentation + 2);
      }
    }
  }

  // member: left_heel
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    if (msg.left_heel.size() == 0) {
      out << "left_heel: []\n";
    } else {
      out << "left_heel:\n";
      for (auto item : msg.left_heel) {
        if (indentation > 0) {
          out << std::string(indentation, ' ');
        }
        out << "-\n";
        to_block_style_yaml(item, out, indentation + 2);
      }
    }
  }

  // member: right_heel
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    if (msg.right_heel.size() == 0) {
      out << "right_heel: []\n";
    } else {
      out << "right_heel:\n";
      for (auto item : msg.right_heel) {
        if (indentation > 0) {
          out << std::string(indentation, ' ');
        }
        out << "-\n";
        to_block_style_yaml(item, out, indentation + 2);
      }
    }
  }

  // member: left_toe
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    if (msg.left_toe.size() == 0) {
      out << "left_toe: []\n";
    } else {
      out << "left_toe:\n";
      for (auto item : msg.left_toe) {
        if (indentation > 0) {
          out << std::string(indentation, ' ');
        }
        out << "-\n";
        to_block_style_yaml(item, out, indentation + 2);
      }
    }
  }

  // member: right_toe
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    if (msg.right_toe.size() == 0) {
      out << "right_toe: []\n";
    } else {
      out << "right_toe:\n";
      for (auto item : msg.right_toe) {
        if (indentation > 0) {
          out << std::string(indentation, ' ');
        }
        out << "-\n";
        to_block_style_yaml(item, out, indentation + 2);
      }
    }
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const CartesianTrajectory & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace msg

}  // namespace nimble_interfaces

namespace rosidl_generator_traits
{

[[deprecated("use nimble_interfaces::msg::to_block_style_yaml() instead")]]
inline void to_yaml(
  const nimble_interfaces::msg::CartesianTrajectory & msg,
  std::ostream & out, size_t indentation = 0)
{
  nimble_interfaces::msg::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use nimble_interfaces::msg::to_yaml() instead")]]
inline std::string to_yaml(const nimble_interfaces::msg::CartesianTrajectory & msg)
{
  return nimble_interfaces::msg::to_yaml(msg);
}

template<>
inline const char * data_type<nimble_interfaces::msg::CartesianTrajectory>()
{
  return "nimble_interfaces::msg::CartesianTrajectory";
}

template<>
inline const char * name<nimble_interfaces::msg::CartesianTrajectory>()
{
  return "nimble_interfaces/msg/CartesianTrajectory";
}

template<>
struct has_fixed_size<nimble_interfaces::msg::CartesianTrajectory>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<nimble_interfaces::msg::CartesianTrajectory>
  : std::integral_constant<bool, false> {};

template<>
struct is_message<nimble_interfaces::msg::CartesianTrajectory>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // NIMBLE_INTERFACES__MSG__DETAIL__CARTESIAN_TRAJECTORY__TRAITS_HPP_
