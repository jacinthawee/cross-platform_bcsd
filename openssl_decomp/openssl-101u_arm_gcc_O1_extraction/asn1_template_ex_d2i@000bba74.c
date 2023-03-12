
undefined4
asn1_template_ex_d2i
          (ASN1_VALUE **param_1,uchar **param_2,int param_3,ASN1_TEMPLATE *param_4,char param_5,
          char *param_6)

{
  uchar *puVar1;
  uint uVar2;
  undefined4 uVar3;
  int iVar4;
  uchar *puVar5;
  uchar *puVar6;
  uint uVar7;
  uchar *local_3c;
  int local_38;
  uint local_34;
  uchar *local_30;
  uchar *local_2c [2];
  
  if (param_1 == (ASN1_VALUE **)0x0) {
    return 0;
  }
  uVar7 = param_4->flags;
  puVar5 = *param_2;
  local_3c = puVar5;
  if ((uVar7 & 0x10) == 0) {
    uVar3 = asn1_template_noexp_d2i();
    return uVar3;
  }
  iVar4 = param_4->tag;
  local_2c[0] = puVar5;
  if (param_6 == (char *)0x0) {
    uVar2 = ASN1_get_object(local_2c,(long *)&local_30,&local_38,(int *)&local_34,param_3);
  }
  else if (*param_6 == '\0') {
    uVar2 = ASN1_get_object(local_2c,(long *)&local_30,&local_38,(int *)&local_34,param_3);
    *(uint *)(param_6 + 0x10) = local_34;
    *param_6 = '\x01';
    *(uchar **)(param_6 + 8) = local_30;
    *(int *)(param_6 + 0x14) = (int)local_2c[0] - (int)puVar5;
    *(int *)(param_6 + 0xc) = local_38;
    *(uint *)(param_6 + 4) = uVar2;
    if (((uVar2 & 0x81) == 0) && (param_3 < (int)(local_30 + ((int)local_2c[0] - (int)puVar5)))) {
      ERR_put_error(0xd,0x68,0x9b,"tasn_dec.c",0x49b);
      *param_6 = '\0';
      goto LAB_000bbafe;
    }
  }
  else {
    local_30 = *(uchar **)(param_6 + 8);
    local_34 = *(uint *)(param_6 + 0x10);
    local_38 = *(int *)(param_6 + 0xc);
    uVar2 = *(uint *)(param_6 + 4);
    local_2c[0] = puVar5 + *(int *)(param_6 + 0x14);
  }
  puVar1 = local_2c[0];
  if ((uVar2 & 0x80) != 0) {
    ERR_put_error(0xd,0x68,0x66,"tasn_dec.c",0x4a3);
    if (param_6 != (char *)0x0) {
      *param_6 = '\0';
    }
LAB_000bbafe:
    ERR_put_error(0xd,0x84,0x3a,"tasn_dec.c",0x224);
    return 0;
  }
  if (-1 < iVar4) {
    if ((iVar4 != local_38) || ((uVar7 & 0xc0) != local_34)) {
      if (param_5 != '\0') {
        return 0xffffffff;
      }
      if (param_6 != (char *)0x0) {
        *param_6 = '\0';
      }
      ERR_put_error(0xd,0x68,0xa8,"tasn_dec.c",0x4af);
      goto LAB_000bbafe;
    }
    if (param_6 != (char *)0x0) {
      *param_6 = '\0';
    }
  }
  puVar6 = local_30;
  if ((int)(uVar2 << 0x1f) < 0) {
    puVar6 = puVar5 + (param_3 - (int)local_2c[0]);
  }
  local_3c = local_2c[0];
  if (-1 < (int)(uVar2 << 0x1a)) {
    ERR_put_error(0xd,0x84,0x78,"tasn_dec.c",0x22a);
    return 0;
  }
  iVar4 = asn1_template_noexp_d2i(param_1,&local_3c,puVar6,param_4,0,param_6);
  if (iVar4 == 0) {
    ERR_put_error(0xd,0x84,0x3a,"tasn_dec.c",0x230);
    return 0;
  }
  if ((uVar2 & 1) == 0) {
    puVar5 = local_3c;
    if (puVar1 + ((int)puVar6 - (int)local_3c) == (uchar *)0x0) goto LAB_000bbc72;
    ERR_put_error(0xd,0x84,0x77,"tasn_dec.c",0x241);
  }
  else {
    if (((1 < (int)(puVar1 + ((int)puVar6 - (int)local_3c))) && (*local_3c == '\0')) &&
       (puVar5 = local_3c + 2, local_3c[1] == '\0')) {
LAB_000bbc72:
      *param_2 = puVar5;
      return 1;
    }
    ERR_put_error(0xd,0x84,0x89,"tasn_dec.c",0x238);
  }
  ASN1_template_free(param_1,param_4);
  return 0;
}

