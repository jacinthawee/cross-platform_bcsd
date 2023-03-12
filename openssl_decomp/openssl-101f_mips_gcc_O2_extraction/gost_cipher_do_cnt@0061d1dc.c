
undefined4 gost_cipher_do_cnt(int param_1,byte *param_2,byte *param_3,uint param_4)

{
  byte bVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  byte *pbVar5;
  byte *pbVar6;
  
  uVar4 = *(uint *)(param_1 + 0x50);
  if (uVar4 == 0) {
    uVar4 = 8;
    uVar3 = 0;
  }
  else {
    uVar2 = uVar4;
    if (uVar4 < 8) {
      if (param_4 == 0) goto LAB_0061d560;
      uVar2 = uVar4 + 1;
      *param_2 = *(byte *)(param_1 + uVar4 + 0x30) ^ *param_3;
      if (uVar2 == 8) {
        uVar3 = 1;
        *(undefined4 *)(param_1 + 0x50) = 0;
        uVar4 = 9;
        param_2 = param_2 + 1;
        param_3 = param_3 + 1;
      }
      else {
        if (param_4 < 2) goto LAB_0061d560;
        uVar3 = uVar4 + 2;
        param_2[1] = *(byte *)(param_1 + uVar2 + 0x30) ^ param_3[1];
        if (uVar3 == 8) {
          uVar3 = 2;
          *(undefined4 *)(param_1 + 0x50) = 0;
          uVar4 = 10;
          param_2 = param_2 + 2;
          param_3 = param_3 + 2;
        }
        else {
          uVar2 = uVar3;
          if (param_4 == 2) goto LAB_0061d560;
          uVar2 = uVar4 + 3;
          param_2[2] = *(byte *)(param_1 + uVar3 + 0x30) ^ param_3[2];
          if (uVar2 == 8) {
            uVar3 = 3;
            *(undefined4 *)(param_1 + 0x50) = 0;
            uVar4 = 0xb;
            param_2 = param_2 + 3;
            param_3 = param_3 + 3;
          }
          else {
            if (param_4 == 3) goto LAB_0061d560;
            uVar3 = uVar4 + 4;
            param_2[3] = *(byte *)(param_1 + uVar2 + 0x30) ^ param_3[3];
            if (uVar3 == 8) {
              uVar3 = 4;
              *(undefined4 *)(param_1 + 0x50) = 0;
              uVar4 = 0xc;
              param_2 = param_2 + 4;
              param_3 = param_3 + 4;
            }
            else {
              uVar2 = uVar3;
              if (param_4 == 4) goto LAB_0061d560;
              uVar2 = uVar4 + 5;
              param_2[4] = *(byte *)(param_1 + uVar3 + 0x30) ^ param_3[4];
              if (uVar2 == 8) {
                uVar3 = 5;
                *(undefined4 *)(param_1 + 0x50) = 0;
                uVar4 = 0xd;
                param_2 = param_2 + 5;
                param_3 = param_3 + 5;
              }
              else {
                if (param_4 == 5) goto LAB_0061d560;
                param_2[5] = *(byte *)(param_1 + uVar2 + 0x30) ^ param_3[5];
                if (uVar4 == 1) {
                  if (param_4 == 6) goto LAB_0061d5d0;
                  uVar3 = 7;
                  uVar4 = 0xf;
                  param_2[6] = *(byte *)(param_1 + 0x37) ^ param_3[6];
                  *(undefined4 *)(param_1 + 0x50) = 0;
                  param_2 = param_2 + 7;
                  param_3 = param_3 + 7;
                }
                else {
                  uVar3 = 6;
                  *(undefined4 *)(param_1 + 0x50) = 0;
                  uVar4 = 0xe;
                  param_2 = param_2 + 6;
                  param_3 = param_3 + 6;
                }
              }
            }
          }
        }
      }
    }
    else {
      uVar3 = 0;
      if (uVar4 != 8) goto LAB_0061d560;
      *(undefined4 *)(param_1 + 0x50) = 0;
      uVar4 = 8;
    }
  }
  if (uVar4 < param_4) {
    pbVar5 = param_2;
    pbVar6 = param_3;
    do {
      uVar3 = uVar4;
      param_3 = pbVar6 + 8;
      gost_cnt_next(*(undefined4 *)(param_1 + 0x60),param_1 + 0x20,param_1 + 0x30);
      param_2 = pbVar5 + 8;
      *pbVar5 = *(byte *)(param_1 + 0x30) ^ *pbVar6;
      pbVar5[1] = *(byte *)(param_1 + 0x31) ^ pbVar6[1];
      pbVar5[2] = *(byte *)(param_1 + 0x32) ^ pbVar6[2];
      pbVar5[3] = *(byte *)(param_1 + 0x33) ^ pbVar6[3];
      pbVar5[4] = *(byte *)(param_1 + 0x34) ^ pbVar6[4];
      pbVar5[5] = *(byte *)(param_1 + 0x35) ^ pbVar6[5];
      pbVar5[6] = *(byte *)(param_1 + 0x36) ^ pbVar6[6];
      pbVar5[7] = *(byte *)(param_1 + 0x37) ^ pbVar6[7];
      pbVar5 = param_2;
      pbVar6 = param_3;
      uVar4 = uVar3 + 8;
    } while (uVar3 + 8 < param_4);
    if (param_4 <= uVar3) {
LAB_0061d430:
      *(undefined4 *)(param_1 + 0x50) = 0;
      return 1;
    }
    gost_cnt_next(*(undefined4 *)(param_1 + 0x60),param_1 + 0x20,param_1 + 0x30);
    bVar1 = *param_3;
  }
  else {
    if (param_4 <= uVar3) goto LAB_0061d430;
    gost_cnt_next(*(undefined4 *)(param_1 + 0x60),param_1 + 0x20,param_1 + 0x30);
    bVar1 = *param_3;
  }
  *param_2 = bVar1 ^ *(byte *)(param_1 + 0x30);
  if (param_4 <= uVar3 + 1) {
    *(undefined4 *)(param_1 + 0x50) = 1;
    return 1;
  }
  param_2[1] = *(byte *)(param_1 + 0x31) ^ param_3[1];
  if (param_4 <= uVar3 + 2) {
    *(undefined4 *)(param_1 + 0x50) = 2;
    return 1;
  }
  param_2[2] = *(byte *)(param_1 + 0x32) ^ param_3[2];
  if (param_4 <= uVar3 + 3) {
    *(undefined4 *)(param_1 + 0x50) = 3;
    return 1;
  }
  param_2[3] = *(byte *)(param_1 + 0x33) ^ param_3[3];
  if (param_4 <= uVar3 + 4) {
    *(undefined4 *)(param_1 + 0x50) = 4;
    return 1;
  }
  param_2[4] = *(byte *)(param_1 + 0x34) ^ param_3[4];
  if (param_4 <= uVar3 + 5) {
    *(undefined4 *)(param_1 + 0x50) = 5;
    return 1;
  }
  param_2[5] = *(byte *)(param_1 + 0x35) ^ param_3[5];
  if (param_4 <= uVar3 + 6) {
    *(undefined4 *)(param_1 + 0x50) = 6;
    return 1;
  }
  param_2[6] = *(byte *)(param_1 + 0x36) ^ param_3[6];
  if (param_4 <= uVar3 + 7) {
LAB_0061d5d0:
    *(undefined4 *)(param_1 + 0x50) = 7;
    return 1;
  }
  param_2[7] = *(byte *)(param_1 + 0x37) ^ param_3[7];
  if (param_4 <= uVar3 + 8) {
    *(undefined4 *)(param_1 + 0x50) = 8;
    return 1;
  }
  param_2[8] = *(byte *)(param_1 + 0x38) ^ param_3[8];
  uVar2 = 9;
LAB_0061d560:
  *(uint *)(param_1 + 0x50) = uVar2;
  return 1;
}

