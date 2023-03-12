
GENERAL_NAME * GENERAL_NAME_dup(GENERAL_NAME *a)

{
  GENERAL_NAME *pGVar1;
  
                    /* WARNING: Could not recover jumptable at 0x0058f06c. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  pGVar1 = (GENERAL_NAME *)(*(code *)PTR_ASN1_dup_006aa144)(i2d_GENERAL_NAME,d2i_GENERAL_NAME,a);
  return pGVar1;
}

