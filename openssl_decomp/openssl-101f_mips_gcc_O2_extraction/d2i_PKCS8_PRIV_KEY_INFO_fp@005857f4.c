
PKCS8_PRIV_KEY_INFO * d2i_PKCS8_PRIV_KEY_INFO_fp(FILE *fp,PKCS8_PRIV_KEY_INFO **p8inf)

{
  PKCS8_PRIV_KEY_INFO *pPVar1;
  
                    /* WARNING: Could not recover jumptable at 0x0058580c. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  pPVar1 = (PKCS8_PRIV_KEY_INFO *)
           (*(code *)PTR_ASN1_d2i_fp_006aa0d0)
                     (PTR_PKCS8_PRIV_KEY_INFO_new_006a9d68,PTR_d2i_PKCS8_PRIV_KEY_INFO_006a9e60,fp,
                      p8inf);
  return pPVar1;
}

