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
 * \file /bulletopengl/application_p3d/BulletLocal/BulletWorld.cpp
 *
 * \date 16/apr/2014 (18:45:24)
 * \author consultit
 */

#include "BulletWorld.h"

namespace ely
{

BulletWorld::BulletWorld(btVector3 gravity)
{
	//begin all
	mCollisionConfiguration = new btDefaultCollisionConfiguration();
	mCollisionDispatcher = new btCollisionDispatcher(mCollisionConfiguration);
	mCollisionDispatcher->setDispatcherFlags(
			mCollisionDispatcher->getDispatcherFlags()
					| btCollisionDispatcher::CD_STATIC_STATIC_REPORTED);
	mBroadphaseInterface = new btDbvtBroadphase();
	mConstraintSolver = new btSequentialImpulseConstraintSolver;
	dynamicsWorld = new btDiscreteDynamicsWorld(mCollisionDispatcher,
			mBroadphaseInterface, mConstraintSolver, mCollisionConfiguration);
	mGravity = gravity;
	dynamicsWorld->setGravity(mGravity);
}

BulletWorld::~BulletWorld()
{
	//delete dynamics world
	delete dynamicsWorld;
	//delete constraint solver
	delete mConstraintSolver;
	//delete broadphase
	delete mBroadphaseInterface;
	//delete dispatcher
	delete mCollisionDispatcher;
	//delete configuration
	delete mCollisionConfiguration;
}

} /* namespace ely */
