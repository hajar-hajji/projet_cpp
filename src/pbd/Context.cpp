#include "pbd/Context.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include <math.h>

// ------------------------------------------------

Context::Context(int capacity)
{
  this->m_num_particles = 0;
  this->m_particles = new Particle[capacity];
}

// ------------------------------------------------

void Context::addParticle(Vec2 world_pos,
  float radius, float mass,
  Vec2 velocity, int draw_id)
  
  {
    this->m_particles[this->m_num_particles] = Particle {
  world_pos,{},velocity, radius, mass, draw_id};
this->m_num_particles++;
  }

void Context::updatePhysicalSystem(float dt, int num_constraint_relaxation)
{
#define FIXED_VELOCITY
#ifdef FIXED_VELOCITY
for (int i=0;i<m_num_particles;i++)
{
  this->m_particles[i].position.x+=dt*this->m_particles[i].velocity.x;
  this->m_particles[i].position.y+=dt*this->m_particles[i].velocity.y;
}  // TODO For testing purposes, add an update of position based on particle velocity
#else
  applyExternalForce(dt);
  dampVelocities();
  updateExpectedPosition(dt);
  addDynamicContactConstraints();
  addStaticContactConstraints();
 
  for(int k=0; k<num_constraint_relaxation; ++k) {
    projectConstraints();
  }

  updateVelocityAndPosition(dt);
  applyFriction();

  deleteContactConstraints();
#endif
}

// ------------------------------------------------

void Context::applyExternalForce(float dt)
{
}

void Context::dampVelocities()
{
}

void Context::updateExpectedPosition(float dt)
{
}

void Context::addDynamicContactConstraints()
{
}

void Context::addStaticContactConstraints()
{
}

void Context::projectConstraints()
{
}

void Context::updateVelocityAndPosition(float dt)
{
}

void Context::applyFriction()
{
}

void Context::deleteContactConstraints()
{
}

// ------------------------------------------------
