
int X509V3_EXT_print(BIO *out,X509_EXTENSION *ext,ulong flag,int indent)

{
  undefined *puVar1;
  X509V3_EXT_METHOD *method;
  ASN1_OCTET_STRING *pAVar2;
  void *ext_00;
  char *pcVar3;
  int iVar4;
  int iVar5;
  X509_EXTENSION *ex;
  ASN1_OBJECT *pAVar6;
  BIO *out_00;
  char *pcVar7;
  BIO *pBVar8;
  ASN1_ITEM_EXP *pAVar9;
  uint uVar10;
  stack_st_CONF_VALUE *val;
  char *local_38;
  uchar *local_28;
  BIO *local_24;
  
  puVar1 = PTR___stack_chk_guard_006aabf0;
  local_24 = *(BIO **)PTR___stack_chk_guard_006aabf0;
  pcVar7 = (char *)ext;
  pBVar8 = (BIO *)flag;
  method = X509V3_EXT_get(ext);
  if (method == (X509V3_EXT_METHOD *)0x0) {
    if ((flag & 0xf0000) == 0x10000) {
      pcVar7 = "%*s<Not Supported>";
      goto LAB_0058b84c;
    }
LAB_0058b7ec:
    uVar10 = flag & 0xf0000;
    pAVar9 = (ASN1_ITEM_EXP *)0x640000;
    if (uVar10 < 0x10001) {
      if (uVar10 == 0) {
        uVar10 = 0;
        goto LAB_0058b6cc;
      }
    }
    else {
      if (uVar10 == 0x20000) {
        pBVar8 = (BIO *)ext->value->length;
        pcVar7 = (char *)ext->value->data;
        local_38 = (char *)0xffffffff;
        uVar10 = (*(code *)PTR_ASN1_parse_dump_006a85b4)(out,pcVar7,pBVar8);
        pAVar9 = (ASN1_ITEM_EXP *)indent;
        goto LAB_0058b6cc;
      }
      pAVar9 = (ASN1_ITEM_EXP *)indent;
      if (uVar10 == 0x30000) {
        pBVar8 = (BIO *)ext->value->length;
        pcVar7 = (char *)ext->value->data;
        uVar10 = (*(code *)PTR_BIO_dump_indent_006a8434)(out,pcVar7,pBVar8);
        pAVar9 = (ASN1_ITEM_EXP *)indent;
        goto LAB_0058b6cc;
      }
    }
  }
  else {
    pAVar2 = ext->value;
    pAVar9 = method->it;
    local_28 = pAVar2->data;
    if (pAVar9 == (ASN1_ITEM_EXP *)0x0) {
      pcVar7 = (char *)&local_28;
      pBVar8 = (BIO *)pAVar2->length;
      ext_00 = (*method->d2i)((void *)0x0,(uchar **)pcVar7,(long)pBVar8);
    }
    else {
      pcVar7 = (char *)&local_28;
      pBVar8 = (BIO *)pAVar2->length;
      ext_00 = (void *)(*(code *)PTR_ASN1_item_d2i_006a9798)(0,pcVar7,pBVar8);
    }
    if (ext_00 != (void *)0x0) {
      if (method->i2s == (X509V3_EXT_I2S)0x0) {
        pBVar8 = (BIO *)0x0;
        if (method->i2v == (X509V3_EXT_I2V)0x0) {
          pAVar9 = (ASN1_ITEM_EXP *)indent;
          if (method->i2r == (X509V3_EXT_I2R)0x0) goto LAB_0058b700;
          iVar4 = (*method->i2r)(method,ext_00,out,indent);
          val = (stack_st_CONF_VALUE *)0x0;
          uVar10 = (uint)(iVar4 != 0);
          pBVar8 = out;
        }
        else {
          val = (*method->i2v)(method,ext_00,(stack_st_CONF_VALUE *)0x0);
          if (val == (stack_st_CONF_VALUE *)0x0) {
            uVar10 = 0;
            indent = (int)pAVar9;
          }
          else {
            pAVar9 = (ASN1_ITEM_EXP *)(method->ext_flags & 4);
            X509V3_EXT_val_prn(out,val,indent,(int)pAVar9);
            uVar10 = 1;
            pBVar8 = (BIO *)indent;
            indent = (int)pAVar9;
          }
        }
LAB_0058b708:
        (*(code *)PTR_sk_pop_free_006a8158)(val,PTR_X509V3_conf_free_006a8c38);
        pcVar7 = (char *)method->it;
        pAVar9 = (ASN1_ITEM_EXP *)indent;
      }
      else {
        pcVar3 = (*method->i2s)(method,ext_00);
        if (pcVar3 == (char *)0x0) {
LAB_0058b700:
          uVar10 = 0;
          val = (stack_st_CONF_VALUE *)0x0;
          indent = (int)pAVar9;
          goto LAB_0058b708;
        }
        pAVar9 = (ASN1_ITEM_EXP *)0x6395d0;
        (*(code *)PTR_BIO_printf_006a7f38)(out,"%*s%s",indent);
        (*(code *)PTR_sk_pop_free_006a8158)(0,PTR_X509V3_conf_free_006a8c38);
        uVar10 = 1;
        (*(code *)PTR_CRYPTO_free_006a7f88)(pcVar3);
        pcVar7 = (char *)method->it;
        pBVar8 = (BIO *)indent;
        local_38 = pcVar3;
      }
      if ((ASN1_ITEM_EXP *)pcVar7 == (ASN1_ITEM_EXP *)0x0) {
        (*method->ext_free)(ext_00);
      }
      else {
        (*(code *)PTR_ASN1_item_free_006a977c)(ext_00);
      }
      goto LAB_0058b6cc;
    }
    if ((flag & 0xf0000) != 0x10000) goto LAB_0058b7ec;
    pcVar7 = "%*s<Parse Error>";
LAB_0058b84c:
    pAVar9 = (ASN1_ITEM_EXP *)0x6395d0;
    (*(code *)PTR_BIO_printf_006a7f38)(out,pcVar7,indent);
    pBVar8 = (BIO *)indent;
  }
  uVar10 = 1;
LAB_0058b6cc:
  if (local_24 == *(BIO **)puVar1) {
    return uVar10;
  }
  out_00 = local_24;
  (*(code *)PTR___stack_chk_fail_006aabb8)();
  iVar4 = (*(code *)PTR_sk_num_006a7f2c)(pBVar8);
  if (0 < iVar4) {
    if ((ASN1_ITEM_EXP *)pcVar7 != (ASN1_ITEM_EXP *)0x0) {
      (*(code *)PTR_BIO_printf_006a7f38)(out_00,"%*s%s:\n",local_38,"",pcVar7);
      local_38 = local_38 + 4;
    }
    for (iVar4 = 0; iVar5 = (*(code *)PTR_sk_num_006a7f2c)(pBVar8), iVar4 < iVar5; iVar4 = iVar4 + 1
        ) {
      ex = (X509_EXTENSION *)(*(code *)PTR_sk_value_006a7f24)(pBVar8,iVar4);
      if ((local_38 != (char *)0x0) &&
         (iVar5 = (*(code *)PTR_BIO_printf_006a7f38)(out_00,&DAT_0066dfa4,local_38,""), iVar5 < 1))
      {
        return 0;
      }
      pAVar6 = X509_EXTENSION_get_object(ex);
      (*(code *)PTR_i2a_ASN1_OBJECT_006a812c)(out_00,pAVar6);
      iVar5 = X509_EXTENSION_get_critical(ex);
      if (iVar5 == 0) {
        iVar5 = (*(code *)PTR_BIO_printf_006a7f38)(out_00,": %s\n","");
      }
      else {
        iVar5 = (*(code *)PTR_BIO_printf_006a7f38)(out_00,": %s\n","critical");
      }
      if (iVar5 < 1) {
        return 0;
      }
      iVar5 = X509V3_EXT_print(out_00,ex,(ulong)pAVar9,(int)(local_38 + 4));
      if (iVar5 == 0) {
        (*(code *)PTR_BIO_printf_006a7f38)(out_00,&DAT_0066dfa4,local_38 + 4,"");
        (*(code *)PTR_ASN1_STRING_print_006a9e74)(out_00,ex->value);
      }
      iVar5 = (*(code *)PTR_BIO_write_006a7f14)(out_00,"\n",1);
      if (iVar5 < 1) {
        return 0;
      }
    }
  }
  return 1;
}

