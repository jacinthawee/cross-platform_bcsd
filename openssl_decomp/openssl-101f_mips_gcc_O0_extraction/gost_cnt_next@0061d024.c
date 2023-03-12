
/* WARNING: Could not reconcile some variable overlaps */

int gost_cnt_next(int param_1,uint *param_2,byte *param_3)

{
  byte bVar1;
  undefined *puVar2;
  int iVar3;
  uint uVar4;
  uint uVar5;
  int iVar6;
  uint uVar7;
  uint *puVar8;
  uint uVar9;
  uint *puVar10;
  byte *pbVar11;
  uint local_2c;
  uint local_28;
  int local_24;
  
  puVar2 = PTR___stack_chk_guard_006aabf0;
  local_24 = *(int *)PTR___stack_chk_guard_006aabf0;
  if (*(int *)(param_1 + 8) == 0) {
    iVar3 = *(int *)(param_1 + 4);
LAB_0061d07c:
    if (iVar3 != 0) goto LAB_0061d084;
LAB_0061d19c:
    gostcrypt(param_1 + 0xc,param_2,&local_2c);
  }
  else {
    if (*(int *)(param_1 + 4) == 0x400) {
      cryptopro_key_meshing(param_1 + 0xc);
      iVar3 = *(int *)(param_1 + 4);
      goto LAB_0061d07c;
    }
    if (*(int *)(param_1 + 4) == 0) goto LAB_0061d19c;
LAB_0061d084:
    local_2c = *param_2;
    local_28 = param_2[1];
  }
  puVar8 = &local_2c;
  uVar7 = (((local_28 >> 0x10) << 0x18 | (local_28 >> 0x18) << 0x10) >> 0x10) +
          ((local_28 & 0xff) << 8 | local_28 >> 8 & 0xff) * 0x10000;
  uVar4 = (((local_2c >> 0x10) << 0x18 | (local_2c >> 0x18) << 0x10) >> 0x10) +
          ((local_2c & 0xff) << 8 | local_2c >> 8 & 0xff) * 0x10000 + 0x1010101;
  uVar9 = uVar4 >> 8;
  uVar5 = uVar7 + 0x1010104;
  local_2c._0_1_ = (undefined)uVar4;
  local_2c = (uint)CONCAT12(local_2c._0_1_,CONCAT11((char)(uVar4 >> 8),(char)(uVar4 >> 0x10))) << 8;
  local_2c = local_2c | uVar4 >> 0x18;
  if (uVar5 < uVar7) {
    uVar5 = uVar7 + 0x1010105;
  }
  *param_2 = local_2c;
  local_28 = CONCAT31(CONCAT21(CONCAT11((char)uVar5,(char)(uVar5 >> 8)),(char)(uVar5 >> 0x10)),
                      (char)(uVar5 >> 0x18));
  param_2[1] = local_28;
  gostcrypt(param_1 + 0xc);
  iVar6 = *(int *)puVar2;
  iVar3 = (*(uint *)(param_1 + 4) & 0x3ff) + 8;
  *(int *)(param_1 + 4) = iVar3;
  if (local_24 == iVar6) {
    return iVar3;
  }
  iVar3 = local_24;
  (*(code *)PTR___stack_chk_fail_006aabb8)();
  uVar4 = *(uint *)(iVar3 + 0x50);
  if (uVar4 == 0) {
    uVar4 = 8;
    uVar5 = 0;
  }
  else {
    uVar7 = uVar4;
    if (uVar4 < 8) {
      if (uVar9 == 0) goto LAB_0061d560;
      uVar7 = uVar4 + 1;
      *(byte *)puVar8 = *(byte *)(iVar3 + uVar4 + 0x30) ^ *param_3;
      if (uVar7 == 8) {
        uVar5 = 1;
        *(undefined4 *)(iVar3 + 0x50) = 0;
        uVar4 = 9;
        puVar8 = (uint *)((int)puVar8 + 1);
        param_3 = param_3 + 1;
      }
      else {
        if (uVar9 < 2) goto LAB_0061d560;
        uVar5 = uVar4 + 2;
        *(byte *)((int)puVar8 + 1) = *(byte *)(iVar3 + uVar7 + 0x30) ^ param_3[1];
        if (uVar5 == 8) {
          uVar5 = 2;
          *(undefined4 *)(iVar3 + 0x50) = 0;
          uVar4 = 10;
          puVar8 = (uint *)((int)puVar8 + 2);
          param_3 = param_3 + 2;
        }
        else {
          uVar7 = uVar5;
          if (uVar9 == 2) goto LAB_0061d560;
          uVar7 = uVar4 + 3;
          *(byte *)((int)puVar8 + 2) = *(byte *)(iVar3 + uVar5 + 0x30) ^ param_3[2];
          if (uVar7 == 8) {
            uVar5 = 3;
            *(undefined4 *)(iVar3 + 0x50) = 0;
            uVar4 = 0xb;
            puVar8 = (uint *)((int)puVar8 + 3);
            param_3 = param_3 + 3;
          }
          else {
            if (uVar9 == 3) goto LAB_0061d560;
            uVar5 = uVar4 + 4;
            *(byte *)((int)puVar8 + 3) = *(byte *)(iVar3 + uVar7 + 0x30) ^ param_3[3];
            if (uVar5 == 8) {
              uVar5 = 4;
              *(undefined4 *)(iVar3 + 0x50) = 0;
              uVar4 = 0xc;
              puVar8 = puVar8 + 1;
              param_3 = param_3 + 4;
            }
            else {
              uVar7 = uVar5;
              if (uVar9 == 4) goto LAB_0061d560;
              uVar7 = uVar4 + 5;
              *(byte *)(puVar8 + 1) = *(byte *)(iVar3 + uVar5 + 0x30) ^ param_3[4];
              if (uVar7 == 8) {
                uVar5 = 5;
                *(undefined4 *)(iVar3 + 0x50) = 0;
                uVar4 = 0xd;
                puVar8 = (uint *)((int)puVar8 + 5);
                param_3 = param_3 + 5;
              }
              else {
                if (uVar9 == 5) goto LAB_0061d560;
                *(byte *)((int)puVar8 + 5) = *(byte *)(iVar3 + uVar7 + 0x30) ^ param_3[5];
                if (uVar4 == 1) {
                  if (uVar9 == 6) goto LAB_0061d5d0;
                  uVar5 = 7;
                  uVar4 = 0xf;
                  *(byte *)((int)puVar8 + 6) = *(byte *)(iVar3 + 0x37) ^ param_3[6];
                  *(undefined4 *)(iVar3 + 0x50) = 0;
                  puVar8 = (uint *)((int)puVar8 + 7);
                  param_3 = param_3 + 7;
                }
                else {
                  uVar5 = 6;
                  *(undefined4 *)(iVar3 + 0x50) = 0;
                  uVar4 = 0xe;
                  puVar8 = (uint *)((int)puVar8 + 6);
                  param_3 = param_3 + 6;
                }
              }
            }
          }
        }
      }
    }
    else {
      uVar5 = 0;
      if (uVar4 != 8) goto LAB_0061d560;
      *(undefined4 *)(iVar3 + 0x50) = 0;
      uVar4 = 8;
    }
  }
  if (uVar4 < uVar9) {
    puVar10 = puVar8;
    pbVar11 = param_3;
    do {
      uVar5 = uVar4;
      param_3 = pbVar11 + 8;
      gost_cnt_next(*(undefined4 *)(iVar3 + 0x60),iVar3 + 0x20,iVar3 + 0x30);
      puVar8 = puVar10 + 2;
      *(byte *)puVar10 = *(byte *)(iVar3 + 0x30) ^ *pbVar11;
      *(byte *)((int)puVar10 + 1) = *(byte *)(iVar3 + 0x31) ^ pbVar11[1];
      *(byte *)((int)puVar10 + 2) = *(byte *)(iVar3 + 0x32) ^ pbVar11[2];
      *(byte *)((int)puVar10 + 3) = *(byte *)(iVar3 + 0x33) ^ pbVar11[3];
      *(byte *)(puVar10 + 1) = *(byte *)(iVar3 + 0x34) ^ pbVar11[4];
      *(byte *)((int)puVar10 + 5) = *(byte *)(iVar3 + 0x35) ^ pbVar11[5];
      *(byte *)((int)puVar10 + 6) = *(byte *)(iVar3 + 0x36) ^ pbVar11[6];
      *(byte *)((int)puVar10 + 7) = *(byte *)(iVar3 + 0x37) ^ pbVar11[7];
      puVar10 = puVar8;
      pbVar11 = param_3;
      uVar4 = uVar5 + 8;
    } while (uVar5 + 8 < uVar9);
    if (uVar9 <= uVar5) {
LAB_0061d430:
      *(undefined4 *)(iVar3 + 0x50) = 0;
      return 1;
    }
    gost_cnt_next(*(undefined4 *)(iVar3 + 0x60),iVar3 + 0x20,iVar3 + 0x30);
    bVar1 = *param_3;
  }
  else {
    if (uVar9 <= uVar5) goto LAB_0061d430;
    gost_cnt_next(*(undefined4 *)(iVar3 + 0x60),iVar3 + 0x20,iVar3 + 0x30);
    bVar1 = *param_3;
  }
  *(byte *)puVar8 = bVar1 ^ *(byte *)(iVar3 + 0x30);
  if (uVar9 <= uVar5 + 1) {
    *(undefined4 *)(iVar3 + 0x50) = 1;
    return 1;
  }
  *(byte *)((int)puVar8 + 1) = *(byte *)(iVar3 + 0x31) ^ param_3[1];
  if (uVar9 <= uVar5 + 2) {
    *(undefined4 *)(iVar3 + 0x50) = 2;
    return 1;
  }
  *(byte *)((int)puVar8 + 2) = *(byte *)(iVar3 + 0x32) ^ param_3[2];
  if (uVar9 <= uVar5 + 3) {
    *(undefined4 *)(iVar3 + 0x50) = 3;
    return 1;
  }
  *(byte *)((int)puVar8 + 3) = *(byte *)(iVar3 + 0x33) ^ param_3[3];
  if (uVar9 <= uVar5 + 4) {
    *(undefined4 *)(iVar3 + 0x50) = 4;
    return 1;
  }
  *(byte *)(puVar8 + 1) = *(byte *)(iVar3 + 0x34) ^ param_3[4];
  if (uVar9 <= uVar5 + 5) {
    *(undefined4 *)(iVar3 + 0x50) = 5;
    return 1;
  }
  *(byte *)((int)puVar8 + 5) = *(byte *)(iVar3 + 0x35) ^ param_3[5];
  if (uVar9 <= uVar5 + 6) {
    *(undefined4 *)(iVar3 + 0x50) = 6;
    return 1;
  }
  *(byte *)((int)puVar8 + 6) = *(byte *)(iVar3 + 0x36) ^ param_3[6];
  if (uVar9 <= uVar5 + 7) {
LAB_0061d5d0:
    *(undefined4 *)(iVar3 + 0x50) = 7;
    return 1;
  }
  *(byte *)((int)puVar8 + 7) = *(byte *)(iVar3 + 0x37) ^ param_3[7];
  if (uVar9 <= uVar5 + 8) {
    *(undefined4 *)(iVar3 + 0x50) = 8;
    return 1;
  }
  *(byte *)(puVar8 + 2) = *(byte *)(iVar3 + 0x38) ^ param_3[8];
  uVar7 = 9;
LAB_0061d560:
  *(uint *)(iVar3 + 0x50) = uVar7;
  return 1;
}

