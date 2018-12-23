#include "pracownik.h"

Pracownik :: Pracownik(string im = "brak imienia", string naz = "brak nazwiska", int w = 0, string t = "brak tytulu", int st = 0):Wizytowka(im, naz, w, t), staz(st){}

Pracownik :: ~Pracownik(){}

