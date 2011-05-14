//----------------------------------------------------------------------------
// registry.h
//
// registry manipulation stuff
//
// Copyright (C) 2011 Neil Butterworth
//----------------------------------------------------------------------------

#ifndef INV_A2P_REGISTRY_H
#define INV_A2P_REGISTRY_H

#include <windows.h>
#include <string>
#include <vector>

class RegPath {

	public:

		RegPath( HKEY root );
		~RegPath();

		unsigned int Count() const;
		std::string At( unsigned int  i ) const;

		bool Find( const std::string & apath ) const;
		bool Add( const std::string & apath );
		bool Remove( const std::string & apath );

	private:

		void SplitPath( const std::string & path );
		void UpdateReg();

		HKEY mRoot, mPathKey;
		typedef std::vector <std::string>  VecType;
		VecType mPath;
};


#endif