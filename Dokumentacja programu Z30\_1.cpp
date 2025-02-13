Opis programu
Program `Z30_1.cpp` oblicza straty energii cząstki alfa w powietrzu przy użyciu równania Bethe-Blocha. Jest on używany do analizy oddziaływań cząstek naładowanych z materią.

Główne elementy programu:
1. Stałe fizyczne – Definiowane są stałe, takie jak liczba Avogadra, klasyczny promień elektronu oraz stała Bethe-Blocha.
2. Funkcja – Implementuje równanie Bethe-Blocha do obliczania strat energii cząstek naładowanych w materii.
3. Parametry wejściowe – Program wykorzystuje wartości energii cząstki alfa oraz właściwości środowiska (gęstość powietrza, azotu, tlenu, potencjały jonizacji itp.).
4. Obliczenia – Program wylicza m.in. prędkość cząstki alfa, stratę energii dE/dx oraz średnią masę atomową powietrza.
5. Wyniki – Program zwraca wynik w postaci strat energii na jednostkę drogi wyrażonych w MeV cm²/g.

Instrukcja kompilacji i uruchomienia
Wymagania
Do skompilowania programu wymagany jest kompilator obsługujący standard C++, np. g++.
Kompilacja:
 g++ -o Z30_1 Z30_1.cpp -lm
Uruchomienie:
 ./Z30_1
Wykorzystanie programu w analizie
Program został wykorzystany do obliczenia strat energii cząstki alfa w powietrzu. Energia Emax w kodzie odpowiada energii uzyskanej w doświadczeniu (E). Wyniki zostały wykorzystane do określenia zasięgu cząstek alfa i ich strat energii w powietrzu. Wartości teoretyczne w wykresie 5 pochodzą z ASTAR, natomiast program `Z30_1.cpp` został użyty do wyznaczenia strat energii na podstawie równania Bethe-Blocha.
