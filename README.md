# ADS - Stekas (dinaminis masyvas)
---
Programa realizuoja abstraktų duomenų tipą **steką (stack)** naudojant
**dinamiškai išskirtą masyvą** C kalboje.

Stekas veikia pagal **LIFO principą (Last In First Out)** -
paskutinis įdėtas elementas išimamas pirmas.

---

## Programos funkcionalumas

- [x] Steko sukūrimas ir sunaikinimas
- [x] Elementų įdėjimas (`push`)
- [x] Elementų išėmimas (`pop`)
- [x] Patikrinimas ar stekas tuščias (`isEmpty`)
- [x] Patikrinimas ar stekas pilnas (`isFull`)
- [x] Automatinis masyvo didinimas (`realloc`)

---

## Programos naudojimas

### makefile

makefile sukuria du failus (main.exe ir stack.o).
```
$ makefile
```

### Go.cmd
Paleidžia programą (Windows aplinkoje)
```
$ ./Go.cmd
```

## Programos funkcijos

- `createStack` – sukuria steką su pradi
- `push` – įdeda elementą į steką.
- `pop` – išema elementą iš steko (iš viršaus).
- `isEmpty` – patikrina ar stekas tuščias.
- `isFull` – patikrina ar stekas pilnas.
- `destroyStack` – sunaikina steką ir atlaisvina vietą atmintyje.