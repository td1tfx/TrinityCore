#include "ScriptMgr.h"
#include "convert.h"

class npc_tool : public CreatureScript
{
public:
npc_tool() : CreatureScript("npc_tool"){}

bool OnGossipHello(Player * pPlayer, Creature * pCreature)
{

pPlayer->ADD_GOSSIP_ITEM(4, AtoU("|cFF009933�����Ӫ|r[�����·���]|cffff0000 ��8000G").c_str(), GOSSIP_SENDER_MAIN, 1);
pPlayer->ADD_GOSSIP_ITEM(4, AtoU("|cFF0033CC�������|r[�����·���]|cffff0000 ��5000G").c_str(), GOSSIP_SENDER_MAIN, 0);
pPlayer->ADD_GOSSIP_ITEM(4, AtoU("|cFF33CCFF����Ա����|r[������]|cffff0000 ��3000G").c_str(), GOSSIP_SENDER_MAIN, 2);
pPlayer->ADD_GOSSIP_ITEM(4, AtoU("|cFF9933CC�����ɫ����|r|cffff0000 ��2000G").c_str(), GOSSIP_SENDER_MAIN, 3);
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
if (Player->HasEnoughMoney(5000 * GOLD)) // �޸�һ��12345���޸ĳ�����Ҫ�������ĵ���ƷID
{
Player->ModifyMoney(-(5000 * GOLD));
Player->SetAtLoginFlag(AT_LOGIN_CHANGE_RACE);
CharacterDatabase.PExecute("UPDATe characters Set at_login = at_login | '128' Where guid = %u", Player->GetGUID());
Player->GetSession()->SendNotification(AtoU("�����ɹ����뷵������ѡ������ٵ���ҷ�ͼ����и���.").c_str());
Player->CLOSE_GOSSIP_MENU();
return true;
}
else
{
Player->GetSession()->SendNotification(AtoU("����û���㹻�Ľ�ҽ��д˲���!��").c_str());
Player->CLOSE_GOSSIP_MENU();
}
break;
case 1:
if (Player->HasEnoughMoney(8000 * GOLD)) // �޸�һ��123���޸ĳ�����Ҫ�������ĵ���ƷID
{
Player->ModifyMoney(-(8000 * GOLD));
Player->SetAtLoginFlag(AT_LOGIN_CHANGE_FACTION);
CharacterDatabase.PExecute("UPDATE characters SET at_login = at_login | '64' WHERE guid = %u", Player->GetGUID());
Player->GetSession()->SendNotification(AtoU("�������ɹ����뷵������ѡ������ٵ���ҷ�ͼ����и���.��").c_str());
Player->CLOSE_GOSSIP_MENU();
return true;
}

else
{
Player->GetSession()->SendNotification(AtoU("����û���㹻�Ľ�ҽ��д˲���!��").c_str());
Player->CLOSE_GOSSIP_MENU();
}
break;
case 2:
if (Player->HasEnoughMoney(3000 * GOLD)) //�޸�һ��152���޸ĳ�����Ҫ�������ĵ���ƷID
{
Player->ModifyMoney(-(3000 * GOLD));
Player->SetAtLoginFlag(AT_LOGIN_CUSTOMIZE);
CharacterDatabase.PExecute("UPDATE characters SET at_login = at_login | '8' WHERE guid = %u", Player->GetGUID());
Player->GetSession()->SendNotification(AtoU("�������ɹ����뷵������ѡ������ٵ���ҷ�ͼ����и���.��").c_str());
Player->CLOSE_GOSSIP_MENU();
return true;
}

else
{
Player->GetSession()->SendNotification(AtoU("����û���㹻�Ľ�ҽ��д˲���!��").c_str());
Player->CLOSE_GOSSIP_MENU();
}
break;
case 3:
if (Player->HasEnoughMoney(2000 * GOLD))
{
 Player->ModifyMoney(-(2000 * GOLD));
 Player->SetAtLoginFlag(AT_LOGIN_RENAME);
 CharacterDatabase.PExecute("UPDATE characters SET at_login = at_login | '8' WHERE guid = %u", Player->GetGUID());
 Player->GetSession()->SendNotification(AtoU("�������ɹ����뷵������ѡ������ٵ��������Ϸ�����Ľ�ɫ��.��").c_str());
 Player->CLOSE_GOSSIP_MENU();
 return true;
}

else
{
Player->GetSession()->SendNotification(AtoU("����û���㹻�Ľ�ҽ��д˲���!��").c_str());
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