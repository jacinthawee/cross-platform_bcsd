
PKCS12 * d2i_PKCS12_fp(FILE *fp,PKCS12 **p12)

{
  PKCS12 *pPVar1;
  
                    /* WARNING: Could not recover jumptable at 0x005ad630. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  pPVar1 = (PKCS12 *)(*(code *)PTR_ASN1_item_d2i_fp_006aa0b0)(PTR_PKCS12_it_006aa350,fp,p12);
  return pPVar1;
}

