#include "ScriptPCH.h"

class announce_login : public PlayerScript
{
public:
	announce_login() : PlayerScript("announce_login") { }
 
	void OnLogin(Player* player, bool /*loginFirst*/)
	{
		if (player->GetTeam() == ALLIANCE)
				{
			std::ostringstream ss;
			ss  << "|cff0026FF联盟|cffFFD800玩家|cff4CFF00" << player->GetName() << "|cffFFD800已上线！";
			sWorld->SendServerMessage(SERVER_MSG_STRING, ss.str().c_str());
				}
				else
				{
			std::ostringstream ss;
						ss << "|cffFF0000部落|cffFFD800玩家|cff4CFF00" << player->GetName() << "|cffFFD800已上线！" ;
			sWorld->SendServerMessage(SERVER_MSG_STRING, ss.str().c_str());
				}
		}
};
 
void AddSC_announce_login()
{
	new announce_login;
}