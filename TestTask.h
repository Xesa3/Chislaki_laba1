#include <vector>
#include <cmath>
#include <cfloat>

double RoundTo(double val, int digits) {
    double factor = std::pow(10.0, digits);
    return std::round(val * factor) / factor;
}

struct StepData2 {
    int i;
    double xi;
    double vi;       // решение за 1 шаг h
    double v2i;      // решение за 2 шага h/2
    double vi_v2i;   // |vi - v2i|
    double error;    // оценка локальной погрешности
    double hi;       // текущий шаг
    int C1;          // шаг уменьшался
    int C2;          // шаг увеличивался
    double ui;       // точное решение
    double abs_err;  // |ui - vi|
};


// пример функции f(x,u) для тестовой задачи
inline double f_test(const double& x, const double& u) {
    return 3.0*u;
}

// шаг RK4
double rk4_step(const double& x, const double& u, const double& h) {
    double k1 = h * f_test(x, u);
    double k2 = h * f_test(x + h / 2.0, u + k1 / 2.0);
    double k3 = h * f_test(x + h / 2.0, u + k2 / 2.0);
    double k4 = h * f_test(x + h, u + k3);
    return u + (k1 + 2 * k2 + 2 * k3 + k4) / 6.0;
}

// универсальная функция RK4
std::vector<StepData2> RK4_table(double x0, double u0, double xmax, double h0, double eps, int smax,double delta) {
    std::vector<StepData2> table;
    double x = x0;
    double u = u0;
    double h = h0;
    int step = 0;

    int count_C1 = 0, count_C2 = 0;

    // Начальная строка (x0)
    {
        StepData2 row;
        row.i = step;
        row.xi = RoundTo(x, 8);        // x_j
        row.vi = RoundTo(u, 8);        // v_j
        row.v2i = RoundTo(u, 8);       // v2_j
        row.vi_v2i = 0.0;
        row.error = 0.0;
        row.hi = RoundTo(h, 8);        // h
        row.C1 = 0;
        row.C2 = 0;
        row.ui = RoundTo(u0 * std::exp(3.0 * x), 8);  // точное решение
        row.abs_err = 0.0;

        table.push_back(row);
    }

    ++step;

    while (x < xmax && step <= smax) {
        bool step_accepted = false;
        StepData2 row;
        row.i = step;
        while (!step_accepted && step <= smax) {
 
            row.C1 = 0;
            row.C2 = 0;

            // Проверяем, не выйдем ли за xmax
            if (x + h > xmax - delta) {
                h = xmax - x;  // последний шаг точно на xmax
            }


            // Один шаг h
            double vi = rk4_step(x, u, h);

            // Два полшага h/2
            double u_half = rk4_step(x, u, h / 2.0);
            double v2i = rk4_step(x + h / 2.0, u_half, h / 2.0);

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
                    row.C1 = 1;
                    ++count_C1;              
                }

                step_accepted = true;

                if (error_est < eps / 32.0) {
                    h *= 2.0;
                    row.C2 = 1;
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

        // Точное решение для КОНЕЧНОЙ точки
        row.ui = RoundTo(u0 * std::exp(3.0 * x_new), 8);
        row.abs_err = RoundTo(std::fabs(row.ui - row.v2i), 8);

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