#ifndef _PLAYER_
#define _PLAYER_

class cPlayer {
public:
  cPlayer();
  ~cPlayer();

public:
  char *handle;
  char *realname;
  char *email;
  char *password;

  char prompt   [MAX_PROMPT_LENGTH];
  char salt     [3];

public:
  void setPassword( const char * p, bool encrypt );
  bool doesPasswordMatch( const char * p );
  bool isHandle( const char * h );
  bool save();
  bool load();
};

#endif // _PLAYER_
