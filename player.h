//
// JK_Botti - be more human!
//
// player.h
//

#ifndef PLAYER_H
#define PLAYER_H

typedef struct posdata_s 
{
   float time;
   qboolean was_alive;
   qboolean ducking;
   Vector origin;
   Vector velocity;
   //Vector accel;
   
} posdata_t;

// try store max 4sec of position data, server max fps is 100 -> 10ms/frame, 4000ms/10ms = 400
#define POSDATA_SIZE (4000/10)

typedef struct player_s 
{
   edict_t * pEdict;
   
   //int current_weapon_id; // Was only needed for OP4 grapple detection (old method)

   int last_waypoint;

   float last_time_not_facing_wall;
   float last_time_dead;
   
   int posdata_head;
   int posdata_count;
   posdata_t posdata_mem[POSDATA_SIZE];

} player_t;

extern player_t players[32];

#endif
