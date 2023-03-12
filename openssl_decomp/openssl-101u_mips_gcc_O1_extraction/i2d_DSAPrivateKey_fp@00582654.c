
int i2d_DSAPrivateKey_fp(FILE *fp,DSA *dsa)

{
  int iVar1;
  
                    /* WARNING: Could not recover jumptable at 0x00582668. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  iVar1 = (*(code *)PTR_ASN1_i2d_fp_006a8fbc)(PTR_i2d_DSAPrivateKey_006a8e6c,fp,dsa);
  return iVar1;
}

