
int X509v3_get_ext_count(stack_st_X509_EXTENSION *x)

{
  int iVar1;
  
  if (x != (stack_st_X509_EXTENSION *)0x0) {
                    /* WARNING: Could not recover jumptable at 0x00580a30. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    iVar1 = (*(code *)PTR_sk_num_006a7f2c)();
    return iVar1;
  }
  return 0;
}

