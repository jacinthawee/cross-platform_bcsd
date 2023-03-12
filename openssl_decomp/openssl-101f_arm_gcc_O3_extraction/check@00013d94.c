
undefined4
check(X509_STORE *param_1,char *param_2,stack_st_X509 *param_3,stack_st_X509 *param_4,
     stack_st_X509_CRL *param_5,undefined4 param_6)

{
  X509 *x509;
  X509_STORE_CTX *ctx;
  int iVar1;
  char *pcVar2;
  undefined4 uVar3;
  
  x509 = (X509 *)load_cert(bio_err,param_2,3,0,param_6,"certificate file");
  if (x509 != (X509 *)0x0) {
    pcVar2 = "stdin";
    if (param_2 != (char *)0x0) {
      pcVar2 = param_2;
    }
    __fprintf_chk(stdout,1,&DAT_00125478,pcVar2);
    ctx = X509_STORE_CTX_new();
    if (ctx != (X509_STORE_CTX *)0x0) {
      X509_STORE_set_flags(param_1,0);
      iVar1 = X509_STORE_CTX_init(ctx,param_1,x509,param_3);
      if (iVar1 != 0) {
        if (param_4 != (stack_st_X509 *)0x0) {
          X509_STORE_CTX_trusted_stack(ctx,param_4);
        }
        if (param_5 != (stack_st_X509_CRL *)0x0) {
          X509_STORE_CTX_set0_crls(ctx,param_5);
        }
        iVar1 = X509_verify_cert(ctx);
        X509_STORE_CTX_free(ctx);
        if (iVar1 < 1) {
          uVar3 = 0;
          ERR_print_errors(bio_err);
        }
        else {
          uVar3 = 1;
          fwrite("OK\n",1,3,stdout);
        }
        goto LAB_00013e52;
      }
    }
    ERR_print_errors(bio_err);
  }
  ERR_print_errors(bio_err);
  if (x509 == (X509 *)0x0) {
    return 0;
  }
  uVar3 = 0;
LAB_00013e52:
  X509_free(x509);
  return uVar3;
}

