#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <map>


/*class Client
{
private:
	int _age;
	int _id;
public:
	Client (int age, int id) : _age(age), _id(id){}

	Client(Client& client) //Конструктор копирования.
	{
		_age = client._age;
		_id = client._id;
	}

	void ShowData()
	{
		std::cout << "Age: " << _age << "\n";
		std::cout << "Id: " << _id << "\n\n";
	}

};*/

class Client
{
private:
	int _id;
	std::string _name;
	float _bill;
public:
	Client(int id, std::string name, float bill, std::map<int, Client*>&map) : _id(id), _name(name), _bill(bill) 
	{
		map[_id] = this; // Это поиск по id.
	}

	Client(Client& client)
	{
		_id = client._id;
		_name = client._name;
		_bill = client._bill;
	}

	void ShowData()
	{
		std::cout << "Id: " << _id << "\n";
		std::cout << "Name: " << _name << "\n";
		std::cout << "Bill: " << _bill << "\n\n";
	}

	/*void Foo()
	{
		this-> _id;
	}*/
};

int main() {
	setlocale(LC_ALL, "Russian");

	// Первая тема.
	/*Client client(24, 1);
	Client client2(client);
	client.ShowData();
	client2.ShowData();*/
	
	// Вторая тема. STL (Библиотека map)
	/*
	// 434353535
	// 23 - John;
	// 26 - Alex;
	
	/*
	std::map<int, std::string> clients =
	{
		{23, "John"}, // Автоматически формируються, по виличене индекса.
		{26, "Alex"},
		{30 , "Bob"}
	};

	auto it = clients.begin();
	*/

	// Способ как по ручному вводить данные.
	/*std::cout << it->first << '\n';
	std::cout << it->second << '\n';
	it++;
	std::cout << it->first << '\n';
	std::cout << it->second << '\n';
	std::advance(it, 2);*/
	
	// Сразу выводит всё.
	/*for (; it != clients.end(); ++it)
	{
		std::cout << it->first << "\n";
		std::cout << it->second << "\n\n";

	}*/

	// Способ добавление.
	/*
	clients.insert(std::make_pair(10, "Monika\n")); // Первый способ. Мы можем добавлять в наш массив (clients).
	clients[55] = "Gary\n"; // Второй способ. Мы можем добавлять в наш массив (clients).
	std::cout << clients[10]; // Это выводит имя, смотря на id к которому относиться. 
	*/

	// Указатели на id.
	/*
	it = clients.find(23); // Это наша ссылка на id человека.
	clients.erase(it); // Сюда она приходит.
	*/

	// Это просто выводим по возрастанию.
	/*
	for (it = clients.begin(); it != clients.end() ; ++it)
	{
		std::cout << it->first << "\n";
		std::cout << it->second << "\n\n";
	}*/
	
	// Третья тема.

	std::map<int, Client*>clients;
	Client* client = new Client(12, "John", 95352.5f, clients);
	Client* client2 = new Client(52, "Alex", 32324.4f, clients);
	Client* client3 = new Client(74, "Bob", 123245.f, clients);
	
	auto it = clients.begin();
	
	for (; it != clients.end(); ++it)
	{
		std::cout << "Client id - " << it->first << ": \n";
			 it->second->ShowData();
			 
	}

	// client->Foo();

	return {};
}