---
# Front matter
title: "Моделирование беспроводных сетей"
subtitle: "Лабораторная работа №1"
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

# Цель работы :

1. Ознакомление со средой имитационного моделирования на языке программирования 
Python (или любой другой язык по желанию студента). 

2. Изучение основные типы данных, команды ввода и вывода данных, статистические 
методы работы с данными.

## Задание 1:

Построим матрицу c количеством строк 10 и столбцов 2, переменные 
заполняются случайными числами с равномерным распределением и полученные сгенерированные случайные числа представим на графике в 
виде точек. 

```
import numpy as np
import matplotlib.pyplot as plt 

matrix_a = np.random.uniform(size=(10,2))
matrix_a

plt.figure(figsize=(5,5))
plt.plot(matrix_a[:,0], matrix_a[:,1],"y^")
plt.show()

```

![Рисунок 1](Images/1.png){ #fig:001 width=70% }

## Задание 2: 

Сгенерируем 1000 случайных чисел с любым известным распределением 
и построем их гистограмму, математическое ожидание, дисперсию.

```
mat_a = np.random.exponential(size= 1000)
x = np.mean(mat_a)
z = np.var(mat_a)
print(mat_a)
print(x)
print(z)

plt.figure(figsize=(5,5))
plt.hist(mat_a, density=True, histtype='stepfilled')
plt.hist(x, density=True, histtype='stepfilled' )
plt.hist(z, density=True, histtype='stepfilled')
plt.show()

```
![Рисунок 2](Images/2.png){ #fig:002 width=70% }

![Рисунок 3](Images/3.png){ #fig:003 width=70% }


## Задание 3 :

Сгенерируем случайную точку, равномерно распределенную в квадрате 
со стороной а. 

```
a = (1,2)
number = np.random.uniform(a)
print(number)

plt.hist(a, bins=(10))
plt.xlim(number)
plt.show()

```

![Рисунок 4](Images/4.png){ #fig:004 width=70% }

# Выводы :

Изучал инструментальные среды имитационного моделирования для 
исследования характеристик беспроводных сетей стандарта 5G. На языке программирования питон научил работать с массивми и их распределния с помошью статистических метод работы с данными.