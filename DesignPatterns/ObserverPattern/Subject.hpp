#pragma once
#include"Observer.hpp"
#include<list>
#define list std::list
#define unique_ptr std::unique_ptr
#define shared_ptr std::shared_ptr
class ISubject
{
public:
    virtual ~ISubject() {};
    virtual void Register(IObserver* observer) = 0;
    virtual void Remove(IObserver* observer) = 0;
    virtual void Notify() = 0;
};

class WeatherData :public ISubject
{
private:
	list<IObserver*> observers;
	float temperature;
	float humidity;
	float pressure;

public:
	void Register(IObserver* o) {
		observers.push_back(o);
	}

	void Remove(IObserver* o) {
		for(auto it = observers.begin();it != observers.end();++it)
		{
			if (*it == o)
			{
				it = observers.erase(it);  
				break;
			}
		}
	}

	void Notify() {
		for (auto observer : observers)
		{
			observer->Update(temperature, humidity, pressure);
		}
	}

	void measurementsChanged() {
		Notify();
	}

	void setMeasurements(float atemperature, float ahumidity, float apressure) {
		temperature = atemperature;
		humidity = ahumidity;
		pressure = apressure;
		measurementsChanged();
	}

	float getTemperature() {
		return temperature;
	}

	float getHumidity() {
		return humidity;
	}

	float getPressure() {
		return pressure;
	}
};
