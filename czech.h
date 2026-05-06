/* Czech unicode keycodes
 * Requires UNICODE_ENABLE = yes in rules.mk
 * Uses UNICODE_MODE_LINUX (Ctrl+Shift+U + hex + Enter) by default.
 */

#pragma once

#include QMK_KEYBOARD_H

// czech unicode (lowercase)
#define CZ_ad   UC(0x00E4)  // ä
#define CZ_a    UC(0x00E1)  // á
#define CZ_c    UC(0x010D)  // č
#define CZ_d    UC(0x010F)  // ď
#define CZ_e    UC(0x00E9)  // é
#define CZ_eh   UC(0x011B)  // ě
#define CZ_i    UC(0x00ED)  // í
#define CZ_n    UC(0x0148)  // ň
#define CZ_o    UC(0x00F3)  // ó
#define CZ_r    UC(0x0159)  // ř
#define CZ_s    UC(0x0161)  // š
#define CZ_t    UC(0x0165)  // ť
#define CZ_u    UC(0x00FA)  // ú
#define CZ_uk   UC(0x016F)  // ů
#define CZ_y    UC(0x00FD)  // ý
#define CZ_z    UC(0x017E)  // ž

// czech unicode (uppercase)
#define CZ_A    UC(0x00C1)  // Á
#define CZ_C    UC(0x010C)  // Č
#define CZ_D    UC(0x010E)  // Ď
#define CZ_E    UC(0x00C9)  // É
#define CZ_Eh   UC(0x011A)  // Ě
#define CZ_I    UC(0x00CD)  // Í
#define CZ_N    UC(0x0147)  // Ň
#define CZ_O    UC(0x00D3)  // Ó
#define CZ_R    UC(0x0158)  // Ř
#define CZ_S    UC(0x0160)  // Š
#define CZ_T    UC(0x0164)  // Ť
#define CZ_U    UC(0x00DA)  // Ú
#define CZ_Uk   UC(0x016E)  // Ů
#define CZ_Y    UC(0x00DD)  // Ý
#define CZ_Z    UC(0x017D)  // Ž
