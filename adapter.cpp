#include <iostream> // implentacja biblioteki <iostream>. Umozliwia wykonywanie operacji na standardowych strumieniach wejscia/wyjscia. 
#include <cstdlib> // implentacja biblioteki <stdlib.h>. Zawiera funkcje ogólne takie jak konwersje, alokacja pamięci czy funkcje matematyczne.
#include <string> // Implementacja biblioteki <string>. Odpowiedzialna jest za obiektowe podejscie do ciągów znakow.
#include <unistd.h> // implementacja biblioteki aby użyć komendy sleep


using namespace std; // Za pomoca slow kluczowych using namespace informujemy kompilator, ze chcemy aby wszystkie funkcje, klasy i szablony nalezace do przestrzeni nazw nie wymagaly przedrostka. Wyraz wystepujacy po tych dwoch slowach kluczowych jest istniejaca nazwa przestrzeni. Dla standardowych bibliotek C++ jest to std.

typedef int Cable; /**< konstruktor dla przyszłych klas */

class EuropaSocketInterface /// Klasa: Gniazdo Europa 
{
public:
    virtual int voltage() = 0; /**< virtual int - metoda wirtualna */

    virtual Cable live() = 0;  /**< virtual wraz z konstruktorem */
    virtual Cable neutral() = 0; /**< virtual wraz z konstruktorem */
    virtual Cable earth() = 0; /**< virtual wraz z konstruktorem */
};


class USASocketInterface /// Klasa: Gniazdo USA (120V) 
{
public:
    virtual int voltage() = 0; /**< virtual int - metoda wirtualna */
    
    virtual Cable live() = 0; /**< virtual wraz z konstruktorem */
    virtual Cable neutral() = 0; /**< virtual wraz z konstruktorem */
    virtual Cable earth() = 0; /**< virtual wraz z konstruktorem */
};


class MeksykSocketInterface /// Klasa: Gniazdo Meksyk (127V) 
{
public:
    virtual int voltage() = 0; /**< virtual int - metoda wirtualna, referencja do obiektu klasy podrzędnej */
    
    virtual Cable live() = 0; /**< virtual wraz z konstruktorem */
    virtual Cable neutral() = 0; /**< virtual wraz z konstruktorem */
    virtual Cable earth() = 0; /**< virtual wraz z konstruktorem */
};


class KoreaPldSocketInterface /// Klasa: Gniazdo Korea Poludniowa (220V) 
{
public:
    virtual int voltage() = 0; /**< virtual int - metoda wirtualna, referencja do obiektu klasy podrzędnej */
    
    virtual Cable live() = 0; /**< virtual wraz z konstruktorem */
    virtual Cable neutral() = 0; /**< virtual wraz z konstruktorem */
    virtual Cable earth() = 0; /**< virtual wraz z konstruktorem */
};


class TaiwanSocketInterface /// Klasa: Gniazdo Taiwan (110V) 
{
public:
    virtual int voltage() = 0; /**< virtual int - metoda wirtualna, referencja do obiektu klasy podrzędnej */
    
    virtual Cable live() = 0; /**< virtual wraz z konstruktorem */
    virtual Cable neutral() = 0; /**< virtual wraz z konstruktorem */
    virtual Cable earth() = 0; /**< virtual wraz z konstruktorem */
};


class SocketEuropa : public EuropaSocketInterface /// Klasa: Główne wejscie Europa korzystająca z Klasy: GniazdoEuropa 
{
public:
    int voltage() { return 230; } /**< virtual int - metoda wirtualna, referencja do obiektu klasy głównej, zmiana wartości z 0 na 230 */
    
    Cable live() { return 1; } /**< zmiana wartości z 0 na 1 */
    Cable neutral() { return -1; } /**< zmiana wartości z 0 na -1 */
    Cable earth() { return 0; } /**< zmiana wartości z 0 na 0 */
};


class AdapterUSA : public USASocketInterface /// Klasa: Adapter Europa -> USA koprzystająca z klasy: Docelowy Standard USA 
{
    EuropaSocketInterface* socket; /**< wskaźnik socket do obiektu klasy podstawowej: Gniazdo Europa */

public:
    void plugIn(EuropaSocketInterface* outlet) /**< funkcja void plugIn nie zwracająca żadnych danych wraz z odniesieniem do klasy: Gniazdo Europa i wskaźnikiem outlet */
    { 
        socket = outlet; /// wskaźnik socket równa się wskaźnikowi outlet 
    }

    int voltage() { return 120; } /**< zmienna voltage, która zwraca nam wartość 120 */
    
    Cable live() { return socket->live(); } /**< Cable live() klasy: Adapter Europa -> USA zwraca wskaźnik socket->live() z klasy: Gniazdo Europa na wartość 1 */
    Cable neutral() { return socket->neutral(); } /**< Cable neutral() klasy: Adapter Europa -> USA zwraca wskaźnik socket->neutral() z klasy: Gniazdo Europa na wartość -1 */
    Cable earth() { return socket->earth(); } /**< Cable earth() klasy: Adapter Europa -> USA zwraca wskaźnik socket->earth() z klasy: Gniazdo Europa na wartość 0 */
};


class AdapterMeksyk : public MeksykSocketInterface /// Klasa: Adapter Europa -> Meksyk koprzystająca z klasy: Docelowy Standard Meksyk
{
    EuropaSocketInterface* socket; /**< wskaźnik socket do obiektu klasy podstawowej: Gniazdo Europa */

public:
    void plugIn(EuropaSocketInterface* outlet) /**< funkcja void plugIn nie zwracająca żadnych danych wraz z odniesieniem do klasy: Gniazdo Europa i wskaźnikiem outlet */
    {
        socket = outlet; /// wskaźnik socket równa się wskaźnikowi outlet 
    }

    int voltage() { return 127; } /**< zmienna voltage, która zwraca nam wartość 127 */
    
    Cable live() { return socket->live(); } /**< Cable live() klasy: Adapter Europa -> Meksyk zwraca wskaźnik socket->live() z klasy: Gniazdo Europa na wartość 1 */
    Cable neutral() { return socket->neutral(); } /**< Cable neutral() klasy: Adapter Europa -> Meksyk zwraca wskaźnik socket->neutral() z klasy: Gniazdo Europa na wartość -1 */
    Cable earth() { return socket->earth(); } /**< Cable earth() klasy: Adapter Europa -> Meksyk zwraca wskaźnik socket->earth() z klasy: Gniazdo Europa na wartość 0 */
};


class AdapterKoreaPld : public KoreaPldSocketInterface /// Klasa: Adapter Europa -> KoreaPld koprzystająca z klasy: Docelowy Standard KoreaPld 
{
    EuropaSocketInterface* socket; /**< wskaźnik socket do obiektu klasy podstawowej: Gniazdo Europa */

public:
    void plugIn(EuropaSocketInterface* outlet) /**< funkcja void plugIn nie zwracająca żadnych danych wraz z odniesieniem do klasy: Gniazdo Europa i wskaźnikiem outlet */
    {
        socket = outlet; /// wskaźnik socket równa się wskaźnikowi outlet 
    }

    int voltage() { return 220; } /**< zmienna voltage, która zwraca nam wartość 220 */
    
    Cable live() { return socket->live(); } /**< Cable live() klasy: Adapter Europa -> KoreaPld zwraca wskaźnik socket->live() z klasy: Gniazdo Europa na wartość 1 */
    Cable neutral() { return socket->neutral(); } /**< Cable neutral() klasy: Adapter Europa -> KoreaPld zwraca wskaźnik socket->neutral() z klasy: Gniazdo Europa na wartość -1 */
    Cable earth() { return socket->earth(); } /**< Cable earth() klasy: Adapter Europa -> KoreaPld zwraca wskaźnik socket->earth() z klasy: Gniazdo Europa na wartość 0 */
};


class AdapterTaiwan : public TaiwanSocketInterface /// Klasa: Adapter Europa -> Taiwan koprzystająca z klasy: Docelowy Standard Taiwan 
{
    EuropaSocketInterface* socket; /**< wskaźnik socket do obiektu klasy podstawowej: Gniazdo Europa */

public:
    void plugIn(EuropaSocketInterface* outlet) /**< funkcja void plugIn nie zwracająca żadnych danych wraz z odniesieniem do klasy: Gniazdo Europa i wskaźnikiem outlet */
    {
        socket = outlet; /// wskaźnik socket równa się wskaźnikowi outlet 
    }

    int voltage() { return 110; } /**< zmienna voltage, która zwraca nam wartość 110 */
    
    Cable live() { return socket->live(); } /**< Cable live() klasy: Adapter Europa -> Taiwan zwraca wskaźnik socket->live() z klasy: Gniazdo Europa na wartość 1 */
    Cable neutral() { return socket->neutral(); } /**< Cable neutral() klasy: Adapter Europa -> Taiwan zwraca wskaźnik socket->neutral() z klasy: Gniazdo Europa na wartość -1 */
    Cable earth() { return socket->earth(); } /**< Cable earth() klasy: Adapter Europa -> Taiwan zwraca wskaźnik socket->earth() z klasy: Gniazdo Europa na wartość 0 */
};


class ElectricDeviceUSA /// Klasa: Urządzenie USA 
{
    USASocketInterface* power; /**< wskaźnik do obiektu klasy podstawowej: Gniazdo USA */

public:
    void plugIn(USASocketInterface* supply) /**< funkcja void plugIn nie zwracająca żadnych danych wraz z odniesieniem do klasy: Gniazdo USA i wskaźnikiem supply */
    {
        power = supply; /// wskaźnik power równa się wskaźnikowi supply 
    }

    void deviceUSA()  /**< funkcja void urządzenia */
    {
        if (power->voltage() > 120) /**< instrukcja if mocy odwołująca się do napięcia; jeżeli napięcie jest większe od 120 wyświetli komunikat za pomocą cout */
        {
            cout << "Zle napiecie!" << endl; /**< wyświetlenie nieprawidłowego napięcia */
            return;
        }

        if (power->live() == 1 && power->neutral() == -1 && power->earth() == 0) /**< instrukcja if - wskaźniki na zgodność z wartościami */
        {
            cout << "Podlaczono pomyslnie." << endl; /**< wyświetlenie poprawnego podłączenia */
        }
    }
};


class ElectricDeviceMeksyk /// Klasa: Urządzenie Meksyk 
{
    MeksykSocketInterface* power; /**< wskaźnik do obiektu klasy podstawowej: Gniazdo Meksyk */

public:
    void plugIn(MeksykSocketInterface* supply) /**< funkcja void plugIn nie zwracająca żadnych danych wraz z odniesieniem do klasy: Gniazdo Meksyk i wskaźnikiem supply */
    {
        power = supply; /// wskaźnik power równa się wskaźnikowi supply 
    }

    void deviceMeksyk() /**< funkcja void urządzenia */
    {
        if (power->voltage() > 127) /**< instrukcja if mocy odwołująca się do napięcia; jeżeli napięcie jest większe od 127 wyświetli komunikat za pomocą cout */
        {
            cout << "Zle napiecie!" << endl; /**< wyświetlenie nieprawidłowego napięcia */
            return;
        }

        if (power->live() == 1 && power->neutral() == -1 && power->earth() == 0) /**< instrukcja if - wskaźniki na zgodność z wartościami */
        {
            cout << "Podlaczono pomyslnie." << endl; /**< wyświetlenie poprawnego podłączenia */
        }
    }
};


class ElectricDeviceKoreaPld /// Klasa: Urządzenie KoreaPld 
{
    KoreaPldSocketInterface* power; /**< wskaźnik do obiektu klasy podstawowej: Gniazdo Korea */

public:
    void plugIn(KoreaPldSocketInterface* supply) /**< funkcja void plugIn nie zwracająca żadnych danych wraz z odniesieniem do klasy: Gniazdo KoreaPld i wskaźnikiem supply */
    {
        power = supply; /// wskaźnik power równa się wskaźnikowi supply 
    }

    void deviceKorea() /**< funkcja void urządzenia */
    {
        if (power->voltage() > 220) /**< instrukcja if mocy odwołująca się do napięcia; jeżeli napięcie jest większe od 220 wyświetli komunikat za pomocą cout */
        {
            cout << "Zle napiecie!" << endl; /**< wyświetlenie nieprawidłowego napięcia */
            return;
        }

        if (power->live() == 1 && power->neutral() == -1 && power->earth() == 0) /**< instrukcja if - wskaźniki na zgodność z wartościami */
        {
            cout << "Podlaczono pomyslnie." << endl; /**< wyświetlenie poprawnego podłączenia */
        }
    }
};


class ElectricDeviceTaiwan /// Klasa: Urządzenie Taiwan 
{
    TaiwanSocketInterface* power; /**< wskaźnik do obiektu klasy podstawowej: Gniazdo Taiwan */

public:
    void plugIn(TaiwanSocketInterface* supply) /**< funkcja void plugIn nie zwracająca żadnych danych wraz z odniesieniem do klasy: Gniazdo Taiwan i wskaźnikiem supply */
    {
        power = supply; /// wskaźnik power równa się wskaźnikowi supply 
    }

    void deviceTaiwan() /**< funkcja void urządzenia */
    {
        if (power->voltage() > 110) /**< instrukcja if mocy odwołująca się do napięcia; jeżeli napięcie jest większe od 110 wyświetli komunikat za pomocą cout */
        {
            cout << "Zle napiecie!" << endl; /**< wyświetlenie nieprawidłowego napięcia */
            return;
        }

        if (power->live() == 1 && power->neutral() == -1 && power->earth() == 0) /**< instrukcja if - wskaźniki na zgodność z wartościami */
        {
            cout << "Podlaczono pomyslnie." << endl; /**< wyświetlenie poprawnego podłączenia */
        }
    }
};


///////////////////////////////////////////////////////////////
/// Menu programu Adapter posiada 5 opcji do wyboru adapteru,
/// wcześniej komenda clear czyści terminal w systemie Linux.
/// Na koniec prosi użytkownika o wybranie opcji od 1 do 5.
void menu()
{
    system("clear"); 

    cout << "======================\n";
    cout << "== Adaptery do wyboru: ==\n"; 
    cout << "======================\n";
    cout << " \n";
    cout << "1) Europa - USA\n"; 
    cout << "2) Europa - Meksyk\n";
    cout << "3) Europa - Korea Południowa\n"; 
    cout << "4) Europa - Taiwan\n"; 
    cout << "5) Wyjdz z programu\n"; 
    cout << " \n";
    cout << "Wybierz numer dla konkretnego adapteru:    (1-5) \n";
}



///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// Główna funkcja programu Adapter. Na początku definiujemy zmienną 'opcja', która w kolejnych krokach umożliwi nam wybór interesującego nas adaptera.
/// Definiujemy boolean 'running' który połączony jest z pętlą while - dopóki wartość będzie 'true' to będzie wykonywać naszą pętlę.
/// Przywołujemy menu główne z funkcji void menu(), użytkownik wpisuje cyfrę od 1 do 5. Wybór odpowiedniej cyfry wywołuje konkretny warunek (case) w instrukcji switch.
///
/// W zależności od wybranej opcji, zmienia nam parametry adaptera końcowego, a następnie wyświetla nam jaki typ adaptera wybraliśmy. 
///
/// Opcje od 1 do 4 wybierają nam rodzaj adapteru, natomiast opcja 5 wychodzi nam z programu.
int main() 
{
    char opcja;
    bool running = true; 
    
    system("clear");

    while (running)
    {
        menu(); 
        cin >> opcja; 

        switch (opcja) 
        {
            case '1':
            { 
                system("clear"); 

                cout << "Adapter USA 120 V" << endl;

                SocketEuropa* socket = new SocketEuropa;
                AdapterUSA* adapter = new AdapterUSA; 
                ElectricDeviceUSA* device = new ElectricDeviceUSA; 

                adapter->plugIn(socket);
                device->plugIn(adapter); 

                device->deviceUSA(); 

                cout << "\n";

		sleep(5); 
		
                break;
            }

            case '2': 
            {
                system("clear");

                cout << "Adapter Meksyk 127 V" << endl; 

                SocketEuropa* socket = new SocketEuropa; 
                AdapterMeksyk* adapter = new AdapterMeksyk; 
                ElectricDeviceMeksyk* device = new ElectricDeviceMeksyk; 

                adapter->plugIn(socket); 
                device->plugIn(adapter); 

                device->deviceMeksyk(); 

                cout << "\n";

		sleep(5); 
		
                break;
            }

            case '3': 
            {
                system("clear"); 

                cout << "Adapter Korea Poludniowa 220 V:\n" << endl; 

                SocketEuropa* socket = new SocketEuropa; 
                AdapterKoreaPld* adapter = new AdapterKoreaPld; 
                ElectricDeviceKoreaPld* device = new ElectricDeviceKoreaPld; 

                adapter->plugIn(socket); 
                device->plugIn(adapter); 

                device->deviceKorea(); 

                cout << "\n";

		sleep(5); 

                break;
            }
 
            case '4': 
            {
                system("clear"); 

                cout << "Adapter Taiwan 110 V:\n" << endl; 

                SocketEuropa* socket = new SocketEuropa; 
                AdapterTaiwan* adapter = new AdapterTaiwan; 
                ElectricDeviceTaiwan* device = new ElectricDeviceTaiwan;

                adapter->plugIn(socket); 
                device->plugIn(adapter);

                device->deviceTaiwan();

                cout << "\n";

		sleep(5); 
		
                break;
            }

            case '5': 
            {
                return EXIT_SUCCESS; 
            }
        }
    }

    system("clear"); 
}

