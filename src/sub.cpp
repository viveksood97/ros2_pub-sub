#include <memory>

#include "rclcpp/rclcpp.hpp"
#include "std_msgs/msg/string.hpp"
using std::placeholders::_1;

class Sub : public rclcpp::Node {
 public:
    Sub(): Node("subscriber") {
      subscription = this->create_subscription<std_msgs::msg::String>(
      "topic", 10, std::bind(&Sub::topic_callback, this, _1));
    }

 private:
    void topic_callback(const std_msgs::msg::String::SharedPtr in) const {
      RCLCPP_INFO(this->get_logger(), "Receiving: '%s'", in->data.c_str());
    }
    rclcpp::Subscription<std_msgs::msg::String>::SharedPtr subscription;
};

int main(int argc, char * argv[]) {
  rclcpp::init(argc, argv);
  rclcpp::spin(std::make_shared<Sub>());
  rclcpp::shutdown();
  return 0;
}