#include "msg_sync/msg_sync.hpp"
#include <iostream>

MsgSync::MsgSync() :
    Node("msg_sync_node"),
    msg1_sub_(this, "/msg_1", rmw_qos_profile_default),
    msg2_sub_(this, "/msg_2", rmw_qos_profile_default),
    approximate_sync_(ApproximateSyncPolicy(5), msg1_sub_, msg2_sub_)
{
    approximate_sync_.registerCallback(&MsgSync::approximateSyncCallback, this);
    RCLCPP_INFO(this->get_logger(), "sync node starts");
}


void MsgSync::approximateSyncCallback(
    const StampedHeaderMsg& msg1,
    const StampedHeaderMsg& msg2)
{
    std::cout << "Message 1: [Timestamp: " << msg1.stamp.sec << "." << msg1.stamp.nanosec << "]" << std::endl;
    std::cout << "Message 2: [Timestamp: " << msg2.stamp.sec << "." << msg2.stamp.nanosec << "]" << std::endl;
}

int main(int argc, char * argv[])
{
 rclcpp::init(argc, argv);
 auto node = std::make_shared<MsgSync>();
 rclcpp::spin(node);
 rclcpp::shutdown();
 return 0;
}