
PKCS7 * d2i_PKCS7_fp(FILE *fp,PKCS7 **p7)

{
  PKCS7 *pPVar1;
  
                    /* WARNING: Could not recover jumptable at 0x00582410. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  pPVar1 = (PKCS7 *)(*(code *)PTR_ASN1_item_d2i_fp_006a8f98)(PTR_PKCS7_it_006a8fa8,fp,p7);
  return pPVar1;
}

