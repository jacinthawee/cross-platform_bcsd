
ASN1_GENERALIZEDTIME * ASN1_GENERALIZEDTIME_set(ASN1_GENERALIZEDTIME *s,time_t t)

{
  undefined4 *puVar1;
  uchar *buf;
  size_t sVar2;
  int in_GS_OFFSET;
  time_t local_40;
  undefined local_3c [44];
  int local_10;
  
  local_10 = *(int *)(in_GS_OFFSET + 0x14);
  local_40 = t;
  if (s == (ASN1_GENERALIZEDTIME *)0x0) {
    s = ASN1_STRING_type_new(0x18);
    if (s == (ASN1_STRING *)0x0) {
      s = (ASN1_GENERALIZEDTIME *)0x0;
      goto LAB_0813a0e6;
    }
  }
  puVar1 = (undefined4 *)OPENSSL_gmtime(&local_40,local_3c);
  if (puVar1 == (undefined4 *)0x0) {
LAB_0813a120:
    s = (ASN1_GENERALIZEDTIME *)0x0;
  }
  else {
    buf = s->data;
    if ((buf == (uchar *)0x0) || ((uint)s->length < 0x14)) {
      buf = (uchar *)CRYPTO_malloc(0x14,"a_gentm.c",0xf3);
      if (buf == (uchar *)0x0) {
        ERR_put_error(0xd,0xd8,0x41,"a_gentm.c",0xf7);
        goto LAB_0813a120;
      }
      if (s->data != (uchar *)0x0) {
        CRYPTO_free(s->data);
      }
      s->data = buf;
    }
    BIO_snprintf((char *)buf,0x14,"%04d%02d%02d%02d%02d%02dZ",puVar1[5] + 0x76c,puVar1[4] + 1,
                 puVar1[3],puVar1[2],puVar1[1],*puVar1);
    sVar2 = strlen((char *)buf);
    s->length = sVar2;
    s->type = 0x18;
  }
LAB_0813a0e6:
  if (local_10 == *(int *)(in_GS_OFFSET + 0x14)) {
    return s;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}

