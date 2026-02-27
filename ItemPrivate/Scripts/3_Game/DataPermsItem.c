class PlayerSVIP {
    string m_TypeVIP;
    ref array<ref PlayerActiveVIP> m_Players = new ref array<ref PlayerActiveVIP>;	
    ref array<string> m_ItemsPrivate = new ref array<string>;	
};

class PlayerActiveVIP {
    string m_Nickname;
    string m_SteamID;
    string m_DateExpired;	

    void PlayerActiveVIP(string nickname, string steamID, string dateExpired){
        m_Nickname = nickname;
        m_SteamID = steamID;
        m_DateExpired = dateExpired;		
	}	 
}; 
