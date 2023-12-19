
#pragma once

#ifndef KOCTAGON_H
#define KOCTAGON_H

#include "Mesh.h"

class KOctagon
{
public:
	KOctagon();
	~KOctagon();

	static void createFlatRing(Mesh& mesh, float scale_factor, float distortion);
private:

};

#endif