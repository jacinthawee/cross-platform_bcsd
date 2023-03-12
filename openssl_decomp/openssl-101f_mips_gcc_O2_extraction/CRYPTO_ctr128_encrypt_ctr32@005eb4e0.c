
void CRYPTO_ctr128_encrypt_ctr32
               (uint *param_1,uint *param_2,uint param_3,undefined4 param_4,char *param_5,
               uint *param_6,uint *param_7,code *param_8)

{
  byte bVar1;
  char cVar2;
  uint uVar3;
  uint uVar4;
  int iVar5;
  int iVar6;
  uint local_2c;
  
  for (uVar3 = *param_7; uVar3 != 0; uVar3 = uVar3 + 1 & 0xf) {
    if (param_3 == 0) {
      *param_7 = uVar3;
      return;
    }
    bVar1 = *(byte *)param_1;
    param_1 = (uint *)((int)param_1 + 1);
    param_3 = param_3 - 1;
    *(byte *)param_2 = *(byte *)((int)param_6 + uVar3) ^ bVar1;
    param_2 = (uint *)((int)param_2 + 1);
  }
  local_2c = *(uint *)(param_5 + 0xc);
  for (; uVar3 = local_2c, 0xf < param_3; param_3 = param_3 + uVar3 * 0x10) {
    while( true ) {
      uVar4 = param_3 >> 4;
      local_2c = uVar4 + uVar3;
      if (local_2c < uVar4) break;
      uVar3 = param_3 & 0xfffffff0;
      (*param_8)(param_1,param_2,uVar4,param_4,param_5);
      param_5[0xf] = (char)local_2c;
      param_3 = param_3 - uVar3;
      param_5[0xe] = (char)(local_2c >> 8);
      param_5[0xc] = (char)(local_2c >> 0x18);
      param_2 = (uint *)((int)param_2 + uVar3);
      param_5[0xd] = (char)(local_2c >> 0x10);
      param_1 = (uint *)((int)param_1 + uVar3);
      uVar3 = local_2c;
      if (param_3 < 0x10) goto LAB_005eb72c;
    }
    (*param_8)(param_1,param_2,-uVar3,param_4,param_5);
    cVar2 = param_5[0xb];
    param_5[0xc] = '\0';
    param_5[0xd] = '\0';
    param_5[0xe] = '\0';
    param_5[0xf] = '\0';
    param_5[0xb] = cVar2 + '\x01';
    if ((((((((char)(cVar2 + '\x01') == '\0') &&
            (cVar2 = param_5[10], param_5[10] = cVar2 + '\x01', (char)(cVar2 + '\x01') == '\0')) &&
           (cVar2 = param_5[9], param_5[9] = cVar2 + '\x01', (char)(cVar2 + '\x01') == '\0')) &&
          ((cVar2 = param_5[8], param_5[8] = cVar2 + '\x01', (char)(cVar2 + '\x01') == '\0' &&
           (cVar2 = param_5[7], param_5[7] = cVar2 + '\x01', (char)(cVar2 + '\x01') == '\0')))) &&
         ((cVar2 = param_5[6], param_5[6] = cVar2 + '\x01', (char)(cVar2 + '\x01') == '\0' &&
          ((cVar2 = param_5[5], param_5[5] = cVar2 + '\x01', (char)(cVar2 + '\x01') == '\0' &&
           (cVar2 = param_5[4], param_5[4] = cVar2 + '\x01', (char)(cVar2 + '\x01') == '\0')))))) &&
        (cVar2 = param_5[3], param_5[3] = cVar2 + '\x01', (char)(cVar2 + '\x01') == '\0')) &&
       ((cVar2 = param_5[2], param_5[2] = cVar2 + '\x01', (char)(cVar2 + '\x01') == '\0' &&
        (cVar2 = param_5[1], param_5[1] = cVar2 + '\x01', (char)(cVar2 + '\x01') == '\0')))) {
      *param_5 = *param_5 + '\x01';
    }
    local_2c = 0;
    param_2 = param_2 + uVar3 * -4;
    param_1 = param_1 + uVar3 * -4;
  }
LAB_005eb72c:
  if (param_3 != 0) {
    (*(code *)PTR_memset_006aab00)(param_6,0,0x10);
    (*param_8)(param_6,param_6,1,param_4,param_5);
    iVar5 = local_2c + 1;
    param_5[0xf] = (char)iVar5;
    param_5[0xc] = (char)((uint)iVar5 >> 0x18);
    param_5[0xd] = (char)((uint)iVar5 >> 0x10);
    param_5[0xe] = (char)((uint)iVar5 >> 8);
    if (((((iVar5 == 0) &&
          (cVar2 = param_5[0xb], param_5[0xb] = cVar2 + '\x01', (char)(cVar2 + '\x01') == '\0')) &&
         (cVar2 = param_5[10], param_5[10] = cVar2 + '\x01', (char)(cVar2 + '\x01') == '\0')) &&
        (((cVar2 = param_5[9], param_5[9] = cVar2 + '\x01', (char)(cVar2 + '\x01') == '\0' &&
          (cVar2 = param_5[8], param_5[8] = cVar2 + '\x01', (char)(cVar2 + '\x01') == '\0')) &&
         ((cVar2 = param_5[7], param_5[7] = cVar2 + '\x01', (char)(cVar2 + '\x01') == '\0' &&
          ((cVar2 = param_5[6], param_5[6] = cVar2 + '\x01', (char)(cVar2 + '\x01') == '\0' &&
           (cVar2 = param_5[5], param_5[5] = cVar2 + '\x01', (char)(cVar2 + '\x01') == '\0'))))))))
       && ((cVar2 = param_5[4], param_5[4] = cVar2 + '\x01', (char)(cVar2 + '\x01') == '\0' &&
           (((cVar2 = param_5[3], param_5[3] = cVar2 + '\x01', (char)(cVar2 + '\x01') == '\0' &&
             (cVar2 = param_5[2], param_5[2] = cVar2 + '\x01', (char)(cVar2 + '\x01') == '\0')) &&
            (cVar2 = param_5[1], param_5[1] = cVar2 + '\x01', (char)(cVar2 + '\x01') == '\0')))))) {
      *param_5 = *param_5 + '\x01';
    }
    uVar3 = param_3 - 1;
    if ((param_3 < 7 ||
         (param_2 < param_6 + 1 && param_6 < param_2 + 1 ||
         param_2 < param_1 + 1 && param_1 < param_2 + 1)) ||
       ((((uint)param_6 | (uint)param_1 | (uint)param_2) & 3) != 0)) {
      *(byte *)param_2 = *(byte *)param_6 ^ *(byte *)param_1;
      if (((((uVar3 != 0) &&
            ((*(byte *)((int)param_2 + 1) =
                   *(byte *)((int)param_1 + 1) ^ *(byte *)((int)param_6 + 1), param_3 != 2 &&
             (*(byte *)((int)param_2 + 2) =
                   *(byte *)((int)param_1 + 2) ^ *(byte *)((int)param_6 + 2), param_3 != 3)))) &&
           (*(byte *)((int)param_2 + 3) = *(byte *)((int)param_1 + 3) ^ *(byte *)((int)param_6 + 3),
           param_3 != 4)) &&
          (((((*(byte *)(param_2 + 1) = *(byte *)(param_1 + 1) ^ *(byte *)(param_6 + 1),
              param_3 != 5 &&
              (*(byte *)((int)param_2 + 5) =
                    *(byte *)((int)param_1 + 5) ^ *(byte *)((int)param_6 + 5), param_3 != 6)) &&
             (*(byte *)((int)param_2 + 6) =
                   *(byte *)((int)param_1 + 6) ^ *(byte *)((int)param_6 + 6), param_3 != 7)) &&
            ((*(byte *)((int)param_2 + 7) =
                   *(byte *)((int)param_1 + 7) ^ *(byte *)((int)param_6 + 7), param_3 != 8 &&
             (*(byte *)(param_2 + 2) = *(byte *)(param_1 + 2) ^ *(byte *)(param_6 + 2), param_3 != 9
             )))) && ((*(byte *)((int)param_2 + 9) =
                            *(byte *)((int)param_1 + 9) ^ *(byte *)((int)param_6 + 9), param_3 != 10
                      && ((*(byte *)((int)param_2 + 10) =
                                *(byte *)((int)param_1 + 10) ^ *(byte *)((int)param_6 + 10),
                          param_3 != 0xb &&
                          (*(byte *)((int)param_2 + 0xb) =
                                *(byte *)((int)param_1 + 0xb) ^ *(byte *)((int)param_6 + 0xb),
                          param_3 != 0xc)))))))) &&
         ((*(byte *)(param_2 + 3) = *(byte *)(param_1 + 3) ^ *(byte *)(param_6 + 3), param_3 != 0xd
          && (*(byte *)((int)param_2 + 0xd) =
                   *(byte *)((int)param_1 + 0xd) ^ *(byte *)((int)param_6 + 0xd), param_3 != 0xe))))
      {
        *(byte *)((int)param_2 + 0xe) =
             *(byte *)((int)param_1 + 0xe) ^ *(byte *)((int)param_6 + 0xe);
      }
    }
    else {
      iVar5 = (param_3 - 4 >> 2) + 1;
      uVar4 = iVar5 * 4;
      if (uVar3 < 3) {
        uVar4 = 0;
        *(byte *)param_2 = *(byte *)param_1 ^ *(byte *)param_6;
      }
      else {
        *param_2 = *param_6 ^ *param_1;
        if ((iVar5 != 1) && (param_2[1] = param_6[1] ^ param_1[1], iVar5 == 3)) {
          param_2[2] = param_6[2] ^ param_1[2];
        }
        uVar3 = uVar3 + iVar5 * -4;
        if (uVar4 == param_3) goto LAB_005eb998;
        *(byte *)(param_2 + iVar5) = *(byte *)(param_1 + iVar5) ^ *(byte *)(param_6 + iVar5);
      }
      if (uVar3 != 0) {
        iVar6 = uVar4 + 1;
        iVar5 = uVar4 + 2;
        *(byte *)((int)param_2 + iVar6) =
             *(byte *)((int)param_1 + iVar6) ^ *(byte *)((int)param_6 + iVar6);
        if (uVar3 != 1) {
          *(byte *)((int)param_2 + iVar5) =
               *(byte *)((int)param_6 + iVar5) ^ *(byte *)((int)param_1 + iVar5);
        }
      }
    }
  }
LAB_005eb998:
  *param_7 = param_3;
  return;
}

