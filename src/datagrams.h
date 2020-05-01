#ifndef _DATAGRAMS_
#define _DATAGRAMS_

// Users Datagrams Errors
#define HANDLE_IS_ILLEGAL       "E01" // unused (see: E7)
#define HANDLE_UNAVAILABLE      "E02"
#define HANDLE_RESERVED         "E03"
#define WRONG_PASSWORD          "E04"
#define HANDLE_TOO_SHORT        "E05"
#define HANDLE_TOO_LONG         "E06"
#define HANDLE_ILLEGAL_CHAR     "E07"
#define PASSWORD_TOO_SHORT      "E08"
#define PASSWORD_TOO_LONG       "E09"
#define PASSWORD_DONT_MATCH     "E10"
#define HANDLE_NOT_REGISTERED   "E11"
#define AUTO_LOGOUT_IDLENESS    "E12"
#define UNKNOWN_COMMAND         "E13"
#define SERVER_SHUTOFF          "E14"
#define SERVER_SHUTDOWN         "E15"
#define PLAYER_RECONNECT        "E16"
#define PLAYER_LOAD_FAILED      "E17"
#define SOCKET_FLOOD            "E18"
#define PLAYER_AT_TABLE         "E19"
#define PLAYER_NO_TABLE         "E20"
#define TABLE_WRONG_CHAIR       "E21"
#define PLAYER_SIT_DELAY        "E22"
#define SOCKET_MAX_CONN_IP      "E23"
#define TABLE_NOT_FOUND         "E24"
#define AMBIGOUS_COMMAND        "E25"
#define TABLE_MUTED             "E26"
#define PLAYER_NOT_SAT          "E27"
#define TABLE_NOT_3PASSED       "E28"
#define TABLE_ALREADY_PASSED    "E29"
#define TABLE_ILLEGAL_CARD      "E30"
#define TABLE_CARD_NOT_FOUND    "E31"
#define TABLE_DOUBLE_CARD       "E32"
#define TABLE_PASSING_OVER      "E33"
#define TABLE_STARTED           "E34"
#define TABLE_FULL              "E35"
#define TABLE_NOT_STARTED       "E36"
#define TABLE_NOT_YOUR_TURN     "E37"
#define TABLE_CANT_BREAK_HEART  "E38"
#define TABLE_QUEEN_SPADE       "E39"
#define TABLE_WRONG_SUIT        "E40"
#define SOCKET_MAX_REGISTER_IP  "E41"
#define TABLE_ALREADY_PLAYED    "E42"
#define SOCKET_ILLEGAL_INPUT    "E43"
#define PLAYER_NOT_MOON         "E44"
#define COMMAND_WRONG_PARAMETER "E45"
#define ADMIN_NOT_FOUND         "E46"
#define ADMIN_ABOVE             "E47"
#define TABLE_CORRUPTED         "E48"
#define WRONG_VALUE             "E49"

// Users datagrams Informations
#define PLAYER_UID              "I01"
#define PLAYER_CHOOSE_CHAIR     "I02"
#define PLAYER_SIT_HERE         "I03"
#define PLAYER_STAND            "I04"
#define TABLE_CREATED           "I05"
#define TABLE_DELETED           "I06"
#define TABLE_SAY               "I07"
#define TABLE_YOUR_CARDS        "I08"
#define TABLE_YOUR_TURN         "I09"
//#define SERVER_WHO              "I10"  // unused, using DG_TEXT now
#define TABLE_LEAVE             "I11"
#define TABLE_CARDS_RECEIVED    "I12"
#define TABLE_FORCE_PASS        "I13"
#define TABLE_FORCE_PLAY        "I14"
#define TABLE_PLAY_TWO_CLUBS    "I15"
#define TABLE_PLAY              "I16"
#define TABLE_HAND_SCORE        "I17"
#define TABLE_SCORE             "I18"
#define TABLE_WHO_AM_I          "I19"
#define TABLE_NO_TRICK_BONUS    "I20"
#define TABLE_OMNIBUS           "I21"
#define TABLE_PERFECT_100       "I22"
#define TABLE_SHOOT_MOON        "I23"
#define COMMAND_SET             "I24"
#define TABLE_GAMEOVER          "I25"
#define TABLE_PAUSED            "I26"
#define TABLE_UNPAUSED          "I27"
#define SERVER_ANNOUNCE         "I28"
#define PLAYER_MOON             "I29"
#define TABLE_CLEAR             "I30"
#define ADMIN_SET               "I31"
#define TABLE_SHUFFLE           "I32"
#define GAME_STATS              "I33"
#define PLAYER_NEW_PASSWORD     "I34"
#define GAME_STARTED            "I35"
#define DG_TEXT                 "I36"
#define DG_RECONNECTED          "I37"

// Users Datagrams help commands informations
#define DGI_HELP_DATE           "H01"
#define DGI_HELP_EXIT           "H02"
#define DGI_HELP_HELP           "H03"
#define DGI_HELP_JOIN           "H04"
#define DGI_HELP_LEAVE          "H05"
#define DGI_HELP_MOON           "H06"
#define DGI_HELP_MUTE           "H07"
#define DGI_HELP_NEW            "H08"
#define DGI_HELP_PASS           "H09"
#define DGI_HELP_PASSWORD       "H10"
#define DGI_HELP_PLAY           "H11"
#define DGI_HELP_SAY            "H12"
#define DGI_HELP_SIT            "H13"
#define DGI_HELP_STATS          "H14"
#define DGI_HELP_TABLES         "H15"
#define DGI_HELP_UPTIME         "H16"
#define DGI_HELP_WHO            "H17"

// Admin Datagrams help commands informations
#define DGI_HELP_ADMIN          "H50"
#define DGI_HELP_ANNOUNCE       "H51"
#define DGI_HELP_PAUSE          "H52"
#define DGI_HELP_SET            "H53"
#define DGI_HELP_SHUTDOWN       "H54"
#define DGI_HELP_SHUTOFF        "H55"
#define DGI_HELP_TEST           "H56"

#endif // _DATAGRAMS_
