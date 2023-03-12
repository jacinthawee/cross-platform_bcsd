
X509_EXTENSION * X509v3_delete_ext(stack_st_X509_EXTENSION *x,int loc)

{
  int iVar1;
  X509_EXTENSION *pXVar2;
  
  if (x == (stack_st_X509_EXTENSION *)0x0) {
    return (X509_EXTENSION *)0x0;
  }
  iVar1 = (*(code *)PTR_sk_num_006a6e2c)();
  if ((loc < iVar1) && (-1 < loc)) {
                    /* WARNING: Could not recover jumptable at 0x0057e000. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    pXVar2 = (X509_EXTENSION *)(*(code *)PTR_sk_delete_006a7288)(x,loc);
    return pXVar2;
  }
  return (X509_EXTENSION *)0x0;
}

