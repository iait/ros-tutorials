#include <ros/ros.h>
#include <std_msgs/String.h>

// los mensajes son pasados a una función de callback
void chatterCallback(const std_msgs::String::ConstPtr& msg) {
    ROS_INFO("I heard [%s]", msg->data.c_str());
}

int main(int argc, char **argv) {

    // inicializa el nodo ROS
    ros::init(argc, argv, "listener");
    ros::NodeHandle nh;

    // crea el suscriptor
    ros::Subscriber sub = nh.subscribe("chatter", 1000, chatterCallback);

    // entra en un loop, procesando los callbacks
    ros::spin();

    return 0;
}

