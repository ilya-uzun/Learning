## Конфог файл для eslint   
eslint требует наличия конфигурационного файла. Создайте в корне вашего проекта файл .eslintrc.yml со следующим содержанием:
~~~
extends:
   - 'airbnb-base'
 env:
   node: true
   browser: true
~~~

## Подключение отдельного файла в html

~~~ html
  <body>
<script src="script.js" type="text/javascript"></script>
  </body>
~~~
>  src="script.js" название файла    
>  type="text/javascript" -  тип используемого языка (Без этого не работает)   


[Справка](http://htmlbook.ru/html)   
[Пример](https://www.youtube.com/watch?v=JkYOYtIAwR0)
