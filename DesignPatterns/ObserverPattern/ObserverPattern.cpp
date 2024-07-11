#include "DisplayElements.hpp"

int main()
{
	shared_ptr<WeatherData> weatherData(new WeatherData());
	unique_ptr<ForecastDisplay> forecastDisplay(new ForecastDisplay(weatherData));

	weatherData->setMeasurements(80, 65, 30.4);
	weatherData->setMeasurements(82, 70, 29.2);
	weatherData->setMeasurements(78, 90, 29.2);

	weatherData->Remove(forecastDisplay.get());
	weatherData->setMeasurements(62, 90, 28.1f);
}
