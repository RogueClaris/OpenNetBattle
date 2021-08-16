#pragma once

#include "bnOverworldPlayerSession.h"
#include "Poco/Buffer.h"
#include "Poco/FileStream.h"
#include "Poco/BinaryWriter.h"
#include "Poco/BinaryReader.h"
#include "../netplay/bnBufferReader.h"
#include "../netplay/bnBufferWriter.h"
#include "../bnBuiltInCards.h"
#include "../bnBuiltInSubchips.h"
#include <vector>


Overworld::PlayerSession Overworld::SessionSaver::LoadGameSession(std::string loadPath)
{
    PlayerSession newSession;
    CardFolderCollection collection;
    std::ifstream in(loadPath+"save.bin", std::ios::binary | std::ios::in);
    if (in.is_open()) {
        // Re-use this local buffer for the entire load method
        char buffer[1024] = { 0 };
        size_t mapname_len = 0;
        in.read((char*)&mapname_len, sizeof(size_t));
        in.read(buffer, mapname_len);
        newSession.mapName = std::string(buffer, mapname_len);

        size_t cash_len = 0;
        in.read((char*)&cash_len, sizeof(size_t));
        in.read(buffer, cash_len);
        newSession.money = std::stoi(string(buffer, cash_len));
        
        size_t mhp_len = 0;
        in.read((char*)&mhp_len, sizeof(size_t));
        in.read(buffer, mhp_len);
        newSession.maxHealth = std::stoi(string(buffer, mhp_len));
        
        size_t health_len = 0;
        in.read((char*)&health_len, sizeof(size_t));
        in.read(buffer, health_len);
        newSession.health = std::stoi(string(buffer, health_len));
        
        size_t x_len = 0;
        in.read((char*)&x_len, sizeof(size_t));
        in.read(buffer, x_len);
        string xStr(buffer);
        newSession.playerPos.x = std::stof(xStr, &x_len);

        size_t y_len = 0;
        in.read((char*)&y_len, sizeof(size_t));
        in.read(buffer, y_len);
        string yStr(buffer);
        newSession.playerPos.y = std::stof(yStr, &y_len);

        size_t z_len = 0;
        in.read((char*)&z_len, sizeof(size_t));
        in.read(buffer, z_len);
        string zStr(buffer);
        newSession.playerPos.z = std::stof(zStr, &z_len);
        
        size_t folderCount = 0;
        in.read((char*)&folderCount, sizeof(size_t));
        in.read(buffer, folderCount);
        int count(folderCount);
        Logger::Logf("%d", count);
        for (auto i = 0; i < count; i++) {
            CardFolder* dummy;
            Battle::Card card;
            size_t name_len = 0;
            in.read((char*)&name_len, sizeof(size_t));
            in.read(buffer, name_len);
            string name(buffer, name_len);
            if (collection.MakeFolder(name)) {
                Logger::Log("Made Folder: " + name);
                if (collection.GetFolder(name, dummy)) {
                    Logger::Log("Got Folder: " + name);
                    for (auto j = 0; j < 30; j++) {
                        size_t len = 0;
                        in.read((char*)&len, sizeof(size_t));
                        in.read(buffer, len);
                        auto uuid = string(buffer, len);
                        uuid[uuid.length()] = '\0';
                        for (auto& [key, value] : BuiltInCards::cardList) {
                            if (value.GetUUID() == uuid) {
                                dummy->AddCard(value);
                            }
                        }
                    }
                }
            }
        }
        newSession.folders = collection;

        size_t pack_len = 0;
        in.read((char*)&pack_len, sizeof(size_t));
        in.read(buffer, pack_len);
        int pack_size = std::stoi(string(buffer, pack_len));
        CHIPLIB.ResetLibrary(); //reset library so as not to duplicate chips on game over > continue.
        for (auto l = 0; l < pack_size; l++) {
            size_t card_name_len = 0;
            in.read((char*)&card_name_len, sizeof(size_t));
            in.read(buffer, card_name_len);
            auto uuid = string(buffer, card_name_len);
            uuid[uuid.length()] = '\0';
            Logger::Log(uuid);
            size_t count_size = 0;
            in.read((char*)&count_size, sizeof(size_t));
            in.read(buffer, count_size);
            string uuid_count_string = string(buffer, count_size);
            uuid_count_string[uuid_count_string.length()] = '\0';
            int uuid_count = std::stoi(uuid_count_string);
            for (auto& [key, value] : BuiltInCards::cardList) {
                if (value.GetUUID() == uuid) {
                    while (CHIPLIB.GetCountOf(value) < uuid_count) {
                        CHIPLIB.AddCard(value);
                    }
                }
            }
        }

        newSession.pack = CHIPLIB;
        auto subchiplist = BuiltInSubchips::SubchipList;
        for (auto subPos = 0; subPos < 4; subPos++) {
            size_t subSize = 0;
            in.read((char*)&subSize, sizeof(size_t));
            in.read(buffer, subSize);
            string subName = string(buffer, subSize);
            
            size_t subSize2 = 0;
            in.read((char*)&subSize2, sizeof(size_t));
            in.read(buffer, subSize2);
            int subCount = std::stoi(string(buffer, subSize2));
            for (auto& value : subchiplist) {
                value.SetAmount(subCount);
            }
        }

        in.close();
    }
    return newSession;
}


bool Overworld::SessionSaver::SaveGameSession(std::string savePath, PlayerSession& sessionToSave) {
    std::ofstream out(savePath+"save.bin", std::ios::binary);
    if (out.is_open()) {
        size_t mapName_len = sessionToSave.mapName.size();
        out.write((char*)&mapName_len, sizeof(size_t));
        out.write(sessionToSave.mapName.c_str(), mapName_len);

        string cashMoney = to_string(sessionToSave.money);
        size_t wallet = cashMoney.size();
        out.write((char*)&wallet, sizeof(size_t));
        out.write(cashMoney.c_str(), wallet);

        string healthBar = to_string(sessionToSave.maxHealth);
        size_t container = healthBar.size();
        out.write((char*)&container, sizeof(size_t));
        out.write(healthBar.c_str(), container);

        string currHp = to_string(sessionToSave.health);
        size_t beep = currHp.size();
        out.write((char*)&beep, sizeof(size_t));
        out.write(currHp.c_str(), beep);

        string xPos = to_string(sessionToSave.playerPos.x);
        size_t xSize = xPos.size();
        out.write((char*)&xSize, sizeof(size_t));
        out.write(xPos.c_str(), xSize);

        string yPos = to_string(sessionToSave.playerPos.y);
        size_t ySize = yPos.size();
        out.write((char*)&ySize, sizeof(size_t));
        out.write(yPos.c_str(), ySize);

        string zPos = to_string(sessionToSave.playerPos.z);
        size_t zSize = zPos.size();
        out.write((char*)&zSize, sizeof(size_t));
        out.write(zPos.c_str(), zSize);

        // Folders
        string fldrs = "folders";
        size_t numOfFolders = sessionToSave.folders.GetFolderOrder().size();
        out.write((char*)&numOfFolders, sizeof(size_t));
        out.write(fldrs.c_str(), numOfFolders);
        std::string name;
        size_t name_len;
        size_t chip_count;
        Battle::Card* card;
        int fldrCount = (int)numOfFolders;
        for (auto i = 0; i < fldrCount; i++) {
            Logger::Log("hi 1");
            CardFolder* dummy;
            if (sessionToSave.folders.GetFolder(i, dummy)) {
                Logger::Log("hi 2");
                name = sessionToSave.folders.GetFolderNames()[i];
                name_len = name.size();
                out.write((char*)&name_len, sizeof(size_t));
                out.write(name.c_str(), name_len);
                chip_count = dummy->GetSize();
                if ((int)chip_count < 30) {
                    continue;
                }
                for (auto j = 0; j < (int)chip_count; j++) {
                    card = dummy->GetCardAt(j);
                    string card_name = card->GetUUID();
                    size_t card_name_len = card_name.length();
                    out.write((char*)&card_name_len, sizeof(size_t));
                    out.write(card_name.c_str(), card_name_len);
                }
            }
        }
        int pack_size = CHIPLIB.GetSize();
        std::map<std::string, int> pack_card_list = CHIPLIB.GetPackList();
        string pack = to_string(pack_card_list.size());
        size_t pack_len = pack.size();
        out.write((char*)&pack_len, sizeof(size_t));
        out.write(pack.c_str(), pack_len);
        for (auto& [key, value] : pack_card_list) {
            string card_name = key;
            size_t card_name_len = card_name.length();
            out.write((char*)&card_name_len, sizeof(size_t));
            out.write(card_name.c_str(), card_name_len);
            string card_amount = to_string(value);
            size_t amount_len = card_amount.length();
            out.write((char*)&amount_len, sizeof(size_t));
            out.write(card_amount.c_str(), amount_len);
        }
        auto subchiplist = BuiltInSubchips::SubchipList;
        for (auto subPos = 0; subPos < 4; subPos++){
            string subchipName = subchiplist[subPos].GetName();
            size_t sub_name_len = subchipName.size();
            out.write((char*)&sub_name_len, sizeof(size_t));
            out.write(subchipName.c_str(), sub_name_len);

            string amount_to_save = to_string(subchiplist[subPos].GetAmount());
            size_t amount_save_len = amount_to_save.size();
            out.write((char*)&amount_save_len, sizeof(size_t));
            out.write(amount_to_save.c_str(), amount_save_len);
        }
        Logger::Log("Game Session was written!");
        out.close();
        return true;
    }
    else {
        Logger::Log("Saving Game Session failed...");
        return false;
    }
};