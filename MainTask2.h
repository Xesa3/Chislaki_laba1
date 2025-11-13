#pragma once
//ќсновна€ задача 2
#include <fstream> 
#include <cmath> 
#include <filesystem> 
#include <string> 
#include <limits> 
#include <cfloat> // ƒл€ DBL_MAX 
#include <Windows.h> 
const double X0 = 0.0;
const double Y10 = 0.0;
const double Y20 = 1.0;
const double H0 = 0.1;
const double XMAX = 10.435634972918;
const double A = 1.0;
const double B = 1.0;
const int MAX_STEPS = 1000;
const double TOLERANCE = 1e-7;
const double EDGE = 1e-7;


struct StepData2 {
    int i;
    double xi;
    double v1i;
    double v1_2i;
    double v2i;
    double v2_2i;
    double v1i_v1_2i;
    double v2i_v2_2i;
    double error; //обща€ ошибка
    double s1;  /*частна€ ошибка по первой функции*/
    double s2;
    double hi;
    int c1;
    int c2;
};
// ќпределение функций правой части системы 
// Args: 
//    
//x - текущее значение x(double)
//    
//    
//    
//    
//y1 - текущее значение y1(double)
//y2 - текущее значение y2(double)
//a - параметр системы уравнений(double)
//b - параметр системы уравнений(double)
// Returns: 
//    
//«начение функции f1(double)

double f1(double x, double y1, double y2, double a, double b) {
    return y2;
}
// Args: 
//    
//x - текущее значение x(double)
//    
//    
//    
//    
//y1 - текущее значение y1(double)
//y2 - текущее значение y2(double)
//a - параметр системы уравнений(double)
//b - параметр системы уравнений(double)
// Returns: 
//    
//«начение функции f2(double)

double f2(double x, double y1, double y2, double a, double b) {
    return -a *std::sqrt(std::pow(y2, 2) + 1);
}
// ћетод –унге- утты 4-го пор€дка (один шаг) 
// Args: 
//    
//x - текущее значение x(double, передаетс€ по ссылке)
//    
//    
//    
//    
//    
//y1 - текущее значение y1(double, передаетс€ по ссылке)
//y2 - текущее значение y2(double, передаетс€ по ссылке)
//h - размер шага(double)
//a - параметр системы уравнений(double)
//b - параметр системы уравнений(double)
// Returns: 
//     
//void(результат записываетс€ в x, y1, y2)

void rungeKuttaStep(double& x, double& y1, double& y2, double h, double a, double b)
{
    double ky11 = f1(x, y1, y2, a, b);
    double ky21 = f2(x, y1, y2, a, b);
    double ky12 = f1(x + h / 2, y1 + h / 2 * ky11, y2 + h / 2 * ky21, a, b);
    double ky22 = f2(x + h / 2, y1 + h / 2 * ky11, y2 + h / 2 * ky21, a, b);
    double ky13 = f1(x + h / 2, y1 + h / 2 * ky12, y2 + h / 2 * ky22, a, b);
    double ky23 = f2(x + h / 2, y1 + h / 2 * ky12, y2 + h / 2 * ky22, a, b);
    double ky14 = f1(x + h, y1 + h * ky13, y2 + h * ky23, a, b);
    double ky24 = f2(x + h, y1 + h * ky13, y2 + h * ky23, a, b);
    y1 = y1 + h * (ky11 + 2 * ky12 + 2 * ky13 + ky14) / 6;
    y2 = y2 + h * (ky21 + 2 * ky22 + 2 * ky23 + ky24) / 6;
    if (std::isinf(y1) || std::isnan(y1) || std::fabs(y1) > DBL_MAX ||
        std::isinf(y2) || std::isnan(y2) || std::fabs(y2) > DBL_MAX) {
        throw std::overflow_error("Value is NaN. | Value is infinite. | Value exceeds the maximum representable double."); 
    }
}
// ћетод –унге- утты 4-го пор€дка без контрол€ локальной погрешности 
// Args: 
//     
//x0 - начальное значение x(double)
//     
//     
//     
//     
//     
//     
//     
//y10 - начальное значение y1(double)
//y20 - начальное значение y2(double)
//h - размер шага(double)
//xmax - конечное значение x(double)
//a - параметр системы уравнений(double)
//b - параметр системы уравнений(double)
//maxSteps - максимальное число шагов(int)
// Returns: 
//     
//0 - если вычислени€ прошли успешно.
std::vector<StepData2> RK4_2t_ordinary(double x0, double y10, double y20, double h, double xmax, double a, double b, int maxSteps, double delta) {
    std::vector<StepData2> table;
    double x = x0;
    double y1 = y10;
    double y2 = y20;
    int step = 0;

    int count_C1 = 0, count_C2 = 0;

    {
        StepData2 row;
        row.i = step;
        row.xi = RoundTo(x, 8);        
        row.v1i = RoundTo(y1, 8);  
        row.v1_2i = 0;
        row.v2i = RoundTo(y2, 8);
        row.v2_2i = 0;
        row.v1i_v1_2i = 0.0;
        row.v2i_v2_2i = 0.0;
        row.error = 0.0;
        row.s1 = 0.0;
        row.s2 = 0.0;
        row.hi = RoundTo(h, 8);        
        row.c1 = 0;
        row.c2 = 0;

        table.push_back(row);
    }
    ++step;
    while ((x + h <= xmax) && (step < maxSteps)) {
        StepData2 row;
        row.i = step;
        row.c1 = 0;
        row.c2 = 0;
        row.error = 0.0;
        row.s1 = 0.0;
        row.s2 = 0.0;
        row.v1i_v1_2i = 0.0;
        row.v2i_v2_2i = 0.0;
        row.v2_2i = 0;

        if ((long long)x + h >= xmax - delta) {
            h = xmax - x;
        }

        rungeKuttaStep(x, y1, y2, h, a, b);

        x = x + h;

        row.v1i = y1;
        row.v2i = y2;
        row.xi = x;
        row.hi = h;
        table.push_back(row);
        step++;
        if (std::fabs(xmax - x) < delta) break;

    }
    return table;
}
// Args: 
//     
//x0 - начальное значение x(double)
//     
//     
//     
//     
//     
//     
//     
//     
//     
//y10 - начальное значение y1(double)
//y20 - начальное значение y2(double)
//h0 - начальный размер шага(double)
//xmax - конечное значение x(double)
//a - параметр системы уравнений(double)
//b - параметр системы уравнений(double)
//maxSteps - максимальное число шагов(int)
//tolerance - параметр контрол€ локальной погрешности(double)
//edge - эпсилон граничное(double)
// Returns: 
//     
//0 - если вычислени€ прошли успешно
std::vector<StepData2> RK4_2t_adaptive(double x0, double y10, double y20, double h, double xmax, double a, double b, int maxSteps, double eps, double delta) {
    double x = x0;
    double y1 = y10;
    double y2 = y20;
    double xtmp, y1tmp, y2tmp;  // ƒл€ временного хранени€ значений 
    double x_half, y1_half, y2_half;


    int c1 = 0;
    int c2 = 0;
    int countC1 = 0, countC2 = 0;

    int step = 0;
    double error = 0.0;
    double s1, s2;
    int p = 4;

    std::vector<StepData2> table;

    int count_C1 = 0, count_C2 = 0;

    {
        StepData2 row;
        row.i = step;
        row.xi = RoundTo(x, 8);
        row.v1i = RoundTo(y1, 8);
        row.v1_2i = RoundTo(y1, 8);
        row.v2i = RoundTo(y2, 8);
        row.v2_2i = RoundTo(y2, 8);
        row.v1i_v1_2i = 0.0;
        row.v2i_v2_2i = 0.0;
        row.error = 0.0;
        row.s1 = 0.0;
        row.s2 = 0.0;
        row.hi = RoundTo(h, 8);
        row.c1 = 0;
        row.c2 = 0;

        table.push_back(row);
    }
    ++step;
    while ((x + h <= xmax) && (step < maxSteps)) {
        StepData2 row;
        bool step_accepted = false;
        row.i = step;
        row.c1 = 0; //double
        row.c2 = 0; //half
        int flag = 0;
        while (!step_accepted && step <= maxSteps) {
            xtmp = x;
            y1tmp = y1;
            y2tmp = y2;
            rungeKuttaStep(x, y1, y2, h, a, b);
            

            rungeKuttaStep(xtmp, y1tmp, y2tmp, h/2.0, a, b);
            xtmp += h / 2.0;
            rungeKuttaStep(xtmp, y1tmp, y2tmp, h/2.0, a, b);

            s1 = std::abs(y1 - y1tmp) / (pow(2, p) - 1);
            s2 = std::abs(y2 - y2tmp) / (pow(2, p) - 1);

            error = sqrt(s1 * s1 + s2 * s2);

            row.v1i = y1;
            row.v2i = y2;
            row.v1_2i = y1tmp;
            row.v2_2i = y2tmp;
            row.v1i_v1_2i = y1 - y1tmp;
            row.v2i_v2_2i = y2 - y2tmp;
            row.error = error;

            if (error > eps) {
                h /= 2.0;
                row.c2 = 1;
                countC2++;
            }
            else if (error <= eps) {
                step_accepted = true;
                x = x + h;
                if ((error < eps / 32.0) && (flag == 0)) {
                    h *= 2.0;
                    row.c1 = 1;
                    ++count_C1;
                }
            }
            
        }
        if (!step_accepted) break;
        step++;
        row.hi = h;
        row.xi = x;
        table.push_back(row);
        if (x + h >= xmax - delta) {
            h = xmax - x;
            count_C2++;
            row.c2 = 1;
            flag = 1;
        }
        if (std::fabs(xmax - x) < delta) break;

    }
    return table;
}