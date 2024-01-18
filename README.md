Kompilacja:
  cc main.c ant.c grid.c
Korzystanie z programu:
  ./a.out -n 5 -m 6 -i 100 -o plik -d n -r 50
  Obowiązkowe parametry:
  -n: liczba kolumn siatki ( > 0, tylko int)
  -m: liczba wierszy siatki ( > 0, tylko int)
  -i: liczba iteracji ruchu mrówki ( >= 0, tylko int)
  -o: przedrostek plików wynikowych, do których będą zapisane kolejne iteracje ( < 250 znaków)
  -d: kierunek, w którym będzie skierowana mrówka przy rozpoczęciu iteracji (działa tylko dla char-ów n/e/s/w)
  Opcjonalny parametr:
  -r: procent pól, które losowo będą ustawione jako czarne przy generacji siatki
