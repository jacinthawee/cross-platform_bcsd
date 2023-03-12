
EVP_CIPHER * EVP_get_cipherbyname(char *name)

{
  EVP_CIPHER *pEVar1;
  
                    /* WARNING: Could not recover jumptable at 0x0053f2b4. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  pEVar1 = (EVP_CIPHER *)(*(code *)PTR_OBJ_NAME_get_006a9b80)(name,2);
  return pEVar1;
}

