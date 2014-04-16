/*
 *   This file is part of bulletopengl.
 *
 *   bulletopengl is free software: you can redistribute it and/or modify
 *   it under the terms of the GNU General Public License as published by
 *   the Free Software Foundation, either version 3 of the License, or
 *   (at your option) any later version.
 *
 *   bulletopengl is distributed in the hope that it will be useful,
 *   but WITHOUT ANY WARRANTY; without even the implied warranty of
 *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *   GNU General Public License for more details.
 *
 *   You should have received a copy of the GNU General Public License
 *   along with bulletopengl.  If not, see <http://www.gnu.org/licenses/>.
 */
/**
 * \file /bulletopengl/application_p3d/BulletLocal/BulletWorld.h
 *
 * \date 16/apr/2014 (18:45:23)
 * \author consultit
 */

#ifndef BULLETWORLD_H_
#define BULLETWORLD_H_

#include <bullet/btBulletCollisionCommon.h>
#include <bullet/btBulletDynamicsCommon.h>

namespace ely
{

class BulletWorld
{
public:
	BulletWorld(btVector3 gravity = btVector3(0.0, -9.81, 0.0));
	virtual ~BulletWorld();

	void stepSimulation(btScalar timeStep, int maxSubSteps = 1,
			btScalar fixedTimeStep = btScalar(1.) / btScalar(60.));

protected:
	///Current underlying DynamicsWorld.
	btDynamicsWorld *dynamicsWorld;
	///collision configuration contains default setup for memory, collision setup. Advanced users can create their own configuration.
	btCollisionConfiguration *mCollisionConfiguration;
	///use the default collision dispatcher. For parallel processing you can use a different dispatcher (see Extras/BulletMultiThreaded)
	btCollisionDispatcher *mCollisionDispatcher;
	///btDbvtBroadphase is a good general purpose broad-phase. You can also try out btAxis3Sweep.
	btBroadphaseInterface* mBroadphaseInterface;
	///the default constraint solver. For parallel processing you can use a different solver (see Extras/BulletMultiThreaded)
	btConstraintSolver *mConstraintSolver;
	///Dynamics World
	btVector3 mGravity;

};

} /* namespace ely */

#endif /* BULLETWORLD_H_ */
