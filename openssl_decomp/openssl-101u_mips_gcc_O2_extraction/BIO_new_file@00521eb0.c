
BIO * BIO_new_file(char *filename,char *mode)

{
  void *parg;
  BIO *b;
  int *piVar1;
  int line;
  int reason;
  
  parg = (void *)(*(code *)PTR_fopen64_006a9990)();
  if (parg != (void *)0x0) {
    b = BIO_new((BIO_METHOD *)methods_filep);
    if (b == (BIO *)0x0) {
      (*(code *)PTR_fclose_006a9998)(parg);
      b = (BIO *)0x0;
    }
    else {
      BIO_clear_flags(b,0);
      BIO_ctrl(b,0x6a,1,parg);
    }
    return b;
  }
  piVar1 = (int *)(*(code *)PTR___errno_location_006a99e8)();
  ERR_put_error(2,1,*piVar1,"bss_file.c",0xaf);
  ERR_add_error_data(5,"fopen(\'",filename,&DAT_00667534,mode,&DAT_00647d34);
  if (*piVar1 == 2) {
    reason = 0x80;
    line = 0xb2;
  }
  else {
    reason = 2;
    line = 0xb4;
  }
  ERR_put_error(0x20,0x6d,reason,"bss_file.c",line);
  return (BIO *)0x0;
}

