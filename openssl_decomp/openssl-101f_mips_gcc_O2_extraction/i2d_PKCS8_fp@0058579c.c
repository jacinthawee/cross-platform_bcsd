
int i2d_PKCS8_fp(FILE *fp,X509_SIG *p8)

{
  int iVar1;
  
                    /* WARNING: Could not recover jumptable at 0x005857b0. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  iVar1 = (*(code *)PTR_ASN1_i2d_fp_006aa0d4)(PTR_i2d_X509_SIG_006a9858,fp,p8);
  return iVar1;
}

