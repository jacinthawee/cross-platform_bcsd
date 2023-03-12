
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int EVP_PKEY_asn1_get_count(void)

{
  int iVar1;
  
  if (app_methods != 0) {
    iVar1 = (*(code *)PTR_sk_num_006a6e2c)();
    return iVar1 + 0xb;
  }
  return 0xb;
}

