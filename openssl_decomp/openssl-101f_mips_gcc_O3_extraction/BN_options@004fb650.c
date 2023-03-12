
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

char * BN_options(void)

{
  if (init_6276 != 0) {
    return data_6277;
  }
  init_6276 = 1;
  (*(code *)PTR_BIO_snprintf_006a8060)(data_6277,0x10,"bn(%d,%d)",0x40,0x20);
  return data_6277;
}

