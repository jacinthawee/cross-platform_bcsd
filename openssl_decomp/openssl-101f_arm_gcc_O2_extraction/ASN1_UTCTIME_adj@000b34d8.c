
ASN1_UTCTIME * ASN1_UTCTIME_adj(ASN1_UTCTIME *s,time_t t,int offset_day,long offset_sec)

{
  undefined4 *puVar1;
  size_t sVar2;
  int iVar3;
  uchar *buf;
  time_t local_4c [2];
  undefined auStack_44 [44];
  
  local_4c[0] = t;
  if (((((s != (ASN1_UTCTIME *)0x0) || (s = ASN1_STRING_type_new(0x17), s != (ASN1_STRING *)0x0)) &&
       (puVar1 = (undefined4 *)OPENSSL_gmtime(local_4c,auStack_44), puVar1 != (undefined4 *)0x0)) &&
      ((offset_sec == 0 && offset_day == 0 ||
       (iVar3 = OPENSSL_gmtime_adj(puVar1,offset_day,offset_sec), iVar3 != 0)))) &&
     (iVar3 = puVar1[5], iVar3 - 0x32U < 100)) {
    buf = s->data;
    if ((buf == (uchar *)0x0) || ((uint)s->length < 0x14)) {
      buf = (uchar *)CRYPTO_malloc(0x14,"a_utctm.c",0xdd);
      if (buf == (uchar *)0x0) {
        ERR_put_error(0xd,0xda,0x41,"a_utctm.c",0xe0);
        return (ASN1_UTCTIME *)0x0;
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
    return s;
  }
  return (ASN1_UTCTIME *)0x0;
}

