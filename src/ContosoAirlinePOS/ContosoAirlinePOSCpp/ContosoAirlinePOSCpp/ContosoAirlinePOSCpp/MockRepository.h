#pragma once
#include <sstream>
#include <chrono>
#include <ctime>
#include <time.h>
#include <iomanip>
#include "Airport.g.h"
#include "Flight.g.h"

#define NUMBER_OF_AIRPORT 7
const double FLIGHT_MULTIPLYING_FACTOR = 1.0;
const std::string FLIGHT_CODE_PREFIX ="CNA";
#define DAY_BRACKET 40;

namespace winrt::ContosoAirlinePOSCpp::implementation
{
	class MockRepository
	{
	private:
		MockRepository();
		MockRepository(const MockRepository& other) = delete;
		MockRepository operator=(const MockRepository& other) = delete;

	public:
		static MockRepository* CreateMockRepositoryInstace();		
		static void DeleteMockRepositoryInstance();		
		static MockRepository* m_pMockpRepo;

	public:
		winrt::ContosoAirlinePOSCpp::Airport SourceAirport();
		std::vector<ContosoAirlinePOSCpp::Airport> DestinationsAirport();
		std::vector<ContosoAirlinePOSCpp::Airport> GetAllAirports();
		void GenerateFlights();
		std::vector<int> GetNRandomNumbersInRange(int start, int end, int n);
		std::string GetFourDigitFlightCode(int code);
		int GetRandomNumberInRange(int start, int end);
		std::string TimeToString(std::time_t tInput);
		int ConvertSecondstoHours(int nSeconds);
		const std::string GetCurrentDateTime(std::time_t time_t);
		void CurrentDateTime(struct tm& tstruct);
		void ConvertFromStringToTime(std::string strInput, struct tm& tmStruct);
		void SplitDateTime(std::string strInput,std::string &strTime);
		std::vector<ContosoAirlinePOSCpp::Flight> SearchFlights(ContosoAirlinePOSCpp::Airport source, ContosoAirlinePOSCpp::Airport destination);
		winrt::ContosoAirlinePOSCpp::Airport m_airportSource;
		std::vector< ContosoAirlinePOSCpp::Airport> m_destinationAirport;
		std::vector<ContosoAirlinePOSCpp::Flight> m_schedules;
		
	};
}

