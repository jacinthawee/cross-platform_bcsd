
void CRYPTO_ctr128_encrypt_ctr32
               (uint *param_1,uint *param_2,uint param_3,undefined4 param_4,char *param_5,
               uint *param_6,uint *param_7,code *param_8)

{
  byte bVar1;
  uint uVar2;
  uint uVar3;
  int iVar4;
  int iVar5;
  uint uVar6;
  uint uVar7;
  uint local_2c;
  
  for (uVar2 = *param_7; uVar2 != 0; uVar2 = uVar2 + 1 & 0xf) {
    if (param_3 == 0) {
      *param_7 = uVar2;
      return;
    }
    bVar1 = *(byte *)param_1;
    param_1 = (uint *)((int)param_1 + 1);
    param_3 = param_3 - 1;
    *(byte *)param_2 = *(byte *)((int)param_6 + uVar2) ^ bVar1;
    param_2 = (uint *)((int)param_2 + 1);
  }
  local_2c = *(uint *)(param_5 + 0xc);
  for (; uVar2 = local_2c, 0xf < param_3; param_3 = param_3 + uVar2 * 0x10) {
    while( true ) {
      uVar3 = param_3 >> 4;
      local_2c = uVar3 + uVar2;
      if (local_2c < uVar3) break;
      uVar2 = param_3 & 0xfffffff0;
      (*param_8)(param_1,param_2,uVar3,param_4,param_5);
      param_5[0xf] = (char)local_2c;
      param_3 = param_3 - uVar2;
      param_5[0xe] = (char)(local_2c >> 8);
      param_5[0xc] = (char)(local_2c >> 0x18);
      param_2 = (uint *)((int)param_2 + uVar2);
      param_5[0xd] = (char)(local_2c >> 0x10);
      param_1 = (uint *)((int)param_1 + uVar2);
      uVar2 = local_2c;
      if (param_3 < 0x10) goto LAB_005e96d4;
    }
    (*param_8)(param_1,param_2,-uVar2,param_4,param_5);
    local_2c = 0;
    param_2 = param_2 + uVar2 * -4;
    param_1 = param_1 + uVar2 * -4;
    uVar7 = (uint)(byte)param_5[10] + ((byte)param_5[0xb] + 1 >> 8);
    param_5[0xb] = (char)((byte)param_5[0xb] + 1);
    uVar6 = (uint)(byte)param_5[9] + (uVar7 >> 8);
    param_5[0xc] = '\0';
    uVar3 = (uint)(byte)param_5[8] + (uVar6 >> 8);
    param_5[0xd] = '\0';
    param_5[0xe] = '\0';
    param_5[0xf] = '\0';
    param_5[8] = (char)uVar3;
    uVar3 = (uint)(byte)param_5[7] + (uVar3 >> 8);
    param_5[10] = (char)uVar7;
    param_5[9] = (char)uVar6;
    param_5[7] = (char)uVar3;
    uVar3 = (uint)(byte)param_5[6] + (uVar3 >> 8);
    param_5[6] = (char)uVar3;
    uVar3 = (uint)(byte)param_5[5] + (uVar3 >> 8);
    param_5[5] = (char)uVar3;
    uVar3 = (uint)(byte)param_5[4] + (uVar3 >> 8);
    param_5[4] = (char)uVar3;
    uVar3 = (uint)(byte)param_5[3] + (uVar3 >> 8);
    param_5[3] = (char)uVar3;
    uVar3 = (uint)(byte)param_5[2] + (uVar3 >> 8);
    param_5[2] = (char)uVar3;
    iVar4 = (uint)(byte)param_5[1] + (uVar3 >> 8);
    param_5[1] = (char)iVar4;
    *param_5 = *param_5 + (char)((uint)iVar4 >> 8);
  }
LAB_005e96d4:
  if (param_3 != 0) {
    (*(code *)PTR_memset_006a99f4)(param_6,0,0x10);
    (*param_8)(param_6,param_6,1,param_4,param_5);
    iVar4 = local_2c + 1;
    param_5[0xf] = (char)iVar4;
    param_5[0xc] = (char)((uint)iVar4 >> 0x18);
    param_5[0xd] = (char)((uint)iVar4 >> 0x10);
    param_5[0xe] = (char)((uint)iVar4 >> 8);
    if (iVar4 == 0) {
      bVar1 = param_5[0xb];
      param_5[0xb] = (char)(bVar1 + 1);
      uVar3 = (uint)(byte)param_5[10] + (bVar1 + 1 >> 8);
      uVar2 = (uint)(byte)param_5[9] + (uVar3 >> 8);
      param_5[10] = (char)uVar3;
      param_5[9] = (char)uVar2;
      uVar2 = (uint)(byte)param_5[8] + (uVar2 >> 8);
      param_5[8] = (char)uVar2;
      uVar2 = (uint)(byte)param_5[7] + (uVar2 >> 8);
      param_5[7] = (char)uVar2;
      uVar2 = (uint)(byte)param_5[6] + (uVar2 >> 8);
      param_5[6] = (char)uVar2;
      uVar2 = (uint)(byte)param_5[5] + (uVar2 >> 8);
      param_5[5] = (char)uVar2;
      uVar2 = (uint)(byte)param_5[4] + (uVar2 >> 8);
      param_5[4] = (char)uVar2;
      uVar2 = (uint)(byte)param_5[3] + (uVar2 >> 8);
      param_5[3] = (char)uVar2;
      uVar2 = (uint)(byte)param_5[2] + (uVar2 >> 8);
      param_5[2] = (char)uVar2;
      iVar4 = (uint)(byte)param_5[1] + (uVar2 >> 8);
      param_5[1] = (char)iVar4;
      *param_5 = *param_5 + (char)((uint)iVar4 >> 8);
    }
    uVar2 = param_3 - 1;
    if ((param_3 < 7 ||
         (param_2 < param_6 + 1 && param_6 < param_2 + 1 ||
         param_2 < param_1 + 1 && param_1 < param_2 + 1)) ||
       ((((uint)param_6 | (uint)param_1 | (uint)param_2) & 3) != 0)) {
      *(byte *)param_2 = *(byte *)param_1 ^ *(byte *)param_6;
      if (((((uVar2 != 0) &&
            (((*(byte *)((int)param_2 + 1) =
                    *(byte *)((int)param_1 + 1) ^ *(byte *)((int)param_6 + 1), param_3 != 2 &&
              (*(byte *)((int)param_2 + 2) =
                    *(byte *)((int)param_1 + 2) ^ *(byte *)((int)param_6 + 2), param_3 != 3)) &&
             (*(byte *)((int)param_2 + 3) =
                   *(byte *)((int)param_1 + 3) ^ *(byte *)((int)param_6 + 3), param_3 != 4)))) &&
           (((*(byte *)(param_2 + 1) = *(byte *)(param_1 + 1) ^ *(byte *)(param_6 + 1), param_3 != 5
             && (*(byte *)((int)param_2 + 5) =
                      *(byte *)((int)param_1 + 5) ^ *(byte *)((int)param_6 + 5), param_3 != 6)) &&
            (*(byte *)((int)param_2 + 6) = *(byte *)((int)param_1 + 6) ^ *(byte *)((int)param_6 + 6)
            , param_3 != 7)))) &&
          ((*(byte *)((int)param_2 + 7) = *(byte *)((int)param_1 + 7) ^ *(byte *)((int)param_6 + 7),
           param_3 != 8 &&
           (*(byte *)(param_2 + 2) = *(byte *)(param_1 + 2) ^ *(byte *)(param_6 + 2), param_3 != 9))
          )) && ((*(byte *)((int)param_2 + 9) =
                       *(byte *)((int)param_1 + 9) ^ *(byte *)((int)param_6 + 9), param_3 != 10 &&
                 ((((*(byte *)((int)param_2 + 10) =
                          *(byte *)((int)param_1 + 10) ^ *(byte *)((int)param_6 + 10),
                    param_3 != 0xb &&
                    (*(byte *)((int)param_2 + 0xb) =
                          *(byte *)((int)param_1 + 0xb) ^ *(byte *)((int)param_6 + 0xb),
                    param_3 != 0xc)) &&
                   (*(byte *)(param_2 + 3) = *(byte *)(param_1 + 3) ^ *(byte *)(param_6 + 3),
                   param_3 != 0xd)) &&
                  (*(byte *)((int)param_2 + 0xd) =
                        *(byte *)((int)param_1 + 0xd) ^ *(byte *)((int)param_6 + 0xd),
                  param_3 != 0xe)))))) {
        *(byte *)((int)param_2 + 0xe) =
             *(byte *)((int)param_1 + 0xe) ^ *(byte *)((int)param_6 + 0xe);
      }
    }
    else {
      iVar4 = (param_3 - 4 >> 2) + 1;
      uVar3 = iVar4 * 4;
      if (uVar2 < 3) {
        uVar3 = 0;
        *(byte *)param_2 = *(byte *)param_1 ^ *(byte *)param_6;
      }
      else {
        *param_2 = *param_1 ^ *param_6;
        if ((iVar4 != 1) && (param_2[1] = param_6[1] ^ param_1[1], iVar4 == 3)) {
          param_2[2] = param_6[2] ^ param_1[2];
        }
        uVar2 = uVar2 + iVar4 * -4;
        if (uVar3 == param_3) goto LAB_005e9858;
        *(byte *)(param_2 + iVar4) = *(byte *)(param_1 + iVar4) ^ *(byte *)(param_6 + iVar4);
      }
      if (uVar2 != 0) {
        iVar5 = uVar3 + 1;
        iVar4 = uVar3 + 2;
        *(byte *)((int)param_2 + iVar5) =
             *(byte *)((int)param_1 + iVar5) ^ *(byte *)((int)param_6 + iVar5);
        if (uVar2 != 1) {
          *(byte *)((int)param_2 + iVar4) =
               *(byte *)((int)param_6 + iVar4) ^ *(byte *)((int)param_1 + iVar4);
        }
      }
    }
  }
LAB_005e9858:
  *param_7 = param_3;
  return;
}

