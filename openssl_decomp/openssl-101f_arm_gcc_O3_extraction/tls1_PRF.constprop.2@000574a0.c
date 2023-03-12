
undefined4
tls1_PRF_constprop_2
          (uint param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,undefined4 param_5,
          undefined4 param_6,undefined4 param_7,undefined4 param_8,undefined4 param_9,int param_10,
          uint param_11,uint *param_12,uint *param_13,uint param_14)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  uint *puVar4;
  uint uVar5;
  uint *puVar6;
  int iVar7;
  uint uVar8;
  int iVar9;
  int iVar10;
  int local_30;
  int local_2c [2];
  
  iVar9 = 0;
  iVar1 = 0;
  while( true ) {
    iVar10 = iVar1 + 1;
    iVar1 = ssl_get_handshake_digest(iVar1,&local_30,local_2c);
    if (iVar1 == 0) break;
    iVar1 = iVar10;
    if ((param_1 & local_30 << 10) != 0) {
      iVar9 = iVar9 + 1;
    }
  }
  iVar10 = __aeabi_idiv(param_11,iVar9);
  memset(param_12,0,param_14);
  uVar5 = param_14 & 0xfffffffc;
  if (iVar9 == 1) {
    param_11 = 0;
  }
  iVar9 = uVar5 + 1;
  uVar3 = (uint)(param_13 + 1 <= param_12 || param_12 + 1 <= param_13);
  iVar7 = uVar5 + 2;
  if (param_14 < 7) {
    uVar3 = 0;
  }
  if ((((uint)param_13 | (uint)param_12) & 3) != 0) {
    uVar3 = 0;
  }
  do {
    iVar2 = ssl_get_handshake_digest(iVar1,&local_30,local_2c);
    if (iVar2 == 0) {
      return 1;
    }
    if ((param_1 & local_30 << 10) != 0) {
      if (local_2c[0] == 0) {
        ERR_put_error(0x14,0x11c,0x146,"t1_enc.c",0x114);
        return 0;
      }
      iVar2 = tls1_P_hash_constprop_3
                        (local_2c[0],param_10,iVar10 + (param_11 & 1),param_2,param_3,param_4,
                         param_5,param_6,param_7,param_8,param_9,param_13,param_14);
      if (iVar2 == 0) {
        return 0;
      }
      param_10 = param_10 + iVar10;
      if (0 < (int)param_14) {
        uVar8 = uVar3;
        if (uVar3 == 0) {
          do {
            *(byte *)((int)param_12 + uVar8) =
                 *(byte *)((int)param_12 + uVar8) ^ *(byte *)((int)param_13 + uVar8);
            uVar8 = uVar8 + 1;
          } while (uVar8 != param_14);
        }
        else {
          if ((param_14 & 0xfffffffc) != 0) {
            puVar4 = param_13 + -1;
            uVar8 = 0;
            puVar6 = param_12;
            do {
              uVar8 = uVar8 + 1;
              puVar4 = puVar4 + 1;
              *puVar6 = *puVar6 ^ *puVar4;
              puVar6 = puVar6 + 1;
            } while (uVar8 < param_14 >> 2);
            if (param_14 == (param_14 & 0xfffffffc)) goto LAB_000575d4;
          }
          *(byte *)((int)param_12 + uVar5) =
               *(byte *)((int)param_13 + uVar5) ^ *(byte *)((int)param_12 + uVar5);
          if ((iVar9 < (int)param_14) &&
             (*(byte *)(iVar9 + (int)param_12) =
                   *(byte *)(iVar9 + (int)param_12) ^ *(byte *)(iVar9 + (int)param_13),
             iVar7 < (int)param_14)) {
            *(byte *)(iVar7 + (int)param_12) =
                 *(byte *)(iVar7 + (int)param_12) ^ *(byte *)(iVar7 + (int)param_13);
          }
        }
      }
    }
LAB_000575d4:
    iVar1 = iVar1 + 1;
  } while( true );
}

