<<<<<<< HEAD
---
# Front matter
title: "Отчёт по лабораторной работе №1"
subtitle: "Шифр простой замены"
author: "Аба Альфонс НФИмд 02-22"

# Generic otions
lang: ru-RU
toc-title: "Содержание"

# Bibliography
bibliography: bib/cite.bib
csl: pandoc/csl/gost-r-7-0-5-2008-numeric.csl

# Pdf output format
toc: true # Table of contents
toc_depth: 2
lof: true # List of figures
fontsize: 12pt
linestretch: 1.5
papersize: a4
documentclass: scrreprt
## I18n
polyglossia-lang:
  name: russian
  options:
	- spelling=modern
	- babelshorthands=true
polyglossia-otherlangs:
  name: english
### Fonts
mainfont: PT Serif
romanfont: PT Serif
sansfont: PT Sans
monofont: PT Mono
mainfontoptions: Ligatures=TeX
romanfontoptions: Ligatures=TeX
sansfontoptions: Ligatures=TeX,Scale=MatchLowercase
monofontoptions: Scale=MatchLowercase,Scale=0.9
## Biblatex
biblatex: true
biblio-style: "gost-numeric"
biblatexoptions:
  - parentracker=true
  - backend=biber
  - hyperref=auto
  - language=auto
  - autolang=other*
  - citestyle=gost-numeric
## Misc options
indent: true
header-includes:
  - \linepenalty=10 # the penalty added to the badness of each line within a paragraph (no associated penalty node) Increasing the value makes tex try to have fewer lines in the paragraph.
  - \interlinepenalty=0 # value of the penalty (node) added after each line of a paragraph.
  - \hyphenpenalty=50 # the penalty for line breaking at an automatically inserted hyphen
  - \exhyphenpenalty=50 # the penalty for line breaking at an explicit hyphen
  - \binoppenalty=700 # the penalty for breaking a line at a binary operator
  - \relpenalty=500 # the penalty for breaking a line at a relation
  - \clubpenalty=150 # extra penalty for breaking after first line of a paragraph
  - \widowpenalty=150 # extra penalty for breaking before last line of a paragraph
  - \displaywidowpenalty=50 # extra penalty for breaking before last line before a display math
  - \brokenpenalty=100 # extra penalty for page breaking after a hyphenated line
  - \predisplaypenalty=10000 # penalty for breaking before a display
  - \postdisplaypenalty=0 # penalty for breaking after a display
  - \floatingpenalty = 20000 # penalty for splitting an insertion (can only be split footnote in standard LaTeX)
  - \raggedbottom # or \flushbottom
  - \usepackage{float} # keep figures where there are in the text
  - \floatplacement{figure}{H} # keep figures where there are in the text
---

# Цель работы

Изучение алгоритмов шифрования Цезаря и Атбаш

# Теоретические сведения

## Шифр Цезаря

Шифр Цезаря, также известный, как шифр сдвига, код Цезаря или сдвиг Цезаря — один из самых простых и наиболее широко известных методов шифрования.

Шифр Цезаря — это вид шифра подстановки, в котором каждый символ в открытом тексте заменяется символом находящимся на некотором постоянном числе позиций левее или правее него в алфавите. Например, в шифре со сдвигом 3 А была бы заменена на Г, Б станет Д, и так далее.

Шифр назван в честь римского императора Гая Юлия Цезаря, использовавшего его для секретной переписки со своими генералами.

Шаг шифрования, выполняемый шифром Цезаря, часто включается как часть более сложных схем, таких как шифр Виженера, и все ещё имеет современное приложение в системе ROT13. Как и все моноалфавитные шифры, шифр Цезаря легко взламывается и не имеет практически никакого применения на практике.

Если сопоставить каждому символу алфавита его порядковый номер (нумеруя с 0), то шифрование и дешифрование можно выразить формулами модульной арифметики:

```
y = (x + k) mod n
x = (y - k + n) mod n
```

где
*x — символ открытого текста,
*y — символ шифрованного текста
*n — мощность алфавита
*k — ключ.

С точки зрения математики шифр Цезаря является частным случаем аффинного шифра.

## Шифр Атбаш

Атбаш — простой шифр подстановки, изначально придуманный для иврита. Правило шифрования состоит в замене i-й буквы алфавита буквой с номером n − i + 1, где n — число букв в алфавите.

# Выполнение работы

## Реализация шифра Цезаря на языке Python

Блок шифрования

```
def cesar():
    lettre = 'ABCDEFGHIJKLMNOPQRSTUVXYZABCDEFGHIJKLMNOPQRSTUVXYZ'
    step = 5
    teste = input("cesar chiffrovanie :)")
    resultat = ''
    for i in teste:
        ind= lettre.find(i)
        newind = ind + step 
        if i in lettre:
            resultat += lettre[newind]
        else:
            resultat += i
        print(resultat)
```

Блок дешифровки

```
# процесс дешифровки уже должен быть ясен
# вместо добавления шага, надо, наоборот же, вычитать, 
# чтоб из зашифр сообщения получить открытый текст
# по сути код такой же, лишь маленькое отличие: вместо + -
def сesar_deshifr():
    lettre = 'ABCDEFGHIJKLMNOPQRSTUVWXYZABCDEFGHIJKLMNOPQRSTUVWXYZ'
    teste1 = 5
    teste = input(" cesar- dechiffrovanie")
    resultat = ''

    for i in teste:
        ind = lettre.find(i)
        newind = ind - teste1
        if i in lettre:
            resultat += lettre[newind]
        else:
            resultat += i
    print(resultat)
```

## Реализация шифра Атбаш на языке Python

Блок шифрования

```
def cesbash():
    # задаем алфавит из английских букв больших(пОЧЕМУ БОЛЬШИХ?  Мы просто указали такой диапазон в ASCII. Вы можете
    # алфавит увеличить
    lettre = [chr(x) for x in range(65, 91)]
    # алфавит-наоборот
    lettre_vu = [x for x in lettre]
    lettre_vu.reverse()

    teste = input("cesbash - chiffrovanie")
    resultat = ""
    # тут для перебираются буквы из исходного текста
    for i in teste:
        # перебираются индексы и значения из letters
        for j,l in enumerate(lettre):
            if i == l: # если буквы i и l равны, то
                resultat += lettre_vu[j] # ставим в результат букву из реверсированного списка с индексом j
    print(resultat)
```

Блок дешифровки

```
# функция дешифровки практически такая же
# тут просто местами мы поменяли списки чтоб наоборот дешифровать сообщения
def cesbash_dchivro():
    lettre = [chr(x) for x in range(65, 91)]
    lettre_vue = [x for x in lettre]
    lettre_vue.reverse()

    teste = input("cesbash - dechirovka")
    resultat = ""
    for i in teste:
        for j, l in enumerate(lettre_vue):
            if i == l:
                resultat += lettre[j]
    print(resultat)
```
Блок Запускаем
```

# функция мейн: тут запускаем поочередно каждую функцию
def main():
    cesar()
    сesar_deshifr()
    cesbash()
    cesbash_dchivro()


```
## Контрольный пример

![Работа алгоритмов](image/01.png){ #fig:001 width=70% height=70%}

# Выводы

Изучили алгоритмы шифрования Цезаря и Атбаш.

# Список литературы{.unnumbered}

1. [Шифр Цезаря](https://habr.com/ru/post/534058/)
2. [Шифр Атбаш](https://habr.com/ru/post/444176/)
=======
---
# Front matter
title: "Отчёт по лабораторной работе №1"
subtitle: "Шифр простой замены"
author: "Аба Альфонс НФИмд 02-22"

# Generic otions
lang: ru-RU
toc-title: "Содержание"

# Bibliography
bibliography: bib/cite.bib
csl: pandoc/csl/gost-r-7-0-5-2008-numeric.csl

# Pdf output format
toc: true # Table of contents
toc_depth: 2
lof: true # List of figures
fontsize: 12pt
linestretch: 1.5
papersize: a4
documentclass: scrreprt
## I18n
polyglossia-lang:
  name: russian
  options:
	- spelling=modern
	- babelshorthands=true
polyglossia-otherlangs:
  name: english
### Fonts
mainfont: PT Serif
romanfont: PT Serif
sansfont: PT Sans
monofont: PT Mono
mainfontoptions: Ligatures=TeX
romanfontoptions: Ligatures=TeX
sansfontoptions: Ligatures=TeX,Scale=MatchLowercase
monofontoptions: Scale=MatchLowercase,Scale=0.9
## Biblatex
biblatex: true
biblio-style: "gost-numeric"
biblatexoptions:
  - parentracker=true
  - backend=biber
  - hyperref=auto
  - language=auto
  - autolang=other*
  - citestyle=gost-numeric
## Misc options
indent: true
header-includes:
  - \linepenalty=10 # the penalty added to the badness of each line within a paragraph (no associated penalty node) Increasing the value makes tex try to have fewer lines in the paragraph.
  - \interlinepenalty=0 # value of the penalty (node) added after each line of a paragraph.
  - \hyphenpenalty=50 # the penalty for line breaking at an automatically inserted hyphen
  - \exhyphenpenalty=50 # the penalty for line breaking at an explicit hyphen
  - \binoppenalty=700 # the penalty for breaking a line at a binary operator
  - \relpenalty=500 # the penalty for breaking a line at a relation
  - \clubpenalty=150 # extra penalty for breaking after first line of a paragraph
  - \widowpenalty=150 # extra penalty for breaking before last line of a paragraph
  - \displaywidowpenalty=50 # extra penalty for breaking before last line before a display math
  - \brokenpenalty=100 # extra penalty for page breaking after a hyphenated line
  - \predisplaypenalty=10000 # penalty for breaking before a display
  - \postdisplaypenalty=0 # penalty for breaking after a display
  - \floatingpenalty = 20000 # penalty for splitting an insertion (can only be split footnote in standard LaTeX)
  - \raggedbottom # or \flushbottom
  - \usepackage{float} # keep figures where there are in the text
  - \floatplacement{figure}{H} # keep figures where there are in the text
---

# Цель работы

Изучение алгоритмов шифрования Цезаря и Атбаш

# Теоретические сведения

## Шифр Цезаря

Шифр Цезаря, также известный, как шифр сдвига, код Цезаря или сдвиг Цезаря — один из самых простых и наиболее широко известных методов шифрования.

Шифр Цезаря — это вид шифра подстановки, в котором каждый символ в открытом тексте заменяется символом находящимся на некотором постоянном числе позиций левее или правее него в алфавите. Например, в шифре со сдвигом 3 А была бы заменена на Г, Б станет Д, и так далее.

Шифр назван в честь римского императора Гая Юлия Цезаря, использовавшего его для секретной переписки со своими генералами.

Шаг шифрования, выполняемый шифром Цезаря, часто включается как часть более сложных схем, таких как шифр Виженера, и все ещё имеет современное приложение в системе ROT13. Как и все моноалфавитные шифры, шифр Цезаря легко взламывается и не имеет практически никакого применения на практике.

Если сопоставить каждому символу алфавита его порядковый номер (нумеруя с 0), то шифрование и дешифрование можно выразить формулами модульной арифметики:

```
y = (x + k) mod n
x = (y - k + n) mod n
```

где
*x — символ открытого текста,
*y — символ шифрованного текста
*n — мощность алфавита
*k — ключ.

С точки зрения математики шифр Цезаря является частным случаем аффинного шифра.

## Шифр Атбаш

Атбаш — простой шифр подстановки, изначально придуманный для иврита. Правило шифрования состоит в замене i-й буквы алфавита буквой с номером n − i + 1, где n — число букв в алфавите.

# Выполнение работы

## Реализация шифра Цезаря на языке Python

Блок шифрования

```
def cesar():
    lettre = 'ABCDEFGHIJKLMNOPQRSTUVXYZABCDEFGHIJKLMNOPQRSTUVXYZ'
    step = 5
    teste = input("cesar chiffrovanie :)")
    resultat = ''
    for i in teste:
        ind= lettre.find(i)
        newind = ind + step 
        if i in lettre:
            resultat += lettre[newind]
        else:
            resultat += i
        print(resultat)
```

Блок дешифровки

```
# процесс дешифровки уже должен быть ясен
# вместо добавления шага, надо, наоборот же, вычитать, 
# чтоб из зашифр сообщения получить открытый текст
# по сути код такой же, лишь маленькое отличие: вместо + -
def сesar_deshifr():
    lettre = 'ABCDEFGHIJKLMNOPQRSTUVWXYZABCDEFGHIJKLMNOPQRSTUVWXYZ'
    teste1 = 5
    teste = input(" cesar- dechiffrovanie")
    resultat = ''

    for i in teste:
        ind = lettre.find(i)
        newind = ind - teste1
        if i in lettre:
            resultat += lettre[newind]
        else:
            resultat += i
    print(resultat)
```

## Реализация шифра Атбаш на языке Python

Блок шифрования

```
def cesbash():
    # задаем алфавит из английских букв больших(пОЧЕМУ БОЛЬШИХ?  Мы просто указали такой диапазон в ASCII. Вы можете
    # алфавит увеличить
    lettre = [chr(x) for x in range(65, 91)]
    # алфавит-наоборот
    lettre_vu = [x for x in lettre]
    lettre_vu.reverse()

    teste = input("cesbash - chiffrovanie")
    resultat = ""
    # тут для перебираются буквы из исходного текста
    for i in teste:
        # перебираются индексы и значения из letters
        for j,l in enumerate(lettre):
            if i == l: # если буквы i и l равны, то
                resultat += lettre_vu[j] # ставим в результат букву из реверсированного списка с индексом j
    print(resultat)
```

Блок дешифровки

```
# функция дешифровки практически такая же
# тут просто местами мы поменяли списки чтоб наоборот дешифровать сообщения
def cesbash_dchivro():
    lettre = [chr(x) for x in range(65, 91)]
    lettre_vue = [x for x in lettre]
    lettre_vue.reverse()

    teste = input("cesbash - dechirovka")
    resultat = ""
    for i in teste:
        for j, l in enumerate(lettre_vue):
            if i == l:
                resultat += lettre[j]
    print(resultat)
```
Блок Запускаем
```

# функция мейн: тут запускаем поочередно каждую функцию
def main():
    cesar()
    сesar_deshifr()
    cesbash()
    cesbash_dchivro()


```
## Контрольный пример

![Работа алгоритмов](image/01.png){ #fig:001 width=70% height=70%}

# Выводы

Изучили алгоритмы шифрования Цезаря и Атбаш.

# Список литературы{.unnumbered}

1. [Шифр Цезаря](https://habr.com/ru/post/534058/)
2. [Шифр Атбаш](https://habr.com/ru/post/444176/)
>>>>>>> 2e2060d0e99b3695d80d0a14f7fe62a64ef98603
