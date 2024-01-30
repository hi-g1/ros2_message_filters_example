#include "msg_sync/msg_pub.hpp"

MsgPub::MsgPub()
: Node("msg2_publisher")
{
    second_msg_ = this->create_publisher<std_msgs::msg::Header>("msg_2", 1);
    timer_ = this->create_wall_timer(std::chrono::milliseconds(33), std::bind(&MsgPub::msg_publish, this));

    RCLCPP_INFO(this->get_logger(), "node starts");
}

void MsgPub::msg_publish()
{
    auto msg2 = std_msgs::msg::Header();
    msg2.frame_id = "second_msg";
    msg2.stamp = this->get_clock()->now();

    second_msg_->publish(msg2);
}

int main(int argc, char * argv[])
{
 rclcpp::init(argc, argv);
 auto node = std::make_shared<MsgPub>();
 rclcpp::spin(node);
 rclcpp::shutdown();
 return 0;
}