
int i2d_RSAPrivateKey_fp(FILE *fp,RSA *rsa)

{
  int iVar1;
  
                    /* WARNING: Could not recover jumptable at 0x0058250c. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  iVar1 = (*(code *)PTR_ASN1_item_i2d_fp_006a8fa0)(PTR_RSAPrivateKey_it_006a8fb0,fp,rsa);
  return iVar1;
}

