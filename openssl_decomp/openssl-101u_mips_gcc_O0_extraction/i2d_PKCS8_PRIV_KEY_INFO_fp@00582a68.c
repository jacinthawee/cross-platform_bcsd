
int i2d_PKCS8_PRIV_KEY_INFO_fp(FILE *fp,PKCS8_PRIV_KEY_INFO *p8inf)

{
  int iVar1;
  
                    /* WARNING: Could not recover jumptable at 0x00582a7c. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  iVar1 = (*(code *)PTR_ASN1_i2d_fp_006a8fbc)(PTR_i2d_PKCS8_PRIV_KEY_INFO_006a8ea4,fp,p8inf);
  return iVar1;
}

