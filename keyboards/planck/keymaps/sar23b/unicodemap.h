/* unicode codepoints used on keebs 
 */

enum unicode_names {
    SNEK,
    ZWJ,
    VS16,
    FLAG,
    TRANS,
    GAY,
    GLITT,
    PHEART,
    UPDF,
    NMOF,
    FLKE,
    SNOW,
    UNICRN,
    PENGU,
    SAUWIA,
    DOLPI,
    WHALE,
    CATPIL,
    NAILS,
    TURTLE,
    BUTFLY
};

const uint32_t PROGMEM unicode_map[] = {
    [ZWJ] = 0x200D, // Zero Width Joiner
    [VS16] = 0xFE0F, // Variation Selector-16
    [SNEK]  = 0x1F40D, // 🐍
    [FLAG] = 0x1F3F3, // 🏳
    [TRANS] = 0x26A7, // ⚧
    [GAY] = 0x1F308, // 🌈
    [GLITT] = 0x2728, // ✨
    [PHEART] = 0x1F49C, // 💜
    [UPDF] = 0x1F643, // 🙃
    [NMOF] = 0x1F636, // 😶
    [FLKE] = 0x2744, // ❄
    [SNOW] = 0x1F328, // 🌨
    [UNICRN] = 0x1f984, // 🦄
    [PENGU] = 0x1f427, // 🐧
    [SAUWIA] = 0x1f995, // 🦕
    [DOLPI] = 0x1f42c, // 🐬
    [WHALE] = 0x1f40b, // 🐋
    [CATPIL] = 0x1f41b, // 🐛
    [NAILS] = 0x1f485l, // 💅
    [TURTLE] = 0x1f422, // 🐢
    [BUTFLY] = 0x1f98b // 🦋
};
