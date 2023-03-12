
undefined4 BN_GF2m_mod(undefined4 param_1,undefined4 param_2,int *param_3)

{
  undefined4 uVar1;
  uint uVar2;
  int iVar3;
  int iVar4;
  uint uVar5;
  int iVar6;
  int *piVar7;
  int iVar8;
  uint *puVar9;
  int iVar10;
  int aiStack_30 [7];
  
  iVar3 = param_3[1];
  if (iVar3 == 0) {
LAB_0011e636:
    ERR_put_error(3,0x83,0x6a,"bn_gf2m.c",0x1de);
    return 0;
  }
  iVar10 = iVar3 + -1;
  if (iVar10 < 0) {
    piVar7 = aiStack_30;
  }
  else {
    iVar8 = iVar10 * 0x20 + -1;
    iVar6 = 0;
    puVar9 = (uint *)(*param_3 + iVar3 * 4);
    do {
      puVar9 = puVar9 + -1;
      uVar5 = *puVar9;
      if (uVar5 != 0) {
        iVar4 = iVar8 + 0x20;
        uVar2 = 0x80000000;
        iVar3 = iVar6;
        while( true ) {
          uVar5 = uVar5 & uVar2;
          uVar2 = uVar2 >> 1;
          iVar6 = iVar3;
          if (uVar5 != 0) {
            iVar6 = iVar3 + 1;
            if (iVar3 < 6) {
              aiStack_30[iVar3] = iVar4;
            }
          }
          iVar4 = iVar4 + -1;
          if (iVar8 == iVar4) break;
          uVar5 = *puVar9;
          iVar3 = iVar6;
        }
      }
      iVar10 = iVar10 + -1;
      iVar8 = iVar8 + -0x20;
    } while (iVar10 != -1);
    if (5 < iVar6) {
      if (6 < iVar6) goto LAB_0011e636;
      goto LAB_0011e620;
    }
    piVar7 = aiStack_30 + iVar6;
  }
  *piVar7 = -1;
LAB_0011e620:
  uVar1 = BN_GF2m_mod_arr(param_1,param_2,aiStack_30);
  return uVar1;
}

