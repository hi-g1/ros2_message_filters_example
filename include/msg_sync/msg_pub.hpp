#include <rclcpp/rclcpp.hpp>
#include <chrono>
#include <memory>
#include <functional>
#include <std_msgs/msg/header.hpp>

class MsgPub : public rclcpp::Node
{
public:
    MsgPub();
    
private:
    void msg_publish();

    rclcpp::TimerBase::SharedPtr timer_;
    rclcpp::Publisher<std_msgs::msg::Header>::SharedPtr first_msg_;
    rclcpp::Publisher<std_msgs::msg::Header>::SharedPtr second_msg_;

};