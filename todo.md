- zwiększyć bezpieczeństwo kodu poprzez ograniczenie mechanizmu przyjaźni - w trakcie porządkowanie klasy Object i Map w plikach map.cpp i map.h, dodawanie setterów i getterów
+ Napisać kontrolę czasu, żeby dokładniej kontrolować szybkość poruszania npc-ów
--Funkcja onloop będzie pobierać czas od uruchomienia programu i odmierzać go między poszczególnymi wejściami do funkcji onloop. Różnicę ma dodawać do określonego celu opóźnienia. Gdy osiągnie określoną wartość
 to funkcja zwróci true, w przeciwnym razie false
+ Napisać, żeby kamera była ruchoma i poruszała się razem z graczem
- kolizje npc z innymi obiektami oraz z graczem

- dodać funkcję do realistycznych zderzeń
-+ dodanie punktów do obiektów
-+ generowanie prostych wokół obiektów na bazie obliczonych punktów
--test obliczanie odległości npc do tych prostych na bazie wyznaczonych wzorów
-- obliczanie punktu frontowego obiektu z uwzględnieniem jego kierunku poruszania się
--


- liczenie punktów przy kontakcie gracza z npc
+ dodać brakujące tekstury
+ dodać właściwość destroyable do klasy obiekt i znaleźć miejsce, w którym będą zdefiniowane właściowści różnych obiektów, np. żeby wystarczyło podać id obiektu, żeby przypisały się
 jego właściwości. Dodawanie właściwości obiektu w zależności od id można wykonać podczas jego dodawania we funkcji add_map_object


 ***
 + W trakcie rozwiązywania problemem z liczeniem kolizji, rysowanie punktów wspólnych w entity.cpp - punkty przecięcia są obliczane prawidłowo, generują się w prawidłowych miejscach
- W trakcie zastępowania tablic vectorami bądź arrayami
 -- zastępowanie aktualnie klasy Map
 -- problem, bo nie zostało jeszcze zakończone ograniczanie przyjaźni

***
 + Zrobić, żeby pozycja obiektów była liczona w double, a nie int. Przeliczenie na int powinno zachodzić tylko w procedurze do rysowania
 + postać napotyka na ograniczenie z lewej strony - ograniczenia znikły niewiadomo czemu po ustawieniu testu kolizji i ponownym skompilowaniu
 - obliczanie kolizji z graczem i obiektami napisana pierwsze przykładowe demo do testowania działania programu, nie wprowadzono pełnego rozwiązania omega
 - dodanie pełnego rozwiązania na kolizje i testowanie programu
