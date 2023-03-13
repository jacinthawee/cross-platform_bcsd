
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

ulong * OPENSSL_ia32cap_loc(void)

{
  OPENSSL_ia32cap_P._4_4_ = 0;
  return (ulong *)&OPENSSL_ia32cap_P;
}

