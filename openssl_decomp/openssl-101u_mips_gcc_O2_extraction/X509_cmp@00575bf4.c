
int X509_cmp(X509 *a,X509 *b)

{
  int iVar1;
  X509_CINF *pXVar2;
  X509_CINF *pXVar3;
  
  X509_check_purpose(a,-1,0);
  X509_check_purpose(b,-1,0);
  iVar1 = (*(code *)PTR_memcmp_006a9ad0)(&a->rfc3779_addr,&b->rfc3779_addr,0x14);
  if (iVar1 == 0) {
    pXVar2 = a->cert_info;
    iVar1 = (pXVar2->enc).modified;
    if (iVar1 == 0) {
      pXVar3 = b->cert_info;
      if (((pXVar3->enc).modified == 0) &&
         (iVar1 = (pXVar2->enc).len - (pXVar3->enc).len, iVar1 == 0)) {
                    /* WARNING: Could not recover jumptable at 0x00575ca4. Too many branches */
                    /* WARNING: Treating indirect jump as call */
        iVar1 = (*(code *)PTR_memcmp_006a9ad0)((pXVar2->enc).enc,(pXVar3->enc).enc);
        return iVar1;
      }
    }
    else {
      iVar1 = 0;
    }
  }
  return iVar1;
}

