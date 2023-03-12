
int ASN1_template_d2i(ASN1_VALUE **pval,uchar **in,long len,ASN1_TEMPLATE *tt)

{
  uchar *puVar1;
  uint uVar2;
  int iVar3;
  uint uVar4;
  uchar *puVar5;
  int in_GS_OFFSET;
  int iVar6;
  int local_48;
  uint local_44;
  int local_40;
  uchar *local_3c;
  undefined local_38 [4];
  uint local_34;
  int local_30;
  int local_2c;
  uint local_28;
  int local_24;
  int local_20;
  
  local_20 = *(int *)(in_GS_OFFSET + 0x14);
  local_38[0] = 0;
  if (pval == (ASN1_VALUE **)0x0) {
    uVar2 = 0;
    goto LAB_0814d23d;
  }
  uVar4 = tt->flags;
  puVar1 = *in;
  if ((uVar4 & 0x10) == 0) {
    uVar2 = asn1_template_noexp_d2i(tt,0,local_38);
    goto LAB_0814d23d;
  }
  iVar6 = tt->tag;
  local_3c = puVar1;
  local_34 = ASN1_get_object(&local_3c,&local_40,&local_48,(int *)&local_44,len);
  puVar5 = local_3c;
  local_38[0] = 1;
  local_28 = local_44;
  local_30 = local_40;
  local_24 = (int)local_3c - (int)puVar1;
  local_2c = local_48;
  if (((local_34 & 0x81) == 0) && (len < local_40 + local_24)) {
    iVar3 = 0x511;
    iVar6 = 0x9b;
LAB_0814d3ef:
    ERR_put_error(0xd,0x68,iVar6,"tasn_dec.c",iVar3);
    local_38[0] = 0;
  }
  else {
    uVar2 = local_34 & 0x80;
    if (uVar2 != 0) {
      iVar3 = 0x51a;
      iVar6 = 0x66;
      goto LAB_0814d3ef;
    }
    if (iVar6 < 0) {
LAB_0814d358:
      uVar4 = local_34 & 1;
      iVar6 = len - local_24;
      if (uVar4 == 0) {
        iVar6 = local_40;
      }
      if ((local_34 & 0x20) == 0) {
        ERR_put_error(0xd,0x84,0x78,"tasn_dec.c",0x23b);
        goto LAB_0814d23d;
      }
      iVar3 = asn1_template_noexp_d2i(tt,0,local_38);
      if (iVar3 == 0) {
        ERR_put_error(0xd,0x84,0x3a,"tasn_dec.c",0x243);
        goto LAB_0814d23d;
      }
      if (uVar4 == 0) {
        if (iVar6 != 0) {
          ERR_put_error(0xd,0x84,0x77,"tasn_dec.c",0x259);
          goto LAB_0814d489;
        }
      }
      else {
        if (((iVar6 < 2) || (*puVar5 != '\0')) || (puVar5[1] != '\0')) {
          ERR_put_error(0xd,0x84,0x89,"tasn_dec.c",0x24e);
LAB_0814d489:
          ASN1_template_free(pval,tt);
          goto LAB_0814d23d;
        }
        puVar5 = puVar5 + 2;
      }
      *in = puVar5;
      uVar2 = 1;
      goto LAB_0814d23d;
    }
    if ((iVar6 == local_48) && ((uVar4 & 0xc0) == local_44)) {
      local_38[0] = 0;
      goto LAB_0814d358;
    }
    local_38[0] = 0;
    ERR_put_error(0xd,0x68,0xa8,"tasn_dec.c",0x527);
  }
  uVar2 = 0;
  ERR_put_error(0xd,0x84,0x3a,"tasn_dec.c",0x233);
LAB_0814d23d:
  if (local_20 == *(int *)(in_GS_OFFSET + 0x14)) {
    return uVar2;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}

