
DH * load_dh_param(char *param_1)

{
  DH *bp;
  DH *pDVar1;
  
  bp = (DH *)BIO_new_file(param_1,"r");
  if (bp != (DH *)0x0) {
    pDVar1 = PEM_read_bio_DHparams((BIO *)bp,(DH **)0x0,(undefined1 *)0x0,(void *)0x0);
    BIO_free((BIO *)bp);
    bp = pDVar1;
  }
  return bp;
}

