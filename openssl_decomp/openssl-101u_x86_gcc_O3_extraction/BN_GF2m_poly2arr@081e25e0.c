
int BN_GF2m_poly2arr(int *param_1,int param_2,int param_3)

{
  int iVar1;
  int iVar2;
  int iVar3;
  uint uVar4;
  uint uVar5;
  int iVar6;
  int iVar7;
  
  iVar2 = param_1[1];
  if (iVar2 != 0) {
    iVar2 = iVar2 + -1;
    if (iVar2 < 0) {
      iVar6 = 0;
    }
    else {
      iVar1 = *param_1;
      iVar6 = 0;
      iVar7 = iVar2 * 0x20 + -1;
      do {
        uVar4 = *(uint *)(iVar1 + iVar2 * 4);
        if (uVar4 != 0) {
          iVar3 = iVar7 + 0x20;
          uVar5 = 0x80000000;
          while( true ) {
            if ((uVar5 & uVar4) != 0) {
              if (iVar6 < param_3) {
                *(int *)(param_2 + iVar6 * 4) = iVar3;
              }
              iVar6 = iVar6 + 1;
            }
            iVar3 = iVar3 + -1;
            uVar5 = uVar5 >> 1;
            if (iVar7 == iVar3) break;
            uVar4 = *(uint *)(iVar1 + iVar2 * 4);
          }
        }
        iVar2 = iVar2 + -1;
        iVar7 = iVar7 + -0x20;
      } while (iVar2 != -1);
    }
    iVar2 = iVar6;
    if (iVar6 < param_3) {
      iVar2 = iVar6 + 1;
      *(undefined4 *)(param_2 + iVar6 * 4) = 0xffffffff;
    }
  }
  return iVar2;
}

