
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

char * DES_options(void)

{
  if (init_9304 != 0) {
    BIO_snprintf(&buf_9305,0x20,"des(%s,%s,%s,%s)",&DAT_00152ff8,&DAT_00152ffc,"16","long");
    init_9304 = 0;
  }
  return &buf_9305;
}

