
int X509_load_cert_file(X509_LOOKUP *ctx,char *file,int type)

{
  undefined4 uVar1;
  BIO *bp;
  int iVar2;
  int iVar3;
  uint uVar4;
  X509 *x;
  undefined4 uVar5;
  
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
    uVar5 = 2;
    uVar1 = 0x8e;
  }
  else if (type == 1) {
    iVar2 = 0;
    while (x = PEM_read_bio_X509_AUX(bp,(X509 **)0x0,(undefined1 *)0x0,(void *)0x0),
          x != (X509 *)0x0) {
      iVar2 = iVar2 + 1;
      iVar3 = X509_STORE_add_cert(ctx->store_ctx,x);
      if (iVar3 == 0) {
        iVar2 = 0;
        goto LAB_00586cd4;
      }
      (*(code *)PTR_X509_free_006a7f90)(x);
    }
    uVar4 = (*(code *)PTR_ERR_peek_last_error_006a8508)();
    if (((uVar4 & 0xfff) == 0x6c) && (iVar2 != 0)) {
      (*(code *)PTR_ERR_clear_error_006a7fe0)();
      goto LAB_00586b68;
    }
    uVar5 = 9;
    uVar1 = 0xa2;
  }
  else {
    if (type != 2) {
      iVar2 = 0;
      (*(code *)PTR_ERR_put_error_006a9030)(0xb,0x6f,100,"by_file.c",0xbc);
      goto LAB_00586b68;
    }
    x = d2i_X509_bio(bp,(X509 **)0x0);
    if (x != (X509 *)0x0) {
      iVar2 = X509_STORE_add_cert(ctx->store_ctx,x);
LAB_00586cd4:
      (*(code *)PTR_X509_free_006a7f90)(x);
      goto LAB_00586b68;
    }
    uVar5 = 0xd;
    uVar1 = 0xb3;
  }
  iVar2 = 0;
  (*(code *)PTR_ERR_put_error_006a9030)(0xb,0x6f,uVar5,"by_file.c",uVar1);
LAB_00586b68:
  (*(code *)PTR_BIO_free_006a7f70)(bp);
  return iVar2;
}
