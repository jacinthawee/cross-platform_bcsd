
int i2d_RSAPublicKey_fp(FILE *fp,RSA *rsa)

{
  int iVar1;
  
                    /* WARNING: Could not recover jumptable at 0x00585310. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  iVar1 = (*(code *)PTR_ASN1_item_i2d_fp_006aa0b8)(PTR_RSAPublicKey_it_006aa0cc,fp,rsa);
  return iVar1;
}
