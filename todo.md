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

