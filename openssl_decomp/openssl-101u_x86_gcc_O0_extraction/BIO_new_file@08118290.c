
BIO * BIO_new_file(char *filename,char *mode)

{
  FILE *__stream;
  BIO *b;
  int *piVar1;
  int reason;
  int line;
  
  __stream = fopen64(filename,mode);
  if (__stream != (FILE *)0x0) {
    b = BIO_new((BIO_METHOD *)methods_filep);
    if (b == (BIO *)0x0) {
      fclose(__stream);
      b = (BIO *)0x0;
    }
    else {
      BIO_clear_flags(b,0);
      BIO_ctrl(b,0x6a,1,__stream);
    }
    return b;
  }
  piVar1 = __errno_location();
  ERR_put_error(2,1,*piVar1,"bss_file.c",0xaf);
  ERR_add_error_data(5,"fopen(\'",filename,&DAT_0822372b,mode,&DAT_082003db);
  if (*piVar1 == 2) {
    line = 0xb2;
    reason = 0x80;
  }
  else {
    line = 0xb4;
    reason = 2;
  }
  ERR_put_error(0x20,0x6d,reason,"bss_file.c",line);
  return (BIO *)0x0;
}

