#ifndef DATE_H
#define DATE_H

#include <string>
#include <iostream>

/**
 * Клас Date.
 * Класът Date представлява обект(дата) структуриран по модела ISO 8601.
 */

class Date {
private:
    int year; /**< Число - Година */
    int month; /**< Число - Месец */
    int day; /**< Число - Ден */

    bool valid(int, int, int); /**< Проверява дали дадена дата е коректна. */
public:
    Date(); /**< Конструктор задаващ нули като стойности на променливите. */
    Date(const Date&); /**< Инициализира датата чрез стойностите на друг обект Date. */
    Date(int, int, int); /**< Инициализира датата чрез три числа(стойности) за година, месец и ден. */
    Date(const std::string); /**< Инициализира датата чрез низ. */

    Date operator= (const Date&); /**< Задава текущата дата чрез друга. */
    bool operator== (const Date&); /**< Проверява дали две дати са еднакви. */
    bool operator!= (const Date&); /**< Проверява дали две дати са различни. */
    bool operator>= (const Date&); /**< Проверява дали текущата дата е по-напред във времето или равна с посочената. */
    bool operator<= (const Date&); /**< Проверява дали текущата дата е по-назад във времето или равна с посочената. */
    bool operator< (const Date&); /**< Проверява дали текущата дата е по-напред във времето с посочената. */
    bool operator> (const Date&); /**< Проверява дали текущата дата е по-назад във времето с посочената. */

    friend std::ostream& operator<< (std::ostream&, const Date&); /**< Позволява да се извеждат обекти от тип Data. */
};

#endif