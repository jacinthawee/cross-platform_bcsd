
undefined4 gost_cipher_do_cnt(int param_1,byte *param_2,byte *param_3,uint param_4)

{
  byte bVar1;
  uint uVar2;
  byte *pbVar3;
  uint uVar4;
  byte *pbVar5;
  uint local_20;
  
  uVar2 = *(uint *)(param_1 + 0x50);
  if (uVar2 == 0) {
    local_20 = 8;
    uVar4 = 0;
  }
  else {
    uVar4 = 0;
    if ((uVar2 < 8) && (pbVar3 = param_2, param_4 != 0)) {
      do {
        pbVar5 = (byte *)(param_1 + 0x30 + uVar2);
        uVar2 = uVar2 + 1;
        uVar4 = uVar4 + 1;
        bVar1 = *param_3;
        param_2 = pbVar3 + 1;
        param_3 = param_3 + 1;
        *pbVar3 = *pbVar5 ^ bVar1;
        if (7 < uVar2) break;
        pbVar3 = param_2;
      } while (uVar4 < param_4);
    }
    if (uVar2 != 8) goto LAB_081da118;
    local_20 = uVar4 + 8;
    *(undefined4 *)(param_1 + 0x50) = 0;
  }
  if (local_20 < param_4) {
    do {
      uVar4 = local_20;
      pbVar5 = param_3 + 8;
      pbVar3 = param_2 + 8;
      gost_cnt_next();
      *param_2 = *(byte *)(param_1 + 0x30) ^ *param_3;
      param_2[1] = *(byte *)(param_1 + 0x31) ^ param_3[1];
      param_2[2] = *(byte *)(param_1 + 0x32) ^ param_3[2];
      param_2[3] = *(byte *)(param_1 + 0x33) ^ param_3[3];
      param_2[4] = *(byte *)(param_1 + 0x34) ^ param_3[4];
      param_2[5] = *(byte *)(param_1 + 0x35) ^ param_3[5];
      param_2[6] = *(byte *)(param_1 + 0x36) ^ param_3[6];
      param_2[7] = *(byte *)(param_1 + 0x37) ^ param_3[7];
      local_20 = uVar4 + 8;
      param_2 = pbVar3;
      param_3 = pbVar5;
    } while (uVar4 + 8 < param_4);
    if (param_4 <= uVar4) {
LAB_081da1db:
      *(undefined4 *)(param_1 + 0x50) = 0;
      return 1;
    }
    gost_cnt_next();
  }
  else {
    if (param_4 <= uVar4) goto LAB_081da1db;
    gost_cnt_next();
  }
  *param_2 = *param_3 ^ *(byte *)(param_1 + 0x30);
  if (uVar4 + 1 < param_4) {
    param_2[1] = param_3[1] ^ *(byte *)(param_1 + 0x31);
    if (uVar4 + 2 < param_4) {
      param_2[2] = param_3[2] ^ *(byte *)(param_1 + 0x32);
      if (uVar4 + 3 < param_4) {
        param_2[3] = *(byte *)(param_1 + 0x33) ^ param_3[3];
        if (uVar4 + 4 < param_4) {
          param_2[4] = *(byte *)(param_1 + 0x34) ^ param_3[4];
          if (uVar4 + 5 < param_4) {
            param_2[5] = *(byte *)(param_1 + 0x35) ^ param_3[5];
            if (uVar4 + 6 < param_4) {
              param_2[6] = *(byte *)(param_1 + 0x36) ^ param_3[6];
              if (uVar4 + 7 < param_4) {
                param_2[7] = *(byte *)(param_1 + 0x37) ^ param_3[7];
                if (uVar4 + 8 < param_4) {
                  param_2[8] = *(byte *)(param_1 + 0x38) ^ param_3[8];
                  uVar2 = 9;
                }
                else {
                  uVar2 = 8;
                }
              }
              else {
                uVar2 = 7;
              }
            }
            else {
              uVar2 = 6;
            }
          }
          else {
            uVar2 = 5;
          }
        }
        else {
          uVar2 = 4;
        }
      }
      else {
        uVar2 = 3;
      }
    }
    else {
      uVar2 = 2;
    }
  }
  else {
    uVar2 = 1;
  }
LAB_081da118:
  *(uint *)(param_1 + 0x50) = uVar2;
  return 1;
}

