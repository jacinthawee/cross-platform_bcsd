
undefined4 CRYPTO_gcm128_encrypt(int param_1,uint *param_2,uint *param_3,uint param_4)

{
  byte bVar1;
  byte bVar2;
  byte bVar3;
  byte bVar4;
  code *pcVar5;
  code *pcVar6;
  int iVar7;
  uint uVar8;
  int iVar9;
  uint uVar10;
  uint *puVar11;
  int iVar12;
  byte bVar13;
  undefined4 uVar14;
  code *pcVar15;
  byte bVar16;
  uint uVar17;
  uint *puVar18;
  uint *puVar19;
  uint uVar20;
  bool bVar21;
  bool bVar22;
  uint local_44;
  uint *local_40;
  uint *local_3c;
  
  pcVar5 = *(code **)(param_1 + 0x160);
  uVar8 = *(uint *)(param_1 + 0x38) + param_4;
  uVar10 = *(int *)(param_1 + 0x3c) + (uint)CARRY4(*(uint *)(param_1 + 0x38),param_4);
  bVar21 = uVar10 < 0x10;
  pcVar6 = *(code **)(param_1 + 0x164);
  if (uVar10 == 0xf) {
    bVar21 = uVar8 < 0xffffffe1;
  }
  pcVar15 = *(code **)(param_1 + 0x170);
  uVar14 = *(undefined4 *)(param_1 + 0x174);
  if (!bVar21) {
    return 0xffffffff;
  }
  *(uint *)(param_1 + 0x38) = uVar8;
  *(uint *)(param_1 + 0x3c) = uVar10;
  if (*(int *)(param_1 + 0x16c) != 0) {
    (*pcVar5)(param_1 + 0x40,param_1 + 0x60);
    *(undefined4 *)(param_1 + 0x16c) = 0;
  }
  bVar1 = *(byte *)(param_1 + 0xf);
  uVar8 = *(uint *)(param_1 + 0x168);
  bVar13 = *(byte *)(param_1 + 0xc);
  bVar2 = *(byte *)(param_1 + 0xd);
  bVar3 = *(byte *)(param_1 + 0xe);
  local_40 = param_3;
  local_3c = param_2;
  local_44 = param_4;
  if (uVar8 != 0) {
    if (param_4 == 0) goto LAB_00084ab4;
    do {
      iVar9 = param_1 + uVar8;
      uVar10 = uVar8 + 1 & 0xf;
      local_3c = (uint *)((int)param_2 + 1);
      uVar8 = uVar8 + 1 & 0xf;
      if (uVar10 != 0) {
        uVar10 = 1;
      }
      param_4 = param_4 - 1;
      bVar16 = *(byte *)(iVar9 + 0x10) ^ *(byte *)param_2;
      uVar10 = uVar10 & 1;
      bVar4 = *(byte *)(iVar9 + 0x40);
      if (param_4 == 0) {
        uVar10 = 0;
      }
      local_40 = (uint *)((int)param_3 + 1);
      *(byte *)param_3 = bVar16;
      *(byte *)(iVar9 + 0x40) = bVar16 ^ bVar4;
      param_3 = local_40;
      param_2 = local_3c;
    } while (uVar10 != 0);
    if (uVar8 != 0) goto LAB_00084ab4;
    (*pcVar5)(param_1 + 0x40,param_1 + 0x60);
    local_44 = param_4;
  }
  uVar10 = (uint)bVar2 << 0x10 | (uint)bVar13 << 0x18 | (uint)bVar1 | (uint)bVar3 << 8;
  if ((((uint)local_40 | (uint)local_3c) & 3) == 0) {
    if (0xbff < local_44) {
      uVar8 = uVar10;
      puVar11 = local_40;
      puVar18 = local_3c;
      do {
        local_3c = puVar18 + 0x300;
        local_40 = puVar11 + 0x300;
        uVar10 = uVar8 + 0xc0;
        puVar19 = puVar11;
        do {
          uVar8 = uVar8 + 1;
          (*pcVar15)(param_1,param_1 + 0x10,uVar14);
          *(char *)(param_1 + 0xf) = (char)uVar8;
          *(char *)(param_1 + 0xc) = (char)(uVar8 >> 0x18);
          *(char *)(param_1 + 0xd) = (char)(uVar8 >> 0x10);
          *(char *)(param_1 + 0xe) = (char)(uVar8 >> 8);
          *puVar19 = *(uint *)(param_1 + 0x10) ^ *puVar18;
          puVar19[1] = *(uint *)(param_1 + 0x14) ^ puVar18[1];
          puVar19[2] = *(uint *)(param_1 + 0x18) ^ puVar18[2];
          puVar19[3] = *(uint *)(param_1 + 0x1c) ^ puVar18[3];
          puVar19 = puVar19 + 4;
          puVar18 = puVar18 + 4;
        } while (uVar8 != uVar10);
        local_44 = local_44 - 0xc00;
        (*pcVar6)(param_1 + 0x40,param_1 + 0x60,puVar11,0xc00);
        uVar8 = uVar10;
        puVar11 = local_40;
        puVar18 = local_3c;
      } while (0xbff < local_44);
    }
    uVar8 = local_44 & 0xfffffff0;
    if (uVar8 != 0) {
      uVar10 = uVar10 + 1;
      uVar20 = local_44 - 0x10 >> 4;
      uVar17 = uVar10 + uVar20;
      puVar11 = local_3c;
      puVar18 = local_40;
      while( true ) {
        (*pcVar15)(param_1,param_1 + 0x10,uVar14);
        *(char *)(param_1 + 0xf) = (char)uVar10;
        *(char *)(param_1 + 0xc) = (char)(uVar10 >> 0x18);
        *(char *)(param_1 + 0xd) = (char)(uVar10 >> 0x10);
        *(char *)(param_1 + 0xe) = (char)(uVar10 >> 8);
        *puVar18 = *(uint *)(param_1 + 0x10) ^ *puVar11;
        puVar18[1] = *(uint *)(param_1 + 0x14) ^ puVar11[1];
        puVar18[2] = *(uint *)(param_1 + 0x18) ^ puVar11[2];
        puVar18[3] = *(uint *)(param_1 + 0x1c) ^ puVar11[3];
        if (uVar10 == uVar17) break;
        uVar10 = uVar10 + 1;
        puVar11 = puVar11 + 4;
        puVar18 = puVar18 + 4;
      }
      iVar9 = uVar20 + 1;
      local_40 = local_40 + iVar9 * 4;
      local_44 = local_44 & 0xf;
      local_3c = local_3c + iVar9 * 4;
      (*pcVar6)(param_1 + 0x40,param_1 + 0x60,(int)local_40 - uVar8);
    }
    if (local_44 != 0) {
      puVar11 = (uint *)(param_1 + 0x10);
      (*pcVar15)(param_1,puVar11,uVar14);
      puVar18 = local_40 + 1;
      uVar8 = (uint)((uint *)(param_1 + 0x44) <= local_3c);
      bVar22 = local_40 <= (uint *)(param_1 + 0x14);
      bVar21 = (uint *)(param_1 + 0x14) == local_40;
      if (bVar22 && !bVar21) {
        bVar22 = puVar11 <= puVar18;
        bVar21 = puVar18 == puVar11;
      }
      iVar9 = uVar10 + 1;
      *(char *)(param_1 + 0xf) = (char)iVar9;
      if (local_3c + 1 <= (uint *)(param_1 + 0x40)) {
        uVar8 = 1;
      }
      uVar8 = (!bVar22 || bVar21) & uVar8;
      uVar10 = (uint)((uint *)(param_1 + 0x44) <= local_40);
      if (local_44 < 5) {
        uVar8 = 0;
      }
      if (puVar18 <= (uint *)(param_1 + 0x40)) {
        uVar10 = 1;
      }
      uVar10 = uVar10 & (puVar18 <= local_3c || local_3c + 1 <= local_40) & uVar8;
      if ((((uint)local_3c | (uint)local_40) & 3) != 0) {
        uVar10 = 0;
      }
      *(char *)(param_1 + 0xc) = (char)((uint)iVar9 >> 0x18);
      *(char *)(param_1 + 0xd) = (char)((uint)iVar9 >> 0x10);
      *(char *)(param_1 + 0xe) = (char)((uint)iVar9 >> 8);
      iVar9 = param_1;
      if (uVar10 == 0) {
        do {
          bVar1 = *(byte *)(iVar9 + 0x40);
          bVar13 = *(byte *)((int)local_3c + uVar10) ^ *(byte *)(iVar9 + 0x10);
          *(byte *)((int)local_40 + uVar10) = bVar13;
          uVar10 = uVar10 + 1;
          *(byte *)(iVar9 + 0x40) = bVar13 ^ bVar1;
          iVar9 = iVar9 + 1;
        } while (uVar10 != local_44);
      }
      else {
        uVar17 = *(uint *)(param_1 + 0x40);
        uVar10 = local_44 & 0xfffffffc;
        uVar8 = *(uint *)(param_1 + 0x10) ^ *local_3c;
        *local_40 = uVar8;
        *(uint *)(param_1 + 0x40) = uVar8 ^ uVar17;
        if (1 < local_44 >> 2) {
          uVar17 = *(uint *)(param_1 + 0x44);
          uVar8 = local_3c[1] ^ *(uint *)(param_1 + 0x14);
          local_40[1] = uVar8;
          *(uint *)(param_1 + 0x44) = uVar8 ^ uVar17;
          if (2 < local_44 >> 2) {
            uVar17 = *(uint *)(param_1 + 0x48);
            uVar8 = local_3c[2] ^ *(uint *)(param_1 + 0x18);
            local_40[2] = uVar8;
            *(uint *)(param_1 + 0x48) = uVar8 ^ uVar17;
          }
        }
        if (local_44 != uVar10) {
          iVar9 = param_1 + uVar10;
          iVar7 = uVar10 + 1;
          bVar1 = *(byte *)(iVar9 + 0x40);
          bVar13 = *(byte *)(iVar9 + 0x10) ^ *(byte *)((int)local_3c + (local_44 & 0xfffffffc));
          *(byte *)((int)local_40 + (local_44 & 0xfffffffc)) = bVar13;
          *(byte *)(iVar9 + 0x40) = bVar13 ^ bVar1;
          if (local_44 - 1 != uVar10) {
            iVar9 = param_1 + iVar7;
            iVar12 = uVar10 + 2;
            bVar1 = *(byte *)(iVar9 + 0x40);
            bVar13 = *(byte *)(iVar9 + 0x10) ^ *(byte *)((int)local_3c + iVar7);
            *(byte *)((int)local_40 + iVar7) = bVar13;
            *(byte *)(iVar9 + 0x40) = bVar13 ^ bVar1;
            if ((local_44 - 1) - uVar10 != 1) {
              iVar9 = param_1 + iVar12;
              bVar1 = *(byte *)(iVar9 + 0x40);
              bVar13 = *(byte *)(iVar9 + 0x10) ^ *(byte *)((int)local_3c + iVar12);
              *(byte *)((int)local_40 + iVar12) = bVar13;
              *(byte *)(iVar9 + 0x40) = bVar13 ^ bVar1;
            }
          }
        }
      }
    }
    *(uint *)(param_1 + 0x168) = local_44;
    return 0;
  }
  uVar8 = local_44;
  if (local_44 != 0) {
    uVar17 = 0;
    uVar8 = 0;
    do {
      while( true ) {
        iVar9 = param_1 + uVar8;
        if (uVar8 != 0) break;
        uVar10 = uVar10 + 1;
        (*pcVar15)(param_1,param_1 + 0x10,uVar14);
        *(char *)(param_1 + 0xf) = (char)uVar10;
        *(char *)(param_1 + 0xc) = (char)(uVar10 >> 0x18);
        *(char *)(param_1 + 0xd) = (char)(uVar10 >> 0x10);
        *(char *)(param_1 + 0xe) = (char)(uVar10 >> 8);
        uVar8 = 1;
        bVar1 = *(byte *)(param_1 + 0x40);
        bVar13 = *(byte *)((int)local_3c + uVar17) ^ *(byte *)(param_1 + 0x10);
        *(byte *)((int)local_40 + uVar17) = bVar13;
        uVar17 = uVar17 + 1;
        *(byte *)(param_1 + 0x40) = bVar13 ^ bVar1;
        if (uVar17 == local_44) goto LAB_00084ab4;
      }
      bVar13 = *(byte *)(iVar9 + 0x10) ^ *(byte *)((int)local_3c + uVar17);
      bVar1 = *(byte *)(iVar9 + 0x40);
      *(byte *)((int)local_40 + uVar17) = bVar13;
      *(byte *)(iVar9 + 0x40) = bVar13 ^ bVar1;
      uVar8 = uVar8 + 1 & 0xf;
      if (uVar8 == 0) {
        (*pcVar5)(param_1 + 0x40,param_1 + 0x60);
      }
      uVar17 = uVar17 + 1;
    } while (uVar17 != local_44);
  }
LAB_00084ab4:
  *(uint *)(param_1 + 0x168) = uVar8;
  return 0;
}

