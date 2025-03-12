
Add submodule to the `qmk_firmware` repo:
```
git submodule add https://github.com/lmnek/qmk-sofle keyboards/sofle/keymaps/lmnk
```

Compile/flash the layout:
```
qmk compile -kb sofle/rev1 -km lmnk
```
