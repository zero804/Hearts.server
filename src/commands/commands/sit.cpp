#include <stdio.h>
#include <string.h>
#include "../define.h"
#include "../errors.h"
#include "../player.h"
#include "sit.h"

void cSit::Execute( cDescriptor &d, cParam &param )
{
  struct cPlayer *player = d.player;

  if (player == nullptr) return;

  struct cTable *table = player->table;

  if (table == nullptr) {
    d.Socket_Write(PLAYER_NO_TABLE);
    return;
  }

  if (!*param.arguments) {
    table->Stand(d);
    return;
  }

  usINT chair;

  Direction(param.arguments[0], chair);
  if (chair == PLAYER_NOWHERE) {
    d.Socket_Write(TABLE_WRONG_CHAIR);
    return;
  }

  table->Sit(d, chair);
}