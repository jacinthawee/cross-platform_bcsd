
int X509V3_EXT_print_fp(FILE *out,X509_EXTENSION *ext,int flag,int indent)

{
  ASN1_OCTET_STRING *pAVar1;
  ASN1_ITEM *it;
  BIO *bio;
  X509V3_EXT_METHOD *method;
  ASN1_VALUE *val;
  char *ptr;
  _STACK *st;
  int iVar2;
  uint uVar3;
  ASN1_VALUE *pAVar4;
  int in_GS_OFFSET;
  bool bVar5;
  uchar *local_24;
  int local_20;
  
  pAVar4 = (ASN1_VALUE *)0x0;
  local_20 = *(int *)(in_GS_OFFSET + 0x14);
  bio = BIO_new_fp(out,0);
  if (bio == (BIO *)0x0) goto LAB_08169854;
  method = X509V3_EXT_get(ext);
  if (method == (X509V3_EXT_METHOD *)0x0) {
    bVar5 = (flag & 0xf0000U) == 0x10000;
    if (bVar5) {
      pAVar4 = (ASN1_VALUE *)0x1;
      BIO_printf(bio,"%*s<Not Supported>",indent,&DAT_081eca46);
    }
    else {
LAB_08169948:
      uVar3 = flag & 0xf0000;
      if (uVar3 < 0x10000 || bVar5) {
        if (uVar3 != 0) {
LAB_081699c7:
          pAVar4 = (ASN1_VALUE *)0x1;
        }
      }
      else if (uVar3 == 0x20000) {
        pAVar4 = (ASN1_VALUE *)ASN1_parse_dump(bio,ext->value->data,ext->value->length,indent,-1);
      }
      else {
        if (uVar3 != 0x30000) goto LAB_081699c7;
        pAVar4 = (ASN1_VALUE *)
                 BIO_dump_indent(bio,(char *)ext->value->data,ext->value->length,indent);
      }
    }
  }
  else {
    pAVar1 = ext->value;
    local_24 = pAVar1->data;
    if (method->it == (ASN1_ITEM *)0x0) {
      val = (ASN1_VALUE *)(*method->d2i)((void *)0x0,&local_24,pAVar1->length);
    }
    else {
      val = ASN1_item_d2i((ASN1_VALUE **)0x0,&local_24,pAVar1->length,method->it);
    }
    if (val == (ASN1_VALUE *)0x0) {
      bVar5 = (flag & 0xf0000U) == 0x10000;
      pAVar4 = val;
      if (!bVar5) goto LAB_08169948;
      BIO_printf(bio,"%*s<Parse Error>",indent,&DAT_081eca46);
      goto LAB_081699c7;
    }
    if (method->i2s == (X509V3_EXT_I2S)0x0) {
      if (method->i2v == (X509V3_EXT_I2V)0x0) {
        if (method->i2r == (X509V3_EXT_I2R)0x0) goto LAB_081698c0;
        iVar2 = (*method->i2r)(method,val,bio,indent);
        pAVar4 = (ASN1_VALUE *)(uint)(iVar2 != 0);
        st = (_STACK *)0x0;
      }
      else {
        pAVar4 = (ASN1_VALUE *)0x0;
        st = (_STACK *)(*method->i2v)(method,val,(stack_st_CONF_VALUE *)0x0);
        if (st != (_STACK *)0x0) {
          pAVar4 = (ASN1_VALUE *)0x1;
          X509V3_EXT_val_prn(bio,(stack_st_CONF_VALUE *)st,indent,method->ext_flags & 4);
        }
      }
LAB_081698c4:
      sk_pop_free(st,X509V3_conf_free);
      it = method->it;
    }
    else {
      ptr = (*method->i2s)(method,val);
      if (ptr == (char *)0x0) {
LAB_081698c0:
        pAVar4 = (ASN1_VALUE *)0x0;
        st = (_STACK *)0x0;
        goto LAB_081698c4;
      }
      BIO_printf(bio,"%*s%s",indent,&DAT_081eca46,ptr);
      sk_pop_free((_STACK *)0x0,X509V3_conf_free);
      pAVar4 = (ASN1_VALUE *)0x1;
      CRYPTO_free(ptr);
      it = method->it;
    }
    if (it == (ASN1_ITEM *)0x0) {
      (*method->ext_free)(val);
    }
    else {
      ASN1_item_free(val,it);
    }
  }
  BIO_free(bio);
LAB_08169854:
  if (local_20 == *(int *)(in_GS_OFFSET + 0x14)) {
    return (int)pAVar4;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}

