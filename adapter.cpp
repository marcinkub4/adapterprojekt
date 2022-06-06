#include <iostream> // implentacja biblioteki <iostream>. Umozliwia wykonywanie operacji na standardowych strumieniach wejscia/wyjscia. 
#include <cstdlib> // implentacja biblioteki <stdlib.h>. Zawiera funkcje ogólne takie jak konwersje, alokacja pamięci czy funkcje matematyczne.
#include <string> // Implementacja biblioteki <string>. Odpowiedzialna jest za obiektowe podejscie do ciągów znakow.
#include <unistd.h> // implementacja biblioteki aby użyć komendy sleep


using namespace std; // Za pomoca slow kluczowych using namespace informujemy kompilator, ze chcemy aby wszystkie funkcje, klasy i szablony nalezace do przestrzeni nazw nie wymagaly przedrostka. Wyraz wystepujacy po tych dwoch slowach kluczowych jest istniejaca nazwa przestrzeni. Dla standardowych bibliotek C++ jest to std.

typedef int Cable; /// konstruktor dla przyszłych klas


class EuropaSocketInterface /// Klasa: GniazdoEuropa 
{
public:
    virtual int voltage() = 0; /// virtual int- metoda wirtualna

    virtual Cable live() = 0;  /// virtual wraz z konstruktorem
    virtual Cable neutral() = 0; /// virtual wraz z konstruktorem
    virtual Cable earth() = 0; /// virtual wraz z konstruktorem
};


class USASocketInterface /// Klasa: Gniazdo USA (120V) 
{
public:
    virtual int voltage() = 0; /// virtual int- metoda wirtualna
    
    virtual Cable live() = 0; /// virtual wraz z konstruktorem
    virtual Cable neutral() = 0; /// virtual wraz z konstruktorem
    virtual Cable earth() = 0; /// virtual wraz z konstruktorem
};


class MeksykSocketInterface /// Klasa: Gniazdo Meksyk (127V) 
{
public:
    virtual int voltage() = 0; /// virtual int- metoda wirtualna, referencja do obiektu klasy podrzędnej
    
    virtual Cable live() = 0; /// virtual wraz z konstruktorem
    virtual Cable neutral() = 0; /// virtual wraz z konstruktorem
    virtual Cable earth() = 0; /// virtual wraz z konstruktorem
};


class KoreaPldSocketInterface /// Klasa: Gniazdo Korea Poludniowa (220V) 
{
public:
    virtual int voltage() = 0; /// virtual int- metoda wirtualna, referencja do obiektu klasy podrzędnej
    
    virtual Cable live() = 0; /// virtual wraz z konstruktorem
    virtual Cable neutral() = 0; /// virtual wraz z konstruktorem
    virtual Cable earth() = 0; /// virtual wraz z konstruktorem
};


class TaiwanSocketInterface /// Klasa: Gniazdo Taiwan (110V) 
{
public:
    virtual int voltage() = 0; /// virtual int- metoda wirtualna, referencja do obiektu klasy podrzędnej
    
    virtual Cable live() = 0; /// virtual wraz z konstruktorem
    virtual Cable neutral() = 0; /// virtual wraz z konstruktorem
    virtual Cable earth() = 0; /// virtual wraz z konstruktorem
};


class SocketEuropa : public EuropaSocketInterface /// Klasa: Główne wejscie Europa korzystająca z Klasy: GniazdoEuropa*/
{
public:
    int voltage() { return 230; } /// virtual int- metoda wirtualna, referencja do obiektu klasy głównej, zmiana wartości z 0 na 230
    
    Cable live() { return 1; } /// zmiana wartości z 0 na 1
    Cable neutral() { return -1; } /// zmiana wartości z 0 na -1
    Cable earth() { return 0; } /// zmiana wartości z 0 na 0
};


class AdapterUSA : public USASocketInterface /// Klasa: Adapter Europa -> USA koprzystająca z klasy: Docelowy Standard USA 
{
    EuropaSocketInterface* socket; /// wskaźnik socket do obiektu klasy podstawowej: Gniazdo Europa

public:
    void plugIn(EuropaSocketInterface* outlet) /// funkcja void plugIn nie zwracająca żadnych danych wraz z odniesieniem do klasy: Gniazdo Europa i wskaźnikiem outlet
    {
        socket = outlet; /// wskaźnik socket równa się wskaźnikowi outlet
    }

    int voltage() { return 120; } /// zmienna voltage, która zwraca nam wartość 120
    
    Cable live() { return socket->live(); } /// Cable live() klasy: Adapter Europa -> USA zwraca wskaźnik socket->live() z klasy: Gniazdo Europa na wartość 1
    Cable neutral() { return socket->neutral(); } /// Cable neutral() klasy: Adapter Europa -> USA zwraca wskaźnik socket->neutral() z klasy: Gniazdo Europa na wartość -1
    Cable earth() { return socket->earth(); } /// Cable earth() klasy: Adapter Europa -> USA zwraca wskaźnik socket->earth() z klasy: Gniazdo Europa na wartość 0
};


class AdapterMeksyk : public MeksykSocketInterface /// Klasa: Adapter Europa -> Meksyk koprzystająca z klasy: Docelowy Standard Meksyk 
{
    EuropaSocketInterface* socket; /// wskaźnik socket do obiektu klasy podstawowej: Gniazdo Europa

public:
    void plugIn(EuropaSocketInterface* outlet) /// funkcja void plugIn nie zwracająca żadnych danych wraz z odniesieniem do klasy: Gniazdo Europa i wskaźnikiem outlet
    {
        socket = outlet; /// wskaźnik socket równa się wskaźnikowi outlet
    }

    int voltage() { return 127; } /// zmienna voltage, która zwraca nam wartość 127
    
    Cable live() { return socket->live(); } /// Cable live() klasy: Adapter Europa -> Meksyk zwraca wskaźnik socket->live() z klasy: Gniazdo Europa na wartość 1
    Cable neutral() { return socket->neutral(); } /// Cable neutral() klasy: Adapter Europa -> Meksyk zwraca wskaźnik socket->neutral() z klasy: Gniazdo Europa na wartość -1
    Cable earth() { return socket->earth(); } /// Cable earth() klasy: Adapter Europa -> Meksyk zwraca wskaźnik socket->earth() z klasy: Gniazdo Europa na wartość 0
};


class AdapterKoreaPld : public KoreaPldSocketInterface /// Klasa: Adapter Europa -> KoreaPld koprzystająca z klasy: Docelowy Standard KoreaPld 
{
    EuropaSocketInterface* socket; /// wskaźnik socket do obiektu klasy podstawowej: Gniazdo Europa

public:
    void plugIn(EuropaSocketInterface* outlet) /// funkcja void plugIn nie zwracająca żadnych danych wraz z odniesieniem do klasy: Gniazdo Europa i wskaźnikiem outlet
    {
        socket = outlet; /// wskaźnik socket równa się wskaźnikowi outlet
    }

    int voltage() { return 220; } /// zmienna voltage, która zwraca nam wartość 220
    
    Cable live() { return socket->live(); } /// Cable live() klasy: Adapter Europa -> KoreaPld zwraca wskaźnik socket->live() z klasy: Gniazdo Europa na wartość 1
    Cable neutral() { return socket->neutral(); } /// Cable neutral() klasy: Adapter Europa -> KoreaPld zwraca wskaźnik socket->neutral() z klasy: Gniazdo Europa na wartość -1
    Cable earth() { return socket->earth(); } /// Cable earth() klasy: Adapter Europa -> KoreaPld zwraca wskaźnik socket->earth() z klasy: Gniazdo Europa na wartość 0
};


class AdapterTaiwan : public TaiwanSocketInterface /// Klasa: Adapter Europa -> Taiwan koprzystająca z klasy: Docelowy Standard Taiwan 
{
    EuropaSocketInterface* socket; /// wskaźnik socket do obiektu klasy podstawowej: Gniazdo Europa

public:
    void plugIn(EuropaSocketInterface* outlet) /// funkcja void plugIn nie zwracająca żadnych danych wraz z odniesieniem do klasy: Gniazdo Europa i wskaźnikiem outlet
    {
        socket = outlet; /// wskaźnik socket równa się wskaźnikowi outlet
    }

    int voltage() { return 110; } /// zmienna voltage, która zwraca nam wartość 110
    
    Cable live() { return socket->live(); } /// Cable live() klasy: Adapter Europa -> Taiwan zwraca wskaźnik socket->live() z klasy: Gniazdo Europa na wartość 1
    Cable neutral() { return socket->neutral(); } /// Cable neutral() klasy: Adapter Europa -> Taiwan zwraca wskaźnik socket->neutral() z klasy: Gniazdo Europa na wartość -1
    Cable earth() { return socket->earth(); } /// Cable earth() klasy: Adapter Europa -> Taiwan zwraca wskaźnik socket->earth() z klasy: Gniazdo Europa na wartość 0
};


class ElectricDeviceUSA /// Klasa: Urządzenie USA 
{
    USASocketInterface* power; /// wskaźnik do obiektu klasy podstawowej: Gniazdo USA

public:
    void plugIn(USASocketInterface* supply) /// funkcja void plugIn nie zwracająca żadnych danych wraz z odniesieniem do klasy: Gniazdo USA i wskaźnikiem supply
    {
        power = supply; /// wskaźnik power równa się wskaźnikowi supply
    }

    void deviceUSA()  /// funkcja void urządzenia
    {
        if (power->voltage() > 120) /// instrukcja if mocy odwołująca się do napięcia; jeżeli napięcie jest większe od 120 wyświetli komunikat za pomocą cout
        {
            cout << "Zle napiecie!" << endl; /// wyświetlenie nieprawidłowego napięcia
            return;
        }

        if (power->live() == 1 && power->neutral() == -1 && power->earth() == 0) /// instrukcja if - wskaźniki na zgodność z wartościami
        {
            cout << "Podlaczono pomyslnie." << endl; /// wyświetlenie poprawnego podłączenia
        }
    }
};


class ElectricDeviceMeksyk /// Klasa: Urządzenie Meksyk 
{
    MeksykSocketInterface* power; /// wskaźnik do obiektu klasy podstawowej: Gniazdo Meksyk

public:
    void plugIn(MeksykSocketInterface* supply) /// funkcja void plugIn nie zwracająca żadnych danych wraz z odniesieniem do klasy: Gniazdo Meksyk i wskaźnikiem supply
    {
        power = supply; /// wskaźnik power równa się wskaźnikowi supply
    }

    void deviceMeksyk() /// funkcja void urządzenia
    {
        if (power->voltage() > 127) /// instrukcja if mocy odwołująca się do napięcia; jeżeli napięcie jest większe od 127 wyświetli komunikat za pomocą cout
        {
            cout << "Zle napiecie!" << endl; /// wyświetlenie nieprawidłowego napięcia
            return;
        }

        if (power->live() == 1 && power->neutral() == -1 && power->earth() == 0) /// instrukcja if - wskaźniki na zgodność z wartościami
        {
            cout << "Podlaczono pomyslnie." << endl; /// wyświetlenie poprawnego podłączenia
        }
    }
};


class ElectricDeviceKoreaPld /// Klasa: Urządzenie KoreaPld 
{
    KoreaPldSocketInterface* power; /// wskaźnik do obiektu klasy podstawowej: Gniazdo Korea

public:
    void plugIn(KoreaPldSocketInterface* supply) /// funkcja void plugIn nie zwracająca żadnych danych wraz z odniesieniem do klasy: Gniazdo KoreaPld i wskaźnikiem supply
    {
        power = supply; /// wskaźnik power równa się wskaźnikowi supply
    }

    void deviceKorea() /// funkcja void urządzenia
    {
        if (power->voltage() > 220) /// instrukcja if mocy odwołująca się do napięcia; jeżeli napięcie jest większe od 220 wyświetli komunikat za pomocą cout
        {
            cout << "Zle napiecie!" << endl; /// wyświetlenie nieprawidłowego napięcia
            return;
        }

        if (power->live() == 1 && power->neutral() == -1 && power->earth() == 0) /// instrukcja if - wskaźniki na zgodność z wartościami
        {
            cout << "Podlaczono pomyslnie." << endl; /// wyświetlenie poprawnego podłączenia
        }
    }
};


class ElectricDeviceTaiwan /// Klasa: Urządzenie Taiwan 
{
    TaiwanSocketInterface* power; /// wskaźnik do obiektu klasy podstawowej: Gniazdo Taiwan

public:
    void plugIn(TaiwanSocketInterface* supply) /// funkcja void plugIn nie zwracająca żadnych danych wraz z odniesieniem do klasy: Gniazdo Taiwan i wskaźnikiem supply
    {
        power = supply; /// wskaźnik power równa się wskaźnikowi supply
    }

    void deviceTaiwan() /// funkcja void urządzenia
    {
        if (power->voltage() > 110) /// instrukcja if mocy odwołująca się do napięcia; jeżeli napięcie jest większe od 110 wyświetli komunikat za pomocą cout
        {
            cout << "Zle napiecie!" << endl; /// wyświetlenie nieprawidłowego napięcia
            return;
        }

        if (power->live() == 1 && power->neutral() == -1 && power->earth() == 0) /// instrukcja if - wskaźniki na zgodność z wartościami
        {
            cout << "Podlaczono pomyslnie." << endl; /// wyświetlenie poprawnego podłączenia
        }
    }
};


void menu() /// Menu programu Adapter 
{
    system("clear"); /// komenda clear czyści terminal w Linuxie

    cout << "======================\n";
    cout << "== Adaptery do wyboru: ==\n"; /// Naglówek z wyborem adapterów
    cout << "======================\n";
    cout << " \n";
    cout << "1) Europa - USA\n"; /// opcja nr 1
    cout << "2) Europa - Meksyk\n"; /// opcja nr 2
    cout << "3) Europa - Korea Południowa\n"; /// opcja nr 3
    cout << "4) Europa - Taiwan\n"; /// opcja nr 4
    cout << "5) Wyjdz z programu\n"; /// opcja nr 5
    cout << " \n";
    cout << "Wybierz numer dla konkretnego adapteru:    (1-5) \n"; /// informacja wyboru
}

int main() /// Główna funkcja programu Adapter 
{
    char opcja; /// zmienna inicjowana aby wybrać konkretną opcję od 1 do 5
    bool running = true; /// boolean 'running' wartością 'true'

    system("clear"); /// komenda clear czyści terminal w Linuxie

    while (running) /// pętla while z booleanem 'running' = true, będzie zawsze powracać do menu glównego po wykonaniu przypadku
    {
        menu(); /// inicjujemy menu
        cin >> opcja; /// komenda cin do wpisania opcji przez użytkownika

        switch (opcja) /// opcja wykonuje dany przypadek
        {
            case '1': /// opcja nr 1 wykonująca operację
            { 
                system("clear"); /// komenda clear czyści terminal w Linuxie

                cout << "Adapter USA 120 V" << endl; /// Wyświetlenie komunikatu jaki to konkretnie adapter

                SocketEuropa* socket = new SocketEuropa; /// 'new' - zwraca adres lokalizacji pamięci, której możemy od teraz używać do przechowywania wartości jakiegoś typu. Klasa Gniazdo Europa ze wskaźnikiem 'socket' tworzy nową lokalizację
                AdapterUSA* adapter = new AdapterUSA; /// 'new' - zwraca adres lokalizacji pamięci, której możemy od teraz używać do przechowywania wartości jakiegoś typu. Klasa Adapter USA ze wskaźnikiem 'adapter' tworzy nową lokalizację
                ElectricDeviceUSA* device = new ElectricDeviceUSA; /// 'new' - zwraca adres lokalizacji pamięci, której możemy od teraz używać do przechowywania wartości jakiegoś typu. Klasa Urządzenie USA ze wskaźnikiem 'device' tworzy nową lokalizację

                adapter->plugIn(socket); /// adapter wskaźnikiem do plugIn(socket)
                device->plugIn(adapter);  /// device wskaźnikiem do plugIn(adapter)

                device->deviceUSA(); /// odniesienie do funkcji void deviceUSA

                cout << "\n";

		sleep(5); /// uśpienie programu na 5 sekund następnie powrót do menu głównego
		
                break;
            }

            case '2': /// opcja nr 2 wykonująca operację
            {
                system("clear"); /// komenda clear czyści terminal w Linuxie

                cout << "Adapter Meksyk 127 V" << endl; /// Wyświetlenie komunikatu jaki to konkretnie adapter

                SocketEuropa* socket = new SocketEuropa; /// 'new' - zwraca adres lokalizacji pamięci, której możemy od teraz używać do przechowywania wartości jakiegoś typu. Klasa Gniazdo Europa ze wskaźnikiem 'socket' tworzy nową lokalizację
                AdapterMeksyk* adapter = new AdapterMeksyk; /// 'new' - zwraca adres lokalizacji pamięci, której możemy od teraz używać do przechowywania wartości jakiegoś typu. Klasa Adapter Meksyk ze wskaźnikiem 'adapter' tworzy nową lokalizację
                ElectricDeviceMeksyk* device = new ElectricDeviceMeksyk; /// 'new' - zwraca adres lokalizacji pamięci, której możemy od teraz używać do przechowywania wartości jakiegoś typu. Klasa Urządzenie Meksyk ze wskaźnikiem 'device' tworzy nową lokalizację

                adapter->plugIn(socket); /// adapter wskaźnikiem do plugIn(socket)
                device->plugIn(adapter); /// device wskaźnikiem do plugIn(adapter)

                device->deviceMeksyk(); /// odniesienie do funkcji void deviceMeksyk

                cout << "\n";

		sleep(5); /// uśpienie programu na 5 sekund następnie powrót do menu głównego
		
                break;
            }

            case '3': /// opcja nr 3 wykonująca operację
            {
                system("clear"); /// komenda clear czyści terminal w Linuxie

                cout << "Adapter Korea Poludniowa 220 V:\n" << endl; /// Wyświetlenie komunikatu jaki to konkretnie adapter

                SocketEuropa* socket = new SocketEuropa; /// 'new' - zwraca adres lokalizacji pamięci, której możemy od teraz używać do przechowywania wartości jakiegoś typu. Klasa Gniazdo Europa ze wskaźnikiem 'socket' tworzy nową lokalizację
                AdapterKoreaPld* adapter = new AdapterKoreaPld; /// 'new' - zwraca adres lokalizacji pamięci, której możemy od teraz używać do przechowywania wartości jakiegoś typu. Klasa Adapter KoreaPld ze wskaźnikiem 'adapter' tworzy nową lokalizację
                ElectricDeviceKoreaPld* device = new ElectricDeviceKoreaPld; /// 'new' - zwraca adres lokalizacji pamięci, której możemy od teraz używać do przechowywania wartości jakiegoś typu. Klasa Urządzenie KoreaPld ze wskaźnikiem 'device' tworzy nową lokalizację

                adapter->plugIn(socket); /// adapter wskaźnikiem do plugIn(socket)
                device->plugIn(adapter); /// device wskaźnikiem do plugIn(adapter)

                device->deviceKorea(); /// odniesienie do funkcji void deviceKorea

                cout << "\n";

		sleep(5); /// uśpienie programu na 5 sekund następnie powrót do menu głównego

                break;
            }
 
            case '4': /// opcja nr 4 wykonująca operację
            {
                system("clear"); /// komenda clear czyści terminal w Linuxie

                cout << "Adapter Taiwan 110 V:\n" << endl; /// Wyświetlenie komunikatu jaki to konkretnie adapter

                SocketEuropa* socket = new SocketEuropa; /// 'new' - zwraca adres lokalizacji pamięci, której możemy od teraz używać do przechowywania wartości jakiegoś typu. Klasa Gniazdo Europa ze wskaźnikiem 'socket' tworzy nową lokalizację
                AdapterTaiwan* adapter = new AdapterTaiwan; /// 'new' - zwraca adres lokalizacji pamięci, której możemy od teraz używać do przechowywania wartości jakiegoś typu. Klasa Adapter Taiwan ze wskaźnikiem 'adapter' tworzy nową lokalizację
                ElectricDeviceTaiwan* device = new ElectricDeviceTaiwan; /// 'new' - zwraca adres lokalizacji pamięci, której możemy od teraz używać do przechowywania wartości jakiegoś typu. Klasa Urządzenie Taiwan ze wskaźnikiem 'device' tworzy nową lokalizację

                adapter->plugIn(socket); /// adapter wskaźnikiem do plugIn(socket)
                device->plugIn(adapter); /// device wskaźnikiem do plugIn(adapter)

                device->deviceTaiwan(); /// odniesienie do funkcji void deviceTaiwan

                cout << "\n";

		sleep(5); /// uśpienie programu na 5 sekund następnie powrót do menu głównego
		
                break;
            }

            case '5': /// opcja nr 5 wykonująca operację
            {
                return EXIT_SUCCESS; /// zamknięcie programu
            }
        }
    }

    system("clear"); /// komenda clear czyści terminal w Linuxie
}

