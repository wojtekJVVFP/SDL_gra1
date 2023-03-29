23.03.2023 added collision detection of new blocks with the rest
25.03.2023
    - added parent class Entity based on Player class. Player is now inherited from class Entity.
    - class Npc inheritated from class Entity. Added example npc object which moves in CApp_OnLoop function
29.03.2023
    - added function timer to control framerate inside onloop function - it counts time between onloop calls and return true if set time is reached
