---
## Front matter
lang: ru-RU
title: Дискреционное разграничение прав в Linux. Основные атрибуты
author: |
	 Аба Альфонсе Нпм-02-18\inst{1}

institute: |
	\inst{1}Российский Университет Дружбы Народов

date: 01 октября, 2021, Москва, Россия

## Formatting
mainfont: PT Serif
romanfont: PT Serif
sansfont: PT Sans

monofont: PT Mono
toc: false
slide_level: 2
theme: metropolis
header-includes: 
 - \metroset{progressbar=frametitle,sectionpage=progressbar,numbering=fraction}
 - '\makeatletter'
 - '\beamer@ignorenonframefalse'
 - '\makeatother'
aspectratio: 43
section-titles: true

---

# Лабораторная работа №6

## Цели работы

Развить навыки администрирования ОС Linux. Получить первое практическое знакомство с технологией SELinux1.
Проверить работу SELinx на практике совместно с веб-сервером
Apache.

## Подготовка к работе на технологией SELinux. 

- Установка, проверка и настройка веб-сервер Apache и конфигурации «рабочая станция»

 ![Рисунок 1](Images/lab6-2.png){ #fig:001 width=70% }

- ввод в систему с полученными учётными данными и запуска программу.

 ![Рисунок 2](Images/lab6-3.png){ #fig:002 width=70% }

## Создание Программу от имени суперпользователя

- проверка созданной прогаммы

 ![Рисунок 3](Images/lab6-7.png){ #fig:003 width=70% }

- проверка контекст созданного файла

 ![Рисунок 4](Images/lab6-8.png){ #fig:004 width=70% }

- Изучение справку man httpd_selinux

 ![Рисунок 5](Images/lab6-6.png){ #fig:005 width=70% }

## Изменение контекста файла /var/www/html/test.html с httpd_sys_content_t

- chcon -t samba_share_t /var/www/html/test.html

![Рисунок 6](Images/lab6-11.png){ #fig:006 width=70% }

- Анализируйте ситуацию : tail /var/log/messages

![Рисунок 7](Images/lab6-12.png){ #fig:007 width=70% }

- Перезапуск веб-сервера Apache и его пояснение : 

Анализ  лог-файлы с помошью tail -nl /var/log/message и Промостр файлы /var/log/http/error_log , /var/log/http/access_log и /var/log/audit/audit.log

![Рисунок 8](Images/lab6-13.png){ #fig:008 width=70% }

#  Выполнение команду 

- semanage port -a -t http_port_t -р tcp 81

![Рисунок 9](Images/lab6-15.png){ #fig:009 width=70% }

- Удалите файл /var/www/html/test.html

![Рисунок 10](Images/lab6-17.png){ #fig:009 width=70% }

## Вывод

В ходе выяполнения работы я получил первое практическое знакомство с технологией SELinux1.Преобрел работу SELinx на практике совместно с веб-сервером Apache.
и намного рашерил мой рабочий способ дискреционного разграничения доступа в современных системах с открытым кодом на базе OC Linux.
















 