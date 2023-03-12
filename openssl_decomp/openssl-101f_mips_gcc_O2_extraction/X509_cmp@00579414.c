
int X509_cmp(X509 *a,X509 *b)

{
  int iVar1;
  
  X509_check_purpose(a,-1,0);
  X509_check_purpose(b,-1,0);
                    /* WARNING: Could not recover jumptable at 0x00579480. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  iVar1 = (*(code *)PTR_memcmp_006aabd8)(&a->rfc3779_addr,&b->rfc3779_addr,0x14);
  return iVar1;
}

