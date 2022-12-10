---
# Front matter
title: "Отчёт по лабораторной работе №7"
subtitle: "Графики"
author: "Аба Альфонс НПМмд 02-22"

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

Научить как реализовать различные графики через Octave GUI.

# Теоретические сведения

Octave представляет интерактивный командный интерфейс для решения линейных и нелинейных математических задач, а также проведения других численных экспериментов. Кроме того, Octave можно использовать для пакетной обработки.Язык Octave оперирует также графической реялизацией при использовании особые команды так как :

    1. linspace -  создает вектор равномерно (линейно) распределенных значений Использование: linspace(start, end, length). Параметр length является опциональным и определяет число элементов в возвращаемом векторе. Если вы опустите этот параметр, то вектор будет содержать 100 значений, первое из которых будет равно start, а последнее stop.
    2. plot -  строит двумерный график Использование: plot(x, y) x и y - векторые одинаковой длины.
    3. figure - создает новую форму для графика Функция бывает полезна, когда вы хотите построить несколько графиков на разных окнах, а не заменять ваш предыдущий график или строить график на той же оси.
    4. hold on / hold off - команда, определяющая хотите ли вы строить последующие графики на тех же осях (hold on) или хотите заменить предыдущий построенный график (hold off).

В качестве примерах мы расмотрели построение следующие графики.

## 1.Параметрические Графики:
 
 Рассмотрим уравнение Циклоиды: x = r(t-sin(t)), y = r(1-cos(t)).
построение его графики требуется трёх периодитический радиуса, то есть время t принимает значение от 0 до 6*pi. 
Мы используем команды t = linspace(0,6*pi,50), после этого сдаем значения тех известные нам координаты и используем команду plot(x,y), чтобы нарисовать графики зависимая от аксис X и y. рис(1)

![рис 1](image/1.jpg){ #fig:001 width=70% height=70%}

![рис 1](image/cycloid.png){ #fig:002 width=70% height=70%}

## 2. Полярные координаты 

Так же как в предыдушим случае, построение графики полярные координаты можно используя функцию r = f(v).
Чтобы построить график, мы вычислим x и y по формуле : x = rcos(v), y = rsini(v)  и так же на этот раз r = 1-2sin(v). рис(2,3) 

![рис 2](image/2.jpg){ #fig:003 width=70% height=70%}

![рис 3](image/3.jpg){ #fig:005 width=70% height=70%}


![рис 3](image/limacon.png){ #fig:006 width=70% height=70%}

## 3. Графики неявных функций 

Неявная функция — это функция, заданная неявным уравнением как связь одной из переменных (значение) с другими переменными (аргументами). Так, неявная функция y в контексте единичной окружности определяется неявно уравнением x^2 + f(x)^2 - 1 = 0. Это неявное уравнение определяет f как функцию от x, если только -1<= x <= 1 и рассматриваются только неотрицательные (или только неположительные) значения функции.
При построении графики неявных функций, используем команды ezplot таким образом :
            ezplot(f)

построим уравнение кривой -x^2 -xy + x + y^2 - y = 1

![рис 4](image/impl1.png){ #fig:003 width=70% height=70%}

рассмотрим пример построения уравнение касательной к графику окружности :
        уравнение окружности (x - 2)^2 + y^2 = 25

на рис(4)

![рис 4](image/4.jpg){ #fig:007 width=70% height=70%}

## 4. Комплексные Числа:

Пусть  Z1 = 1 + 2i, Z2 = 2 - 3i две комплексные числа для того чтобы построить их график нужно использовать команды "compass()". рассмотим на рис(5)

![рис 5](image/5.jpg){ #fig:008 width=70% height=70%}

![рис 6](image/6.jpg){ #fig:009 width=70% height=70%}

## 5. Специальные функции:

В Octave доступно много специяльных функций, таких как функции Бесселя (bessel), функция ошибок (erf), гамма-функция (gamma).
для качество примера построим график гамма-функция:

            Г(x) = integrale(0 до inf)[ t^(x-1)*e^(-t) ]dt

рассмотрим на рис()

![рис 7](image/7.jpg){ #fig:011 width=70% height=70%}

![рис 8](image/8.jpg){ #fig:021 width=70% height=70%}

# Заключения 

я научился как реализовать код с помошью, которого можно нарисовать различные графику в OCTAVE GNU.



1. [OCtave GNU](https://octave.org/bugs.html)

2. [Задача на собственные значения](https://esystem.rudn.ru/pluginfile.php/1712599/mod_resource/content/2/README.pdf)

