#include <Windows.h>

#include <D2Dll.h>

#undef D2FUNC_DLL
#define D2FUNC_DLL D2FUNC_DLL_STUB

#include <Fog.h>

// Fog.0x6FF53940 (#10229)
uint32_t __stdcall FOG_ComputeChecksum(void* pData, size_t dwSize)
{
	// The original x86 loop interprets the count as signed.
	if (dwSize > 0x7FFFFFFFu)
	{
		return 0;
	}

	const uint8_t* pBytes = static_cast<const uint8_t*>(pData);
	uint32_t nChecksum = 0;
	for (size_t i = 0; i < dwSize; ++i)
	{
		nChecksum = (nChecksum << 1) + (nChecksum >> 31) + pBytes[i];
	}
	return nChecksum;
}
