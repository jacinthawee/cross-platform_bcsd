
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

char * DES_options(void)

{
  if (init_6765 == 0) {
    return buf_6766;
  }
  BIO_snprintf(buf_6766,0x20,"des(%s,%s,%s,%s)",&DAT_08216205,&DAT_08216200,"16","long");
  init_6765 = 0;
  return buf_6766;
}

