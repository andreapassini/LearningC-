#include <iostream>
#include <vector>

class Collider {
public:
	virtual void f() {
		std::cout << "A";
	}
};

class SphereCollider : public Collider {
public:
	void f() {
		std::cout << "B";
	}
};

int main() {
	std::vector<Collider*> colliders;

	colliders.push_back(new SphereCollider());
	colliders.push_back(new SphereCollider());

	colliders[0]->f();

	//Collider* c = dynamic_cast<Collider*>(&colliders[1]);
	//c->f();
	SphereCollider sp = SphereCollider();
	Collider* col = &sp;
	col->f();
}