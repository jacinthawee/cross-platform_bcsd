
int X509V3_EXT_print(BIO *out,X509_EXTENSION *ext,ulong flag,int indent)

{
  ASN1_OCTET_STRING *pAVar1;
  ASN1_ITEM *it;
  X509V3_EXT_METHOD *method;
  ASN1_VALUE *val;
  char *ptr;
  _STACK *st;
  int iVar2;
  uint uVar3;
  uint uVar4;
  int in_GS_OFFSET;
  bool bVar5;
  uchar *local_24;
  int local_20;
  
  local_20 = *(int *)(in_GS_OFFSET + 0x14);
  method = X509V3_EXT_get(ext);
  if (method == (X509V3_EXT_METHOD *)0x0) {
    bVar5 = (flag & 0xf0000) == 0x10000;
    if (bVar5) {
      BIO_printf(out,"%*s<Not Supported>",indent,&DAT_081ec74a);
      uVar4 = 1;
      goto LAB_0816b337;
    }
LAB_0816b41a:
    uVar3 = flag & 0xf0000;
    if (uVar3 < 0x10000 || bVar5) {
      uVar4 = 0;
      if (uVar3 == 0) goto LAB_0816b337;
    }
    else {
      if (uVar3 == 0x20000) {
        uVar4 = ASN1_parse_dump(out,ext->value->data,ext->value->length,indent,-1);
        goto LAB_0816b337;
      }
      if (uVar3 == 0x30000) {
        uVar4 = BIO_dump_indent(out,(char *)ext->value->data,ext->value->length,indent);
        goto LAB_0816b337;
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
    if (val != (ASN1_VALUE *)0x0) {
      if (method->i2s == (X509V3_EXT_I2S)0x0) {
        if (method->i2v == (X509V3_EXT_I2V)0x0) {
          if (method->i2r == (X509V3_EXT_I2R)0x0) goto LAB_0816b350;
          iVar2 = (*method->i2r)(method,val,out,indent);
          uVar4 = (uint)(iVar2 != 0);
          st = (_STACK *)0x0;
        }
        else {
          uVar4 = 0;
          st = (_STACK *)(*method->i2v)(method,val,(stack_st_CONF_VALUE *)0x0);
          if (st != (_STACK *)0x0) {
            uVar4 = 1;
            X509V3_EXT_val_prn(out,(stack_st_CONF_VALUE *)st,indent,method->ext_flags & 4);
          }
        }
LAB_0816b354:
        sk_pop_free(st,X509V3_conf_free);
        it = method->it;
      }
      else {
        ptr = (*method->i2s)(method,val);
        if (ptr == (char *)0x0) {
LAB_0816b350:
          uVar4 = 0;
          st = (_STACK *)0x0;
          goto LAB_0816b354;
        }
        BIO_printf(out,"%*s%s",indent,&DAT_081ec74a,ptr);
        sk_pop_free((_STACK *)0x0,X509V3_conf_free);
        uVar4 = 1;
        CRYPTO_free(ptr);
        it = method->it;
      }
      if (it == (ASN1_ITEM *)0x0) {
        (*method->ext_free)(val);
      }
      else {
        ASN1_item_free(val,it);
      }
      goto LAB_0816b337;
    }
    bVar5 = (flag & 0xf0000) == 0x10000;
    if (!bVar5) goto LAB_0816b41a;
    BIO_printf(out,"%*s<Parse Error>",indent,&DAT_081ec74a);
  }
  uVar4 = 1;
LAB_0816b337:
  if (local_20 == *(int *)(in_GS_OFFSET + 0x14)) {
    return uVar4;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}

