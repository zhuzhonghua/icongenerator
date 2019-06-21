#pragma once

class Gizmo{
public:
	Gizmo(){ _parent = NULL; }
	virtual ~Gizmo() {}
	
	Gizmo* getParent() { return _parent; }
	void setParent(Gizmo* p) { _parent = p; }

	void add(Gizmo* g);

	virtual void draw();
protected:
	std::vector<Gizmo*> _members;
	Gizmo* _parent;	
};
