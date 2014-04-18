#include "BulletOpenGLApplication.h"

class BasicDemo: public BulletOpenGLApplication
{
public:
	virtual void InitializePhysics() override;
	virtual void ShutdownPhysics() override;

	void CreateObjects();
};
