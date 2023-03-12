
int i2d_PKCS8_fp(FILE *fp,X509_SIG *p8)

{
  int iVar1;
  
                    /* WARNING: Could not recover jumptable at 0x00582a04. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  iVar1 = (*(code *)PTR_ASN1_i2d_fp_006a8fbc)(PTR_i2d_X509_SIG_006a8734,fp,p8);
  return iVar1;
}

