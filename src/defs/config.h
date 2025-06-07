#pragma once

//
// Structures related to configuration.
//

typedef enum tag_ST_SPLIT_LIST_MODE
{
        // List contains apps that should be excluded from the tunnel
        ST_SPLIT_LIST_EXCLUDE = 0,

        // List contains apps that should remain inside the tunnel
        ST_SPLIT_LIST_INCLUDE = 1
} ST_SPLIT_LIST_MODE;

typedef struct tag_ST_CONFIGURATION_ENTRY
{
	// Offset into buffer region that follows all entries.
	// The image name uses the device path.
	SIZE_T ImageNameOffset;

	// Byte length for non-null terminated wide char string.
	USHORT ImageNameLength;
}
ST_CONFIGURATION_ENTRY;

typedef struct tag_ST_CONFIGURATION_HEADER
{
        // Number of entries immediately following the header.
        SIZE_T NumEntries;

        // Total byte length: header + entries + string buffer.
        SIZE_T TotalLength;

        // How the image list should be interpreted
        ST_SPLIT_LIST_MODE Mode;
}
ST_CONFIGURATION_HEADER;
