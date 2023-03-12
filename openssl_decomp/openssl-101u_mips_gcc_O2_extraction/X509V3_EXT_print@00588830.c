
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
  
  puVar1 = PTR___stack_chk_guard_006a9ae8;
  local_24 = *(BIO **)PTR___stack_chk_guard_006a9ae8;
  pcVar7 = (char *)ext;
  pBVar8 = (BIO *)flag;
  method = X509V3_EXT_get(ext);
  if (method == (X509V3_EXT_METHOD *)0x0) {
    if ((flag & 0xf0000) == 0x10000) {
      pcVar7 = "%*s<Not Supported>";
      goto LAB_00588adc;
    }
LAB_00588a7c:
    uVar10 = flag & 0xf0000;
    if (uVar10 < 0x10001) {
      indent = (int)"-check_ss_sig";
      if (uVar10 == 0) {
        uVar10 = 0;
        goto LAB_0058895c;
      }
    }
    else {
      if (uVar10 == 0x20000) {
        pBVar8 = (BIO *)ext->value->length;
        pcVar7 = (char *)ext->value->data;
        local_38 = (char *)0xffffffff;
        uVar10 = (*(code *)PTR_ASN1_parse_dump_006a74b8)(out,pcVar7,pBVar8);
        goto LAB_0058895c;
      }
      if (uVar10 == 0x30000) {
        pBVar8 = (BIO *)ext->value->length;
        pcVar7 = (char *)ext->value->data;
        uVar10 = (*(code *)PTR_BIO_dump_indent_006a7334)(out,pcVar7,pBVar8);
        goto LAB_0058895c;
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
      ext_00 = (void *)(*(code *)PTR_ASN1_item_d2i_006a8674)(0,pcVar7,pBVar8);
    }
    if (ext_00 != (void *)0x0) {
      if (method->i2s == (X509V3_EXT_I2S)0x0) {
        pBVar8 = (BIO *)0x0;
        if (method->i2v == (X509V3_EXT_I2V)0x0) {
          pAVar9 = (ASN1_ITEM_EXP *)indent;
          if (method->i2r == (X509V3_EXT_I2R)0x0) goto LAB_00588990;
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
LAB_00588998:
        (*(code *)PTR_sk_pop_free_006a7058)(val,PTR_X509V3_conf_free_006a7b4c);
        pcVar7 = (char *)method->it;
      }
      else {
        pcVar3 = (*method->i2s)(method,ext_00);
        if (pcVar3 == (char *)0x0) {
LAB_00588990:
          uVar10 = 0;
          val = (stack_st_CONF_VALUE *)0x0;
          indent = (int)pAVar9;
          goto LAB_00588998;
        }
        pAVar9 = (ASN1_ITEM_EXP *)0x638d8c;
        (*(code *)PTR_BIO_printf_006a6e38)(out,"%*s%s",indent);
        (*(code *)PTR_sk_pop_free_006a7058)(0,PTR_X509V3_conf_free_006a7b4c);
        uVar10 = 1;
        (*(code *)PTR_CRYPTO_free_006a6e88)(pcVar3);
        pcVar7 = (char *)method->it;
        pBVar8 = (BIO *)indent;
        indent = (int)pAVar9;
        local_38 = pcVar3;
      }
      if ((ASN1_ITEM_EXP *)pcVar7 == (ASN1_ITEM_EXP *)0x0) {
        (*method->ext_free)(ext_00);
      }
      else {
        (*(code *)PTR_ASN1_item_free_006a8658)(ext_00);
      }
      goto LAB_0058895c;
    }
    if ((flag & 0xf0000) != 0x10000) goto LAB_00588a7c;
    pcVar7 = "%*s<Parse Error>";
LAB_00588adc:
    pAVar9 = (ASN1_ITEM_EXP *)0x638d8c;
    (*(code *)PTR_BIO_printf_006a6e38)(out,pcVar7,indent);
    pBVar8 = (BIO *)indent;
    indent = (int)pAVar9;
  }
  uVar10 = 1;
LAB_0058895c:
  if (local_24 == *(BIO **)puVar1) {
    return uVar10;
  }
  out_00 = local_24;
  (*(code *)PTR___stack_chk_fail_006a9ab0)();
  iVar4 = (*(code *)PTR_sk_num_006a6e2c)(pBVar8);
  if (0 < iVar4) {
    if ((ASN1_ITEM_EXP *)pcVar7 != (ASN1_ITEM_EXP *)0x0) {
      (*(code *)PTR_BIO_printf_006a6e38)(out_00,"%*s%s:\n",local_38,"",pcVar7);
      local_38 = local_38 + 4;
    }
    for (iVar4 = 0; iVar5 = (*(code *)PTR_sk_num_006a6e2c)(pBVar8), iVar4 < iVar5; iVar4 = iVar4 + 1
        ) {
      ex = (X509_EXTENSION *)(*(code *)PTR_sk_value_006a6e24)(pBVar8,iVar4);
      if ((local_38 != (char *)0x0) &&
         (iVar5 = (*(code *)PTR_BIO_printf_006a6e38)(out_00,&DAT_0066d674,local_38,""), iVar5 < 1))
      {
        return 0;
      }
      pAVar6 = X509_EXTENSION_get_object(ex);
      (*(code *)PTR_i2a_ASN1_OBJECT_006a702c)(out_00,pAVar6);
      iVar5 = X509_EXTENSION_get_critical(ex);
      if (iVar5 == 0) {
        iVar5 = (*(code *)PTR_BIO_printf_006a6e38)(out_00,": %s\n","");
      }
      else {
        iVar5 = (*(code *)PTR_BIO_printf_006a6e38)(out_00,": %s\n","critical");
      }
      if (iVar5 < 1) {
        return 0;
      }
      iVar5 = X509V3_EXT_print(out_00,ex,indent,(int)(local_38 + 4));
      if (iVar5 == 0) {
        (*(code *)PTR_BIO_printf_006a6e38)(out_00,&DAT_0066d674,local_38 + 4,"");
        (*(code *)PTR_ASN1_STRING_print_006a8d54)(out_00,ex->value);
      }
      iVar5 = (*(code *)PTR_BIO_write_006a6e14)(out_00,"\n",1);
      if (iVar5 < 1) {
        return 0;
      }
    }
  }
  return 1;
}

