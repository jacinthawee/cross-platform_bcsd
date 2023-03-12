
undefined4
tls1_PRF_constprop_2
          (uint param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,undefined4 param_5,
          undefined4 param_6,undefined4 param_7,undefined4 param_8,undefined4 param_9,int param_10,
          uint param_11,uint *param_12,uint *param_13,uint param_14)

{
  int iVar1;
  int iVar2;
  uint *puVar3;
  uint uVar4;
  uint uVar5;
  uint *puVar6;
  uint uVar7;
  int iVar8;
  int iVar9;
  int iVar10;
  bool bVar11;
  int local_30;
  int local_2c [2];
  
  iVar8 = 0;
  iVar1 = 0;
  while( true ) {
    iVar10 = iVar1 + 1;
    iVar1 = ssl_get_handshake_digest(iVar1,&local_30,local_2c);
    if (iVar1 == 0) break;
    iVar1 = iVar10;
    if ((param_1 & local_30 << 10) != 0) {
      iVar8 = iVar8 + 1;
    }
  }
  if (iVar8 == 0) {
    ERR_put_error(0x14,0x11c,0x44,"t1_enc.c",0x10a);
    return 0;
  }
  iVar10 = __aeabi_idiv(param_11,iVar8);
  if (iVar8 == 1) {
    param_11 = 0;
  }
  memset(param_12,0,param_14);
  uVar5 = param_14 & 0xfffffffc;
  puVar3 = param_13 + 1;
  iVar8 = uVar5 + 1;
  bVar11 = param_12 < puVar3;
  iVar9 = uVar5 + 2;
  if (!bVar11 || param_13 >= param_12 + 1) {
    puVar3 = (uint *)0x1;
  }
  if (bVar11 && param_13 < param_12 + 1) {
    puVar3 = (uint *)0x0;
  }
  if (param_14 < 7) {
    uVar4 = 0;
  }
  else {
    uVar4 = (uint)puVar3 & 1;
  }
  if ((((uint)param_13 | (uint)param_12) & 3) != 0) {
    uVar4 = 0;
  }
  do {
    iVar2 = ssl_get_handshake_digest(iVar1,&local_30,local_2c);
    if (iVar2 == 0) {
      return 1;
    }
    if ((param_1 & local_30 << 10) != 0) {
      if (local_2c[0] == 0) {
        ERR_put_error(0x14,0x11c,0x146,"t1_enc.c",0x115);
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
        uVar7 = uVar4;
        if (uVar4 == 0) {
          do {
            *(byte *)((int)param_12 + uVar7) =
                 *(byte *)((int)param_12 + uVar7) ^ *(byte *)((int)param_13 + uVar7);
            uVar7 = uVar7 + 1;
          } while (uVar7 != param_14);
        }
        else {
          if ((param_14 & 0xfffffffc) != 0) {
            puVar3 = param_13 + -1;
            uVar7 = 0;
            puVar6 = param_12;
            do {
              uVar7 = uVar7 + 1;
              puVar3 = puVar3 + 1;
              *puVar6 = *puVar6 ^ *puVar3;
              puVar6 = puVar6 + 1;
            } while (uVar7 < param_14 >> 2);
            if (param_14 == (param_14 & 0xfffffffc)) goto LAB_00054c86;
          }
          *(byte *)((int)param_12 + uVar5) =
               *(byte *)((int)param_13 + uVar5) ^ *(byte *)((int)param_12 + uVar5);
          if ((iVar8 < (int)param_14) &&
             (*(byte *)(iVar8 + (int)param_12) =
                   *(byte *)(iVar8 + (int)param_12) ^ *(byte *)(iVar8 + (int)param_13),
             iVar9 < (int)param_14)) {
            *(byte *)(iVar9 + (int)param_12) =
                 *(byte *)(iVar9 + (int)param_12) ^ *(byte *)(iVar9 + (int)param_13);
          }
        }
      }
    }
LAB_00054c86:
    iVar1 = iVar1 + 1;
  } while( true );
}

