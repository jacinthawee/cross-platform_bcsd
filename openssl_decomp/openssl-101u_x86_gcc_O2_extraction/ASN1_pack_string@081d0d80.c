
ASN1_STRING * ASN1_pack_string(void *obj,undefined1 *i2d,ASN1_OCTET_STRING **oct)

{
  ASN1_STRING *pAVar1;
  int num;
  ASN1_STRING *a;
  int in_GS_OFFSET;
  uchar *local_24;
  int local_20;
  
  local_20 = *(int *)(in_GS_OFFSET + 0x14);
  if (oct == (ASN1_OCTET_STRING **)0x0) {
    a = ASN1_STRING_new();
    if (a == (ASN1_STRING *)0x0) {
LAB_081d0eaf:
      ERR_put_error(0xd,0x7c,0x41,"asn_pack.c",0x86);
      a = (ASN1_STRING *)0x0;
      goto LAB_081d0e41;
    }
  }
  else {
    a = *oct;
    if (a == (ASN1_STRING *)0x0) {
      a = ASN1_STRING_new();
      if (a == (ASN1_STRING *)0x0) goto LAB_081d0eaf;
      *oct = a;
    }
  }
  num = (*(code *)i2d)(obj,0);
  a->length = num;
  if (num == 0) {
    ERR_put_error(0xd,0x7c,0x70,"asn_pack.c",0x8f);
  }
  else {
    local_24 = (uchar *)CRYPTO_malloc(num,"asn_pack.c",0x92);
    if (local_24 != (uchar *)0x0) {
      a->data = local_24;
      (*(code *)i2d)(obj,&local_24);
      goto LAB_081d0e41;
    }
    ERR_put_error(0xd,0x7c,0x41,"asn_pack.c",0x93);
  }
  if (oct == (ASN1_OCTET_STRING **)0x0) {
    ASN1_STRING_free(a);
    a = (ASN1_STRING *)0x0;
  }
  else {
    pAVar1 = *oct;
    if (pAVar1 == (ASN1_STRING *)0x0) {
      ASN1_STRING_free(a);
      *oct = (ASN1_OCTET_STRING *)0x0;
      a = pAVar1;
    }
    else {
      a = (ASN1_STRING *)0x0;
    }
  }
LAB_081d0e41:
  if (local_20 == *(int *)(in_GS_OFFSET + 0x14)) {
    return a;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}

