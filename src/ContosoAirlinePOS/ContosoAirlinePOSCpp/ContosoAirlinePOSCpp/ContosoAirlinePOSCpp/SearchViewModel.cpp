#include "pch.h"
#include "SearchViewModel.h"
#include "SearchViewModel.g.cpp"

namespace winrt::ContosoAirlinePOSCpp::implementation
{
    SearchViewModel::SearchViewModel()
    {
        m_bookingResults = winrt::single_threaded_observable_vector<BookingResult>();

        BookingResult bookingResult1;
        bookingResult1.SerialNumber(1);
        bookingResult1.CustomerName(L"John Doe");
        bookingResult1.ContactNumber(L"8796079680");
        bookingResult1.BookingID(90001);
        bookingResult1.FlightNumber(L"CNA0233");
        bookingResult1.Source(L"JFK");
        bookingResult1.Destination(L"LAX");
        m_bookingResults.Append(bookingResult1);

        BookingResult bookingResult2;
        bookingResult2.SerialNumber(1);
        bookingResult2.CustomerName(L"John Doe");
        bookingResult2.ContactNumber(L"8796079680");
        bookingResult2.BookingID(90001);
        bookingResult2.FlightNumber(L"CNA0233");
        bookingResult2.Source(L"JFK");
        bookingResult2.Destination(L"LAX");
        m_bookingResults.Append(bookingResult2);

        BookingResult bookingResult3;
        bookingResult3.SerialNumber(1);
        bookingResult3.CustomerName(L"John Doe");
        bookingResult3.ContactNumber(L"8796079680");
        bookingResult3.BookingID(90001);
        bookingResult3.FlightNumber(L"CNA0233");
        bookingResult3.Source(L"JFK");
        bookingResult3.Destination(L"LAX");
        m_bookingResults.Append(bookingResult3);

        BookingResult bookingResult4;
        bookingResult4.SerialNumber(1);
        bookingResult4.CustomerName(L"John Doe");
        bookingResult4.ContactNumber(L"8796079680");
        bookingResult4.BookingID(90001);
        bookingResult4.FlightNumber(L"CNA0233");
        bookingResult4.Source(L"JFK");
        bookingResult4.Destination(L"LAX");
        m_bookingResults.Append(bookingResult4);

        BookingResult bookingResult5;
        bookingResult5.SerialNumber(1);
        bookingResult5.CustomerName(L"John Doe");
        bookingResult5.ContactNumber(L"8796079680");
        bookingResult5.BookingID(90001);
        bookingResult5.FlightNumber(L"CNA0233");
        bookingResult5.Source(L"JFK");
        bookingResult5.Destination(L"LAX");
        m_bookingResults.Append(bookingResult5);
    }

    Windows::Foundation::Collections::IObservableVector<ContosoAirlinePOSCpp::BookingResult> SearchViewModel::SearchResults()
    {
        return m_bookingResults;
    }
    winrt::event_token SearchViewModel::PropertyChanged(Microsoft::UI::Xaml::Data::PropertyChangedEventHandler const& handler)
    {
        return m_propertyChanged.add(handler);
    }
    void SearchViewModel::PropertyChanged(winrt::event_token const& token) noexcept
    {
        m_propertyChanged.remove(token);
    }
}
