#define BLEP_OVERSAMPLING 256
#define BLEP_OVERSAMPLING_BITS 8
#define BLEP_TABLE_SIZE 6360
int16_t blep[] = {
16384, 16384, 16384, 16384, 16384, 16384, 16384, 16384,
16384, 16384, 16384, 16384, 16384, 16384, 16384, 16384,
16384, 16384, 16384, 16384, 16384, 16384, 16384, 16384,
16384, 16384, 16384, 16384, 16384, 16384, 16384, 16384,
16384, 16384, 16384, 16384, 16384, 16384, 16384, 16384,
16384, 16384, 16384, 16384, 16384, 16384, 16384, 16384,
16384, 16384, 16384, 16384, 16384, 16384, 16384, 16384,
16384, 16384, 16384, 16384, 16384, 16384, 16384, 16384,
16384, 16384, 16384, 16384, 16384, 16384, 16384, 16384,
16384, 16384, 16384, 16384, 16384, 16384, 16384, 16384,
16384, 16384, 16384, 16384, 16384, 16384, 16384, 16384,
16384, 16384, 16384, 16384, 16384, 16384, 16384, 16384,
16384, 16384, 16384, 16384, 16384, 16384, 16384, 16384,
16384, 16384, 16384, 16384, 16384, 16384, 16384, 16384,
16384, 16384, 16384, 16384, 16384, 16384, 16384, 16384,
16384, 16384, 16384, 16384, 16384, 16384, 16384, 16384,
16384, 16384, 16384, 16384, 16384, 16384, 16384, 16384,
16384, 16384, 16384, 16384, 16383, 16383, 16383, 16383,
16383, 16383, 16383, 16383, 16383, 16383, 16383, 16383,
16383, 16383, 16383, 16383, 16383, 16383, 16383, 16383,
16383, 16383, 16383, 16383, 16383, 16383, 16383, 16383,
16383, 16383, 16382, 16382, 16382, 16382, 16382, 16382,
16382, 16382, 16382, 16382, 16382, 16382, 16382, 16382,
16382, 16382, 16381, 16381, 16381, 16381, 16381, 16381,
16381, 16381, 16381, 16381, 16381, 16380, 16380, 16380,
16380, 16380, 16380, 16380, 16380, 16380, 16379, 16379,
16379, 16379, 16379, 16379, 16379, 16378, 16378, 16378,
16378, 16378, 16378, 16377, 16377, 16377, 16377, 16377,
16376, 16376, 16376, 16376, 16376, 16375, 16375, 16375,
16375, 16374, 16374, 16374, 16374, 16373, 16373, 16373,
16373, 16372, 16372, 16372, 16371, 16371, 16371, 16370,
16370, 16370, 16369, 16369, 16369, 16368, 16368, 16368,
16367, 16367, 16366, 16366, 16366, 16365, 16365, 16364,
16364, 16363, 16363, 16362, 16362, 16361, 16361, 16360,
16360, 16359, 16359, 16358, 16358, 16357, 16356, 16356,
16355, 16354, 16354, 16353, 16353, 16352, 16351, 16350,
16350, 16349, 16348, 16347, 16347, 16346, 16345, 16344,
16343, 16343, 16342, 16341, 16340, 16339, 16338, 16337,
16336, 16335, 16334, 16333, 16332, 16331, 16330, 16329,
16328, 16327, 16326, 16325, 16324, 16322, 16321, 16320,
16319, 16317, 16316, 16315, 16314, 16312, 16311, 16309,
16308, 16307, 16305, 16304, 16302, 16301, 16299, 16298,
16296, 16294, 16293, 16291, 16289, 16288, 16286, 16284,
16282, 16280, 16279, 16277, 16275, 16273, 16271, 16269,
16267, 16265, 16263, 16261, 16258, 16256, 16254, 16252,
16250, 16247, 16245, 16242, 16240, 16238, 16235, 16233,
16230, 16228, 16225, 16222, 16220, 16217, 16214, 16211,
16208, 16206, 16203, 16200, 16197, 16194, 16191, 16187,
16184, 16181, 16178, 16174, 16171, 16168, 16164, 16161,
16157, 16154, 16150, 16147, 16143, 16139, 16135, 16131,
16128, 16124, 16120, 16116, 16112, 16107, 16103, 16099,
16095, 16090, 16086, 16081, 16077, 16072, 16068, 16063,
16058, 16054, 16049, 16044, 16039, 16034, 16029, 16024,
16018, 16013, 16008, 16002, 15997, 15991, 15986, 15980,
15975, 15969, 15963, 15957, 15951, 15945, 15939, 15933,
15927, 15920, 15914, 15907, 15901, 15894, 15888, 15881,
15874, 15867, 15860, 15853, 15846, 15839, 15832, 15824,
15817, 15809, 15802, 15794, 15786, 15779, 15771, 15763,
15755, 15746, 15738, 15730, 15721, 15713, 15704, 15696,
15687, 15678, 15669, 15660, 15651, 15642, 15633, 15623,
15614, 15604, 15595, 15585, 15575, 15565, 15555, 15545,
15535, 15524, 15514, 15503, 15493, 15482, 15471, 15460,
15449, 15438, 15427, 15416, 15404, 15393, 15381, 15369,
15357, 15345, 15333, 15321, 15309, 15296, 15284, 15271,
15259, 15246, 15233, 15220, 15207, 15193, 15180, 15166,
15153, 15139, 15125, 15111, 15097, 15083, 15068, 15054,
15039, 15025, 15010, 14995, 14980, 14964, 14949, 14934,
14918, 14902, 14887, 14871, 14854, 14838, 14822, 14805,
14789, 14772, 14755, 14738, 14721, 14704, 14686, 14669,
14651, 14633, 14616, 14597, 14579, 14561, 14542, 14524,
14505, 14486, 14467, 14448, 14429, 14409, 14390, 14370,
14350, 14330, 14310, 14290, 14269, 14249, 14228, 14207,
14186, 14165, 14143, 14122, 14100, 14079, 14057, 14035,
14012, 13990, 13968, 13945, 13922, 13899, 13876, 13853,
13829, 13806, 13782, 13758, 13734, 13710, 13686, 13661,
13637, 13612, 13587, 13562, 13537, 13511, 13486, 13460,
13434, 13408, 13382, 13356, 13329, 13302, 13276, 13249,
13222, 13194, 13167, 13139, 13111, 13084, 13055, 13027,
12999, 12970, 12942, 12913, 12884, 12854, 12825, 12796,
12766, 12736, 12706, 12676, 12646, 12615, 12584, 12554,
12523, 12492, 12460, 12429, 12397, 12366, 12334, 12302,
12269, 12237, 12204, 12172, 12139, 12106, 12072, 12039,
12006, 11972, 11938, 11904, 11870, 11836, 11801, 11766,
11732, 11697, 11662, 11626, 11591, 11555, 11520, 11484,
11448, 11411, 11375, 11339, 11302, 11265, 11228, 11191,
11154, 11116, 11079, 11041, 11003, 10965, 10927, 10889,
10850, 10811, 10773, 10734, 10695, 10655, 10616, 10576,
10537, 10497, 10457, 10417, 10377, 10336, 10296, 10255,
10214, 10173, 10132, 10091, 10049, 10008, 9966, 9924,
9882, 9840, 9798, 9756, 9713, 9671, 9628, 9585,
9542, 9499, 9456, 9412, 9369, 9325, 9281, 9238,
9194, 9149, 9105, 9061, 9016, 8972, 8927, 8882,
8837, 8792, 8747, 8702, 8656, 8611, 8565, 8519,
8473, 8427, 8381, 8335, 8289, 8242, 8196, 8149,
8103, 8056, 8009, 7962, 7915, 7868, 7821, 7773,
7726, 7678, 7631, 7583, 7535, 7487, 7439, 7391,
7343, 7295, 7247, 7198, 7150, 7102, 7053, 7004,
6956, 6907, 6858, 6809, 6760, 6711, 6662, 6613,
6564, 6515, 6465, 6416, 6366, 6317, 6268, 6218,
6168, 6119, 6069, 6019, 5970, 5920, 5870, 5820,
5770, 5720, 5670, 5620, 5570, 5520, 5470, 5420,
5370, 5320, 5269, 5219, 5169, 5119, 5069, 5018,
4968, 4918, 4868, 4817, 4767, 4717, 4667, 4617,
4566, 4516, 4466, 4416, 4366, 4315, 4265, 4215,
4165, 4115, 4065, 4015, 3965, 3915, 3865, 3815,
3765, 3715, 3665, 3616, 3566, 3516, 3467, 3417,
3368, 3318, 3269, 3219, 3170, 3121, 3071, 3022,
2973, 2924, 2875, 2826, 2778, 2729, 2680, 2632,
2583, 2535, 2487, 2438, 2390, 2342, 2294, 2246,
2199, 2151, 2103, 2056, 2008, 1961, 1914, 1867,
1820, 1773, 1726, 1680, 1633, 1587, 1541, 1494,
1448, 1403, 1357, 1311, 1266, 1220, 1175, 1130,
1085, 1040, 996, 951, 907, 862, 818, 774,
731, 687, 644, 600, 557, 514, 471, 429,
386, 344, 302, 260, 218, 176, 135, 94,
53, 12, -29, -69, -110, -150, -190, -230,
-269, -309, -348, -387, -425, -464, -502, -541,
-578, -616, -654, -691, -728, -765, -802, -838,
-874, -910, -946, -982, -1017, -1052, -1087, -1122,
-1156, -1190, -1224, -1258, -1291, -1325, -1358, -1390,
-1423, -1455, -1487, -1519, -1551, -1582, -1613, -1644,
-1674, -1704, -1735, -1764, -1794, -1823, -1852, -1881,
-1909, -1937, -1965, -1993, -2020, -2048, -2075, -2101,
-2127, -2154, -2179, -2205, -2230, -2255, -2280, -2304,
-2328, -2352, -2376, -2399, -2422, -2445, -2467, -2490,
-2512, -2533, -2555, -2576, -2596, -2617, -2637, -2657,
-2677, -2696, -2715, -2734, -2752, -2770, -2788, -2806,
-2823, -2840, -2857, -2873, -2889, -2905, -2921, -2936,
-2951, -2966, -2980, -2994, -3008, -3021, -3034, -3047,
-3060, -3072, -3084, -3096, -3107, -3118, -3129, -3140,
-3150, -3160, -3169, -3179, -3188, -3197, -3205, -3213,
-3221, -3229, -3236, -3243, -3249, -3256, -3262, -3268,
-3273, -3278, -3283, -3288, -3292, -3296, -3300, -3303,
-3306, -3309, -3312, -3314, -3316, -3318, -3319, -3320,
-3321, -3322, -3322, -3322, -3322, -3321, -3320, -3319,
-3318, -3316, -3314, -3312, -3309, -3306, -3303, -3300,
-3296, -3292, -3288, -3284, -3279, -3274, -3269, -3263,
-3257, -3251, -3245, -3239, -3232, -3225, -3217, -3210,
-3202, -3194, -3185, -3177, -3168, -3159, -3149, -3140,
-3130, -3120, -3110, -3099, -3088, -3077, -3066, -3054,
-3043, -3031, -3018, -3006, -2993, -2980, -2967, -2954,
-2940, -2926, -2912, -2898, -2884, -2869, -2854, -2839,
-2824, -2808, -2793, -2777, -2761, -2745, -2728, -2711,
-2695, -2677, -2660, -2643, -2625, -2607, -2589, -2571,
-2553, -2534, -2516, -2497, -2478, -2459, -2439, -2420,
-2400, -2380, -2360, -2340, -2320, -2299, -2279, -2258,
-2237, -2216, -2195, -2174, -2152, -2131, -2109, -2087,
-2065, -2043, -2021, -1999, -1976, -1954, -1931, -1908,
-1885, -1862, -1839, -1816, -1793, -1769, -1746, -1722,
-1698, -1675, -1651, -1627, -1603, -1579, -1555, -1530,
-1506, -1482, -1457, -1433, -1408, -1383, -1359, -1334,
-1309, -1284, -1259, -1234, -1209, -1184, -1159, -1134,
-1109, -1084, -1059, -1033, -1008, -983, -958, -932,
-907, -882, -856, -831, -805, -780, -755, -729,
-704, -679, -653, -628, -603, -577, -552, -527,
-501, -476, -451, -426, -401, -375, -350, -325,
-300, -275, -250, -226, -201, -176, -151, -127,
-102, -77, -53, -29, -4, 20, 44, 68,
92, 116, 140, 164, 188, 212, 235, 259,
282, 305, 328, 351, 374, 397, 420, 443,
465, 488, 510, 532, 555, 577, 598, 620,
642, 663, 685, 706, 727, 748, 769, 790,
810, 831, 851, 871, 891, 911, 931, 950,
970, 989, 1008, 1027, 1046, 1065, 1083, 1101,
1120, 1138, 1156, 1173, 1191, 1208, 1225, 1242,
1259, 1276, 1292, 1308, 1324, 1340, 1356, 1372,
1387, 1402, 1417, 1432, 1447, 1461, 1475, 1489,
1503, 1517, 1531, 1544, 1557, 1570, 1582, 1595,
1607, 1619, 1631, 1643, 1654, 1666, 1677, 1688,
1698, 1709, 1719, 1729, 1739, 1749, 1758, 1767,
1776, 1785, 1794, 1802, 1810, 1818, 1826, 1833,
1841, 1848, 1855, 1861, 1868, 1874, 1880, 1886,
1891, 1897, 1902, 1907, 1911, 1916, 1920, 1924,
1928, 1932, 1935, 1938, 1941, 1944, 1947, 1949,
1951, 1953, 1955, 1956, 1958, 1959, 1960, 1960,
1961, 1961, 1961, 1961, 1960, 1960, 1959, 1958,
1956, 1955, 1953, 1951, 1949, 1947, 1944, 1942,
1939, 1936, 1932, 1929, 1925, 1921, 1917, 1913,
1908, 1903, 1898, 1893, 1888, 1883, 1877, 1871,
1865, 1859, 1852, 1846, 1839, 1832, 1825, 1817,
1810, 1802, 1794, 1786, 1778, 1769, 1760, 1752,
1743, 1734, 1724, 1715, 1705, 1695, 1685, 1675,
1665, 1654, 1644, 1633, 1622, 1611, 1600, 1588,
1577, 1565, 1553, 1541, 1529, 1517, 1505, 1492,
1479, 1467, 1454, 1441, 1427, 1414, 1401, 1387,
1373, 1359, 1345, 1331, 1317, 1303, 1289, 1274,
1259, 1245, 1230, 1215, 1200, 1185, 1169, 1154,
1139, 1123, 1107, 1092, 1076, 1060, 1044, 1028,
1012, 996, 979, 963, 947, 930, 914, 897,
880, 864, 847, 830, 813, 796, 779, 762,
745, 728, 710, 693, 676, 659, 641, 624,
606, 589, 571, 554, 536, 519, 501, 484,
466, 448, 431, 413, 395, 378, 360, 342,
325, 307, 289, 272, 254, 236, 219, 201,
184, 166, 148, 131, 113, 96, 78, 61,
44, 26, 9, -8, -26, -43, -60, -77,
-94, -111, -128, -145, -162, -179, -196, -212,
-229, -246, -262, -278, -295, -311, -327, -344,
-360, -376, -392, -407, -423, -439, -455, -470,
-485, -501, -516, -531, -546, -561, -576, -591,
-605, -620, -635, -649, -663, -677, -691, -705,
-719, -733, -746, -760, -773, -786, -799, -812,
-825, -838, -851, -863, -875, -888, -900, -912,
-923, -935, -947, -958, -969, -981, -992, -1002,
-1013, -1024, -1034, -1044, -1055, -1065, -1074, -1084,
-1094, -1103, -1112, -1121, -1130, -1139, -1148, -1156,
-1165, -1173, -1181, -1189, -1196, -1204, -1211, -1219,
-1226, -1233, -1239, -1246, -1252, -1259, -1265, -1271,
-1276, -1282, -1288, -1293, -1298, -1303, -1308, -1312,
-1317, -1321, -1325, -1329, -1333, -1336, -1340, -1343,
-1346, -1349, -1352, -1355, -1357, -1359, -1361, -1363,
-1365, -1367, -1368, -1369, -1371, -1371, -1372, -1373,
-1373, -1373, -1374, -1374, -1373, -1373, -1372, -1372,
-1371, -1370, -1368, -1367, -1365, -1364, -1362, -1360,
-1358, -1355, -1353, -1350, -1347, -1344, -1341, -1338,
-1334, -1331, -1327, -1323, -1319, -1315, -1310, -1306,
-1301, -1296, -1292, -1286, -1281, -1276, -1270, -1264,
-1259, -1253, -1247, -1240, -1234, -1227, -1221, -1214,
-1207, -1200, -1193, -1185, -1178, -1170, -1162, -1155,
-1147, -1138, -1130, -1122, -1113, -1105, -1096, -1087,
-1078, -1069, -1060, -1051, -1041, -1032, -1022, -1013,
-1003, -993, -983, -973, -962, -952, -942, -931,
-921, -910, -899, -888, -877, -866, -855, -844,
-832, -821, -810, -798, -786, -775, -763, -751,
-739, -727, -715, -703, -691, -679, -666, -654,
-641, -629, -616, -604, -591, -579, -566, -553,
-540, -527, -514, -501, -489, -475, -462, -449,
-436, -423, -410, -397, -384, -370, -357, -344,
-330, -317, -304, -290, -277, -264, -250, -237,
-224, -210, -197, -184, -170, -157, -143, -130,
-117, -103, -90, -77, -63, -50, -37, -24,
-10, 3, 16, 29, 42, 55, 68, 81,
94, 107, 120, 133, 146, 159, 171, 184,
197, 209, 222, 234, 247, 259, 272, 284,
296, 308, 320, 332, 344, 356, 368, 380,
392, 403, 415, 426, 438, 449, 460, 471,
483, 494, 504, 515, 526, 537, 547, 558,
568, 579, 589, 599, 609, 619, 629, 638,
648, 658, 667, 676, 686, 695, 704, 713,
722, 730, 739, 747, 756, 764, 772, 780,
788, 796, 804, 811, 819, 826, 833, 840,
847, 854, 861, 868, 874, 881, 887, 893,
899, 905, 911, 916, 922, 927, 932, 937,
942, 947, 952, 957, 961, 965, 970, 974,
978, 982, 985, 989, 992, 995, 999, 1002,
1004, 1007, 1010, 1012, 1015, 1017, 1019, 1021,
1023, 1024, 1026, 1027, 1029, 1030, 1031, 1032,
1032, 1033, 1033, 1034, 1034, 1034, 1034, 1034,
1033, 1033, 1032, 1032, 1031, 1030, 1029, 1027,
1026, 1024, 1023, 1021, 1019, 1017, 1015, 1013,
1010, 1008, 1005, 1002, 999, 996, 993, 990,
986, 983, 979, 976, 972, 968, 964, 959,
955, 950, 946, 941, 936, 931, 926, 921,
916, 911, 905, 900, 894, 888, 882, 876,
870, 864, 858, 851, 845, 838, 831, 825,
818, 811, 804, 796, 789, 782, 774, 767,
759, 751, 744, 736, 728, 720, 712, 704,
695, 687, 679, 670, 661, 653, 644, 635,
627, 618, 609, 600, 591, 581, 572, 563,
554, 544, 535, 525, 516, 506, 496, 487,
477, 467, 457, 447, 438, 428, 418, 408,
398, 387, 377, 367, 357, 347, 336, 326,
316, 306, 295, 285, 274, 264, 254, 243,
233, 222, 212, 201, 191, 180, 170, 159,
149, 138, 128, 117, 107, 96, 86, 75,
65, 54, 44, 33, 23, 13, 2, -8,
-19, -29, -39, -50, -60, -70, -80, -90,
-101, -111, -121, -131, -141, -151, -161, -171,
-181, -191, -200, -210, -220, -230, -239, -249,
-258, -268, -277, -286, -296, -305, -314, -323,
-332, -341, -350, -359, -368, -377, -386, -394,
-403, -411, -420, -428, -436, -445, -453, -461,
-469, -477, -485, -492, -500, -508, -515, -523,
-530, -537, -545, -552, -559, -566, -573, -579,
-586, -593, -599, -605, -612, -618, -624, -630,
-636, -642, -648, -653, -659, -664, -670, -675,
-680, -685, -690, -695, -700, -705, -709, -714,
-718, -722, -726, -730, -734, -738, -742, -746,
-749, -753, -756, -759, -762, -765, -768, -771,
-773, -776, -778, -781, -783, -785, -787, -789,
-791, -793, -794, -796, -797, -798, -799, -800,
-801, -802, -803, -803, -804, -804, -805, -805,
-805, -805, -805, -804, -804, -804, -803, -802,
-801, -801, -800, -798, -797, -796, -794, -793,
-791, -790, -788, -786, -784, -782, -779, -777,
-774, -772, -769, -767, -764, -761, -758, -755,
-751, -748, -745, -741, -737, -734, -730, -726,
-722, -718, -714, -709, -705, -701, -696, -692,
-687, -682, -677, -672, -667, -662, -657, -652,
-646, -641, -635, -630, -624, -618, -613, -607,
-601, -595, -589, -583, -576, -570, -564, -557,
-551, -544, -538, -531, -524, -517, -511, -504,
-497, -490, -483, -475, -468, -461, -454, -446,
-439, -432, -424, -416, -409, -401, -394, -386,
-378, -370, -363, -355, -347, -339, -331, -323,
-315, -307, -299, -291, -283, -275, -266, -258,
-250, -242, -234, -225, -217, -209, -200, -192,
-184, -175, -167, -159, -150, -142, -134, -125,
-117, -108, -100, -92, -83, -75, -66, -58,
-50, -41, -33, -25, -16, -8, 0, 9,
17, 25, 34, 42, 50, 58, 66, 74,
83, 91, 99, 107, 115, 123, 131, 139,
147, 155, 162, 170, 178, 186, 193, 201,
209, 216, 224, 231, 239, 246, 253, 261,
268, 275, 282, 289, 296, 303, 310, 317,
324, 331, 337, 344, 351, 357, 364, 370,
377, 383, 389, 395, 401, 407, 413, 419,
425, 431, 437, 442, 448, 453, 459, 464,
469, 475, 480, 485, 490, 495, 500, 504,
509, 514, 518, 523, 527, 531, 535, 540,
544, 548, 551, 555, 559, 563, 566, 570,
573, 576, 579, 583, 586, 589, 591, 594,
597, 600, 602, 605, 607, 609, 611, 613,
615, 617, 619, 621, 623, 624, 626, 627,
628, 629, 631, 632, 633, 633, 634, 635,
635, 636, 636, 637, 637, 637, 637, 637,
637, 637, 636, 636, 636, 635, 634, 634,
633, 632, 631, 630, 629, 627, 626, 625,
623, 622, 620, 618, 616, 614, 612, 610,
608, 606, 604, 601, 599, 596, 594, 591,
588, 585, 582, 579, 576, 573, 570, 566,
563, 560, 556, 552, 549, 545, 541, 537,
533, 529, 525, 521, 517, 513, 508, 504,
499, 495, 490, 486, 481, 476, 471, 467,
462, 457, 452, 446, 441, 436, 431, 426,
420, 415, 409, 404, 398, 393, 387, 381,
376, 370, 364, 358, 352, 346, 340, 334,
328, 322, 316, 310, 304, 297, 291, 285,
279, 272, 266, 260, 253, 247, 240, 234,
227, 221, 214, 208, 201, 194, 188, 181,
174, 168, 161, 154, 148, 141, 134, 128,
121, 114, 107, 101, 94, 87, 81, 74,
67, 60, 54, 47, 40, 33, 27, 20,
13, 7, 0, -7, -13, -20, -27, -33,
-40, -47, -53, -60, -66, -73, -79, -86,
-92, -98, -105, -111, -118, -124, -130, -136,
-143, -149, -155, -161, -167, -173, -179, -185,
-191, -197, -203, -209, -215, -221, -226, -232,
-238, -243, -249, -254, -260, -265, -271, -276,
-281, -286, -292, -297, -302, -307, -312, -317,
-322, -326, -331, -336, -341, -345, -350, -354,
-359, -363, -367, -372, -376, -380, -384, -388,
-392, -396, -400, -403, -407, -411, -414, -418,
-421, -425, -428, -431, -435, -438, -441, -444,
-447, -449, -452, -455, -458, -460, -463, -465,
-468, -470, -472, -474, -476, -478, -480, -482,
-484, -486, -487, -489, -490, -492, -493, -495,
-496, -497, -498, -499, -500, -501, -502, -502,
-503, -504, -504, -505, -505, -505, -506, -506,
-506, -506, -506, -506, -505, -505, -505, -504,
-504, -503, -503, -502, -501, -500, -500, -499,
-498, -496, -495, -494, -493, -491, -490, -488,
-487, -485, -483, -482, -480, -478, -476, -474,
-472, -470, -467, -465, -463, -460, -458, -455,
-453, -450, -447, -445, -442, -439, -436, -433,
-430, -427, -424, -421, -417, -414, -411, -407,
-404, -400, -396, -393, -389, -385, -382, -378,
-374, -370, -366, -362, -358, -354, -350, -346,
-341, -337, -333, -328, -324, -320, -315, -311,
-306, -302, -297, -292, -288, -283, -278, -273,
-269, -264, -259, -254, -249, -244, -239, -234,
-229, -224, -219, -214, -209, -204, -199, -193,
-188, -183, -178, -172, -167, -162, -157, -151,
-146, -141, -135, -130, -125, -119, -114, -109,
-103, -98, -92, -87, -82, -76, -71, -65,
-60, -55, -49, -44, -38, -33, -28, -22,
-17, -12, -6, -1, 5, 10, 15, 21,
26, 31, 36, 42, 47, 52, 57, 63,
68, 73, 78, 83, 88, 93, 98, 103,
108, 113, 118, 123, 128, 133, 138, 143,
148, 152, 157, 162, 166, 171, 176, 180,
185, 189, 194, 198, 203, 207, 211, 216,
220, 224, 228, 232, 237, 241, 245, 249,
252, 256, 260, 264, 268, 271, 275, 279,
282, 286, 289, 293, 296, 300, 303, 306,
309, 312, 315, 319, 322, 324, 327, 330,
333, 336, 338, 341, 344, 346, 349, 351,
353, 356, 358, 360, 362, 364, 366, 368,
370, 372, 374, 376, 377, 379, 380, 382,
383, 385, 386, 387, 389, 390, 391, 392,
393, 394, 395, 396, 396, 397, 398, 398,
399, 399, 400, 400, 400, 401, 401, 401,
401, 401, 401, 401, 401, 401, 400, 400,
400, 399, 399, 398, 397, 397, 396, 395,
394, 394, 393, 392, 391, 389, 388, 387,
386, 384, 383, 382, 380, 379, 377, 375,
374, 372, 370, 368, 366, 365, 363, 361,
358, 356, 354, 352, 350, 347, 345, 343,
340, 338, 335, 332, 330, 327, 324, 322,
319, 316, 313, 310, 307, 304, 301, 298,
295, 292, 289, 286, 282, 279, 276, 272,
269, 266, 262, 259, 255, 252, 248, 244,
241, 237, 233, 230, 226, 222, 218, 215,
211, 207, 203, 199, 195, 191, 187, 183,
179, 175, 171, 167, 163, 159, 155, 151,
146, 142, 138, 134, 130, 126, 121, 117,
113, 109, 104, 100, 96, 92, 87, 83,
79, 74, 70, 66, 62, 57, 53, 49,
44, 40, 36, 31, 27, 23, 19, 14,
10, 6, 2, -3, -7, -11, -15, -20,
-24, -28, -32, -36, -40, -45, -49, -53,
-57, -61, -65, -69, -73, -77, -81, -85,
-89, -93, -97, -101, -105, -109, -112, -116,
-120, -124, -127, -131, -135, -139, -142, -146,
-149, -153, -156, -160, -163, -167, -170, -173,
-177, -180, -183, -187, -190, -193, -196, -199,
-202, -205, -208, -211, -214, -217, -220, -223,
-226, -228, -231, -234, -236, -239, -241, -244,
-246, -249, -251, -254, -256, -258, -260, -263,
-265, -267, -269, -271, -273, -275, -277, -278,
-280, -282, -284, -285, -287, -289, -290, -292,
-293, -294, -296, -297, -298, -299, -301, -302,
-303, -304, -305, -306, -307, -308, -308, -309,
-310, -310, -311, -312, -312, -313, -313, -313,
-314, -314, -314, -314, -315, -315, -315, -315,
-315, -315, -315, -314, -314, -314, -314, -313,
-313, -312, -312, -311, -311, -310, -309, -309,
-308, -307, -306, -305, -305, -304, -303, -302,
-300, -299, -298, -297, -296, -294, -293, -292,
-290, -289, -287, -286, -284, -283, -281, -279,
-277, -276, -274, -272, -270, -268, -266, -264,
-262, -260, -258, -256, -254, -252, -250, -247,
-245, -243, -240, -238, -236, -233, -231, -228,
-226, -223, -221, -218, -215, -213, -210, -207,
-205, -202, -199, -196, -193, -190, -188, -185,
-182, -179, -176, -173, -170, -167, -164, -161,
-158, -155, -152, -148, -145, -142, -139, -136,
-133, -129, -126, -123, -120, -116, -113, -110,
-107, -103, -100, -97, -93, -90, -87, -83,
-80, -77, -73, -70, -66, -63, -60, -56,
-53, -50, -46, -43, -39, -36, -33, -29,
-26, -23, -19, -16, -13, -9, -6, -2,
1, 4, 8, 11, 14, 17, 21, 24,
27, 31, 34, 37, 40, 44, 47, 50,
53, 56, 59, 63, 66, 69, 72, 75,
78, 81, 84, 87, 90, 93, 96, 99,
102, 105, 108, 110, 113, 116, 119, 122,
124, 127, 130, 132, 135, 138, 140, 143,
145, 148, 150, 153, 155, 158, 160, 162,
165, 167, 169, 171, 174, 176, 178, 180,
182, 184, 186, 188, 190, 192, 194, 196,
198, 199, 201, 203, 204, 206, 208, 209,
211, 212, 214, 215, 217, 218, 220, 221,
222, 223, 225, 226, 227, 228, 229, 230,
231, 232, 233, 234, 235, 236, 236, 237,
238, 239, 239, 240, 240, 241, 241, 242,
242, 243, 243, 243, 244, 244, 244, 244,
244, 244, 244, 244, 244, 244, 244, 244,
244, 244, 244, 243, 243, 243, 242, 242,
242, 241, 241, 240, 239, 239, 238, 238,
237, 236, 235, 234, 234, 233, 232, 231,
230, 229, 228, 227, 226, 225, 223, 222,
221, 220, 218, 217, 216, 214, 213, 212,
210, 209, 207, 206, 204, 202, 201, 199,
198, 196, 194, 192, 191, 189, 187, 185,
183, 181, 179, 178, 176, 174, 172, 170,
167, 165, 163, 161, 159, 157, 155, 153,
150, 148, 146, 144, 141, 139, 137, 135,
132, 130, 128, 125, 123, 120, 118, 116,
113, 111, 108, 106, 103, 101, 98, 96,
93, 91, 88, 86, 83, 80, 78, 75,
73, 70, 68, 65, 62, 60, 57, 55,
52, 49, 47, 44, 41, 39, 36, 34,
31, 28, 26, 23, 21, 18, 15, 13,
10, 8, 5, 2, 0, -3, -5, -8,
-11, -13, -16, -18, -21, -23, -26, -28,
-31, -33, -36, -38, -41, -43, -45, -48,
-50, -53, -55, -57, -60, -62, -64, -67,
-69, -71, -74, -76, -78, -80, -83, -85,
-87, -89, -91, -93, -95, -97, -100, -102,
-104, -106, -108, -110, -111, -113, -115, -117,
-119, -121, -123, -124, -126, -128, -130, -131,
-133, -135, -136, -138, -140, -141, -143, -144,
-146, -147, -149, -150, -151, -153, -154, -155,
-157, -158, -159, -160, -162, -163, -164, -165,
-166, -167, -168, -169, -170, -171, -172, -173,
-174, -174, -175, -176, -177, -178, -178, -179,
-180, -180, -181, -181, -182, -182, -183, -183,
-184, -184, -184, -185, -185, -185, -185, -186,
-186, -186, -186, -186, -186, -186, -186, -186,
-186, -186, -186, -186, -186, -186, -185, -185,
-185, -185, -184, -184, -184, -183, -183, -182,
-182, -181, -181, -180, -180, -179, -179, -178,
-177, -177, -176, -175, -174, -173, -173, -172,
-171, -170, -169, -168, -167, -166, -165, -164,
-163, -162, -161, -160, -159, -158, -156, -155,
-154, -153, -151, -150, -149, -148, -146, -145,
-143, -142, -141, -139, -138, -136, -135, -133,
-132, -130, -129, -127, -125, -124, -122, -121,
-119, -117, -116, -114, -112, -111, -109, -107,
-105, -104, -102, -100, -98, -96, -95, -93,
-91, -89, -87, -85, -84, -82, -80, -78,
-76, -74, -72, -70, -68, -66, -64, -62,
-60, -59, -57, -55, -53, -51, -49, -47,
-45, -43, -41, -39, -37, -35, -33, -31,
-29, -27, -25, -23, -21, -19, -17, -15,
-13, -11, -9, -7, -5, -3, -1, 1,
3, 5, 7, 9, 11, 13, 15, 16,
18, 20, 22, 24, 26, 28, 30, 32,
33, 35, 37, 39, 41, 42, 44, 46,
48, 50, 51, 53, 55, 57, 58, 60,
62, 63, 65, 67, 68, 70, 71, 73,
74, 76, 78, 79, 81, 82, 84, 85,
86, 88, 89, 91, 92, 93, 95, 96,
97, 99, 100, 101, 102, 104, 105, 106,
107, 108, 109, 111, 112, 113, 114, 115,
116, 117, 118, 119, 120, 121, 121, 122,
123, 124, 125, 126, 126, 127, 128, 129,
129, 130, 131, 131, 132, 132, 133, 133,
134, 134, 135, 135, 136, 136, 137, 137,
137, 138, 138, 138, 138, 139, 139, 139,
139, 139, 140, 140, 140, 140, 140, 140,
140, 140, 140, 140, 140, 140, 140, 139,
139, 139, 139, 139, 138, 138, 138, 138,
137, 137, 136, 136, 136, 135, 135, 134,
134, 133, 133, 132, 132, 131, 131, 130,
129, 129, 128, 127, 127, 126, 125, 125,
124, 123, 122, 121, 121, 120, 119, 118,
117, 116, 115, 114, 113, 112, 111, 110,
109, 108, 107, 106, 105, 104, 103, 102,
101, 100, 98, 97, 96, 95, 94, 92,
91, 90, 89, 88, 86, 85, 84, 82,
81, 80, 79, 77, 76, 75, 73, 72,
70, 69, 68, 66, 65, 64, 62, 61,
59, 58, 56, 55, 54, 52, 51, 49,
48, 46, 45, 43, 42, 40, 39, 37,
36, 35, 33, 32, 30, 29, 27, 26,
24, 23, 21, 20, 18, 17, 15, 14,
12, 11, 9, 8, 6, 5, 3, 2,
0, -1, -2, -4, -5, -7, -8, -10,
-11, -13, -14, -15, -17, -18, -20, -21,
-22, -24, -25, -26, -28, -29, -30, -32,
-33, -34, -36, -37, -38, -40, -41, -42,
-43, -45, -46, -47, -48, -50, -51, -52,
-53, -54, -55, -57, -58, -59, -60, -61,
-62, -63, -64, -65, -66, -67, -68, -69,
-70, -71, -72, -73, -74, -75, -76, -77,
-78, -78, -79, -80, -81, -82, -82, -83,
-84, -85, -86, -86, -87, -88, -88, -89,
-90, -90, -91, -91, -92, -93, -93, -94,
-94, -95, -95, -96, -96, -96, -97, -97,
-98, -98, -98, -99, -99, -99, -100, -100,
-100, -100, -101, -101, -101, -101, -101, -102,
-102, -102, -102, -102, -102, -102, -102, -102,
-102, -102, -102, -102, -102, -102, -102, -102,
-102, -102, -102, -101, -101, -101, -101, -101,
-100, -100, -100, -100, -99, -99, -99, -98,
-98, -98, -97, -97, -96, -96, -96, -95,
-95, -94, -94, -93, -93, -92, -92, -91,
-91, -90, -89, -89, -88, -88, -87, -86,
-86, -85, -84, -84, -83, -82, -81, -81,
-80, -79, -78, -78, -77, -76, -75, -75,
-74, -73, -72, -71, -70, -69, -69, -68,
-67, -66, -65, -64, -63, -62, -61, -60,
-59, -58, -57, -56, -56, -55, -54, -53,
-52, -51, -50, -49, -48, -46, -45, -44,
-43, -42, -41, -40, -39, -38, -37, -36,
-35, -34, -33, -32, -31, -30, -29, -27,
-26, -25, -24, -23, -22, -21, -20, -19,
-18, -17, -15, -14, -13, -12, -11, -10,
-9, -8, -7, -6, -5, -4, -3, -1,
0, 1, 2, 3, 4, 5, 6, 7,
8, 9, 10, 11, 12, 13, 14, 15,
16, 17, 18, 19, 20, 21, 22, 23,
24, 25, 26, 27, 28, 29, 30, 31,
31, 32, 33, 34, 35, 36, 37, 38,
38, 39, 40, 41, 42, 43, 43, 44,
45, 46, 46, 47, 48, 49, 49, 50,
51, 52, 52, 53, 54, 54, 55, 55,
56, 57, 57, 58, 59, 59, 60, 60,
61, 61, 62, 62, 63, 63, 64, 64,
65, 65, 66, 66, 66, 67, 67, 68,
68, 68, 69, 69, 69, 70, 70, 70,
70, 71, 71, 71, 71, 72, 72, 72,
72, 72, 73, 73, 73, 73, 73, 73,
73, 73, 73, 73, 74, 74, 74, 74,
74, 74, 74, 74, 73, 73, 73, 73,
73, 73, 73, 73, 73, 73, 72, 72,
72, 72, 72, 71, 71, 71, 71, 71,
70, 70, 70, 69, 69, 69, 68, 68,
68, 67, 67, 67, 66, 66, 66, 65,
65, 64, 64, 63, 63, 63, 62, 62,
61, 61, 60, 60, 59, 59, 58, 58,
57, 57, 56, 55, 55, 54, 54, 53,
52, 52, 51, 51, 50, 49, 49, 48,
47, 47, 46, 46, 45, 44, 43, 43,
42, 41, 41, 40, 39, 39, 38, 37,
36, 36, 35, 34, 34, 33, 32, 31,
31, 30, 29, 28, 28, 27, 26, 25,
25, 24, 23, 22, 22, 21, 20, 19,
18, 18, 17, 16, 15, 15, 14, 13,
12, 11, 11, 10, 9, 8, 8, 7,
6, 5, 5, 4, 3, 2, 2, 1,
0, -1, -2, -2, -3, -4, -4, -5,
-6, -7, -7, -8, -9, -10, -10, -11,
-12, -12, -13, -14, -14, -15, -16, -17,
-17, -18, -19, -19, -20, -21, -21, -22,
-22, -23, -24, -24, -25, -26, -26, -27,
-27, -28, -28, -29, -30, -30, -31, -31,
-32, -32, -33, -33, -34, -34, -35, -35,
-36, -36, -37, -37, -38, -38, -39, -39,
-40, -40, -40, -41, -41, -42, -42, -42,
-43, -43, -43, -44, -44, -44, -45, -45,
-45, -46, -46, -46, -46, -47, -47, -47,
-47, -48, -48, -48, -48, -49, -49, -49,
-49, -49, -49, -50, -50, -50, -50, -50,
-50, -50, -50, -51, -51, -51, -51, -51,
-51, -51, -51, -51, -51, -51, -51, -51,
-51, -51, -51, -51, -51, -51, -51, -51,
-50, -50, -50, -50, -50, -50, -50, -50,
-50, -49, -49, -49, -49, -49, -49, -48,
-48, -48, -48, -48, -47, -47, -47, -47,
-46, -46, -46, -46, -45, -45, -45, -44,
-44, -44, -43, -43, -43, -42, -42, -42,
-41, -41, -41, -40, -40, -40, -39, -39,
-38, -38, -38, -37, -37, -36, -36, -36,
-35, -35, -34, -34, -33, -33, -33, -32,
-32, -31, -31, -30, -30, -29, -29, -28,
-28, -27, -27, -26, -26, -25, -25, -24,
-24, -23, -23, -22, -22, -21, -21, -20,
-20, -19, -19, -18, -18, -17, -17, -16,
-16, -15, -14, -14, -13, -13, -12, -12,
-11, -11, -10, -10, -9, -9, -8, -7,
-7, -6, -6, -5, -5, -4, -4, -3,
-3, -2, -2, -1, -1, 0, 0, 1,
1, 2, 2, 3, 4, 4, 5, 5,
6, 6, 7, 7, 7, 8, 8, 9,
9, 10, 10, 11, 11, 12, 12, 13,
13, 14, 14, 14, 15, 15, 16, 16,
17, 17, 17, 18, 18, 19, 19, 19,
20, 20, 21, 21, 21, 22, 22, 22,
23, 23, 24, 24, 24, 25, 25, 25,
25, 26, 26, 26, 27, 27, 27, 28,
28, 28, 28, 29, 29, 29, 29, 30,
30, 30, 30, 31, 31, 31, 31, 31,
31, 32, 32, 32, 32, 32, 33, 33,
33, 33, 33, 33, 33, 33, 34, 34,
34, 34, 34, 34, 34, 34, 34, 34,
34, 34, 34, 34, 34, 34, 35, 35,
35, 35, 35, 35, 35, 34, 34, 34,
34, 34, 34, 34, 34, 34, 34, 34,
34, 34, 34, 34, 34, 33, 33, 33,
33, 33, 33, 33, 33, 32, 32, 32,
32, 32, 32, 31, 31, 31, 31, 31,
31, 30, 30, 30, 30, 30, 29, 29,
29, 29, 28, 28, 28, 28, 27, 27,
27, 27, 26, 26, 26, 26, 25, 25,
25, 25, 24, 24, 24, 23, 23, 23,
22, 22, 22, 22, 21, 21, 21, 20,
20, 20, 19, 19, 19, 18, 18, 18,
17, 17, 17, 16, 16, 16, 15, 15,
15, 14, 14, 13, 13, 13, 12, 12,
12, 11, 11, 11, 10, 10, 10, 9,
9, 8, 8, 8, 7, 7, 7, 6,
6, 6, 5, 5, 4, 4, 4, 3,
3, 3, 2, 2, 2, 1, 1, 1,
0, 0, -1, -1, -1, -2, -2, -2,
-3, -3, -3, -4, -4, -4, -5, -5,
-5, -6, -6, -6, -7, -7, -7, -8,
-8, -8, -8, -9, -9, -9, -10, -10,
-10, -11, -11, -11, -11, -12, -12, -12,
-12, -13, -13, -13, -14, -14, -14, -14,
-15, -15, -15, -15, -15, -16, -16, -16,
-16, -17, -17, -17, -17, -17, -18, -18,
-18, -18, -18, -19, -19, -19, -19, -19,
-19, -20, -20, -20, -20, -20, -20, -20,
-21, -21, -21, -21, -21, -21, -21, -21,
-22, -22, -22, -22, -22, -22, -22, -22,
-22, -22, -22, -22, -22, -23, -23, -23,
-23, -23, -23, -23, -23, -23, -23, -23,
-23, -23, -23, -23, -23, -23, -23, -23,
-23, -23, -23, -23, -23, -23, -23, -23,
-23, -22, -22, -22, -22, -22, -22, -22,
-22, -22, -22, -22, -22, -22, -22, -21,
-21, -21, -21, -21, -21, -21, -21, -21,
-20, -20, -20, -20, -20, -20, -20, -19,
-19, -19, -19, -19, -19, -19, -18, -18,
-18, -18, -18, -18, -17, -17, -17, -17,
-17, -16, -16, -16, -16, -16, -15, -15,
-15, -15, -15, -14, -14, -14, -14, -14,
-13, -13, -13, -13, -13, -12, -12, -12,
-12, -11, -11, -11, -11, -11, -10, -10,
-10, -10, -9, -9, -9, -9, -8, -8,
-8, -8, -7, -7, -7, -7, -6, -6,
-6, -6, -6, -5, -5, -5, -5, -4,
-4, -4, -4, -3, -3, -3, -3, -2,
-2, -2, -2, -1, -1, -1, -1, -1,
0, 0, 0, 0, 1, 1, 1, 1,
2, 2, 2, 2, 2, 3, 3, 3,
3, 4, 4, 4, 4, 4, 5, 5,
5, 5, 5, 6, 6, 6, 6, 6,
7, 7, 7, 7, 7, 8, 8, 8,
8, 8, 8, 9, 9, 9, 9, 9,
9, 10, 10, 10, 10, 10, 10, 11,
11, 11, 11, 11, 11, 11, 12, 12,
12, 12, 12, 12, 12, 12, 12, 13,
13, 13, 13, 13, 13, 13, 13, 13,
13, 14, 14, 14, 14, 14, 14, 14,
14, 14, 14, 14, 14, 14, 14, 15,
15, 15, 15, 15, 15, 15, 15, 15,
15, 15, 15, 15, 15, 15, 15, 15,
15, 15, 15, 15, 15, 15, 15, 15,
15, 15, 15, 15, 15, 15, 15, 15,
15, 15, 15, 15, 15, 15, 15, 14,
14, 14, 14, 14, 14, 14, 14, 14,
14, 14, 14, 14, 14, 14, 14, 13,
13, 13, 13, 13, 13, 13, 13, 13,
13, 13, 12, 12, 12, 12, 12, 12,
12, 12, 12, 11, 11, 11, 11, 11,
11, 11, 11, 10, 10, 10, 10, 10,
10, 10, 10, 9, 9, 9, 9, 9,
9, 9, 8, 8, 8, 8, 8, 8,
8, 7, 7, 7, 7, 7, 7, 7,
6, 6, 6, 6, 6, 6, 5, 5,
5, 5, 5, 5, 5, 4, 4, 4,
4, 4, 4, 3, 3, 3, 3, 3,
3, 2, 2, 2, 2, 2, 2, 2,
1, 1, 1, 1, 1, 1, 0, 0,
0, 0, 0, 0, 0, -1, -1, -1,
-1, -1, -1, -1, -2, -2, -2, -2,
-2, -2, -2, -3, -3, -3, -3, -3,
-3, -3, -4, -4, -4, -4, -4, -4,
-4, -4, -5, -5, -5, -5, -5, -5,
-5, -5, -5, -6, -6, -6, -6, -6,
-6, -6, -6, -6, -7, -7, -7, -7,
-7, -7, -7, -7, -7, -7, -7, -8,
-8, -8, -8, -8, -8, -8, -8, -8,
-8, -8, -8, -8, -8, -8, -9, -9,
-9, -9, -9, -9, -9, -9, -9, -9,
-9, -9, -9, -9, -9, -9, -9, -9,
-9, -9, -9, -9, -9, -9, -9, -9,
-9, -9, -9, -9, -9, -9, -9, -10,
-10, -10, -10, -9, -9, -9, -9, -9,
-9, -9, -9, -9, -9, -9, -9, -9,
-9, -9, -9, -9, -9, -9, -9, -9,
-9, -9, -9, -9, -9, -9, -9, -9,
-9, -9, -9, -9, -9, -8, -8, -8,
-8, -8, -8, -8, -8, -8, -8, -8,
-8, -8, -8, -8, -8, -7, -7, -7,
-7, -7, -7, -7, -7, -7, -7, -7,
-7, -7, -6, -6, -6, -6, -6, -6,
-6, -6, -6, -6, -6, -6, -5, -5,
-5, -5, -5, -5, -5, -5, -5, -5,
-5, -4, -4, -4, -4, -4, -4, -4,
-4, -4, -4, -3, -3, -3, -3, -3,
-3, -3, -3, -3, -3, -2, -2, -2,
-2, -2, -2, -2, -2, -2, -2, -1,
-1, -1, -1, -1, -1, -1, -1, -1,
-1, 0, 0, 0, 0, 0, 0, 0,
0, 0, 0, 1, 1, 1, 1, 1,
1, 1, 1, 1, 1, 1, 2, 2,
2, 2, 2, 2, 2, 2, 2, 2,
2, 2, 3, 3, 3, 3, 3, 3,
3, 3, 3, 3, 3, 3, 3, 4,
4, 4, 4, 4, 4, 4, 4, 4,
4, 4, 4, 4, 4, 4, 4, 5,
5, 5, 5, 5, 5, 5, 5, 5,
5, 5, 5, 5, 5, 5, 5, 5,
5, 5, 5, 5, 5, 6, 6, 6,
6, 6, 6, 6, 6, 6, 6, 6,
6, 6, 6, 6, 6, 6, 6, 6,
6, 6, 6, 6, 6, 6, 6, 6,
6, 6, 6, 6, 6, 6, 6, 6,
6, 6, 6, 6, 6, 6, 6, 6,
6, 6, 6, 6, 6, 6, 6, 6,
6, 6, 6, 6, 6, 6, 6, 6,
6, 6, 6, 6, 6, 5, 5, 5,
5, 5, 5, 5, 5, 5, 5, 5,
5, 5, 5, 5, 5, 5, 5, 5,
5, 5, 5, 5, 5, 5, 5, 4,
4, 4, 4, 4, 4, 4, 4, 4,
4, 4, 4, 4, 4, 4, 4, 4,
4, 3, 3, 3, 3, 3, 3, 3,
3, 3, 3, 3, 3, 3, 3, 3,
3, 3, 2, 2, 2, 2, 2, 2,
2, 2, 2, 2, 2, 2, 2, 2,
2, 2, 1, 1, 1, 1, 1, 1,
1, 1, 1, 1, 1, 1, 1, 1,
1, 1, 0, 0, 0, 0, 0, 0,
0, 0, 0, 0, 0, 0, 0, 0,
0, 0, 0, -1, -1, -1, -1, -1,
-1, -1, -1, -1, -1, -1, -1, -1,
-1, -1, -1, -1, -1, -1, -2, -2,
-2, -2, -2, -2, -2, -2, -2, -2,
-2, -2, -2, -2, -2, -2, -2, -2,
-2, -2, -2, -2, -3, -3, -3, -3,
-3, -3, -3, -3, -3, -3, -3, -3,
-3, -3, -3, -3, -3, -3, -3, -3,
-3, -3, -3, -3, -3, -3, -3, -3,
-3, -3, -3, -3, -3, -3, -3, -3,
-3, -3, -3, -3, -3, -4, -4, -4,
-4, -4, -4, -4, -4, -4, -4, -4,
-4, -4, -4, -4, -4, -4, -4, -4,
-4, -4, -4, -4, -4, -4, -4, -4,
-4, -4, -4, -4, -4, -4, -4, -4,
};