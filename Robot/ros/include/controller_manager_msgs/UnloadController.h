// Generated by gencpp from file controller_manager_msgs/UnloadController.msg
// DO NOT EDIT!


#ifndef CONTROLLER_MANAGER_MSGS_MESSAGE_UNLOADCONTROLLER_H
#define CONTROLLER_MANAGER_MSGS_MESSAGE_UNLOADCONTROLLER_H

#include <ros/service_traits.h>


#include <controller_manager_msgs/UnloadControllerRequest.h>
#include <controller_manager_msgs/UnloadControllerResponse.h>


namespace controller_manager_msgs
{

struct UnloadController
{

typedef UnloadControllerRequest Request;
typedef UnloadControllerResponse Response;
Request request;
Response response;

typedef Request RequestType;
typedef Response ResponseType;

}; // struct UnloadController
} // namespace controller_manager_msgs


namespace ros
{
namespace service_traits
{


template<>
struct MD5Sum< ::controller_manager_msgs::UnloadController > {
  static const char* value()
  {
    return "647e5c54b8d6468952d8d31f1efe96c0";
  }

  static const char* value(const ::controller_manager_msgs::UnloadController&) { return value(); }
};

template<>
struct DataType< ::controller_manager_msgs::UnloadController > {
  static const char* value()
  {
    return "controller_manager_msgs/UnloadController";
  }

  static const char* value(const ::controller_manager_msgs::UnloadController&) { return value(); }
};


// service_traits::MD5Sum< ::controller_manager_msgs::UnloadControllerRequest> should match
// service_traits::MD5Sum< ::controller_manager_msgs::UnloadController >
template<>
struct MD5Sum< ::controller_manager_msgs::UnloadControllerRequest>
{
  static const char* value()
  {
    return MD5Sum< ::controller_manager_msgs::UnloadController >::value();
  }
  static const char* value(const ::controller_manager_msgs::UnloadControllerRequest&)
  {
    return value();
  }
};

// service_traits::DataType< ::controller_manager_msgs::UnloadControllerRequest> should match
// service_traits::DataType< ::controller_manager_msgs::UnloadController >
template<>
struct DataType< ::controller_manager_msgs::UnloadControllerRequest>
{
  static const char* value()
  {
    return DataType< ::controller_manager_msgs::UnloadController >::value();
  }
  static const char* value(const ::controller_manager_msgs::UnloadControllerRequest&)
  {
    return value();
  }
};

// service_traits::MD5Sum< ::controller_manager_msgs::UnloadControllerResponse> should match
// service_traits::MD5Sum< ::controller_manager_msgs::UnloadController >
template<>
struct MD5Sum< ::controller_manager_msgs::UnloadControllerResponse>
{
  static const char* value()
  {
    return MD5Sum< ::controller_manager_msgs::UnloadController >::value();
  }
  static const char* value(const ::controller_manager_msgs::UnloadControllerResponse&)
  {
    return value();
  }
};

// service_traits::DataType< ::controller_manager_msgs::UnloadControllerResponse> should match
// service_traits::DataType< ::controller_manager_msgs::UnloadController >
template<>
struct DataType< ::controller_manager_msgs::UnloadControllerResponse>
{
  static const char* value()
  {
    return DataType< ::controller_manager_msgs::UnloadController >::value();
  }
  static const char* value(const ::controller_manager_msgs::UnloadControllerResponse&)
  {
    return value();
  }
};

} // namespace service_traits
} // namespace ros

#endif // CONTROLLER_MANAGER_MSGS_MESSAGE_UNLOADCONTROLLER_H
