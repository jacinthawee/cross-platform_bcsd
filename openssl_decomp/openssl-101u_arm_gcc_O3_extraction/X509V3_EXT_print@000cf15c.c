
int X509V3_EXT_print(BIO *out,X509_EXTENSION *ext,ulong flag,int indent)

{
  X509V3_EXT_METHOD *method;
  Elf32_Ehdr *val;
  char *ptr;
  int iVar1;
  ASN1_OCTET_STRING *pAVar2;
  ASN1_ITEM *it;
  _STACK *st;
  _STACK *p_Var3;
  uchar *local_24 [2];
  
  method = X509V3_EXT_get(ext);
  if (method == (X509V3_EXT_METHOD *)0x0) {
    val = (Elf32_Ehdr *)(flag & 0xf0000);
    if (val == &Elf32_Ehdr_00010000) {
      BIO_printf(out,"%*s<Not Supported>",indent,"");
      return 1;
    }
    if (Elf32_Ehdr_00010000.e_ident_magic_str <= val) {
joined_r0x000cf26e:
      if ((flag & 0xf0000) == 0x20000) {
        iVar1 = ASN1_parse_dump(out,ext->value->data,ext->value->length,indent,-1);
        return iVar1;
      }
      if ((flag & 0xf0000) != 0x30000) {
        return 1;
      }
      iVar1 = BIO_dump_indent(out,ext->value->data,ext->value->length,indent);
      return iVar1;
    }
joined_r0x000cf2ba:
    if ((flag & 0xf0000) != 0) {
      return 1;
    }
    return (int)val;
  }
  pAVar2 = ext->value;
  local_24[0] = pAVar2->data;
  if (method->it == (ASN1_ITEM *)0x0) {
    val = (Elf32_Ehdr *)(*method->d2i)((void *)0x0,local_24,pAVar2->length);
  }
  else {
    val = (Elf32_Ehdr *)ASN1_item_d2i((ASN1_VALUE **)0x0,local_24,pAVar2->length,method->it);
  }
  if (val == (Elf32_Ehdr *)0x0) {
    if ((flag & 0xf0000) == 0x10000) {
      BIO_printf(out,"%*s<Parse Error>",indent,"");
      return 1;
    }
    if (0x10000 < (flag & 0xf0000)) goto joined_r0x000cf26e;
    goto joined_r0x000cf2ba;
  }
  if (method->i2s == (X509V3_EXT_I2S)0x0) {
    st = (_STACK *)method->i2v;
    if (st == (_STACK *)0x0) {
      if (method->i2r == (X509V3_EXT_I2R)0x0) goto LAB_000cf1e4;
      p_Var3 = (_STACK *)(*method->i2r)(method,val,out,indent);
      if (p_Var3 != (_STACK *)0x0) {
        p_Var3 = (_STACK *)0x1;
      }
    }
    else {
      st = (_STACK *)(*(code *)st)(method,val);
      p_Var3 = st;
      if (st != (_STACK *)0x0) {
        X509V3_EXT_val_prn(out,(stack_st_CONF_VALUE *)st,indent,method->ext_flags & 4);
        p_Var3 = (_STACK *)0x1;
      }
    }
  }
  else {
    ptr = (*method->i2s)(method,val);
    if (ptr != (char *)0x0) {
      p_Var3 = (_STACK *)0x1;
      BIO_printf(out,"%*s%s",indent,"",ptr);
      sk_pop_free((_STACK *)0x0,X509V3_conf_free + 1);
      CRYPTO_free(ptr);
      it = method->it;
      goto joined_r0x000cf1fa;
    }
LAB_000cf1e4:
    st = (_STACK *)0x0;
    p_Var3 = (_STACK *)0x0;
  }
  sk_pop_free(st,X509V3_conf_free + 1);
  it = method->it;
joined_r0x000cf1fa:
  if (it == (ASN1_ITEM *)0x0) {
    (*method->ext_free)(val);
    return (int)p_Var3;
  }
  ASN1_item_free((ASN1_VALUE *)val,it);
  return (int)p_Var3;
}

