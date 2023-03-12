
void idea_set_decrypt_key(IDEA_KEY_SCHEDULE *ek,IDEA_KEY_SCHEDULE *dk)

{
  int iVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  uint (*pauVar5) [6];
  uint (*pauVar6) [6];
  uint (*pauVar7) [6];
  uint (*pauVar8) [6];
  int iVar9;
  int iVar10;
  int iVar11;
  int iVar12;
  
  pauVar5 = ek->data[8];
  uVar3 = (*pauVar5)[0];
  pauVar6 = pauVar5;
  pauVar8 = (uint (*) [6])dk;
  if (uVar3 == 0) goto LAB_004e6a30;
  if (uVar3 == 0) {
    trap(7);
  }
  iVar9 = 0x10001 % (int)uVar3;
  pauVar7 = (uint (*) [6])dk;
  if (iVar9 != 0) goto LAB_004e6ab8;
  do {
    uVar3 = 1;
    pauVar6 = pauVar5;
    pauVar8 = pauVar7;
LAB_004e6a30:
    do {
      (*(uint (*) [6])*pauVar8)[0] = uVar3;
      (*(uint (*) [6])*pauVar8)[1] = -(*(uint (*) [6])*pauVar6)[2] & 0xffff;
      (*(uint (*) [6])*pauVar8)[2] = -(*(uint (*) [6])*pauVar6)[1] & 0xffff;
      uVar3 = (*(uint (*) [6])*pauVar6)[3];
      if (uVar3 == 0) {
LAB_004e6a78:
        (*(uint (*) [6])*pauVar8)[3] = uVar3;
      }
      else {
        if (uVar3 == 0) {
          trap(7);
        }
        iVar9 = 0x10001 % (int)uVar3;
        if (iVar9 == 0) {
          uVar3 = 1;
          goto LAB_004e6a78;
        }
        if (uVar3 == 0) {
          trap(7);
        }
        if (iVar9 == 0) {
          trap(7);
        }
        if (iVar9 == 0) {
          trap(7);
        }
        iVar12 = (int)(uVar3 - (int)uVar3 % iVar9) / iVar9;
        iVar11 = (int)uVar3 % iVar9;
        uVar2 = 1;
        uVar3 = -((0x10001 - iVar9) / (int)uVar3);
        while (iVar11 != 0) {
          if (iVar11 == 0) {
            trap(7);
          }
          iVar10 = iVar9 % iVar11;
          iVar1 = uVar3 * iVar12;
          if (iVar11 == 0) {
            trap(7);
          }
          iVar12 = (iVar9 - iVar10) / iVar11;
          uVar4 = uVar2 - iVar1;
          iVar9 = iVar11;
          iVar11 = iVar10;
          uVar2 = uVar3;
          uVar3 = uVar4;
        }
        if (-1 < (int)uVar3) goto LAB_004e6a78;
        (*pauVar8)[3] = uVar3 + 0x10001;
      }
      if (ek == (IDEA_KEY_SCHEDULE *)pauVar6) {
        uVar4 = dk->data[2];
        uVar2 = dk->data[8][1];
        uVar3 = dk->data[8][2];
        dk->data[2] = dk->data[1];
        dk->data[1] = uVar4;
        dk->data[8][2] = uVar2;
        dk->data[8][1] = uVar3;
        return;
      }
      pauVar5 = pauVar6[-1];
      pauVar7 = pauVar8[1];
      (*pauVar8)[4] = pauVar6[-1][4];
      (*pauVar8)[5] = pauVar6[-1][5];
      uVar3 = (*pauVar5)[0];
      pauVar6 = pauVar5;
      pauVar8 = pauVar7;
    } while (uVar3 == 0);
    if (uVar3 == 0) {
      trap(7);
    }
    iVar9 = 0x10001 % (int)uVar3;
  } while (iVar9 == 0);
LAB_004e6ab8:
  if (uVar3 == 0) {
    trap(7);
  }
  if (iVar9 == 0) {
    trap(7);
  }
  if (iVar9 == 0) {
    trap(7);
  }
  iVar11 = (int)(uVar3 - (int)uVar3 % iVar9) / iVar9;
  uVar2 = 1;
  iVar12 = (int)uVar3 % iVar9;
  uVar3 = -((0x10001 - iVar9) / (int)uVar3);
  while (iVar1 = iVar12, iVar1 != 0) {
    if (iVar1 == 0) {
      trap(7);
    }
    uVar4 = uVar2 - iVar11 * uVar3;
    if (iVar1 == 0) {
      trap(7);
    }
    iVar11 = (iVar9 - iVar9 % iVar1) / iVar1;
    uVar2 = uVar3;
    iVar12 = iVar9 % iVar1;
    iVar9 = iVar1;
    uVar3 = uVar4;
  }
  if ((int)uVar3 < 0) {
    uVar3 = uVar3 + 0x10001;
  }
  goto LAB_004e6a30;
}

