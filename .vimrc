"NERDTree da
    let g:NERDTreeShowHidden = 0

"Отступы
"для крестов или змеюки
    set expandtab "Замена отступов на пробелы
    set smarttab "При на жатии tab создаёт пробелы
    "Отключать для make
    set tabstop=4 "Количество пробелов в отступе
    set softtabstop=4 "Количество пробелов в отступе при удалении
    set shiftwidth=4 "Количество пробелов smarttab

"=============НАСТРОЙКИ СВОРАЧИВАНИЯ БЛОКОВ КОДА (фолдинг)=============
    set foldenable " отклключить фолдинг по умолчанию
    set foldmethod=syntax " определять блоки на основе синтаксиса файла
    "set foldmethod=indent " определять блоки на основе отступов
    set foldnestmax=3       "deepest fold is 3 levels
    "set foldcolumn=10 " показать полосу для управления сворачиванием
    set foldlevel=1 " Первый уровень вложенности открыт, остальные закрыты
    "set foldopen=all " автоматическое открытие сверток при заходе в них

"Сборка
    set makeprg=make 
    nnoremap <F4> :make!<cr>

"Запуск
    nnoremap <F5> :!./Exec<cr>

"Отладка
    let debugFiles='' 
    nnoremap <F6> :execute '!gfortran -g -ffpe-trap=zero,invalid,overflow,underflow ' . debugFiles . ';gdb a.out -q' . '; rm a.out'
