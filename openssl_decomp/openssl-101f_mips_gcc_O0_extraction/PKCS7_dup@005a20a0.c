
PKCS7 * PKCS7_dup(PKCS7 *p7)

{
  PKCS7 *pPVar1;
  
                    /* WARNING: Could not recover jumptable at 0x005a20b4. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  pPVar1 = (PKCS7 *)(*(code *)PTR_ASN1_item_dup_006a9860)(PKCS7_it,p7);
  return pPVar1;
}

