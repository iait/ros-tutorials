#include <ros/ros.h>
#include <std_msgs/Float32.h>

#include <sstream>

int main(int argc, char **argv) {

    // inicializa ROS
    ros::init(argc, argv, "velodyne_pub");
    ros::NodeHandle nh;

    // crea publicador
    ros::Publisher pub = nh.advertise<std_msgs::Float32>("my_velodyne/vel_cmd", 1000);

    // publica cada 5 segundos
    ros::Rate loop_rate(0.3);

    int count = 0;
    while (ros::ok()) {

        std_msgs::Float32 msg;
        if (count % 2 == 0) {
            msg.data = 0.2;
        } else {
            msg.data = 0.0;
        }

        ROS_INFO("Se publica la velocidad %f", msg.data);

        pub.publish(msg);

        ros::spinOnce();

        loop_rate.sleep();
        count++;
    }

    return 0;
}
