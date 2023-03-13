
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

BIO_METHOD * BIO_s_datagram(void)

{
  return (BIO_METHOD *)methods_dgramp;
}

