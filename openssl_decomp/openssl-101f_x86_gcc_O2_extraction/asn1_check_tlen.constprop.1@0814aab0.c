
uint __regparm3
asn1_check_tlen_constprop_1
          (int *param_1_00,int *param_2_00,undefined *param_3_00,byte *param_1,byte *param_2,
          uchar **param_3,int param_4,undefined4 param_5,char *param_6)

{
  uchar *puVar1;
  uint uVar2;
  uint uVar3;
  int in_GS_OFFSET;
  int local_30;
  int local_2c;
  int local_28;
  uchar *local_24;
  int local_20;
  
  puVar1 = *param_3;
  local_20 = *(int *)(in_GS_OFFSET + 0x14);
  local_24 = puVar1;
  if (param_6 == (char *)0x0) {
    uVar3 = ASN1_get_object(&local_24,&local_28,&local_30,&local_2c,param_4);
    if ((uVar3 & 0x80) != 0) {
      ERR_put_error(0xd,0x68,0x66,"tasn_dec.c",0x51a);
      uVar2 = 0;
      goto LAB_0814ab88;
    }
  }
  else {
    if (*param_6 == '\0') {
      uVar3 = ASN1_get_object(&local_24,&local_28,&local_30,&local_2c,param_4);
      *(uint *)(param_6 + 4) = uVar3;
      *param_6 = '\x01';
      *(int *)(param_6 + 8) = local_28;
      *(int *)(param_6 + 0x10) = local_2c;
      *(int *)(param_6 + 0xc) = local_30;
      *(int *)(param_6 + 0x14) = (int)local_24 - (int)puVar1;
      uVar2 = uVar3 & 0x81;
      if ((uVar2 == 0) && (param_4 < local_28 + ((int)local_24 - (int)puVar1))) {
        ERR_put_error(0xd,0x68,0x9b,"tasn_dec.c",0x511);
        *param_6 = '\0';
        goto LAB_0814ab88;
      }
    }
    else {
      local_28 = *(int *)(param_6 + 8);
      uVar3 = *(uint *)(param_6 + 4);
      local_2c = *(int *)(param_6 + 0x10);
      local_24 = puVar1 + *(int *)(param_6 + 0x14);
      local_30 = *(int *)(param_6 + 0xc);
    }
    if ((uVar3 & 0x80) != 0) {
      ERR_put_error(0xd,0x68,0x66,"tasn_dec.c",0x51a);
      *param_6 = '\0';
      uVar2 = 0;
      goto LAB_0814ab88;
    }
  }
  if ((uVar3 & 1) != 0) {
    local_28 = param_4 - ((int)local_24 - (int)puVar1);
  }
  if (param_1 != (byte *)0x0) {
    *param_1 = (byte)uVar3 & 1;
  }
  if (param_2 != (byte *)0x0) {
    *param_2 = (byte)uVar3 & 0x20;
  }
  if (param_1_00 != (int *)0x0) {
    *param_1_00 = local_28;
  }
  if (param_3_00 != (undefined *)0x0) {
    *param_3_00 = (char)local_2c;
  }
  if (param_2_00 != (int *)0x0) {
    *param_2_00 = local_30;
  }
  *param_3 = local_24;
  uVar2 = 1;
LAB_0814ab88:
  if (local_20 != *(int *)(in_GS_OFFSET + 0x14)) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return uVar2;
}

