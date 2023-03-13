
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

char * BN_options(void)

{
  if (init_6284 != 0) {
    return data_6285;
  }
  init_6284 = 1;
  (*(code *)PTR_BIO_snprintf_006a6f60)(data_6285,0x10,"bn(%d,%d)",0x40,0x20);
  return data_6285;
}

