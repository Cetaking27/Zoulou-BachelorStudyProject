---
# Front matter
title: "Отчёт по лабораторной работе №8"
subtitle: "Задача на собственные значения"
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

Сформировать навык решения задач на собственные значения и собственные векторы для линейного преобразования и научится как применить их решение через Octave GUI.

# Теоретические сведения

Рассматриваются проблемы нахождения собственных значений и собственных векторов квадратной вещественной матрицы A. Собственным числом называется число λ такое, что для некоторого ненулевого вектора (собственного вектора) x имеет место равенство:
                            Ax=λx

С учетом того, что ищется нетривиальное решение уравнения, то

                            det(A−λI)=0

Тем самым собственные значения λ матрицы A являются корнями характеристического многочлена n-ой степени . Задача отыскания собственных значений и собственных векторов матрицы сводится к построению характеристического многочлена, отысканию его корней и последующему нахождению нетривиальных решений уравнения для найденных собственных значений.                           
Квадратная вещественная матрица порядка n имеет n собственных значений, при этом каждое собственное значение считается столько раз, какова его кратность как корня характеристического многочлена. Для симметричной матрицы A собственные значения вещественны, а собственные вектора, соответствующие различным собственным значениям, ортогональны, т.е. (xi,xj)= 0, если i≠j. Отметим также некоторые свойства собственных значений и собственных векторов для сопряженной матрицы AT:

                            A*y = μ*y

## Практические нахождение собственные значения и собственные векторы в OCTAVE 

Пусь данно матрица :

![рис 1](image/0.jpg){ #fig:001 width=70% height=70%}

Для того чтобы находить собственные значения и собственные векторы используется команда eig с двумя выходными аргументами. Синтаксис [V lambda] = eig(A) как указанно на рис.

![рис 2](image/1.jpg){ #fig:002 width=70% height=70%}

Для того, чтоьы получить матрицу с действительными собственными значениями, мы используем симетричную матрицу путём умножения матрицы и транспонированную матрицу. как на рис 

![рис 3](image/2.jpg){ #fig:003 width=70% height=70%}

## Практические  Марковские цепи в OCTAVE :

Цепь Мaркова — последовательность случайных событий с конечным или счётным числом исходов, где вероятность наступления каждого события зависит только от состояния, достигнутого в предыдущем событии. Характеризуется тем свойством, что, говоря нестрого, при фиксированном настоящем будущее независимо от прошлого. 
цепь Маркова – это вероятностный автомат. Распределение вероятностей переходов обычно представляется в виде матрицы. Если цепь Маркова имеет N возможных состояний, то матрица будет иметь вид N x N, в которой запись (I, J) будет являться вероятностью перехода из состояния I в состояние J. Кроме того, такая матрица должна быть стохастической, то есть строки или столбцы в сумме должны давать единицу. В такой матрице каждая строка будет иметь собственное распределение вероятностей.

# случайние блужадание

Случайное блуждание — математический объект, известный как стохастический или случайный процесс, который описывает путь, состоящий из последовательности случайных шагов в каком-нибудь математическом пространстве (например, на множестве целых чисел).
рассмотрим исследование OCTAVE  на  рис 

![рис 4](image/001.jpg){ #fig:03 width=70% height=70%}


![рис 5](image/3.jpg){ #fig:003 width=70% height=70%}

# Заключения 

я научился как реализовать матричные преобразования и найти собственные значения и собственные векторы,и так же написать программу которые может считать Марковские цепи в OCTAVE GNU.



1. [OCtave GNU](https://octave.org/bugs.html)
2.[Цепь Маркова](https://ru.wikipedia.org/wiki/%D0%A6%D0%B5%D0%BF%D1%8C_%D0%9C%D0%B0%D1%80%D0%BA%D0%BE%D0%B2%D0%B0)
3.[случайние блужадание](https://ru.wikipedia.org/wiki/%D0%A1%D0%BB%D1%83%D1%87%D0%B0%D0%B9%D0%BD%D0%BE%D0%B5_%D0%B1%D0%BB%D1%83%D0%B6%D0%B4%D0%B0%D0%BD%D0%B8%D0%B5)
4. [Задача на собственные значения](https://esystem.rudn.ru/pluginfile.php/1712601/mod_resource/content/2/README.pdf)

