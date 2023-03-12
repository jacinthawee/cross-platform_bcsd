
/* WARNING: Restarted to delay deadcode elimination for space: stack */

void CRYPTO_ccm128_decrypt(byte *param_1,uint *param_2,uint *param_3,uint param_4)

{
  byte bVar1;
  byte bVar2;
  ushort uVar3;
  uint3 uVar4;
  int iVar5;
  int iVar6;
  uint *puVar7;
  byte *pbVar8;
  uint uVar9;
  byte bVar10;
  uint uVar11;
  uint uVar12;
  uint uVar13;
  int iVar14;
  code *pcVar15;
  uint *puVar16;
  undefined4 uVar17;
  uint *puVar18;
  bool bVar19;
  bool bVar20;
  bool bVar21;
  bool bVar22;
  uint *local_64;
  uint local_58;
  uint *local_54;
  uint *local_50;
  undefined4 local_40;
  uint local_3c;
  uint local_38;
  uint uStack_34;
  int local_2c;
  
  bVar1 = *param_1;
  pcVar15 = *(code **)(param_1 + 0x28);
  uVar17 = *(undefined4 *)(param_1 + 0x2c);
  local_2c = __TMC_END__;
  if (-1 < (int)((uint)bVar1 << 0x19)) {
    (*pcVar15)(param_1,param_1 + 0x10,uVar17);
  }
  uVar11 = bVar1 & 7;
  iVar14 = 0xf - uVar11;
  *param_1 = (byte)uVar11;
  if ((bVar1 & 7) == 0) {
    local_58 = 0;
  }
  else {
    bVar2 = param_1[iVar14];
    iVar6 = 0x10 - uVar11;
    param_1[iVar14] = 0;
    local_58 = (uint)bVar2 << 8;
    if (iVar6 != 0xf) {
      bVar10 = param_1[iVar6];
      iVar5 = 0x11 - uVar11;
      param_1[iVar6] = 0;
      uVar3 = CONCAT11(bVar2,bVar10);
      local_58 = (uint)uVar3 << 8;
      if (iVar5 != 0xf) {
        bVar2 = param_1[iVar5];
        iVar6 = 0x12 - uVar11;
        param_1[iVar5] = 0;
        uVar4 = CONCAT21(uVar3,bVar2);
        local_58 = (uint)uVar4 << 8;
        if (iVar6 != 0xf) {
          bVar2 = param_1[iVar6];
          iVar5 = 0x13 - uVar11;
          param_1[iVar6] = 0;
          local_58 = CONCAT31(uVar4,bVar2) << 8;
          if (iVar5 != 0xf) {
            bVar2 = param_1[iVar5];
            iVar6 = 0x14 - uVar11;
            param_1[iVar5] = 0;
            local_58 = (local_58 | bVar2) << 8;
            if (iVar6 != 0xf) {
              bVar2 = param_1[iVar6];
              param_1[iVar6] = 0;
              local_58 = (local_58 | bVar2) << 8;
              if (uVar11 != 6) {
                bVar2 = param_1[0xe];
                param_1[0xe] = 0;
                local_58 = (local_58 | bVar2) << 8;
              }
            }
          }
        }
      }
    }
  }
  bVar2 = param_1[0xf];
  param_1[0xf] = 1;
  local_58 = bVar2 | local_58;
  if (local_58 == param_4) {
    local_54 = param_3;
    local_50 = param_2;
    if (0xf < param_4) {
      puVar18 = param_2;
      puVar7 = param_3;
      do {
        (*pcVar15)(param_1,&local_40,uVar17);
        bVar10 = param_1[0xf];
        param_1[0xf] = bVar10 + 1;
        if (((((byte)(bVar10 + 1) == 0) &&
             (bVar10 = param_1[0xe], param_1[0xe] = bVar10 + 1, (byte)(bVar10 + 1) == 0)) &&
            (bVar10 = param_1[0xd], param_1[0xd] = bVar10 + 1, (byte)(bVar10 + 1) == 0)) &&
           (((bVar10 = param_1[0xc], param_1[0xc] = bVar10 + 1, (byte)(bVar10 + 1) == 0 &&
             (bVar10 = param_1[0xb], param_1[0xb] = bVar10 + 1, (byte)(bVar10 + 1) == 0)) &&
            ((bVar10 = param_1[10], param_1[10] = bVar10 + 1, (byte)(bVar10 + 1) == 0 &&
             (bVar10 = param_1[9], param_1[9] = bVar10 + 1, (byte)(bVar10 + 1) == 0)))))) {
          param_1[8] = param_1[8] + 1;
        }
        param_4 = param_4 - 0x10;
        local_40 = local_40 ^ *puVar18;
        local_3c = local_3c ^ puVar18[1];
        local_38 = puVar18[2] ^ local_38;
        uStack_34 = puVar18[3] ^ uStack_34;
        *(uint *)(param_1 + 0x10) = local_40 ^ *(uint *)(param_1 + 0x10);
        *(uint *)(param_1 + 0x14) = local_3c ^ *(uint *)(param_1 + 0x14);
        *(uint *)(param_1 + 0x18) = local_38 ^ *(uint *)(param_1 + 0x18);
        *(uint *)(param_1 + 0x1c) = uStack_34 ^ *(uint *)(param_1 + 0x1c);
        *puVar7 = local_40;
        puVar7[1] = local_3c;
        puVar7[2] = local_38;
        puVar7[3] = uStack_34;
        (*pcVar15)(param_1 + 0x10,param_1 + 0x10,uVar17);
        puVar18 = puVar18 + 4;
        puVar7 = puVar7 + 4;
      } while (0xf < param_4);
      uVar9 = local_58 - 0x10;
      local_58 = bVar2 & 0xf;
      iVar6 = (uVar9 & 0xfffffff0) + 0x10;
      local_50 = (uint *)((int)param_2 + iVar6);
      local_54 = (uint *)((int)param_3 + iVar6);
    }
    local_64 = &local_40;
    if (local_58 != 0) {
      (*pcVar15)(param_1,local_64,uVar17);
      puVar7 = (uint *)(param_1 + 0x14);
      puVar18 = local_54 + 1;
      uVar12 = (uint)(puVar7 <= local_50);
      puVar16 = (uint *)(param_1 + 0x10);
      uVar9 = (uint)(puVar18 <= local_50);
      if (local_50 + 1 <= puVar16) {
        uVar12 = 1;
      }
      if (local_50 + 1 <= local_54) {
        uVar9 = 1;
      }
      uVar9 = uVar9 & uVar12;
      bVar21 = local_54 <= &local_3c;
      bVar19 = &local_3c == local_54;
      if (bVar21 && !bVar19) {
        bVar21 = local_64 <= puVar18;
        bVar19 = puVar18 == local_64;
      }
      if (local_58 < 5) {
        uVar9 = 0;
      }
      bVar22 = local_54 <= puVar7;
      bVar20 = puVar7 == local_54;
      if (bVar22 && !bVar20) {
        bVar22 = puVar16 <= puVar18;
        bVar20 = puVar18 == puVar16;
      }
      uVar9 = (uint)(!bVar22 || bVar20) & uVar9 & (!bVar21 || bVar19);
      if ((((uint)local_54 | (uint)local_50) & 3) != 0) {
        uVar9 = 0;
      }
      pbVar8 = param_1;
      if (uVar9 == 0) {
        do {
          bVar2 = pbVar8[0x10];
          bVar10 = *(byte *)((int)local_64 + uVar9) ^ *(byte *)((int)local_50 + uVar9);
          *(byte *)((int)local_54 + uVar9) = bVar10;
          uVar9 = uVar9 + 1;
          pbVar8[0x10] = bVar10 ^ bVar2;
          pbVar8 = pbVar8 + 1;
        } while (uVar9 != local_58);
      }
      else {
        uVar12 = *local_50;
        uVar9 = *(uint *)(param_1 + 0x10);
        *local_54 = local_40 ^ uVar12;
        *(uint *)(param_1 + 0x10) = local_40 ^ uVar12 ^ uVar9;
        uVar9 = local_58 & 0xfffffffc;
        if (1 < local_58 >> 2) {
          uVar12 = local_50[1];
          uVar13 = *(uint *)(param_1 + 0x14);
          local_54[1] = uVar12 ^ local_3c;
          *(uint *)(param_1 + 0x14) = uVar12 ^ local_3c ^ uVar13;
          if (2 < local_58 >> 2) {
            uVar13 = *(uint *)(param_1 + 0x18);
            uVar12 = local_50[2];
            local_54[2] = uVar12 ^ local_38;
            *(uint *)(param_1 + 0x18) = uVar12 ^ local_38 ^ uVar13;
          }
        }
        if (local_58 != uVar9) {
          uVar12 = uVar9 + 1;
          bVar2 = param_1[uVar9 + 0x10];
          bVar10 = *(byte *)((int)&local_40 + uVar9) ^
                   *(byte *)((int)local_50 + (local_58 & 0xfffffffc));
          *(byte *)((int)local_54 + (local_58 & 0xfffffffc)) = bVar10;
          param_1[uVar9 + 0x10] = bVar10 ^ bVar2;
          if (uVar12 < local_58) {
            uVar13 = uVar9 + 2;
            bVar2 = param_1[uVar9 + 0x11];
            bVar10 = *(byte *)((int)&local_40 + uVar9 + 1) ^ *(byte *)((int)local_50 + uVar12);
            *(byte *)((int)local_54 + uVar12) = bVar10;
            param_1[uVar9 + 0x11] = bVar2 ^ bVar10;
            if (uVar13 < local_58) {
              bVar2 = param_1[uVar9 + 0x12];
              bVar10 = *(byte *)((int)&local_40 + uVar9 + 2) ^ *(byte *)((int)local_50 + uVar13);
              *(byte *)((int)local_54 + uVar13) = bVar10;
              param_1[uVar9 + 0x12] = bVar2 ^ bVar10;
            }
          }
        }
      }
      (*pcVar15)(puVar16,puVar16,uVar17);
    }
    memset(param_1 + iVar14,0,uVar11 + 1);
    (*pcVar15)(param_1,local_64,uVar17);
    uVar17 = 0;
    *(uint *)(param_1 + 0x10) = *(uint *)(param_1 + 0x10) ^ local_40;
    *(uint *)(param_1 + 0x14) = *(uint *)(param_1 + 0x14) ^ local_3c;
    *param_1 = bVar1;
    *(uint *)(param_1 + 0x18) = *(uint *)(param_1 + 0x18) ^ local_38;
    *(uint *)(param_1 + 0x1c) = *(uint *)(param_1 + 0x1c) ^ uStack_34;
  }
  else {
    uVar17 = 0xffffffff;
  }
  if (local_2c != __TMC_END__) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(uVar17);
  }
  return;
}

