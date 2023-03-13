
int i2d_RSA_PUBKEY_fp(FILE *fp,RSA *rsa)

{
  int iVar1;
  
                    /* WARNING: Could not recover jumptable at 0x00582580. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  iVar1 = (*(code *)PTR_ASN1_i2d_fp_006a8fbc)(PTR_i2d_RSA_PUBKEY_006a8e68,fp,rsa);
  return iVar1;
}

