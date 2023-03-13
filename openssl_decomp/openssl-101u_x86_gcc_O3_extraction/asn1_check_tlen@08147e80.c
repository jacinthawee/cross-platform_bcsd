
uint __regparm3
asn1_check_tlen(int *param_1_00,int *param_2_00,undefined *param_3_00,byte *param_1,byte *param_2,
               uchar **param_3,int param_4,int param_5,int param_6,char param_7,char *param_8)

{
  uchar *puVar1;
  uint uVar2;
  uint uVar3;
  int in_GS_OFFSET;
  int reason;
  int line;
  int local_30;
  int local_2c;
  int local_28;
  uchar *local_24;
  int local_20;
  
  puVar1 = *param_3;
  local_20 = *(int *)(in_GS_OFFSET + 0x14);
  local_24 = puVar1;
  if (param_8 == (char *)0x0) {
    uVar3 = ASN1_get_object(&local_24,&local_28,&local_30,&local_2c,param_4);
    if ((uVar3 & 0x80) == 0) goto LAB_08147efe;
    line = 0x4a3;
    reason = 0x66;
LAB_08147f3c:
    ERR_put_error(0xd,0x68,reason,"tasn_dec.c",line);
    uVar2 = 0;
  }
  else {
    if (*param_8 == '\0') {
      uVar3 = ASN1_get_object(&local_24,&local_28,&local_30,&local_2c,param_4);
      *(uint *)(param_8 + 4) = uVar3;
      *param_8 = '\x01';
      *(int *)(param_8 + 0x10) = local_2c;
      *(int *)(param_8 + 8) = local_28;
      *(int *)(param_8 + 0xc) = local_30;
      *(int *)(param_8 + 0x14) = (int)local_24 - (int)puVar1;
      uVar2 = uVar3 & 0x81;
      if ((uVar2 == 0) && (param_4 < local_28 + ((int)local_24 - (int)puVar1))) {
        ERR_put_error(0xd,0x68,0x9b,"tasn_dec.c",0x49b);
        *param_8 = '\0';
        goto LAB_08147f4a;
      }
    }
    else {
      local_28 = *(int *)(param_8 + 8);
      uVar3 = *(uint *)(param_8 + 4);
      local_2c = *(int *)(param_8 + 0x10);
      local_30 = *(int *)(param_8 + 0xc);
      local_24 = puVar1 + *(int *)(param_8 + 0x14);
    }
    if ((uVar3 & 0x80) != 0) {
      ERR_put_error(0xd,0x68,0x66,"tasn_dec.c",0x4a3);
      *param_8 = '\0';
      uVar2 = 0;
      goto LAB_08147f4a;
    }
LAB_08147efe:
    if (-1 < param_5) {
      if ((param_5 != local_30) || (local_2c != param_6)) {
        if (param_7 != '\0') {
          uVar2 = 0xffffffff;
          goto LAB_08147f4a;
        }
        if (param_8 != (char *)0x0) {
          *param_8 = '\0';
        }
        line = 0x4af;
        reason = 0xa8;
        goto LAB_08147f3c;
      }
      if (param_8 != (char *)0x0) {
        *param_8 = '\0';
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
  }
LAB_08147f4a:
  if (local_20 == *(int *)(in_GS_OFFSET + 0x14)) {
    return uVar2;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}

