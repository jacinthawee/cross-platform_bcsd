
undefined4 CRYPTO_gcm128_decrypt(int param_1,uint *param_2,uint *param_3,uint param_4)

{
  byte bVar1;
  byte bVar2;
  byte bVar3;
  byte bVar4;
  byte bVar5;
  code *pcVar6;
  int iVar7;
  uint uVar8;
  int iVar9;
  uint uVar10;
  uint *puVar11;
  int iVar12;
  undefined4 uVar13;
  code *pcVar14;
  uint *puVar15;
  code *pcVar16;
  uint *puVar17;
  bool bVar18;
  bool bVar19;
  uint *local_40;
  uint local_3c;
  uint local_38;
  
  uVar8 = *(uint *)(param_1 + 0x38) + param_4;
  uVar10 = *(int *)(param_1 + 0x3c) + (uint)CARRY4(*(uint *)(param_1 + 0x38),param_4);
  bVar18 = uVar10 < 0x10;
  pcVar6 = *(code **)(param_1 + 0x164);
  if (uVar10 == 0xf) {
    bVar18 = uVar8 < 0xffffffe1;
  }
  pcVar14 = *(code **)(param_1 + 0x170);
  uVar13 = *(undefined4 *)(param_1 + 0x174);
  pcVar16 = *(code **)(param_1 + 0x160);
  if (!bVar18) {
    return 0xffffffff;
  }
  *(uint *)(param_1 + 0x38) = uVar8;
  *(uint *)(param_1 + 0x3c) = uVar10;
  if (*(int *)(param_1 + 0x16c) != 0) {
    (*pcVar16)(param_1 + 0x40,param_1 + 0x60);
    *(undefined4 *)(param_1 + 0x16c) = 0;
  }
  bVar1 = *(byte *)(param_1 + 0xe);
  uVar8 = *(uint *)(param_1 + 0x168);
  bVar2 = *(byte *)(param_1 + 0xc);
  bVar3 = *(byte *)(param_1 + 0xd);
  bVar4 = *(byte *)(param_1 + 0xf);
  local_40 = param_3;
  local_3c = param_4;
  if (uVar8 == 0) {
LAB_00084fe0:
    local_38 = (uint)bVar3 << 0x10 | (uint)bVar2 << 0x18 | (uint)bVar4 | (uint)bVar1 << 8;
    if ((((uint)local_40 | (uint)param_2) & 3) == 0) {
      if (0xbff < local_3c) {
        do {
          puVar17 = param_2 + 0x300;
          (*pcVar6)(param_1 + 0x40,param_1 + 0x60,param_2,0xc00);
          puVar11 = param_2;
          puVar15 = local_40;
          uVar8 = local_38;
          do {
            uVar8 = uVar8 + 1;
            (*pcVar14)(param_1,param_1 + 0x10,uVar13);
            *(char *)(param_1 + 0xf) = (char)uVar8;
            *(char *)(param_1 + 0xc) = (char)(uVar8 >> 0x18);
            *(char *)(param_1 + 0xd) = (char)(uVar8 >> 0x10);
            param_2 = puVar11 + 4;
            *(char *)(param_1 + 0xe) = (char)(uVar8 >> 8);
            *puVar15 = *(uint *)(param_1 + 0x10) ^ *puVar11;
            puVar15[1] = *(uint *)(param_1 + 0x14) ^ puVar11[1];
            puVar15[2] = *(uint *)(param_1 + 0x18) ^ puVar11[2];
            puVar15[3] = *(uint *)(param_1 + 0x1c) ^ puVar11[3];
            puVar11 = param_2;
            puVar15 = puVar15 + 4;
          } while (param_2 != puVar17);
          local_3c = local_3c - 0xc00;
          local_38 = local_38 + 0xc0;
          local_40 = local_40 + 0x300;
        } while (0xbff < local_3c);
      }
      if ((local_3c & 0xfffffff0) != 0) {
        (*pcVar6)(param_1 + 0x40,param_1 + 0x60,param_2);
        uVar10 = local_3c - 0x10 >> 4;
        local_38 = local_38 + 1;
        uVar8 = local_38 + uVar10;
        puVar11 = param_2;
        puVar15 = local_40;
        while( true ) {
          (*pcVar14)(param_1,param_1 + 0x10,uVar13);
          *(char *)(param_1 + 0xf) = (char)local_38;
          *(char *)(param_1 + 0xc) = (char)(local_38 >> 0x18);
          *(char *)(param_1 + 0xd) = (char)(local_38 >> 0x10);
          *(char *)(param_1 + 0xe) = (char)(local_38 >> 8);
          *puVar15 = *(uint *)(param_1 + 0x10) ^ *puVar11;
          puVar15[1] = *(uint *)(param_1 + 0x14) ^ puVar11[1];
          puVar15[2] = *(uint *)(param_1 + 0x18) ^ puVar11[2];
          puVar15[3] = *(uint *)(param_1 + 0x1c) ^ puVar11[3];
          if (local_38 == uVar8) break;
          local_38 = local_38 + 1;
          puVar11 = puVar11 + 4;
          puVar15 = puVar15 + 4;
        }
        iVar9 = uVar10 + 1;
        local_3c = local_3c & 0xf;
        local_40 = local_40 + iVar9 * 4;
        param_2 = param_2 + iVar9 * 4;
      }
      if (local_3c != 0) {
        puVar11 = (uint *)(param_1 + 0x10);
        (*pcVar14)(param_1,puVar11,uVar13);
        puVar15 = local_40 + 1;
        uVar8 = (uint)((uint *)(param_1 + 0x44) <= local_40);
        bVar19 = local_40 <= (uint *)(param_1 + 0x14);
        bVar18 = (uint *)(param_1 + 0x14) == local_40;
        if (bVar19 && !bVar18) {
          bVar19 = puVar11 <= puVar15;
          bVar18 = puVar15 == puVar11;
        }
        if (puVar15 <= (uint *)(param_1 + 0x40)) {
          uVar8 = 1;
        }
        uVar8 = (!bVar19 || bVar18) & uVar8;
        uVar10 = (uint)((uint *)(param_1 + 0x44) <= param_2);
        if (local_3c < 5) {
          uVar8 = 0;
        }
        if (param_2 + 1 <= (uint *)(param_1 + 0x40)) {
          uVar10 = 1;
        }
        uVar10 = uVar10 & uVar8 & (puVar15 <= param_2 || param_2 + 1 <= local_40);
        iVar9 = local_38 + 1;
        if ((((uint)param_2 | (uint)local_40) & 3) != 0) {
          uVar10 = 0;
        }
        *(char *)(param_1 + 0xf) = (char)iVar9;
        *(char *)(param_1 + 0xc) = (char)((uint)iVar9 >> 0x18);
        *(char *)(param_1 + 0xd) = (char)((uint)iVar9 >> 0x10);
        *(char *)(param_1 + 0xe) = (char)((uint)iVar9 >> 8);
        iVar9 = param_1;
        if (uVar10 == 0) {
          do {
            bVar1 = *(byte *)((int)param_2 + uVar10);
            *(byte *)(iVar9 + 0x40) = *(byte *)(iVar9 + 0x40) ^ bVar1;
            *(byte *)((int)local_40 + uVar10) = bVar1 ^ *(byte *)(iVar9 + 0x10);
            uVar10 = uVar10 + 1;
            iVar9 = iVar9 + 1;
          } while (uVar10 != local_3c);
        }
        else {
          uVar10 = *param_2;
          *(uint *)(param_1 + 0x40) = *(uint *)(param_1 + 0x40) ^ uVar10;
          uVar8 = local_3c & 0xfffffffc;
          *local_40 = *(uint *)(param_1 + 0x10) ^ uVar10;
          if (1 < local_3c >> 2) {
            uVar10 = param_2[1];
            *(uint *)(param_1 + 0x44) = *(uint *)(param_1 + 0x44) ^ uVar10;
            local_40[1] = *(uint *)(param_1 + 0x14) ^ uVar10;
            if (2 < local_3c >> 2) {
              uVar10 = param_2[2];
              *(uint *)(param_1 + 0x48) = *(uint *)(param_1 + 0x48) ^ uVar10;
              local_40[2] = *(uint *)(param_1 + 0x18) ^ uVar10;
            }
          }
          if (uVar8 != local_3c) {
            iVar9 = param_1 + uVar8;
            bVar1 = *(byte *)((int)param_2 + (local_3c & 0xfffffffc));
            iVar7 = uVar8 + 1;
            *(byte *)(iVar9 + 0x40) = *(byte *)(iVar9 + 0x40) ^ bVar1;
            *(byte *)((int)local_40 + (local_3c & 0xfffffffc)) = bVar1 ^ *(byte *)(iVar9 + 0x10);
            if (local_3c - 1 != uVar8) {
              iVar9 = param_1 + iVar7;
              bVar1 = *(byte *)((int)param_2 + iVar7);
              iVar12 = uVar8 + 2;
              *(byte *)(iVar9 + 0x40) = *(byte *)(iVar9 + 0x40) ^ bVar1;
              *(byte *)((int)local_40 + iVar7) = bVar1 ^ *(byte *)(iVar9 + 0x10);
              if ((local_3c - 1) - uVar8 != 1) {
                iVar9 = param_1 + iVar12;
                bVar1 = *(byte *)((int)param_2 + iVar12);
                *(byte *)(iVar9 + 0x40) = *(byte *)(iVar9 + 0x40) ^ bVar1;
                *(byte *)((int)local_40 + iVar12) = bVar1 ^ *(byte *)(iVar9 + 0x10);
              }
            }
          }
        }
      }
      *(uint *)(param_1 + 0x168) = local_3c;
      return 0;
    }
    uVar8 = local_3c;
    if (local_3c != 0) {
      uVar10 = 0;
      uVar8 = 0;
      do {
        while( true ) {
          iVar9 = param_1 + uVar8;
          if (uVar8 != 0) break;
          local_38 = local_38 + 1;
          uVar8 = 1;
          (*pcVar14)(param_1,param_1 + 0x10,uVar13);
          *(char *)(param_1 + 0xf) = (char)local_38;
          *(char *)(param_1 + 0xc) = (char)(local_38 >> 0x18);
          *(char *)(param_1 + 0xd) = (char)(local_38 >> 0x10);
          *(char *)(param_1 + 0xe) = (char)(local_38 >> 8);
          bVar1 = *(byte *)((int)param_2 + uVar10);
          *(byte *)((int)local_40 + uVar10) = *(byte *)(param_1 + 0x10) ^ bVar1;
          uVar10 = uVar10 + 1;
          *(byte *)(param_1 + 0x40) = bVar1 ^ *(byte *)(param_1 + 0x40);
          if (uVar10 == local_3c) goto LAB_000850a8;
        }
        bVar1 = *(byte *)((int)param_2 + uVar10);
        *(byte *)((int)local_40 + uVar10) = bVar1 ^ *(byte *)(iVar9 + 0x10);
        *(byte *)(iVar9 + 0x40) = bVar1 ^ *(byte *)(iVar9 + 0x40);
        uVar8 = uVar8 + 1 & 0xf;
        if (uVar8 == 0) {
          (*pcVar16)(param_1 + 0x40,param_1 + 0x60);
        }
        uVar10 = uVar10 + 1;
      } while (uVar10 != local_3c);
    }
LAB_000850a8:
    *(uint *)(param_1 + 0x168) = uVar8;
    return 0;
  }
  puVar11 = param_2;
  if (param_4 != 0) {
    do {
      iVar9 = param_1 + uVar8;
      uVar10 = uVar8 + 1 & 0xf;
      param_2 = (uint *)((int)puVar11 + 1);
      bVar5 = *(byte *)puVar11;
      uVar8 = uVar8 + 1 & 0xf;
      if (uVar10 != 0) {
        uVar10 = 1;
      }
      param_4 = param_4 - 1;
      uVar10 = uVar10 & 1;
      local_40 = (uint *)((int)param_3 + 1);
      *(byte *)param_3 = bVar5 ^ *(byte *)(iVar9 + 0x10);
      if (param_4 == 0) {
        uVar10 = 0;
      }
      *(byte *)(iVar9 + 0x40) = bVar5 ^ *(byte *)(iVar9 + 0x40);
      puVar11 = param_2;
      param_3 = local_40;
    } while (uVar10 != 0);
    if (uVar8 == 0) {
      (*pcVar16)(param_1 + 0x40,param_1 + 0x60);
      local_3c = param_4;
      goto LAB_00084fe0;
    }
  }
  *(uint *)(param_1 + 0x168) = uVar8;
  return 0;
}

