
undefined4
CRYPTO_gcm128_decrypt_ctr32(int param_1,uint *param_2,uint *param_3,uint param_4,code *param_5)

{
  byte bVar1;
  byte bVar2;
  byte bVar3;
  byte bVar4;
  byte bVar5;
  int iVar6;
  uint uVar7;
  uint uVar8;
  int iVar9;
  code *pcVar10;
  code *pcVar11;
  uint *puVar12;
  undefined4 uVar13;
  uint uVar14;
  uint *puVar15;
  int iVar16;
  bool bVar17;
  bool bVar18;
  
  uVar7 = *(uint *)(param_1 + 0x38) + param_4;
  pcVar10 = *(code **)(param_1 + 0x160);
  uVar8 = *(int *)(param_1 + 0x3c) + (uint)CARRY4(*(uint *)(param_1 + 0x38),param_4);
  bVar17 = uVar8 < 0x10;
  if (uVar8 == 0xf) {
    bVar17 = uVar7 < 0xffffffe1;
  }
  uVar13 = *(undefined4 *)(param_1 + 0x174);
  pcVar11 = *(code **)(param_1 + 0x164);
  if (bVar17) {
    *(uint *)(param_1 + 0x38) = uVar7;
    *(uint *)(param_1 + 0x3c) = uVar8;
    if (*(int *)(param_1 + 0x16c) != 0) {
      (*pcVar10)(param_1 + 0x40,param_1 + 0x60);
      *(undefined4 *)(param_1 + 0x16c) = 0;
    }
    bVar1 = *(byte *)(param_1 + 0xe);
    uVar7 = *(uint *)(param_1 + 0x168);
    bVar2 = *(byte *)(param_1 + 0xc);
    bVar3 = *(byte *)(param_1 + 0xd);
    bVar4 = *(byte *)(param_1 + 0xf);
    if (uVar7 != 0) {
      puVar15 = param_2;
      puVar12 = param_3;
      if (param_4 == 0) {
LAB_000858b4:
        *(uint *)(param_1 + 0x168) = uVar7;
        return 0;
      }
      do {
        iVar16 = param_1 + uVar7;
        uVar8 = uVar7 + 1 & 0xf;
        param_2 = (uint *)((int)puVar15 + 1);
        bVar5 = *(byte *)puVar15;
        uVar7 = uVar7 + 1 & 0xf;
        if (uVar8 != 0) {
          uVar8 = 1;
        }
        param_4 = param_4 - 1;
        uVar8 = uVar8 & 1;
        param_3 = (uint *)((int)puVar12 + 1);
        *(byte *)puVar12 = bVar5 ^ *(byte *)(iVar16 + 0x10);
        if (param_4 == 0) {
          uVar8 = 0;
        }
        *(byte *)(iVar16 + 0x40) = bVar5 ^ *(byte *)(iVar16 + 0x40);
        puVar15 = param_2;
        puVar12 = param_3;
      } while (uVar8 != 0);
      if (uVar7 != 0) goto LAB_000858b4;
      (*pcVar10)(param_1 + 0x40,param_1 + 0x60);
    }
    uVar7 = (uint)bVar3 << 0x10 | (uint)bVar2 << 0x18 | (uint)bVar4 | (uint)bVar1 << 8;
    if (0xbff < param_4) {
      do {
        param_4 = param_4 - 0xc00;
        (*pcVar11)(param_1 + 0x40,param_1 + 0x60,param_2,0xc00);
        uVar7 = uVar7 + 0xc0;
        (*param_5)(param_2,param_3,0xc0,uVar13,param_1);
        *(char *)(param_1 + 0xc) = (char)(uVar7 >> 0x18);
        param_2 = param_2 + 0x300;
        param_3 = param_3 + 0x300;
        *(char *)(param_1 + 0xf) = (char)uVar7;
        *(char *)(param_1 + 0xd) = (char)(uVar7 >> 0x10);
        *(char *)(param_1 + 0xe) = (char)(uVar7 >> 8);
      } while (0xbff < param_4);
    }
    uVar8 = param_4 & 0xfffffff0;
    if (uVar8 != 0) {
      uVar14 = param_4 >> 4;
      (*pcVar11)(param_1 + 0x40,param_1 + 0x60,param_2,uVar8);
      uVar7 = uVar7 + uVar14;
      param_4 = param_4 - uVar8;
      (*param_5)(param_2,param_3,uVar14,uVar13,param_1);
      param_2 = (uint *)((int)param_2 + uVar8);
      *(char *)(param_1 + 0xc) = (char)(uVar7 >> 0x18);
      param_3 = (uint *)((int)param_3 + uVar8);
      *(char *)(param_1 + 0xf) = (char)uVar7;
      *(char *)(param_1 + 0xd) = (char)(uVar7 >> 0x10);
      *(char *)(param_1 + 0xe) = (char)(uVar7 >> 8);
    }
    if (param_4 != 0) {
      puVar12 = (uint *)(param_1 + 0x10);
      (**(code **)(param_1 + 0x170))(param_1,puVar12,uVar13);
      puVar15 = param_3 + 1;
      iVar16 = uVar7 + 1;
      uVar7 = (uint)((uint *)(param_1 + 0x44) <= param_3);
      bVar18 = param_3 <= (uint *)(param_1 + 0x14);
      bVar17 = (uint *)(param_1 + 0x14) == param_3;
      if (bVar18 && !bVar17) {
        bVar18 = puVar12 <= puVar15;
        bVar17 = puVar15 == puVar12;
      }
      *(char *)(param_1 + 0xf) = (char)iVar16;
      if (puVar15 <= (uint *)(param_1 + 0x40)) {
        uVar7 = 1;
      }
      uVar7 = (!bVar18 || bVar17) & uVar7;
      uVar8 = (uint)((uint *)(param_1 + 0x44) <= param_2);
      if (param_4 < 5) {
        uVar7 = 0;
      }
      if (param_2 + 1 <= (uint *)(param_1 + 0x40)) {
        uVar8 = 1;
      }
      uVar8 = uVar7 & (puVar15 <= param_2 || param_2 + 1 <= param_3) & uVar8;
      if ((((uint)param_2 | (uint)param_3) & 3) != 0) {
        uVar8 = 0;
      }
      *(char *)(param_1 + 0xc) = (char)((uint)iVar16 >> 0x18);
      *(char *)(param_1 + 0xd) = (char)((uint)iVar16 >> 0x10);
      *(char *)(param_1 + 0xe) = (char)((uint)iVar16 >> 8);
      iVar16 = param_1;
      if (uVar8 == 0) {
        do {
          bVar1 = *(byte *)((int)param_2 + uVar8);
          *(byte *)(iVar16 + 0x40) = *(byte *)(iVar16 + 0x40) ^ bVar1;
          *(byte *)((int)param_3 + uVar8) = bVar1 ^ *(byte *)(iVar16 + 0x10);
          uVar8 = uVar8 + 1;
          iVar16 = iVar16 + 1;
        } while (uVar8 != param_4);
      }
      else {
        uVar8 = param_4 >> 2;
        uVar14 = *param_2;
        uVar7 = param_4 & 0xfffffffc;
        *(uint *)(param_1 + 0x40) = *(uint *)(param_1 + 0x40) ^ uVar14;
        *param_3 = *(uint *)(param_1 + 0x10) ^ uVar14;
        if (1 < uVar8) {
          uVar14 = param_2[1];
          *(uint *)(param_1 + 0x44) = *(uint *)(param_1 + 0x44) ^ uVar14;
          param_3[1] = *(uint *)(param_1 + 0x14) ^ uVar14;
          if (2 < uVar8) {
            uVar14 = param_2[2];
            *(uint *)(param_1 + 0x48) = *(uint *)(param_1 + 0x48) ^ uVar14;
            param_3[2] = *(uint *)(param_1 + 0x18) ^ uVar14;
            if (3 < uVar8) {
              uVar8 = param_2[3];
              *(uint *)(param_1 + 0x4c) = *(uint *)(param_1 + 0x4c) ^ uVar8;
              param_3[3] = *(uint *)(param_1 + 0x1c) ^ uVar8;
            }
          }
        }
        if (param_4 != uVar7) {
          iVar16 = param_1 + uVar7;
          bVar1 = *(byte *)((int)param_2 + (param_4 & 0xfffffffc));
          iVar6 = uVar7 + 1;
          *(byte *)(iVar16 + 0x40) = *(byte *)(iVar16 + 0x40) ^ bVar1;
          *(byte *)((int)param_3 + (param_4 & 0xfffffffc)) = bVar1 ^ *(byte *)(iVar16 + 0x10);
          if (param_4 - 1 != uVar7) {
            iVar9 = param_1 + iVar6;
            bVar1 = *(byte *)((int)param_2 + iVar6);
            iVar16 = uVar7 + 2;
            *(byte *)(iVar9 + 0x40) = *(byte *)(iVar9 + 0x40) ^ bVar1;
            *(byte *)((int)param_3 + iVar6) = bVar1 ^ *(byte *)(iVar9 + 0x10);
            if ((param_4 - 1) - uVar7 != 1) {
              iVar6 = param_1 + iVar16;
              bVar1 = *(byte *)((int)param_2 + iVar16);
              *(byte *)(iVar6 + 0x40) = *(byte *)(iVar6 + 0x40) ^ bVar1;
              *(byte *)((int)param_3 + iVar16) = bVar1 ^ *(byte *)(iVar6 + 0x10);
            }
          }
        }
      }
    }
    uVar13 = 0;
    *(uint *)(param_1 + 0x168) = param_4;
  }
  else {
    uVar13 = 0xffffffff;
  }
  return uVar13;
}

