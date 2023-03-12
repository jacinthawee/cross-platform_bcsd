
int BN_GF2m_poly2arr(int *param_1,int param_2,int param_3)

{
  uint uVar1;
  int iVar2;
  uint uVar3;
  int iVar4;
  int iVar5;
  uint *puVar6;
  int iVar7;
  
  iVar2 = param_1[1];
  if (iVar2 != 0) {
    iVar7 = iVar2 + -1;
    if (iVar7 < 0) {
      iVar4 = 0;
    }
    else {
      iVar5 = iVar7 * 0x20 + -1;
      iVar4 = 0;
      puVar6 = (uint *)(*param_1 + iVar2 * 4);
      do {
        puVar6 = puVar6 + -1;
        uVar3 = *puVar6;
        if (uVar3 != 0) {
          iVar2 = iVar5 + 0x20;
          uVar1 = 0x80000000;
          while( true ) {
            uVar3 = uVar3 & uVar1;
            uVar1 = uVar1 >> 1;
            if (uVar3 != 0) {
              if (iVar4 < param_3) {
                *(int *)(param_2 + iVar4 * 4) = iVar2;
              }
              iVar4 = iVar4 + 1;
            }
            iVar2 = iVar2 + -1;
            if (iVar5 == iVar2) break;
            uVar3 = *puVar6;
          }
        }
        iVar7 = iVar7 + -1;
        iVar5 = iVar5 + -0x20;
      } while (iVar7 != -1);
    }
    if (iVar4 < param_3) {
      *(undefined4 *)(param_2 + iVar4 * 4) = 0xffffffff;
      iVar4 = iVar4 + 1;
    }
    return iVar4;
  }
  return 0;
}

