# Durak

## Descrierea jocului

Durak este un joc de cărți rusesc clasic jucat cu un pachet de 36 de cărți. Scopul jocului este de a scăpa de toate cărțile din mână. Jucătorul care rămâne cu cărți la finalul jocului este „Durak" (prostul).

## Reguli

- Fiecare jucător primește 6 cărți la începutul jocului.
- O carte este întoarsă pentru a determina atu-ul (trump).
- Jucătorii atacă și apără folosind cărțile din mână.
- O carte poate fi bătută doar de o carte mai mare de aceeași culoare sau de un atu.
- Atuu bate orice carte non-atu.
- După fiecare rundă, jucătorii completează mâna până la 6 cărți din pachet.
- Când pachetul se termină, jucătorul care rămâne cu cărți este „Durak".

## Interfață colorată

Jocul folosește culori pentru a diferenția cărțile:

- **Galben** - cărțile atu (trump)
- **Roșu** - inimi (♥) și caro (♦)
- **Cyan** - pică (♠) și treflă (♣)

## Structuri de date

- **Card**: reprezintă o carte (culoare și valoare). Include metode pentru comparare și afișare.
- **Deck**: reprezintă pachetul de cărți. Gestionează amestecarea, distribuirea și atu-ul.
- **Player**: reprezintă un jucător (mână, nume). Poate adăuga, elimina și afișa cărți.
- **GameEngine**: implementează logica jocului (atac, apărare, distribuire cărți). Controlează fluxul principal al jocului.

## Compilare și rulare

Folosește `make` pentru a compila jocul:
```
make
```

Rulează jocul:
```
./CardGameDurak
```

Curăță fișierele compilate:
```
make clean
```

## Structura fișierelor

Proiectul conține:
- **src/** - fișierele sursă (.cpp)
- **include/** - fișierele header (.hpp)
- **Makefile** - configurația de compilare

## Note

Jocul necesită Windows pentru afișarea culorilor în consolă (folosește `windows.h`).