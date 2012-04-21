/*
 * Copyright (C) 2006-2011 ScriptDev2 <http://www.scriptdev2.com/>
 * Copyright (C) 2010-2011 ScriptDev0 <http://github.com/mangos-zero/scriptdev0>
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
 */

#ifndef DEF_DEADMINES_H
#define DEF_DEADMINES_H

enum
{
    MAX_ENCOUNTER           = 4,

    TYPE_RHAHKZOR           = 0,
    TYPE_SNEED              = 1,
    TYPE_GILNID             = 2,
    TYPE_IRON_CLAD_DOOR     = 3,

    INST_SAY_ALARM1         = -1036000,
    INST_SAY_ALARM2         = -1036001,

    GO_FACTORY_DOOR         = 13965,                        // rhahk'zor
    GO_MAST_ROOM_DOOR       = 16400,                        // sneed
    GO_FOUNDRY_DOOR         = 16399,                        // gilnid
    GO_HEAVY_DOOR_1         = 17153,                        // to sneed
    GO_HEAVY_DOOR_2         = 17154,                        // to gilnid
    GO_IRON_CLAD_DOOR       = 16397,
    GO_DEFIAS_CANNON        = 16398,
    GO_SMITE_CHEST          = 144111,                       // use to get correct location of mr.smites equipment changes

    NPC_RHAHKZOR            = 644,
    NPC_SNEED               = 643,
    NPC_GILNID              = 1763,
    NPC_MR_SMITE            = 646,
    NPC_PIRATE              = 657,
    NPC_SQUALLSHAPER        = 1732,
};

class MANGOS_DLL_DECL instance_deadmines : public ScriptedInstance
{
    public:
        instance_deadmines(Map* pMap);

        void Initialize();

        void OnCreatureCreate(Creature* pCreature);
        void OnObjectCreate(GameObject* pGo);

        void OnCreatureDeath(Creature* pCreature);

        void SetData(uint32 uiType, uint32 uiData);
        uint32 GetData(uint32 uiType);

        const char* Save() { return m_strInstData.c_str(); }
        void Load(const char* chrIn);

        void Update(uint32 uiDiff);

    private:
        uint32 m_auiEncounter[MAX_ENCOUNTER];
        std::string m_strInstData;

        uint32 m_uiIronDoorTimer;
};

#endif
