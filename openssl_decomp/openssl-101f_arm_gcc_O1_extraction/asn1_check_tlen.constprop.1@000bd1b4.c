
char * asn1_check_tlen_constprop_1
                 (uchar **param_1,int *param_2,undefined *param_3,undefined *param_4,byte *param_5,
                 uchar **param_6,int param_7,undefined4 param_8,char *param_9)

{
  uint uVar1;
  uchar *puVar2;
  int local_38;
  int local_34;
  uchar *local_30;
  uchar *local_2c [2];
  
  puVar2 = *param_6;
  local_2c[0] = puVar2;
  if (param_9 == (char *)0x0) {
    uVar1 = ASN1_get_object(local_2c,(long *)&local_30,&local_38,&local_34,param_7);
  }
  else if (*param_9 == '\0') {
    uVar1 = ASN1_get_object(local_2c,(long *)&local_30,&local_38,&local_34,param_7);
    *param_9 = '\x01';
    *(int *)(param_9 + 0x10) = local_34;
    *(int *)(param_9 + 0x14) = (int)local_2c[0] - (int)puVar2;
    *(int *)(param_9 + 0xc) = local_38;
    *(uint *)(param_9 + 4) = uVar1;
    *(uchar **)(param_9 + 8) = local_30;
    if (((uVar1 & 0x81) == 0) && (param_7 < (int)(local_30 + ((int)local_2c[0] - (int)puVar2)))) {
      ERR_put_error(0xd,0x68,0x9b,"tasn_dec.c",0x511);
      *param_9 = '\0';
      return (char *)0x0;
    }
  }
  else {
    local_30 = *(uchar **)(param_9 + 8);
    local_34 = *(int *)(param_9 + 0x10);
    local_38 = *(int *)(param_9 + 0xc);
    uVar1 = *(uint *)(param_9 + 4);
    local_2c[0] = puVar2 + *(int *)(param_9 + 0x14);
  }
  if ((int)(uVar1 << 0x18) < 0) {
    ERR_put_error(0xd,0x68,0x66,"tasn_dec.c",0x51a);
    if (param_9 != (char *)0x0) {
      *param_9 = '\0';
      return (char *)0x0;
    }
  }
  else {
    if ((uVar1 & 1) != 0) {
      local_30 = puVar2 + (param_7 - (int)local_2c[0]);
    }
    if (param_4 != (undefined *)0x0) {
      *param_4 = (char)(uVar1 & 1);
    }
    if (param_5 != (byte *)0x0) {
      *param_5 = (byte)uVar1 & 0x20;
    }
    if (param_1 != (uchar **)0x0) {
      *param_1 = local_30;
    }
    if (param_3 != (undefined *)0x0) {
      *param_3 = (char)local_34;
    }
    if (param_2 != (int *)0x0) {
      *param_2 = local_38;
    }
    param_9 = (char *)0x1;
    *param_6 = local_2c[0];
  }
  return param_9;
}

