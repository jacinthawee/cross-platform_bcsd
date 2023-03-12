
/* WARNING: Type propagation algorithm not settling */

int ASN1_item_ndef_i2d(ASN1_VALUE *val,uchar **out,ASN1_ITEM *it)

{
  int iVar1;
  uchar *puVar2;
  ASN1_VALUE **ppAVar3;
  ASN1_TEMPLATE *pAVar4;
  int iVar5;
  code *pcVar6;
  ASN1_TEMPLATE *pAVar7;
  uchar *puVar8;
  code *pcVar9;
  int local_38;
  ASN1_VALUE *local_30;
  uchar *local_2c [2];
  
  local_30 = val;
  if ((out != (uchar **)0x0) && (*out == (uchar *)0x0)) {
    iVar1 = ASN1_item_ex_i2d(&local_30,(uchar **)0x0,it,-1,0x800);
    if (iVar1 < 1) {
      return iVar1;
    }
    puVar2 = (uchar *)CRYPTO_malloc(iVar1,"tasn_enc.c",0x6e);
    if (puVar2 == (uchar *)0x0) {
      return -1;
    }
    local_2c[0] = puVar2;
    ASN1_item_ex_i2d(&local_30,local_2c,it,-1,0x800);
    *out = puVar2;
    return iVar1;
  }
  pcVar6 = (code *)it->funcs;
  if ((it->itype != '\0') && (val == (ASN1_VALUE *)0x0)) {
    return 0;
  }
  pcVar9 = pcVar6;
  if (pcVar6 != (code *)0x0) {
    pcVar9 = *(code **)(pcVar6 + 0x10);
  }
  switch(it->itype) {
  case '\0':
    if (it->templates != (ASN1_TEMPLATE *)0x0) {
      iVar1 = asn1_template_ex_i2d(&local_30,out,it->templates,0xffffffff,0x800);
      return iVar1;
    }
    goto LAB_000ba28a;
  case '\x01':
    local_38 = 1;
    break;
  case '\x02':
    if ((pcVar9 != (code *)0x0) && (iVar1 = (*pcVar9)(6,&local_30,it,0), iVar1 == 0)) {
      return 0;
    }
    iVar1 = asn1_get_choice_selector(&local_30,it);
    if ((-1 < iVar1) && (iVar1 < it->tcount)) {
      pAVar7 = it->templates;
      ppAVar3 = asn1_get_field_ptr(&local_30,pAVar7 + iVar1);
      iVar1 = asn1_template_ex_i2d(ppAVar3,out,pAVar7 + iVar1,0xffffffff,0x800);
      return iVar1;
    }
    if (pcVar9 == (code *)0x0) {
      return 0;
    }
    (*pcVar9)(7,&local_30,it,0);
    return 0;
  case '\x03':
    iVar1 = (**(code **)(pcVar6 + 0xc))(val,out);
    return iVar1;
  case '\x04':
    iVar1 = (**(code **)(pcVar6 + 0x14))(&local_30,out,it,0xffffffff,0x800);
    return iVar1;
  case '\x05':
LAB_000ba28a:
    iVar1 = asn1_i2d_ex_primitive(&local_30,out,it,0xffffffff,0x800);
    return iVar1;
  case '\x06':
    local_38 = 2;
    break;
  default:
    goto LAB_000ba1da;
  }
  puVar2 = (uchar *)asn1_enc_restore((int *)local_2c,out,&local_30,it);
  if (-1 < (int)puVar2) {
    if (puVar2 != (uchar *)0x0) {
      return (int)local_2c[0];
    }
    local_2c[0] = puVar2;
    if ((pcVar9 == (code *)0x0) || (iVar1 = (*pcVar9)(6,&local_30,it,0), iVar1 != 0)) {
      pAVar7 = it->templates;
      puVar8 = puVar2;
      if (0 < it->tcount) {
        do {
          puVar8 = puVar8 + 1;
          pAVar4 = asn1_do_adb(&local_30,pAVar7,1);
          pAVar7 = pAVar7 + 1;
          if (pAVar4 == (ASN1_TEMPLATE *)0x0) {
            return 0;
          }
          ppAVar3 = asn1_get_field_ptr(&local_30,pAVar4);
          iVar1 = asn1_template_ex_i2d(ppAVar3,0,pAVar4,0xffffffff,0x800);
          if (iVar1 == -1) {
            return -1;
          }
          iVar5 = 0x7fffffff - (int)local_2c[0];
          local_2c[0] = local_2c[0] + iVar1;
          if (iVar5 < iVar1) {
            return -1;
          }
        } while ((int)puVar8 < it->tcount);
      }
      iVar1 = ASN1_object_size(local_38,(int)local_2c[0],0x10);
      if (out == (uchar **)0x0 || iVar1 == -1) {
        return iVar1;
      }
      ASN1_put_object(out,local_38,(int)local_2c[0],0x10,0x800);
      pAVar7 = it->templates;
      if (0 < it->tcount) {
        do {
          puVar2 = puVar2 + 1;
          pAVar4 = asn1_do_adb(&local_30,pAVar7,1);
          pAVar7 = pAVar7 + 1;
          if (pAVar4 == (ASN1_TEMPLATE *)0x0) {
            return 0;
          }
          ppAVar3 = asn1_get_field_ptr(&local_30,pAVar4);
          asn1_template_ex_i2d(ppAVar3,out,pAVar4,0xffffffff,0x800);
        } while ((int)puVar2 < it->tcount);
      }
      if (local_38 == 2) {
        ASN1_put_eoc(out);
      }
      if (pcVar9 == (code *)0x0) {
        return iVar1;
      }
      iVar5 = (*pcVar9)(7,&local_30,it,0);
      if (iVar5 != 0) {
        return iVar1;
      }
    }
  }
LAB_000ba1da:
  return 0;
}

