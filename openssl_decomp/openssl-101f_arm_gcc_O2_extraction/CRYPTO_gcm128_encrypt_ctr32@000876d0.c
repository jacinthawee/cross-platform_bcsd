
undefined4
CRYPTO_gcm128_encrypt_ctr32(int param_1,uint *param_2,uint *param_3,uint param_4,code *param_5)

{
  byte bVar1;
  byte bVar2;
  byte bVar3;
  byte bVar4;
  byte bVar5;
  int iVar6;
  uint uVar7;
  uint uVar8;
  uint uVar9;
  int iVar10;
  code *pcVar11;
  code *pcVar12;
  uint *puVar13;
  byte bVar14;
  undefined4 uVar15;
  uint uVar16;
  uint *puVar17;
  int iVar18;
  bool bVar19;
  bool bVar20;
  
  uVar7 = *(uint *)(param_1 + 0x38) + param_4;
  pcVar11 = *(code **)(param_1 + 0x160);
  uVar8 = *(int *)(param_1 + 0x3c) + (uint)CARRY4(*(uint *)(param_1 + 0x38),param_4);
  bVar19 = uVar8 < 0x10;
  if (uVar8 == 0xf) {
    bVar19 = uVar7 < 0xffffffe1;
  }
  uVar15 = *(undefined4 *)(param_1 + 0x174);
  pcVar12 = *(code **)(param_1 + 0x164);
  if (bVar19) {
    *(uint *)(param_1 + 0x38) = uVar7;
    *(uint *)(param_1 + 0x3c) = uVar8;
    if (*(int *)(param_1 + 0x16c) != 0) {
      (*pcVar11)(param_1 + 0x40,param_1 + 0x60);
      *(undefined4 *)(param_1 + 0x16c) = 0;
    }
    bVar1 = *(byte *)(param_1 + 0xe);
    uVar7 = *(uint *)(param_1 + 0x168);
    bVar14 = *(byte *)(param_1 + 0xc);
    bVar2 = *(byte *)(param_1 + 0xd);
    bVar3 = *(byte *)(param_1 + 0xf);
    if (uVar7 != 0) {
      puVar17 = param_3;
      puVar13 = param_2;
      if (param_4 == 0) {
LAB_000877f8:
        *(uint *)(param_1 + 0x168) = uVar7;
        return 0;
      }
      do {
        iVar18 = param_1 + uVar7;
        uVar8 = uVar7 + 1 & 0xf;
        param_2 = (uint *)((int)puVar13 + 1);
        uVar7 = uVar7 + 1 & 0xf;
        if (uVar8 != 0) {
          uVar8 = 1;
        }
        param_4 = param_4 - 1;
        bVar5 = *(byte *)(iVar18 + 0x10) ^ *(byte *)puVar13;
        uVar8 = uVar8 & 1;
        bVar4 = *(byte *)(iVar18 + 0x40);
        if (param_4 == 0) {
          uVar8 = 0;
        }
        param_3 = (uint *)((int)puVar17 + 1);
        *(byte *)puVar17 = bVar5;
        *(byte *)(iVar18 + 0x40) = bVar5 ^ bVar4;
        puVar17 = param_3;
        puVar13 = param_2;
      } while (uVar8 != 0);
      if (uVar7 != 0) goto LAB_000877f8;
      (*pcVar11)(param_1 + 0x40,param_1 + 0x60);
    }
    uVar7 = (uint)bVar2 << 0x10 | (uint)bVar14 << 0x18 | (uint)bVar3 | (uint)bVar1 << 8;
    if (0xbff < param_4) {
      puVar17 = param_3;
      do {
        uVar7 = uVar7 + 0xc0;
        param_4 = param_4 - 0xc00;
        (*param_5)(param_2,puVar17,0xc0,uVar15,param_1);
        *(char *)(param_1 + 0xc) = (char)(uVar7 >> 0x18);
        *(char *)(param_1 + 0xd) = (char)(uVar7 >> 0x10);
        *(char *)(param_1 + 0xf) = (char)uVar7;
        *(char *)(param_1 + 0xe) = (char)(uVar7 >> 8);
        param_2 = param_2 + 0x300;
        param_3 = puVar17 + 0x300;
        (*pcVar12)(param_1 + 0x40,param_1 + 0x60,puVar17);
        puVar17 = param_3;
      } while (0xbff < param_4);
    }
    uVar8 = param_4 & 0xfffffff0;
    if (uVar8 != 0) {
      uVar9 = param_4 >> 4;
      uVar7 = uVar7 + uVar9;
      param_4 = param_4 - uVar8;
      (*param_5)(param_2,param_3,uVar9,uVar15,param_1);
      *(char *)(param_1 + 0xf) = (char)uVar7;
      *(char *)(param_1 + 0xc) = (char)(uVar7 >> 0x18);
      *(char *)(param_1 + 0xd) = (char)(uVar7 >> 0x10);
      *(char *)(param_1 + 0xe) = (char)(uVar7 >> 8);
      (*pcVar12)(param_1 + 0x40,param_1 + 0x60,param_3,uVar8);
      param_2 = (uint *)((int)param_2 + uVar8);
      param_3 = (uint *)((int)param_3 + uVar8);
    }
    if (param_4 != 0) {
      puVar13 = (uint *)(param_1 + 0x10);
      (**(code **)(param_1 + 0x170))(param_1,puVar13,uVar15);
      puVar17 = param_3 + 1;
      uVar8 = (uint)((uint *)(param_1 + 0x44) <= param_2);
      bVar20 = param_3 <= (uint *)(param_1 + 0x14);
      bVar19 = (uint *)(param_1 + 0x14) == param_3;
      if (bVar20 && !bVar19) {
        bVar20 = puVar13 <= puVar17;
        bVar19 = puVar17 == puVar13;
      }
      iVar18 = uVar7 + 1;
      *(char *)(param_1 + 0xf) = (char)iVar18;
      if (param_2 + 1 <= (uint *)(param_1 + 0x40)) {
        uVar8 = 1;
      }
      uVar8 = (!bVar20 || bVar19) & uVar8;
      uVar7 = (uint)((uint *)(param_1 + 0x44) <= param_3);
      if (param_4 < 5) {
        uVar8 = 0;
      }
      if (puVar17 <= (uint *)(param_1 + 0x40)) {
        uVar7 = 1;
      }
      uVar7 = uVar7 & (puVar17 <= param_2 || param_2 + 1 <= param_3) & uVar8;
      if ((((uint)param_2 | (uint)param_3) & 3) != 0) {
        uVar7 = 0;
      }
      *(char *)(param_1 + 0xc) = (char)((uint)iVar18 >> 0x18);
      *(char *)(param_1 + 0xd) = (char)((uint)iVar18 >> 0x10);
      *(char *)(param_1 + 0xe) = (char)((uint)iVar18 >> 8);
      iVar18 = param_1;
      if (uVar7 == 0) {
        do {
          bVar1 = *(byte *)(iVar18 + 0x40);
          bVar14 = *(byte *)((int)param_2 + uVar7) ^ *(byte *)(iVar18 + 0x10);
          *(byte *)((int)param_3 + uVar7) = bVar14;
          uVar7 = uVar7 + 1;
          *(byte *)(iVar18 + 0x40) = bVar14 ^ bVar1;
          iVar18 = iVar18 + 1;
        } while (uVar7 != param_4);
      }
      else {
        uVar9 = param_4 >> 2;
        uVar16 = *(uint *)(param_1 + 0x40);
        uVar8 = param_4 & 0xfffffffc;
        uVar7 = *(uint *)(param_1 + 0x10) ^ *param_2;
        *param_3 = uVar7;
        *(uint *)(param_1 + 0x40) = uVar7 ^ uVar16;
        if (1 < uVar9) {
          uVar16 = *(uint *)(param_1 + 0x44);
          uVar7 = param_2[1] ^ *(uint *)(param_1 + 0x14);
          param_3[1] = uVar7;
          *(uint *)(param_1 + 0x44) = uVar7 ^ uVar16;
          if (2 < uVar9) {
            uVar16 = *(uint *)(param_1 + 0x48);
            uVar7 = param_2[2] ^ *(uint *)(param_1 + 0x18);
            param_3[2] = uVar7;
            *(uint *)(param_1 + 0x48) = uVar7 ^ uVar16;
            if (3 < uVar9) {
              uVar9 = *(uint *)(param_1 + 0x4c);
              uVar7 = param_2[3] ^ *(uint *)(param_1 + 0x1c);
              param_3[3] = uVar7;
              *(uint *)(param_1 + 0x4c) = uVar7 ^ uVar9;
            }
          }
        }
        if (param_4 != uVar8) {
          iVar18 = param_1 + uVar8;
          iVar6 = uVar8 + 1;
          bVar1 = *(byte *)(iVar18 + 0x40);
          bVar14 = *(byte *)(iVar18 + 0x10) ^ *(byte *)((int)param_2 + (param_4 & 0xfffffffc));
          *(byte *)((int)param_3 + (param_4 & 0xfffffffc)) = bVar14;
          *(byte *)(iVar18 + 0x40) = bVar14 ^ bVar1;
          if (param_4 - 1 != uVar8) {
            iVar10 = param_1 + iVar6;
            iVar18 = uVar8 + 2;
            bVar1 = *(byte *)(iVar10 + 0x40);
            bVar14 = *(byte *)(iVar10 + 0x10) ^ *(byte *)((int)param_2 + iVar6);
            *(byte *)((int)param_3 + iVar6) = bVar14;
            *(byte *)(iVar10 + 0x40) = bVar14 ^ bVar1;
            if ((param_4 - 1) - uVar8 != 1) {
              iVar6 = param_1 + iVar18;
              bVar1 = *(byte *)(iVar6 + 0x40);
              bVar14 = *(byte *)(iVar6 + 0x10) ^ *(byte *)((int)param_2 + iVar18);
              *(byte *)((int)param_3 + iVar18) = bVar14;
              *(byte *)(iVar6 + 0x40) = bVar14 ^ bVar1;
            }
          }
        }
      }
    }
    uVar15 = 0;
    *(uint *)(param_1 + 0x168) = param_4;
  }
  else {
    uVar15 = 0xffffffff;
  }
  return uVar15;
}

