// FacadePattern.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "PopcornPopper.hpp"

class HomeTheaterFacade {
private:
	shared_ptr<Amplifier> ampl;
	shared_ptr<Tuner> tuner;
	shared_ptr<StreamingPlayer> player;
	shared_ptr<CdPlayer> cd;
	shared_ptr<Projector> projector;
	shared_ptr<TheaterLights> lights;
	shared_ptr<Screen> screen;
	shared_ptr<PopcornPopper> popper;
public:
	HomeTheaterFacade(shared_ptr<Amplifier>& _amp,
		shared_ptr<Tuner>& _tuner,
		shared_ptr<StreamingPlayer>& _player,
		shared_ptr<Projector>& _projector,
		shared_ptr<Screen>& _screen,
		shared_ptr<TheaterLights>& _lights,
		shared_ptr<PopcornPopper>& _popper)
	{
		ampl = _amp;
		tuner = _tuner;
		player = _player;
		projector = _projector;
		screen = _screen;
		lights = _lights;
		popper = _popper;
	}
	void watchMovie(string movie)
	{
		cout << "Get ready to watch a movie...\n";
		popper->on();
		popper->pop();
		lights->dim(10);
		screen->down();
		projector->on();
		projector->wideScreenMode();
		ampl->on();
		ampl->setStreamingPlayer(player);
		ampl->setSurroundSound();
		ampl->setVolume(5);
		player->on();
		player->play(movie);
	}
	void endMovie()
	{
		cout << "Shutting movie theater down...\n";
		popper->off();
		lights->on();
		screen->up();
		projector->off();
		ampl->off();
		player->stop();
		player->off();
	}

	void listenToRadio(double frequency)
	{
		cout << "Tuning in the airwaves...\n";
		tuner->on();
		tuner->setFrequency(frequency);
		ampl->on();
		ampl->setVolume(5);
		ampl->setTuner(tuner);
	}

	void endRadio()
	{
		cout << "Shutting down the tuner...\n";
		tuner->off();
		ampl->off();
	}
};

int main()
{
	shared_ptr<Amplifier> ampl(new Amplifier("Amplifier"));
	shared_ptr<Tuner> tuner(new Tuner("AM/FM Tuner"));
	shared_ptr<StreamingPlayer> player=std::make_shared<StreamingPlayer>("Streaming Player");
	shared_ptr<CdPlayer> cd=std::make_shared<CdPlayer>("CD Player", ampl);
	shared_ptr<Projector> projector=std::make_shared<Projector>("Projector", player);
	shared_ptr<TheaterLights> lights=std::make_shared<TheaterLights>("Theater Ceiling Lights");
	shared_ptr<Screen> screen=std::make_shared<Screen>("Theater Screen");
	shared_ptr<PopcornPopper> popper=std::make_shared<PopcornPopper>("Popcorn Popper");
	shared_ptr<HomeTheaterFacade> homeTheater=std::make_shared<HomeTheaterFacade>(ampl, tuner, player,projector, screen, lights, popper);

	homeTheater->watchMovie("Raiders of the Lost Ark");
	homeTheater->endMovie();
}
