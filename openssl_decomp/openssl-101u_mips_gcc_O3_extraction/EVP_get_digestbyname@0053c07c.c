
EVP_MD * EVP_get_digestbyname(char *name)

{
  EVP_MD *pEVar1;
  
                    /* WARNING: Could not recover jumptable at 0x0053c088. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  pEVar1 = (EVP_MD *)(*(code *)PTR_OBJ_NAME_get_006a8a64)(name,1);
  return pEVar1;
}

