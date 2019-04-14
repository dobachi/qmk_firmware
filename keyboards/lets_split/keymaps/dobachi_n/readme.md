# README

## how to flash

```
$ make lets_split:dobachi_n:dfu
```
なお、DFUモードになるのを待つことになるので、
そのタイミングでPro MicroのGRDとRSTをショートさせる。（数秒ほど？）


もしくはだが、これはうまくいかない。

```
$ make lets_split:dobachi_n:avrdude
```
