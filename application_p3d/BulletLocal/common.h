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
 * \file /bulletopengl/application_p3d/BulletLocal/common.h
 *
 * \date 16/apr/2014 (17:08:39)
 * \author consultit
 */

#ifndef BULLETLOCALCOMMON_H_
#define BULLETLOCALCOMMON_H_

#include <nodePath.h>
#include <lquaternion.h>
#include <lvecBase3.h>
#include <bullet/btBulletCollisionCommon.h>

namespace ely
{

// Utility functions
inline btVector3 LVecBase3fTobtVector3(const LVecBase3f& v)
{
	return btVector3(v.get_x(), v.get_z(), -v.get_y());
}
inline LVecBase3f btVector3ToLVecBase3f(const btVector3& v)
{
	return LVecBase3f(v.x(), -v.z(), v.y());
}

inline btQuaternion LQuaternionfTobtQuaternion(const LQuaternionf& q)
{
	return btQuaternion(q.get_i(), q.get_j(), q.get_k(), q.get_r());
}

inline LQuaternionf btQuaternionToLQuaternionf(const btQuaternion& q)
{
	return LQuaternionf(q.w(), q.x(), q.y(), q.z());
}

//Motion states
class DynamicMotionState: public btMotionState
{
public:
	DynamicMotionState(const btTransform &initialpos, NodePath node)
	{
		mVisibleobj = node;
		mPos1 = initialpos;
	}

	virtual ~DynamicMotionState()
	{
	}

	void setNode(NodePath node)
	{
		mVisibleobj = node;
	}

	virtual void getWorldTransform(btTransform &worldTrans) const
	{
		worldTrans = mPos1;
	}

	virtual void setWorldTransform(const btTransform &worldTrans)
	{
		mPos1 = worldTrans;
		if (mVisibleobj.is_empty())
			return; // silently return before we set a node
		mVisibleobj.set_quat(
				btQuaternionToLQuaternionf(worldTrans.getRotation()));
		mVisibleobj.set_pos(btVector3ToLVecBase3f(worldTrans.getOrigin()));
	}

protected:
	NodePath mVisibleobj;
	btTransform mPos1;
};

class KinematicMotionState: public btMotionState
{
public:
	KinematicMotionState(const btTransform &initialpos, NodePath node)
	{
		mVisibleobj = node;
		mPos1 = initialpos;
	}

	virtual ~KinematicMotionState()
	{
	}

	void setNode(NodePath node)
	{
		mVisibleobj = node;
	}

	virtual void getWorldTransform(btTransform &worldTrans) const
	{
		worldTrans = mPos1;
	}

	virtual void setWorldTransform(const btTransform &worldTrans)
	{
		mPos1 = worldTrans;
	}

protected:
	NodePath mVisibleobj;
	btTransform mPos1;
};

} // namespace ely

#endif /* BULLETLOCALCOMMON_H_ */
