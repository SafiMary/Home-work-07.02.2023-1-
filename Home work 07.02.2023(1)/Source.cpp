#include <iostream>
#include <string>
#include <vector>
#include <stdio.h>
#include <windows.h>
#include <memory>

class Parent {
public:
	Parent() {}
	virtual ~Parent(){}
	void setMoney(int money) {
		_money = money;
	}
	void  setPower(const std::string& power) {
		_power = power;
	}
	int getMoney() {
		return _money;
	}
	const std::string& getPower(){
		return _power;
	}
	virtual void MoneyHoney() {
		std::cout << "MoneyHoney Parent" << std::endl;
	}
private:
	int _money{};
	std::string _power{};
};

class Child : public Parent {
	void setMoneyCH(int moneychild) {
		_moneychild = moneychild;
	}
	void  setPowerCH(const std::string& powerchild) {
		_powerchild = powerchild;
	}
	int getMoneyCH() {
		return _moneychild;
	}
	const std::string& getPowerCH() {
		return _powerchild;
	}
	void MoneyHoney()override {
		std::cout << "MoneyHoney Child" << std::endl;
	}
private:
	int _moneychild{};
	std::string _powerchild{};
};




int main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	std::shared_ptr<Parent> pParent(new Child);
	std::shared_ptr<Parent> pParent2 = std::make_shared<Child>();

	pParent2->MoneyHoney();
	std::dynamic_pointer_cast<Child>(pParent2);
	if (pParent2.get() != nullptr) {
		std::cout << "Cast ok!" << std::endl;
	}
	else {
		std::cout << "nullptr" << std::endl;
	}

	pParent2->MoneyHoney();
}