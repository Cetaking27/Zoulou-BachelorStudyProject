---
# Front matter
title: "Отчёт по лабораторной работе 4"
author: "Аба Альфонс НПМ-02-18"

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
lot: true # List of tables
fontsize: 12pt
linestretch: 1.5
papersize: a4
documentclass: scrreprt
## I18n
polyglossia-lang:
name: russian
options:
- spelling = modern
- babelshorthands = true
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
  - \binoppenalty=600 # the penalty for breaking a line at a binary operator
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

Освоить на практике применение режима однократного гаммирования на примере кодирования различных исходных текстов одним ключом

## Порядок выполнения работы 

мы набрали Два текста и кодировались с одним ключом (однократное гаммирование).
Для этого нам потребовало писать программу, которую сможет прочитать оба текста не зная ключа и не стремясь его 
определить. 
Мы разработали приложение, позволяющее шифровать и дешифровать тексты P1 и P2 в режиме однократного гаммирования. 
Созданное нам Приложение имеет определить вид шифротекстов C1 и C2 обоих текстов P1 и
P2 при известном ключе; 
мы так же определили и выразили аналитически способ, при котором злоумышленник может прочитать оба текста, не
зная ключа и не стремясь его определить

  ![Рисунок ](Images/lab8-1.png){ #fig:012 width=60% }

  ![Рисунок ](Images/lab8-2.png){ #fig:0013 width=60% }

  ![Рисунок ](Images/lab8-3.png){ #fig:013 width=60% }

## Заключение:

В ходе выполнения лабораторной работы я изучил теорию и освоил на практике применение режима однократного гаммирования и 
его примере кодирования различных исходных текстов одним ключом.

## Ответы на контрольные вопросы:

1. Как, зная один из текстов (P1 или P2), определить другой, не зная при
этом ключа?

Предположим, что одна из телеграмм является шаблоном — т.е. имеет текст фиксированный формат, в который вписываются значения полей.
Допустим, что злоумышленнику этот формат известен. Тогда он получает
достаточно много пар C1 ⊕ C2 (известен вид обеих шифровок). Тогда зная
P1 и учитывая имеем:
C1 ⊕ C2 ⊕ P1 = P1 ⊕ P2 ⊕ P1 = P2.
Таким образом, злоумышленник получает возможность определить те
символы сообщения P2, которые находятся на позициях известного шаблона сообщения P1.

2. Что будет при повторном использовании ключа при шифровании текста?

при шифровании текста набладаем нестойкость шифра при повторном использовании ключа.

3. Как реализуется режим шифрования однократного гаммирования одним
ключом двух открытых текстов?

С помощью формул режима однократного гаммирования получаются шифротексты обеих 
телеграмм: Y1 = P1 + k, Y2 = P2 + K 
после этого нужно сложить по модулю оба равенства. Учитывая такие свойства операции xor, как чтобы получить 
Y1 ⊕ Y2 = P1 ⊕ K ⊕ P2 ⊕ K = P1 ⊕ P2 
Предположим, что одна из телеграмм является "рыбой", т.е. имеет фиксированный формат, в который вписываются значения полей, и злоумышленнику доподлинно известен этот формат. тогда получим достаточно много пар Y1 ⊕ Y2, преположим, P1.
Тогда с учётом Y1 ⊕ Y2 ⊕ P1 =  P1 ⊕ P2 ⊕ P1 = P2
Таким образом, злоумышленник получает возможность определить те символы сообщения 
 , которые находятся на позициях известной "рыбы" сообщения .

4. Перечислите недостатки шифрования одним ключом двух открытых
текстов

5. Перечислите преимущества шифрования одним ключом двух открытых
текстов
Преимущество алгоритмов симметричной криптографии в том, что они быстрые, очень быстрые, кроме того, в последние годы аппаратное ускорение шифрования было включено в компьютерные процессоры, серверы, маршрутизаторы и другие устройства, таким образом, мы можем передавать данные через VPN действительно быстро.
Скорость также зависит от используемого алгоритма симметричного шифрования, например, AES и ChaCha20 - два из самых быстрых и безопасных, которые у нас есть сегодня, но аппаратное обеспечение оборудования сильно влияет.

# Список литературы
1. https://github.com/lierdakil/pandoc-crossref/releases
2. https://yandex.ru/search/?clid=2285101&text=centos+%C3%B9nj+xnj&lr=213 
3. https://github.com/yamadharma/academic-laboratory-report-template 
4. https://www.virtualbox.org/