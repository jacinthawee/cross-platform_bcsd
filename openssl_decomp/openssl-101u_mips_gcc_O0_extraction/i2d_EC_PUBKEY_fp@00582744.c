
int i2d_EC_PUBKEY_fp(FILE *fp,EC_KEY *eckey)

{
  int iVar1;
  
                    /* WARNING: Could not recover jumptable at 0x00582758. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  iVar1 = (*(code *)PTR_ASN1_i2d_fp_006a8fbc)(PTR_i2d_EC_PUBKEY_006a8e80,fp,eckey);
  return iVar1;
}

