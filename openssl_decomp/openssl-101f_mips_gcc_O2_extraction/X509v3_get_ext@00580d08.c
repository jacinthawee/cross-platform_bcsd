
X509_EXTENSION * X509v3_get_ext(stack_st_X509_EXTENSION *x,int loc)

{
  int iVar1;
  X509_EXTENSION *pXVar2;
  
  if (x == (stack_st_X509_EXTENSION *)0x0) {
    return (X509_EXTENSION *)0x0;
  }
  iVar1 = (*(code *)PTR_sk_num_006a7f2c)();
  if ((loc < iVar1) && (-1 < loc)) {
                    /* WARNING: Could not recover jumptable at 0x00580d60. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    pXVar2 = (X509_EXTENSION *)(*(code *)PTR_sk_value_006a7f24)(x,loc);
    return pXVar2;
  }
  return (X509_EXTENSION *)0x0;
}

