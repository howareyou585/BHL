#pragma once
#include <iostream>
using namespace std;
namespace UsageTypeID {
	class Base {
	public:
		virtual ~Base() {}
	};
	class DerivedA : public Base {
	public:
		void identify() {
			std::cout << "I am DerivedA" << std::endl;
		}
	};
	class DerivedB : public Base {
	public:
		void identify() {
			std::cout << "I am DerivedB" << std::endl;
		}
	};
	void identifyType(Base* obj) {
		/*if (typeid(*obj) == typeid(DerivedA)) {
			static_cast<DerivedA*>(obj)->identify();
		} else if (typeid(*obj) == typeid(DerivedB)) {
			static_cast<DerivedB*>(obj)->identify();
		} else {
			std::cout << "Unknown type" << std::endl;
		}*/
		std::cout << "Class name: " << typeid(*obj).name() << std::endl;
	}
}