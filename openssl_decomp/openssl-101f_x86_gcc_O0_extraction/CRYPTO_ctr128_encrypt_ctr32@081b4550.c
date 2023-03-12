
void CRYPTO_ctr128_encrypt_ctr32
               (byte *param_1,byte *param_2,uint param_3,undefined4 param_4,char *param_5,
               undefined4 *param_6,uint *param_7,code *param_8)

{
  byte *pbVar1;
  uint *puVar2;
  char cVar3;
  byte *pbVar4;
  uint uVar5;
  uint uVar6;
  int iVar7;
  uint *puVar8;
  byte *pbVar9;
  uint uVar10;
  uint uVar11;
  uint *puVar12;
  uint local_28;
  
  uVar5 = *param_7;
  pbVar9 = param_1;
  pbVar4 = param_2;
  uVar11 = uVar5;
  if (param_3 != 0) {
    do {
      param_1 = pbVar9;
      param_2 = pbVar4;
      if (uVar11 == 0) break;
      pbVar1 = (byte *)((int)param_6 + uVar5);
      param_1 = pbVar9 + 1;
      param_2 = pbVar4 + 1;
      param_3 = param_3 - 1;
      uVar5 = uVar5 + 1 & 0xf;
      *pbVar4 = *pbVar1 ^ *pbVar9;
      pbVar9 = param_1;
      pbVar4 = param_2;
      uVar11 = param_3;
    } while (uVar5 != 0);
  }
  uVar11 = *(uint *)(param_5 + 0xc);
  uVar11 = uVar11 >> 0x18 | (uVar11 & 0xff0000) >> 8 | (uVar11 & 0xff00) << 8 | uVar11 << 0x18;
  while (uVar6 = uVar11, pbVar9 = param_1, 0xf < param_3) {
    while( true ) {
      uVar10 = param_3 >> 4;
      uVar6 = uVar10 + uVar11;
      if (CARRY4(uVar10,uVar11)) break;
      uVar11 = param_3 & 0xfffffff0;
      param_3 = param_3 - uVar11;
      pbVar9 = param_1 + uVar11;
      (*param_8)(param_1,param_2,uVar10,param_4,param_5);
      param_2 = param_2 + uVar11;
      *(uint *)(param_5 + 0xc) =
           uVar6 >> 0x18 | (uVar6 & 0xff0000) >> 8 | (uVar6 & 0xff00) << 8 | uVar6 * 0x1000000;
      uVar11 = uVar6;
      param_1 = pbVar9;
      if (param_3 < 0x10) goto LAB_081b4718;
    }
    (*param_8)(param_1,param_2,-uVar11,param_4,param_5);
    *(undefined4 *)(param_5 + 0xc) = 0;
    cVar3 = param_5[0xb];
    param_5[0xb] = cVar3 + '\x01';
    if ((((((((char)(cVar3 + '\x01') == '\0') &&
            (cVar3 = param_5[10], param_5[10] = cVar3 + '\x01', (char)(cVar3 + '\x01') == '\0')) &&
           (cVar3 = param_5[9], param_5[9] = cVar3 + '\x01', (char)(cVar3 + '\x01') == '\0')) &&
          ((cVar3 = param_5[8], param_5[8] = cVar3 + '\x01', (char)(cVar3 + '\x01') == '\0' &&
           (cVar3 = param_5[7], param_5[7] = cVar3 + '\x01', (char)(cVar3 + '\x01') == '\0')))) &&
         ((cVar3 = param_5[6], param_5[6] = cVar3 + '\x01', (char)(cVar3 + '\x01') == '\0' &&
          ((cVar3 = param_5[5], param_5[5] = cVar3 + '\x01', (char)(cVar3 + '\x01') == '\0' &&
           (cVar3 = param_5[4], param_5[4] = cVar3 + '\x01', (char)(cVar3 + '\x01') == '\0')))))) &&
        (cVar3 = param_5[3], param_5[3] = cVar3 + '\x01', (char)(cVar3 + '\x01') == '\0')) &&
       ((cVar3 = param_5[2], param_5[2] = cVar3 + '\x01', (char)(cVar3 + '\x01') == '\0' &&
        (cVar3 = param_5[1], param_5[1] = cVar3 + '\x01', (char)(cVar3 + '\x01') == '\0')))) {
      *param_5 = *param_5 + '\x01';
    }
    param_2 = param_2 + uVar11 * -0x10;
    param_1 = param_1 + uVar11 * -0x10;
    param_3 = param_3 + uVar11 * 0x10;
    uVar11 = 0;
  }
LAB_081b4718:
  if (param_3 == 0) {
    *param_7 = uVar5;
    return;
  }
  *param_6 = 0;
  param_6[1] = 0;
  param_6[2] = 0;
  param_6[3] = 0;
  (*param_8)(param_6,param_6,1,param_4,param_5);
  uVar6 = uVar6 + 1;
  *(uint *)(param_5 + 0xc) =
       uVar6 >> 0x18 | (uVar6 & 0xff0000) >> 8 | (uVar6 & 0xff00) << 8 | uVar6 * 0x1000000;
  if (((((uVar6 == 0) &&
        (cVar3 = param_5[0xb], param_5[0xb] = cVar3 + '\x01', (char)(cVar3 + '\x01') == '\0')) &&
       (cVar3 = param_5[10], param_5[10] = cVar3 + '\x01', (char)(cVar3 + '\x01') == '\0')) &&
      (((cVar3 = param_5[9], param_5[9] = cVar3 + '\x01', (char)(cVar3 + '\x01') == '\0' &&
        (cVar3 = param_5[8], param_5[8] = cVar3 + '\x01', (char)(cVar3 + '\x01') == '\0')) &&
       ((cVar3 = param_5[7], param_5[7] = cVar3 + '\x01', (char)(cVar3 + '\x01') == '\0' &&
        ((cVar3 = param_5[6], param_5[6] = cVar3 + '\x01', (char)(cVar3 + '\x01') == '\0' &&
         (cVar3 = param_5[5], param_5[5] = cVar3 + '\x01', (char)(cVar3 + '\x01') == '\0')))))))) &&
     ((cVar3 = param_5[4], param_5[4] = cVar3 + '\x01', (char)(cVar3 + '\x01') == '\0' &&
      (((cVar3 = param_5[3], param_5[3] = cVar3 + '\x01', (char)(cVar3 + '\x01') == '\0' &&
        (cVar3 = param_5[2], param_5[2] = cVar3 + '\x01', (char)(cVar3 + '\x01') == '\0')) &&
       (cVar3 = param_5[1], param_5[1] = cVar3 + '\x01', (char)(cVar3 + '\x01') == '\0')))))) {
    *param_5 = *param_5 + '\x01';
  }
  local_28 = param_3 - 1;
  iVar7 = uVar5 + 4;
  puVar8 = (uint *)(param_2 + uVar5);
  puVar12 = (uint *)((int)param_6 + uVar5);
  if (((puVar8 < (uint *)((int)param_6 + iVar7) && puVar12 < param_2 + iVar7 ||
       puVar8 < pbVar9 + iVar7 && pbVar9 + uVar5 < param_2 + iVar7) || param_3 < 7) ||
     ((((uint)puVar8 | (uint)(pbVar9 + uVar5) | (uint)puVar12) & 3) != 0)) {
    *(byte *)puVar8 = pbVar9[uVar5] ^ *(byte *)puVar12;
    if (((((local_28 != 0) &&
          ((param_2[uVar5 + 1] = pbVar9[uVar5 + 1] ^ *(byte *)((int)param_6 + uVar5 + 1),
           param_3 != 2 &&
           (param_2[uVar5 + 2] = pbVar9[uVar5 + 2] ^ *(byte *)((int)param_6 + uVar5 + 2),
           param_3 != 3)))) &&
         (param_2[uVar5 + 3] = pbVar9[uVar5 + 3] ^ *(byte *)((int)param_6 + uVar5 + 3), param_3 != 4
         )) && (((((param_2[uVar5 + 4] = pbVar9[uVar5 + 4] ^ *(byte *)((int)param_6 + uVar5 + 4),
                   param_3 != 5 &&
                   (param_2[uVar5 + 5] = pbVar9[uVar5 + 5] ^ *(byte *)((int)param_6 + uVar5 + 5),
                   param_3 != 6)) &&
                  (param_2[uVar5 + 6] = pbVar9[uVar5 + 6] ^ *(byte *)((int)param_6 + uVar5 + 6),
                  param_3 != 7)) &&
                 ((param_2[uVar5 + 7] = pbVar9[uVar5 + 7] ^ *(byte *)((int)param_6 + uVar5 + 7),
                  param_3 != 8 &&
                  (param_2[uVar5 + 8] = pbVar9[uVar5 + 8] ^ *(byte *)((int)param_6 + uVar5 + 8),
                  param_3 != 9)))) &&
                ((param_2[uVar5 + 9] = pbVar9[uVar5 + 9] ^ *(byte *)((int)param_6 + uVar5 + 9),
                 param_3 != 10 &&
                 ((param_2[uVar5 + 10] = pbVar9[uVar5 + 10] ^ *(byte *)((int)param_6 + uVar5 + 10),
                  param_3 != 0xb &&
                  (param_2[uVar5 + 0xb] =
                        pbVar9[uVar5 + 0xb] ^ *(byte *)((int)param_6 + uVar5 + 0xb), param_3 != 0xc)
                  ))))))) &&
       ((param_2[uVar5 + 0xc] = pbVar9[uVar5 + 0xc] ^ *(byte *)((int)param_6 + uVar5 + 0xc),
        param_3 != 0xd &&
        (param_2[uVar5 + 0xd] = pbVar9[uVar5 + 0xd] ^ *(byte *)((int)param_6 + uVar5 + 0xd),
        param_3 != 0xe)))) {
      param_2[uVar5 + 0xe] = pbVar9[uVar5 + 0xe] ^ *(byte *)((int)param_6 + uVar5 + 0xe);
    }
  }
  else {
    iVar7 = (param_3 - 4 >> 2) + 1;
    uVar11 = uVar5;
    if (2 < local_28) {
      puVar2 = (uint *)(pbVar9 + uVar5);
      *puVar8 = *puVar12 ^ *puVar2;
      if ((iVar7 != 1) && (puVar8[1] = puVar12[1] ^ puVar2[1], iVar7 == 3)) {
        puVar8[2] = puVar2[2] ^ puVar12[2];
      }
      local_28 = local_28 + iVar7 * -4;
      uVar11 = iVar7 * 4 + uVar5;
      if (iVar7 * 4 == param_3) goto LAB_081b495b;
    }
    param_2[uVar11] = pbVar9[uVar11] ^ *(byte *)((int)param_6 + uVar11);
    if ((local_28 != 0) &&
       (param_2[uVar11 + 1] = pbVar9[uVar11 + 1] ^ *(byte *)((int)param_6 + uVar11 + 1),
       local_28 != 1)) {
      param_2[uVar11 + 2] = pbVar9[uVar11 + 2] ^ *(byte *)((int)param_6 + uVar11 + 2);
    }
  }
LAB_081b495b:
  *param_7 = uVar5 + param_3;
  return;
}

