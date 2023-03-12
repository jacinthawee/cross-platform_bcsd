
BIO * BIO_new_file(char *filename,char *mode)

{
  FILE *__stream;
  FILE *b;
  int *piVar1;
  
  __stream = fopen64(filename,mode);
  if (__stream == (FILE *)0x0) {
    piVar1 = __errno_location();
    ERR_put_error(2,1,*piVar1,"bss_file.c",0xa9);
    ERR_add_error_data(5,"fopen(\'",filename,&DAT_0015f0a8,mode,&DAT_0013adec);
    if (*piVar1 != 2) {
      ERR_put_error(0x20,0x6d,2,"bss_file.c",0xae);
      return (BIO *)0x0;
    }
    ERR_put_error(0x20,0x6d,0x80,"bss_file.c",0xac);
  }
  else {
    b = (FILE *)BIO_new((BIO_METHOD *)&methods_filep);
    if (b == (FILE *)0x0) {
      fclose(__stream);
      __stream = b;
    }
    else {
      BIO_clear_flags((BIO *)b,0);
      BIO_ctrl((BIO *)b,0x6a,1,__stream);
      __stream = b;
    }
  }
  return (BIO *)__stream;
}

