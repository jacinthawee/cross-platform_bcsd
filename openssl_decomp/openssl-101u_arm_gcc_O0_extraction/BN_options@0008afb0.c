
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

char * BN_options(void)

{
  if (init_8918 != 0) {
    return PTR_data_8919_0008afe8;
  }
  init_8918 = 1;
  BIO_snprintf(data_8919,0x10,"bn(%d,%d)",0x40,0x20);
  return PTR_data_8919_0008afe8;
}

