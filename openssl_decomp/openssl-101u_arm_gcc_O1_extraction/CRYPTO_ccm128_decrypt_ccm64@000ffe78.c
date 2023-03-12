
void CRYPTO_ccm128_decrypt_ccm64
               (byte *param_1,uint *param_2,uint *param_3,uint param_4,code *param_5)

{
  byte bVar1;
  byte bVar2;
  ushort uVar3;
  uint3 uVar4;
  byte bVar5;
  int iVar6;
  uint uVar7;
  int iVar8;
  byte *pbVar9;
  uint *puVar10;
  uint uVar11;
  uint uVar12;
  uint uVar13;
  code *pcVar14;
  undefined4 uVar15;
  uint uVar16;
  int iVar17;
  uint uVar18;
  uint uVar19;
  bool bVar20;
  bool bVar21;
  undefined4 *local_5c;
  uint *local_44;
  undefined4 local_40;
  uint local_3c;
  uint local_38;
  uint local_34;
  int local_2c;
  
  pcVar14 = *(code **)(param_1 + 0x28);
  bVar1 = *param_1;
  uVar15 = *(undefined4 *)(param_1 + 0x2c);
  local_2c = __stack_chk_guard;
  if ((bVar1 & 0x40) == 0) {
    (*pcVar14)(param_1,param_1 + 0x10,uVar15);
  }
  uVar13 = bVar1 & 7;
  *param_1 = (byte)uVar13;
  iVar17 = 0xf - uVar13;
  if ((bVar1 & 7) == 0) {
    uVar12 = 0;
  }
  else {
    bVar2 = param_1[iVar17];
    iVar8 = 0x10 - uVar13;
    param_1[iVar17] = 0;
    uVar12 = (uint)bVar2 << 8;
    if (iVar8 != 0xf) {
      bVar5 = param_1[iVar8];
      iVar6 = 0x11 - uVar13;
      param_1[iVar8] = 0;
      uVar3 = CONCAT11(bVar2,bVar5);
      uVar12 = (uint)uVar3 << 8;
      if (iVar6 != 0xf) {
        bVar2 = param_1[iVar6];
        iVar8 = 0x12 - uVar13;
        param_1[iVar6] = 0;
        uVar4 = CONCAT21(uVar3,bVar2);
        uVar12 = (uint)uVar4 << 8;
        if (iVar8 != 0xf) {
          bVar2 = param_1[iVar8];
          iVar6 = 0x13 - uVar13;
          param_1[iVar8] = 0;
          uVar12 = CONCAT31(uVar4,bVar2) << 8;
          if (iVar6 != 0xf) {
            bVar2 = param_1[iVar6];
            iVar8 = 0x14 - uVar13;
            param_1[iVar6] = 0;
            uVar12 = (uVar12 | bVar2) << 8;
            if (iVar8 != 0xf) {
              bVar2 = param_1[iVar8];
              param_1[iVar8] = 0;
              uVar12 = (uVar12 | bVar2) << 8;
              if (uVar13 != 6) {
                bVar2 = param_1[0xe];
                param_1[0xe] = 0;
                uVar12 = (uVar12 | bVar2) << 8;
              }
            }
          }
        }
      }
    }
  }
  uVar12 = uVar12 | param_1[0xf];
  param_1[0xf] = 1;
  if (uVar12 != param_4) {
    uVar15 = 0xffffffff;
    goto LAB_000fffac;
  }
  uVar18 = param_4 >> 4;
  if (uVar18 == 0) {
    if (param_4 != 0) {
LAB_00100070:
      local_44 = (uint *)(param_1 + 0x10);
      (*pcVar14)(param_1,&local_40,uVar15);
      puVar10 = param_3 + 1;
      uVar18 = (uint)(param_1 + 0x14 <= param_2);
      if (param_2 + 1 <= local_44) {
        uVar18 = 1;
      }
      uVar18 = uVar18 & (puVar10 <= param_2 || param_2 + 1 <= param_3);
      uVar11 = (uint)(param_1 + 0x14 <= param_3);
      if (uVar12 < 5) {
        uVar18 = 0;
      }
      bVar21 = param_3 <= &local_3c;
      bVar20 = &local_3c == param_3;
      if (bVar21 && !bVar20) {
        bVar21 = &local_40 <= puVar10;
        bVar20 = puVar10 == &local_40;
      }
      if (puVar10 <= local_44) {
        uVar11 = 1;
      }
      uVar11 = uVar11 & uVar18 & (!bVar21 || bVar20);
      if ((((uint)param_2 | (uint)param_3) & 3) != 0) {
        uVar11 = 0;
      }
      pbVar9 = param_1;
      if (uVar11 == 0) {
        do {
          bVar2 = pbVar9[0x10];
          bVar5 = *(byte *)((int)param_2 + uVar11) ^ *(byte *)((int)&local_40 + uVar11);
          *(byte *)((int)param_3 + uVar11) = bVar5;
          uVar11 = uVar11 + 1;
          pbVar9[0x10] = bVar5 ^ bVar2;
          pbVar9 = pbVar9 + 1;
        } while (uVar11 < uVar12);
      }
      else {
        uVar18 = uVar12;
        if (uVar12 == 0) {
          uVar18 = 1;
        }
        uVar19 = uVar18 >> 2;
        uVar11 = uVar18 & 0xfffffffc;
        if (uVar19 == 0) {
          bVar5 = *(byte *)param_2;
          uVar19 = 1;
          bVar2 = param_1[0x10];
          *(byte *)param_3 = bVar5 ^ (byte)local_40;
          param_1[0x10] = bVar5 ^ (byte)local_40 ^ bVar2;
LAB_001001b8:
          uVar18 = uVar19 + 1;
          bVar2 = param_1[uVar19 + 0x10];
          bVar5 = *(byte *)((int)param_2 + uVar19) ^ *(byte *)((int)&local_40 + uVar19);
          *(byte *)((int)param_3 + uVar19) = bVar5;
          param_1[uVar19 + 0x10] = bVar5 ^ bVar2;
          if (uVar18 < uVar12) {
            bVar2 = param_1[uVar19 + 0x11];
            bVar5 = *(byte *)((int)param_2 + uVar18) ^ *(byte *)((int)&local_40 + uVar19 + 1);
            *(byte *)((int)param_3 + uVar18) = bVar5;
            param_1[uVar19 + 0x11] = bVar2 ^ bVar5;
          }
        }
        else {
          uVar16 = *param_2;
          uVar7 = *(uint *)(param_1 + 0x10);
          *param_3 = uVar16 ^ local_40;
          *(uint *)(param_1 + 0x10) = uVar16 ^ local_40 ^ uVar7;
          if (1 < uVar19) {
            uVar16 = param_2[1];
            uVar7 = *(uint *)(param_1 + 0x14);
            param_3[1] = uVar16 ^ local_3c;
            *(uint *)(param_1 + 0x14) = uVar16 ^ local_3c ^ uVar7;
            if (2 < uVar19) {
              uVar16 = param_2[2];
              uVar7 = *(uint *)(param_1 + 0x18);
              param_3[2] = uVar16 ^ local_38;
              *(uint *)(param_1 + 0x18) = uVar16 ^ local_38 ^ uVar7;
              if (3 < uVar19) {
                uVar7 = param_2[3];
                uVar19 = *(uint *)(param_1 + 0x1c);
                param_3[3] = uVar7 ^ local_34;
                *(uint *)(param_1 + 0x1c) = uVar7 ^ local_34 ^ uVar19;
              }
            }
          }
          if (uVar18 != uVar11) {
            uVar19 = uVar11 + 1;
            bVar2 = param_1[uVar11 + 0x10];
            bVar5 = *(byte *)((int)&local_40 + uVar11) ^
                    *(byte *)((int)param_2 + (uVar18 & 0xfffffffc));
            *(byte *)((int)param_3 + (uVar18 & 0xfffffffc)) = bVar5;
            param_1[uVar11 + 0x10] = bVar2 ^ bVar5;
            if (uVar19 < uVar12) goto LAB_001001b8;
          }
        }
      }
      (*pcVar14)(local_44,local_44,uVar15);
    }
  }
  else {
    (*param_5)(param_2,param_3,uVar18,uVar15,param_1,param_1 + 0x10);
    uVar12 = param_4 + uVar18 * -0x10;
    if (uVar12 != 0) {
      uVar18 = (uVar18 & 0xff) + (uint)param_1[0xf];
      param_1[0xf] = (byte)uVar18;
      uVar18 = uVar18 >> 8;
      if ((uVar18 | param_4 >> 0xc) != 0) {
        uVar18 = uVar18 + (uint)param_1[0xe] + (param_4 >> 0xc & 0xff);
        param_1[0xe] = (byte)uVar18;
        uVar18 = uVar18 >> 8;
        if ((uVar18 | param_4 >> 0x14) != 0) {
          uVar18 = uVar18 + (uint)param_1[0xd] + (param_4 >> 0x14 & 0xff);
          param_1[0xd] = (byte)uVar18;
          uVar18 = uVar18 >> 8;
          if ((uVar18 | param_4 >> 0x1c) != 0) {
            uVar18 = (param_4 >> 0x1c) + (uint)param_1[0xc] + uVar18;
            param_1[0xc] = (byte)uVar18;
            uVar18 = uVar18 >> 8;
            if (uVar18 != 0) {
              uVar18 = uVar18 + param_1[0xb];
              param_1[0xb] = (byte)uVar18;
              uVar18 = uVar18 >> 8;
              if (uVar18 != 0) {
                uVar18 = uVar18 + param_1[10];
                param_1[10] = (byte)uVar18;
                uVar18 = uVar18 >> 8;
                if (uVar18 != 0) {
                  uVar18 = uVar18 + param_1[9];
                  param_1[9] = (byte)uVar18;
                  if (uVar18 >> 8 != 0) {
                    param_1[8] = (char)(uVar18 >> 8) + param_1[8];
                  }
                }
              }
            }
          }
        }
      }
      param_2 = (uint *)((int)param_2 + (param_4 & 0xfffffff0));
      param_3 = (uint *)((int)param_3 + (param_4 & 0xfffffff0));
      goto LAB_00100070;
    }
  }
  local_5c = &local_40;
  memset(param_1 + iVar17,0,uVar13 + 1);
  (*pcVar14)(param_1,local_5c,uVar15);
  uVar15 = 0;
  *param_1 = bVar1;
  *(uint *)(param_1 + 0x10) = *(uint *)(param_1 + 0x10) ^ local_40;
  *(uint *)(param_1 + 0x14) = *(uint *)(param_1 + 0x14) ^ local_3c;
  *(uint *)(param_1 + 0x18) = *(uint *)(param_1 + 0x18) ^ local_38;
  *(uint *)(param_1 + 0x1c) = *(uint *)(param_1 + 0x1c) ^ local_34;
LAB_000fffac:
  if (local_2c != __stack_chk_guard) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(uVar15);
  }
  return;
}

