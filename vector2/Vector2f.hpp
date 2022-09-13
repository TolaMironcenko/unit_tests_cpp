#pragma once
// pragma once защищает от проблемы двойного включения заголовка в файл
// подробнее: https://stackoverflow.com/questions/1143936/

// Подключаем заголовок cmath из стандартной библиотеки, он пригодится позже
// Документация заголовка: http://en.cppreference.com/w/cpp/header/cmath
#include <cmath>

// Объявляем новый тип данных - структуру с названием Vector2f
struct Vector2f
{
    // Два поля структуры имеют тип float
    // Мы явно указываем, что поля в любом случае надо инициализировать нулём.
    // Использование неинициализированной памяти - одна из самых страшных
    //  ошибок C++ программиста, и её надо всячески избегать.
    float x = 0;
    float y = 0;

    // Конструктор без аргументов инициализирует структуру в той
    //  инструкции, где она объявлена. Нас устраивает реализация
    //  конструктора, предлагаемая компилятором по умолчанию,
    //  поэтому мы написали "= default"
    Vector2f() = default;

    // Конструктор с двумя аргументами инициализирует структуру
    //  двумя значениями. Пример:
    //    Vector2 speed(10, 20);
    Vector2f(float x, float y)
        : x(x), y(y)
    {
    }

    float length() const
    {
        return std::hypot(x, y);
    }

    Vector2f operator+(const Vector2f &other) const
    {
        return {x + other.x, y + other.y};
    }

    Vector2f &operator+=(const Vector2f &other)
    {
        x += other.x;
        y += other.y;
        return *this;
    }

    // inline float dot(const Vector2f &a, const Vector2f &b)
    // {
    //     return 0;
    // }
};

inline float dot(const Vector2f &a, const Vector2f &b)
{
    return 0;
}
// После объявления структуры следует поставить точку с запятой.
// Если этого не сделать, возникнет ошибка компиляции.
// Некоторые компиляторы плохо обрабатывают эту ошибку и выдают
//  много индуцированных ошибок вместо одной правильной.