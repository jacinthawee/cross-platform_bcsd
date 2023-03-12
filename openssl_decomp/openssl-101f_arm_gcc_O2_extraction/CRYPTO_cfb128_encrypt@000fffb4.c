
void CRYPTO_cfb128_encrypt
               (byte *param_1,byte *param_2,uint param_3,undefined4 param_4,uint param_5,
               uint *param_6,int param_7,code *param_8)

{
  uint uVar1;
  byte *pbVar2;
  byte bVar3;
  uint uVar4;
  uint uVar5;
  byte *pbVar6;
  uint uVar7;
  int iVar8;
  int iVar9;
  byte *pbVar10;
  uint uVar11;
  uint uVar12;
  byte *pbVar13;
  byte *pbVar14;
  byte *pbVar15;
  bool bVar16;
  bool bVar17;
  bool bVar18;
  bool bVar19;
  bool bVar20;
  bool bVar21;
  
  uVar11 = *param_6;
  if (param_7 == 0) {
    pbVar2 = param_2;
    pbVar6 = param_1;
    if (uVar11 != 0 && param_3 != 0) {
      do {
        param_1 = pbVar6 + 1;
        bVar3 = *pbVar6;
        uVar4 = uVar11 + 1 & 0xf;
        if (uVar4 != 0) {
          uVar4 = 1;
        }
        param_3 = param_3 - 1;
        uVar4 = uVar4 & 1;
        if (param_3 == 0) {
          uVar4 = 0;
        }
        param_2 = pbVar2 + 1;
        *pbVar2 = *(byte *)(param_5 + uVar11) ^ bVar3;
        *(byte *)(param_5 + uVar11) = bVar3;
        uVar11 = uVar11 + 1 & 0xf;
        pbVar2 = param_2;
        pbVar6 = param_1;
      } while (uVar4 != 0);
    }
    if ((((uint)param_1 | (uint)param_2 | param_5) & 3) == 0) {
      uVar4 = param_3;
      pbVar2 = param_1;
      pbVar6 = param_2;
      if (0xf < param_3) {
        do {
          (*param_8)(param_5,param_5,param_4);
          uVar1 = uVar11 + 4;
          uVar5 = uVar11 + 8;
          uVar7 = uVar11 + 0xc;
          if (uVar11 < 0x10) {
            uVar12 = *(uint *)(pbVar2 + uVar11);
            *(uint *)(pbVar6 + uVar11) = *(uint *)(param_5 + uVar11) ^ uVar12;
            *(uint *)(param_5 + uVar11) = uVar12;
            if (uVar1 < 0x10) {
              uVar11 = *(uint *)(pbVar2 + uVar1);
              *(uint *)(pbVar6 + uVar1) = *(uint *)(param_5 + uVar1) ^ uVar11;
              *(uint *)(param_5 + uVar1) = uVar11;
              if (uVar5 < 0x10) {
                uVar11 = *(uint *)(pbVar2 + uVar5);
                *(uint *)(pbVar6 + uVar5) = *(uint *)(param_5 + uVar5) ^ uVar11;
                *(uint *)(param_5 + uVar5) = uVar11;
                if (uVar7 < 0x10) {
                  uVar11 = *(uint *)(pbVar2 + uVar7);
                  *(uint *)(pbVar6 + uVar7) = *(uint *)(param_5 + uVar7) ^ uVar11;
                  *(uint *)(param_5 + uVar7) = uVar11;
                }
              }
            }
          }
          uVar4 = uVar4 - 0x10;
          uVar11 = 0;
          pbVar2 = pbVar2 + 0x10;
          pbVar6 = pbVar6 + 0x10;
        } while (0xf < uVar4);
        uVar11 = 0;
        uVar4 = param_3 - 0x10;
        param_3 = param_3 & 0xf;
        iVar8 = (uVar4 & 0xfffffff0) + 0x10;
        param_2 = param_2 + iVar8;
        param_1 = param_1 + iVar8;
      }
      uVar4 = uVar11;
      if (param_3 != 0) {
        (*param_8)(param_5,param_5,param_4);
        pbVar6 = (byte *)(param_5 + uVar11);
        pbVar14 = param_2 + uVar11;
        pbVar2 = param_1 + uVar11;
        if ((((uint)pbVar14 | (uint)pbVar6 | (uint)pbVar2) & 3) == 0 &&
            ((pbVar2 + 4 <= pbVar6 || pbVar6 + 4 <= pbVar2) &&
            (6 < param_3 &&
            ((pbVar6 + 4 <= pbVar14 || pbVar14 + 4 <= pbVar6) &&
            (pbVar2 + 4 <= pbVar14 || pbVar14 + 4 <= pbVar2))))) {
          iVar8 = 0;
          uVar4 = 0;
          uVar1 = param_3 & 0xfffffffc;
          do {
            uVar5 = *(uint *)(pbVar2 + iVar8);
            uVar4 = uVar4 + 1;
            *(uint *)(pbVar14 + iVar8) = uVar5 ^ *(uint *)(pbVar6 + iVar8);
            *(uint *)(pbVar6 + iVar8) = uVar5;
            iVar8 = iVar8 + 4;
          } while (uVar4 < param_3 >> 2);
          uVar4 = uVar1 + uVar11;
          if (param_3 != uVar1) {
            bVar3 = param_1[uVar4];
            iVar8 = uVar4 + 1;
            param_2[uVar4] = bVar3 ^ *(byte *)(param_5 + uVar4);
            *(byte *)(param_5 + uVar4) = bVar3;
            if (param_3 - 1 != uVar1) {
              bVar3 = param_1[iVar8];
              iVar9 = uVar4 + 2;
              param_2[iVar8] = bVar3 ^ *(byte *)(param_5 + iVar8);
              *(byte *)(param_5 + iVar8) = bVar3;
              if ((param_3 - 1) - uVar1 != 1) {
                bVar3 = param_1[iVar9];
                uVar4 = param_3 + uVar11;
                param_2[iVar9] = *(byte *)(param_5 + iVar9) ^ bVar3;
                *(byte *)(param_5 + iVar9) = bVar3;
                goto LAB_001000bc;
              }
            }
            uVar4 = param_3 + uVar11;
          }
        }
        else {
          uVar4 = param_3 + uVar11;
          do {
            bVar3 = param_1[uVar11];
            param_2[uVar11] = *(byte *)(param_5 + uVar11) ^ bVar3;
            *(byte *)(param_5 + uVar11) = bVar3;
            uVar11 = uVar11 + 1;
          } while (uVar11 != uVar4);
        }
      }
LAB_001000bc:
      *param_6 = uVar4;
      return;
    }
    uVar4 = uVar11;
    if (param_3 != 0) {
      uVar1 = 0;
      do {
        if (uVar11 == 0) {
          (*param_8)(param_5,param_5,param_4);
        }
        bVar3 = param_1[uVar1];
        param_2[uVar1] = *(byte *)(param_5 + uVar11) ^ bVar3;
        uVar1 = uVar1 + 1;
        *(byte *)(param_5 + uVar11) = bVar3;
        uVar11 = uVar11 + 1 & 0xf;
        uVar4 = uVar11;
      } while (uVar1 != param_3);
    }
  }
  else {
    pbVar2 = param_2;
    pbVar6 = param_1;
    if (uVar11 != 0 && param_3 != 0) {
      do {
        uVar4 = uVar11 + 1 & 0xf;
        param_1 = pbVar6 + 1;
        if (uVar4 != 0) {
          uVar4 = 1;
        }
        param_3 = param_3 - 1;
        uVar4 = uVar4 & 1;
        bVar3 = *pbVar6 ^ *(byte *)(param_5 + uVar11);
        if (param_3 == 0) {
          uVar4 = 0;
        }
        *(byte *)(param_5 + uVar11) = bVar3;
        uVar11 = uVar11 + 1 & 0xf;
        param_2 = pbVar2 + 1;
        *pbVar2 = bVar3;
        pbVar2 = param_2;
        pbVar6 = param_1;
      } while (uVar4 != 0);
    }
    if ((((uint)param_1 | (uint)param_2 | param_5) & 3) != 0) {
      if (param_3 != 0) {
        uVar4 = 0;
        do {
          if (uVar11 == 0) {
            (*param_8)(param_5,param_5,param_4);
          }
          bVar3 = param_1[uVar4] ^ *(byte *)(param_5 + uVar11);
          *(byte *)(param_5 + uVar11) = bVar3;
          param_2[uVar4] = bVar3;
          uVar4 = uVar4 + 1;
          uVar11 = uVar11 + 1 & 0xf;
        } while (uVar4 != param_3);
      }
      *param_6 = uVar11;
      return;
    }
    pbVar2 = param_1;
    pbVar6 = param_2;
    uVar4 = param_3;
    if (0xf < param_3) {
      do {
        (*param_8)(param_5,param_5,param_4);
        uVar7 = uVar11 + 4;
        uVar1 = uVar11 + 8;
        uVar5 = uVar11 + 0xc;
        if (uVar11 < 0x10) {
          uVar12 = *(uint *)(param_5 + uVar11) ^ *(uint *)(pbVar2 + uVar11);
          *(uint *)(param_5 + uVar11) = uVar12;
          *(uint *)(pbVar6 + uVar11) = uVar12;
          if (uVar7 < 0x10) {
            uVar11 = *(uint *)(param_5 + uVar7) ^ *(uint *)(pbVar2 + uVar7);
            *(uint *)(param_5 + uVar7) = uVar11;
            *(uint *)(pbVar6 + uVar7) = uVar11;
            if (uVar1 < 0x10) {
              uVar11 = *(uint *)(param_5 + uVar1) ^ *(uint *)(pbVar2 + uVar1);
              *(uint *)(param_5 + uVar1) = uVar11;
              *(uint *)(pbVar6 + uVar1) = uVar11;
              if (uVar5 < 0x10) {
                uVar11 = *(uint *)(param_5 + uVar5) ^ *(uint *)(pbVar2 + uVar5);
                *(uint *)(param_5 + uVar5) = uVar11;
                *(uint *)(pbVar6 + uVar5) = uVar11;
              }
            }
          }
        }
        uVar4 = uVar4 - 0x10;
        uVar11 = 0;
        pbVar2 = pbVar2 + 0x10;
        pbVar6 = pbVar6 + 0x10;
      } while (0xf < uVar4);
      iVar8 = (param_3 - 0x10 & 0xfffffff0) + 0x10;
      param_3 = param_3 & 0xf;
      param_2 = param_2 + iVar8;
      param_1 = param_1 + iVar8;
      uVar11 = 0;
    }
    uVar4 = uVar11;
    if (param_3 != 0) {
      (*param_8)(param_5,param_5,param_4);
      pbVar2 = (byte *)(param_5 + uVar11);
      pbVar13 = param_1 + uVar11;
      pbVar14 = pbVar2 + 4;
      pbVar6 = pbVar13 + 4;
      pbVar15 = param_2 + uVar11;
      bVar19 = pbVar13 <= pbVar14;
      bVar16 = pbVar14 == pbVar13;
      if (bVar19 && !bVar16) {
        bVar19 = pbVar2 <= pbVar6;
        bVar16 = pbVar6 == pbVar2;
      }
      pbVar10 = pbVar15 + 4;
      bVar20 = pbVar13 <= pbVar10;
      bVar17 = pbVar10 == pbVar13;
      if (bVar20 && !bVar17) {
        bVar20 = pbVar15 <= pbVar6;
        bVar17 = pbVar6 == pbVar15;
      }
      bVar21 = pbVar2 <= pbVar10;
      bVar18 = pbVar10 == pbVar2;
      if (bVar21 && !bVar18) {
        bVar21 = pbVar15 <= pbVar14;
        bVar18 = pbVar14 == pbVar15;
      }
      if ((((uint)pbVar13 | (uint)pbVar2 | (uint)pbVar15) & 3) != 0 ||
          (bVar21 && !bVar18 || (param_3 < 7 || (bVar20 && !bVar17 || bVar19 && !bVar16)))) {
        uVar4 = param_3 + uVar11;
        do {
          bVar3 = param_1[uVar11] ^ *(byte *)(param_5 + uVar11);
          *(byte *)(param_5 + uVar11) = bVar3;
          param_2[uVar11] = bVar3;
          uVar11 = uVar11 + 1;
        } while (uVar11 != uVar4);
      }
      else {
        iVar8 = 0;
        uVar4 = 0;
        uVar1 = param_3 & 0xfffffffc;
        do {
          uVar4 = uVar4 + 1;
          uVar5 = *(uint *)(pbVar2 + iVar8);
          uVar7 = *(uint *)(pbVar13 + iVar8);
          *(uint *)(pbVar2 + iVar8) = uVar5 ^ uVar7;
          *(uint *)(pbVar15 + iVar8) = uVar5 ^ uVar7;
          iVar8 = iVar8 + 4;
        } while (uVar4 < param_3 >> 2);
        uVar4 = uVar1 + uVar11;
        if (uVar1 != param_3) {
          iVar8 = uVar4 + 1;
          bVar3 = *(byte *)(param_5 + uVar4) ^ param_1[uVar4];
          *(byte *)(param_5 + uVar4) = bVar3;
          param_2[uVar4] = bVar3;
          if (param_3 - 1 != uVar1) {
            iVar9 = uVar4 + 2;
            bVar3 = param_1[iVar8] ^ *(byte *)(param_5 + iVar8);
            *(byte *)(param_5 + iVar8) = bVar3;
            param_2[iVar8] = bVar3;
            if ((param_3 - 1) - uVar1 != 1) {
              uVar4 = param_3 + uVar11;
              bVar3 = param_1[iVar9] ^ *(byte *)(param_5 + iVar9);
              *(byte *)(param_5 + iVar9) = bVar3;
              param_2[iVar9] = bVar3;
              goto LAB_001001ba;
            }
          }
          uVar4 = param_3 + uVar11;
        }
      }
    }
  }
LAB_001001ba:
  *param_6 = uVar4;
  return;
}

