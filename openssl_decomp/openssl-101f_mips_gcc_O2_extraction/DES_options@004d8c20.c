
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

char * DES_options(void)

{
  if (init_6666 == 0) {
    return buf_6667;
  }
  (*(code *)PTR_BIO_snprintf_006a8060)
            (buf_6667,0x20,"des(%s,%s,%s,%s)",&DAT_0065ba30,&DAT_0065ba48,"16","long");
  init_6666 = 0;
  return buf_6667;
}

