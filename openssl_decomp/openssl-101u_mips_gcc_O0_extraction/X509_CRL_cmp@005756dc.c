
int X509_CRL_cmp(X509_CRL *a,X509_CRL *b)

{
  int iVar1;
  X509_NAME *pXVar2;
  X509_NAME *pXVar3;
  
  pXVar2 = a->crl->issuer;
  pXVar3 = b->crl->issuer;
  if (((pXVar2->canon_enc == (uchar *)0x0) || (pXVar2->modified != 0)) &&
     (iVar1 = (*(code *)PTR_i2d_X509_NAME_006a76ec)(pXVar2,0), iVar1 < 0)) {
    iVar1 = -2;
  }
  else if (((pXVar3->canon_enc == (uchar *)0x0) || (pXVar3->modified != 0)) &&
          (iVar1 = (*(code *)PTR_i2d_X509_NAME_006a76ec)(pXVar3,0), iVar1 < 0)) {
    iVar1 = -2;
  }
  else {
    iVar1 = pXVar2->canon_enclen - pXVar3->canon_enclen;
    if (iVar1 == 0) {
                    /* WARNING: Could not recover jumptable at 0x00575760. Too many branches */
                    /* WARNING: Treating indirect jump as call */
      iVar1 = (*(code *)PTR_memcmp_006a9ad0)(pXVar2->canon_enc,pXVar3->canon_enc);
      return iVar1;
    }
  }
  return iVar1;
}

