
int X509V3_EXT_print_fp(FILE *out,X509_EXTENSION *ext,int flag,int indent)

{
  undefined *puVar1;
  BIO *out_00;
  X509V3_EXT_METHOD *method;
  ASN1_OCTET_STRING *pAVar2;
  void *ext_00;
  char *pcVar3;
  int iVar4;
  int *piVar5;
  ASN1_ITEM_EXP *pAVar6;
  uint uVar7;
  stack_st_CONF_VALUE *val;
  uchar *local_28;
  int *local_24;
  
  puVar1 = PTR___stack_chk_guard_006a9ae8;
  local_24 = *(int **)PTR___stack_chk_guard_006a9ae8;
  out_00 = (BIO *)(*(code *)PTR_BIO_new_fp_006a7248)(out,0);
  if (out_00 == (BIO *)0x0) {
    uVar7 = 0;
    goto LAB_00588f08;
  }
  method = X509V3_EXT_get(ext);
  if (method == (X509V3_EXT_METHOD *)0x0) {
    if ((flag & 0xf0000U) == 0x10000) {
      pcVar3 = "%*s<Not Supported>";
      goto LAB_0058909c;
    }
LAB_00589038:
    uVar7 = flag & 0xf0000;
    if (uVar7 < 0x10001) {
      if (uVar7 != 0) goto LAB_005890ac;
      uVar7 = 0;
    }
    else if (uVar7 == 0x20000) {
      uVar7 = (*(code *)PTR_ASN1_parse_dump_006a74b8)
                        (out_00,ext->value->data,ext->value->length,indent,0xffffffff);
    }
    else {
      if (uVar7 != 0x30000) goto LAB_005890ac;
      uVar7 = (*(code *)PTR_BIO_dump_indent_006a7334)
                        (out_00,ext->value->data,ext->value->length,indent);
    }
  }
  else {
    pAVar2 = ext->value;
    local_28 = pAVar2->data;
    if (method->it == (ASN1_ITEM_EXP *)0x0) {
      ext_00 = (*method->d2i)((void *)0x0,&local_28,pAVar2->length);
    }
    else {
      ext_00 = (void *)(*(code *)PTR_ASN1_item_d2i_006a8674)(0,&local_28,pAVar2->length);
    }
    if (ext_00 == (void *)0x0) {
      if ((flag & 0xf0000U) != 0x10000) goto LAB_00589038;
      pcVar3 = "%*s<Parse Error>";
LAB_0058909c:
      (*(code *)PTR_BIO_printf_006a6e38)(out_00,pcVar3,indent,"");
LAB_005890ac:
      uVar7 = 1;
    }
    else {
      if (method->i2s == (X509V3_EXT_I2S)0x0) {
        if (method->i2v == (X509V3_EXT_I2V)0x0) {
          if (method->i2r == (X509V3_EXT_I2R)0x0) goto LAB_00588f9c;
          iVar4 = (*method->i2r)(method,ext_00,out_00,indent);
          val = (stack_st_CONF_VALUE *)0x0;
          uVar7 = (uint)(iVar4 != 0);
        }
        else {
          val = (*method->i2v)(method,ext_00,(stack_st_CONF_VALUE *)0x0);
          if (val == (stack_st_CONF_VALUE *)0x0) {
            uVar7 = 0;
          }
          else {
            X509V3_EXT_val_prn(out_00,val,indent,method->ext_flags & 4);
            uVar7 = 1;
          }
        }
LAB_00588fa4:
        (*(code *)PTR_sk_pop_free_006a7058)(val,PTR_X509V3_conf_free_006a7b4c);
        pAVar6 = method->it;
      }
      else {
        pcVar3 = (*method->i2s)(method,ext_00);
        if (pcVar3 == (char *)0x0) {
LAB_00588f9c:
          uVar7 = 0;
          val = (stack_st_CONF_VALUE *)0x0;
          goto LAB_00588fa4;
        }
        (*(code *)PTR_BIO_printf_006a6e38)(out_00,"%*s%s",indent,"",pcVar3);
        (*(code *)PTR_sk_pop_free_006a7058)(0,PTR_X509V3_conf_free_006a7b4c);
        uVar7 = 1;
        (*(code *)PTR_CRYPTO_free_006a6e88)(pcVar3);
        pAVar6 = method->it;
      }
      if (pAVar6 == (ASN1_ITEM_EXP *)0x0) {
        (*method->ext_free)(ext_00);
      }
      else {
        (*(code *)PTR_ASN1_item_free_006a8658)(ext_00);
      }
    }
  }
  (*(code *)PTR_BIO_free_006a6e70)(out_00);
LAB_00588f08:
  if (local_24 == *(int **)puVar1) {
    return uVar7;
  }
  piVar5 = local_24;
  iVar4 = (*(code *)PTR___stack_chk_fail_006a9ab0)();
  if (piVar5 != (int *)0x0) {
    if (piVar5[1] != 0) {
      (*(code *)PTR_CRYPTO_free_006a6e88)();
    }
    if (piVar5[2] != 0) {
      (*(code *)PTR_CRYPTO_free_006a6e88)();
    }
    if (*piVar5 != 0) {
      (*(code *)PTR_CRYPTO_free_006a6e88)();
    }
                    /* WARNING: Could not recover jumptable at 0x0058919c. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    iVar4 = (*(code *)PTR_CRYPTO_free_006a6e88)(piVar5);
    return iVar4;
  }
  return iVar4;
}

