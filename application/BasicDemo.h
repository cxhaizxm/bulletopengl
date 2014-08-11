#include "BulletOpenGLApplication.h"

class BasicDemo: public BulletOpenGLApplication
{
public:
	virtual void InitializePhysics() override;
	virtual void ShutdownPhysics() override;

	void CreateObjects();

	virtual void CollisionEvent(btRigidBody* pBody0, btRigidBody* pBody1)
			override;

protected:
	// our box to lift
	GameObject* m_pBox;

	// a simple trigger volume
	btCollisionObject* m_pTrigger;
};
