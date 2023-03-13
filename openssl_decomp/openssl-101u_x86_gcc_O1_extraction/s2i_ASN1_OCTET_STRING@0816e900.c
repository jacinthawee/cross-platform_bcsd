
ASN1_OCTET_STRING * s2i_ASN1_OCTET_STRING(X509V3_EXT_METHOD *method,X509V3_CTX *ctx,char *str)

{
  ASN1_OCTET_STRING *a;
  uchar *puVar1;
  int in_GS_OFFSET;
  int local_14;
  int local_10;
  
  local_10 = *(int *)(in_GS_OFFSET + 0x14);
  a = ASN1_STRING_type_new(4);
  if (a == (ASN1_STRING *)0x0) {
    ERR_put_error(0x22,0x70,0x41,"v3_skey.c",0x57);
    a = (ASN1_OCTET_STRING *)0x0;
  }
  else {
    puVar1 = string_to_hex(str,&local_14);
    a->data = puVar1;
    if (puVar1 == (uchar *)0x0) {
      ASN1_STRING_free(a);
      a = (ASN1_OCTET_STRING *)0x0;
    }
    else {
      a->length = local_14;
    }
  }
  if (local_10 == *(int *)(in_GS_OFFSET + 0x14)) {
    return a;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}

