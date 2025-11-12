#pragma once
#include <iostream>
#include <vector>
#include <cmath>
#include <cfloat> // Для DBL_MAX

// В нашей программе Y это V

//Я решил разделить чуть чуть мб плохо но говнокодим ибо время поджимает

struct StepData {
    int i;
    double xi;
    double vi;
    double v2i;
    double vi_v2i;
    double error;
    double hi;
    int c1;
    int c2;
};

// Args:
// x - значение независимой переменной (double)
// y(u) - значение зависимой переменной (double)
// Returns:
// Значение функции f(x, y) (double)
inline double f(const double& x, const double& u) {
    return (1/(2*x+pow(x,2)))*pow(u,2) + u - pow(u, 3) * std::sin(10 * x);
}
// Метод Рунге-Кутта четвертого порядка
// Args:
// x - значение независимой переменной (double)
// y - значение зависимой переменной (double)
// h - размер шага (double)
// Returns:
// Значение y на следующем шаге (double)
double RK_4_Step(const double& x, const double& y, const double& h)
{
    double k1 = h * f(x, y);
    double k2 = h * f(x + h / 2, y + k1 / 2);
    double k3 = h * f(x + h / 2, y + k2 / 2);
    double k4 = h * f(x + h, y + k3);
    double y_next = y + (k1 + 2 * k2 + 2 * k3 + k4) / 6;
    if (std::isinf(y_next) || std::isnan(y_next) || std::fabs(y_next) > DBL_MAX)
    {
        throw std::overflow_error("Value is NaN. | Value is infinite. | Value exceeds the maximum representable double.");
    }
    return y_next;
}

// универсальная функция RK4 в которой мы считаем численно шение либо с контролем ЛП либо без
std::vector<StepData> RK4_table1(double x0, double u0, double xmax, double h0, double eps, int smax, double delta) {
    std::vector<StepData> table;
    double x = x0;
    double u = u0;
    double h = h0;
    int step = 0;

    int count_C1 = 0, count_C2 = 0;

    // Начальная строка (x0)
    {
        StepData row;
        row.i = step;
        row.xi = RoundTo(x, 8);        // x_j
        row.vi = RoundTo(u, 8);        // v_j
        row.v2i = RoundTo(u, 8);       // v2_j
        row.vi_v2i = 0.0;
        row.error = 0.0;
        row.hi = RoundTo(h, 8);        // h
        row.c1 = 0;
        row.c2 = 0;

        table.push_back(row);
    }

    ++step;

    while (x < xmax && step <= smax) {
        bool step_accepted = false;
        StepData row;
        row.i = step;
        while (!step_accepted && step <= smax) {

            row.c1 = 0;
            row.c2 = 0;

            // Проверяем, не выйдем ли за xmax
            if (x + h > xmax - delta) {
                h = xmax - x;  // последний шаг точно на xmax
            }


            // Один шаг h
            double vi = RK_4_Step(x, u, h);

            // Два полшага h/2
            double u_half = RK_4_Step(x, u, h / 2.0);
            double v2i = RK_4_Step(x + h / 2.0, u_half, h / 2.0);

            // Разность решений и оценка погрешности
            double diff = std::fabs(vi - v2i);
            double error_est = (std::abs(vi - v2i)) / (pow(2., 4) - 1.);

            row.vi = RoundTo(vi, 8);
            row.v2i = RoundTo(v2i, 8);
            row.vi_v2i = RoundTo(diff, 8);
            row.error = RoundTo(error_est, 8);

            // Адаптивный контроль шага
            if (eps > 0) {
                if (error_est > eps) {
                    h /= 2.0;
                    row.c1 = 1;
                    ++count_C1;
                }

                step_accepted = true;

                if (error_est < eps / 32.0) {
                    h *= 2.0;
                    row.c2 = 1;
                    ++count_C2;
                }
            }
            else {
                step_accepted = true;
            }
        }

        if (!step_accepted) break;

        // ВАЖНО: x_i = x + h (конечная точка шага)
        double x_new = x + h;
        row.xi = RoundTo(x_new, 8);  // x_j (конечная точка)

  

        // Обновляем состояние
        u = row.v2i;  // берем более точное решение
        x = x_new;
        row.hi = RoundTo(h, 8);
        table.push_back(row);
        ++step;

        // если достигли xmax с точностью delta — выходим
        if (std::fabs(xmax - x) < delta) break;
    }

    return table;
}
