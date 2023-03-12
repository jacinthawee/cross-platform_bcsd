
int ASN1_template_d2i(ASN1_VALUE **pval,uchar **in,long len,ASN1_TEMPLATE *tt)

{
  uchar *puVar1;
  uint uVar2;
  uchar *puVar3;
  int iVar4;
  bool bVar5;
  uchar *local_54;
  int local_50;
  uint local_4c;
  uchar *local_48;
  uchar *local_44;
  undefined local_40 [4];
  uint local_3c;
  uchar *local_38;
  int local_34;
  uint local_30;
  int local_2c;
  
  local_40[0] = 0;
  if (pval == (ASN1_VALUE **)0x0) {
    return 0;
  }
  uVar2 = tt->flags;
  puVar3 = *in;
  local_54 = puVar3;
  if ((uVar2 & 0x10) == 0) {
    iVar4 = asn1_template_noexp_d2i();
    return iVar4;
  }
  iVar4 = tt->tag;
  local_44 = puVar3;
  local_3c = ASN1_get_object(&local_44,(long *)&local_48,&local_50,(int *)&local_4c,len);
  puVar1 = local_44;
  local_40[0] = 1;
  local_2c = (int)local_44 - (int)puVar3;
  local_38 = local_48;
  local_30 = local_4c;
  local_34 = local_50;
  if (((local_3c & 0x81) == 0) && (len < (int)(local_48 + local_2c))) {
    ERR_put_error(0xd,0x68,0x9b,"tasn_dec.c",0x511);
    local_40[0] = 0;
  }
  else {
    if ((local_3c & 0x80) == 0) {
      if (-1 < iVar4) {
        if ((iVar4 != local_50) || ((uVar2 & 0xc0) != local_4c)) {
          local_40[0] = 0;
          ERR_put_error(0xd,0x68,0xa8,"tasn_dec.c",0x527);
          goto LAB_000bf112;
        }
        local_40[0] = 0;
      }
      bVar5 = (int)(local_3c << 0x1f) < 0;
      if (bVar5) {
        puVar3 = puVar3 + -(int)local_44;
      }
      local_54 = local_44;
      if (bVar5) {
        local_48 = puVar3 + len;
      }
      uVar2 = local_3c & 1;
      if (-1 < (int)(local_3c << 0x1a)) {
        ERR_put_error(0xd,0x84,0x78,"tasn_dec.c",0x23b);
        return 0;
      }
      iVar4 = asn1_template_noexp_d2i(pval,&local_54,local_48,tt,0,local_40);
      if (iVar4 == 0) {
        ERR_put_error(0xd,0x84,0x3a,"tasn_dec.c",0x243);
        return 0;
      }
      if (uVar2 == 0) {
        puVar3 = local_54;
        if (local_48 + ((int)puVar1 - (int)local_54) == (uchar *)0x0) goto LAB_000bf218;
        ERR_put_error(0xd,0x84,0x77,"tasn_dec.c",0x259);
      }
      else {
        if (((1 < (int)(local_48 + ((int)puVar1 - (int)local_54))) && (*local_54 == '\0')) &&
           (puVar3 = local_54 + 2, local_54[1] == '\0')) {
LAB_000bf218:
          *in = puVar3;
          return 1;
        }
        ERR_put_error(0xd,0x84,0x89,"tasn_dec.c",0x24e);
      }
      ASN1_template_free(pval,tt);
      return 0;
    }
    ERR_put_error(0xd,0x68,0x66,"tasn_dec.c",0x51a);
    local_40[0] = 0;
  }
LAB_000bf112:
  ERR_put_error(0xd,0x84,0x3a,"tasn_dec.c",0x233);
  return 0;
}

