
void CRYPTO_ctr128_encrypt_ctr32
               (byte *param_1,byte *param_2,uint param_3,undefined4 param_4,char *param_5,
               undefined4 *param_6,uint *param_7,code *param_8)

{
  byte *pbVar1;
  uint *puVar2;
  uint *puVar3;
  byte bVar4;
  byte *pbVar5;
  uint uVar6;
  int iVar7;
  byte *pbVar8;
  uint uVar9;
  uint uVar10;
  uint *puVar11;
  uint local_28;
  uint local_24;
  
  local_28 = *param_7;
  pbVar8 = param_1;
  pbVar5 = param_2;
  uVar6 = local_28;
  if (param_3 != 0) {
    do {
      param_2 = pbVar5;
      param_1 = pbVar8;
      if (uVar6 == 0) break;
      pbVar1 = (byte *)((int)param_6 + local_28);
      param_1 = pbVar8 + 1;
      param_2 = pbVar5 + 1;
      param_3 = param_3 - 1;
      local_28 = local_28 + 1 & 0xf;
      *pbVar5 = *pbVar1 ^ *pbVar8;
      pbVar8 = param_1;
      pbVar5 = param_2;
      uVar6 = param_3;
    } while (local_28 != 0);
  }
  uVar6 = *(uint *)(param_5 + 0xc);
  uVar6 = uVar6 >> 0x18 | (uVar6 & 0xff0000) >> 8 | (uVar6 & 0xff00) << 8 | uVar6 << 0x18;
  for (; uVar10 = uVar6, pbVar8 = param_1, 0xf < param_3; param_3 = param_3 + uVar10 * 0x10) {
    while( true ) {
      uVar9 = param_3 >> 4;
      uVar6 = uVar10 + uVar9;
      if (CARRY4(uVar10,uVar9)) break;
      uVar10 = param_3 & 0xfffffff0;
      param_3 = param_3 - uVar10;
      param_1 = pbVar8 + uVar10;
      (*param_8)(pbVar8,param_2,uVar9,param_4,param_5);
      param_2 = param_2 + uVar10;
      *(uint *)(param_5 + 0xc) =
           uVar6 >> 0x18 | (uVar6 & 0xff0000) >> 8 | (uVar6 & 0xff00) << 8 | uVar6 * 0x1000000;
      uVar10 = uVar6;
      pbVar8 = param_1;
      if (param_3 < 0x10) goto LAB_081b33f4;
    }
    param_1 = pbVar8 + uVar10 * -0x10;
    (*param_8)(pbVar8,param_2,-uVar10,param_4,param_5);
    *(undefined4 *)(param_5 + 0xc) = 0;
    bVar4 = param_5[0xb];
    param_2 = param_2 + uVar10 * -0x10;
    param_5[0xb] = (char)(bVar4 + 1);
    uVar6 = (bVar4 + 1 >> 8) + (uint)(byte)param_5[10];
    param_5[10] = (char)uVar6;
    uVar6 = (uVar6 >> 8) + (uint)(byte)param_5[9];
    param_5[9] = (char)uVar6;
    uVar6 = (uVar6 >> 8) + (uint)(byte)param_5[8];
    param_5[8] = (char)uVar6;
    uVar6 = (uVar6 >> 8) + (uint)(byte)param_5[7];
    param_5[7] = (char)uVar6;
    uVar6 = (uVar6 >> 8) + (uint)(byte)param_5[6];
    param_5[6] = (char)uVar6;
    uVar6 = (uVar6 >> 8) + (uint)(byte)param_5[5];
    param_5[5] = (char)uVar6;
    uVar6 = (uVar6 >> 8) + (uint)(byte)param_5[4];
    param_5[4] = (char)uVar6;
    uVar6 = (uVar6 >> 8) + (uint)(byte)param_5[3];
    param_5[3] = (char)uVar6;
    uVar6 = (uVar6 >> 8) + (uint)(byte)param_5[2];
    param_5[2] = (char)uVar6;
    iVar7 = (uVar6 >> 8) + (uint)(byte)param_5[1];
    param_5[1] = (char)iVar7;
    *param_5 = *param_5 + (char)((uint)iVar7 >> 8);
    uVar6 = 0;
  }
LAB_081b33f4:
  if (param_3 == 0) goto LAB_081b33f8;
  *param_6 = 0;
  param_6[1] = 0;
  param_6[2] = 0;
  param_6[3] = 0;
  (*param_8)(param_6,param_6,1,param_4,param_5);
  uVar6 = uVar6 + 1;
  *(uint *)(param_5 + 0xc) =
       uVar6 >> 0x18 | (uVar6 & 0xff0000) >> 8 | (uVar6 & 0xff00) << 8 | uVar6 * 0x1000000;
  if (uVar6 == 0) {
    bVar4 = param_5[0xb];
    param_5[0xb] = (char)(bVar4 + 1);
    uVar6 = (bVar4 + 1 >> 8) + (uint)(byte)param_5[10];
    param_5[10] = (char)uVar6;
    uVar6 = (uVar6 >> 8) + (uint)(byte)param_5[9];
    param_5[9] = (char)uVar6;
    uVar6 = (uVar6 >> 8) + (uint)(byte)param_5[8];
    param_5[8] = (char)uVar6;
    uVar6 = (uVar6 >> 8) + (uint)(byte)param_5[7];
    param_5[7] = (char)uVar6;
    uVar6 = (uVar6 >> 8) + (uint)(byte)param_5[6];
    param_5[6] = (char)uVar6;
    uVar6 = (uVar6 >> 8) + (uint)(byte)param_5[5];
    param_5[5] = (char)uVar6;
    uVar6 = (uVar6 >> 8) + (uint)(byte)param_5[4];
    param_5[4] = (char)uVar6;
    uVar6 = (uVar6 >> 8) + (uint)(byte)param_5[3];
    param_5[3] = (char)uVar6;
    uVar6 = (uVar6 >> 8) + (uint)(byte)param_5[2];
    param_5[2] = (char)uVar6;
    iVar7 = (uint)(byte)param_5[1] + (uVar6 >> 8);
    param_5[1] = (char)iVar7;
    *param_5 = *param_5 + (char)((uint)iVar7 >> 8);
  }
  local_24 = param_3 - 1;
  puVar3 = (uint *)(param_1 + local_28);
  puVar2 = (uint *)(param_2 + local_28);
  puVar11 = (uint *)((int)param_6 + local_28);
  iVar7 = local_28 + 4;
  if (((puVar2 < (uint *)((int)param_6 + iVar7) && puVar11 < param_2 + iVar7 ||
       puVar2 < param_1 + iVar7 && puVar3 < param_2 + iVar7) || param_3 < 7) ||
     ((((uint)puVar2 | (uint)puVar3 | (uint)puVar11) & 3) != 0)) {
    *(byte *)puVar2 = *(byte *)puVar11 ^ *(byte *)puVar3;
    if ((((local_24 != 0) &&
         ((((param_2[local_28 + 1] = param_1[local_28 + 1] ^ *(byte *)((int)param_6 + local_28 + 1),
            param_3 != 2 &&
            (param_2[local_28 + 2] = param_1[local_28 + 2] ^ *(byte *)((int)param_6 + local_28 + 2),
            param_3 != 3)) &&
           (param_2[local_28 + 3] = param_1[local_28 + 3] ^ *(byte *)((int)param_6 + local_28 + 3),
           param_3 != 4)) &&
          ((param_2[local_28 + 4] = param_1[local_28 + 4] ^ *(byte *)((int)param_6 + local_28 + 4),
           param_3 != 5 &&
           (param_2[local_28 + 5] = param_1[local_28 + 5] ^ *(byte *)((int)param_6 + local_28 + 5),
           param_3 != 6)))))) &&
        (param_2[local_28 + 6] = param_1[local_28 + 6] ^ *(byte *)((int)param_6 + local_28 + 6),
        param_3 != 7)) &&
       ((((param_2[local_28 + 7] = param_1[local_28 + 7] ^ *(byte *)((int)param_6 + local_28 + 7),
          param_3 != 8 &&
          (param_2[local_28 + 8] = param_1[local_28 + 8] ^ *(byte *)((int)param_6 + local_28 + 8),
          param_3 != 9)) &&
         ((param_2[local_28 + 9] = param_1[local_28 + 9] ^ *(byte *)((int)param_6 + local_28 + 9),
          param_3 != 10 &&
          (((param_2[local_28 + 10] =
                  param_1[local_28 + 10] ^ *(byte *)((int)param_6 + local_28 + 10), param_3 != 0xb
            && (param_2[local_28 + 0xb] =
                     param_1[local_28 + 0xb] ^ *(byte *)((int)param_6 + local_28 + 0xb),
               param_3 != 0xc)) &&
           (param_2[local_28 + 0xc] =
                 param_1[local_28 + 0xc] ^ *(byte *)((int)param_6 + local_28 + 0xc), param_3 != 0xd)
           ))))) &&
        (param_2[local_28 + 0xd] =
              param_1[local_28 + 0xd] ^ *(byte *)((int)param_6 + local_28 + 0xd), param_3 != 0xe))))
    {
      param_2[local_28 + 0xe] = param_1[local_28 + 0xe] ^ *(byte *)((int)param_6 + local_28 + 0xe);
    }
  }
  else {
    iVar7 = (param_3 - 4 >> 2) + 1;
    uVar6 = local_28;
    if (2 < local_24) {
      *puVar2 = *puVar11 ^ *puVar3;
      if ((iVar7 != 1) && (puVar2[1] = puVar11[1] ^ puVar3[1], iVar7 == 3)) {
        puVar2[2] = puVar11[2] ^ puVar3[2];
      }
      local_24 = local_24 + iVar7 * -4;
      uVar6 = local_28 + iVar7 * 4;
      if (param_3 == iVar7 * 4) goto LAB_081b3581;
    }
    param_2[uVar6] = param_1[uVar6] ^ *(byte *)((int)param_6 + uVar6);
    if ((local_24 != 0) &&
       (param_2[uVar6 + 1] = param_1[uVar6 + 1] ^ *(byte *)((int)param_6 + uVar6 + 1), local_24 != 1
       )) {
      param_2[uVar6 + 2] = param_1[uVar6 + 2] ^ *(byte *)((int)param_6 + uVar6 + 2);
    }
  }
LAB_081b3581:
  local_28 = local_28 + param_3;
LAB_081b33f8:
  *param_7 = local_28;
  return;
}

