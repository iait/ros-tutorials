#include <ros/ros.h>
#include <tf2/LinearMath/Quaternion.h>
#include <tf2_ros/transform_broadcaster.h>
#include <geometry_msgs/TransformStamped.h>
#include <turtlesim/Pose.h>

std::string turtle_name;

/*
 * Recibe puntero a:
 * turtlesim/Pose.msg
 *   float32 x
 *   float32 y
 *   float32 theta
 * Y difunde la transformación de la posición de la tortuga.
 */
void poseCallback(const turtlesim::PoseConstPtr& msg) {

    static tf2_ros::TransformBroadcaster br;
    geometry_msgs::TransformStamped transformStamped;

    transformStamped.header.stamp = ros::Time::now();
    transformStamped.header.frame_id = "world";
    transformStamped.child_frame_id = turtle_name;

    // traslación, solo sobre (x,y)
    transformStamped.transform.translation.x = msg->x;
    transformStamped.transform.translation.y = msg->y;
    transformStamped.transform.translation.z = 0.0;

    // rotación, solo yaw (es decir, sobre el eje z)
    tf2::Quaternion q;
    q.setRPY(0, 0, msg->theta);
    transformStamped.transform.rotation.x = q.x();
    transformStamped.transform.rotation.y = q.y();
    transformStamped.transform.rotation.z = q.z();
    transformStamped.transform.rotation.w = q.w();

    br.sendTransform(transformStamped);
}

int main(int argc, char** argv) {

    ros::init(argc, argv, "my_tf2_broadcaster");

    // si el nodo privado tiene un parámetro llamado 'turtle', se lo toma como el nombre
    // sino se toma el segundo argumento como el nombre de la tortuga
    ros::NodeHandle private_node("~");
    if (!private_node.hasParam("turtle")) {
        if (argc != 2) {
            ROS_ERROR("need turtle name as argument");
            return -1;
        }
        turtle_name = argv[1];

    } else {
        private_node.getParam("turtle", turtle_name);
    }

    // se suscribe al topic turtle_name/pose
    ros::NodeHandle node;
    ros::Subscriber sub = node.subscribe(turtle_name + "/pose", 10, &poseCallback);

    ros::spin();
    return 0;
}
