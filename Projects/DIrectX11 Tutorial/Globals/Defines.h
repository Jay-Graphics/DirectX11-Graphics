#pragma once

enum class Return
{
	// The function succeded
	SUCCESS = 0xFFFFFFFF,
	// The function failed (Check function documentation for possible reasons)
	FAILURE = 0,
	//  An invalid argument was passed into the function
	INVALID_ARGUMENT = 1, 
	// A memory corruption occurred in the function
	MEMORY_CORRUPTION = 2, 
	// The requested interface is not supported by the object
	INTERFACE_UNSUPPORTED = 3,
	//  A requested file is not found
	FILE_NOT_FOUND = 4, 
	// The requested operation will not do anything
	REDUNDANT_OPERATION = 5, 
	// Attempted an operation that is currently not supported
	FEATURE_UNSUPPORTED = 6, 
};

#define SUCCESS(_return_) (((_return_)) == Return::SUCCESS)
#define FAIL(_return_) (((_return_)) == Return::FAILURE)