
int X509_load_cert_crl_file(X509_LOOKUP *ctx,char *file,int type)

{
  undefined4 uVar1;
  BIO *bp;
  int iVar2;
  X509 *x;
  undefined4 uVar3;
  
  if (type == 1) {
    iVar2 = X509_load_cert_crl_file_part_0();
    return iVar2;
  }
  if (file == (char *)0x0) {
    return 1;
  }
  uVar1 = (*(code *)PTR_BIO_s_file_006a7fa0)();
  bp = (BIO *)(*(code *)PTR_BIO_new_006a7fa4)(uVar1);
  if (bp == (BIO *)0x0) {
    (*(code *)PTR_ERR_put_error_006a9030)(0xb,0x6f,2,"by_file.c",0x8e);
    return 0;
  }
  iVar2 = (*(code *)PTR_BIO_ctrl_006a7f18)(bp,0x6c,3,file);
  if (iVar2 < 1) {
    uVar3 = 2;
    uVar1 = 0x8e;
  }
  else if (type == 2) {
    x = d2i_X509_bio(bp,(X509 **)0x0);
    if (x != (X509 *)0x0) {
      iVar2 = X509_STORE_add_cert(ctx->store_ctx,x);
      (*(code *)PTR_X509_free_006a7f90)(x);
      goto LAB_0058716c;
    }
    uVar3 = 0xd;
    uVar1 = 0xb3;
  }
  else {
    uVar3 = 100;
    uVar1 = 0xbc;
  }
  iVar2 = 0;
  (*(code *)PTR_ERR_put_error_006a9030)(0xb,0x6f,uVar3,"by_file.c",uVar1);
LAB_0058716c:
  (*(code *)PTR_BIO_free_006a7f70)(bp);
  return iVar2;
}

