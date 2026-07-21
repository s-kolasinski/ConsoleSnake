# Console Snake Game

Klasyczna gra zręcznościowa napisana w języku C++, działająca bezpośrednio w oknie terminala. Projekt skupia się na płynnej rozgrywce, optymalizacji wyświetlania w konsoli oraz trwałym zapisywaniu najlepszych wyników.

## Główne funkcjonalności

* **Płynny rendering:** Zastosowano kody ANSI oraz ukrywanie kursora, co całkowicie eliminuje problem migotania ekranu konsoli.
* **Dynamiczny poziom trudności:** Szybkość poruszania się węża zwiększa się automatycznie po każdych 5 zdobytych punktach (zjedzonych owocach).
* **Zapis najlepszego wyniku:** Gra automatycznie odczytuje i nadpisuje High Score w pliku tekstowym (best_score.txt).
* **Zarządzanie stanem gry:** Możliwość szybkiego restartu rozgrywki po ekranie Game Over bez konieczności ponownego uruchamiania całej aplikacji.
* **Wyczyszczony bufor wejścia:** Niezawodne odczytywanie klawiszy funkcyjnych (np. przy restarcie), odporne na zalegające sygnały z klawiszy sterujących.

## Wymagania wstępne

Aby skompilować i uruchomić ten projekt, potrzebujesz:
* Kompilatora C++ (np. GCC / MinGW).
* Środowiska obsługującego zewnętrzne terminale (np. Visual Studio Code).
* Narzędzia CMake (opcjonalnie, do automatycznego budowania).

## Uruchomienie i kompilacja

Zgodnie z ułożeniem plików w projekcie (pliki źródłowe `.cpp` w folderze `src`, a nagłówkowe `.h` w folderze `include`), najprostszą metodą ręcznej kompilacji jest użycie kompilatora g++. 

Otwórz terminal w głównym katalogu projektu i wykonaj poniższe polecenie:

```bash
g++ src/main.cpp src/Game.cpp src/Snake.cpp src/Fruit.cpp -I include -o build/SnakeGame.exe
```

Następnie uruchom skompilowaną grę:

```bash
./build/SnakeGame.exe
```


## Sterowanie

* **W, A, S, D** – zmiana kierunku poruszania się węża
* **R** – restart gry (dostępne na ekranie Game Over)
* **Q** – wyjście z programu

```

```
