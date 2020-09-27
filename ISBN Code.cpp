#include "pch.h"
#include <iostream>

using namespace std;

//Эта программа проверяет верный ли ISBN-13 код ввёл пользователь (если пользователь ввёл 13 цифр) 
//и генерирует проверочное число для ISBN-13 кода (если пользователь ввёл 12 цифр)

int generateCheckDigit(int numberSum, int& checkDigit) {
	while (numberSum % 10 != 0) {
		numberSum++;
		checkDigit++;
	}
	return checkDigit;
}
void checkUserNumber(int numberSum) {
	if (numberSum % 10 == 0) {
		cout << "Ваш ISNB-13 код верен."<< endl;
	}
	else {
		cout << "Ваш ISBN-13 код не верен. Проверочная цифра не верна." << endl;
	}
}

int main()
{
	setlocale(LC_ALL, "Russian");
	
	char digit = '\0';
	int numberSum = 0;
	int position = 1;
	int checkDigit = 0;
	cout << "Введите число." << endl;
	digit = cin.get();
	while (digit != 10) {
		if (digit == 45) {
			digit = cin.get();
		}
		else {
			if (position % 2 == 0) {
				numberSum += (digit - '0') * 3;
			}
			else {
				numberSum += digit - '0';
			}
			digit = cin.get();
			position++;
		}
	} if (position-1 == 12) {
		cout << "Вы ввели число без проверочной цифры."<<endl;
		cout << "Сгенерированная проверочная цифра : "<< generateCheckDigit(numberSum,checkDigit)<<endl;
	}
	else if (position-1 == 13) {
		checkUserNumber(numberSum);
	}
	else {
		cout << "ОШИБКА!" << endl << "Число цифр не совпадает с числом цифр ISBN-13 кода." << endl;
	}
	
	return 0;
}
