# GameEngineYear2

A lightweight physics engine designed for 2D games, providing essential features for rigid body dynamics and collision detection.
that bounces around.

## Components

### RigidBodyComponent

The `RigidBodyComponent` is responsible for managing the physics properties of an object, such as its mass, velocity, and gravitational effects.

- **Methods**:
  - `RigidBodyComponent()`: Constructor to initialize the rigid body.
  - `void applyForce(GameMath::Vector2 force)`: Applies a force to the rigid body, affecting its velocity.
  - `void clampVelocity(float maxSpeed)`: Ensures the velocity does not exceed a specified maximum speed.
  - `void fixedUpdate(float fixedDeltaTime)`: Updates the position based on velocity and applies gravity.
  - `void resolveCollision(GamePhysics::Collision* collisiondata)`: Handles the resolution of collisions with other objects.

### ColliderComponent

The `ColliderComponent` is the base class for all collider types, providing functionality for collision detection and response.

- **Methods**:
  - `Collision* checkCollision(ColliderComponent* other)`: Checks for a collision with another collider and determines the response.
  - `virtual Collision* checkCollisionCircle(CircleColliderComponent* other) = 0`: Pure virtual function to check collision with a circle collider.
  - `virtual Collision* checkCollisionAABB(AABBColliderComponent* other) = 0`: Pure virtual function to check collision with an AABB collider.
  - `void onCollisionEnter(GamePhysics::Collision* other)`: Called when a collision occurs with another collider.

### AABBColliderComponent

The `AABBColliderComponent` represents an axis-aligned bounding box collider, which is useful for rectangular shapes.

- **Methods**:
  - `AABBColliderComponent(float width, float height)`: Constructor to create an AABB collider with specified dimensions.
  - `float getWidth()`: Returns the width of the collider.
  - `float getHeight()`: Returns the height of the collider.
  - `float getLeft()`: Returns the leftmost position of the collider.
  - `float getRight()`: Returns the rightmost position of the collider.
  - `float getTop()`: Returns the topmost position of the collider.
  - `float getBottom()`: Returns the bottommost position of the collider.
  - `void draw()`: Renders the collider visually in the game (if applicable).
  - `Collision* checkCollisionCircle(CircleColliderComponent* other)`: Checks for collision with a circle collider.
  - `Collision* checkCollisionAABB(AABBColliderComponent* other)`: Checks for collision with another AABB collider.

### CircleColliderComponent

The `CircleColliderComponent` represents a circular collider, suitable for round shapes.

- **Methods**:
  - `CircleColliderComponent(float radius)`: Constructor to create a circular collider with a specified radius.
  - `float getRadius()`: Returns the radius of the collider.
  - `void draw()`: Renders the collider visually in the game (if applicable).
  - `Collision* checkCollisionCircle(CircleColliderComponent* other)`: Checks for collision with another circle collider.
  - `Collision* checkCollisionAABB(AABBColliderComponent* other)`: Checks for collision with an AABB collider.

### Collision Structure

The `Collision` structure holds information about collisions between colliders.

- **Members**:
  - `GameMath::Vector2 normal`: The normal vector of the collision surface.
  - `ColliderComponent* collider`: Pointer to the collider involved in the collision.
  - `GameMath::Vector2 contactPoint`: The point of contact between colliders.
  - `float penetrationDistance`: The distance of penetration between colliders during the collision.

## Conclusion

This physics engine provides a foundation for implementing realistic physics in 2D games, offering flexible colliders and dynamic rigid bodies. It can be easily integrated into game projects to enhance gameplay mechanics and interactions.
1. Clone the repository:
   ```bash
   git clone https://github.com/TheCompindium13/GameEngineYear2.git
