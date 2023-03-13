
undefined4 gost_cipher_do_cfb(int param_1,uint *param_2,uint *param_3,uint param_4)

{
  byte bVar3;
  uint uVar1;
  uint uVar2;
  uint uVar4;
  int iVar5;
  int iVar6;
  undefined4 uVar7;
  uint uVar8;
  uint *puVar9;
  uint *puVar10;
  uint *puVar11;
  
  uVar4 = *(uint *)(param_1 + 0x50);
  if (uVar4 == 0) {
    uVar1 = 8;
    uVar4 = 0;
  }
  else {
    uVar1 = uVar4;
    if (uVar4 < 8) {
      if (param_4 == 0) {
LAB_0061d498:
        *(uint *)(param_1 + 0x50) = uVar1;
        return 1;
      }
      iVar5 = param_1 + uVar4;
      if (*(int *)(param_1 + 8) == 0) {
        *(byte *)(iVar5 + 0x38) = *(byte *)param_3;
      }
      bVar3 = *(byte *)(iVar5 + 0x30) ^ *(byte *)param_3;
      *(byte *)param_2 = bVar3;
      iVar6 = *(int *)(param_1 + 8);
      if (iVar6 != 0) {
        *(byte *)(iVar5 + 0x38) = bVar3;
      }
      uVar1 = uVar4 + 1;
      if (uVar1 == 8) {
        uVar4 = 1;
        param_3 = (uint *)((int)param_3 + 1);
        param_2 = (uint *)((int)param_2 + 1);
      }
      else {
        if (param_4 < 2) goto LAB_0061d498;
        if (iVar6 == 0) {
          *(byte *)(iVar5 + 0x39) = *(byte *)((int)param_3 + 1);
        }
        bVar3 = *(byte *)(param_1 + uVar1 + 0x30) ^ *(byte *)((int)param_3 + 1);
        *(byte *)((int)param_2 + 1) = bVar3;
        iVar6 = *(int *)(param_1 + 8);
        if (iVar6 != 0) {
          *(byte *)(iVar5 + 0x39) = bVar3;
        }
        uVar1 = uVar4 + 2;
        if (uVar1 == 8) {
          uVar4 = 2;
          param_3 = (uint *)((int)param_3 + 2);
          param_2 = (uint *)((int)param_2 + 2);
        }
        else {
          if (param_4 == 2) goto LAB_0061d498;
          if (iVar6 == 0) {
            *(byte *)(iVar5 + 0x3a) = *(byte *)((int)param_3 + 2);
          }
          bVar3 = *(byte *)(param_1 + uVar1 + 0x30) ^ *(byte *)((int)param_3 + 2);
          *(byte *)((int)param_2 + 2) = bVar3;
          iVar6 = *(int *)(param_1 + 8);
          if (iVar6 != 0) {
            *(byte *)(iVar5 + 0x3a) = bVar3;
          }
          uVar1 = uVar4 + 3;
          if (uVar1 == 8) {
            uVar4 = 3;
            param_3 = (uint *)((int)param_3 + 3);
            param_2 = (uint *)((int)param_2 + 3);
          }
          else {
            if (param_4 == 3) goto LAB_0061d498;
            if (iVar6 == 0) {
              *(byte *)(iVar5 + 0x3b) = *(byte *)((int)param_3 + 3);
            }
            bVar3 = *(byte *)(param_1 + uVar1 + 0x30) ^ *(byte *)((int)param_3 + 3);
            *(byte *)((int)param_2 + 3) = bVar3;
            iVar6 = *(int *)(param_1 + 8);
            if (iVar6 != 0) {
              *(byte *)(iVar5 + 0x3b) = bVar3;
            }
            uVar1 = uVar4 + 4;
            if (uVar1 == 8) {
              uVar4 = 4;
              param_3 = param_3 + 1;
              param_2 = param_2 + 1;
            }
            else {
              if (param_4 == 4) goto LAB_0061d498;
              if (iVar6 == 0) {
                *(byte *)(iVar5 + 0x3c) = *(byte *)(param_3 + 1);
              }
              bVar3 = *(byte *)(param_1 + uVar1 + 0x30) ^ *(byte *)(param_3 + 1);
              *(byte *)(param_2 + 1) = bVar3;
              iVar6 = *(int *)(param_1 + 8);
              if (iVar6 != 0) {
                *(byte *)(iVar5 + 0x3c) = bVar3;
              }
              uVar1 = uVar4 + 5;
              if (uVar1 == 8) {
                uVar4 = 5;
                param_3 = (uint *)((int)param_3 + 5);
                param_2 = (uint *)((int)param_2 + 5);
              }
              else {
                if (param_4 == 5) goto LAB_0061d498;
                if (iVar6 == 0) {
                  *(byte *)(iVar5 + 0x3d) = *(byte *)((int)param_3 + 5);
                }
                bVar3 = *(byte *)(param_1 + uVar1 + 0x30) ^ *(byte *)((int)param_3 + 5);
                *(byte *)((int)param_2 + 5) = bVar3;
                iVar6 = *(int *)(param_1 + 8);
                if (iVar6 != 0) {
                  *(byte *)(iVar5 + 0x3d) = bVar3;
                }
                if (uVar4 == 1) {
                  uVar1 = 7;
                  if (param_4 == 6) goto LAB_0061d498;
                  if (iVar6 == 0) {
                    *(byte *)(param_1 + 0x3f) = *(byte *)((int)param_3 + 6);
                  }
                  bVar3 = *(byte *)(param_1 + 0x37) ^ *(byte *)((int)param_3 + 6);
                  *(byte *)((int)param_2 + 6) = bVar3;
                  if (*(int *)(param_1 + 8) != 0) {
                    *(byte *)(param_1 + 0x3f) = bVar3;
                  }
                  uVar4 = 7;
                  param_3 = (uint *)((int)param_3 + 7);
                  param_2 = (uint *)((int)param_2 + 7);
                }
                else {
                  uVar4 = 6;
                  param_3 = (uint *)((int)param_3 + 6);
                  param_2 = (uint *)((int)param_2 + 6);
                }
              }
            }
          }
        }
      }
    }
    else {
      if (uVar4 != 8) goto LAB_0061d498;
      uVar4 = 0;
    }
    uVar1 = uVar4 + 8;
    uVar8 = *(uint *)(param_1 + 0x38);
    uVar7 = *(undefined4 *)(param_1 + 0x3c);
    uVar2 = param_1 + 0x20U & 3;
    puVar9 = (uint *)((param_1 + 0x20U) - uVar2);
    *puVar9 = *puVar9 & -1 << (4 - uVar2) * 8 | uVar8 >> uVar2 * 8;
    uVar2 = param_1 + 0x23U & 3;
    puVar9 = (uint *)((param_1 + 0x23U) - uVar2);
    *puVar9 = *puVar9 & 0xffffffffU >> (uVar2 + 1) * 8 | uVar8 << (3 - uVar2) * 8;
    *(undefined4 *)(param_1 + 0x24) = uVar7;
    *(undefined4 *)(param_1 + 0x50) = 0;
  }
  if (uVar1 < param_4) {
    puVar11 = (uint *)(param_1 + 0x20);
    puVar9 = param_3;
    puVar10 = param_2;
    while( true ) {
      iVar5 = *(int *)(param_1 + 0x60);
      if ((*(int *)(iVar5 + 8) != 0) && (*(int *)(iVar5 + 4) == 0x400)) {
        cryptopro_key_meshing(iVar5 + 0xc,puVar11);
      }
      gostcrypt(iVar5 + 0xc,puVar11,param_1 + 0x30);
      iVar6 = *(int *)(param_1 + 8);
      *(uint *)(iVar5 + 4) = (*(uint *)(iVar5 + 4) & 0x3ff) + 8;
      if (iVar6 == 0) {
        uVar4 = puVar9[1];
        *puVar11 = *puVar9;
        *(uint *)(param_1 + 0x24) = uVar4;
      }
      *(byte *)puVar10 = *(byte *)(param_1 + 0x30) ^ *(byte *)puVar9;
      *(byte *)((int)puVar10 + 1) = *(byte *)(param_1 + 0x31) ^ *(byte *)((int)puVar9 + 1);
      *(byte *)((int)puVar10 + 2) = *(byte *)(param_1 + 0x32) ^ *(byte *)((int)puVar9 + 2);
      *(byte *)((int)puVar10 + 3) = *(byte *)(param_1 + 0x33) ^ *(byte *)((int)puVar9 + 3);
      *(byte *)(puVar10 + 1) = *(byte *)(param_1 + 0x34) ^ *(byte *)(puVar9 + 1);
      *(byte *)((int)puVar10 + 5) = *(byte *)(param_1 + 0x35) ^ *(byte *)((int)puVar9 + 5);
      *(byte *)((int)puVar10 + 6) = *(byte *)(param_1 + 0x36) ^ *(byte *)((int)puVar9 + 6);
      *(byte *)((int)puVar10 + 7) = *(byte *)(param_1 + 0x37) ^ *(byte *)((int)puVar9 + 7);
      if (*(int *)(param_1 + 8) != 0) {
        uVar4 = puVar10[1];
        *puVar11 = *puVar10;
        *(uint *)(param_1 + 0x24) = uVar4;
      }
      param_2 = puVar10 + 2;
      param_3 = puVar9 + 2;
      uVar4 = uVar1;
      if (param_4 <= uVar1 + 8) break;
      puVar10 = puVar10 + 2;
      puVar9 = puVar9 + 2;
      uVar1 = uVar1 + 8;
    }
  }
  if (param_4 <= uVar4) {
    *(undefined4 *)(param_1 + 0x50) = 0;
    return 1;
  }
  iVar5 = *(int *)(param_1 + 0x60);
  if ((*(int *)(iVar5 + 8) != 0) && (*(int *)(iVar5 + 4) == 0x400)) {
    cryptopro_key_meshing(iVar5 + 0xc,param_1 + 0x20);
  }
  gostcrypt(iVar5 + 0xc,param_1 + 0x20,(uint *)(param_1 + 0x30));
  iVar6 = *(int *)(param_1 + 8);
  *(uint *)(iVar5 + 4) = (*(uint *)(iVar5 + 4) & 0x3ff) + 8;
  if (iVar6 == 0) {
    uVar1 = param_4 - uVar4;
    (*(code *)PTR_memcpy_006a9aec)(param_1 + 0x38,param_3,uVar1);
  }
  else {
    uVar1 = param_4 - uVar4;
  }
  if ((uVar1 < 7 ||
       ((uint *)(param_1 + 0x30) < param_2 + 1 && param_2 < (uint *)(param_1 + 0x34) ||
       param_2 < param_3 + 1 && param_3 < param_2 + 1)) ||
     ((((uint)param_2 | (uint)param_3) & 3) != 0)) {
    *(byte *)param_2 = *(byte *)(param_1 + 0x30) ^ *(byte *)param_3;
    if ((((uVar4 + 1 < param_4) &&
         ((((*(byte *)((int)param_2 + 1) = *(byte *)(param_1 + 0x31) ^ *(byte *)((int)param_3 + 1),
            uVar4 + 2 < param_4 &&
            (*(byte *)((int)param_2 + 2) = *(byte *)(param_1 + 0x32) ^ *(byte *)((int)param_3 + 2),
            uVar4 + 3 < param_4)) &&
           (*(byte *)((int)param_2 + 3) = *(byte *)(param_1 + 0x33) ^ *(byte *)((int)param_3 + 3),
           uVar4 + 4 < param_4)) &&
          ((*(byte *)(param_2 + 1) = *(byte *)(param_1 + 0x34) ^ *(byte *)(param_3 + 1),
           uVar4 + 5 < param_4 &&
           (*(byte *)((int)param_2 + 5) = *(byte *)(param_1 + 0x35) ^ *(byte *)((int)param_3 + 5),
           uVar4 + 6 < param_4)))))) &&
        (*(byte *)((int)param_2 + 6) = *(byte *)(param_1 + 0x36) ^ *(byte *)((int)param_3 + 6),
        uVar4 + 7 < param_4)) &&
       (*(byte *)((int)param_2 + 7) = *(byte *)(param_1 + 0x37) ^ *(byte *)((int)param_3 + 7),
       uVar4 + 8 < param_4)) {
      *(byte *)(param_2 + 2) = *(byte *)(param_1 + 0x38) ^ *(byte *)(param_3 + 2);
    }
  }
  else {
    iVar5 = (uVar1 - 4 >> 2) + 1;
    uVar2 = iVar5 * 4;
    if ((param_4 - 1) - uVar4 < 3) {
      uVar2 = 0;
    }
    else {
      *param_2 = *param_3 ^ *(uint *)(param_1 + 0x30);
      if ((iVar5 != 1) && (param_2[1] = param_3[1] ^ *(uint *)(param_1 + 0x34), iVar5 != 2)) {
        param_2[2] = param_3[2] ^ *(uint *)(param_1 + 0x38);
      }
      uVar4 = uVar4 + uVar2;
      if (uVar1 == uVar2) goto LAB_0061d660;
    }
    iVar5 = uVar2 + 1;
    *(byte *)((int)param_2 + uVar2) =
         *(byte *)((int)param_3 + uVar2) ^ *(byte *)(param_1 + uVar2 + 0x30);
    if (uVar4 + 1 < param_4) {
      iVar6 = uVar2 + 2;
      *(byte *)((int)param_2 + iVar5) =
           *(byte *)((int)param_3 + iVar5) ^ *(byte *)(param_1 + iVar5 + 0x30);
      if (uVar4 + 2 < param_4) {
        *(byte *)((int)param_2 + iVar6) =
             *(byte *)((int)param_3 + iVar6) ^ *(byte *)(param_1 + iVar6 + 0x30);
      }
    }
  }
LAB_0061d660:
  *(uint *)(param_1 + 0x50) = uVar1;
  if (*(int *)(param_1 + 8) != 0) {
    (*(code *)PTR_memcpy_006a9aec)(param_1 + 0x38,param_2,uVar1);
  }
  return 1;
}

