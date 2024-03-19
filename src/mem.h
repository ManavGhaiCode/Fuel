#ifndef _FUEL_MEME_H_
#define _FUEL_MEME_H_

#include "config.h"

namespace Fuel {
    typedef enum {
        MEMORY_TAG_UNKNOWN,

        MEMORY_TAG_ARRAY,
        MEMORY_TAG_DARRAY,
        MEMORU_TAG_STRING,
        MEMORY_TAG_MAP,
        MEMORY_TAG_SET,
        MEMORY_TAG_BST,
        MEMORY_TAG_LIST,
        MEMORY_TAG_QUEUE,
        MEMORY_TAG_BTREE,
        MEMORY_TAG_SHADER,
        MEMORY_TAG_TEXTURE,
        MEMORY_TAG_MATERIAL,
        MEMORY_TAG_GAME,
        MEMORY_TAG_ENGINE,

        MEMORY_TAG_MAX
    } MemoryTag;

    struct MemoryStats {
        u64 Allocated;
        u64 TagAllocation[ MEMORY_TAG_MAX ];
    };

    void InitMemory();
    void ShutdownMemory();

    void* Allocate( u64 Size, MemoryTag Tag );
    void  Free( void* Block, u64 Size, MemoryTag Tag );

    void* Memset( void* Dest, u8 Value, u64 __n );
    void* Memcpy( void* Dest, void* Src, u64 __n );
    void* Memzero( void* Dest, u64 Size );
}

#endif // _FUEL_MEME_H_