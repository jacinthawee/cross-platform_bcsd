
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int X509_PURPOSE_get_count(void)

{
  int iVar1;
  
  if (xptable != 0) {
    iVar1 = (*(code *)PTR_sk_num_006a7f2c)();
    return iVar1 + 9;
  }
  return 9;
}

