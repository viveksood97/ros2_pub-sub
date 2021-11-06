#include "rclcpp/rclcpp.hpp"

class publisher: public rclcpp::Node {
 public:
    publisher() : Node("kick_publisher") {
        timer_ = this->create_wall_timer(
            std::chrono::milliseconds(200),
            std::bind(&publisher::timerCallback, this));
    }
 private:
    void timerCallback() {
        RCLCPP_INFO(this->get_logger(), "Knock Knock");
    }
    rclcpp::TimerBase::SharedPtr timer_;
};
int main(int argc, char **argv) {
    rclcpp::init(argc, argv);
    auto node = std::make_shared<publisher>();
    rclcpp::spin(node);
    rclcpp::shutdown();
    return 0;
}
