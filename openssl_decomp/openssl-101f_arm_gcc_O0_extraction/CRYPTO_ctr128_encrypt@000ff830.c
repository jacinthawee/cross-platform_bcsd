
void CRYPTO_ctr128_encrypt
               (byte *param_1,byte *param_2,uint param_3,undefined4 param_4,char *param_5,
               int param_6,uint *param_7,code *param_8)

{
  char cVar1;
  uint uVar2;
  byte *pbVar3;
  uint uVar4;
  int iVar5;
  int iVar6;
  byte *pbVar7;
  uint uVar8;
  uint uVar9;
  byte *pbVar10;
  
  uVar8 = *param_7;
  pbVar3 = param_1;
  pbVar7 = param_2;
  if (uVar8 != 0 && param_3 != 0) {
    do {
      pbVar10 = (byte *)(param_6 + uVar8);
      uVar4 = uVar8 + 1 & 0xf;
      param_1 = pbVar3 + 1;
      uVar8 = uVar8 + 1 & 0xf;
      if (uVar4 != 0) {
        uVar4 = 1;
      }
      param_3 = param_3 - 1;
      uVar4 = uVar4 & 1;
      if (param_3 == 0) {
        uVar4 = 0;
      }
      param_2 = pbVar7 + 1;
      *pbVar7 = *pbVar3 ^ *pbVar10;
      pbVar3 = param_1;
      pbVar7 = param_2;
    } while (uVar4 != 0);
  }
  if ((((uint)param_1 | (uint)param_2 | (uint)param_5) & 3) == 0) {
    uVar4 = param_3;
    pbVar3 = param_1;
    pbVar7 = param_2;
    if (0xf < param_3) {
      while( true ) {
        (*param_8)(param_5,param_6,param_4);
        cVar1 = param_5[0xf];
        param_5[0xf] = cVar1 + '\x01';
        if (((((char)(cVar1 + '\x01') == '\0') &&
             (cVar1 = param_5[0xe], param_5[0xe] = cVar1 + '\x01', (char)(cVar1 + '\x01') == '\0'))
            && (((cVar1 = param_5[0xd], param_5[0xd] = cVar1 + '\x01',
                 (char)(cVar1 + '\x01') == '\0' &&
                 (((cVar1 = param_5[0xc], param_5[0xc] = cVar1 + '\x01',
                   (char)(cVar1 + '\x01') == '\0' &&
                   (cVar1 = param_5[0xb], param_5[0xb] = cVar1 + '\x01',
                   (char)(cVar1 + '\x01') == '\0')) &&
                  (cVar1 = param_5[10], param_5[10] = cVar1 + '\x01', (char)(cVar1 + '\x01') == '\0'
                  )))) && ((cVar1 = param_5[9], param_5[9] = cVar1 + '\x01',
                           (char)(cVar1 + '\x01') == '\0' &&
                           (cVar1 = param_5[8], param_5[8] = cVar1 + '\x01',
                           (char)(cVar1 + '\x01') == '\0')))))) &&
           ((cVar1 = param_5[7], param_5[7] = cVar1 + '\x01', (char)(cVar1 + '\x01') == '\0' &&
            (((cVar1 = param_5[6], param_5[6] = cVar1 + '\x01', (char)(cVar1 + '\x01') == '\0' &&
              (cVar1 = param_5[5], param_5[5] = cVar1 + '\x01', (char)(cVar1 + '\x01') == '\0')) &&
             ((cVar1 = param_5[4], param_5[4] = cVar1 + '\x01', (char)(cVar1 + '\x01') == '\0' &&
              (((cVar1 = param_5[3], param_5[3] = cVar1 + '\x01', (char)(cVar1 + '\x01') == '\0' &&
                (cVar1 = param_5[2], param_5[2] = cVar1 + '\x01', (char)(cVar1 + '\x01') == '\0'))
               && (cVar1 = param_5[1], param_5[1] = cVar1 + '\x01', (char)(cVar1 + '\x01') == '\0'))
              )))))))) {
          *param_5 = *param_5 + '\x01';
        }
        if (uVar8 < 0x10) {
          uVar9 = uVar8 + 4;
          *(uint *)(pbVar7 + uVar8) = *(uint *)(pbVar3 + uVar8) ^ *(uint *)(param_6 + uVar8);
          if (uVar9 < 0x10) {
            uVar2 = uVar8 + 8;
            *(uint *)(pbVar7 + uVar9) = *(uint *)(pbVar3 + uVar9) ^ *(uint *)(param_6 + uVar9);
            if (uVar2 < 0x10) {
              uVar8 = uVar8 + 0xc;
              *(uint *)(pbVar7 + uVar2) = *(uint *)(pbVar3 + uVar2) ^ *(uint *)(param_6 + uVar2);
              if (uVar8 < 0x10) {
                *(uint *)(pbVar7 + uVar8) = *(uint *)(pbVar3 + uVar8) ^ *(uint *)(param_6 + uVar8);
              }
            }
          }
        }
        if (uVar4 - 0x10 < 0x10) break;
        uVar8 = 0;
        uVar4 = uVar4 - 0x10;
        pbVar3 = pbVar3 + 0x10;
        pbVar7 = pbVar7 + 0x10;
      }
      uVar8 = 0;
      uVar4 = param_3 - 0x10;
      param_3 = param_3 & 0xf;
      iVar5 = (uVar4 & 0xfffffff0) + 0x10;
      param_2 = param_2 + iVar5;
      param_1 = param_1 + iVar5;
    }
    if (param_3 != 0) {
      (*param_8)(param_5,param_6,param_4);
      cVar1 = param_5[0xf];
      param_5[0xf] = cVar1 + '\x01';
      if (((((char)(cVar1 + '\x01') == '\0') &&
           (cVar1 = param_5[0xe], param_5[0xe] = cVar1 + '\x01', (char)(cVar1 + '\x01') == '\0')) &&
          ((cVar1 = param_5[0xd], param_5[0xd] = cVar1 + '\x01', (char)(cVar1 + '\x01') == '\0' &&
           ((cVar1 = param_5[0xc], param_5[0xc] = cVar1 + '\x01', (char)(cVar1 + '\x01') == '\0' &&
            (cVar1 = param_5[0xb], param_5[0xb] = cVar1 + '\x01', (char)(cVar1 + '\x01') == '\0'))))
          )) && ((cVar1 = param_5[10], param_5[10] = cVar1 + '\x01', (char)(cVar1 + '\x01') == '\0'
                 && ((((((cVar1 = param_5[9], param_5[9] = cVar1 + '\x01',
                         (char)(cVar1 + '\x01') == '\0' &&
                         (cVar1 = param_5[8], param_5[8] = cVar1 + '\x01',
                         (char)(cVar1 + '\x01') == '\0')) &&
                        (cVar1 = param_5[7], param_5[7] = cVar1 + '\x01',
                        (char)(cVar1 + '\x01') == '\0')) &&
                       ((cVar1 = param_5[6], param_5[6] = cVar1 + '\x01',
                        (char)(cVar1 + '\x01') == '\0' &&
                        (cVar1 = param_5[5], param_5[5] = cVar1 + '\x01',
                        (char)(cVar1 + '\x01') == '\0')))) &&
                      ((cVar1 = param_5[4], param_5[4] = cVar1 + '\x01',
                       (char)(cVar1 + '\x01') == '\0' &&
                       ((cVar1 = param_5[3], param_5[3] = cVar1 + '\x01',
                        (char)(cVar1 + '\x01') == '\0' &&
                        (cVar1 = param_5[2], param_5[2] = cVar1 + '\x01',
                        (char)(cVar1 + '\x01') == '\0')))))) &&
                     (cVar1 = param_5[1], param_5[1] = cVar1 + '\x01',
                     (char)(cVar1 + '\x01') == '\0')))))) {
        *param_5 = *param_5 + '\x01';
      }
      pbVar3 = param_2 + uVar8;
      pbVar10 = (byte *)(param_6 + uVar8);
      pbVar7 = param_1 + uVar8;
      if ((((uint)pbVar10 | (uint)pbVar3 | (uint)pbVar7) & 3) == 0 &&
          (6 < param_3 &&
          ((pbVar7 + 4 <= pbVar3 || pbVar3 + 4 <= pbVar7) &&
          (pbVar10 + 4 <= pbVar3 || pbVar3 + 4 <= pbVar10)))) {
        iVar5 = 0;
        uVar4 = 0;
        uVar9 = param_3 & 0xfffffffc;
        do {
          uVar4 = uVar4 + 1;
          *(uint *)(pbVar3 + iVar5) = *(uint *)(pbVar10 + iVar5) ^ *(uint *)(pbVar7 + iVar5);
          iVar5 = iVar5 + 4;
        } while (uVar4 < param_3 >> 2);
        uVar4 = uVar9 + uVar8;
        if (uVar9 != param_3) {
          iVar5 = uVar4 + 1;
          param_2[uVar4] = *(byte *)(param_6 + uVar4) ^ param_1[uVar4];
          if (param_3 - 1 != uVar9) {
            iVar6 = uVar4 + 2;
            param_2[iVar5] = *(byte *)(param_6 + iVar5) ^ param_1[iVar5];
            if ((param_3 - 1) - uVar9 != 1) {
              uVar4 = param_3 + uVar8;
              param_2[iVar6] = *(byte *)(param_6 + iVar6) ^ param_1[iVar6];
              goto LAB_000ffc5a;
            }
          }
          uVar4 = param_3 + uVar8;
        }
      }
      else {
        uVar4 = param_3 + uVar8;
        do {
          param_2[uVar8] = *(byte *)(param_6 + uVar8) ^ param_1[uVar8];
          uVar8 = uVar8 + 1;
        } while (uVar8 != uVar4);
      }
LAB_000ffc5a:
      *param_7 = uVar4;
      return;
    }
  }
  else {
    uVar4 = 0;
    if (param_3 != 0) {
      do {
        if (uVar8 == 0) {
          (*param_8)(param_5,param_6,param_4);
          cVar1 = param_5[0xf];
          param_5[0xf] = cVar1 + '\x01';
          if (((((((char)(cVar1 + '\x01') == '\0') &&
                 (cVar1 = param_5[0xe], param_5[0xe] = cVar1 + '\x01',
                 (char)(cVar1 + '\x01') == '\0')) &&
                (cVar1 = param_5[0xd], param_5[0xd] = cVar1 + '\x01', (char)(cVar1 + '\x01') == '\0'
                )) && ((cVar1 = param_5[0xc], param_5[0xc] = cVar1 + '\x01',
                       (char)(cVar1 + '\x01') == '\0' &&
                       (cVar1 = param_5[0xb], param_5[0xb] = cVar1 + '\x01',
                       (char)(cVar1 + '\x01') == '\0')))) &&
              ((cVar1 = param_5[10], param_5[10] = cVar1 + '\x01', (char)(cVar1 + '\x01') == '\0' &&
               ((cVar1 = param_5[9], param_5[9] = cVar1 + '\x01', (char)(cVar1 + '\x01') == '\0' &&
                (cVar1 = param_5[8], param_5[8] = cVar1 + '\x01', (char)(cVar1 + '\x01') == '\0'))))
              )) && ((cVar1 = param_5[7], param_5[7] = cVar1 + '\x01',
                     (char)(cVar1 + '\x01') == '\0' &&
                     ((((cVar1 = param_5[6], param_5[6] = cVar1 + '\x01',
                        (char)(cVar1 + '\x01') == '\0' &&
                        (cVar1 = param_5[5], param_5[5] = cVar1 + '\x01',
                        (char)(cVar1 + '\x01') == '\0')) &&
                       (cVar1 = param_5[4], param_5[4] = cVar1 + '\x01',
                       (char)(cVar1 + '\x01') == '\0')) &&
                      (((cVar1 = param_5[3], param_5[3] = cVar1 + '\x01',
                        (char)(cVar1 + '\x01') == '\0' &&
                        (cVar1 = param_5[2], param_5[2] = cVar1 + '\x01',
                        (char)(cVar1 + '\x01') == '\0')) &&
                       (cVar1 = param_5[1], param_5[1] = cVar1 + '\x01',
                       (char)(cVar1 + '\x01') == '\0')))))))) {
            *param_5 = *param_5 + '\x01';
          }
        }
        pbVar3 = (byte *)(param_6 + uVar8);
        uVar8 = uVar8 + 1 & 0xf;
        param_2[uVar4] = param_1[uVar4] ^ *pbVar3;
        uVar4 = uVar4 + 1;
      } while (uVar4 != param_3);
    }
  }
  *param_7 = uVar8;
  return;
}

