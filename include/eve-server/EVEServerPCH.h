/*
    ------------------------------------------------------------------------------------
    LICENSE:
    ------------------------------------------------------------------------------------
    This file is part of EVEmu: EVE Online Server Emulator
    Copyright 2006 - 2011 The EVEmu Team
    For the latest information visit http://evemu.org
    ------------------------------------------------------------------------------------
    This program is free software; you can redistribute it and/or modify it under
    the terms of the GNU Lesser General Public License as published by the Free Software
    Foundation; either version 2 of the License, or (at your option) any later
    version.

    This program is distributed in the hope that it will be useful, but WITHOUT
    ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS
    FOR A PARTICULAR PURPOSE. See the GNU Lesser General Public License for more details.

    You should have received a copy of the GNU Lesser General Public License along with
    this program; if not, write to the Free Software Foundation, Inc., 59 Temple
    Place - Suite 330, Boston, MA 02111-1307, USA, or go to
    http://www.gnu.org/copyleft/lesser.txt.
    ------------------------------------------------------------------------------------
    Author:     Zhur
*/

#ifndef __EVE_SERVER_PCH_H__INCL__
#define __EVE_SERVER_PCH_H__INCL__

#include "common.h"

/************************************************************************/
/* dep includes                                                         */
/************************************************************************/
#include <Base64.h>

#include <GaPreReqs.h>
#include <GaMath.h>
#include <GaTypes.h>

#include <mysql.h>

#include <tinyxml.h>

#include <utf8.h>

/************************************************************************/
/* common includes                                                      */
/************************************************************************/
#include "database/dbcore.h"

#include "log/LogNew.h"
#include "log/logsys.h"

#include "network/StreamPacketizer.h"
#include "network/TCPConnection.h"
#include "network/TCPServer.h"

#include "threading/Mutex.h"

#include "utils/crc32.h"
#include "utils/Deflate.h"
#include "utils/EvilNumber.h"
#include "utils/gpoint.h"
#include "utils/misc.h"
#include "utils/RefPtr.h"
#include "utils/Seperator.h"
#include "utils/timer.h"
#include "utils/utils_time.h"
#include "utils/utils_string.h"
#include "utils/XMLParserEx.h"

/************************************************************************/
/* eve-common includes                                                  */
/************************************************************************/
#include "EVEVersion.h"

#include "cache/CachedObjectMgr.h"

#include "database/EVEDBUtils.h"

#include "destiny/DestinyBinDump.h"
#include "destiny/DestinyStructs.h"

#include "network/EVETCPConnection.h"
#include "network/EVETCPServer.h"
#include "network/EVEPktDispatch.h"
#include "network/EVESession.h"

#include "marshal/EVEMarshal.h"
#include "marshal/EVEMarshalOpcodes.h"
#include "marshal/EVEMarshalStringTable.h"
#include "marshal/EVEUnmarshal.h"

#include "packets/AccountPkts.h"
#include "packets/CorporationPkts.h"
#include "packets/Crypto.h"
#include "packets/Character.h"
#include "packets/Destiny.h"
#include "packets/DogmaIM.h"
#include "packets/General.h"
#include "packets/Inventory.h"
#include "packets/Wallet.h"
#include "packets/Missions.h"
#include "packets/Language.h"
#include "packets/LSCPkts.h"
#include "packets/Manufacturing.h"
#include "packets/ObjectCaching.h"
#include "packets/Market.h"
#include "packets/Standing2.h"
#include "packets/Trade.h"
#include "packets/Tutorial.h"

#include "python/PyVisitor.h"
#include "python/PyRep.h"
#include "python/PyPacket.h"
#include "python/PyDumpVisitor.h"
#include "python/PyLookupDump.h"
#include "python/PyXMLGenerator.h"

#include "python/classes/PyDatabase.h"
#include "python/classes/PyExceptions.h"
#include "python/classes/PyUtils.h"

#include "tables/invCategories.h"
#include "tables/invGroups.h"

#include "utils/EVEUtils.h"
#include "utils/EvilNumber.h"


/************************************************************************/
/* eve-server includes                                                  */
/************************************************************************/
#include "Client.h"
#include "ClientSession.h"
#include "EntityList.h"
#include "EVEServerConfig.h"
#include "NetService.h"
#include "PyBoundObject.h"
#include "PyCallable.h"
#include "PyServiceCD.h"
#include "PyServiceMgr.h"

#include "account/AccountDB.h"
#include "account/AccountService.h"
#include "account/AuthService.h"
#include "account/ClientStatMgrService.h"
#include "account/UserService.h"

#include "admin/AlertService.h"
#include "admin/AllCommands.h"
#include "admin/CommandDispatcher.h"
#include "admin/CommandDB.h"
#include "admin/PetitionerService.h"
#include "admin/SlashService.h"

// client object cache stuff
#include "cache/ObjCacheService.h"
#include "cache/ObjCacheDB.h"

// character stuff
#include "character/CertificateMgrDB.h"
#include "character/CertificateMgrService.h"
#include "character/Character.h"
#include "character/CharacterAppearance_fields.h"
#include "character/CharacterDB.h"
#include "character/CharacterService.h"
#include "character/CharMgrService.h"
#include "character/Skill.h"
#include "character/SkillMgrService.h"

// chat stuff
#include "chat/kenny.h"
#include "chat/LookupService.h"
#include "chat/LSCChannel.h"
#include "chat/LSCDB.h"
#include "chat/LSCService.h"
#include "chat/OnlineStatusService.h"
#include "chat/VoiceMgrService.h"

// server config stuff
#include "config/ConfigDB.h"
#include "config/ConfigService.h"
#include "config/LanguageService.h"

// corporation stuff
#include "corporation/CorpMgrService.h"
#include "corporation/CorporationCarrier.h"
#include "corporation/CorporationDB.h"
#include "corporation/CorporationService.h"
#include "corporation/CorpRegistryService.h"
#include "corporation/CorpStationMgrService.h"
#include "corporation/LPService.h"

// dogma crap dono what this is
#include "dogmaim/DogmaIMDB.h"
#include "dogmaim/DogmaIMService.h"

// item stuff
#include "inventory/AttributeEnum.h"
#include "inventory/AttributeMgr.h"
#include "inventory/EVEAttributeMgr.h"
#include "inventory/InvBrokerService.h"
#include "inventory/Inventory.h"
#include "inventory/InventoryDB.h"
#include "inventory/InventoryItem.h"
#include "inventory/ItemDB.h"
#include "inventory/ItemFactory.h"
#include "inventory/ItemRef.h"
#include "inventory/ItemType.h"
#include "inventory/Owner.h"

// factory stuff
#include "manufacturing/Blueprint.h"
#include "manufacturing/FactoryDB.h"
#include "manufacturing/FactoryService.h"
#include "manufacturing/RamProxyDB.h"
#include "manufacturing/RamProxyService.h"

//services:
#include "missions/AgentMgrService.h"
#include "missions/MissionMgrService.h"
#include "missions/Agent.h"
#include "missions/MissionDB.h"

#include "mining/Asteroid.h"
#include "mining/AsteroidBeltManager.h"
#include "mining/MiningDB.h"
#include "mining/ReprocessingDB.h"
#include "mining/ReprocessingService.h"

#include "map/MapDB.h"
#include "map/MapService.h"

#include "market/BillMgrService.h"
#include "market/Contract.h"
#include "market/ContractDB.h"
#include "market/ContractManager.h"
#include "market/ContractMgrService.h"
#include "market/MarketDB.h"
#include "market/MarketProxyService.h"

#include "posmgr/PosMgrDB.h"
#include "posmgr/PosMgrService.h"
#include "posmgr/Structure.h"

#include "npc/NPC.h"
#include "npc/NPCAI.h"

#include "system/BookmarkDB.h"
#include "system/BookmarkService.h"
#include "system/BubbleManager.h"
#include "system/Celestial.h"
#include "system/Container.h"
#include "system/Deployable.h"
#include "system/Damage.h"
#include "system/DungeonService.h"
#include "system/KeeperService.h"
#include "system/ScenarioService.h"
#include "system/SolarSystem.h"
#include "system/SystemBubble.h"
#include "system/SystemDB.h"
#include "system/SystemEntities.h"
#include "system/SystemEntity.h"
#include "system/SystemManager.h"

#include "ship/ModuleManager.h"
#include "ship/BeyonceService.h"
#include "ship/DestinyManager.h"
#include "ship/Drone.h"
#include "ship/InsuranceService.h"
#include "ship/Ship.h"
#include "ship/ShipDB.h"
#include "ship/ShipService.h"
#include "ship/TargetManager.h"
#include "ship/dgmtypeattributeinfo.h"

#include "spawn/SpawnDB.h"
#include "spawn/SpawnManager.h"

#include "standing/FactionWarMgrDB.h"
#include "standing/FactionWarMgrService.h"
#include "standing/Standing2Service.h"
#include "standing/StandingDB.h"
#include "standing/WarRegistryService.h"

#include "station/JumpCloneService.h"
#include "station/Station.h"
#include "station/StationDB.h"
#include "station/StationService.h"
#include "station/StationSvcService.h"

#include "trade/TradeService.h"
#include "trade/TradeDB.h"

#include "tutorial/TutorialDB.h"
#include "tutorial/TutorialService.h"

#endif//__EVE_SERVER_PCH_H__INCL__
