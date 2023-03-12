
int X509_NAME_cmp(X509_NAME *a,X509_NAME *b)

{
  int iVar1;
  
  if (((a->canon_enc == (uchar *)0x0) || (a->modified != 0)) &&
     (iVar1 = (*(code *)PTR_i2d_X509_NAME_006a76ec)(a,0), iVar1 < 0)) {
    iVar1 = -2;
  }
  else if (((b->canon_enc == (uchar *)0x0) || (b->modified != 0)) &&
          (iVar1 = (*(code *)PTR_i2d_X509_NAME_006a76ec)(b,0), iVar1 < 0)) {
    iVar1 = -2;
  }
  else {
    iVar1 = a->canon_enclen - b->canon_enclen;
    if (iVar1 == 0) {
                    /* WARNING: Could not recover jumptable at 0x00575d3c. Too many branches */
                    /* WARNING: Treating indirect jump as call */
      iVar1 = (*(code *)PTR_memcmp_006a9ad0)(a->canon_enc,b->canon_enc);
      return iVar1;
    }
  }
  return iVar1;
}

