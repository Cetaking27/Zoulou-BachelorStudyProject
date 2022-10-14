---
# Front matter
title: "Отчёт по лабораторной работе №3"
subtitle: "Введение в работу с Octave"
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

Введение в работу с Octave : Изучать ee функции и имееть реализовать  простейшие операции на нем. 

# Теоретические сведения
GNU Octave — свободная программная система для математических вычислений, использующая совместимый с MATLAB язык высокого уровня.
Octave представляет интерактивный командный интерфейс для решения линейных и нелинейных математических задач, а также проведения других численных экспериментов. Кроме того, Octave можно использовать для пакетной обработки. Язык Octave оперирует арифметикой вещественных и комплексных скаляров, векторов и матриц, имеет расширения для решения линейных алгебраических задач, нахождения корней систем нелинейных алгебраических уравнений, работы с полиномами, решения различных дифференциальных уравнений, интегрирования систем дифференциальных и дифференциально-алгебраических уравнений первого порядка, интегрирования функций на конечных и бесконечных интервалах. Этот список можно легко расширить, используя язык Octave (или используя динамически загружаемые модули, созданные на языках C, C++, Фортран и др.).

## Последовательность выполнения работы

Для того чтобы выпольнить работы в Octave, мне пришло его скачать и установить в моем ПК через https://octave.org/.

### Простейшие операции

Включил  журналирование сессии с помощью команд  "diary on" и начался реализовать простейшие операции так как Octave можно использовать как простейший калькулятор .

Так же соблюдая формат введение код в нем я сдавал  вектор-строку (ковектор), вектор-столбец (вектор),матрицу итд...

![Рис 1](image/1.png){ #fig:001 width=70% height=70%}

### Операции с векторами

Используя правильность введение код в Octave, я смог работать с векторами и выпольнил нескольких операц так как : Сложение векторов, Скалярное умножение векторов, Векторное умножение так же находить норму вектора:

![Рис 2](image/2.png){ #fig:002 width=70% height=70%}

### Вычисление проектора

Вычислил проекцию вектора u на вектор v . 

![Рис 3](image/3.png){ #fig:003 width=70% height=70%}

### Матричные операции

я смог работать матрицами и выпольнил нескольких операц.

![Рис 3](image/3.png){ #fig:003 width=70% height=70%}

![Рис 4](image/4.png){ #fig:004 width=70% height=70%}

### Построение простейших графиков

1. Построил график функции sin 𝑥 на интервале [0, 2π].

![Рис 5](image/5.png){ #fig:005 width=70% height=70%}

![Рис 6](image/6.png){ #fig:006 width=70% height=70%}

2. Улучшил внешний вид графика

![Рис 7](image/7.png){ #fig:007 width=70% height=70%}

3. Начертил два графика на одном чертеже.

![Рис 8](image/8.png){ #fig:008 width=70% height=70%}

4. Построил график 𝑦 = 𝑥2 sin x

![Рис 9](image/9.png){ #fig:009 width=70% height=70%}

### Сравнение циклов и операций с векторами 

Сравнил эффективность работы с циклами и операций с векторами.

![Рис 10](image/10.png){ #fig:010 width=70% height=70%}

![Рис 11](image/11.png){ #fig:011 width=70% height=70%}

Полученно мне результаты показывает что работа с векторами быстрее вычислается чем с циклами.
# Выводы

Изучили как работать в Octave, начил базисные функции как "diary on","clear","clf","tic","toc" итд... 

# Список литературы{.unnumbered}

1. [doc octave](https://esystem.rudn.ru/pluginfile.php/1712591/mod_resource/content/3/003-octave-intro.pdf)
2. [official site docummentation octave](https://octave.org/)
3. [wiki-octave](https://ru.wikipedia.org/wiki/GNU_Octave)