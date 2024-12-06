#include <iostream>
#include <cmath>

// Stałe
const double Na = 6.022e23; // Liczba Avogadra w mol^-1
const double re = 2.82e-13; // Klasyczny promień elektronu w cm
const double me_c2 = 0.511; // Masa elektronu w MeV/c^2
const double K = 2 * M_PI * Na * re * re * me_c2; // Stała w MeV cm^2 / mol

// Funkcja obliczająca straty energii przy użyciu równania Bethe-Blocha
double Bethe_Bloch(double mean, double Z, double rho, double I, double v) {
    // Parametry cząstki
    double beta = v;                            // Beta = v/c
    double gamma = 1.0 / std::sqrt(1 - beta * beta); // Czynnik Lorentza
    double Tmax = 2 * me_c2 * (gamma * beta) * (gamma * beta); // Maksymalna energia przekazana elektronowi

    // Obliczenia równania Bethe-Blocha
    double t1 = K * Z * Z * mean * (rho / (beta * beta));
    double temp = (Tmax / I) * (Tmax / I);
    double t2 = std::log(temp) - 2 * beta * beta;

    return t1 * t2; // Wynik w MeV cm^2/g
}

int main() {
    // Parametry cząstki alfa i środowiska
    double E_max = 1.0;            // Maksymalna energia kinetyczna (MeV)
    double m_He = 3727.0;          // Masa cząstki alfa (MeV/c^2)
    double rho_O = 1.43e-3;        // Gęstość tlenu (g/cm^3) z błędem 20%
    double rho_Na = 1.25e-3;       // Gęstość azotu (g/cm^3) z błędem 80%
    double rho = 1.22e-3;          // Gęstość powietrza (g/cm^3)

    double E_c = m_He + E_max;     // Całkowita energia cząstki alfa
    double p_alpha = std::sqrt(E_c * E_c - m_He * m_He); // Impuls cząstki alfa
    double v_alpha = p_alpha / std::sqrt(m_He * m_He + p_alpha * p_alpha); // Prędkość cząstki alfa (v/c)

    // Parametry jonizacji dla azotu i tlenu
    double I_Na = (7 * 12 + 7) * 1e-6; // Średni potencjał jonizacji azotu (MeV)
    double I_O = (8 * 12 + 7) * 1e-6;  // Średni potencjał jonizacji tlenu (MeV)

    // Frakcje wagowe azotu i tlenu w powietrzu
    double w_Na = 14 * 0.78 / (14 * 0.78 + 16 * 0.22);
    double w_O = 16 * 0.22 / (16 * 0.22 + 14 * 0.78);

    // Średnia masa atomowa azotu i tlenu
    double A_Na = 14.0;
    double A_O = 16.0;

    // Obliczenia Bethe-Blocha dla azotu i tlenu
    double bb_Na = Bethe_Bloch(0.5, 2, rho_Na, I_Na, v_alpha);
    double bb_O = Bethe_Bloch(0.5, 2, rho_O, I_O, v_alpha);

    // Obliczenia strat energii w mieszaninie
    double de_dx_1 = w_Na * bb_Na;
    double de_dx_2 = w_O * bb_O;
    double dE_dx = (de_dx_1 + de_dx_2) / rho;

    // Wyświetlenie wyniku
    std::cout << "dE/dx = " << dE_dx << " MeV cm^2/g" << std::endl;

    return 0;
}
