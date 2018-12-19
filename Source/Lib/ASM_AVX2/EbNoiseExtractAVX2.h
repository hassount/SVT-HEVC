/*
* Copyright(c) 2018 Intel Corporation
* SPDX - License - Identifier: BSD - 2 - Clause - Patent
*/

#ifndef EbNoiseExtractAVX2_h
#define EbNoiseExtractAVX2_h

#include "immintrin.h"
#include "EbDefinitions.h"
#include "EbPictureBufferDesc.h"
#ifdef __cplusplus
extern "C" {
#endif


/*******************************************
* noiseExtractLumaWeak
*  weak filter Luma and store noise.
*******************************************/
void NoiseExtractLumaWeak_AVX2_INTRIN(
	EbPictureBufferDesc_t       *inputPicturePtr,	
	EbPictureBufferDesc_t       *denoisedPicturePtr,
	EbPictureBufferDesc_t       *noisePicturePtr,   
	EB_U32                       lcuOriginY,
	EB_U32                       lcuOriginX
	);

void NoiseExtractLumaWeakLcu_AVX2_INTRIN(
	EbPictureBufferDesc_t       *inputPicturePtr,
	EbPictureBufferDesc_t       *denoisedPicturePtr,
	EbPictureBufferDesc_t       *noisePicturePtr,
	EB_U32                       lcuOriginY,
	EB_U32                       lcuOriginX
	);

void NoiseExtractChromaStrong_AVX2_INTRIN(
	EbPictureBufferDesc_t       *inputPicturePtr,
	EbPictureBufferDesc_t       *denoisedPicturePtr,
	EB_U32                       lcuOriginY,
	EB_U32						 lcuOriginX);

void NoiseExtractChromaWeak_AVX2_INTRIN(
	EbPictureBufferDesc_t       *inputPicturePtr,
	EbPictureBufferDesc_t       *denoisedPicturePtr,
	EB_U32                       lcuOriginY,
	EB_U32						 lcuOriginX);

void NoiseExtractLumaStrong_AVX2_INTRIN(
	EbPictureBufferDesc_t       *inputPicturePtr,
	EbPictureBufferDesc_t       *denoisedPicturePtr,
	EB_U32                       lcuOriginY,
	EB_U32                       lcuOriginX);

void ChromaStrong_AVX2_INTRIN(
	__m256i						top,
	__m256i						curr,
	__m256i						bottom,
	__m256i						currPrev,
	__m256i						currNext,
	__m256i						topPrev,
	__m256i						topNext,
	__m256i						bottomPrev,
	__m256i						bottomNext,
	EB_U8					   *ptrDenoised);

void lumaWeakFilter_AVX2_INTRIN(
	__m256i						top,
	__m256i						curr,
	__m256i						bottom,
	__m256i						currPrev,
	__m256i						currNext,
	EB_U8					   *ptrDenoised,
	EB_U8					    *ptrNoise);


void chromaWeakLumaStrongFilter_AVX2_INTRIN(
	__m256i						top,
	__m256i						curr,
	__m256i						bottom,
	__m256i						currPrev,
	__m256i						currNext,
	__m256i						topPrev,
	__m256i						topNext,
	__m256i						bottomPrev,
	__m256i						bottomNext,
	EB_U8					   *ptrDenoised);

#ifdef __cplusplus
}
#endif        
#endif // EbNoiseExtractAVX2_h

