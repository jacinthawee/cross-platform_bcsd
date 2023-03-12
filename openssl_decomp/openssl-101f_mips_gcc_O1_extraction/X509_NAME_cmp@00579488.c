
int X509_NAME_cmp(X509_NAME *a,X509_NAME *b)

{
  int iVar1;
  
  if (((a->canon_enc == (uchar *)0x0) || (a->modified != 0)) &&
     (iVar1 = (*(code *)PTR_i2d_X509_NAME_006a87d8)(a,0), iVar1 < 0)) {
    iVar1 = -2;
  }
  else if (((b->canon_enc == (uchar *)0x0) || (b->modified != 0)) &&
          (iVar1 = (*(code *)PTR_i2d_X509_NAME_006a87d8)(b,0), iVar1 < 0)) {
    iVar1 = -2;
  }
  else {
    iVar1 = a->canon_enclen - b->canon_enclen;
    if (iVar1 == 0) {
                    /* WARNING: Could not recover jumptable at 0x00579500. Too many branches */
                    /* WARNING: Treating indirect jump as call */
      iVar1 = (*(code *)PTR_memcmp_006aabd8)(a->canon_enc,b->canon_enc);
      return iVar1;
    }
  }
  return iVar1;
}

