
int i2d_PUBKEY_fp(FILE *fp,EVP_PKEY *pkey)

{
  int iVar1;
  
                    /* WARNING: Could not recover jumptable at 0x00585910. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  iVar1 = (*(code *)PTR_ASN1_i2d_fp_006aa0d4)(PTR_i2d_PUBKEY_006a9fa4,fp,pkey);
  return iVar1;
}

