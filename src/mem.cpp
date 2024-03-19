#include "mem.h"
#include "log.h"

#include <string.h>

namespace Fuel {
    static MemoryStats Stats;

    void InitMemory() {
        memset(&Stats, 0, sizeof ( MemoryStats ));
    }

    void ShutdownMemory() {};

    void* Allocate( u64 Size, MemoryTag Tag ) {
        FUEL_ASSET_MSG( Size != 0, "Allocating Memory Block of Size 0" );
        FUEL_ASSET_MSG( Tag != MEMORY_TAG_MAX, "Allocating to MemoryTag MAX" );

        if ( Tag == MEMORY_TAG_UNKNOWN ) {
            FUEL_WARN("Allocating to MemoryTag Unknown...");
        }

        Stats.Allocated += Size;
        Stats.TagAllocation[Tag] += Size;

        return malloc( Size );
    }

    void  Free( void* Block, u64 Size, MemoryTag Tag ) {
        FUEL_ASSET_MSG( Block != nullptr, "Freeing nullptr" );
        FUEL_ASSET_MSG( Size != 0, "Freeing Memory Block of Size 0" );
        FUEL_ASSET_MSG( Tag != MEMORY_TAG_MAX, "Freeing to MemoryTag MAX" );

        if ( Tag == MEMORY_TAG_UNKNOWN ) {
            FUEL_WARN("Freeing from MemoryTag Unknown...");
        }

        Stats.Allocated -= Size;
        Stats.TagAllocation[Tag] -= Size;

        free( Block );
    }


    void* Memset( void* Dest, u8 Value, u64 __n ) {
        FUEL_ASSET_MSG( Dest != nullptr, "Setting nullptr" );
        FUEL_ASSET( __n != 0 );

        return memset( Dest, Value, __n );
    }

    void* Memcpy( void* Dest, void* Src, u64 __n ) {
        FUEL_ASSET_MSG( __n != 0, "Copying 0 Bytes" );
        FUEL_ASSET_MSG( Dest != nullptr, "Copying to nullptr" );
        FUEL_ASSET_MSG( Src != nullptr, "Copying from nullptr" );

        return memcpy( Dest, Src, __n );
    }

    void* Memzero( void* Dest, u64 Size ) {
        FUEL_ASSET_MSG( Dest != nullptr, "Zeroing nullptr" );
        FUEL_ASSET_MSG( Size != 0, "Zeroing 0 Bytes" );

        return memset( Dest, 0, Size );
    }
}