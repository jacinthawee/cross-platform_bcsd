
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

char * BN_options(void)

{
  if (init_6264 != 0) {
    return data_6265;
  }
  init_6264 = 1;
  BIO_snprintf(data_6265,0x10,"bn(%d,%d)",0x40,0x20);
  return data_6265;
}

