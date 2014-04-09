#include "BulletOpenGLApplication.h"

#include <bullet/btBulletDynamicsCommon.h>

class BasicDemo: public BulletOpenGLApplication
{
public:
	virtual void InitializePhysics() override;
	virtual void ShutdownPhysics() override;
};
