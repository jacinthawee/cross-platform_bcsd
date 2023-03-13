
void idea_set_decrypt_key(IDEA_KEY_SCHEDULE *ek,IDEA_KEY_SCHEDULE *dk)

{
  uint (*pauVar1) [6];
  int iVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  uint uVar8;
  uint (*local_18) [6];
  
  local_18 = (uint (*) [6])dk;
  pauVar1 = ek->data[8];
  while( true ) {
    uVar7 = (*(uint (*) [6])*pauVar1)[0];
    uVar5 = uVar7;
    if (uVar7 != 0) {
      uVar4 = (uint)(0x10001 % (longlong)(int)uVar7);
      uVar5 = 1;
      if (uVar4 != 0) {
        iVar2 = (int)(0x10001 - uVar4) / (int)uVar7;
        uVar6 = 0;
        uVar8 = 1;
        do {
          uVar3 = uVar4;
          uVar5 = uVar6 - iVar2 * uVar8;
          uVar4 = (int)uVar7 % (int)uVar3;
          iVar2 = (int)(uVar7 - uVar4) / (int)uVar3;
          uVar6 = uVar8;
          uVar7 = uVar3;
          uVar8 = uVar5;
        } while (uVar4 != 0);
        if ((int)uVar5 < 0) {
          uVar5 = uVar5 + 0x10001;
        }
      }
    }
    (*(uint (*) [6])*local_18)[0] = uVar5;
    (*(uint (*) [6])*local_18)[1] = -(*(uint (*) [6])*pauVar1)[2] & 0xffff;
    (*(uint (*) [6])*local_18)[2] = -(*(uint (*) [6])*pauVar1)[1] & 0xffff;
    uVar7 = (*(uint (*) [6])*pauVar1)[3];
    uVar5 = uVar7;
    if (uVar7 != 0) {
      uVar4 = (uint)(0x10001 % (longlong)(int)uVar7);
      uVar5 = 1;
      if (uVar4 != 0) {
        iVar2 = (int)(0x10001 - uVar4) / (int)uVar7;
        uVar6 = 0;
        uVar8 = 1;
        do {
          uVar3 = uVar4;
          uVar5 = uVar6 - iVar2 * uVar8;
          uVar4 = (int)uVar7 % (int)uVar3;
          iVar2 = (int)(uVar7 - uVar4) / (int)uVar3;
          uVar6 = uVar8;
          uVar7 = uVar3;
          uVar8 = uVar5;
        } while (uVar4 != 0);
        if ((int)uVar5 < 0) {
          uVar5 = uVar5 + 0x10001;
        }
      }
    }
    (*(uint (*) [6])*local_18)[3] = uVar5;
    if (ek == (IDEA_KEY_SCHEDULE *)pauVar1) break;
    (*local_18)[4] = pauVar1[-1][4];
    (*local_18)[5] = pauVar1[-1][5];
    pauVar1 = pauVar1[-1];
    local_18 = local_18[1];
  }
  uVar7 = dk->data[1];
  dk->data[1] = dk->data[2];
  dk->data[2] = uVar7;
  uVar7 = dk->data[8][1];
  dk->data[8][1] = dk->data[8][2];
  dk->data[8][2] = uVar7;
  return;
}

