#include "ScriptMgr.h"
#include "convert.h"

class npc_tool : public CreatureScript
{
public:
npc_tool() : CreatureScript("npc_tool"){}

bool OnGossipHello(Player * pPlayer, Creature * pCreature)
{

pPlayer->ADD_GOSSIP_ITEM(4, AtoU("|cFF009933变更阵营|r[含以下服务]|cffff0000 需8000G").c_str(), GOSSIP_SENDER_MAIN, 1);
pPlayer->ADD_GOSSIP_ITEM(4, AtoU("|cFF0033CC变更种族|r[含以下服务]|cffff0000 需5000G").c_str(), GOSSIP_SENDER_MAIN, 0);
pPlayer->ADD_GOSSIP_ITEM(4, AtoU("|cFF33CCFF变更性别外观|r[含改名]|cffff0000 需3000G").c_str(), GOSSIP_SENDER_MAIN, 2);
pPlayer->ADD_GOSSIP_ITEM(4, AtoU("|cFF9933CC变更角色名字|r|cffff0000 需2000G").c_str(), GOSSIP_SENDER_MAIN, 3);
pPlayer->PlayerTalkClass->SendGossipMenu(9425, pCreature->GetGUID());
return true;
}

bool OnGossipSelect(Player * Player, Creature * Creature, uint32 /*uiSender*/, uint32 uiAction)
{
if (!Player)
return true;

switch (uiAction)
{
case 0:
if (Player->HasEnoughMoney(5000 * GOLD)) // 修改一下12345，修改成你需要设置消耗的物品ID
{
Player->ModifyMoney(-(5000 * GOLD));
Player->SetAtLoginFlag(AT_LOGIN_CHANGE_RACE);
CharacterDatabase.PExecute("UPDATe characters Set at_login = at_login | '128' Where guid = %u", Player->GetGUID());
Player->GetSession()->SendNotification(AtoU("操作成功，请返回人物选择界面再点击右方图标进行更改.").c_str());
Player->CLOSE_GOSSIP_MENU();
return true;
}
else
{
Player->GetSession()->SendNotification(AtoU("　你没有足够的金币进行此操作!　").c_str());
Player->CLOSE_GOSSIP_MENU();
}
break;
case 1:
if (Player->HasEnoughMoney(8000 * GOLD)) // 修改一下123，修改成你需要设置消耗的物品ID
{
Player->ModifyMoney(-(8000 * GOLD));
Player->SetAtLoginFlag(AT_LOGIN_CHANGE_FACTION);
CharacterDatabase.PExecute("UPDATE characters SET at_login = at_login | '64' WHERE guid = %u", Player->GetGUID());
Player->GetSession()->SendNotification(AtoU("　操作成功，请返回人物选择界面再点击右方图标进行更改.　").c_str());
Player->CLOSE_GOSSIP_MENU();
return true;
}

else
{
Player->GetSession()->SendNotification(AtoU("　你没有足够的金币进行此操作!　").c_str());
Player->CLOSE_GOSSIP_MENU();
}
break;
case 2:
if (Player->HasEnoughMoney(3000 * GOLD)) //修改一下152，修改成你需要设置消耗的物品ID
{
Player->ModifyMoney(-(3000 * GOLD));
Player->SetAtLoginFlag(AT_LOGIN_CUSTOMIZE);
CharacterDatabase.PExecute("UPDATE characters SET at_login = at_login | '8' WHERE guid = %u", Player->GetGUID());
Player->GetSession()->SendNotification(AtoU("　操作成功，请返回人物选择界面再点击右方图标进行更改.　").c_str());
Player->CLOSE_GOSSIP_MENU();
return true;
}

else
{
Player->GetSession()->SendNotification(AtoU("　你没有足够的金币进行此操作!　").c_str());
Player->CLOSE_GOSSIP_MENU();
}
break;
case 3:
if (Player->HasEnoughMoney(2000 * GOLD))
{
 Player->ModifyMoney(-(2000 * GOLD));
 Player->SetAtLoginFlag(AT_LOGIN_RENAME);
 CharacterDatabase.PExecute("UPDATE characters SET at_login = at_login | '8' WHERE guid = %u", Player->GetGUID());
 Player->GetSession()->SendNotification(AtoU("　操作成功，请返回人物选择界面再点击进入游戏来更改角色名.　").c_str());
 Player->CLOSE_GOSSIP_MENU();
 return true;
}

else
{
Player->GetSession()->SendNotification(AtoU("　你没有足够的金币进行此操作!　").c_str());
Player->CLOSE_GOSSIP_MENU();
}
break;

}
return true;
}
};

void AddSc_npc_tool()
{
new npc_tool();
}