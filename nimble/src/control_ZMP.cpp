#include <chrono>
#include <functional>
#include <memory>
#include <string>
#include <iostream>
#include "ZMP/zmpupdate.h"
#include "previewControl/previewClass.h"
#include "zmpNode/zmpnode.h"


using namespace std;
using namespace zmpUpdate;
ofstream in;

std::string keyboardInput() {
    std::string line;
    std::getline(std::cin,line);
    return line;
}
void command(std::string line);
int main(int argc, char *argv[])
{
    rclcpp::init(argc, argv);
    auto node = std::make_shared<ZMPNode>();

    remove("ZMPX.txt");
    remove("ZMPY.txt");
    remove("COM.txt");
    ZMPupdate myZMP;
    PreviewClass cartTableModel;

    double x_cart[3]={0};
    double y_cart[3]={0};
    double steps=-1;
    double time=0;
    std::string line2;
    auto future = std::async(std::launch::async, keyboardInput);
    while (steps<2000){
        rclcpp::Rate loopRate(100);

        if(future.wait_for(std::chrono::seconds(0))==std::future_status::ready){
            auto line=future.get();
            future=std::async(std::launch::async,keyboardInput);
            node->command(line);

        }

        //startingTime
        if (time>=4.97)
            int a=0;
        if(myZMP.RemainingDSTime<0)
            int a=0;

        if(time>2){
            if(myZMP.RemainingSSTime<=0){
                myZMP.RemainingDSTime=myZMP.desiredStepTime*myZMP.DS_SS_Ratio;
                myZMP.RemainingSSTime=myZMP.desiredStepTime*(1-myZMP.DS_SS_Ratio);
                steps++;
                steps=myZMP.stepCount;
            }
            else{
                if (myZMP.RemainingDSTime>=0)
                    myZMP.RemainingDSTime-=SamplingTime;
                if (myZMP.RemainingSSTime>0 && myZMP.RemainingDSTime<=0)
                    myZMP.RemainingSSTime-=SamplingTime;
                if (time>5 && time<5.2)
                    myZMP.setNextFootHold(0.35);

            }
            myZMP.UpdateZMPData(myZMP.RemainingSSTime,myZMP.RemainingDSTime);
            cartTableModel.previewControl(x_cart,myZMP.ZMPX);
            cartTableModel.previewControl(y_cart,myZMP.ZMPY);

            node->PublishComRefx(x_cart[1]);
            node->PublishComRefy(y_cart[1]);

            rclcpp::spin_some(node);
            loopRate.sleep();
        }
        time+=SamplingTime;


    }

    rclcpp::shutdown();
    return 0;
}
