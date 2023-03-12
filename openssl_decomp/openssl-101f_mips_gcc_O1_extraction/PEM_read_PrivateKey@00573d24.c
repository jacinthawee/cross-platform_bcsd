
EVP_PKEY * PEM_read_PrivateKey(FILE *fp,EVP_PKEY **x,undefined1 *cb,void *u)

{
  undefined4 uVar1;
  BIO *bp;
  EVP_PKEY *pEVar2;
  
  uVar1 = (*(code *)PTR_BIO_s_file_006a7fa0)();
  bp = (BIO *)(*(code *)PTR_BIO_new_006a7fa4)(uVar1);
  if (bp == (BIO *)0x0) {
    (*(code *)PTR_ERR_put_error_006a9030)(9,0x7c,7,"pem_pkey.c",0xd8);
    pEVar2 = (EVP_PKEY *)0x0;
  }
  else {
    (*(code *)PTR_BIO_ctrl_006a7f18)(bp,0x6a,0,fp);
    pEVar2 = PEM_read_bio_PrivateKey(bp,x,cb,u);
    (*(code *)PTR_BIO_free_006a7f70)(bp);
  }
  return pEVar2;
}

