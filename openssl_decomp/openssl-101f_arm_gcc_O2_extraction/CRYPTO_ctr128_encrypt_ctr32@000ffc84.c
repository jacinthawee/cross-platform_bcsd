
void CRYPTO_ctr128_encrypt_ctr32
               (byte *param_1,byte *param_2,uint param_3,undefined4 param_4,char *param_5,
               void *param_6,uint *param_7,code *param_8)

{
  char cVar1;
  byte bVar2;
  uint uVar3;
  byte *pbVar4;
  byte bVar5;
  int iVar6;
  byte *pbVar7;
  int iVar8;
  byte *pbVar9;
  uint uVar10;
  byte *pbVar11;
  byte *pbVar12;
  uint uVar13;
  uint uVar14;
  bool bVar15;
  bool bVar16;
  
  uVar14 = *param_7;
  pbVar12 = param_1;
  pbVar4 = param_2;
  if (uVar14 != 0 && param_3 != 0) {
    do {
      pbVar7 = (byte *)((int)param_6 + uVar14);
      uVar3 = uVar14 + 1 & 0xf;
      param_1 = pbVar12 + 1;
      uVar14 = uVar14 + 1 & 0xf;
      if (uVar3 != 0) {
        uVar3 = 1;
      }
      param_3 = param_3 - 1;
      uVar3 = uVar3 & 1;
      if (param_3 == 0) {
        uVar3 = 0;
      }
      param_2 = pbVar4 + 1;
      *pbVar4 = *pbVar12 ^ *pbVar7;
      pbVar12 = param_1;
      pbVar4 = param_2;
    } while (uVar3 != 0);
  }
  uVar3 = (uint)(byte)param_5[0xd] << 0x10 | (uint)(byte)param_5[0xc] << 0x18 |
          (uint)(byte)param_5[0xf] | (uint)(byte)param_5[0xe] << 8;
  while (pbVar12 = param_2, uVar13 = uVar3, 0xf < param_3) {
    while( true ) {
      uVar10 = param_3 >> 4;
      uVar13 = uVar10 + uVar3;
      if (CARRY4(uVar10,uVar3) != false) break;
      uVar3 = param_3 & 0xfffffff0;
      param_3 = param_3 - uVar3;
      pbVar12 = param_2 + uVar3;
      (*param_8)(param_1,param_2,uVar10,param_4,param_5);
      param_5[0xf] = (char)uVar13;
      param_5[0xc] = (char)(uVar13 >> 0x18);
      param_5[0xd] = (char)(uVar13 >> 0x10);
      param_5[0xe] = (char)(uVar13 >> 8);
      param_1 = param_1 + uVar3;
      param_2 = pbVar12;
      uVar3 = uVar13;
      if (param_3 < 0x10) goto LAB_000ffe06;
    }
    (*param_8)(param_1,param_2,-uVar3,param_4,param_5);
    bVar5 = param_5[0xb] + 1;
    param_5[0xc] = '\0';
    param_5[0xd] = '\0';
    param_5[0xe] = '\0';
    param_5[0xf] = '\0';
    param_5[0xb] = bVar5;
    if (bVar5 != 0) goto LAB_000ffe1c;
    bVar2 = param_5[10] + 1;
    param_5[10] = bVar2;
    uVar13 = (uint)bVar5;
    if (bVar2 == 0) {
      bVar5 = param_5[9] + 1;
      param_5[9] = bVar5;
      uVar13 = (uint)bVar2;
      if (bVar5 == 0) {
        bVar2 = param_5[8] + 1;
        param_5[8] = bVar2;
        uVar13 = (uint)bVar5;
        if (bVar2 == 0) {
          bVar5 = param_5[7] + 1;
          param_5[7] = bVar5;
          uVar13 = (uint)bVar2;
          if (bVar5 == 0) {
            bVar2 = param_5[6] + 1;
            param_5[6] = bVar2;
            uVar13 = (uint)bVar5;
            if (bVar2 == 0) {
              bVar5 = param_5[5] + 1;
              param_5[5] = bVar5;
              uVar13 = (uint)bVar2;
              if ((bVar5 == 0) &&
                 (cVar1 = param_5[4], param_5[4] = cVar1 + '\x01', uVar13 = (uint)bVar5,
                 (char)(cVar1 + '\x01') == '\0')) {
                cVar1 = param_5[3];
                param_5[3] = cVar1 + '\x01';
                if ((char)(cVar1 + '\x01') == '\0') {
                  uVar13 = (uint)(byte)(param_5[2] + 1U);
                  param_5[2] = param_5[2] + 1U;
                  if (uVar13 == 0) {
                    bVar5 = param_5[1] + 1;
                    param_5[1] = bVar5;
                    if (bVar5 == 0) {
                      *param_5 = *param_5 + '\x01';
                      uVar13 = (uint)bVar5;
                    }
                    goto LAB_000ffdb4;
                  }
                }
LAB_000ffe1c:
                uVar13 = 0;
              }
            }
          }
        }
      }
    }
LAB_000ffdb4:
    param_2 = param_2 + uVar3 * -0x10;
    param_1 = param_1 + uVar3 * -0x10;
    param_3 = param_3 + uVar3 * 0x10;
    uVar3 = uVar13;
  }
LAB_000ffe06:
  if (param_3 == 0) {
    *param_7 = uVar14;
    return;
  }
  memset(param_6,0,0x10);
  (*param_8)(param_6,param_6,1,param_4,param_5);
  iVar6 = uVar13 + 1;
  param_5[0xf] = (char)iVar6;
  param_5[0xc] = (char)((uint)iVar6 >> 0x18);
  param_5[0xd] = (char)((uint)iVar6 >> 0x10);
  param_5[0xe] = (char)((uint)iVar6 >> 8);
  if (((((iVar6 == 0) &&
        (cVar1 = param_5[0xb], param_5[0xb] = cVar1 + '\x01', (char)(cVar1 + '\x01') == '\0')) &&
       (cVar1 = param_5[10], param_5[10] = cVar1 + '\x01', (char)(cVar1 + '\x01') == '\0')) &&
      ((((cVar1 = param_5[9], param_5[9] = cVar1 + '\x01', (char)(cVar1 + '\x01') == '\0' &&
         (cVar1 = param_5[8], param_5[8] = cVar1 + '\x01', (char)(cVar1 + '\x01') == '\0')) &&
        ((cVar1 = param_5[7], param_5[7] = cVar1 + '\x01', (char)(cVar1 + '\x01') == '\0' &&
         ((cVar1 = param_5[6], param_5[6] = cVar1 + '\x01', (char)(cVar1 + '\x01') == '\0' &&
          (cVar1 = param_5[5], param_5[5] = cVar1 + '\x01', (char)(cVar1 + '\x01') == '\0')))))) &&
       (cVar1 = param_5[4], param_5[4] = cVar1 + '\x01', (char)(cVar1 + '\x01') == '\0')))) &&
     (((cVar1 = param_5[3], param_5[3] = cVar1 + '\x01', (char)(cVar1 + '\x01') == '\0' &&
       (cVar1 = param_5[2], param_5[2] = cVar1 + '\x01', (char)(cVar1 + '\x01') == '\0')) &&
      (cVar1 = param_5[1], param_5[1] = cVar1 + '\x01', (char)(cVar1 + '\x01') == '\0')))) {
    *param_5 = *param_5 + '\x01';
  }
  pbVar4 = pbVar12 + uVar14;
  pbVar7 = pbVar4 + 4;
  pbVar11 = param_1 + uVar14;
  pbVar9 = (byte *)((int)param_6 + uVar14);
  bVar16 = pbVar4 <= pbVar9 + 4;
  bVar15 = pbVar9 + 4 == pbVar4;
  if (bVar16 && !bVar15) {
    bVar16 = pbVar9 <= pbVar7;
    bVar15 = pbVar7 == pbVar9;
  }
  if ((((uint)pbVar4 | (uint)pbVar11 | (uint)pbVar9) & 3) != 0 ||
      (param_3 < 7 || (bVar16 && !bVar15 || pbVar4 < pbVar11 + 4 && pbVar11 < pbVar7))) {
    uVar3 = param_3 + uVar14;
    do {
      pbVar12[uVar14] = *(byte *)((int)param_6 + uVar14) ^ param_1[uVar14];
      uVar14 = uVar14 + 1;
    } while (uVar14 != uVar3);
  }
  else {
    iVar6 = 0;
    uVar3 = 0;
    uVar13 = param_3 & 0xfffffffc;
    do {
      uVar3 = uVar3 + 1;
      *(uint *)(pbVar4 + iVar6) = *(uint *)(pbVar11 + iVar6) ^ *(uint *)(pbVar9 + iVar6);
      iVar6 = iVar6 + 4;
    } while (uVar3 < param_3 >> 2);
    uVar3 = uVar13 + uVar14;
    if (param_3 != uVar13) {
      iVar6 = uVar3 + 1;
      pbVar12[uVar3] = param_1[uVar3] ^ *(byte *)((int)param_6 + uVar3);
      if (param_3 - 1 != uVar13) {
        iVar8 = uVar3 + 2;
        pbVar12[iVar6] = param_1[iVar6] ^ *(byte *)((int)param_6 + iVar6);
        if ((param_3 - 1) - uVar13 != 1) {
          uVar3 = param_3 + uVar14;
          pbVar12[iVar8] = *(byte *)((int)param_6 + iVar8) ^ param_1[iVar8];
          goto LAB_000fff84;
        }
      }
      uVar3 = param_3 + uVar14;
    }
  }
LAB_000fff84:
  *param_7 = uVar3;
  return;
}

