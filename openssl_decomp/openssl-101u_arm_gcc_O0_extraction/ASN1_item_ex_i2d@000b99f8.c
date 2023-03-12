
/* WARNING: Type propagation algorithm not settling */

int ASN1_item_ex_i2d(ASN1_VALUE **pval,uchar **out,ASN1_ITEM *it,int tag,int aclass)

{
  int iVar1;
  int iVar2;
  ASN1_VALUE **ppAVar3;
  int iVar4;
  ASN1_TEMPLATE *pAVar5;
  code *pcVar6;
  int iVar7;
  byte *pbVar8;
  ASN1_TEMPLATE *pAVar9;
  code *pcVar10;
  int local_38;
  int local_2c [2];
  
  pcVar6 = (code *)it->funcs;
  if ((it->itype != '\0') && (*pval == (ASN1_VALUE *)0x0)) {
    return 0;
  }
  pcVar10 = pcVar6;
  if (pcVar6 != (code *)0x0) {
    pcVar10 = *(code **)(pcVar6 + 0x10);
  }
  switch(it->itype) {
  case '\0':
    if (it->templates != (ASN1_TEMPLATE *)0x0) {
      iVar1 = asn1_template_ex_i2d(pval,out,it->templates,tag,aclass);
      return iVar1;
    }
    iVar1 = asn1_i2d_ex_primitive(pval,out,it,tag,aclass);
    return iVar1;
  case '\x01':
    local_38 = 1;
    break;
  case '\x02':
    if ((pcVar10 != (code *)0x0) && (iVar1 = (*pcVar10)(6,pval,it,0), iVar1 == 0)) {
      return 0;
    }
    iVar1 = asn1_get_choice_selector(pval,it);
    if ((-1 < iVar1) && (iVar1 < it->tcount)) {
      pAVar9 = it->templates;
      ppAVar3 = asn1_get_field_ptr(pval,pAVar9 + iVar1);
      iVar1 = asn1_template_ex_i2d(ppAVar3,out,pAVar9 + iVar1,0xffffffff,aclass);
      return iVar1;
    }
    if (pcVar10 == (code *)0x0) {
      return 0;
    }
    (*pcVar10)(7,pval,it,0);
    return 0;
  case '\x03':
    if (out == (uchar **)0x0) {
      iVar1 = (**(code **)(pcVar6 + 0xc))(*pval,0);
      return iVar1;
    }
    pbVar8 = *out;
    iVar1 = (**(code **)(pcVar6 + 0xc))();
    if (tag != -1) {
      *pbVar8 = (byte)tag | (byte)aclass | *pbVar8 & 0x20;
      return iVar1;
    }
    return iVar1;
  case '\x04':
    iVar1 = (**(code **)(pcVar6 + 0x14))(pval,out,it,tag,aclass);
    return iVar1;
  case '\x05':
    iVar1 = asn1_i2d_ex_primitive(pval,out,it,0xffffffff,aclass);
    return iVar1;
  case '\x06':
    if ((aclass & 0x800U) == 0) {
      local_38 = 1;
    }
    else {
      local_38 = 2;
    }
    break;
  default:
    goto LAB_000b9a60;
  }
  iVar1 = asn1_enc_restore(local_2c,out,pval,it);
  if (-1 < iVar1) {
    if (iVar1 != 0) {
      return local_2c[0];
    }
    if (tag == -1) {
      tag = 0x10;
      aclass = aclass & 0xffffff3f;
    }
    local_2c[0] = iVar1;
    if ((pcVar10 == (code *)0x0) || (iVar2 = (*pcVar10)(6,pval,it,0), iVar2 != 0)) {
      pAVar9 = it->templates;
      iVar2 = iVar1;
      if (0 < it->tcount) {
        do {
          iVar2 = iVar2 + 1;
          pAVar5 = asn1_do_adb(pval,pAVar9,1);
          pAVar9 = pAVar9 + 1;
          if (pAVar5 == (ASN1_TEMPLATE *)0x0) {
            return 0;
          }
          ppAVar3 = asn1_get_field_ptr(pval,pAVar5);
          iVar4 = asn1_template_ex_i2d(ppAVar3,0,pAVar5,0xffffffff,aclass);
          if (iVar4 == -1) {
            return -1;
          }
          iVar7 = 0x7fffffff - local_2c[0];
          local_2c[0] = local_2c[0] + iVar4;
          if (iVar7 < iVar4) {
            return -1;
          }
        } while (iVar2 < it->tcount);
      }
      iVar2 = ASN1_object_size(local_38,local_2c[0],tag);
      if (out == (uchar **)0x0 || iVar2 == -1) {
        return iVar2;
      }
      ASN1_put_object(out,local_38,local_2c[0],tag,aclass);
      pAVar9 = it->templates;
      if (0 < it->tcount) {
        do {
          iVar1 = iVar1 + 1;
          pAVar5 = asn1_do_adb(pval,pAVar9,1);
          pAVar9 = pAVar9 + 1;
          if (pAVar5 == (ASN1_TEMPLATE *)0x0) {
            return 0;
          }
          ppAVar3 = asn1_get_field_ptr(pval,pAVar5);
          asn1_template_ex_i2d(ppAVar3,out,pAVar5,0xffffffff,aclass);
        } while (iVar1 < it->tcount);
      }
      if (local_38 == 2) {
        ASN1_put_eoc(out);
      }
      if (pcVar10 == (code *)0x0) {
        return iVar2;
      }
      iVar1 = (*pcVar10)(7,pval,it,0);
      if (iVar1 != 0) {
        return iVar2;
      }
    }
  }
LAB_000b9a60:
  return 0;
}

