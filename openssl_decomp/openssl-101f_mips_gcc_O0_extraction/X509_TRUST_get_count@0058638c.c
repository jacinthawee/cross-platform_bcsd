
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int X509_TRUST_get_count(void)

{
  int iVar1;
  
  if (trtable != 0) {
    iVar1 = (*(code *)PTR_sk_num_006a7f2c)();
    return iVar1 + 8;
  }
  return 8;
}

