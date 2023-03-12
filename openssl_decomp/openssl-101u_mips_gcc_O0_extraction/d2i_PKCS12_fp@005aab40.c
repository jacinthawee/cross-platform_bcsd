
PKCS12 * d2i_PKCS12_fp(FILE *fp,PKCS12 **p12)

{
  PKCS12 *pPVar1;
  
                    /* WARNING: Could not recover jumptable at 0x005aab54. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  pPVar1 = (PKCS12 *)(*(code *)PTR_ASN1_item_d2i_fp_006a8f98)(PTR_PKCS12_it_006a9244,fp,p12);
  return pPVar1;
}

