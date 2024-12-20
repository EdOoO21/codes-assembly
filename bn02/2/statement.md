|                      |       |
|----------------------|-------|
| **Time limit:**      | `1 s` |
| **Real time limit:** | `5 s` |
| **Memory limit:**    | `64M` |


### Problem bn02-2: c/floats/quake

В 2010 году отечественная индустрия игр была на взлёте, появлялись всё больше и больше новых и
интересных игр! Яна и Алексей тоже решили сделать свою крутую 3д игру “Дрожь Земли”, они достаточно
быстро придумали, что там нужно будет бегать и стрелять в монстров, собирать оружие и классно
прыгать. Яна нарисовала графику, а Алексей занялся написанием движка. Через какое-то время всё было
закончено, но вот незадача среди ребят не оказалось ни одного любителя дискры и матанализа, а пары
АКиОС тогда ещё нарушали правила ВШЭ(на них никто не ходил) и игра оказалась очень медленной и
зависающей. Спустя 13 лет вам в руки попал тот самый код и вы решили, что сможете исправить и
разобраться в коде. Покапавшись, вы узнали, что Алексей забыл математику, но пытался как-то
реализовать функцию, которая будет уметь быстро считать обратный кубический корень от числа с некой
апроксимацией. Ваша задача переписать эту функцию float fast_reverse_cube(float number) и применить
её к массиву чисел, который подаётся на стандартный вход. Стандартную библиотеку math.h использовать
запрещено.

Вам так же может быть полезно почитать про то, как это сделали ребята в [другой
игре](https://en.wikipedia.org/wiki/Fast_inverse_square_root), а так же более подробную
[статью](http://web.archive.org/web/20181125230416/http://www.phailed.me/2014/10/0x5f400000-understanding-
fast-inverse-sqrt-the-easyish-way/) про ту же игру.

На вход подается последовательность вещественных чисел. Для каждого выведите ответ

Для подсчёта обратного кубического корня циклы использовать запрещено

### Examples

#### Input

    
    
    1 2 3 4

#### Output

    
    
    0.999990 0.793701 0.693354 0.62996

