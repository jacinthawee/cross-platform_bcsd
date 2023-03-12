
uint bn_add_part_words(ulong *param_1,ulong *param_2,ulong *param_3,int param_4,int param_5)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  uint *puVar6;
  uint *puVar7;
  uint uVar8;
  uint *puVar9;
  uint *puVar10;
  
  uVar3 = bn_add_words(param_1,param_2,param_3,param_4);
  if (param_5 != 0) {
    puVar10 = param_1 + param_4;
    if (param_5 < 0) {
      puVar7 = param_3 + param_4;
      if (uVar3 == 0) {
LAB_080f7e4f:
        *puVar10 = *puVar7;
        while (((param_5 != -1 && (puVar10[1] = puVar7[1], param_5 != -2)) &&
               (puVar10[2] = puVar7[2], param_5 != -3))) {
          param_5 = param_5 + 4;
          puVar10[3] = puVar7[3];
          if (param_5 == 0) {
            return 0;
          }
          puVar7 = puVar7 + 4;
          puVar10 = puVar10 + 4;
          *puVar10 = *puVar7;
        }
        return 0;
      }
      uVar4 = uVar3 + *puVar7;
      uVar3 = (uint)CARRY4(uVar3,*puVar7);
      *puVar10 = uVar4;
      if (param_5 != -1) {
        uVar4 = uVar3 + puVar7[1];
        uVar3 = (uint)CARRY4(uVar3,puVar7[1]);
        puVar10[1] = uVar4;
        if (param_5 != -2) {
          iVar2 = -param_5;
          iVar1 = param_5 + 4;
          puVar6 = puVar7;
          puVar9 = puVar10;
          do {
            uVar4 = (uint)CARRY4(uVar3,puVar6[2]);
            puVar9[2] = uVar3 + puVar6[2];
            if (-4 < param_5) {
              return uVar4;
            }
            uVar5 = uVar4 + puVar6[3];
            uVar3 = (uint)CARRY4(uVar4,puVar6[3]);
            param_5 = param_5 + 4;
            puVar9[3] = uVar5;
            if (param_5 == 0) {
              return uVar3;
            }
            puVar7 = puVar6 + 4;
            puVar10 = puVar9 + 4;
            if (uVar4 <= uVar5) goto LAB_080f7e4f;
            uVar4 = (uint)CARRY4(uVar3,*puVar7);
            *puVar10 = uVar3 + *puVar7;
            if (param_5 == -1) {
              return uVar4;
            }
            uVar3 = (uint)CARRY4(uVar4,puVar6[5]);
            puVar9[5] = uVar4 + puVar6[5];
            puVar6 = puVar7;
            puVar9 = puVar10;
          } while (iVar1 + (iVar2 - 3U & 0xfffffffc) != param_5);
        }
      }
    }
    else {
      puVar7 = param_2 + param_4;
      if (uVar3 == 0) {
LAB_080f7d7f:
        while( true ) {
          *puVar10 = *puVar7;
          if (param_5 == 1) {
            return 0;
          }
          puVar10[1] = puVar7[1];
          if (param_5 == 2) {
            return 0;
          }
          puVar10[2] = puVar7[2];
          if (param_5 == 3) {
            return 0;
          }
          param_5 = param_5 + -4;
          puVar10[3] = puVar7[3];
          if (param_5 == 0) break;
          puVar7 = puVar7 + 4;
          puVar10 = puVar10 + 4;
        }
        return 0;
      }
      uVar4 = uVar3 + *puVar7;
      uVar3 = (uint)CARRY4(uVar3,*puVar7);
      *puVar10 = uVar4;
      if (param_5 != 1) {
        uVar4 = uVar3 + puVar7[1];
        uVar3 = (uint)CARRY4(uVar3,puVar7[1]);
        puVar10[1] = uVar4;
        if (param_5 != 2) {
          uVar4 = param_5 - 3;
          iVar1 = param_5 + -4;
          puVar6 = puVar7;
          puVar9 = puVar10;
          do {
            uVar5 = (uint)CARRY4(uVar3,puVar6[2]);
            puVar9[2] = uVar3 + puVar6[2];
            if (param_5 < 4) {
              return uVar5;
            }
            uVar8 = uVar5 + puVar6[3];
            uVar3 = (uint)CARRY4(uVar5,puVar6[3]);
            param_5 = param_5 + -4;
            puVar9[3] = uVar8;
            if (param_5 == 0) {
              return uVar3;
            }
            puVar7 = puVar6 + 4;
            puVar10 = puVar9 + 4;
            if (uVar5 <= uVar8) goto LAB_080f7d7f;
            uVar5 = (uint)CARRY4(uVar3,*puVar7);
            *puVar10 = uVar3 + *puVar7;
            if (param_5 == 1) {
              return uVar5;
            }
            uVar3 = (uint)CARRY4(uVar5,puVar6[5]);
            puVar9[5] = uVar5 + puVar6[5];
            puVar6 = puVar7;
            puVar9 = puVar10;
          } while (param_5 != iVar1 - (uVar4 & 0xfffffffc));
        }
      }
    }
  }
  return uVar3;
}

