#define WIN32_LEAN_AND_MEAN

#include <windows.h>

#include "UnrealVRLoader.h"

BOOL APIENTRY DllMain(HMODULE hModule, const DWORD ul_reason_for_call, LPVOID lpReserved)
{
    switch (ul_reason_for_call)
    {
    case DLL_PROCESS_ATTACH:
        UnrealVR::Loader::Init();
    case DLL_THREAD_ATTACH:
    case DLL_THREAD_DETACH:
        break;
    case DLL_PROCESS_DETACH:
        UnrealVR::Loader::Stop();
    default:
        break;
    }
    return TRUE;
}

