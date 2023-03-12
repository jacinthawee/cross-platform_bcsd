
uchar * SHA1(uchar *d,size_t n,uchar *md)

{
  uchar *puVar1;
  SHA_CTX SStack_70;
  
  if (md == (uchar *)0x0) {
    md = &m_6572;
  }
  puVar1 = (uchar *)SHA1_Init(&SStack_70);
  if (puVar1 != (uchar *)0x0) {
    SHA1_Update(&SStack_70,d,n);
    SHA1_Final(md,&SStack_70);
    OPENSSL_cleanse(&SStack_70,0x60);
    puVar1 = md;
  }
  return puVar1;
}

