#ifndef _TABLE_
#define _TABLE_

#include "comm.h"

class cTable {
public:
  cTable(cDescriptor &desc, int f);
  ~cTable();

private:
  cDescriptor *player_desc[4];
  cDescriptor *owner;
  unsigned int table_id;
  unsigned int flags;
  unsigned int player_id[4];
  unsigned int num_players;
  bool muted;
  bool paused;
  time_t expire;

public:
  class cGame *game;

  cPlayer *Player(unsigned int chair);
  unsigned int TableID();
  unsigned int Flags();
  unsigned int Num_Players();
  time_t Expire();
  void Sit(cDescriptor &desc, unsigned int chair);
  void Say(cDescriptor &desc, const char *message);
  void SendAll(const char *format, ... );
  void Send(usINT chair, const char *format, ... );
  void Sat(cDescriptor &desc);
  void Mute();
  void Clear();
  void Pause(bool pause);
  bool Stand(cDescriptor &desc);
  bool PlayerLink(cDescriptor &desc);
  bool Full();
  bool Muted();
  bool Paused();
  bool PlayerSat(cDescriptor &desc);
  usINT Chair(cDescriptor &desc);
  cDescriptor *desc(usINT chair);
};

class cTabList {
public:
  cTabList();
  ~cTabList();

private:
  int num_elem;
  struct sList {
     cTable *elem;
     struct sList *next;
  };
  struct sList *head;

public:
  bool Add(cTable *elem);
  bool Empty(); 
  bool Remove(cTable *elem);
  void Remove_Expired();
  void Play();
  cTable *Search(unsigned int id);
  void List(cDescriptor &desc);
};
#endif // _TABLE_
