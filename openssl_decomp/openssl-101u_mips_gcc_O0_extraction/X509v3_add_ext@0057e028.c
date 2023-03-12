
stack_st_X509_EXTENSION * X509v3_add_ext(stack_st_X509_EXTENSION **x,X509_EXTENSION *ex,int loc)

{
  int iVar1;
  X509_EXTENSION *a;
  undefined4 uVar2;
  undefined4 uVar3;
  stack_st_X509_EXTENSION *psVar4;
  
  if (x == (stack_st_X509_EXTENSION **)0x0) {
    uVar3 = 0x43;
    uVar2 = 0x98;
  }
  else {
    psVar4 = *x;
    if ((psVar4 != (stack_st_X509_EXTENSION *)0x0) ||
       (psVar4 = (stack_st_X509_EXTENSION *)(*(code *)PTR_sk_new_null_006a6fa4)(),
       psVar4 != (stack_st_X509_EXTENSION *)0x0)) {
      iVar1 = (*(code *)PTR_sk_num_006a6e2c)(psVar4);
      if ((loc <= iVar1) && (-1 < loc)) {
        iVar1 = loc;
      }
      a = X509_EXTENSION_dup(ex);
      if (a != (X509_EXTENSION *)0x0) {
        iVar1 = (*(code *)PTR_sk_insert_006a87bc)(psVar4,a,iVar1);
        if (iVar1 != 0) {
          if (*x == (stack_st_X509_EXTENSION *)0x0) {
            *x = psVar4;
            return psVar4;
          }
          return psVar4;
        }
        (*(code *)PTR_ERR_put_error_006a7f34)(0xb,0x68,0x41,"x509_v3.c",0xb0);
        X509_EXTENSION_free(a);
      }
      (*(code *)PTR_sk_free_006a6e80)(psVar4);
      return (stack_st_X509_EXTENSION *)0x0;
    }
    uVar3 = 0x41;
    uVar2 = 0xb0;
  }
  (*(code *)PTR_ERR_put_error_006a7f34)(0xb,0x68,uVar3,"x509_v3.c",uVar2);
  return (stack_st_X509_EXTENSION *)0x0;
}

