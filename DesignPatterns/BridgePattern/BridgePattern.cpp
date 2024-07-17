// BridgePattern.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "DeviceRemoteControls.hpp"

int main()
{
    shared_ptr<Device> sonyDevice = std::make_shared<SonyTv>();
    shared_ptr<Device> samsungDevice = std::make_shared<SamsungTv>();
    shared_ptr<RemoteControl> Sony = std::make_shared<RemoteControl>(sonyDevice);
    shared_ptr<AdvancedRemoteControl> Samsung = std::make_shared<AdvancedRemoteControl>(samsungDevice);
    Sony->turnOn();
    Samsung->turnOn();
    Samsung->setChannel(5);
    Sony->turnOff();
    Samsung->turnOff();
}
