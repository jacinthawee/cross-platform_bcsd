
int cb(int param_1,X509_STORE_CTX *param_2)

{
  int n;
  X509 *a;
  X509_NAME *nm;
  char *pcVar1;
  int iVar2;
  X509_STORE_CTX *pXVar3;
  char *pcVar4;
  
  n = X509_STORE_CTX_get_error(param_2);
  a = X509_STORE_CTX_get_current_cert(param_2);
  if (param_1 == 0) {
    if (a != (X509 *)0x0) {
      nm = X509_get_subject_name(a);
      X509_NAME_print_ex_fp(stdout,nm,0,0x82031f);
      putchar(10);
    }
    pcVar1 = X509_verify_cert_error_string(n);
    iVar2 = X509_STORE_CTX_get_error_depth(param_2);
    pXVar3 = X509_STORE_CTX_get0_parent_ctx(param_2);
    pcVar4 = "[CRL path]";
    if (pXVar3 == (X509_STORE_CTX *)0x0) {
      pcVar4 = "";
    }
    __printf_chk(1,"%serror %d at %d depth lookup:%s\n",pcVar4,n,iVar2,pcVar1);
    switch(n) {
    case 10:
    case 0xb:
    case 0xc:
    case 0x12:
    case 0x18:
    case 0x19:
    case 0x1a:
    case 0x22:
    case 0x25:
      return 1;
    case 0x2b:
      policies_print(0,param_2);
      return 1;
    }
  }
  else {
    if ((n == 0) && (param_1 == 2)) {
      policies_print(0,param_2);
    }
    if (v_verbose == 0) {
      ERR_clear_error();
    }
  }
  return param_1;
}

