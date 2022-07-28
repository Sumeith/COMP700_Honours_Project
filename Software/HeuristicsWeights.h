#pragma once
#include "DEFINITIONS.hpp" 
#ifdef __cplusplus
extern "C" {
#endif // __cplusplus

	int weight1_4x4[HEIGHT_4x4][WIDTH_4x4];
	int weight1_7x6[HEIGHT_7x6][WIDTH_7x6];
	int weight1_14x12[HEIGHT_14x12][WIDTH_14x12];

	int weight2_4x4[HEIGHT_4x4][WIDTH_4x4];
	int weight2_7x6[HEIGHT_7x6][WIDTH_7x6];
	int weight2_14x12[HEIGHT_14x12][WIDTH_14x12];

	int weight3_4x4[HEIGHT_4x4][WIDTH_4x4];
	int weight3_7x6[HEIGHT_7x6][WIDTH_7x6];
	int weight3_14x12[HEIGHT_14x12][WIDTH_14x12];

#ifdef __cplusplus
}
#endif // __cplusplus