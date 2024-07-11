#pragma once
#include"Subject.hpp"

class IDisplayElement
{
public:
	virtual void display()=0;
};

class ForecastDisplay :public IObserver, public IDisplayElement
{
private:
	float currentPressure = 29.92f;
	float lastPressure=5;
	shared_ptr<WeatherData> weatherData;
public:
	ForecastDisplay(shared_ptr<WeatherData>& WeatherDataObj):weatherData(WeatherDataObj) {
		weatherData->Register(this);
	}

	void Update(float temp, float humidity, float pressure) {
		lastPressure = currentPressure;
		currentPressure = pressure;
		display();
	}

	void display() {
		printf("Forecast: \n");
		if (currentPressure > lastPressure) {
			printf("Improving weather on the way!\n");
		}
		else if (currentPressure == lastPressure) {
			printf("More of the same\n");
		}
		else if (currentPressure < lastPressure) {
			printf("Watch out for cooler, rainy weather\n");
		}
	}
};