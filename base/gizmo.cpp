#include "stdafx.h"

#include "gizmo.h"

void Gizmo::add(Gizmo* g)
{
	_members.push_back(g);
}

void Gizmo::draw()
{
	for(std::vector<Gizmo*>::iterator itr = _members.begin();
			itr != _members.end(); itr++)
	{
		(*itr)->draw();
	}
}
