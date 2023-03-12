
int EVP_PKEY_CTX_ctrl_str(EVP_PKEY_CTX *ctx,char *type,char *value)

{
  int iVar1;
  EVP_MD *pEVar2;
  code *UNRECOVERED_JUMPTABLE;
  
  if (((ctx == (EVP_PKEY_CTX *)0x0) || (*(int *)ctx == 0)) ||
     (UNRECOVERED_JUMPTABLE = *(code **)(*(int *)ctx + 0x68), UNRECOVERED_JUMPTABLE == (code *)0x0))
  {
    ERR_put_error(6,0x96,0x93,"pmeth_lib.c",0x1a7);
    iVar1 = -2;
  }
  else {
    iVar1 = strcmp(type,"digest");
    if (iVar1 != 0) {
                    /* WARNING: Could not recover jumptable at 0x000b151c. Too many branches */
                    /* WARNING: Treating indirect jump as call */
      iVar1 = (*UNRECOVERED_JUMPTABLE)(ctx,type,value);
      return iVar1;
    }
    if ((value == (char *)0x0) || (pEVar2 = EVP_get_digestbyname(value), pEVar2 == (EVP_MD *)0x0)) {
      ERR_put_error(6,0x96,0x98,"pmeth_lib.c",0x1b0);
      return 0;
    }
    if ((*(int *)ctx == 0) ||
       (UNRECOVERED_JUMPTABLE = *(code **)(*(int *)ctx + 100), UNRECOVERED_JUMPTABLE == (code *)0x0)
       ) {
      ERR_put_error(6,0x89,0x93,"pmeth_lib.c",0x186);
      iVar1 = -2;
    }
    else if (*(uint *)(ctx + 0x10) == 0) {
      ERR_put_error(6,0x89,0x95,"pmeth_lib.c",0x18e);
      iVar1 = -1;
    }
    else if ((*(uint *)(ctx + 0x10) & 0xf8) == 0) {
      ERR_put_error(6,0x89,0x94,"pmeth_lib.c",0x194);
      iVar1 = -1;
    }
    else {
      iVar1 = (*UNRECOVERED_JUMPTABLE)(ctx,1,0,pEVar2);
      if (iVar1 == -2) {
        ERR_put_error(6,0x89,0x93,"pmeth_lib.c",0x19b);
      }
    }
  }
  return iVar1;
}

