
uint bn_add_part_words(ulong *param_1,ulong *param_2,ulong *param_3,int param_4,int param_5)

{
  uint uVar1;
  int iVar2;
  ulong *puVar3;
  ulong *puVar4;
  int iVar5;
  int iVar6;
  uint uVar7;
  uint uVar8;
  ulong *puVar9;
  ulong *puVar10;
  uint uVar11;
  
  uVar1 = bn_add_words(param_1,param_2,param_3,param_4);
  if (param_5 != 0) {
    puVar10 = param_1 + param_4;
    if (param_5 < 0) {
      puVar4 = param_3 + param_4;
      if (uVar1 == 0) {
LAB_00088fea:
        *puVar10 = *puVar4;
        if (param_5 == -1) {
          return 0;
        }
        do {
          puVar10[1] = puVar4[1];
          if (param_5 == -2) {
            return 0;
          }
          puVar10[2] = puVar4[2];
          if (param_5 == -3) {
            return 0;
          }
          iVar2 = param_5 + 4;
          puVar10[3] = puVar4[3];
          if (iVar2 == 0) {
            return 0;
          }
          puVar4 = puVar4 + 4;
          iVar6 = param_5 + 5;
          puVar10 = puVar10 + 4;
          *puVar10 = *puVar4;
          param_5 = iVar2;
        } while (iVar6 < 0 != SCARRY4(iVar2,1));
        return 0;
      }
      uVar7 = param_3[param_4];
      param_1[param_4] = uVar1 + uVar7;
      uVar1 = (uint)(CARRY4(uVar1,uVar7) != false);
      if (param_5 != -1) {
        uVar7 = puVar4[1];
        puVar10[1] = uVar1 + uVar7;
        uVar1 = (uint)(CARRY4(uVar1,uVar7) != false);
        if (param_5 != -2) {
          iVar2 = -param_5;
          iVar6 = -param_5;
          iVar5 = param_5 + 4;
          puVar3 = puVar4;
          puVar9 = puVar10;
          do {
            uVar7 = puVar3[2];
            puVar9[2] = uVar1 + uVar7;
            uVar1 = (uint)(CARRY4(uVar1,uVar7) != false);
            if (param_5 + 3 < 0 == SCARRY4(param_5,3)) {
              return uVar1;
            }
            uVar7 = puVar3[3];
            puVar10 = puVar9 + 4;
            puVar4 = puVar3 + 4;
            puVar9[3] = uVar1 + uVar7;
            uVar1 = (uint)(CARRY4(uVar1,uVar7) != false);
            param_5 = param_5 + 4;
            if (param_5 == 0) {
              return uVar1;
            }
            if (uVar1 == 0) goto LAB_00088fea;
            uVar1 = count_leading_zeroes(*puVar4 + 1);
            *puVar10 = *puVar4 + 1;
            uVar1 = uVar1 >> 5;
            if (param_5 == iVar5 + (iVar6 - 2U & 0xfffffffc)) {
              return uVar1;
            }
            uVar7 = puVar3[5];
            puVar9[5] = uVar1 + uVar7;
            uVar1 = (uint)(CARRY4(uVar1,uVar7) != false);
            puVar3 = puVar4;
            puVar9 = puVar10;
          } while (param_5 != (iVar2 - 3U & 0xfffffffc) + iVar5);
        }
      }
    }
    else {
      puVar4 = param_2 + param_4;
      if (uVar1 == 0) {
LAB_00088fb6:
        *puVar10 = *puVar4;
        if (param_5 != 1) {
          do {
            puVar10[1] = puVar4[1];
            if (param_5 == 2) {
              return 0;
            }
            puVar10[2] = puVar4[2];
            if (param_5 == 3) {
              return 0;
            }
            param_5 = param_5 + -4;
            puVar10[3] = puVar4[3];
            if (param_5 == 0) {
              return 0;
            }
            puVar4 = puVar4 + 4;
            puVar10 = puVar10 + 4;
            *puVar10 = *puVar4;
          } while (1 < param_5);
        }
        return 0;
      }
      uVar7 = param_2[param_4];
      param_1[param_4] = uVar1 + uVar7;
      uVar1 = (uint)(CARRY4(uVar1,uVar7) != false);
      if (param_5 != 1) {
        uVar7 = puVar4[1];
        puVar10[1] = uVar1 + uVar7;
        uVar1 = (uint)(CARRY4(uVar1,uVar7) != false);
        if (param_5 != 2) {
          uVar11 = param_5 - 3;
          uVar7 = param_5 - 2;
          iVar2 = param_5 + -4;
          puVar3 = puVar4;
          puVar9 = puVar10;
          do {
            uVar8 = puVar3[2];
            puVar9[2] = uVar1 + uVar8;
            uVar1 = (uint)(CARRY4(uVar1,uVar8) != false);
            if (param_5 < 4) {
              return uVar1;
            }
            uVar8 = puVar3[3];
            puVar10 = puVar9 + 4;
            puVar4 = puVar3 + 4;
            puVar9[3] = uVar1 + uVar8;
            uVar1 = (uint)(CARRY4(uVar1,uVar8) != false);
            param_5 = param_5 + -4;
            if (param_5 == 0) {
              return uVar1;
            }
            if (uVar1 == 0) goto LAB_00088fb6;
            uVar1 = count_leading_zeroes(*puVar4 + 1);
            *puVar10 = *puVar4 + 1;
            uVar1 = uVar1 >> 5;
            if (param_5 == iVar2 - (uVar7 & 0xfffffffc)) {
              return uVar1;
            }
            uVar8 = puVar3[5];
            puVar9[5] = uVar1 + uVar8;
            uVar1 = (uint)(CARRY4(uVar1,uVar8) != false);
            puVar3 = puVar4;
            puVar9 = puVar10;
          } while (param_5 != iVar2 - (uVar11 & 0xfffffffc));
        }
      }
    }
  }
  return uVar1;
}

