
int i2d_PrivateKey_fp(FILE *fp,EVP_PKEY *pkey)

{
  int iVar1;
  
                    /* WARNING: Could not recover jumptable at 0x00582b28. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  iVar1 = (*(code *)PTR_ASN1_i2d_fp_006a8fbc)(PTR_i2d_PrivateKey_006a8eb0,fp,pkey);
  return iVar1;
}

