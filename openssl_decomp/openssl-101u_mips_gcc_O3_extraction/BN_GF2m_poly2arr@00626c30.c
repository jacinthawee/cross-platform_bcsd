
int BN_GF2m_poly2arr(int *param_1,int param_2,int param_3)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  int iVar4;
  uint uVar5;
  int iVar6;
  int iVar7;
  
  iVar1 = param_1[1];
  iVar2 = iVar1 + -1;
  if (iVar1 != 0) {
    if (iVar2 < 0) {
      iVar1 = 0;
    }
    else {
      iVar7 = *param_1;
      iVar6 = iVar1 * 4;
      iVar1 = 0;
      iVar6 = iVar7 + iVar6;
      iVar2 = iVar2 * 0x20 + -1;
      do {
        uVar3 = *(uint *)(iVar6 + -4);
        iVar4 = iVar2 + 0x20;
        if (uVar3 != 0) {
          uVar5 = 0x80000000;
          while( true ) {
            if ((uVar5 & uVar3) != 0) {
              if (iVar1 < param_3) {
                *(int *)(param_2 + iVar1 * 4) = iVar4;
              }
              iVar1 = iVar1 + 1;
            }
            iVar4 = iVar4 + -1;
            uVar5 = uVar5 >> 1;
            if (iVar2 == iVar4) break;
            uVar3 = *(uint *)(iVar6 + -4);
          }
        }
        iVar6 = iVar6 + -4;
        iVar2 = iVar2 + -0x20;
      } while (iVar7 != iVar6);
    }
    iVar2 = iVar1 * 4;
    if (iVar1 < param_3) {
      iVar1 = iVar1 + 1;
      *(undefined4 *)(param_2 + iVar2) = 0xffffffff;
    }
  }
  return iVar1;
}

