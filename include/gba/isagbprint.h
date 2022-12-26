#ifndef GUARD_GBA_ISAGBPRINT_H
#define GUARD_GBA_ISAGBPRINT_H

#if NDEBUG || SPANISH
#define AGBPrintInit()
#define AGBPutc(cChr)
#define AGBPrint(pBuf)
#define	AGBPrintf(pBuf, ...)
#define AGBPrintFlush1Block()
#define AGBPrintFlush()
#define AGBAssert(pFile, nLine, pExpression, nStopProgram)
#else
void AGBPrintInit(void);
void AGBPutc(const char cChr);
void AGBPrint(const char *pBuf);
void AGBPrintf(const char *pBuf, ...);
void AGBPrintFlush1Block(void);
void AGBPrintFlush(void);
void AGBAssert(const char *pFile, int nLine, const char *pExpression, int nStopProgram);
#endif

#undef AGB_ASSERT
#if NDEBUG || SPANISH
#define	AGB_ASSERT(exp)
#else
#define	AGB_ASSERT(exp) (exp) ? ((void *)0) : AGBAssert(__FILE__, __LINE__, #exp, 1);
#endif

#undef AGB_WARNING
#if NDEBUG || SPANISH
#define	AGB_WARNING(exp)
#else
#define	AGB_WARNING(exp) (exp) ? ((void *)0) : AGBAssert(__FILE__, __LINE__, #exp, 0);
#endif

// for matching purposes

#if MODERN
#define AGB_ASSERT_EX(exp, file, line) AGB_ASSERT(exp)
#define AGB_WARNING_EX(exp, file, line) AGB_WARNING(exp)
#else
#if NDEBUG || SPANISH
#define	AGB_ASSERT_EX(exp, file, line)
#else
#define	AGB_ASSERT_EX(exp, file, line) (exp) ? ((void *)0) : AGBAssert(file, line, #exp, 1);
#endif

#if NDEBUG || SPANISH
#define	AGB_WARNING_EX(exp, file, line)
#else
#define	AGB_WARNING_EX(exp, file, line) (exp) ? ((void *)0) : AGBAssert(file, line, #exp, 0);
#endif
#endif

#endif // GUARD_GBA_ISAGBPRINT_H
