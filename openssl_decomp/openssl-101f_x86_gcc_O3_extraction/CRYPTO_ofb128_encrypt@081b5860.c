
void CRYPTO_ofb128_encrypt
               (byte *param_1,byte *param_2,uint param_3,undefined4 param_4,int param_5,
               uint *param_6,code *param_7)

{
  uint *puVar1;
  uint *puVar2;
  int iVar3;
  byte *pbVar4;
  uint uVar5;
  byte *pbVar6;
  uint uVar7;
  byte *pbVar8;
  int iVar9;
  uint local_34;
  
  uVar5 = *param_6;
  pbVar4 = param_1;
  if ((uVar5 != 0) && (param_3 != 0)) {
    do {
      pbVar6 = (byte *)(param_5 + uVar5);
      pbVar4 = param_1 + 1;
      pbVar8 = param_2 + 1;
      param_3 = param_3 - 1;
      uVar5 = uVar5 + 1 & 0xf;
      *param_2 = *pbVar6 ^ *param_1;
      param_2 = pbVar8;
      if (uVar5 == 0) break;
      param_1 = pbVar4;
    } while (param_3 != 0);
  }
  pbVar6 = param_2;
  uVar7 = param_3;
  pbVar8 = pbVar4;
  if (param_3 < 0x10) {
    if (param_3 != 0) {
      (*param_7)(param_5,param_5,param_4);
      local_34 = param_3 - 1;
      goto LAB_081b59a0;
    }
  }
  else {
    do {
      (*param_7)(param_5,param_5,param_4);
      if ((((uVar5 < 0x10) &&
           (*(uint *)(pbVar6 + uVar5) = *(uint *)(pbVar8 + uVar5) ^ *(uint *)(param_5 + uVar5),
           uVar5 + 4 < 0x10)) &&
          (*(uint *)(pbVar6 + uVar5 + 4) =
                *(uint *)(pbVar8 + uVar5 + 4) ^ *(uint *)(param_5 + 4 + uVar5), uVar5 + 8 < 0x10))
         && (*(uint *)(pbVar6 + uVar5 + 8) =
                  *(uint *)(pbVar8 + uVar5 + 8) ^ *(uint *)(param_5 + 8 + uVar5), uVar5 + 0xc < 0x10
            )) {
        *(uint *)(pbVar6 + uVar5 + 0xc) =
             *(uint *)(pbVar8 + uVar5 + 0xc) ^ *(uint *)(param_5 + 0xc + uVar5);
      }
      uVar7 = uVar7 - 0x10;
      uVar5 = 0;
      pbVar6 = pbVar6 + 0x10;
      pbVar8 = pbVar8 + 0x10;
    } while (0xf < uVar7);
    iVar9 = ((param_3 - 0x10 >> 4) + 1) * 0x10;
    param_2 = param_2 + iVar9;
    pbVar4 = pbVar4 + iVar9;
    uVar5 = 0;
    if ((param_3 & 0xf) != 0) {
      (*param_7)(param_5,param_5,param_4);
      local_34 = (param_3 - 0x11) - (param_3 - 0x10 & 0xfffffff0);
      uVar5 = 0;
LAB_081b59a0:
      puVar1 = (uint *)(pbVar4 + uVar5);
      puVar2 = (uint *)(param_2 + uVar5);
      iVar9 = uVar5 + 4;
      if ((((uint *)(param_5 + uVar5) < param_2 + iVar9 && puVar2 < (uint *)(param_5 + iVar9) ||
           puVar2 < pbVar4 + iVar9 && puVar1 < param_2 + iVar9) || local_34 + 1 < 7) ||
         (((param_5 + uVar5 | (uint)puVar1 | (uint)puVar2) & 3) != 0)) {
        *(byte *)puVar2 = *(byte *)(param_5 + uVar5) ^ *(byte *)puVar1;
        if (((((local_34 != 0) &&
              ((param_2[uVar5 + 1] = pbVar4[uVar5 + 1] ^ *(byte *)(param_5 + 1 + uVar5),
               local_34 != 1 &&
               (param_2[uVar5 + 2] = pbVar4[uVar5 + 2] ^ *(byte *)(param_5 + 2 + uVar5),
               local_34 != 2)))) &&
             (param_2[uVar5 + 3] = pbVar4[uVar5 + 3] ^ *(byte *)(param_5 + 3 + uVar5), local_34 != 3
             )) && (((param_2[uVar5 + 4] = pbVar4[uVar5 + 4] ^ *(byte *)(param_5 + 4 + uVar5),
                     local_34 != 4 &&
                     (param_2[uVar5 + 5] = pbVar4[uVar5 + 5] ^ *(byte *)(param_5 + 5 + uVar5),
                     local_34 != 5)) &&
                    (param_2[uVar5 + 6] = pbVar4[uVar5 + 6] ^ *(byte *)(param_5 + 6 + uVar5),
                    local_34 != 6)))) &&
           ((((param_2[uVar5 + 7] = pbVar4[uVar5 + 7] ^ *(byte *)(param_5 + 7 + uVar5),
              local_34 != 7 &&
              (param_2[uVar5 + 8] = pbVar4[uVar5 + 8] ^ *(byte *)(param_5 + 8 + uVar5),
              local_34 != 8)) &&
             ((param_2[uVar5 + 9] = pbVar4[uVar5 + 9] ^ *(byte *)(param_5 + 9 + uVar5),
              local_34 != 9 &&
              ((param_2[uVar5 + 10] = pbVar4[uVar5 + 10] ^ *(byte *)(param_5 + 10 + uVar5),
               local_34 != 10 &&
               (param_2[uVar5 + 0xb] = pbVar4[uVar5 + 0xb] ^ *(byte *)(param_5 + 0xb + uVar5),
               local_34 != 0xb)))))) &&
            ((param_2[uVar5 + 0xc] = pbVar4[uVar5 + 0xc] ^ *(byte *)(param_5 + 0xc + uVar5),
             local_34 != 0xc &&
             (param_2[uVar5 + 0xd] = pbVar4[uVar5 + 0xd] ^ *(byte *)(param_5 + 0xd + uVar5),
             local_34 != 0xd)))))) {
          param_2[uVar5 + 0xe] = pbVar4[uVar5 + 0xe] ^ *(byte *)(param_5 + 0xe + uVar5);
        }
      }
      else {
        iVar9 = (local_34 - 3 >> 2) + 1;
        uVar7 = iVar9 * 4;
        *puVar2 = *(uint *)(param_5 + uVar5) ^ *puVar1;
        if ((iVar9 != 1) && (puVar2[1] = *(uint *)(param_5 + uVar5 + 4) ^ puVar1[1], iVar9 == 3)) {
          puVar2[2] = puVar1[2] ^ *(uint *)(param_5 + uVar5 + 8);
        }
        iVar3 = uVar7 + uVar5;
        if (((local_34 + 1 != uVar7) &&
            (param_2[iVar3] = pbVar4[iVar3] ^ *(byte *)(param_5 + iVar3), local_34 != uVar7)) &&
           (param_2[iVar3 + 1] = pbVar4[iVar3 + 1] ^ *(byte *)(param_5 + 1 + iVar3),
           local_34 + iVar9 * -4 != 1)) {
          param_2[iVar3 + 2] = pbVar4[iVar3 + 2] ^ *(byte *)(param_5 + 2 + iVar3);
        }
      }
      *param_6 = local_34 + 1 + uVar5;
      return;
    }
  }
  *param_6 = uVar5;
  return;
}

