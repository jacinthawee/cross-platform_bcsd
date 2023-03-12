
undefined4 __regparm3
check(X509_STORE *param_1_00,char *param_2_00,stack_st_X509 *param_3_00,stack_st_X509 *param_1,
     stack_st_X509_CRL *param_2,undefined4 param_3)

{
  X509 *x509;
  X509_STORE_CTX *ctx;
  int iVar1;
  undefined4 uVar2;
  
  x509 = (X509 *)load_cert(bio_err,param_2_00,3,0,param_3,"certificate file");
  if (x509 == (X509 *)0x0) {
    ERR_print_errors(bio_err);
    return 0;
  }
  if (param_2_00 == (char *)0x0) {
    param_2_00 = "stdin";
  }
  __fprintf_chk(stdout,1,"%s: ",param_2_00);
  ctx = X509_STORE_CTX_new();
  if (ctx == (X509_STORE_CTX *)0x0) {
LAB_0804c710:
    ERR_print_errors(bio_err);
  }
  else {
    X509_STORE_set_flags(param_1_00,0);
    iVar1 = X509_STORE_CTX_init(ctx,param_1_00,x509,param_3_00);
    if (iVar1 == 0) goto LAB_0804c710;
    if (param_1 != (stack_st_X509 *)0x0) {
      X509_STORE_CTX_trusted_stack(ctx,param_1);
    }
    if (param_2 != (stack_st_X509_CRL *)0x0) {
      X509_STORE_CTX_set0_crls(ctx,param_2);
    }
    iVar1 = X509_verify_cert(ctx);
    X509_STORE_CTX_free(ctx);
    if (0 < iVar1) {
      uVar2 = 1;
      fwrite("OK\n",1,3,stdout);
      goto LAB_0804c6f7;
    }
  }
  uVar2 = 0;
  ERR_print_errors(bio_err);
LAB_0804c6f7:
  X509_free(x509);
  return uVar2;
}

