
uchar * SHA1(uchar *d,size_t n,uchar *md)

{
  int iVar1;
  uchar *puVar2;
  int in_GS_OFFSET;
  SHA_CTX local_70;
  int local_10;
  
  local_10 = *(int *)(in_GS_OFFSET + 0x14);
  if (md == (uchar *)0x0) {
    md = m_3918;
  }
  iVar1 = SHA1_Init(&local_70);
  puVar2 = (uchar *)0x0;
  if (iVar1 != 0) {
    SHA1_Update(&local_70,d,n);
    SHA1_Final(md,&local_70);
    OPENSSL_cleanse(&local_70,0x60);
    puVar2 = md;
  }
  if (local_10 == *(int *)(in_GS_OFFSET + 0x14)) {
    return puVar2;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}

