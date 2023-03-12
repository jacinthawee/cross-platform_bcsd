
ulong bn_add_part_words(ulong *param_1,ulong *param_2,ulong *param_3,int param_4,int param_5)

{
  bool bVar1;
  ulong uVar2;
  uint uVar3;
  uint uVar4;
  uint *puVar5;
  uint *puVar6;
  uint *puVar7;
  uint *puVar8;
  uint uVar9;
  int iVar10;
  int iVar11;
  
  uVar2 = bn_add_words(param_1,param_2,param_3,param_4);
  if (param_5 != 0) {
    puVar6 = param_1 + param_4;
    if (param_5 < 0) {
      puVar8 = param_3 + param_4;
      if (uVar2 == 0) {
LAB_004f4f20:
        *puVar6 = *puVar8;
        if (param_5 == -1) {
          return 0;
        }
        puVar6[1] = puVar8[1];
        if (param_5 == -2) {
          return 0;
        }
        puVar6[2] = puVar8[2];
        if (param_5 == -3) {
          return 0;
        }
        puVar6[3] = puVar8[3];
        while( true ) {
          param_5 = param_5 + 4;
          if (param_5 == 0) {
            return 0;
          }
          puVar6[4] = puVar8[4];
          if (param_5 == -1) {
            return 0;
          }
          puVar6[5] = puVar8[5];
          if (param_5 == -2) {
            return 0;
          }
          puVar6[6] = puVar8[6];
          if (param_5 == -3) break;
          puVar6[7] = puVar8[7];
          puVar6 = puVar6 + 4;
          puVar8 = puVar8 + 4;
        }
        return 0;
      }
      uVar4 = uVar2 + *puVar8;
      uVar2 = (ulong)(uVar4 < uVar2);
      *puVar6 = uVar4;
      if (param_5 != -1) {
        uVar4 = uVar2 + puVar8[1];
        uVar2 = (ulong)(uVar4 < uVar2);
        puVar6[1] = uVar4;
        if (param_5 != -2) {
          iVar10 = param_5 + 4;
          iVar11 = -param_5;
          puVar5 = puVar6;
          puVar7 = puVar8;
          do {
            bVar1 = -4 < param_5;
            param_5 = param_5 + 4;
            uVar4 = (uint)(uVar2 + puVar7[2] < uVar2);
            puVar5[2] = uVar2 + puVar7[2];
            if (bVar1) {
              return uVar4;
            }
            puVar6 = puVar5 + 4;
            puVar8 = puVar7 + 4;
            uVar3 = (uint)(uVar4 + puVar7[3] < uVar4);
            puVar5[3] = uVar4 + puVar7[3];
            if (param_5 == 0) {
              return uVar3;
            }
            if (uVar3 == 0) goto LAB_004f4f20;
            uVar4 = (uint)(uVar3 + *puVar8 < uVar3);
            *puVar6 = uVar3 + *puVar8;
            if (param_5 == -1) {
              return uVar4;
            }
            uVar2 = (ulong)(uVar4 + puVar7[5] < uVar4);
            puVar5[5] = uVar4 + puVar7[5];
            puVar5 = puVar6;
            puVar7 = puVar8;
          } while ((iVar11 - 3U & 0xfffffffc) + iVar10 != param_5);
        }
      }
    }
    else {
      puVar8 = param_2 + param_4;
      if (uVar2 == 0) {
LAB_004f4da4:
        *puVar6 = *puVar8;
        if (((param_5 != 1) && (puVar6[1] = puVar8[1], param_5 != 2)) &&
           (puVar6[2] = puVar8[2], param_5 != 3)) {
          puVar6[3] = puVar8[3];
          while (param_5 = param_5 + -4, param_5 != 0) {
            puVar6[4] = puVar8[4];
            if (param_5 == 1) {
              return 0;
            }
            puVar6[5] = puVar8[5];
            if (param_5 == 2) {
              return 0;
            }
            puVar6[6] = puVar8[6];
            if (param_5 == 3) {
              return 0;
            }
            puVar6[7] = puVar8[7];
            puVar6 = puVar6 + 4;
            puVar8 = puVar8 + 4;
          }
        }
        return 0;
      }
      uVar4 = uVar2 + *puVar8;
      uVar2 = (ulong)(uVar4 < uVar2);
      *puVar6 = uVar4;
      if (param_5 != 1) {
        uVar4 = uVar2 + puVar8[1];
        uVar2 = (ulong)(uVar4 < uVar2);
        puVar6[1] = uVar4;
        if (param_5 != 2) {
          uVar4 = param_5 - 3;
          iVar11 = param_5 + -4;
          puVar5 = puVar6;
          puVar7 = puVar8;
          do {
            bVar1 = param_5 < 4;
            param_5 = param_5 + -4;
            uVar3 = (uint)(uVar2 + puVar7[2] < uVar2);
            puVar5[2] = uVar2 + puVar7[2];
            if (bVar1) {
              return uVar3;
            }
            puVar6 = puVar5 + 4;
            puVar8 = puVar7 + 4;
            uVar9 = (uint)(uVar3 + puVar7[3] < uVar3);
            puVar5[3] = uVar3 + puVar7[3];
            if (param_5 == 0) {
              return uVar9;
            }
            if (uVar9 == 0) goto LAB_004f4da4;
            uVar3 = (uint)(uVar9 + *puVar8 < uVar9);
            *puVar6 = uVar9 + *puVar8;
            if (param_5 == 1) {
              return uVar3;
            }
            uVar2 = (ulong)(uVar3 + puVar7[5] < uVar3);
            puVar5[5] = uVar3 + puVar7[5];
            puVar5 = puVar6;
            puVar7 = puVar8;
          } while (param_5 != iVar11 - (uVar4 & 0xfffffffc));
        }
      }
    }
  }
  return uVar2;
}

