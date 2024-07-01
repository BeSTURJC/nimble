#include "zmpnode.h"

void ZMPNode::call_back_carTarget(const nimble_interfaces::msg::CartesianTrajectory & cart_target_msg)
{
    shared_data_.cart_target = cart_target_msg;  //almacenamiento del mensaje en la estructura de datos
    processData();  //llamada a la funcion de procesamiento

}

void ZMPNode::call_back_ModifiedStepTarget(const nimble_interfaces::msg::TherapyRequirements & step_target_msg)
{

    shared_data_.modified_step_target = step_target_msg;
    processData();

}
void ZMPNode::call_back_ImposedStepTarget(const nimble_interfaces::msg::TherapyRequirements & step_target_msg)
{

    shared_data_.imposed_step_target = step_target_msg;
    processData();

}

void ZMPNode::call_back_framestate(const nimble_interfaces::msg::FrameState & frame_state_msg)
{
    shared_data_.frame_state = frame_state_msg;
    processData();

}

/* void call_back_cablestate(const sensor_msgs::msg::JointState & cables_state_msg)
{
    shared_data_.cables_state = cables_state_msg;
    processData();

}

void call_back_FSR(const std_msgs::msg::ByteMultiArray & FSR_msg)
{
    shared_data_.FSR = FSR_msg;
    processData();
}*/

//Funcion para procesamiento y publicacion
void ZMPNode::processData() {

}

// Callback ejecutado cada cierto tiempo (eliminar si no se usa)
void ZMPNode::timer_callback()
{


}

void ZMPNode::PublishComRefx(double data){
    std_msgs::msg::Float32 data1;
    data1.data=data;
    publisher_COMx->publish(data1);
}
void ZMPNode::PublishComRefy(double data){
    std_msgs::msg::Float32 data1;
    data1.data=data;
    publisher_COMy->publish(data1);
}
void ZMPNode::PublishPosReference(double reference){
    std_msgs::msg::Float32 data1;
    data1.data=reference;
    publisher_posReference->publish(data1);
}
void ZMPNode::PublishVelReference(double reference){
    std_msgs::msg::Float32 data1;
    data1.data=reference;
    publisher_velReference->publish(data1);
}
void ZMPNode::PublishCommand(double reference){
    std_msgs::msg::Float32 data1;
    data1.data=reference;
    publisher_ControlMode->publish(data1);
}
//void ZMPNode::PublishCommand(std::string reference){
//    std::cout<<reference<<std::endl;
//    std_msgs::msg::String data1;
//    data1.data=reference;
//    publisher_ControlMode->publish(data1);
//}
void ZMPNode::command(std::string line){
    size_t pos;
    float numericValue;
    char aux=line[0];
    if (line=="s" || line=="VELOCITY" || line =="POSITION" || line =="SENSORPO" || line =="SENSORVE" || line =="MPC" || line =="VERBOSE" ||
            line =="Poserror"){
        aux='a';
    }

    switch (aux) {
    case 'P':

        numericValue = std::stof(line.substr(1), &pos);
        this->PublishPosReference(numericValue);
        break;

    case 'V':
        numericValue = std::stof(line.substr(1), &pos);
        this->PublishVelReference(numericValue);
        break;
    default:
        if (line=="POSITION")
        {this->PublishCommand(1);}
        else if (line=="VELOCITY")
        {this->PublishCommand(2);}
        else if (line=="SENSORPO")
        {this->PublishCommand(3);}
        else if (line=="SENSORVE")
        {this->PublishCommand(4);}
        else if (line=="MPC")
        {this->PublishCommand(5);}
        else if (line=="s")
        {this->PublishCommand(6);}
        else if (line=="VERBOSE")
        {this->PublishCommand(7);}
        else if (line=="a")
        {this->PublishCommand(8);}
        else if (line=="d")
        {this->PublishCommand(9);}
        else if (line=="w")
        {this->PublishCommand(10);}
        else if (line=="q")
        {this->PublishCommand(11);}
        else if (line=="e")
        {this->PublishCommand(12);}

        else{
            std::cout<<"Not a valid Command"<<std::endl;
        }
        break;
    }

}



