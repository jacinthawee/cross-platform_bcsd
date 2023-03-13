
undefined4 __regparm3
tls1_PRF_constprop_1
          (uint param_1_00,undefined4 param_2_00,undefined4 param_3_00,undefined4 param_1,
          undefined4 param_2,undefined4 param_3,undefined4 param_4,undefined4 param_5,
          undefined4 param_6,undefined4 param_7,undefined4 param_8,byte *param_9,byte *param_10,
          uint param_11)

{
  uint uVar1;
  uint uVar2;
  byte bVar3;
  int iVar4;
  uint uVar5;
  byte *pbVar6;
  undefined4 uVar7;
  byte *pbVar8;
  int iVar9;
  int iVar10;
  int in_GS_OFFSET;
  int local_28;
  int local_24;
  int local_20;
  
  iVar9 = 0;
  iVar10 = 0;
  local_20 = *(int *)(in_GS_OFFSET + 0x14);
  while (iVar4 = ssl_get_handshake_digest(iVar10,&local_28,&local_24), iVar4 != 0) {
    iVar9 = (iVar9 + 1) - (uint)((local_28 << 10 & param_1_00) == 0);
    iVar10 = iVar10 + 1;
  }
  if (iVar9 == 0) {
    iVar10 = 0x10a;
    iVar9 = 0x44;
LAB_080ae44f:
    ERR_put_error(0x14,0x11c,iVar9,"t1_enc.c",iVar10);
    uVar7 = 0;
  }
  else {
    memset(param_9,0,param_11);
    iVar9 = 0;
    uVar1 = (param_11 - 4 >> 2) + 1;
    uVar2 = uVar1 * 4;
    while (iVar10 = ssl_get_handshake_digest(iVar9,&local_28,&local_24), iVar10 != 0) {
      if ((param_1_00 & local_28 << 10) == 0) goto LAB_080ae344;
      if (local_24 == 0) {
        iVar10 = 0x115;
        iVar9 = 0x146;
        goto LAB_080ae44f;
      }
      iVar10 = tls1_P_hash_constprop_2
                         (param_2_00,param_3_00,param_1,param_2,param_3,param_4,param_5,param_6,
                          param_10,param_11);
      if (iVar10 == 0) {
        uVar7 = 0;
        goto LAB_080ae425;
      }
      if (0 < (int)param_11) {
        if ((param_11 < 7 || param_10 < param_9 + 4 && param_9 < param_10 + 4) ||
            (((uint)param_10 | (uint)param_9) & 3) != 0) {
          pbVar6 = param_9;
          pbVar8 = param_10;
          do {
            bVar3 = *pbVar8;
            pbVar8 = pbVar8 + 1;
            *pbVar6 = *pbVar6 ^ bVar3;
            pbVar6 = pbVar6 + 1;
          } while (pbVar6 != param_9 + param_11);
        }
        else {
          uVar5 = 0;
          if (2 < param_11 - 1) {
            do {
              *(uint *)(param_9 + uVar5 * 4) =
                   *(uint *)(param_9 + uVar5 * 4) ^ *(uint *)(param_10 + uVar5 * 4);
              uVar5 = uVar5 + 1;
            } while (uVar5 < uVar1);
            uVar5 = uVar2;
            if (param_11 == uVar2) goto LAB_080ae344;
          }
          param_9[uVar5] = param_9[uVar5] ^ param_10[uVar5];
          if ((int)(uVar5 + 1) < (int)param_11) {
            param_9[uVar5 + 1] = param_9[uVar5 + 1] ^ param_10[uVar5 + 1];
            if ((int)(uVar5 + 2) < (int)param_11) {
              param_9[uVar5 + 2] = param_9[uVar5 + 2] ^ param_10[uVar5 + 2];
            }
          }
        }
      }
LAB_080ae344:
      iVar9 = iVar9 + 1;
    }
    uVar7 = 1;
  }
LAB_080ae425:
  if (local_20 == *(int *)(in_GS_OFFSET + 0x14)) {
    return uVar7;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}

