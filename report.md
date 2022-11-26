---
# Front matter
title: "Отчёт по лабораторной работе №6"
subtitle: "Пределы, Последовательности и ряды"
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

Научиться оформлять и решать задачи над пределам и также последовательностиям и ряды  через Octave GNU.
Использование цикл и так же векторные методы  для решения Пределных числовых последовательностией.

# Теоретические сведения

## Предел функции.
Предел функции является обобщением понятия предела последовательности. Изначально под пределом функции $f(x)$ в точке $x$ понимали предел последовательности значений функции:$f(x_1),f(x_2),f(x_3),\dots,$ соответствующих последовательности элементов области определения функции $x_1, x_2, x_3,\dots.$ Если такой предел существует, то говорят, что функция сходится к указанному значению, иначе говорят, что функция расходится.

1. Определение и ппимер нахождение в Octave GUI : 

Рассмотрим функцию $ f(x)$ и точку стремления  $ x_{0},$, являющуюся предельной точкой для области определения $ f,$ но не обязанную ей принадлежать. Существуют несколько равносильных определений предела функции — среди них есть сформулированные Гейне и Коши.

2. Предел функции по Гейне:

Значение $ A $ называется пределом (предельным значением) функции $f(x)$ в точке $x_{0},$ если для любой последовательности точек $\{x\}^\infty_{n=1}$, сходящейся к $ x_{0}$, но не содержащей $ x_{0}$ в качестве одного из своих элементов то есть в проколотой окрестности $ x_{0} $, последовательность значений функции $\{f(x_{n})\}^\infty_{n=1}$ сходится к $ A $.

3. Предел функции по Коши

Значение $ A $ называется пределом (предельным значением) функции $f(x)$ в точке $ x_{0},$ если для любого положительного числа $\varepsilon $ можно подобрать соответствующее ему положительное число $ \delta =\delta (\varepsilon )$ такое, что для всех аргументов $x,$  удовлетворяющих условию $ 0<\left|x-x_{0}\right|<\delta,$  выполняется неравенство: $ 0\leqslant |f(x)-A|<\varepsilon ,$ то есть $|f(x)-A|<\varepsilon $.

$$\lim _{x\to x_{0}}f(x) = A\Leftrightarrow {\Big [}\forall \varepsilon >0~\exists \delta =\delta {\big (}\varepsilon )>0~\forall x~(0<|x-x_{0}|<\delta {\big )}\Rightarrow {\big (}|f(x)-A|<\varepsilon {\big )}{\Big ]},  $$
где:

$ \forall $ — квантор всеобщности;

$ \exists $  — квантор существования;

$ \Rightarrow $ — импликация.

4. Решение задач 

Рассмотрим предел  $$ \lim_{n\to \infty}{\Big(}1 + \frac{1}{n}{\Big)} ^{n}$$

Оценим это выражение

![рис 1](image/1.jpg) 
Мы полулчили что предел сходиться к конечному значению, которое составляет приблизительно 2.71829......

## Частичные Суммы 
1. Определение

Частичными суммами натурального ряда являются 1, 3, 6, 10, 15 и т. д. Таким образом, n-я частичная сумма выражается формулой

$$ \sum _{k=1}^{n}k={\frac {n(n+1)}{2}}.$$
Это выражение было известно ещё Пифагору в VI веке до нашей эры. Числа такого вида называются треугольными, так как они могут быть представлены в виде треугольника.

Бесконечная последовательность треугольных чисел стремится к $ +\infty $  и, следовательно, бесконечная сумма натурального ряда также стремится к $ +\infty $ . Такой результат является следствием невыполнения необходимого условия сходимости числового ряда.

2. Пример решение в Octave GUI

Пусть данно реализовать нескольких операции над рядам $$a_{n}=\frac{1}{n(n+2)}$$
Для этого определим индексный вектор n от 2 до 11, а затем вычислим члены (рис2)
![рис 2](image/2.jpg) 

## Сумма Ряда 
1. Пример находение через Octave GUI

Найдем сууму первых 1000 членов гармоничемкогоо ряда $$ \sum^{1000}_{n=1} \frac{1}{n}$$
на (рис.3)
![рис 3](image/3.jpg) 

## Численное Интегрирование
вычисление значения определённого интеграла (как правило, приближённое). Под численным интегрированием понимают набор численных методов для нахождения значения определённого интеграла.

Численное интегрирование применяется, когда:

- Сама подынтегральная функция не задана аналитически. Например, она представлена в виде таблицы (массива) значений в узлах некоторой расчётной сетки.
- Аналитическое представление подынтегральной функции известно, но её первообразная не выражается через аналитические функции. Например, $ f(x)=\exp(-x^{2})$.
В этих двух случаях невозможно вычисление интеграла по формуле Ньютона — Лейбница. Также возможна ситуация, когда вид первообразной настолько сложен, что быстрее вычислить значение интеграла численным методом.
## 1. Вычисление Интегралов

Вычислим интеграл :$$\int^{\frac{\pi}{2}}_{0} \epsilon^{x^2}\cos(x)dx$$
решение на рис(4).
![рис 3](image/3.jpg) 

## 2. Аппроксимирование Суммами
Находим с помощью правилом средней точки, правило трапеции и правило Симпсона. Для этог  о напешим альгоритм решение как рис4.
![рис 4](image/4.jpg) 
с помошью называнием тестовой файл запустим 
![рис 5](image/5.jpg) 

расмотрим другой способ решения через Векторный метод, для этого создадим вектор $x$— координат средных точек. затем мы оценим $f$ по этому вектору, чтобы получить вектор значений функции. Аппроксиация средней точки — это сумма компонент вектора умноженная на $\Delta x$. на рис$.6$ и рис.$7$.
![рис 6](image/6.jpg)
![рис 7](image/7.jpg)
# Выводы

Изучили как оформлять и решать задачи над пределам и также последовательностиям и ряды  через Octave GNU.

# Список литературы{.unnumbered}

1. [OCtave GNU](https://octave.org/bugs.html)

2.[Предел числовой последовательности](https://ru.wikipedia.org/wiki/%D0%9F%D1%80%D0%B5%D0%B4%D0%B5%D0%BB_%D1%87%D0%B8%D1%81%D0%BB%D0%BE%D0%B2%D0%BE%D0%B9_%D0%BF%D0%BE%D1%81%D0%BB%D0%B5%D0%B4%D0%BE%D0%B2%D0%B0%D1%82%D0%B5%D0%BB%D1%8C%D0%BD%D0%BE%D1%81%D1%82%D0%B8)

2. [Задача аппроксимации ](http://aco.ifmo.ru/el_books/numerical_methods/lectures/glava4.html?ysclid=laxt60c5nb233588438)