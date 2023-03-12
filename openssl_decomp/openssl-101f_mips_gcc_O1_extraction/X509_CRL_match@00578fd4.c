
int X509_CRL_match(X509_CRL *a,X509_CRL *b)

{
  int iVar1;
  
                    /* WARNING: Could not recover jumptable at 0x00578fe8. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  iVar1 = (*(code *)PTR_memcmp_006aabd8)(a->sha1_hash,b->sha1_hash,0x14);
  return iVar1;
}

