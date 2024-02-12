#ifndef UNICODE_MAP
#define UNICODE_MAP
/* unicode codepoints used on keebs 
 */

enum unicode_names {
    // control 
    ZWJ,
    VS16,

    // gay
    FLAG,
    TRANS,
    GAY,
    NAILS,

    // animal
    SNEK,
    UNICRN,
    PENGU,
    SAUWIA,
    DOLPI,
    WHALE,
    CATPIL,
    TURTLE,
    BUTFLY,

    // space
    STARS,
    SAT,
    MIKWAY,
    SATURN,
    ALIEN,

    // emotion
    GLITT,
    PHEART,
    UPDF,
    NMOF,
    LIT,

    // weather
    FLKE,
    SNOW,

    // pictures
    FIRWRK,
    SPAKL,
    CDUSK,
    SUNST,
    NISTA,
    NBRI,

    // food
    WAFLE,

    // other
    GIFT

};

const uint32_t PROGMEM unicode_map[] = {
    // control
    [ZWJ] = 0x200D, // Zero Width Joiner
    [VS16] = 0xFE0F, // Variation Selector-16

    // gay
    [FLAG] = 0x1F3F3, // 🏳
    [TRANS] = 0x26A7, // ⚧
    [GAY] = 0x1F308, // 🌈
    [NAILS] = 0x1f485l, // 💅

    // animal 
    [SNEK]  = 0x1F40D, // 🐍
    [UNICRN] = 0x1f984, // 🦄
    [PENGU] = 0x1f427, // 🐧
    [SAUWIA] = 0x1f995, // 🦕
    [DOLPI] = 0x1f42c, // 🐬
    [WHALE] = 0x1f40b, // 🐋
    [CATPIL] = 0x1f41b, // 🐛
    [TURTLE] = 0x1f422, // 🐢
    [BUTFLY] = 0x1f98b, // 🦋

    // space 
    [ALIEN] = 0x1f47e,  // 👾
    [STARS] = 0x1f320, // 🌠
    [SAT] = 0x1f6f0, // 🛰
    [MIKWAY] = 0x1f30c, // 🌌
    [SATURN] = 0x1fa90, // 🪐

    // emotion
    [GLITT] = 0x2728, // ✨
    [PHEART] = 0x1F49C, // 💜
    [UPDF] = 0x1F643, // 🙃
    [NMOF] = 0x1F636, // 😶
    [LIT] = 0x1f525, // 🔥

    // weather
    [FLKE] = 0x2744, // ❄
    [SNOW] = 0x1F328, // 🌨

    // pictures
    [NISTA] = 0x1f303, // 🌃
    [NBRI] = 0x1f309, // 🌉
    [FIRWRK] = 0x1f386, // 🎆
    [SPAKL] = 0x1f387, // 🎇
    [CDUSK] = 0x1f306, // 🌆
    [SUNST] = 0x1f307, // 🌇

    // food
    [WAFLE] = 0x1f9c7, // 🧇

    // other
    [GIFT] = 0x1f381 // 🎁
};
#endif 
