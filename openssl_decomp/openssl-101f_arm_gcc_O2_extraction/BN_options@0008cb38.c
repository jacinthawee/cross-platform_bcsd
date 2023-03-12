
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

char * BN_options(void)

{
  if (init_8910 != 0) {
    return PTR_data_8911_0008cb70;
  }
  init_8910 = 1;
  BIO_snprintf(data_8911,0x10,"bn(%d,%d)",0x40,0x20);
  return PTR_data_8911_0008cb70;
}

