   
	--- class Transport ---

virtual Transport* Clone() const abstract;: Цей віртуальний метод повертає вказівник на новий об'єкт, який є копією поточного об'єкта.
virtual void PrintTo(std::ostream& os = std::cout) const abstract;: Цей віртуальний метод виводить інформацію про транспорт до заданого потоку. За замовчуванням вивід відбувається на консоль.
virtual void ReadFrom(std::istream& is = std::cin) abstract;: Цей віртуальний метод зчитує інформацію про транспорт з заданого потоку. За замовчуванням зчитування відбувається з консолі.
virtual double CostOfUse() const abstract;: Цей віртуальний метод обчислює вартість використання транспорту. Для автомобілів він повертає вартість пального на 100 км, а для літаків - вартість одного квитка.

std::istream& operator>>(std::istream& is, Transport& T);: Перевантажений оператор >> для зчитування інформації про транспорт з потоку.
std::ostream& operator<<(std::ostream& os, const Transport& T);: Перевантажений оператор << для виведення інформації про транспорт у потік.

   	--- class Auto ---

std::string autoBrand: Зберігає марку автомобіля.
double autoLitersPer100Km: Зберігає кількість літрів пального, яку автомобіль споживає на 100 км.

Auto(): Конструктор за замовчуванням.
Auto(std::string& brand, double litersPer100Km): Конструктор, який приймає марку автомобіля та кількість літрів пального на 100 км.
Auto(const Auto& A): Конструктор копіювання.
Auto& operator=(const Auto& A): Перевантажений оператор присвоєння.

virtual Transport* Clone() const override: Віртуальний метод для клонування об'єкта.
virtual void PrintTo(std::ostream& os = std::cout) const override: Віртуальний метод для виведення інформації про автомобіль.
virtual void ReadFrom(std::istream& is = std::cin) override: Віртуальний метод для зчитування інформації про автомобіль.
virtual double CostOfUse() const override: Віртуальний метод для обчислення вартості використання автомобіля (в цьому випадку - вартість пального на 100 км, як і зазначалося в умові).
double AutoActualCostOfUse(double distance) const: Метод для обчислення фактичної вартості використання автомобіля для певної відстані. (під фактичною вартістю подорожі розуміється 
вартість бензину за вказану відстань)
std::string GetBrand() const: Метод для отримання марки автомобіля.

namespace AutoSpace: Простір імен, який містить константу FUEL_PRICE, яка представляє ціну пального.

	--- class Plane ---

std::string planeAirCompany: Зберігає назву авіакомпанії.
double planePricePerTicket: Зберігає ціну квитка на літак.

Plane(): Конструктор за замовчуванням.
Plane(std::string& airCompany, double pricePerTicket): Конструктор, який приймає назву авіакомпанії та ціну квитка на літак.
Plane(const Plane& P): Конструктор копіювання.
Plane& operator=(const Plane& P): Перевантажений оператор присвоєння.

virtual Transport* Clone() const override: Віртуальний метод для клонування об'єкта.
virtual void PrintTo(std::ostream& os = std::cout) const override: Віртуальний метод для виведення інформації про літак.
virtual void ReadFrom(std::istream& is = std::cin) override: Віртуальний метод для зчитування інформації про літак.
virtual double CostOfUse() const override: Віртуальний метод для обчислення вартості використання літака (в цьому випадку - ціна квитка на літак).
double PlaneActualCostOfUse(int tickets) const: Метод для обчислення фактичної вартості використання літака для певної кількості квитків. (під фактичною вартістю подорожі розуміється 
вартість квитків на вказану кількість людей)

	--- class Trip ---

Transport* tripTransport: Вказівник на об'єкт класу Transport, який використовується для подорожі.
std::string tripDestination: Рядок, що містить місце призначення подорожі.

Trip(): Конструктор за замовчуванням.
Trip(const Trip& T): Конструктор копіювання.
Trip& operator=(const Trip& T): Перевантажений оператор присвоєння.
Trip(Transport* transport, std::string destination): Конструктор, що приймає вказівник на транспорт та місце призначення.

virtual double CalculateTripCost() const abstract: Віртуальний метод для обчислення вартості подорожі.
const Transport* GetTransport() const: Метод для отримання вказівника на транспорт, який використовується для подорожі.
virtual void PrintTo(std::ostream& os = std::cout) const abstract: Віртуальний метод для виведення інформації про подорож у вказаний потік. 
virtual void ReadFrom(std::istream& is = std::cin) abstract: Віртуальний метод для зчитування інформації про подорож з вказаного потоку. 
virtual Trip* Clone() const abstract: Віртуальний метод для клонування об'єкта. 

delete tripTransport: Використовується для звільнення пам'яті, що використовується під час знищення об'єктів.

std::istream& operator>>(std::istream& is, Trip& T): Перевантажений оператор >> для зчитування інформації про подорож з потоку.
std::ostream& operator<<(std::ostream& os, const Trip& T): Перевантажений оператор << для виведення інформації про подорож у потік.

	--- class AutoTrip ---

double distance: Зберігає відстань подорожі.

AutoTrip(): Конструктор за замовчуванням.
AutoTrip(const AutoTrip& A): Конструктор копіювання.
AutoTrip(std::string brand, double litersPer100Km, std::string destination, double d): Конструктор, який приймає марку автомобіля, кількість літрів пального на 100 км, місце призначення та відстань.
AutoTrip(Transport* T, std::string destination, double d): Конструктор, який приймає вказівник на транспорт, місце призначення та відстань.

virtual double CalculateTripCost() const override: Віртуальний метод для обчислення вартості подорожі. Обчислює вартість подорожі автомобілем на основі відстані та вартості пального на кожну одиницю відстані.
virtual void PrintTo(std::ostream& os = std::cout) const override: Віртуальний метод для виведення інформації про подорож автомобілем.
virtual void ReadFrom(std::istream& is = std::cin) override: Віртуальний метод для зчитування інформації про подорож з вказаного потоку.
virtual Trip* Clone() const override: Віртуальний метод для клонування об'єкта.

	--- class PlaneTrip ---

unsigned familyMembers: Кількість членів сім'ї, що беруть участь у подорожі.

PlaneTrip(): Конструктор за замовчуванням.
PlaneTrip(const PlaneTrip& P): Конструктор копіювання.
PlaneTrip(std::string airCompany, double ticketPrice, std::string destination, double family): Конструктор, який приймає назву авіакомпанії, ціну квитка, місце призначення та кількість членів сім'ї.
PlaneTrip(Transport* T, std::string destination, double family): Конструктор, який приймає вказівник на транспорт, місце призначення та кількість членів сім'ї.
virtual double CalculateTripCost() const override: Віртуальний метод для обчислення вартості подорожі. Обчислює вартість подорожі літаком на основі ціни квитка та кількості членів сім'ї.
virtual void PrintTo(std::ostream& os = std::cout) const override: Віртуальний метод для виведення інформації про подорож літаком.
virtual void ReadFrom(std::istream& is = std::cin) override: Віртуальний метод для зчитування інформації про подорож з вказаного потоку.
virtual Trip* Clone() const override: Віртуальний метод для клонування об'єкта.
unsigned GetFamilyMembers() const: Метод для отримання кількості членів сім'ї, що беруть участь у подорожі.

	--- class TripContainer ---

Trip** container: Вказівник на масив вказівників на об'єкти типу Trip.
unsigned size: Розмір контейнера.

TripContainer(unsigned size = 10): Конструктор, який створює контейнер заданого розміру. За замовчуванням, розмір контейнера встановлюється на 10.
~TripContainer(): Деструктор, який звільняє пам'ять, виділену для масиву container.

void AllocateMemory(): Виділяє пам'ять для масиву container у два рази більшого розміру.
void ReadFromFile(std::istream& is): Зчитує дані про подорожі з файлу та додає їх до контейнера.
void PrintAll(std::ostream& os = std::cout): Виводить інформацію про всі подорожі, збережені у контейнері.
double PriceOfAllTrips() const: Обчислює загальну вартість всіх подорожей, збережених у контейнері.
const Trip& FindMax(bool(*func)(const Trip&)) const: Знаходить подорож з максимальною вартістю згідно з функцією, переданою в якості аргументу.
TripContainer* Filter(bool(*func)(const Trip&)) const: Фільтрує подорожі у контейнері за допомогою функції, переданої в якості аргументу.
unsigned GetSize() const: Повертає розмір контейнера.
bool IsValid(unsigned index) const: Перевіряє, чи є даний індекс дійсним 

	--- інші функції ---

Функція FamilyMembersInTheCheapestTrip приймає посилання на об'єкт TripContainer та повертає кількість членів сім'ї у найдешевшій подорожі літаком.
Функція AutoWithHighestCostOfUse приймає константний посилання на об'єкт TripContainer та повертає вказівник на транспортний засіб (типу Transport), який має найвищу вартість використання (вартість користування - метод що повертає фактичну ціну, враховуючи параметри, а не ціну за замовчуванням).

IsAutoTrip(const Trip& T): Перевіряє, чи є об'єкт T типу AutoTrip. Повертає true, якщо так, і false у протилежному випадку.
IsPlaneTrip(const Trip& T): Перевіряє, чи є об'єкт T типу PlaneTrip. Повертає true, якщо так, і false у протилежному випадку.
