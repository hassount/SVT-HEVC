/*
* Copyright(c) 2018 Intel Corporation
* SPDX - License - Identifier: BSD - 2 - Clause - Patent
*/

#ifndef EbPictureAnalysis_h
#define EbPictureAnalysis_h

#include "EbDefinitions.h"
#include "EbSystemResourceManager.h"
#include "EbNoiseExtractAVX2.h"


/**************************************
 * Context
 **************************************/
typedef struct PictureAnalysisContext_s
{ 
	EB_ALIGN(64) EB_U8            localCache[64];  
    EbFifo_t                     *resourceCoordinationResultsInputFifoPtr;
    EbFifo_t                     *pictureAnalysisResultsOutputFifoPtr;
	EbPictureBufferDesc_t        *denoisedPicturePtr;
	EbPictureBufferDesc_t        *noisePicturePtr;
	double						  picNoiseVarianceFloat;
    EB_U16		                **grad;
} PictureAnalysisContext_t;

/***************************************
 * Extern Function Declaration
 ***************************************/
extern EB_ERRORTYPE PictureAnalysisContextCtor(
	EbPictureBufferDescInitData_t * inputPictureBufferDescInitData,
	EB_BOOL                         denoiseFlag,
    PictureAnalysisContext_t      **contextDblPtr,
    EbFifo_t                       *resourceCoordinationResultsInputFifoPtr,
    EbFifo_t                       *pictureAnalysisResultsOutputFifoPtr,
    EB_U16						    lcuTotalCount);
    
extern void* PictureAnalysisKernel(void *inputPtr);

void NoiseExtractLumaWeak(
	EbPictureBufferDesc_t       *inputPicturePtr,
	EbPictureBufferDesc_t       *denoisedPicturePtr,
	EbPictureBufferDesc_t       *noisePicturePtr,
	EB_U32                       lcuOriginY,
	EB_U32						 lcuOriginX
	);
typedef void(*EB_WEAKLUMAFILTER_TYPE)(
	EbPictureBufferDesc_t       *inputPicturePtr,
	EbPictureBufferDesc_t       *denoisedPicturePtr,
	EbPictureBufferDesc_t       *noisePicturePtr,
	EB_U32                       lcuOriginY,
	EB_U32						 lcuOriginX
	);
static EB_WEAKLUMAFILTER_TYPE FUNC_TABLE WeakLumaFilter_funcPtrArray[ASM_TYPE_TOTAL] =
{
	// C_DEFAULT
	NoiseExtractLumaWeak,
	// AVX2
	NoiseExtractLumaWeak_AVX2_INTRIN,

};

void NoiseExtractLumaWeakLcu(
	EbPictureBufferDesc_t       *inputPicturePtr,
	EbPictureBufferDesc_t       *denoisedPicturePtr,
	EbPictureBufferDesc_t       *noisePicturePtr,
	EB_U32                       lcuOriginY,
	EB_U32						 lcuOriginX
	);
static EB_WEAKLUMAFILTER_TYPE FUNC_TABLE WeakLumaFilterLcu_funcPtrArray[ASM_TYPE_TOTAL] =
{
	// C_DEFAULT
	NoiseExtractLumaWeakLcu,
	// AVX2
	NoiseExtractLumaWeakLcu_AVX2_INTRIN,

};


void NoiseExtractLumaStrong(
	EbPictureBufferDesc_t       *inputPicturePtr,
	EbPictureBufferDesc_t       *denoisedPicturePtr,
	EB_U32                       lcuOriginY,
	EB_U32						 lcuOriginX
	);
typedef void(*EB_STRONGLUMAFILTER_TYPE)(
	EbPictureBufferDesc_t       *inputPicturePtr,
	EbPictureBufferDesc_t       *denoisedPicturePtr,
	EB_U32                       lcuOriginY,
	EB_U32						 lcuOriginX
	);
static EB_STRONGLUMAFILTER_TYPE FUNC_TABLE StrongLumaFilter_funcPtrArray[ASM_TYPE_TOTAL] =
{
	// C_DEFAULT
	NoiseExtractLumaStrong,
	// AVX2
	NoiseExtractLumaStrong_AVX2_INTRIN,

};
void NoiseExtractChromaStrong(
	EbPictureBufferDesc_t       *inputPicturePtr,
	EbPictureBufferDesc_t       *denoisedPicturePtr,
	EB_U32                       lcuOriginY,
	EB_U32						 lcuOriginX
	);
typedef void(*EB_STRONGCHROMAFILTER_TYPE)(
	EbPictureBufferDesc_t       *inputPicturePtr,
	EbPictureBufferDesc_t       *denoisedPicturePtr,
	EB_U32                       lcuOriginY,
	EB_U32						 lcuOriginX
	);
static EB_STRONGCHROMAFILTER_TYPE FUNC_TABLE StrongChromaFilter_funcPtrArray[ASM_TYPE_TOTAL] =
{
	// C_DEFAULT
	NoiseExtractChromaStrong,
	// AVX2
	NoiseExtractChromaStrong_AVX2_INTRIN,

};

void NoiseExtractChromaWeak(
	EbPictureBufferDesc_t       *inputPicturePtr,
	EbPictureBufferDesc_t       *denoisedPicturePtr,
	EB_U32                       lcuOriginY,
	EB_U32						 lcuOriginX
	);
typedef void(*EB_WEAKCHROMAFILTER_TYPE)(
	EbPictureBufferDesc_t       *inputPicturePtr,
	EbPictureBufferDesc_t       *denoisedPicturePtr,
	EB_U32                       lcuOriginY,
	EB_U32						 lcuOriginX
	);
static EB_WEAKCHROMAFILTER_TYPE FUNC_TABLE WeakChromaFilter_funcPtrArray[ASM_TYPE_TOTAL] =
{
	// C_DEFAULT
	NoiseExtractChromaWeak,
	// AVX2
	NoiseExtractChromaWeak_AVX2_INTRIN,

};


#endif // EbPictureAnalysis_h