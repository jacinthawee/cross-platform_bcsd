
DH * __regparm3 load_dh_param(char *param_1)

{
  BIO *bp;
  DH *pDVar1;
  
  bp = BIO_new_file(param_1,"r");
  if (bp == (BIO *)0x0) {
    pDVar1 = (DH *)0x0;
  }
  else {
    pDVar1 = PEM_read_bio_DHparams(bp,(DH **)0x0,(undefined1 *)0x0,(void *)0x0);
    BIO_free(bp);
  }
  return pDVar1;
}

