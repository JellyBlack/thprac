#include "thprac_load_exe.h"
#include <windows.h>

namespace THPrac {

//#define INIT_SHELLCODE "\x55\x8B\xEC\x83\xE4\xF8\x83\xEC\x2C\x33\xC4\x89\x44\x24\x28\x8B\x45\x08\x53\x56\x57\x8B\x48\x04\x8B\x10\x89\x4C\x24\x14\x8B\x48\x08\x89\x4C\x24\x28\x8B\x48\x0C\x83\xC0\x10\x50\x89\x54\x24\x30\x89\x4C\x24\x24\xFF\xD2\x8B\xF0\x85\xF6\x0F\x84\xC3\x01\x00\x00\x8B\x7E\x3C\x03\xFE\x89\x7C\x24\x24\x2B\x47\x34\x89\x44\x24\x18\x0F\x84\xBB\x00\x00\x00\x8B\x87\xA0\x00\x00\x00\x85\xC0\x0F\x84\xAD\x00\x00\x00\x83\xBF\xA4\x00\x00\x00\x00\x0F\x84\xA0\x00\x00\x00\x8D\x0C\x30\x89\x4C\x24\x10\x85\xC9\x0F\x84\x83\x01\x00\x00\x8B\x01\x8B\x51\x04\x03\xC2\x0F\x84\x84\x00\x00\x00\x8D\x42\xF8\xBB\x00\x00\x00\x00\xD1\xE8\x89\x44\x24\x1C\x74\x60\xBA\x00\x30\x00\x00\x66\x0F\x1F\x84\x00\x00\x00\x00\x00\x0F\xB7\x7C\x59\x08\x8B\xC7\x25\x00\xF0\x00\x00\x66\x3B\xD0\x75\x37\x8D\x44\x24\x30\x81\xE7\xFF\x0F\x00\x00\x03\x39\x50\x6A\x40\x6A\x04\x03\xFE\x57\xFF\x54\x24\x24\x8B\x44\x24\x18\x01\x07\x8D\x44\x24\x30\x50\xFF\x74\x24\x34\x6A\x04\x57\xFF\x54\x24\x24\x8B\x4C\x24\x10\xBA\x00\x30\x00\x00\x43\x3B\x5C\x24\x1C\x7C\xB1\x8B\x51\x04\x8B\x04\x11\x03\xCA\x89\x4C\x24\x10\x8B\x51\x04\x03\xC2\x75\x80\x8B\x7C\x24\x24\x8B\x87\x80\x00\x00\x00\x85\xC0\x0F\x84\xC2\x00\x00\x00\x83\xBF\x84\x00\x00\x00\x00\x0F\x84\xB5\x00\x00\x00\x8D\x1C\x30\x8B\x43\x0C\x89\x5C\x24\x18\x85\xC0\x0F\x84\xA3\x00\x00\x00\x8D\x3C\x30\x57\xFF\x54\x24\x2C\x8B\xC8\x89\x4C\x24\x10\x85\xC9\x75\x13\x57\xFF\x54\x24\x30\x8B\xC8\x89\x44\x24\x10\x85\xC9\x0F\x84\xA0\x00\x00\x00\x8B\x13\x8B\x43\x10\x85\xD2\x75\x02\x8B\xD0\x03\xD6\x8D\x3C\x30\x8B\x02\x85\xC0\x74\x52\x2B\xD7\x85\xC0\x89\x54\x24\x1C\x79\x05\x0F\xB7\xC0\xEB\x05\x83\xC0\x02\x03\xC6\x50\x51\xFF\x54\x24\x28\x8B\xD8\x8D\x44\x24\x30\x50\x6A\x40\x6A\x04\x57\xFF\x54\x24\x24\x8D\x44\x24\x30\x89\x1F\x50\xFF\x74\x24\x34\x6A\x04\x57\xFF\x54\x24\x24\x8B\x44\x24\x1C\x83\xC7\x04\x8B\x4C\x24\x10\x8B\x04\x38\x85\xC0\x75\xBA\x8B\x5C\x24\x18\x8B\x43\x20\x83\xC3\x14\x89\x5C\x24\x18\x85\xC0\x0F\x85\x61\xFF\xFF\xFF\x8B\x7C\x24\x24\x8B\x47\x28\x03\xC6\x74\x02\xFF\xD0\xB8\x01\x00\x00\x00\x5F\x5E\x5B\x8B\x4C\x24\x28\x33\xCC\x8B\xE5\x5D\xC2\x04\x00\x8B\x4C\x24\x34\x33\xC0\x5F\x5E\x5B\x33\xCC\x8B\xE5\x5D\xC2\x04\x00\xCC"

/* D:\Projects\thprac\Release\thprac.exe (1/6/2022 1:36:55 PM)
   StartOffset(h): 00180FF0, EndOffset(h): 001813DF, Length(h): 000003F0 */

unsigned char INIT_SHELLCODE[1008] = {
    0x83, 0xEC, 0x20, 0x8B, 0x4C, 0x24, 0x24, 0x53, 0x55, 0x56, 0x8B, 0x41,
    0x0C, 0x8B, 0x51, 0x08, 0x8B, 0x69, 0x10, 0x89, 0x44, 0x24, 0x10, 0x8B,
    0x41, 0x14, 0x89, 0x44, 0x24, 0x1C, 0x8D, 0x41, 0x18, 0x57, 0x50, 0x89,
    0x54, 0x24, 0x30, 0x89, 0x6C, 0x24, 0x1C, 0xFF, 0xD2, 0x8B, 0xF0, 0x85,
    0xF6, 0x0F, 0x84, 0xDA, 0x01, 0x00, 0x00, 0x8B, 0x56, 0x3C, 0x03, 0xD6,
    0x89, 0x54, 0x24, 0x1C, 0x2B, 0x42, 0x34, 0x89, 0x44, 0x24, 0x24, 0x0F,
    0x84, 0xA9, 0x00, 0x00, 0x00, 0x8B, 0x82, 0xA0, 0x00, 0x00, 0x00, 0x85,
    0xC0, 0x0F, 0x84, 0x9B, 0x00, 0x00, 0x00, 0x83, 0xBA, 0xA4, 0x00, 0x00,
    0x00, 0x00, 0x0F, 0x84, 0x8E, 0x00, 0x00, 0x00, 0x8D, 0x2C, 0x30, 0x85,
    0xED, 0x0F, 0x84, 0x9E, 0x01, 0x00, 0x00, 0x8B, 0x45, 0x00, 0x8B, 0x4D,
    0x04, 0x03, 0xC1, 0x74, 0x75, 0xBA, 0x00, 0x30, 0x00, 0x00, 0x8D, 0x41,
    0xF8, 0xBB, 0x00, 0x00, 0x00, 0x00, 0xD1, 0xE8, 0x89, 0x44, 0x24, 0x28,
    0x74, 0x4F, 0x0F, 0xB7, 0x7C, 0x5D, 0x08, 0x8B, 0xC7, 0x25, 0x00, 0xF0,
    0x00, 0x00, 0x66, 0x3B, 0xD0, 0x75, 0x34, 0x8D, 0x44, 0x24, 0x10, 0x81,
    0xE7, 0xFF, 0x0F, 0x00, 0x00, 0x03, 0x7D, 0x00, 0x50, 0x6A, 0x40, 0x6A,
    0x04, 0x03, 0xFE, 0x57, 0xFF, 0x54, 0x24, 0x24, 0x8B, 0x44, 0x24, 0x24,
    0x01, 0x07, 0x8D, 0x44, 0x24, 0x10, 0x50, 0xFF, 0x74, 0x24, 0x14, 0x6A,
    0x04, 0x57, 0xFF, 0x54, 0x24, 0x24, 0xBA, 0x00, 0x30, 0x00, 0x00, 0x43,
    0x3B, 0x5C, 0x24, 0x28, 0x7C, 0xB4, 0x8B, 0x4D, 0x04, 0x8B, 0x44, 0x0D,
    0x00, 0x03, 0xE9, 0x8B, 0x4D, 0x04, 0x03, 0xC1, 0x75, 0x94, 0x8B, 0x54,
    0x24, 0x1C, 0x8B, 0x6C, 0x24, 0x18, 0x8B, 0x82, 0x80, 0x00, 0x00, 0x00,
    0x85, 0xC0, 0x0F, 0x84, 0xB8, 0x00, 0x00, 0x00, 0x83, 0xBA, 0x84, 0x00,
    0x00, 0x00, 0x00, 0x0F, 0x84, 0xAB, 0x00, 0x00, 0x00, 0x8D, 0x1C, 0x30,
    0x8B, 0x43, 0x0C, 0x89, 0x5C, 0x24, 0x24, 0x85, 0xC0, 0x0F, 0x84, 0x99,
    0x00, 0x00, 0x00, 0x8D, 0x3C, 0x30, 0x57, 0xFF, 0xD5, 0x8B, 0xE8, 0x85,
    0xED, 0x75, 0x0F, 0x57, 0xFF, 0x54, 0x24, 0x30, 0x8B, 0xE8, 0x85, 0xED,
    0x0F, 0x84, 0xD3, 0x00, 0x00, 0x00, 0x8B, 0x0B, 0x8B, 0x43, 0x10, 0x85,
    0xC9, 0x75, 0x02, 0x8B, 0xC8, 0x03, 0xCE, 0x8D, 0x3C, 0x30, 0x8B, 0x01,
    0x85, 0xC0, 0x74, 0x4E, 0x2B, 0xCF, 0x85, 0xC0, 0x89, 0x4C, 0x24, 0x28,
    0x79, 0x05, 0x0F, 0xB7, 0xC0, 0xEB, 0x05, 0x83, 0xC0, 0x02, 0x03, 0xC6,
    0x50, 0x55, 0xFF, 0x54, 0x24, 0x28, 0x8B, 0xD8, 0x8D, 0x44, 0x24, 0x10,
    0x50, 0x6A, 0x40, 0x6A, 0x04, 0x57, 0xFF, 0x54, 0x24, 0x24, 0x8D, 0x44,
    0x24, 0x10, 0x89, 0x1F, 0x50, 0xFF, 0x74, 0x24, 0x14, 0x6A, 0x04, 0x57,
    0xFF, 0x54, 0x24, 0x24, 0x8B, 0x44, 0x24, 0x28, 0x83, 0xC7, 0x04, 0x8B,
    0x04, 0x38, 0x85, 0xC0, 0x75, 0xBE, 0x8B, 0x5C, 0x24, 0x24, 0x8B, 0x43,
    0x20, 0x83, 0xC3, 0x14, 0x8B, 0x6C, 0x24, 0x18, 0x89, 0x5C, 0x24, 0x24,
    0x85, 0xC0, 0x0F, 0x85, 0x6B, 0xFF, 0xFF, 0xFF, 0x8B, 0x54, 0x24, 0x1C,
    0x8B, 0xBA, 0xC0, 0x00, 0x00, 0x00, 0x85, 0xFF, 0x74, 0x3C, 0x8B, 0x7C,
    0x37, 0x0C, 0x85, 0xFF, 0x74, 0x1B, 0x8B, 0x07, 0x85, 0xC0, 0x74, 0x15,
    0x6A, 0x00, 0x6A, 0x01, 0x56, 0xFF, 0xD0, 0x8B, 0x47, 0x04, 0x8D, 0x7F,
    0x04, 0x85, 0xC0, 0x75, 0xEF, 0x8B, 0x54, 0x24, 0x1C, 0x8B, 0x44, 0x24,
    0x34, 0x8B, 0x08, 0x85, 0xC9, 0x74, 0x06, 0x8B, 0x40, 0x04, 0x89, 0x0C,
    0x06, 0x8B, 0x42, 0x28, 0x03, 0xC6, 0x74, 0x02, 0xFF, 0xD0, 0x5F, 0x5E,
    0x5D, 0xB8, 0x01, 0x00, 0x00, 0x00, 0x5B, 0x83, 0xC4, 0x20, 0xC2, 0x04,
    0x00, 0x5F, 0x5E, 0x5D, 0x33, 0xC0, 0x5B, 0x83, 0xC4, 0x20, 0xC2, 0x04,
    0x00, 0xCC, 0xCC, 0xCC, 0x83, 0xEC, 0x68, 0xA1, 0xB4, 0x27, 0x33, 0x10,
    0x33, 0xC4, 0x89, 0x44, 0x24, 0x64, 0x53, 0x55, 0x8B, 0x6C, 0x24, 0x74,
    0x56, 0x57, 0x8B, 0xBC, 0x24, 0x80, 0x00, 0x00, 0x00, 0xBE, 0xF8, 0x36,
    0x2F, 0x10, 0xC7, 0x44, 0x24, 0x1C, 0x00, 0x00, 0x00, 0x00, 0xC6, 0x44,
    0x24, 0x53, 0x00, 0xC6, 0x44, 0x24, 0x4F, 0x86, 0x0F, 0x1F, 0x40, 0x00,
    0x0F, 0x1F, 0x84, 0x00, 0x00, 0x00, 0x00, 0x00, 0xF3, 0x0F, 0x7E, 0x06,
    0x8B, 0x46, 0x08, 0x66, 0x0F, 0xD6, 0x44, 0x24, 0x20, 0x8B, 0x54, 0x24,
    0x20, 0x8B, 0xCA, 0x66, 0x0F, 0xD6, 0x44, 0x24, 0x14, 0x89, 0x44, 0x24,
    0x10, 0x8D, 0x59, 0x01, 0x8A, 0x01, 0x41, 0x84, 0xC0, 0x75, 0xF9, 0x2B,
    0xCB, 0x8D, 0x41, 0x01, 0x50, 0x52, 0x8D, 0x44, 0x24, 0x5C, 0x50, 0xE8,
    0xB8, 0x11, 0x09, 0x00, 0x83, 0xC4, 0x0C, 0x8D, 0x44, 0x24, 0x1C, 0x6A,
    0x00, 0x50, 0x68, 0x10, 0x28, 0x18, 0x10, 0x8D, 0x44, 0x24, 0x44, 0x50,
    0x55, 0xFF, 0x15, 0x10, 0x00, 0x25, 0x10, 0x83, 0x7C, 0x24, 0x1C, 0x00,
    0x0F, 0x85, 0xD8, 0x00, 0x00, 0x00, 0x83, 0xC6, 0x0C, 0x81, 0xFE, 0x58,
    0x37, 0x2F, 0x10, 0x75, 0x97, 0x33, 0xC0, 0xC7, 0x44, 0x24, 0x30, 0x00,
    0x00, 0x00, 0x00, 0x50, 0x66, 0x89, 0x44, 0x24, 0x24, 0x8D, 0x44, 0x24,
    0x24, 0x50, 0x68, 0xD0, 0x22, 0x18, 0x10, 0x6A, 0x00, 0x55, 0xC7, 0x44,
    0x24, 0x48, 0x07, 0x00, 0x00, 0x00, 0xFF, 0x15, 0x28, 0x00, 0x25, 0x10,
    0x83, 0x7C, 0x24, 0x30, 0x00, 0x75, 0x04, 0x33, 0xF6, 0xEB, 0x48, 0x83,
    0x7C, 0x24, 0x34, 0x08, 0x8D, 0x44, 0x24, 0x20, 0xC7, 0x07, 0x2C, 0x0B,
    0x25, 0x10, 0x0F, 0x43, 0x44, 0x24, 0x20, 0x50, 0x6A, 0x00, 0x6A, 0x00,
    0x6A, 0x00, 0x6A, 0x00, 0x68, 0x86, 0x00, 0x00, 0x00, 0x6A, 0x00, 0x6A,
    0x00, 0x6A, 0x00, 0x6A, 0x00, 0x6A, 0x00, 0x6A, 0x00, 0x6A, 0x00, 0x6A,
    0x00, 0xC7, 0x47, 0x04, 0x00, 0x00, 0x00, 0x00, 0xC7, 0x47, 0x08, 0x00,
    0x00, 0x80, 0x3F, 0xFF, 0x15, 0x30, 0x00, 0x25, 0x10, 0x8B, 0xF0, 0x8B,
    0x54, 0x24, 0x34, 0x83, 0xFA, 0x08, 0x72, 0x2F, 0x8B, 0x4C, 0x24, 0x20,
    0x8D, 0x14, 0x55, 0x02, 0x00, 0x00, 0x00, 0x8B, 0xC1, 0x81, 0xFA, 0x00,
    0x10, 0x00, 0x00, 0x72, 0x10, 0x8B, 0x49, 0xFC, 0x83, 0xC2, 0x23, 0x2B,
    0xC1, 0x83, 0xC0, 0xFC, 0x83, 0xF8, 0x1F, 0x77, 0x6C, 0x52, 0x51, 0xE8,
    0x70, 0xB6, 0x08, 0x00, 0x83, 0xC4, 0x08, 0x5F, 0x8B, 0xC6, 0x5E, 0x5D,
    0x5B, 0x8B, 0x4C, 0x24, 0x64, 0x33, 0xCC, 0xE8, 0x6A, 0xB6, 0x08, 0x00,
    0x83, 0xC4, 0x68, 0xC2, 0x08, 0x00, 0xF3, 0x0F, 0x7E, 0x44, 0x24, 0x14,
    0x8B, 0x44, 0x24, 0x10, 0x66, 0x0F, 0xD6, 0x07, 0x89, 0x47, 0x08, 0xFF,
    0x37, 0x6A, 0x00, 0x6A, 0x00, 0x6A, 0x00, 0x6A, 0x00, 0x68, 0x86, 0x00,
    0x00, 0x00, 0x6A, 0x00, 0x6A, 0x00, 0x6A, 0x00, 0x6A, 0x00, 0x6A, 0x00,
    0x6A, 0x00, 0x6A, 0x00, 0x6A, 0x00, 0xFF, 0x15, 0x34, 0x00, 0x25, 0x10,
    0x8B, 0x4C, 0x24, 0x74, 0x5F, 0x5E, 0x5D, 0x5B, 0x33, 0xCC, 0xE8, 0x1F,
    0xB6, 0x08, 0x00, 0x83, 0xC4, 0x68, 0xC2, 0x08, 0x00, 0xE8, 0x1B, 0x2E,
    0x0A, 0x00, 0xCC, 0xCC, 0xCC, 0xCC, 0xCC, 0xCC, 0xCC, 0xCC, 0xCC, 0xCC
};


typedef HMODULE(WINAPI* PLoadLibraryA)(LPCSTR);
typedef BOOL(WINAPI* PVirtualProtect)(LPVOID, SIZE_T, DWORD, PDWORD);
typedef HMODULE(WINAPI* PGetModuleHandleA)(LPCSTR);
typedef FARPROC(WINAPI* PGetProcAddress)(HMODULE, LPCSTR);
typedef void (*PExeMain)();

typedef struct __remote_param {
    LPVOID pUserData;
    PUINT8 pAddrOfUserData;
    PLoadLibraryA pLoadLibraryA; // LoadLibraryA
    PVirtualProtect pVirtualProtect; // VirtualProtect
    PGetModuleHandleA pGetModuleHandleA; // GetModuleHandleA
    PGetProcAddress pGetProcAddress; // GetProcAddress
    char sExePath[MAX_PATH];
} remote_param;

#define MakePointer(t, p, offset) ((t)((PUINT8)(p) + offset))

#if 0
#pragma comment(linker, "/EXPORT:InitParamNew=_InitParamNew@4")
extern "C" __declspec(safebuffers) DWORD WINAPI InitParamNew(remote_param* param)
{
    union // MemModule base
    {
#if _WIN64
        ULONGLONG iBase;
#else
        DWORD iBase;
#endif
        HMODULE hModule;
        LPVOID lpBase;
        PIMAGE_DOS_HEADER pImageDosHeader;
    } pe;

    auto pLoadLibraryA = param->pLoadLibraryA;
    auto pVirtualProtect = param->pVirtualProtect;
    auto pGetModuleHandleA = param->pGetModuleHandleA;
    auto pGetProcAddress = param->pGetProcAddress;
    DWORD lOldProtect;

    pe.hModule = pLoadLibraryA(param->sExePath);
    if (pe.hModule == NULL)
        return FALSE;

    /*-------------------------------------------------------------------------------

								  B A S E    R E L O C A T I O N

		-------------------------------------------------------------------------------*/

    PIMAGE_NT_HEADERS pImageNtHeader = MakePointer(PIMAGE_NT_HEADERS, pe.pImageDosHeader, pe.pImageDosHeader->e_lfanew);

    // Get the delta of the real image base with the predefined
    LONGLONG lBaseDelta = ((PUINT8)pe.iBase - (PUINT8)pImageNtHeader->OptionalHeader.ImageBase);

    // This module has been loaded to the ImageBase, no need to do relocation
    if (0 != lBaseDelta) {
        if (!(0 == pImageNtHeader->OptionalHeader.DataDirectory[IMAGE_DIRECTORY_ENTRY_BASERELOC].VirtualAddress || 0 == pImageNtHeader->OptionalHeader.DataDirectory[IMAGE_DIRECTORY_ENTRY_BASERELOC].Size)) {

            PIMAGE_BASE_RELOCATION pImageBaseRelocation = MakePointer(PIMAGE_BASE_RELOCATION, pe.lpBase,
                pImageNtHeader->OptionalHeader.DataDirectory[IMAGE_DIRECTORY_ENTRY_BASERELOC].VirtualAddress);

            if (NULL == pImageBaseRelocation)
                return FALSE;

            while (0 != (pImageBaseRelocation->VirtualAddress + pImageBaseRelocation->SizeOfBlock)) {
                PWORD pRelocationData = MakePointer(PWORD, pImageBaseRelocation, sizeof(IMAGE_BASE_RELOCATION));

                int NumberOfRelocationData = (pImageBaseRelocation->SizeOfBlock - sizeof(IMAGE_BASE_RELOCATION)) / sizeof(WORD);

                for (int i = 0; i < NumberOfRelocationData; i++) {
                    if (IMAGE_REL_BASED_HIGHLOW == (pRelocationData[i] >> 12)) {
                        PDWORD pAddress = (PDWORD)(pe.iBase + pImageBaseRelocation->VirtualAddress + (pRelocationData[i] & 0x0FFF));

                        pVirtualProtect(pAddress, sizeof(DWORD), PAGE_EXECUTE_READWRITE, &lOldProtect);
                        *pAddress += (DWORD)lBaseDelta;
                        pVirtualProtect(pAddress, sizeof(DWORD), lOldProtect, &lOldProtect);
                    }

#ifdef _WIN64
                    if (IMAGE_REL_BASED_DIR64 == (pRelocationData[i] >> 12)) {
                        PULONGLONG pAddress = (PULONGLONG)(param->iBase + pImageBaseRelocation->VirtualAddress + (pRelocationData[i] & 0x0FFF));
                        *pAddress += lBaseDelta;
                    }
#endif
                }

                pImageBaseRelocation = MakePointer(PIMAGE_BASE_RELOCATION, pImageBaseRelocation, pImageBaseRelocation->SizeOfBlock);
            }
        }
    }

    /*-------------------------------------------------------------------------------

								  I M P O R T    R E S O L V E

		-------------------------------------------------------------------------------*/
    if (!(pImageNtHeader->OptionalHeader.DataDirectory[IMAGE_DIRECTORY_ENTRY_IMPORT].VirtualAddress == 0 || pImageNtHeader->OptionalHeader.DataDirectory[IMAGE_DIRECTORY_ENTRY_IMPORT].Size == 0)) {

        PIMAGE_IMPORT_DESCRIPTOR pImageImportDescriptor = MakePointer(PIMAGE_IMPORT_DESCRIPTOR, pe.lpBase,
            pImageNtHeader->OptionalHeader.DataDirectory[IMAGE_DIRECTORY_ENTRY_IMPORT].VirtualAddress);

        for (; pImageImportDescriptor->Name; pImageImportDescriptor++) {
            // Get the dependent module name
            PCHAR pDllName = MakePointer(PCHAR, pe.lpBase, pImageImportDescriptor->Name);

            // Get the dependent module handle
            HMODULE hMod = pGetModuleHandleA(pDllName);

            // Load the dependent module
            if (NULL == hMod)
                hMod = pLoadLibraryA(pDllName);

            // Failed
            if (NULL == hMod)
                return FALSE;

            // Original thunk
            PIMAGE_THUNK_DATA pOriginalThunk = NULL;
            if (pImageImportDescriptor->OriginalFirstThunk)
                pOriginalThunk = MakePointer(PIMAGE_THUNK_DATA, pe.lpBase, pImageImportDescriptor->OriginalFirstThunk);
            else
                pOriginalThunk = MakePointer(PIMAGE_THUNK_DATA, pe.lpBase, pImageImportDescriptor->FirstThunk);

            // IAT thunk
            PIMAGE_THUNK_DATA pIATThunk = MakePointer(PIMAGE_THUNK_DATA, pe.lpBase,
                pImageImportDescriptor->FirstThunk);

            for (; pOriginalThunk->u1.AddressOfData; pOriginalThunk++, pIATThunk++) {
                FARPROC lpFunction = NULL;
                if (IMAGE_SNAP_BY_ORDINAL(pOriginalThunk->u1.Ordinal)) {
                    lpFunction = pGetProcAddress(hMod, (LPCSTR)IMAGE_ORDINAL(pOriginalThunk->u1.Ordinal));
                } else {
                    PIMAGE_IMPORT_BY_NAME pImageImportByName = MakePointer(
                        PIMAGE_IMPORT_BY_NAME, pe.lpBase, pOriginalThunk->u1.AddressOfData);

                    lpFunction = pGetProcAddress(hMod, (LPCSTR) & (pImageImportByName->Name));
                }

                // Write into IAT
#ifdef _WIN64
                pVirtualProtect(&(pIATThunk->u1.Function), sizeof(ULONGLONG), PAGE_EXECUTE_READWRITE, &lOldProtect);
                pIATThunk->u1.Function = (ULONGLONG)lpFunction;
                pVirtualProtect(&(pIATThunk->u1.Function), sizeof(ULONGLONG), lOldProtect, &lOldProtect);
#else
                pVirtualProtect(&(pIATThunk->u1.Function), sizeof(DWORD), PAGE_EXECUTE_READWRITE, &lOldProtect);
                pIATThunk->u1.Function = (DWORD)lpFunction;
                pVirtualProtect(&(pIATThunk->u1.Function), sizeof(DWORD), lOldProtect, &lOldProtect);
#endif
            }
        }
    }

#define GET_HEADER_DICTIONARY(m, idx) &m->OptionalHeader.DataDirectory[idx]
    unsigned char* codeBase = (unsigned char*)pe.lpBase;
    PIMAGE_TLS_DIRECTORY tls;
    PIMAGE_TLS_CALLBACK* callback;

    PIMAGE_DATA_DIRECTORY directory = GET_HEADER_DICTIONARY(pImageNtHeader, IMAGE_DIRECTORY_ENTRY_TLS);
    if (directory->VirtualAddress == 0) {
        return TRUE;
    }

    tls = (PIMAGE_TLS_DIRECTORY)(codeBase + directory->VirtualAddress);
    callback = (PIMAGE_TLS_CALLBACK*)tls->AddressOfCallBacks;
    if (callback) {
        while (*callback) {
            (*callback)((LPVOID)codeBase, DLL_PROCESS_ATTACH, NULL);
            callback++;
        }
    }

    // User data
    if (param->pUserData) {
        LPVOID* addrForUserData = (LPVOID*)(param->pAddrOfUserData + pe.iBase);
        *addrForUserData = param->pUserData;
    }

    PExeMain pfnModuleEntry = NULL;
    pfnModuleEntry = MakePointer(PExeMain, pe.lpBase, pImageNtHeader->OptionalHeader.AddressOfEntryPoint);
    if (pfnModuleEntry) {
        pfnModuleEntry();
    }
    return TRUE;
};
#endif

bool LoadSelf(HANDLE hProcess, void* userdata, size_t userdataSize)
{
    remote_param lModule;

    // User data
    if (userdata) {
        auto rUserData = VirtualAllocEx(hProcess, NULL, userdataSize, MEM_COMMIT | MEM_RESERVE, PAGE_EXECUTE_READWRITE);
        WriteProcessMemory(hProcess, rUserData, userdata, userdataSize, NULL);
        lModule.pUserData = rUserData;
        lModule.pAddrOfUserData = (PUINT8)((PUINT8)GetUserData() - (PUINT8)GetModuleHandleA(NULL));
    } else {
        lModule.pUserData = nullptr;
    }

    // Prepare parameters
    lModule.pLoadLibraryA = ::LoadLibraryA;
    lModule.pVirtualProtect = ::VirtualProtect;
    lModule.pGetModuleHandleA = ::GetModuleHandleA;
    lModule.pGetProcAddress = ::GetProcAddress;
    GetModuleFileNameA(NULL, lModule.sExePath, MAX_PATH);

    // Write shellcode and parameters
    auto rModule = VirtualAllocEx(hProcess, NULL, sizeof(remote_param), MEM_COMMIT | MEM_RESERVE, PAGE_EXECUTE_READWRITE);
    WriteProcessMemory(hProcess, rModule, &lModule, sizeof(remote_param), NULL);
    auto pRemoteInit = VirtualAllocEx(hProcess, NULL, sizeof(INIT_SHELLCODE), MEM_COMMIT | MEM_RESERVE, PAGE_EXECUTE_READWRITE);
    WriteProcessMemory(hProcess, pRemoteInit, INIT_SHELLCODE, sizeof(INIT_SHELLCODE), NULL);

    // Invoke
    DWORD rResult;
    auto tInit = CreateRemoteThread(hProcess, NULL, 0, (LPTHREAD_START_ROUTINE)pRemoteInit, rModule, 0, NULL);
    WaitForSingleObject(tInit, INFINITE);
    GetExitCodeThread(tInit, &rResult);
    VirtualFreeEx(hProcess, rModule, 0, MEM_RELEASE);
    VirtualFreeEx(hProcess, pRemoteInit, 0, MEM_RELEASE);

    return rResult;
}

void** GetUserData()
{
    static void* userdata = nullptr;
    return &userdata;
}
}