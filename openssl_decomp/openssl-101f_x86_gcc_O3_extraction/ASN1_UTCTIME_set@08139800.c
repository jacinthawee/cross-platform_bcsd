
ASN1_UTCTIME * ASN1_UTCTIME_set(ASN1_UTCTIME *s,time_t t)

{
  undefined4 *puVar1;
  uchar *buf;
  size_t sVar2;
  int iVar3;
  int in_GS_OFFSET;
  time_t local_40;
  undefined local_3c [44];
  int local_10;
  
  local_10 = *(int *)(in_GS_OFFSET + 0x14);
  local_40 = t;
  if (s == (ASN1_UTCTIME *)0x0) {
    s = ASN1_STRING_type_new(0x17);
    if (s == (ASN1_STRING *)0x0) {
      s = (ASN1_UTCTIME *)0x0;
      goto LAB_081398e8;
    }
  }
  puVar1 = (undefined4 *)OPENSSL_gmtime(&local_40,local_3c);
  if ((puVar1 == (undefined4 *)0x0) || (iVar3 = puVar1[5], 99 < iVar3 - 0x32U)) {
LAB_08139920:
    s = (ASN1_UTCTIME *)0x0;
  }
  else {
    buf = s->data;
    if ((buf == (uchar *)0x0) || ((uint)s->length < 0x14)) {
      buf = (uchar *)CRYPTO_malloc(0x14,"a_utctm.c",0xdd);
      if (buf == (uchar *)0x0) {
        ERR_put_error(0xd,0xda,0x41,"a_utctm.c",0xe0);
        goto LAB_08139920;
      }
      if (s->data != (uchar *)0x0) {
        CRYPTO_free(s->data);
      }
      iVar3 = puVar1[5];
      s->data = buf;
    }
    BIO_snprintf((char *)buf,0x14,"%02d%02d%02d%02d%02d%02dZ",iVar3 % 100,puVar1[4] + 1,puVar1[3],
                 puVar1[2],puVar1[1],*puVar1);
    sVar2 = strlen((char *)buf);
    s->length = sVar2;
    s->type = 0x17;
  }
LAB_081398e8:
  if (local_10 == *(int *)(in_GS_OFFSET + 0x14)) {
    return s;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}

