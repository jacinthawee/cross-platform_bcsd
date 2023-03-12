
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

BIO_METHOD * BIO_s_fd(void)

{
  return (BIO_METHOD *)&methods_fdp;
}

