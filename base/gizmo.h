#pragma once

class Gizmo{
public:
	Gizmo(){ _parent = NULL; }

	Gizmo* getParent() { return _parent; }
protected:
	Gizmo* _parent;	
};
