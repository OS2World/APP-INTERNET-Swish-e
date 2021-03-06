
/* This file was generated automatically by the Snowball to ANSI C compiler */

#include "header.h"

extern int italian_stem(struct SN_env * z);
static int r_vowel_suffix(struct SN_env * z);
static int r_verb_suffix(struct SN_env * z);
static int r_standard_suffix(struct SN_env * z);
static int r_attached_pronoun(struct SN_env * z);
static int r_R2(struct SN_env * z);
static int r_R1(struct SN_env * z);
static int r_RV(struct SN_env * z);
static int r_mark_regions(struct SN_env * z);
static int r_postlude(struct SN_env * z);
static int r_prelude(struct SN_env * z);

extern struct SN_env * italian_create_env(void);
extern void italian_close_env(struct SN_env * z);

static symbol s_0_1[2] = { 'q', 'u' };
static symbol s_0_2[1] = { 225 };
static symbol s_0_3[1] = { 233 };
static symbol s_0_4[1] = { 237 };
static symbol s_0_5[1] = { 243 };
static symbol s_0_6[1] = { 250 };

static struct among a_0[7] =
{
/*  0 */ { 0, 0, -1, 7, 0},
/*  1 */ { 2, s_0_1, 0, 6, 0},
/*  2 */ { 1, s_0_2, 0, 1, 0},
/*  3 */ { 1, s_0_3, 0, 2, 0},
/*  4 */ { 1, s_0_4, 0, 3, 0},
/*  5 */ { 1, s_0_5, 0, 4, 0},
/*  6 */ { 1, s_0_6, 0, 5, 0}
};

static symbol s_1_1[1] = { 'I' };
static symbol s_1_2[1] = { 'U' };

static struct among a_1[3] =
{
/*  0 */ { 0, 0, -1, 3, 0},
/*  1 */ { 1, s_1_1, 0, 1, 0},
/*  2 */ { 1, s_1_2, 0, 2, 0}
};

static symbol s_2_0[2] = { 'l', 'a' };
static symbol s_2_1[4] = { 'c', 'e', 'l', 'a' };
static symbol s_2_2[6] = { 'g', 'l', 'i', 'e', 'l', 'a' };
static symbol s_2_3[4] = { 'm', 'e', 'l', 'a' };
static symbol s_2_4[4] = { 't', 'e', 'l', 'a' };
static symbol s_2_5[4] = { 'v', 'e', 'l', 'a' };
static symbol s_2_6[2] = { 'l', 'e' };
static symbol s_2_7[4] = { 'c', 'e', 'l', 'e' };
static symbol s_2_8[6] = { 'g', 'l', 'i', 'e', 'l', 'e' };
static symbol s_2_9[4] = { 'm', 'e', 'l', 'e' };
static symbol s_2_10[4] = { 't', 'e', 'l', 'e' };
static symbol s_2_11[4] = { 'v', 'e', 'l', 'e' };
static symbol s_2_12[2] = { 'n', 'e' };
static symbol s_2_13[4] = { 'c', 'e', 'n', 'e' };
static symbol s_2_14[6] = { 'g', 'l', 'i', 'e', 'n', 'e' };
static symbol s_2_15[4] = { 'm', 'e', 'n', 'e' };
static symbol s_2_16[4] = { 's', 'e', 'n', 'e' };
static symbol s_2_17[4] = { 't', 'e', 'n', 'e' };
static symbol s_2_18[4] = { 'v', 'e', 'n', 'e' };
static symbol s_2_19[2] = { 'c', 'i' };
static symbol s_2_20[2] = { 'l', 'i' };
static symbol s_2_21[4] = { 'c', 'e', 'l', 'i' };
static symbol s_2_22[6] = { 'g', 'l', 'i', 'e', 'l', 'i' };
static symbol s_2_23[4] = { 'm', 'e', 'l', 'i' };
static symbol s_2_24[4] = { 't', 'e', 'l', 'i' };
static symbol s_2_25[4] = { 'v', 'e', 'l', 'i' };
static symbol s_2_26[3] = { 'g', 'l', 'i' };
static symbol s_2_27[2] = { 'm', 'i' };
static symbol s_2_28[2] = { 's', 'i' };
static symbol s_2_29[2] = { 't', 'i' };
static symbol s_2_30[2] = { 'v', 'i' };
static symbol s_2_31[2] = { 'l', 'o' };
static symbol s_2_32[4] = { 'c', 'e', 'l', 'o' };
static symbol s_2_33[6] = { 'g', 'l', 'i', 'e', 'l', 'o' };
static symbol s_2_34[4] = { 'm', 'e', 'l', 'o' };
static symbol s_2_35[4] = { 't', 'e', 'l', 'o' };
static symbol s_2_36[4] = { 'v', 'e', 'l', 'o' };

static struct among a_2[37] =
{
/*  0 */ { 2, s_2_0, -1, -1, 0},
/*  1 */ { 4, s_2_1, 0, -1, 0},
/*  2 */ { 6, s_2_2, 0, -1, 0},
/*  3 */ { 4, s_2_3, 0, -1, 0},
/*  4 */ { 4, s_2_4, 0, -1, 0},
/*  5 */ { 4, s_2_5, 0, -1, 0},
/*  6 */ { 2, s_2_6, -1, -1, 0},
/*  7 */ { 4, s_2_7, 6, -1, 0},
/*  8 */ { 6, s_2_8, 6, -1, 0},
/*  9 */ { 4, s_2_9, 6, -1, 0},
/* 10 */ { 4, s_2_10, 6, -1, 0},
/* 11 */ { 4, s_2_11, 6, -1, 0},
/* 12 */ { 2, s_2_12, -1, -1, 0},
/* 13 */ { 4, s_2_13, 12, -1, 0},
/* 14 */ { 6, s_2_14, 12, -1, 0},
/* 15 */ { 4, s_2_15, 12, -1, 0},
/* 16 */ { 4, s_2_16, 12, -1, 0},
/* 17 */ { 4, s_2_17, 12, -1, 0},
/* 18 */ { 4, s_2_18, 12, -1, 0},
/* 19 */ { 2, s_2_19, -1, -1, 0},
/* 20 */ { 2, s_2_20, -1, -1, 0},
/* 21 */ { 4, s_2_21, 20, -1, 0},
/* 22 */ { 6, s_2_22, 20, -1, 0},
/* 23 */ { 4, s_2_23, 20, -1, 0},
/* 24 */ { 4, s_2_24, 20, -1, 0},
/* 25 */ { 4, s_2_25, 20, -1, 0},
/* 26 */ { 3, s_2_26, 20, -1, 0},
/* 27 */ { 2, s_2_27, -1, -1, 0},
/* 28 */ { 2, s_2_28, -1, -1, 0},
/* 29 */ { 2, s_2_29, -1, -1, 0},
/* 30 */ { 2, s_2_30, -1, -1, 0},
/* 31 */ { 2, s_2_31, -1, -1, 0},
/* 32 */ { 4, s_2_32, 31, -1, 0},
/* 33 */ { 6, s_2_33, 31, -1, 0},
/* 34 */ { 4, s_2_34, 31, -1, 0},
/* 35 */ { 4, s_2_35, 31, -1, 0},
/* 36 */ { 4, s_2_36, 31, -1, 0}
};

static symbol s_3_0[4] = { 'a', 'n', 'd', 'o' };
static symbol s_3_1[4] = { 'e', 'n', 'd', 'o' };
static symbol s_3_2[2] = { 'a', 'r' };
static symbol s_3_3[2] = { 'e', 'r' };
static symbol s_3_4[2] = { 'i', 'r' };

static struct among a_3[5] =
{
/*  0 */ { 4, s_3_0, -1, 1, 0},
/*  1 */ { 4, s_3_1, -1, 1, 0},
/*  2 */ { 2, s_3_2, -1, 2, 0},
/*  3 */ { 2, s_3_3, -1, 2, 0},
/*  4 */ { 2, s_3_4, -1, 2, 0}
};

static symbol s_4_0[2] = { 'i', 'c' };
static symbol s_4_1[4] = { 'a', 'b', 'i', 'l' };
static symbol s_4_2[2] = { 'o', 's' };
static symbol s_4_3[2] = { 'i', 'v' };

static struct among a_4[4] =
{
/*  0 */ { 2, s_4_0, -1, -1, 0},
/*  1 */ { 4, s_4_1, -1, -1, 0},
/*  2 */ { 2, s_4_2, -1, -1, 0},
/*  3 */ { 2, s_4_3, -1, 1, 0}
};

static symbol s_5_0[2] = { 'i', 'c' };
static symbol s_5_1[4] = { 'a', 'b', 'i', 'l' };
static symbol s_5_2[2] = { 'i', 'v' };

static struct among a_5[3] =
{
/*  0 */ { 2, s_5_0, -1, 1, 0},
/*  1 */ { 4, s_5_1, -1, 1, 0},
/*  2 */ { 2, s_5_2, -1, 1, 0}
};

static symbol s_6_0[3] = { 'i', 'c', 'a' };
static symbol s_6_1[5] = { 'l', 'o', 'g', 'i', 'a' };
static symbol s_6_2[3] = { 'o', 's', 'a' };
static symbol s_6_3[4] = { 'i', 's', 't', 'a' };
static symbol s_6_4[3] = { 'i', 'v', 'a' };
static symbol s_6_5[4] = { 'a', 'n', 'z', 'a' };
static symbol s_6_6[4] = { 'e', 'n', 'z', 'a' };
static symbol s_6_7[3] = { 'i', 'c', 'e' };
static symbol s_6_8[6] = { 'a', 't', 'r', 'i', 'c', 'e' };
static symbol s_6_9[4] = { 'i', 'c', 'h', 'e' };
static symbol s_6_10[5] = { 'l', 'o', 'g', 'i', 'e' };
static symbol s_6_11[5] = { 'a', 'b', 'i', 'l', 'e' };
static symbol s_6_12[5] = { 'i', 'b', 'i', 'l', 'e' };
static symbol s_6_13[6] = { 'u', 's', 'i', 'o', 'n', 'e' };
static symbol s_6_14[6] = { 'a', 'z', 'i', 'o', 'n', 'e' };
static symbol s_6_15[6] = { 'u', 'z', 'i', 'o', 'n', 'e' };
static symbol s_6_16[5] = { 'a', 't', 'o', 'r', 'e' };
static symbol s_6_17[3] = { 'o', 's', 'e' };
static symbol s_6_18[5] = { 'm', 'e', 'n', 't', 'e' };
static symbol s_6_19[6] = { 'a', 'm', 'e', 'n', 't', 'e' };
static symbol s_6_20[4] = { 'i', 's', 't', 'e' };
static symbol s_6_21[3] = { 'i', 'v', 'e' };
static symbol s_6_22[4] = { 'a', 'n', 'z', 'e' };
static symbol s_6_23[4] = { 'e', 'n', 'z', 'e' };
static symbol s_6_24[3] = { 'i', 'c', 'i' };
static symbol s_6_25[6] = { 'a', 't', 'r', 'i', 'c', 'i' };
static symbol s_6_26[4] = { 'i', 'c', 'h', 'i' };
static symbol s_6_27[5] = { 'a', 'b', 'i', 'l', 'i' };
static symbol s_6_28[5] = { 'i', 'b', 'i', 'l', 'i' };
static symbol s_6_29[4] = { 'i', 's', 'm', 'i' };
static symbol s_6_30[6] = { 'u', 's', 'i', 'o', 'n', 'i' };
static symbol s_6_31[6] = { 'a', 'z', 'i', 'o', 'n', 'i' };
static symbol s_6_32[6] = { 'u', 'z', 'i', 'o', 'n', 'i' };
static symbol s_6_33[5] = { 'a', 't', 'o', 'r', 'i' };
static symbol s_6_34[3] = { 'o', 's', 'i' };
static symbol s_6_35[6] = { 'a', 'm', 'e', 'n', 't', 'i' };
static symbol s_6_36[6] = { 'i', 'm', 'e', 'n', 't', 'i' };
static symbol s_6_37[4] = { 'i', 's', 't', 'i' };
static symbol s_6_38[3] = { 'i', 'v', 'i' };
static symbol s_6_39[3] = { 'i', 'c', 'o' };
static symbol s_6_40[4] = { 'i', 's', 'm', 'o' };
static symbol s_6_41[3] = { 'o', 's', 'o' };
static symbol s_6_42[6] = { 'a', 'm', 'e', 'n', 't', 'o' };
static symbol s_6_43[6] = { 'i', 'm', 'e', 'n', 't', 'o' };
static symbol s_6_44[3] = { 'i', 'v', 'o' };
static symbol s_6_45[3] = { 'i', 't', 224 };
static symbol s_6_46[4] = { 'i', 's', 't', 224 };
static symbol s_6_47[4] = { 'i', 's', 't', 232 };
static symbol s_6_48[4] = { 'i', 's', 't', 236 };

static struct among a_6[49] =
{
/*  0 */ { 3, s_6_0, -1, 1, 0},
/*  1 */ { 5, s_6_1, -1, 3, 0},
/*  2 */ { 3, s_6_2, -1, 1, 0},
/*  3 */ { 4, s_6_3, -1, 1, 0},
/*  4 */ { 3, s_6_4, -1, 9, 0},
/*  5 */ { 4, s_6_5, -1, 1, 0},
/*  6 */ { 4, s_6_6, -1, 5, 0},
/*  7 */ { 3, s_6_7, -1, 1, 0},
/*  8 */ { 6, s_6_8, 7, 1, 0},
/*  9 */ { 4, s_6_9, -1, 1, 0},
/* 10 */ { 5, s_6_10, -1, 3, 0},
/* 11 */ { 5, s_6_11, -1, 1, 0},
/* 12 */ { 5, s_6_12, -1, 1, 0},
/* 13 */ { 6, s_6_13, -1, 4, 0},
/* 14 */ { 6, s_6_14, -1, 2, 0},
/* 15 */ { 6, s_6_15, -1, 4, 0},
/* 16 */ { 5, s_6_16, -1, 2, 0},
/* 17 */ { 3, s_6_17, -1, 1, 0},
/* 18 */ { 5, s_6_18, -1, 1, 0},
/* 19 */ { 6, s_6_19, 18, 7, 0},
/* 20 */ { 4, s_6_20, -1, 1, 0},
/* 21 */ { 3, s_6_21, -1, 9, 0},
/* 22 */ { 4, s_6_22, -1, 1, 0},
/* 23 */ { 4, s_6_23, -1, 5, 0},
/* 24 */ { 3, s_6_24, -1, 1, 0},
/* 25 */ { 6, s_6_25, 24, 1, 0},
/* 26 */ { 4, s_6_26, -1, 1, 0},
/* 27 */ { 5, s_6_27, -1, 1, 0},
/* 28 */ { 5, s_6_28, -1, 1, 0},
/* 29 */ { 4, s_6_29, -1, 1, 0},
/* 30 */ { 6, s_6_30, -1, 4, 0},
/* 31 */ { 6, s_6_31, -1, 2, 0},
/* 32 */ { 6, s_6_32, -1, 4, 0},
/* 33 */ { 5, s_6_33, -1, 2, 0},
/* 34 */ { 3, s_6_34, -1, 1, 0},
/* 35 */ { 6, s_6_35, -1, 6, 0},
/* 36 */ { 6, s_6_36, -1, 6, 0},
/* 37 */ { 4, s_6_37, -1, 1, 0},
/* 38 */ { 3, s_6_38, -1, 9, 0},
/* 39 */ { 3, s_6_39, -1, 1, 0},
/* 40 */ { 4, s_6_40, -1, 1, 0},
/* 41 */ { 3, s_6_41, -1, 1, 0},
/* 42 */ { 6, s_6_42, -1, 6, 0},
/* 43 */ { 6, s_6_43, -1, 6, 0},
/* 44 */ { 3, s_6_44, -1, 9, 0},
/* 45 */ { 3, s_6_45, -1, 8, 0},
/* 46 */ { 4, s_6_46, -1, 1, 0},
/* 47 */ { 4, s_6_47, -1, 1, 0},
/* 48 */ { 4, s_6_48, -1, 1, 0}
};

static symbol s_7_0[4] = { 'i', 's', 'c', 'a' };
static symbol s_7_1[4] = { 'e', 'n', 'd', 'a' };
static symbol s_7_2[3] = { 'a', 't', 'a' };
static symbol s_7_3[3] = { 'i', 't', 'a' };
static symbol s_7_4[3] = { 'u', 't', 'a' };
static symbol s_7_5[3] = { 'a', 'v', 'a' };
static symbol s_7_6[3] = { 'e', 'v', 'a' };
static symbol s_7_7[3] = { 'i', 'v', 'a' };
static symbol s_7_8[6] = { 'e', 'r', 'e', 'b', 'b', 'e' };
static symbol s_7_9[6] = { 'i', 'r', 'e', 'b', 'b', 'e' };
static symbol s_7_10[4] = { 'i', 's', 'c', 'e' };
static symbol s_7_11[4] = { 'e', 'n', 'd', 'e' };
static symbol s_7_12[3] = { 'a', 'r', 'e' };
static symbol s_7_13[3] = { 'e', 'r', 'e' };
static symbol s_7_14[3] = { 'i', 'r', 'e' };
static symbol s_7_15[4] = { 'a', 's', 's', 'e' };
static symbol s_7_16[3] = { 'a', 't', 'e' };
static symbol s_7_17[5] = { 'a', 'v', 'a', 't', 'e' };
static symbol s_7_18[5] = { 'e', 'v', 'a', 't', 'e' };
static symbol s_7_19[5] = { 'i', 'v', 'a', 't', 'e' };
static symbol s_7_20[3] = { 'e', 't', 'e' };
static symbol s_7_21[5] = { 'e', 'r', 'e', 't', 'e' };
static symbol s_7_22[5] = { 'i', 'r', 'e', 't', 'e' };
static symbol s_7_23[3] = { 'i', 't', 'e' };
static symbol s_7_24[6] = { 'e', 'r', 'e', 's', 't', 'e' };
static symbol s_7_25[6] = { 'i', 'r', 'e', 's', 't', 'e' };
static symbol s_7_26[3] = { 'u', 't', 'e' };
static symbol s_7_27[4] = { 'e', 'r', 'a', 'i' };
static symbol s_7_28[4] = { 'i', 'r', 'a', 'i' };
static symbol s_7_29[4] = { 'i', 's', 'c', 'i' };
static symbol s_7_30[4] = { 'e', 'n', 'd', 'i' };
static symbol s_7_31[4] = { 'e', 'r', 'e', 'i' };
static symbol s_7_32[4] = { 'i', 'r', 'e', 'i' };
static symbol s_7_33[4] = { 'a', 's', 's', 'i' };
static symbol s_7_34[3] = { 'a', 't', 'i' };
static symbol s_7_35[3] = { 'i', 't', 'i' };
static symbol s_7_36[6] = { 'e', 'r', 'e', 's', 't', 'i' };
static symbol s_7_37[6] = { 'i', 'r', 'e', 's', 't', 'i' };
static symbol s_7_38[3] = { 'u', 't', 'i' };
static symbol s_7_39[3] = { 'a', 'v', 'i' };
static symbol s_7_40[3] = { 'e', 'v', 'i' };
static symbol s_7_41[3] = { 'i', 'v', 'i' };
static symbol s_7_42[4] = { 'i', 's', 'c', 'o' };
static symbol s_7_43[4] = { 'a', 'n', 'd', 'o' };
static symbol s_7_44[4] = { 'e', 'n', 'd', 'o' };
static symbol s_7_45[4] = { 'Y', 'a', 'm', 'o' };
static symbol s_7_46[4] = { 'i', 'a', 'm', 'o' };
static symbol s_7_47[5] = { 'a', 'v', 'a', 'm', 'o' };
static symbol s_7_48[5] = { 'e', 'v', 'a', 'm', 'o' };
static symbol s_7_49[5] = { 'i', 'v', 'a', 'm', 'o' };
static symbol s_7_50[5] = { 'e', 'r', 'e', 'm', 'o' };
static symbol s_7_51[5] = { 'i', 'r', 'e', 'm', 'o' };
static symbol s_7_52[6] = { 'a', 's', 's', 'i', 'm', 'o' };
static symbol s_7_53[4] = { 'a', 'm', 'm', 'o' };
static symbol s_7_54[4] = { 'e', 'm', 'm', 'o' };
static symbol s_7_55[6] = { 'e', 'r', 'e', 'm', 'm', 'o' };
static symbol s_7_56[6] = { 'i', 'r', 'e', 'm', 'm', 'o' };
static symbol s_7_57[4] = { 'i', 'm', 'm', 'o' };
static symbol s_7_58[3] = { 'a', 'n', 'o' };
static symbol s_7_59[6] = { 'i', 's', 'c', 'a', 'n', 'o' };
static symbol s_7_60[5] = { 'a', 'v', 'a', 'n', 'o' };
static symbol s_7_61[5] = { 'e', 'v', 'a', 'n', 'o' };
static symbol s_7_62[5] = { 'i', 'v', 'a', 'n', 'o' };
static symbol s_7_63[6] = { 'e', 'r', 'a', 'n', 'n', 'o' };
static symbol s_7_64[6] = { 'i', 'r', 'a', 'n', 'n', 'o' };
static symbol s_7_65[3] = { 'o', 'n', 'o' };
static symbol s_7_66[6] = { 'i', 's', 'c', 'o', 'n', 'o' };
static symbol s_7_67[5] = { 'a', 'r', 'o', 'n', 'o' };
static symbol s_7_68[5] = { 'e', 'r', 'o', 'n', 'o' };
static symbol s_7_69[5] = { 'i', 'r', 'o', 'n', 'o' };
static symbol s_7_70[8] = { 'e', 'r', 'e', 'b', 'b', 'e', 'r', 'o' };
static symbol s_7_71[8] = { 'i', 'r', 'e', 'b', 'b', 'e', 'r', 'o' };
static symbol s_7_72[6] = { 'a', 's', 's', 'e', 'r', 'o' };
static symbol s_7_73[6] = { 'e', 's', 's', 'e', 'r', 'o' };
static symbol s_7_74[6] = { 'i', 's', 's', 'e', 'r', 'o' };
static symbol s_7_75[3] = { 'a', 't', 'o' };
static symbol s_7_76[3] = { 'i', 't', 'o' };
static symbol s_7_77[3] = { 'u', 't', 'o' };
static symbol s_7_78[3] = { 'a', 'v', 'o' };
static symbol s_7_79[3] = { 'e', 'v', 'o' };
static symbol s_7_80[3] = { 'i', 'v', 'o' };
static symbol s_7_81[2] = { 'a', 'r' };
static symbol s_7_82[2] = { 'i', 'r' };
static symbol s_7_83[3] = { 'e', 'r', 224 };
static symbol s_7_84[3] = { 'i', 'r', 224 };
static symbol s_7_85[3] = { 'e', 'r', 242 };
static symbol s_7_86[3] = { 'i', 'r', 242 };

static struct among a_7[87] =
{
/*  0 */ { 4, s_7_0, -1, 1, 0},
/*  1 */ { 4, s_7_1, -1, 1, 0},
/*  2 */ { 3, s_7_2, -1, 1, 0},
/*  3 */ { 3, s_7_3, -1, 1, 0},
/*  4 */ { 3, s_7_4, -1, 1, 0},
/*  5 */ { 3, s_7_5, -1, 1, 0},
/*  6 */ { 3, s_7_6, -1, 1, 0},
/*  7 */ { 3, s_7_7, -1, 1, 0},
/*  8 */ { 6, s_7_8, -1, 1, 0},
/*  9 */ { 6, s_7_9, -1, 1, 0},
/* 10 */ { 4, s_7_10, -1, 1, 0},
/* 11 */ { 4, s_7_11, -1, 1, 0},
/* 12 */ { 3, s_7_12, -1, 1, 0},
/* 13 */ { 3, s_7_13, -1, 1, 0},
/* 14 */ { 3, s_7_14, -1, 1, 0},
/* 15 */ { 4, s_7_15, -1, 1, 0},
/* 16 */ { 3, s_7_16, -1, 1, 0},
/* 17 */ { 5, s_7_17, 16, 1, 0},
/* 18 */ { 5, s_7_18, 16, 1, 0},
/* 19 */ { 5, s_7_19, 16, 1, 0},
/* 20 */ { 3, s_7_20, -1, 1, 0},
/* 21 */ { 5, s_7_21, 20, 1, 0},
/* 22 */ { 5, s_7_22, 20, 1, 0},
/* 23 */ { 3, s_7_23, -1, 1, 0},
/* 24 */ { 6, s_7_24, -1, 1, 0},
/* 25 */ { 6, s_7_25, -1, 1, 0},
/* 26 */ { 3, s_7_26, -1, 1, 0},
/* 27 */ { 4, s_7_27, -1, 1, 0},
/* 28 */ { 4, s_7_28, -1, 1, 0},
/* 29 */ { 4, s_7_29, -1, 1, 0},
/* 30 */ { 4, s_7_30, -1, 1, 0},
/* 31 */ { 4, s_7_31, -1, 1, 0},
/* 32 */ { 4, s_7_32, -1, 1, 0},
/* 33 */ { 4, s_7_33, -1, 1, 0},
/* 34 */ { 3, s_7_34, -1, 1, 0},
/* 35 */ { 3, s_7_35, -1, 1, 0},
/* 36 */ { 6, s_7_36, -1, 1, 0},
/* 37 */ { 6, s_7_37, -1, 1, 0},
/* 38 */ { 3, s_7_38, -1, 1, 0},
/* 39 */ { 3, s_7_39, -1, 1, 0},
/* 40 */ { 3, s_7_40, -1, 1, 0},
/* 41 */ { 3, s_7_41, -1, 1, 0},
/* 42 */ { 4, s_7_42, -1, 1, 0},
/* 43 */ { 4, s_7_43, -1, 1, 0},
/* 44 */ { 4, s_7_44, -1, 1, 0},
/* 45 */ { 4, s_7_45, -1, 1, 0},
/* 46 */ { 4, s_7_46, -1, 1, 0},
/* 47 */ { 5, s_7_47, -1, 1, 0},
/* 48 */ { 5, s_7_48, -1, 1, 0},
/* 49 */ { 5, s_7_49, -1, 1, 0},
/* 50 */ { 5, s_7_50, -1, 1, 0},
/* 51 */ { 5, s_7_51, -1, 1, 0},
/* 52 */ { 6, s_7_52, -1, 1, 0},
/* 53 */ { 4, s_7_53, -1, 1, 0},
/* 54 */ { 4, s_7_54, -1, 1, 0},
/* 55 */ { 6, s_7_55, 54, 1, 0},
/* 56 */ { 6, s_7_56, 54, 1, 0},
/* 57 */ { 4, s_7_57, -1, 1, 0},
/* 58 */ { 3, s_7_58, -1, 1, 0},
/* 59 */ { 6, s_7_59, 58, 1, 0},
/* 60 */ { 5, s_7_60, 58, 1, 0},
/* 61 */ { 5, s_7_61, 58, 1, 0},
/* 62 */ { 5, s_7_62, 58, 1, 0},
/* 63 */ { 6, s_7_63, -1, 1, 0},
/* 64 */ { 6, s_7_64, -1, 1, 0},
/* 65 */ { 3, s_7_65, -1, 1, 0},
/* 66 */ { 6, s_7_66, 65, 1, 0},
/* 67 */ { 5, s_7_67, 65, 1, 0},
/* 68 */ { 5, s_7_68, 65, 1, 0},
/* 69 */ { 5, s_7_69, 65, 1, 0},
/* 70 */ { 8, s_7_70, -1, 1, 0},
/* 71 */ { 8, s_7_71, -1, 1, 0},
/* 72 */ { 6, s_7_72, -1, 1, 0},
/* 73 */ { 6, s_7_73, -1, 1, 0},
/* 74 */ { 6, s_7_74, -1, 1, 0},
/* 75 */ { 3, s_7_75, -1, 1, 0},
/* 76 */ { 3, s_7_76, -1, 1, 0},
/* 77 */ { 3, s_7_77, -1, 1, 0},
/* 78 */ { 3, s_7_78, -1, 1, 0},
/* 79 */ { 3, s_7_79, -1, 1, 0},
/* 80 */ { 3, s_7_80, -1, 1, 0},
/* 81 */ { 2, s_7_81, -1, 1, 0},
/* 82 */ { 2, s_7_82, -1, 1, 0},
/* 83 */ { 3, s_7_83, -1, 1, 0},
/* 84 */ { 3, s_7_84, -1, 1, 0},
/* 85 */ { 3, s_7_85, -1, 1, 0},
/* 86 */ { 3, s_7_86, -1, 1, 0}
};

static unsigned char g_v[] = { 17, 65, 16, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 128, 128, 8, 2, 1 };

static unsigned char g_AEIO[] = { 17, 65, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 128, 128, 8, 2 };

static unsigned char g_CG[] = { 17 };

static symbol s_0[] = { 224 };
static symbol s_1[] = { 232 };
static symbol s_2[] = { 236 };
static symbol s_3[] = { 242 };
static symbol s_4[] = { 249 };
static symbol s_5[] = { 'q', 'U' };
static symbol s_6[] = { 'u' };
static symbol s_7[] = { 'U' };
static symbol s_8[] = { 'i' };
static symbol s_9[] = { 'I' };
static symbol s_10[] = { 'i' };
static symbol s_11[] = { 'u' };
static symbol s_12[] = { 'e' };
static symbol s_13[] = { 'i', 'c' };
static symbol s_14[] = { 'l', 'o', 'g' };
static symbol s_15[] = { 'u' };
static symbol s_16[] = { 'e', 'n', 't', 'e' };
static symbol s_17[] = { 'a', 't' };
static symbol s_18[] = { 'a', 't' };
static symbol s_19[] = { 'i', 'c' };
static symbol s_20[] = { 'i' };
static symbol s_21[] = { 'h' };

static int r_prelude(struct SN_env * z) {
    int among_var;
    {   int c_test = z->c; /* test, line 35 */
        while(1) { /* repeat, line 35 */
            int c = z->c;
            z->bra = z->c; /* [, line 36 */
            among_var = find_among(z, a_0, 7); /* substring, line 36 */
            if (!(among_var)) goto lab0;
            z->ket = z->c; /* ], line 36 */
            switch(among_var) {
                case 0: goto lab0;
                case 1:
                    slice_from_s(z, 1, s_0); /* <-, line 37 */
                    break;
                case 2:
                    slice_from_s(z, 1, s_1); /* <-, line 38 */
                    break;
                case 3:
                    slice_from_s(z, 1, s_2); /* <-, line 39 */
                    break;
                case 4:
                    slice_from_s(z, 1, s_3); /* <-, line 40 */
                    break;
                case 5:
                    slice_from_s(z, 1, s_4); /* <-, line 41 */
                    break;
                case 6:
                    slice_from_s(z, 2, s_5); /* <-, line 42 */
                    break;
                case 7:
                    if (z->c >= z->l) goto lab0;
                    z->c++; /* next, line 43 */
                    break;
            }
            continue;
        lab0:
            z->c = c;
            break;
        }
        z->c = c_test;
    }
    while(1) { /* repeat, line 46 */
        int c = z->c;
        while(1) { /* goto, line 46 */
            int c = z->c;
            if (!(in_grouping(z, g_v, 97, 249))) goto lab2;
            z->bra = z->c; /* [, line 47 */
            {   int c = z->c; /* or, line 47 */
                if (!(eq_s(z, 1, s_6))) goto lab4;
                z->ket = z->c; /* ], line 47 */
                if (!(in_grouping(z, g_v, 97, 249))) goto lab4;
                slice_from_s(z, 1, s_7); /* <-, line 47 */
                goto lab3;
            lab4:
                z->c = c;
                if (!(eq_s(z, 1, s_8))) goto lab2;
                z->ket = z->c; /* ], line 48 */
                if (!(in_grouping(z, g_v, 97, 249))) goto lab2;
                slice_from_s(z, 1, s_9); /* <-, line 48 */
            }
        lab3:
            z->c = c;
            break;
        lab2:
            z->c = c;
            if (z->c >= z->l) goto lab1;
            z->c++;
        }
        continue;
    lab1:
        z->c = c;
        break;
    }
    return 1;
}

static int r_mark_regions(struct SN_env * z) {
    z->I[0] = z->l;
    z->I[1] = z->l;
    z->I[2] = z->l;
    {   int c = z->c; /* do, line 58 */
        {   int c = z->c; /* or, line 60 */
            if (!(in_grouping(z, g_v, 97, 249))) goto lab2;
            {   int c = z->c; /* or, line 59 */
                if (!(out_grouping(z, g_v, 97, 249))) goto lab4;
                while(1) { /* gopast, line 59 */
                    if (!(in_grouping(z, g_v, 97, 249))) goto lab5;
                    break;
                lab5:
                    if (z->c >= z->l) goto lab4;
                    z->c++;
                }
                goto lab3;
            lab4:
                z->c = c;
                if (!(in_grouping(z, g_v, 97, 249))) goto lab2;
                while(1) { /* gopast, line 59 */
                    if (!(out_grouping(z, g_v, 97, 249))) goto lab6;
                    break;
                lab6:
                    if (z->c >= z->l) goto lab2;
                    z->c++;
                }
            }
        lab3:
            goto lab1;
        lab2:
            z->c = c;
            if (!(out_grouping(z, g_v, 97, 249))) goto lab0;
            {   int c = z->c; /* or, line 61 */
                if (!(out_grouping(z, g_v, 97, 249))) goto lab8;
                while(1) { /* gopast, line 61 */
                    if (!(in_grouping(z, g_v, 97, 249))) goto lab9;
                    break;
                lab9:
                    if (z->c >= z->l) goto lab8;
                    z->c++;
                }
                goto lab7;
            lab8:
                z->c = c;
                if (!(in_grouping(z, g_v, 97, 249))) goto lab0;
                if (z->c >= z->l) goto lab0;
                z->c++; /* next, line 61 */
            }
        lab7:
            ;
        }
    lab1:
        z->I[0] = z->c; /* setmark pV, line 62 */
    lab0:
        z->c = c;
    }
    {   int c = z->c; /* do, line 64 */
        while(1) { /* gopast, line 65 */
            if (!(in_grouping(z, g_v, 97, 249))) goto lab11;
            break;
        lab11:
            if (z->c >= z->l) goto lab10;
            z->c++;
        }
        while(1) { /* gopast, line 65 */
            if (!(out_grouping(z, g_v, 97, 249))) goto lab12;
            break;
        lab12:
            if (z->c >= z->l) goto lab10;
            z->c++;
        }
        z->I[1] = z->c; /* setmark p1, line 65 */
        while(1) { /* gopast, line 66 */
            if (!(in_grouping(z, g_v, 97, 249))) goto lab13;
            break;
        lab13:
            if (z->c >= z->l) goto lab10;
            z->c++;
        }
        while(1) { /* gopast, line 66 */
            if (!(out_grouping(z, g_v, 97, 249))) goto lab14;
            break;
        lab14:
            if (z->c >= z->l) goto lab10;
            z->c++;
        }
        z->I[2] = z->c; /* setmark p2, line 66 */
    lab10:
        z->c = c;
    }
    return 1;
}

static int r_postlude(struct SN_env * z) {
    int among_var;
    while(1) { /* repeat, line 70 */
        int c = z->c;
        z->bra = z->c; /* [, line 72 */
        among_var = find_among(z, a_1, 3); /* substring, line 72 */
        if (!(among_var)) goto lab0;
        z->ket = z->c; /* ], line 72 */
        switch(among_var) {
            case 0: goto lab0;
            case 1:
                slice_from_s(z, 1, s_10); /* <-, line 73 */
                break;
            case 2:
                slice_from_s(z, 1, s_11); /* <-, line 74 */
                break;
            case 3:
                if (z->c >= z->l) goto lab0;
                z->c++; /* next, line 75 */
                break;
        }
        continue;
    lab0:
        z->c = c;
        break;
    }
    return 1;
}

static int r_RV(struct SN_env * z) {
    if (!(z->I[0] <= z->c)) return 0;
    return 1;
}

static int r_R1(struct SN_env * z) {
    if (!(z->I[1] <= z->c)) return 0;
    return 1;
}

static int r_R2(struct SN_env * z) {
    if (!(z->I[2] <= z->c)) return 0;
    return 1;
}

static int r_attached_pronoun(struct SN_env * z) {
    int among_var;
    z->ket = z->c; /* [, line 87 */
    if (!(find_among_b(z, a_2, 37))) return 0; /* substring, line 87 */
    z->bra = z->c; /* ], line 87 */
    among_var = find_among_b(z, a_3, 5); /* among, line 97 */
    if (!(among_var)) return 0;
    if (!r_RV(z)) return 0; /* call RV, line 97 */
    switch(among_var) {
        case 0: return 0;
        case 1:
            slice_del(z); /* delete, line 98 */
            break;
        case 2:
            slice_from_s(z, 1, s_12); /* <-, line 99 */
            break;
    }
    return 1;
}

static int r_standard_suffix(struct SN_env * z) {
    int among_var;
    z->ket = z->c; /* [, line 104 */
    among_var = find_among_b(z, a_6, 49); /* substring, line 104 */
    if (!(among_var)) return 0;
    z->bra = z->c; /* ], line 104 */
    switch(among_var) {
        case 0: return 0;
        case 1:
            if (!r_R2(z)) return 0; /* call R2, line 110 */
            slice_del(z); /* delete, line 110 */
            break;
        case 2:
            if (!r_R2(z)) return 0; /* call R2, line 112 */
            slice_del(z); /* delete, line 112 */
            {   int m = z->l - z->c; /* try, line 113 */
                z->ket = z->c; /* [, line 113 */
                if (!(eq_s_b(z, 2, s_13))) { z->c = z->l - m; goto lab0; }
                z->bra = z->c; /* ], line 113 */
                if (!r_R2(z)) { z->c = z->l - m; goto lab0; } /* call R2, line 113 */
                slice_del(z); /* delete, line 113 */
            lab0:
                ;
            }
            break;
        case 3:
            if (!r_R2(z)) return 0; /* call R2, line 116 */
            slice_from_s(z, 3, s_14); /* <-, line 116 */
            break;
        case 4:
            if (!r_R2(z)) return 0; /* call R2, line 118 */
            slice_from_s(z, 1, s_15); /* <-, line 118 */
            break;
        case 5:
            if (!r_R2(z)) return 0; /* call R2, line 120 */
            slice_from_s(z, 4, s_16); /* <-, line 120 */
            break;
        case 6:
            if (!r_RV(z)) return 0; /* call RV, line 122 */
            slice_del(z); /* delete, line 122 */
            break;
        case 7:
            if (!r_R1(z)) return 0; /* call R1, line 124 */
            slice_del(z); /* delete, line 124 */
            {   int m = z->l - z->c; /* try, line 125 */
                z->ket = z->c; /* [, line 126 */
                among_var = find_among_b(z, a_4, 4); /* substring, line 126 */
                if (!(among_var)) { z->c = z->l - m; goto lab1; }
                z->bra = z->c; /* ], line 126 */
                if (!r_R2(z)) { z->c = z->l - m; goto lab1; } /* call R2, line 126 */
                slice_del(z); /* delete, line 126 */
                switch(among_var) {
                    case 0: { z->c = z->l - m; goto lab1; }
                    case 1:
                        z->ket = z->c; /* [, line 127 */
                        if (!(eq_s_b(z, 2, s_17))) { z->c = z->l - m; goto lab1; }
                        z->bra = z->c; /* ], line 127 */
                        if (!r_R2(z)) { z->c = z->l - m; goto lab1; } /* call R2, line 127 */
                        slice_del(z); /* delete, line 127 */
                        break;
                }
            lab1:
                ;
            }
            break;
        case 8:
            if (!r_R2(z)) return 0; /* call R2, line 133 */
            slice_del(z); /* delete, line 133 */
            {   int m = z->l - z->c; /* try, line 134 */
                z->ket = z->c; /* [, line 135 */
                among_var = find_among_b(z, a_5, 3); /* substring, line 135 */
                if (!(among_var)) { z->c = z->l - m; goto lab2; }
                z->bra = z->c; /* ], line 135 */
                switch(among_var) {
                    case 0: { z->c = z->l - m; goto lab2; }
                    case 1:
                        if (!r_R2(z)) { z->c = z->l - m; goto lab2; } /* call R2, line 136 */
                        slice_del(z); /* delete, line 136 */
                        break;
                }
            lab2:
                ;
            }
            break;
        case 9:
            if (!r_R2(z)) return 0; /* call R2, line 141 */
            slice_del(z); /* delete, line 141 */
            {   int m = z->l - z->c; /* try, line 142 */
                z->ket = z->c; /* [, line 142 */
                if (!(eq_s_b(z, 2, s_18))) { z->c = z->l - m; goto lab3; }
                z->bra = z->c; /* ], line 142 */
                if (!r_R2(z)) { z->c = z->l - m; goto lab3; } /* call R2, line 142 */
                slice_del(z); /* delete, line 142 */
                z->ket = z->c; /* [, line 142 */
                if (!(eq_s_b(z, 2, s_19))) { z->c = z->l - m; goto lab3; }
                z->bra = z->c; /* ], line 142 */
                if (!r_R2(z)) { z->c = z->l - m; goto lab3; } /* call R2, line 142 */
                slice_del(z); /* delete, line 142 */
            lab3:
                ;
            }
            break;
    }
    return 1;
}

static int r_verb_suffix(struct SN_env * z) {
    int among_var;
    {   int m = z->l - z->c; /* setlimit, line 147 */
        int m3;
        if (z->c < z->I[0]) return 0;
        z->c = z->I[0]; /* tomark, line 147 */
        m3 = z->lb; z->lb = z->c;
        z->c = z->l - m;
        z->ket = z->c; /* [, line 148 */
        among_var = find_among_b(z, a_7, 87); /* substring, line 148 */
        if (!(among_var)) { z->lb = m3; return 0; }
        z->bra = z->c; /* ], line 148 */
        switch(among_var) {
            case 0: { z->lb = m3; return 0; }
            case 1:
                slice_del(z); /* delete, line 162 */
                break;
        }
        z->lb = m3;
    }
    return 1;
}

static int r_vowel_suffix(struct SN_env * z) {
    {   int m = z->l - z->c; /* try, line 170 */
        z->ket = z->c; /* [, line 171 */
        if (!(in_grouping_b(z, g_AEIO, 97, 242))) { z->c = z->l - m; goto lab0; }
        z->bra = z->c; /* ], line 171 */
        if (!r_RV(z)) { z->c = z->l - m; goto lab0; } /* call RV, line 171 */
        slice_del(z); /* delete, line 171 */
        z->ket = z->c; /* [, line 172 */
        if (!(eq_s_b(z, 1, s_20))) { z->c = z->l - m; goto lab0; }
        z->bra = z->c; /* ], line 172 */
        if (!r_RV(z)) { z->c = z->l - m; goto lab0; } /* call RV, line 172 */
        slice_del(z); /* delete, line 172 */
    lab0:
        ;
    }
    {   int m = z->l - z->c; /* try, line 174 */
        z->ket = z->c; /* [, line 175 */
        if (!(eq_s_b(z, 1, s_21))) { z->c = z->l - m; goto lab1; }
        z->bra = z->c; /* ], line 175 */
        if (!(in_grouping_b(z, g_CG, 99, 103))) { z->c = z->l - m; goto lab1; }
        if (!r_RV(z)) { z->c = z->l - m; goto lab1; } /* call RV, line 175 */
        slice_del(z); /* delete, line 175 */
    lab1:
        ;
    }
    return 1;
}

extern int italian_stem(struct SN_env * z) {
    {   int c = z->c; /* do, line 181 */
        if (!r_prelude(z)) goto lab0; /* call prelude, line 181 */
    lab0:
        z->c = c;
    }
    {   int c = z->c; /* do, line 182 */
        if (!r_mark_regions(z)) goto lab1; /* call mark_regions, line 182 */
    lab1:
        z->c = c;
    }
    z->lb = z->c; z->c = z->l; /* backwards, line 183 */

    {   int m = z->l - z->c; /* do, line 184 */
        if (!r_attached_pronoun(z)) goto lab2; /* call attached_pronoun, line 184 */
    lab2:
        z->c = z->l - m;
    }
    {   int m = z->l - z->c; /* do, line 185 */
        {   int m = z->l - z->c; /* or, line 185 */
            if (!r_standard_suffix(z)) goto lab5; /* call standard_suffix, line 185 */
            goto lab4;
        lab5:
            z->c = z->l - m;
            if (!r_verb_suffix(z)) goto lab3; /* call verb_suffix, line 185 */
        }
    lab4:
    lab3:
        z->c = z->l - m;
    }
    {   int m = z->l - z->c; /* do, line 186 */
        if (!r_vowel_suffix(z)) goto lab6; /* call vowel_suffix, line 186 */
    lab6:
        z->c = z->l - m;
    }
    z->c = z->lb;
    {   int c = z->c; /* do, line 188 */
        if (!r_postlude(z)) goto lab7; /* call postlude, line 188 */
    lab7:
        z->c = c;
    }
    return 1;
}

extern struct SN_env * italian_create_env(void) { return SN_create_env(0, 3, 0); }

extern void italian_close_env(struct SN_env * z) { SN_close_env(z); }

