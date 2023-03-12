
EVP_MD * EVP_get_digestbyname(char *name)

{
  EVP_MD *pEVar1;
  
                    /* WARNING: Could not recover jumptable at 0x0053f2c8. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  pEVar1 = (EVP_MD *)(*(code *)PTR_OBJ_NAME_get_006a9b80)(name,1);
  return pEVar1;
}

