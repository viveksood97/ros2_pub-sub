#include <chrono>
#include <functional>
#include <memory>
#include <string>

#include "rclcpp/rclcpp.hpp"
#include "std_msgs/msg/string.hpp"


class Pub : public rclcpp::Node {
 public:
    Pub():Node("publisher") {
        publisher = this->create_publisher<std_msgs::msg::String>("topic", 1);
        timer = this->create_wall_timer(
        std::chrono::milliseconds(200), std::bind(&Pub::timer_callback, this));
    }

 private:
    void timer_callback() {
      auto out = std_msgs::msg::String();
      out.data = "Knock Knock";
      RCLCPP_INFO(this->get_logger(), out.data);
      publisher->publish(out);
    }
    rclcpp::TimerBase::SharedPtr timer;
    rclcpp::Publisher<std_msgs::msg::String>::SharedPtr publisher;
};

int main(int argc, char * argv[]) {
  rclcpp::init(argc, argv);
  rclcpp::spin(std::make_shared<Pub>());
  rclcpp::shutdown();
  return 0;
}
