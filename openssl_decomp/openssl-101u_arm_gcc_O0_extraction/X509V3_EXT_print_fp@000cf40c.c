
/* WARNING: Type propagation algorithm not settling */

int X509V3_EXT_print_fp(FILE *out,X509_EXTENSION *ext,int flag,int indent)

{
  BIO *bio;
  X509V3_EXT_METHOD *method;
  Elf32_Ehdr *val;
  char *ptr;
  ASN1_OCTET_STRING *pAVar1;
  ASN1_ITEM *it;
  Elf32_Ehdr *st;
  Elf32_Ehdr *pEVar2;
  uchar *local_24 [2];
  
  bio = BIO_new_fp(out,0);
  if (bio == (BIO *)0x0) {
    return 0;
  }
  method = X509V3_EXT_get(ext);
  if (method == (X509V3_EXT_METHOD *)0x0) {
    pEVar2 = (Elf32_Ehdr *)(flag & 0xf0000);
    if (pEVar2 == &Elf32_Ehdr_00010000) {
      BIO_printf(bio,"%*s<Not Supported>",indent,"");
      pEVar2 = (Elf32_Ehdr *)0x1;
      goto LAB_000cf49e;
    }
    if (Elf32_Ehdr_00010000.e_ident_magic_str <= pEVar2) goto joined_r0x000cf538;
joined_r0x000cf588:
    if ((flag & 0xf0000U) == 0) goto LAB_000cf49e;
  }
  else {
    pAVar1 = ext->value;
    local_24[0] = pAVar1->data;
    if (method->it == (ASN1_ITEM *)0x0) {
      val = (Elf32_Ehdr *)(*method->d2i)((void *)0x0,local_24,pAVar1->length);
    }
    else {
      val = (Elf32_Ehdr *)ASN1_item_d2i((ASN1_VALUE **)0x0,local_24,pAVar1->length,method->it);
    }
    if (val != (Elf32_Ehdr *)0x0) {
      if (method->i2s == (X509V3_EXT_I2S)0x0) {
        st = (Elf32_Ehdr *)method->i2v;
        if (st == (Elf32_Ehdr *)0x0) {
          if (method->i2r == (X509V3_EXT_I2R)0x0) goto LAB_000cf4da;
          pEVar2 = (Elf32_Ehdr *)(*method->i2r)(method,val,bio,indent);
          if (pEVar2 != (Elf32_Ehdr *)0x0) {
            pEVar2 = (Elf32_Ehdr *)0x1;
          }
        }
        else {
          st = (Elf32_Ehdr *)(*(code *)st)(method,val);
          pEVar2 = st;
          if (st != (Elf32_Ehdr *)0x0) {
            X509V3_EXT_val_prn(bio,(stack_st_CONF_VALUE *)st,indent,method->ext_flags & 4);
            pEVar2 = (Elf32_Ehdr *)0x1;
          }
        }
LAB_000cf4e0:
        sk_pop_free((_STACK *)st,X509V3_conf_free + 1);
        it = method->it;
      }
      else {
        ptr = (*method->i2s)(method,val);
        if (ptr == (char *)0x0) {
LAB_000cf4da:
          st = (Elf32_Ehdr *)0x0;
          pEVar2 = (Elf32_Ehdr *)0x0;
          goto LAB_000cf4e0;
        }
        pEVar2 = (Elf32_Ehdr *)0x1;
        BIO_printf(bio,"%*s%s",indent,"",ptr);
        sk_pop_free((_STACK *)0x0,X509V3_conf_free + 1);
        CRYPTO_free(ptr);
        it = method->it;
      }
      if (it == (ASN1_ITEM *)0x0) {
        (*method->ext_free)(val);
      }
      else {
        ASN1_item_free((ASN1_VALUE *)val,it);
      }
      goto LAB_000cf49e;
    }
    if ((flag & 0xf0000U) == 0x10000) {
      BIO_printf(bio,"%*s<Parse Error>",indent,"");
      pEVar2 = (Elf32_Ehdr *)0x1;
      goto LAB_000cf49e;
    }
    pEVar2 = val;
    if ((flag & 0xf0000U) < 0x10001) goto joined_r0x000cf588;
joined_r0x000cf538:
    if ((Elf32_Ehdr *)(flag & 0xf0000U) == (Elf32_Ehdr *)0x20000) {
      pEVar2 = (Elf32_Ehdr *)ASN1_parse_dump(bio,ext->value->data,ext->value->length,indent,-1);
      goto LAB_000cf49e;
    }
    if ((flag & 0xf0000U) == 0x30000) {
      pEVar2 = (Elf32_Ehdr *)BIO_dump_indent(bio,ext->value->data,ext->value->length,indent);
      goto LAB_000cf49e;
    }
  }
  pEVar2 = (Elf32_Ehdr *)0x1;
LAB_000cf49e:
  BIO_free(bio);
  return (int)pEVar2;
}

