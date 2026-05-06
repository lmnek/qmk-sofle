# Sofle vs. kanata

This keymap mirrors `~/.config/kanata/kanata.kbd` so muscle memory transfers
between the daily-driver kanata setup and the Sofle split.

## What matches kanata 1:1

| Behavior | Position |
|---|---|
| `ESC` tap / chars layer hold | Caps-position (row 3 outer-left) — same as kanata `@⎋+🔣` |
| `BSPC` tap / vim layer hold | `]`-position (row 2 outer-right) — same as kanata `@⌫+` |
| `ENT` tap / `LCtl` hold | `;`-position (row 3 inner-right) — same as kanata `@↩+⌃` |
| `SPC` tap / `LGui` hold | inner-left thumb — same as kanata `@␣+⌘` |
| `.` tap / numpad hold | `.`-position — same as kanata `@.+` |
| chars layer cell-by-cell | `~ # { } &` on `qwert`, `% ; ( ) ?` on `asdfg`, etc. |
| nav layer with vim word motions | `b` (`C-Left`), `e` (`C-Right`), `^` (Home), `$` (End), `cu`/`cd` (PgUp/PgDn) |
| czech layer (low/up) | held via right-thumb |

## What's different (Sofle wins)

The split has **5 thumb keys per side** vs. kanata's 3. Extra slots used for:

- `OSM_SFT` (left outer thumb) — see *one-shot mods* below
- `MOD_SPC` mirrored on **both** thumbs (symmetric `SPC` tap / `LGui` hold) —
  use either thumb for space, or hold one and tap the other
- `CZ_LOW` (right thumb, replaces `RAlt`) — czech toggle, mirrors kanata's right-thumb cz-toggle
- `KC_DEL` (right outermost thumb) — bonus delete
- Encoder presses still map to `MUTE` / `PrtSc`

Layer holds (`BSP_NAV`, `ESC_CHR`) live on **both** the kanata-mirror row positions
**and** the right thumbs — pick whichever feels better in the moment.

## Things kanata can't do (new to learn)

### One-shot shift (`OSM_SFT`)

Tap once → the **next** keypress is shifted, then it auto-releases.
Lets you write a single capital letter without holding shift.

```
Tap OSM_SFT, tap A   →   A
Tap OSM_SFT, tap A, tap b   →   Ab
```

Hold it like a normal shift if you want the regular sustained behaviour.
Particularly handy for sentence-starts and proper nouns.

### Czech layer mechanics

```
Hold right-thumb (CZ_LOW)         → access lowercase: á č ď é ě í ň ó ř š ť ú ů ý ž (+ ä)
Hold right-thumb + LSft slot      → access uppercase: Á Č Ď É Ě Í Ň Ó Ř Š Ť Ú Ů Ý Ž
```

Czech letters are typed via Linux IBus-compatible unicode input
(`Ctrl+Shift+U` → hex → `Enter`). Configured in `config.h`:

```c
#define UNICODE_SELECTED_MODES UNICODE_MODE_LINUX
```

If unicode input doesn't fire, your DE may need `IBUS_ENABLE_CTRL_SHIFT_U=yes`
or `gtk-im-module=ibus`. (Kanata sidesteps this with `linux-unicode-termination
enter` + `danger-enable-cmd`; QMK uses the standard IBus shortcut.)

## What's missing / dropped vs. kanata

- **Mouse layer** — not implemented (skipped per request). Easy to add later as
  `_MOUSE` and an `LT(_MOUSE, KC_SCLN)` on the `;` slot if you want it.
- **Play/pause** — kanata had it on `]`-position (now `BSP_NAV`). Add to a free
  slot (e.g. an outer thumb) if you miss it.
- **Rotary scroll behavior** — kanata's mouse layer has scroll on home row;
  Sofle uses the encoder rotation directly via `encoder.c` instead.
- **Layer activation positions for chars/nav** — also placed on thumbs (extra
  ergonomics). Kanata only has them on home-row pinky positions.

## Recommended workflow

1. Burn this in via the home-row positions first (matches kanata reflexes).
2. Once comfortable, start using the thumb-cluster equivalents for the same
   layers — the thumbs are kinder on the pinkies and the split's strength.
3. Add `OSM_SFT` to your sentence-starting routine; it's a small habit shift
   with big ergonomic payoff.

## Build

```sh
cd ~/repos/qmk_firmware
qmk compile -kb sofle -km lmnk
qmk flash -kb sofle -km lmnk   # put one half in bootloader mode first
```

Files touched in this round:
- `keymap.c` — new layout, layers, czech unicode
- `config.h` — `UNICODE_SELECTED_MODES`
- `rules.mk` — `UNICODE_ENABLE = yes`
- `oled.c` — added `cz` / `CZ` layer labels
