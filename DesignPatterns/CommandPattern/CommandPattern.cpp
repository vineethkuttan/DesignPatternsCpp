#pragma once
#include "CeilingFan.hpp"
#include "Light.hpp"
#include<list>
#include<vector>
#include<sstream>
class RemoteControlWithUndo 
{
	std::vector<shared_ptr<ICommand>> onCommands;
	std::vector<shared_ptr<ICommand>> offCommands;
	shared_ptr<ICommand> undoCommand;

public:
	RemoteControlWithUndo() 
	{
		shared_ptr<ICommand> noCommand(new NoCommand());
		for (int i = 0; i < 7; i++)
		{
			onCommands.push_back(noCommand);
			offCommands.push_back(noCommand);
		}
		undoCommand = noCommand;
	}

	void setCommand(int slot, shared_ptr<ICommand> onCommand, shared_ptr<ICommand> offCommand) 
	{
		onCommands[slot] = onCommand;
		offCommands[slot] = offCommand;
	}

	void onButtonWasPushed(int slot)
	{
		onCommands[slot]->Execute();
		undoCommand = onCommands[slot];
	}

	void offButtonWasPushed(int slot) 
	{
		offCommands[slot]->Execute();
		undoCommand = offCommands[slot];
	}

	void undoButtonWasPushed() {
		undoCommand->Undo();
	}

	string toString() {
		std::ostringstream oss;
		oss << "------ Remote Control -------\n";
		for (int i = 0; i < onCommands.size(); ++i) {
			oss << "[slot " << i << "] " << typeid(*onCommands[i]).name()
				<< "    " << typeid(*offCommands[i]).name() << "\n";
		}
		oss << "[undo] " << typeid(*undoCommand).name() << "\n";
		return oss.str();
	}
};

int main()
{
	shared_ptr<RemoteControlWithUndo> remoteControl(new RemoteControlWithUndo());

	shared_ptr<Light> livingRoomLight(new Light("Living Room"));

	shared_ptr<LightOnCommand> livingRoomLightOn(new LightOnCommand(livingRoomLight));
	shared_ptr<LightOffCommand> livingRoomLightOff(new LightOffCommand(livingRoomLight));

	remoteControl->setCommand(0, livingRoomLightOn, livingRoomLightOff);

	remoteControl->onButtonWasPushed(0);
	remoteControl->offButtonWasPushed(0);
	std::cout << remoteControl.get() << " remoteControl Address\n";
	remoteControl->undoButtonWasPushed();
	remoteControl->offButtonWasPushed(0);
	remoteControl->onButtonWasPushed(0);
	std::cout << remoteControl.get() << " remoteControl Address\n";
	remoteControl->undoButtonWasPushed();

	shared_ptr<CeilingFan> ceilingFan(new CeilingFan("Living Room"));

	shared_ptr<CeilingFanMediumCommand> ceilingFanMedium(new CeilingFanMediumCommand(ceilingFan));
	shared_ptr<CeilingFanHighCommand> ceilingFanHigh(new CeilingFanHighCommand(ceilingFan));
	shared_ptr<CeilingFanOffCommand> ceilingFanOff(new CeilingFanOffCommand(ceilingFan));

	remoteControl->setCommand(0, ceilingFanMedium, ceilingFanOff);
	remoteControl->setCommand(1, ceilingFanHigh, ceilingFanOff);

	remoteControl->onButtonWasPushed(0);
	remoteControl->offButtonWasPushed(0);
	std::cout << remoteControl.get() << " remoteControl Address\n";
	remoteControl->undoButtonWasPushed();

	remoteControl->onButtonWasPushed(1);
	std::cout << remoteControl.get() << " remoteControl Address\n";
	remoteControl->undoButtonWasPushed();
	std::cout << remoteControl->toString().c_str() << "\n";
	return 0;
}