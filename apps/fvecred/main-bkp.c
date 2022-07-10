/*=================================================================================================
Project Name:    Ara
Author:          Xiaorui Yin <yinx@student.ethz.ch>
Organization:    ETH Zürich
File Name:       main.c
Created On:      2022/05/19

Description:     

CopyRight Notice
All Rights Reserved
===================================================================================================
Modification    History:          
Date            By              Version         Change Description
---------------------------------------------------------------------------------------------------

=================================================================================================*/

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

//#include "runtime.h"
#include "printf.h"
#include "fvecred.h"

#define VL_S  32
#define VL_M  128
#define VL_L  256

// The length of a vector register is 4096bits
// Maximal LMUL is 8, the maximal VL is 4096 * 8 / EW
#define VL_MAX_16 2048 // EW16
#define VL_MAX_32 1024 // EW32
#define VL_MAX_64 512  // EW64

double rand_data[2048] = {-1474, -3288, -1392, -698, 3628, -3295, 1810, 323, 2239, -9, 975, 1046, 3877, -239, 230, -1871, -117, -2253, 2578, 1223, 3095, -77, 1507, 1036, -705, 809, 3667, -1563, -1300, -1479, -2583, -1101, 452, -2779, 805, 985, -3969, -451, -3319, -3880, 3513, -342, 2997, -835, -298, 3572, 2139, -157, 3209, -2057, -910, -1225, -1089, -2171, 2658, -1719, -1811, -686, -198, 2283, -3242, 2868, -3280, -2204, 3671, 294, -3380, 396, 3022, 3767, 584, -116, 3702, -3599, 1303, -2055, -3, -2332, 63, 108, -2864, 130, 1505, -1257, 2008, -382, -1754, -2144, 1788, 1156, -1390, 399, 1829, 3321, -558, 1834, -3772, -2897, -2247, 1886, -3016, 4035, 3280, -717, -670, 790, -1641, 3803, 3517, 628, -874, -2014, -2118, -1830, 1676, 975, 3926, -1109, 2966, -433, 1974, 1800, 3341, 1167, -571, 2531, 1563, 1022, 201, 2993, 1478, -1427, 3257, -1208, -2732, 3752, 3493, 3553, 145, -1321, -1520, 2128, -2567, 2942, 310, -1077, 1321, -393, -1657, 2340, -2441, 2462, -3653, -1032, 3296, -3444, -3204, 3740, -2854, -1526, 3762, -2430, -1527, 3795, -4037, -1609, -1013, -2549, -2673, 2323, 3151, -801, 1830, 3868, 3661, -3411, 523, 3847, 1906, 1115, 730, -178, 1519, -545, -1972, 2943, 3363, -965, -775, -762, -934, 1342, -3320, -3950, -1218, 2817, -3569, 3359, 2794, 853, -2204, 3463, 1558, 1214, -3855, -4048, 451, -921, -1741, 412, -937, 2598, 3800, 2901, 3745, -393, -2884, -1314, -2328, 1597, 3744, -3608, 4000, -725, 4000, -3078, -3364, -21, -3155, 3707, -2227, 2970, 142, -974, -1327, -874, 3964, -110, -3501, 1876, 2167, -1991, -1870, 3278, 591, 2228, 3885, -3349, -351, 2029, -3940, -2044, -1777, 3943, -4052, 712, 3135, -1755, 2, 2948, -3271, -827, 1038, -398, 3990, -2469, -4084, -3374, -3870, -3129, -2116, 2689, -1727, 3324, -1272, -2482, 725, 2016, -1671, -1328, -859, 1411, -2793, 3713, 1447, -2515, 3087, -1102, -3429, 3101, -1747, 1577, 2927, 2665, -4006, 2189, -48, -1685, -102, 2766, 2950, -268, 948, 1215, 2440, -3363, 802, 3076, -368, 3406, 2385, -2314, 3278, -1497, -3837, -850, 1273, 623, 2112, -3670, -1095, 487, -3704, 2273, -3418, 3304, 1658, -114, -3355, -1941, -2500, 1520, -2328, 3211, 2182, -760, -1277, 773, 2941, -2219, -4024, -1629, -846, 2169, -85, -1717, -2812, 1433, -3189, -2202, -3068, 1175, 4074, -3385, 3955, -2775, -3717, 3432, 950, 677, -3035, 10, -2905, 409, -533, 3554, -1616, -3326, 1545, -616, 1715, -116, -2181, 306, 1936, -4007, -972, -2463, -2187, -3652, -1690, 2091, -970, -1797, -515, -3325, 4010, -3940, -2765, 957, 1407, -444, -2131, -4070, 2078, 2617, 1246, 3232, 3733, 245, 3658, -3570, 2142, -2066, -3169, 213, -1296, 1763, -469, -3167, 2398, -326, -3875, 100, 2393, 898, -254, -516, 1498, -2782, -708, 198, -243, 583, 3462, 2537, -628, 104, 3032, 3196, -1561, -1374, -3262, 1508, -3140, -2637, 1022, 3975, -2873, -3839, -2579, -3390, -1897, 981, -2664, 1900, -2386, -3504, 3149, -1530, 3208, 3998, 442, -1035, 2602, 1195, -3568, 821, 969, 3531, -822, 3727, -2499, 2425, 3287, 231, 3695, 4093, 258, -1336, 302, -2532, 3805, 1198, -1807, 3599, -1888, 3399, -31, -2779, 3640, 3818, 3194, 3254, -2184, -179, -894, -543, 2604, -563, 2553, -4085, -451, 1828, -1707, -1303, 885, -1375, 2410, 2893, -1769, 4037, 2796, -277, -810, -3779, 2887, 311, -1491, 2995, 917, 483, 3809, 3366, 3972, 196, 2191, -3394, 2212, -27, 31, -443, 1567, 2309, -770, -1827, -3428, -3295, -2044, -2403, -59, 2530, 3851, -2401, 474, -3562, -1723, 1948, 1780, -1325, 2463, 1877, -24, 833, -2130, -950, 390, 312, -3304, -4061, 839, 3923, 1073, 3275, 2845, 1840, 153, 1286, -991, -2245, -2862, 1365, 2534, 3558, -895, -2466, -425, -1500, 3717, -825, -3229, -426, -3048, -3383, 3401, -1131, 2333, -18, -3581, -462, -413, 246, 3595, -2379, -3390, -2006, 3437, 1231, 2155, -3797, -104, -3080, -1245, 631, 111, -482, 3493, 1036, -3412, 1739, -1765, 4062, 2420, -1144, -961, -2489, -3853, 2948, 3491, -3943, -595, -1198, -2618, 2099, -387, -1768, -369, 875, 219, 3998, -560, -2033, 478, 2743, -4052, 3925, -3493, -80, -2527, -2444, 2757, -708, -1629, -1241, 3040, 2295, 1707, -1954, 1986, 3762, -3164, -650, -2710, 2944, -1009, -3105, -2677, -565, 3772, 180, 878, 6, 3142, -3075, -93, -1577, 1344, -763, 1655, -2519, -1631, 9, 443, 3691, -1981, -704, -2069, 3273, -3905, 3669, 2712, 1467, -4037, 1609, -3256, 4091, -2591, -1012, -4037, 2443, -4011, 1328, -2482, 751, 3472, -2836, 2514, -2242, 2960, -1010, 903, -161, -3042, -4096, -2685, 2600, 1010, 2292, -211, 3648, 3570, 3359, 3373, -2259, -3785, -3957, 1376, 670, 2516, 2965, -3674, -4040, 2459, 1665, -3948, -1111, 2064, -2449, 1665, -2699, 3126, -3425, 1924, -1860, -3183, -3511, -3560, 112, 1273, 949, -1743, 1955, 3963, 442, 312, -118, 513, 3829, -3680, -2040, -2833, -3060, 928, -2337, -2087, 1149, 3170, -2240, 3933, -3204, 1032, -445, -844, -1281, 3384, 3270, -927, 2703, -703, 3438, -3617, -2689, 2254, -3866, -1474, 1569, 1039, 956, 3185, 1717, -3468, 2850, 778, 2376, 2784, -2052, 1560, 678, 12, -2678, 2260, 165, 332, -943, 3355, -3612, -487, -1897, -2738, -3817, -865, 3959, 3796, 3499, 960, -3372, -1497, -1415, 966, 2926, 1221, 2040, 88, -376, -1576, 3970, 1154, -3191, 639, 3303, -3197, 2864, -3013, -1553, 2020, 617, -3612, 3498, 1062, -3982, -2010, 1137, -289, 3059, -126, 3721, 309, -3475, 2936, 825, 1420, -3573, 814, 459, -2144, 1111, -3800, 364, -3842, 407, -1845, 1142, 1022, 3826, 2340, 280, 3011, -3049, -2775, -1905, -1166, 1048, 3256, 2044, -1108, -571, 1710, -555, 4062, -2206, -2616, 2311, -1762, 1931, 3967, -3983, 3472, 3959, -3272, -390, -415, 1805, 1890, 1350, -123, 2009, 1690, -1860, -3354, -2807, -3348, 1562, -1798, 1993, 2099, -1402, 1575, -2051, 294, -3977, 3721, 3090, -3611, 2938, -3441, -2285, -3563, -538, -2999, 3, -2703, 3386, 168, -223, 3210, -644, 481, -608, 3967, 139, -3209, -2166, -2841, 25, 1540, -862, -2416, -2687, 212, -2625, -2034, -2637, -4092, 1416, -1180, -1065, -1835, 791, 2795, -2508, 1786, -1584, 845, -1175, 2709, -3936, 469, 3776, 1428, 2130, 2468, -3402, -847, -1075, 4053, -1363, 2787, -2036, -3004, -2443, 3215, -2779, 92, -1801, -751, 2211, 3539, 3471, -2003, 3391, -2139, 897, 3290, -778, -3498, 719, 2715, -1812, -3838, -3569, -3943, 3146, -3904, 115, 1342, -2811, -2830, -2505, 1700, 544, -2329, 3400, 2754, 1125, 1677, 4050, 3648, -2253, -3326, -1326, 3188, -627, 2922, -226, -3076, -1720, -1833, 1375, -3137, -3456, -2925, -2337, -49, 3214, -727, -2873, -497, -1313, -3288, -1674, -3933, 1652, 3410, 3734, 628, 1329, 2600, 2661, 3737, -1438, 956, 780, 3216, 434, -2195, -1078, 925, -901, 2411, 129, -3876, -1001, -2365, -2041, 1544, -1529, 2987, -3332, -865, 567, 1370, -3772, -1231, 200, -3939, 1933, 788, -2955, -1395, -2631, -3146, -1864, -25, -1265, -3482, 2281, -3473, -3640, -995, -291, -1785, -2882, 2876, 1319, 774, -4050, 786, 3821, -1067, 1154, 743, -2500, 378, 2070, -2075, -3552, -1152, -2533, -705, 1432, -289, -3183, -1322, 2409, 3952, -2468, -3880, -1261, -3207, 111, 347, 1518, -2087, -2092, -207, -2679, -28, 3484, 2151, -2747, 3441, 2294, 2166, -167, -3336, -1004, 2249, 2114, 1626, 3451, -1783, 2047, -3724, 1661, -3175, -2337, 3352, -3574, -322, 593, 2844, 3220, -2167, 19, -1837, 699, 3204, 3740, -3534, 600, -2103, -2137, 1434, 3627, 1005, -986, -3127, 287, 658, -3980, -2086, -460, 517, -841, 3145, 2834, 7, -329, -1601, 3883, 1558, -2512, -138, 2835, -3926, -2843, -2314, -1607, -2702, -793, 1585, 978, -933, 288, 3563, -3749, -2842, 686, 3671, -293, 3435, 1894, -3566, 3372, 1295, 2906, 310, -3991, 1247, 2483, -1741, 979, -1046, 1858, 1325, 1017, 878, 2014, 3192, -2325, -1624, 1554, -22, -2635, 357, -2346, 2282, -1136, 1013, -2115, -2750, 3536, -4051, 3686, 2053, -2910, -2977, -2900, 4084, 2799, 122, -72, 3179, 1319, 122, 1612, -2486, 1260, -3390, -4084, 3919, -3355, 3765, -1770, 1350, -887, 2162, 2691, -1496, 1759, -1370, -2955, -429, -808, 2554, 1840, 1830, -145, 567, 3976, -2200, 2791, 3521, 4062, 4080, 947, 1552, -3205, -792, 1237, -3792, -1793, 1284, -3451, 1443, -2879, -1916, -3424, 1702, -2920, 71, 3533, -3685, -1821, 1237, 3256, 65, -3944, 1779, 2261, -2572, -508, 2243, -960, 829, -310, -3360, -1431, 743, 4012, 805, 1166, -1178, -2297, 2136, 3951, 3112, 2233, 2516, 2775, -3399, 440, -416, 2851, 2354, 1330, 164, 3493, 1477, -2652, -2595, 1495, -4035, -43, -3745, 124, -402, -908, 1034, -1867, -1674, 3195, 2273, 1181, -1045, -2104, -1237, 3011, 3229, 3890, -2890, 814, 2816, 479, -66, 2266, -905, -1679, 3602, -1376, -3947, 1969, 2161, 666, 53, 1422, -3942, -2391, -1644, -1637, 2432, -2709, -3340, 3080, -605, -1698, 455, -2820, -1852, -671, 1864, 1354, -2002, -3939, 346, -644, 917, 2456, 3739, 459, -3709, 1600, 1942, 1909, -3845, -3793, -1935, 856, -2810, -3756, -3006, 194, 2451, -1364, 1906, 243, 739, -420, 750, 2999, -1154, -3346, -1316, -1860, -176, -3031, -266, -488, 3502, -891, 2080, -3922, -599, 3130, -2858, -757, 3406, -3346, -230, 3310, -3240, -315, -1428, -3086, 2590, -1671, -1145, -2871, -1337, 3602, -2963, -1587, -410, 3651, 134, 1455, 3252, -1266, -2492, 1648, 48, -3175, 2110, -3372, 2918, 1138, 3974, -2212, 345, -3822, 99, -3516, 1720, 3007, -1766, -1761, 452, -2962, -680, 1401, -610, 3124, -448, 3046, -3283, 1579, -2166, -3597, 2491, 231, -3265, -1903, 3379, 233, 4003, -3424, -2479, -102, 1811, 3705, 390, 1747, -2106, 1858, 268, -491, -3083, 1588, 1539, 1610, 1562, -3456, -2677, 202, 1304, -4050, 163, -911, -3239, 568, 255, 1186, -454, -776, -456, -3109, 397, 3448, 947, 2984, -1012, 1696, 3284, -849, -897, -2664, -3616, -52, 2013, 2236, -2527, 3432, 116, -3823, 3750, 1211, 3997, 619, 3089, -2045, 1005, -3820, -579, 2817, -327, 3184, 498, -397, 3377, 2733, -464, -931, -2721, 1970, -1073, -1871, -1964, -511, -1301, 409, 3694, 1562, 3873, 2676, -42, -1759, 3953, 3872, 1047, -2519, -2195, -3505, -187, 2684, 3471, -976, 2316, 3026, -2934, 717, 1373, -1597, -2452, 2156, 2118, 3559, 3593, -1690, -3048, -1724, 3425, -1772, 938, 438, -2538, -319, -1038, 61, -2528, -3250, -204, 2662, -2774, 1462, -263, 3077, -1963, -2586, -948, -2059, 1182, 4073, 2937, -199, -891, 3730, 2865, 1646, -850, -2782, 2968, 2538, 627, -2839, -2937, 3844, -1023, 2703, -3770, 903, -1226, -1447, 2186, -1245, -98, -3179, 1443, 2081, 1926, -869, 3303, -970, 2301, -2617, 122, -3939, 646, -375, -2605, -2281, 2830, 1298, 3463, -2738, 2590, -3693, 1318, -2380, -1506, -4080, -2512, 2163, 2655, 2968, -2731, -3578, -3782, -932, -579, 3210, -2743, -3294, -2290, 1661, 3408, -2347, 4066, 1246, -2456, 2958, 2877, 514, -259, -78, 1952, 408, 581, -2177, 3346, 2001, 324, 4095, 3631, -4077, 2799, -2387, 2364, 1350, -229, -190, -3861, 302, 553, 2221, -1462, 860, -1278, 497, 295, -2765, -3309, 3880, 3816, -2371, 2432, -1247, -1630, 3550, -3841, 868, 2528, 1736, -3575, 1016, -595, 4052, 2704, -1572, 3052, -3815, -2735, -475, 3233, -1142, 3966, 3542, -1260, 220, -3636, -1425, 1789, 1602, -2116, -1067, 788, -315, -800, -520, 3350, -1243, 577, 150, -2801, 3084, -456, 1519, 3432, -2391, -3306, -3544, -3016, 2503, -3840, -3548, -229, 3998, 2406, 322, 1346, -342, -1411, -1542, 1867, -2559, -2711, 802, 3861, 3273, -1293, 2487, 1870, -1503, -1851, -3855, 2239, -53, -2799, -3423, -3282, -1808, -2947, -1329, 3673, 151, -3466, 1570, 2946, 2431, 2040, 2879, 2699, 3287, -938, 428, -1150, 3851, 752, -2200, -1861, -611, 1330, 1824, -671, -1734, 1879, 2372, -3997, 686, -1374, -2651, 730, -3678, -2444, -1074, -779, -810, -1174, 441, -2459, 3852, 3290, 1992, 2741, -3202, 376, -2427, -2262, -3570, 3698, -3987, -1474, -2234, 3327, 2714, -1803, 380, 3580, 2491, 9, 1166, -1874, -3269, 3604, -1100, -977, 1064, -303, 1867, 3512, 1761, -3705, 1805, -4018, -3703, 688, 3193, -672, 353, -943, 2015, -2588, -3118, -2107, 3434, -426, 923, -2405, -605, -1874, -2009, 1147, -1482, -3876, -3800, -1373, -2322, 2871, 2920, -2567, -3182, -1645, -1012, 4063, 1328, -3718, 3340, -3958, 2485, -315, 2182, 1643, 3732, -3511, -2961, -2562, -3262, -3392, -3008, 3005, -439, -3666, 2643, 2548, 3344, 3416, -398, 1518, 3483, 1676, -3391, -3701, -3305, -2876, 2090, -4009, -1528, -1074, 3405, -2136, -2539, 2515, 2073, 3219, 1958, -3862, -240, -2503, -2121, 260, -2939, -996, 1838, 1166, 3452, 2365, 3780, -1309, -3565, -3249, -2932, -2516, -1281, -827, -1546, -3879, -2682, -3719, -1574, 1039, 2519, 502, 426, 540, 3870, -1186, -2798, 3268, 793, -2098, 2908, -1746, 1984, -282, 166, 2116, 916, 1246, 579, -2320, -442, -2761, -1426, -2046, 2954, 2962, -2057, -392, -620, -4095, 2572, -598, -1289, -2229, 1204, -2778, -757, -1768, -2425, -1035, -1471, 3340, -3363, 3729, -3568, 314, -2902, -1663, 3826, 1063, 1482, -1028, 2007, 3697, -828, 1220, 491, -3492, -2956, -2042, 527, -2269, 2911, 3184, -339, 2139, -3306, -3910, -1437, 2829, -3714, 3935, 3753, 4000, -2336, -1980, 1641, -3916, -618, 1742, -3274, 92, 2229, -568, 661, -660, -715, 3199, -3815, -1612, -1112, -247, 4074, -1508, -1939, -76, -3392, 1318, 3869, -1724, -975, -789, -3630, -3904, -2178, -2660, 515, -1203, 1572, 1292, 2287, -757, -1338, 2231, -484, 922, 3988, -755, 896};

void gen_rand_vec_64(double *vec, uint16_t vl) {
  for (uint16_t i = 0; i < vl; i++) {
    vec[i] = rand_data[i];
  }
}

void gen_rand_vec_32(float *vec, uint16_t vl) {
  for (uint16_t i = 0; i < vl; i++) {
    vec[i] = (float)rand_data[i];
  }
}

void gen_rand_vec_16(uint16_t *vec, uint16_t vl) {
  for (uint16_t i = 0; i < vl; i++) {
    vec[i] = (uint16_t)rand_data[i];
  }
}

void verify_result_64(double *vec, double scalar, uint16_t vl, double res) {
  double sum = scalar;
  printf("Verifying Result\n");
  for (uint16_t i = 0; i < vl; i++)
    sum += vec[i];
  if (sum == res) {
    printf("PASS\n");
  } else {
    printf("FAIL\n");
    printf("ACT = %f, EXP = %f\n", res, sum);
  }
  printf("\n");
}

void verify_result_32(float *vec, float scalar, uint16_t vl, float res) {
  float sum = scalar;
  printf("Verifying Result\n");
  for (uint16_t i = 0; i < vl; i++)
    sum += vec[i];
  if (sum == res) {
    printf("PASS\n");
  } else {
    printf("FAIL\n");
    printf("ACT = %f, EXP = %f\n", res, sum);
  }
  printf("\n");
}
 
//void verify_result_16(uint16_t *vec, uint16_t scalar, uint16_t vl, uint16_t res) {
//  uint16_t sum = scalar;
//  printf("Verifying Result\n");
//  for (uint16_t i = 0; i < vl; i++)
//    sum += vec[i];
//  if (sum == res) {
//    printf("PASS\n");
//  } else {
//    printf("FAIL\n");
//    printf("ACT = %f, EXP = %f\n", res, sum);
//  }
//  printf("\n");
//}

void vfredusum_16() {
  printf("\n");
  printf("======================\n");
  printf("vfredsum EW16\n");
  printf("======================\n");
  printf("\n");
  printf("\n");

  uint16_t vec1[VL_S], res1[VL_S];
  uint16_t vec2[VL_M], res2[VL_M];
  uint16_t vec3[VL_L], res3[VL_L];
  uint16_t vec4[VL_MAX_64], res4[VL_MAX_64];
  uint16_t vec5[VL_MAX_32], res5[VL_MAX_32];
  uint16_t vec6[VL_MAX_16], res6[VL_MAX_16];
  gen_rand_vec_16(vec1, VL_S);
  gen_rand_vec_16(vec2, VL_M);
  gen_rand_vec_16(vec3, VL_L);
  gen_rand_vec_16(vec4, VL_MAX_64);
  gen_rand_vec_16(vec5, VL_MAX_32);
  gen_rand_vec_16(vec6, VL_MAX_16);

  printf("======================\n");
  printf("VL=32\n");
  printf("======================\n");
  VSET(VL_S, e16, m1);
  asm volatile("vle16.v v0, (%0);" ::"r"(vec1));
  asm volatile("vle16.v v1, (%0);" ::"r"(vec1));
  asm volatile("vfredsum.vs v2, v0, v1");
  asm volatile("vse16.v v2, (%0);" ::"r"(res1));
  //verify_result_32(vec1, vec1[0], VL_S, res1[0]);
  printf("\n");
  printf("\n");

  printf("======================\n");
  printf("VL=128\n");
  printf("======================\n");
  VSET(VL_M, e16, m1);
  asm volatile("vle16.v v0, (%0);" ::"r"(vec2));
  asm volatile("vle16.v v1, (%0);" ::"r"(vec2));
  asm volatile("vfredsum.vs v2, v0, v1");
  asm volatile("vse16.v v2, (%0);" ::"r"(res2));
  //verify_result_32(vec2, vec2[0], VL_M, res2[0]);
  printf("\n");
  printf("\n");
  
  printf("======================\n");
  printf("VL=256\n");
  printf("======================\n");
  VSET(VL_L, e16, m1);
  asm volatile("vle16.v v4, (%0);" ::"r"(vec3));
  asm volatile("vle16.v v6, (%0);" ::"r"(vec3));
  asm volatile("vfredsum.vs v2, v4, v6");
  asm volatile("vse16.v v2, (%0);" ::"r"(res3));
  //verify_result_32(vec3, vec3[0], VL_L, res3[0]);
  printf("\n");
  printf("\n");

  printf("======================\n");
  printf("VL=512\n");
  printf("======================\n");
  VSET(VL_MAX_64, e16, m2);
  asm volatile("vle16.v v0, (%0);" ::"r"(vec4));
  asm volatile("vle16.v v8, (%0);" ::"r"(vec4));
  asm volatile("vfredsum.vs v16, v0, v8");
  asm volatile("vse16.v v16, (%0);" ::"r"(res4));
  //verify_result_32(vec4, vec4[0], VL_MAX_32, res4[0]);
  printf("\n");
  printf("\n");
  
  printf("======================\n");
  printf("VL=1024\n");
  printf("======================\n");
  VSET(VL_MAX_32, e16, m4);
  asm volatile("vle16.v v0, (%0);" ::"r"(vec5));
  asm volatile("vle16.v v8, (%0);" ::"r"(vec5));
  asm volatile("vfredsum.vs v16, v0, v8");
  asm volatile("vse16.v v16, (%0);" ::"r"(res5));
  //verify_result_32(vec4, vec4[0], VL_MAX_32, res4[0]);
  printf("\n");
  printf("\n");

  printf("======================\n");
  printf("VL=2048\n");
  printf("======================\n");
  VSET(VL_MAX_16, e16, m8);
  asm volatile("vle16.v v0, (%0);" ::"r"(vec6));
  asm volatile("vle16.v v8, (%0);" ::"r"(vec6));
  asm volatile("vfredsum.vs v16, v0, v8");
  asm volatile("vse16.v v16, (%0);" ::"r"(res6));
  //verify_result_32(vec4, vec4[0], VL_MAX_32, res4[0]);
  printf("\n");
  printf("\n");

  //Issue a redundant vector add instruction to eliminate 
  //the effect of stalls due to data denpendencies
  printf("======================\n");
  printf("VL=32 PRELOADED\n");
  printf("======================\n");
  VSET(VL_S, e16, m1);
  asm volatile("vle16.v v0, (%0);" ::"r"(vec1));
  asm volatile("vle16.v v1, (%0);" ::"r"(vec1));
  gen_rand_vec_16(vec6, VL_MAX_16);
  //asm volatile("vfadd.vv v2, v0, v1");
  asm volatile("vfredsum.vs v2, v0, v1");
  asm volatile("vse16.v v2, (%0);" ::"r"(res1));
  //verify_result_32(vec1, vec1[0], VL_S, res1[0]);
  printf("\n");
  printf("\n");

  printf("======================\n");
  printf("VL=128 PRELOADED\n");
  printf("======================\n");
  VSET(VL_M, e16, m1);
  asm volatile("vle16.v v0, (%0);" ::"r"(vec2));
  asm volatile("vle16.v v1, (%0);" ::"r"(vec2));
  //asm volatile("vfadd.vv v2, v0, v1");
  gen_rand_vec_16(vec6, VL_MAX_16);
  asm volatile("vfredsum.vs v2, v0, v1");
  asm volatile("vse16.v v2, (%0);" ::"r"(res2));
  //verify_result_32(vec2, vec2[0], VL_M, res2[0]);
  printf("\n");
  printf("\n");
  
  printf("======================\n");
  printf("VL=256 PRELOADED\n");
  printf("======================\n");
  VSET(VL_L, e16, m1);
  asm volatile("vle16.v v4, (%0);" ::"r"(vec3));
  asm volatile("vle16.v v6, (%0);" ::"r"(vec3));
  //asm volatile("vfadd.vv v2, v4, v6");
  gen_rand_vec_16(vec6, VL_MAX_16);
  asm volatile("vfredsum.vs v2, v4, v6");
  asm volatile("vse16.v v2, (%0);" ::"r"(res3));
  //verify_result_32(vec3, vec3[0], VL_L, res3[0]);
  printf("\n");
  printf("\n");

  printf("======================\n");
  printf("VL=512 PRELOADED\n");
  printf("======================\n");
  VSET(VL_MAX_64, e16, m2);
  asm volatile("vle16.v v4, (%0);" ::"r"(vec4));
  asm volatile("vle16.v v6, (%0);" ::"r"(vec4));
  //asm volatile("vfadd.vv v2, v4, v6");
  gen_rand_vec_16(vec6, VL_MAX_16);
  asm volatile("vfredsum.vs v2, v4, v6");
  asm volatile("vse16.v v2, (%0);" ::"r"(res4));
  //verify_result_32(vec3, vec3[0], VL_L, res3[0]);
  printf("\n");
  printf("\n");

  printf("======================\n");
  printf("VL=1024 PRELOADED\n");
  printf("======================\n");
  VSET(VL_MAX_32, e16, m4);
  asm volatile("vle16.v v0, (%0);" ::"r"(vec5));
  asm volatile("vle16.v v8, (%0);" ::"r"(vec5));
  //asm volatile("vfadd.vv v16, v0, v8");
  gen_rand_vec_16(vec6, VL_MAX_16);
  asm volatile("vfredsum.vs v16, v0, v8");
  asm volatile("vse16.v v16, (%0);" ::"r"(res5));
  //verify_result_32(vec4, vec4[0], VL_MAX_32, res4[0]);
  printf("\n");
  printf("\n");

  printf("======================\n");
  printf("VL=2048 PRELOADED\n");
  printf("======================\n");
  VSET(VL_MAX_16, e16, m8);
  asm volatile("vle16.v v0, (%0);" ::"r"(vec6));
  asm volatile("vle16.v v8, (%0);" ::"r"(vec6));
  //asm volatile("vfadd.vv v16, v0, v8");
  gen_rand_vec_16(vec6, VL_MAX_16);
  asm volatile("vfredsum.vs v16, v0, v8");
  asm volatile("vse16.v v16, (%0);" ::"r"(res6));
  //verify_result_32(vec4, vec4[0], VL_MAX_32, res4[0]);
  printf("\n");
  printf("\n");
}

void vfredosum_16() {
  printf("\n");
  printf("======================\n");
  printf("VFREDOSUM EW16\n");
  printf("======================\n");
  printf("\n");
  printf("\n");

  uint16_t vec1[VL_S], res1[VL_S];
  uint16_t vec2[VL_M], res2[VL_M];
  uint16_t vec3[VL_L], res3[VL_L];
  uint16_t vec4[VL_MAX_64], res4[VL_MAX_64];
  uint16_t vec5[VL_MAX_32], res5[VL_MAX_32];
  uint16_t vec6[VL_MAX_16], res6[VL_MAX_16];
  gen_rand_vec_16(vec1, VL_S);
  gen_rand_vec_16(vec2, VL_M);
  gen_rand_vec_16(vec3, VL_L);
  gen_rand_vec_16(vec4, VL_MAX_64);
  gen_rand_vec_16(vec5, VL_MAX_32);
  gen_rand_vec_16(vec6, VL_MAX_16);
  
  // Issue a redundant vector add instruction to eliminate 
  // the effect of stalls due to data denpendencies
  printf("======================\n");
  printf("VL=32 PRELOADED\n");
  printf("======================\n");
  VSET(VL_S, e16, m1);
  asm volatile("vle16.v v0, (%0);" ::"r"(vec1));
  asm volatile("vle16.v v1, (%0);" ::"r"(vec1));
  asm volatile("vfadd.vv v2, v0, v1");
  asm volatile("vfredosum.vs v2, v0, v1");
  asm volatile("vse16.v v2, (%0);" ::"r"(res1));
  //verify_result_32(vec1, vec1[0], VL_S, res1[0]);
  printf("\n");
  printf("\n");

  printf("======================\n");
  printf("VL=128 PRELOADED\n");
  printf("======================\n");
  VSET(VL_M, e16, m1);
  asm volatile("vle16.v v0, (%0);" ::"r"(vec2));
  asm volatile("vle16.v v1, (%0);" ::"r"(vec2));
  asm volatile("vfadd.vv v2, v0, v1");
  asm volatile("vfredosum.vs v2, v0, v1");
  asm volatile("vse16.v v2, (%0);" ::"r"(res2));
  //verify_result_32(vec2, vec2[0], VL_M, res2[0]);
  printf("\n");
  printf("\n");
  
  printf("======================\n");
  printf("VL=256 PRELOADED\n");
  printf("======================\n");
  VSET(VL_L, e16, m1);
  asm volatile("vle16.v v4, (%0);" ::"r"(vec3));
  asm volatile("vle16.v v6, (%0);" ::"r"(vec3));
  asm volatile("vfadd.vv v2, v4, v6");
  asm volatile("vfredosum.vs v2, v4, v6");
  asm volatile("vse16.v v2, (%0);" ::"r"(res3));
  //verify_result_32(vec3, vec3[0], VL_L, res3[0]);
  printf("\n");
  printf("\n");

  printf("======================\n");
  printf("VL=512 PRELOADED\n");
  printf("======================\n");
  VSET(VL_MAX_64, e16, m2);
  asm volatile("vle16.v v4, (%0);" ::"r"(vec4));
  asm volatile("vle16.v v6, (%0);" ::"r"(vec4));
  asm volatile("vfadd.vv v2, v4, v6");
  asm volatile("vfredosum.vs v2, v4, v6");
  asm volatile("vse16.v v2, (%0);" ::"r"(res4));
  //verify_result_32(vec3, vec3[0], VL_L, res3[0]);
  printf("\n");
  printf("\n");
  
  printf("======================\n");
  printf("VL=1024 PRELOADED\n");
  printf("======================\n");
  VSET(VL_MAX_32, e16, m4);
  asm volatile("vle16.v v0, (%0);" ::"r"(vec5));
  asm volatile("vle16.v v8, (%0);" ::"r"(vec5));
  asm volatile("vfadd.vv v16, v0, v8");
  asm volatile("vfredosum.vs v16, v0, v8");
  asm volatile("vse16.v v16, (%0);" ::"r"(res5));
  //verify_result_32(vec4, vec4[0], VL_MAX_32, res4[0]);
  printf("\n");
  printf("\n");

  printf("======================\n");
  printf("VL=2048 PRELOADED\n");
  printf("======================\n");
  VSET(VL_MAX_16, e16, m8);
  asm volatile("vle16.v v0, (%0);" ::"r"(vec6));
  asm volatile("vle16.v v8, (%0);" ::"r"(vec6));
  asm volatile("vfadd.vv v16, v0, v8");
  asm volatile("vfredosum.vs v16, v0, v8");
  asm volatile("vse16.v v16, (%0);" ::"r"(res6));
  //verify_result_32(vec3, vec3[0], VL_L, res3[0]);
  printf("\n");
  printf("\n");
}

void vfredusum_32() {
  printf("\n");
  printf("======================\n");
  printf("vfredsum EW32\n");
  printf("======================\n");
  printf("\n");
  printf("\n");

  float vec1[VL_S], res1[VL_S];
  float vec2[VL_M], res2[VL_M];
  float vec3[VL_L], res3[VL_L];
  float vec4[VL_MAX_32], res4[VL_MAX_32];
  gen_rand_vec_32(vec1, VL_S);
  gen_rand_vec_32(vec2, VL_M);
  gen_rand_vec_32(vec3, VL_L);
  gen_rand_vec_32(vec4, VL_MAX_32);

  printf("======================\n");
  printf("VL=32\n");
  printf("======================\n");
  VSET(VL_S, e32, m1);
  asm volatile("vle32.v v0, (%0);" ::"r"(vec1));
  asm volatile("vle32.v v1, (%0);" ::"r"(vec1));
  asm volatile("vfredsum.vs v2, v0, v1");
  asm volatile("vse32.v v2, (%0);" ::"r"(res1));
  verify_result_32(vec1, vec1[0], VL_S, res1[0]);
  printf("\n");
  printf("\n");

  printf("======================\n");
  printf("VL=128\n");
  printf("======================\n");
  VSET(VL_M, e32, m1);
  asm volatile("vle32.v v0, (%0);" ::"r"(vec2));
  asm volatile("vle32.v v1, (%0);" ::"r"(vec2));
  asm volatile("vfredsum.vs v2, v0, v1");
  asm volatile("vse32.v v2, (%0);" ::"r"(res2));
  verify_result_32(vec2, vec2[0], VL_M, res2[0]);
  printf("\n");
  printf("\n");
  
  printf("======================\n");
  printf("VL=256\n");
  printf("======================\n");
  VSET(VL_L, e32, m2);
  asm volatile("vle32.v v4, (%0);" ::"r"(vec3));
  asm volatile("vle32.v v6, (%0);" ::"r"(vec3));
  asm volatile("vfredsum.vs v2, v4, v6");
  asm volatile("vse32.v v2, (%0);" ::"r"(res3));
  verify_result_32(vec3, vec3[0], VL_L, res3[0]);
  printf("\n");
  printf("\n");

  printf("======================\n");
  printf("VL=1024\n");
  printf("======================\n");
  VSET(VL_MAX_32, e32, m8);
  asm volatile("vle32.v v0, (%0);" ::"r"(vec4));
  asm volatile("vle32.v v8, (%0);" ::"r"(vec4));
  asm volatile("vfredsum.vs v16, v0, v8");
  asm volatile("vse32.v v16, (%0);" ::"r"(res4));
  verify_result_32(vec4, vec4[0], VL_MAX_32, res4[0]);
  printf("\n");
  printf("\n");
  
  // Issue a redundant vector add instruction to eliminate 
  // the effect of stalls due to data denpendencies
  printf("======================\n");
  printf("VL=32 PRELOADED\n");
  printf("======================\n");
  VSET(VL_S, e32, m1);
  asm volatile("vle32.v v0, (%0);" ::"r"(vec1));
  asm volatile("vle32.v v1, (%0);" ::"r"(vec1));
  asm volatile("vfadd.vv v2, v0, v1");
  asm volatile("vfredsum.vs v2, v0, v1");
  asm volatile("vse32.v v2, (%0);" ::"r"(res1));
  verify_result_32(vec1, vec1[0], VL_S, res1[0]);
  printf("\n");
  printf("\n");

  printf("======================\n");
  printf("VL=128 PRELOADED\n");
  printf("======================\n");
  VSET(VL_M, e32, m1);
  asm volatile("vle32.v v0, (%0);" ::"r"(vec2));
  asm volatile("vle32.v v1, (%0);" ::"r"(vec2));
  asm volatile("vfadd.vv v2, v0, v1");
  asm volatile("vfredsum.vs v2, v0, v1");
  asm volatile("vse32.v v2, (%0);" ::"r"(res2));
  verify_result_32(vec2, vec2[0], VL_M, res2[0]);
  printf("\n");
  printf("\n");
  
  printf("======================\n");
  printf("VL=256 PRELOADED\n");
  printf("======================\n");
  VSET(VL_L, e32, m2);
  asm volatile("vle32.v v4, (%0);" ::"r"(vec3));
  asm volatile("vle32.v v6, (%0);" ::"r"(vec3));
  asm volatile("vfadd.vv v2, v4, v6");
  asm volatile("vfredsum.vs v2, v4, v6");
  asm volatile("vse32.v v2, (%0);" ::"r"(res3));
  verify_result_32(vec3, vec3[0], VL_L, res3[0]);
  printf("\n");
  printf("\n");

  printf("======================\n");
  printf("VL=1024 PRELOADED\n");
  printf("======================\n");
  VSET(VL_MAX_32, e32, m8);
  asm volatile("vle32.v v0, (%0);" ::"r"(vec4));
  asm volatile("vle32.v v8, (%0);" ::"r"(vec4));
  asm volatile("vfadd.vv v16, v0, v8");
  asm volatile("vfredsum.vs v16, v0, v8");
  asm volatile("vse32.v v16, (%0);" ::"r"(res4));
  verify_result_32(vec4, vec4[0], VL_MAX_32, res4[0]);
  printf("\n");
  printf("\n");
}

void vfredosum_32() {
  printf("\n");
  printf("======================\n");
  printf("VFREDOSUM EW32\n");
  printf("======================\n");
  printf("\n");
  printf("\n");

  float vec1[VL_S], res1[VL_S];
  float vec2[VL_M], res2[VL_M];
  float vec3[VL_L], res3[VL_L];
  float vec4[VL_MAX_32], res4[VL_MAX_32];
  gen_rand_vec_32(vec1, VL_S);
  gen_rand_vec_32(vec2, VL_M);
  gen_rand_vec_32(vec3, VL_L);
  gen_rand_vec_32(vec4, VL_MAX_32);

  printf("======================\n");
  printf("VL=32\n");
  printf("======================\n");
  VSET(VL_S, e32, m1);
  asm volatile("vle32.v v0, (%0);" ::"r"(vec1));
  asm volatile("vle32.v v1, (%0);" ::"r"(vec1));
  asm volatile("vfredosum.vs v2, v0, v1");
  asm volatile("vse32.v v2, (%0);" ::"r"(res1));
  verify_result_32(vec1, vec1[0], VL_S, res1[0]);
  printf("\n");
  printf("\n");

  printf("======================\n");
  printf("VL=128\n");
  printf("======================\n");
  VSET(VL_M, e32, m1);
  asm volatile("vle32.v v0, (%0);" ::"r"(vec2));
  asm volatile("vle32.v v1, (%0);" ::"r"(vec2));
  asm volatile("vfredosum.vs v2, v0, v1");
  asm volatile("vse32.v v2, (%0);" ::"r"(res2));
  verify_result_32(vec2, vec2[0], VL_M, res2[0]);
  printf("\n");
  printf("\n");
  
  printf("======================\n");
  printf("VL=256\n");
  printf("======================\n");
  VSET(VL_L, e32, m2);
  asm volatile("vle32.v v4, (%0);" ::"r"(vec3));
  asm volatile("vle32.v v6, (%0);" ::"r"(vec3));
  asm volatile("vfredosum.vs v2, v4, v6");
  asm volatile("vse32.v v2, (%0);" ::"r"(res3));
  verify_result_32(vec3, vec3[0], VL_L, res3[0]);
  printf("\n");
  printf("\n");

  printf("======================\n");
  printf("VL=1024\n");
  printf("======================\n");
  VSET(VL_MAX_32, e32, m8);
  asm volatile("vle32.v v0, (%0);" ::"r"(vec4));
  asm volatile("vle32.v v8, (%0);" ::"r"(vec4));
  asm volatile("vfredosum.vs v16, v0, v8");
  asm volatile("vse32.v v16, (%0);" ::"r"(res4));
  verify_result_32(vec4, vec4[0], VL_MAX_32, res4[0]);
  printf("\n");
  printf("\n");
  
  // Issue a redundant vector add instruction to eliminate 
  // the effect of stalls due to data denpendencies
  printf("======================\n");
  printf("VL=32 PRELOADED\n");
  printf("======================\n");
  VSET(VL_S, e32, m1);
  asm volatile("vle32.v v0, (%0);" ::"r"(vec1));
  asm volatile("vle32.v v1, (%0);" ::"r"(vec1));
  asm volatile("vfadd.vv v2, v0, v1");
  asm volatile("vfredosum.vs v2, v0, v1");
  asm volatile("vse32.v v2, (%0);" ::"r"(res1));
  verify_result_32(vec1, vec1[0], VL_S, res1[0]);
  printf("\n");
  printf("\n");

  printf("======================\n");
  printf("VL=128 PRELOADED\n");
  printf("======================\n");
  VSET(VL_M, e32, m1);
  asm volatile("vle32.v v0, (%0);" ::"r"(vec2));
  asm volatile("vle32.v v1, (%0);" ::"r"(vec2));
  asm volatile("vfadd.vv v2, v0, v1");
  asm volatile("vfredosum.vs v2, v0, v1");
  asm volatile("vse32.v v2, (%0);" ::"r"(res2));
  verify_result_32(vec2, vec2[0], VL_M, res2[0]);
  printf("\n");
  printf("\n");
  
  printf("======================\n");
  printf("VL=256 PRELOADED\n");
  printf("======================\n");
  VSET(VL_L, e32, m2);
  asm volatile("vle32.v v4, (%0);" ::"r"(vec3));
  asm volatile("vle32.v v6, (%0);" ::"r"(vec3));
  asm volatile("vfadd.vv v2, v4, v6");
  asm volatile("vfredosum.vs v2, v4, v6");
  asm volatile("vse32.v v2, (%0);" ::"r"(res3));
  verify_result_32(vec3, vec3[0], VL_L, res3[0]);
  printf("\n");
  printf("\n");

  printf("======================\n");
  printf("VL=1024 PRELOADED\n");
  printf("======================\n");
  VSET(VL_MAX_32, e32, m8);
  asm volatile("vle32.v v0, (%0);" ::"r"(vec4));
  asm volatile("vle32.v v8, (%0);" ::"r"(vec4));
  asm volatile("vfadd.vv v16, v0, v8");
  asm volatile("vfredosum.vs v16, v0, v8");
  asm volatile("vse32.v v16, (%0);" ::"r"(res4));
  verify_result_32(vec4, vec4[0], VL_MAX_32, res4[0]);
  printf("\n");
  printf("\n");
}

void vfredusum_64() {
  printf("\n");
  printf("======================\n");
  printf("VFREDUSUM EW64\n");
  printf("======================\n");
  printf("\n");
  printf("\n");

  double vec1[VL_S], res1[VL_S];
  double vec2[VL_M], res2[VL_M];
  double vec3[VL_L], res3[VL_L];
  double vec4[VL_MAX_64], res4[VL_MAX_64];
  gen_rand_vec_64(vec1, VL_S);
  gen_rand_vec_64(vec2, VL_M);
  gen_rand_vec_64(vec3, VL_L);
  gen_rand_vec_64(vec4, VL_MAX_64);

  printf("======================\n");
  printf("VL=32\n");
  printf("======================\n");
  VSET(VL_S, e64, m1);
  asm volatile("vle64.v v0, (%0);" ::"r"(vec1));
  asm volatile("vle64.v v1, (%0);" ::"r"(vec1));
  asm volatile("vfredsum.vs v2, v0, v1");
  asm volatile("vse64.v v2, (%0);" ::"r"(res1));
  verify_result_64(vec1, vec1[0], VL_S, res1[0]);
  printf("\n");
  printf("\n");

  printf("======================\n");
  printf("VL=128\n");
  printf("======================\n");
  VSET(VL_M, e64, m2);
  asm volatile("vle64.v v0, (%0);" ::"r"(vec2));
  asm volatile("vle64.v v2, (%0);" ::"r"(vec2));
  asm volatile("vfredsum.vs v4, v0, v2");
  asm volatile("vse64.v v4, (%0);" ::"r"(res2));
  verify_result_64(vec2, vec2[0], VL_M, res2[0]);
  printf("\n");
  printf("\n");
  
  printf("======================\n");
  printf("VL=256\n");
  printf("======================\n");
  VSET(VL_L, e64, m4);
  asm volatile("vle64.v v0, (%0);" ::"r"(vec3));
  asm volatile("vle64.v v4, (%0);" ::"r"(vec3));
  asm volatile("vfredsum.vs v8, v0, v4");
  asm volatile("vse64.v v8, (%0);" ::"r"(res3));
  verify_result_64(vec3, vec3[0], VL_L, res3[0]);
  printf("\n");
  printf("\n");

  printf("======================\n");
  printf("VL=512\n");
  printf("======================\n");
  VSET(VL_MAX_64, e64, m8);
  asm volatile("vle64.v v0, (%0);" ::"r"(vec4));
  asm volatile("vle64.v v8, (%0);" ::"r"(vec4));
  asm volatile("vfredsum.vs v16, v0, v8");
  asm volatile("vse64.v v16, (%0);" ::"r"(res4));
  verify_result_64(vec4, vec4[0], VL_MAX_64, res4[0]);
  printf("\n");
  printf("\n");
  
  // Issue a redundant vector add instruction to eliminate 
  // the effect of stalls due to data denpendencies
  printf("======================\n");
  printf("VL=32 PRELOADED\n");
  printf("======================\n");
  VSET(VL_S, e64, m1);
  asm volatile("vle64.v v0, (%0);" ::"r"(vec1));
  asm volatile("vle64.v v1, (%0);" ::"r"(vec1));
  asm volatile("vfadd.vv v2, v0, v1");
  asm volatile("vfredsum.vs v2, v0, v1");
  asm volatile("vse64.v v2, (%0);" ::"r"(res1));
  verify_result_64(vec1, vec1[0], VL_S, res1[0]);
  printf("\n");
  printf("\n");

  printf("======================\n");
  printf("VL=128 PRELOADED\n");
  printf("======================\n");
  VSET(VL_M, e64, m2);
  asm volatile("vle64.v v0, (%0);" ::"r"(vec2));
  asm volatile("vle64.v v2, (%0);" ::"r"(vec2));
  asm volatile("vfadd.vv v4, v0, v2");
  asm volatile("vfredsum.vs v4, v0, v2");
  asm volatile("vse64.v v4, (%0);" ::"r"(res2));
  verify_result_64(vec2, vec2[0], VL_M, res2[0]);
  printf("\n");
  printf("\n");
  
  printf("======================\n");
  printf("VL=256 PRELOADED\n");
  printf("======================\n");
  VSET(VL_L, e64, m4);
  asm volatile("vle64.v v0, (%0);" ::"r"(vec3));
  asm volatile("vle64.v v4, (%0);" ::"r"(vec3));
  asm volatile("vfadd.vv v8, v0, v4");
  asm volatile("vfredsum.vs v8, v0, v4");
  asm volatile("vse64.v v8, (%0);" ::"r"(res3));
  verify_result_64(vec3, vec3[0], VL_L, res3[0]);
  printf("\n");
  printf("\n");

  printf("======================\n");
  printf("VL=512 PRELOADED\n");
  printf("======================\n");
  VSET(VL_MAX_64, e64, m8);
  asm volatile("vle64.v v0, (%0);" ::"r"(vec4));
  asm volatile("vle64.v v8, (%0);" ::"r"(vec4));
  asm volatile("vfadd.vv v16, v0, v8");
  asm volatile("vfredsum.vs v16, v0, v8");
  asm volatile("vse64.v v16, (%0);" ::"r"(res4));
  verify_result_64(vec4, vec4[0], VL_MAX_64, res4[0]);
  printf("\n");
  printf("\n");
}

void vfredosum_64() {
  printf("\n");
  printf("======================\n");
  printf("VFREDOSUM EW64\n");
  printf("======================\n");
  printf("\n");
  printf("\n");

  double vec1[VL_S], res1[VL_S];
  double vec2[VL_M], res2[VL_M];
  double vec3[VL_L], res3[VL_L];
  double vec4[VL_MAX_64], res4[VL_MAX_64];
  gen_rand_vec_64(vec1, VL_S);
  gen_rand_vec_64(vec2, VL_M);
  gen_rand_vec_64(vec3, VL_L);
  gen_rand_vec_64(vec4, VL_MAX_64);

  printf("======================\n");
  printf("VL=32\n");
  printf("======================\n");
  VSET(VL_S, e64, m1);
  asm volatile("vle64.v v0, (%0);" ::"r"(vec1));
  asm volatile("vle64.v v1, (%0);" ::"r"(vec1));
  asm volatile("vfredosum.vs v2, v0, v1");
  asm volatile("vse64.v v2, (%0);" ::"r"(res1));
  verify_result_64(vec1, vec1[0], VL_S, res1[0]);
  printf("\n");
  printf("\n");

  printf("======================\n");
  printf("VL=128\n");
  printf("======================\n");
  VSET(VL_M, e64, m2);
  asm volatile("vle64.v v0, (%0);" ::"r"(vec2));
  asm volatile("vle64.v v2, (%0);" ::"r"(vec2));
  asm volatile("vfredosum.vs v4, v0, v2");
  asm volatile("vse64.v v4, (%0);" ::"r"(res2));
  verify_result_64(vec2, vec2[0], VL_M, res2[0]);
  printf("\n");
  printf("\n");
  
  printf("======================\n");
  printf("VL=256\n");
  printf("======================\n");
  VSET(VL_L, e64, m4);
  asm volatile("vle64.v v0, (%0);" ::"r"(vec3));
  asm volatile("vle64.v v4, (%0);" ::"r"(vec3));
  asm volatile("vfredosum.vs v8, v0, v4");
  asm volatile("vse64.v v8, (%0);" ::"r"(res3));
  verify_result_64(vec3, vec3[0], VL_L, res3[0]);
  printf("\n");
  printf("\n");

  printf("======================\n");
  printf("VL=512\n");
  printf("======================\n");
  VSET(VL_MAX_64, e64, m8);
  asm volatile("vle64.v v0, (%0);" ::"r"(vec4));
  asm volatile("vle64.v v8, (%0);" ::"r"(vec4));
  asm volatile("vfredosum.vs v16, v0, v8");
  asm volatile("vse64.v v16, (%0);" ::"r"(res4));
  verify_result_64(vec4, vec4[0], VL_MAX_64, res4[0]);
  printf("\n");
  printf("\n");
  
  // Issue a redundant vector add instruction to eliminate 
  // the effect of stalls due to data denpendencies
  printf("======================\n");
  printf("VL=32 PRELOADED\n");
  printf("======================\n");
  VSET(VL_S, e64, m1);
  asm volatile("vle64.v v0, (%0);" ::"r"(vec1));
  asm volatile("vle64.v v1, (%0);" ::"r"(vec1));
  asm volatile("vfadd.vv v2, v0, v1");
  asm volatile("vfredosum.vs v2, v0, v1");
  asm volatile("vse64.v v2, (%0);" ::"r"(res1));
  verify_result_64(vec1, vec1[0], VL_S, res1[0]);
  printf("\n");
  printf("\n");

  printf("======================\n");
  printf("VL=128 PRELOADED\n");
  printf("======================\n");
  VSET(VL_M, e64, m2);
  asm volatile("vle64.v v0, (%0);" ::"r"(vec2));
  asm volatile("vle64.v v2, (%0);" ::"r"(vec2));
  asm volatile("vfadd.vv v4, v0, v2");
  asm volatile("vfredosum.vs v4, v0, v2");
  asm volatile("vse64.v v4, (%0);" ::"r"(res2));
  verify_result_64(vec2, vec2[0], VL_M, res2[0]);
  printf("\n");
  printf("\n");
  
  printf("======================\n");
  printf("VL=256 PRELOADED\n");
  printf("======================\n");
  VSET(VL_L, e64, m4);
  asm volatile("vle64.v v0, (%0);" ::"r"(vec3));
  asm volatile("vle64.v v4, (%0);" ::"r"(vec3));
  asm volatile("vfadd.vv v8, v0, v4");
  asm volatile("vfredosum.vs v8, v0, v4");
  asm volatile("vse64.v v8, (%0);" ::"r"(res3));
  verify_result_64(vec3, vec3[0], VL_L, res3[0]);
  printf("\n");
  printf("\n");

  printf("======================\n");
  printf("VL=512 PRELOADED\n");
  printf("======================\n");
  VSET(VL_MAX_64, e64, m8);
  asm volatile("vle64.v v0, (%0);" ::"r"(vec4));
  asm volatile("vle64.v v8, (%0);" ::"r"(vec4));
  asm volatile("vfadd.vv v16, v0, v8");
  asm volatile("vfredosum.vs v16, v0, v8");
  asm volatile("vse64.v v16, (%0);" ::"r"(res4));
  verify_result_64(vec4, vec4[0], VL_MAX_64, res4[0]);
  printf("\n");
  printf("\n");
}

int main() {
  vfredusum_16();
  vfredosum_16();
  vfredusum_32();
  vfredosum_32();
  vfredusum_64();
  vfredosum_64();
  return 0;
}