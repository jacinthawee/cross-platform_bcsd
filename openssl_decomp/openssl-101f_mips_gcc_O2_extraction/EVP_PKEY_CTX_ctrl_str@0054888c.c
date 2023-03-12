
int EVP_PKEY_CTX_ctrl_str(EVP_PKEY_CTX *ctx,char *type,char *value)

{
  int iVar1;
  EVP_MD *pEVar2;
  int reason;
  int iVar3;
  code *UNRECOVERED_JUMPTABLE;
  
  if (((ctx == (EVP_PKEY_CTX *)0x0) || (*(int *)ctx == 0)) ||
     (UNRECOVERED_JUMPTABLE = *(code **)(*(int *)ctx + 0x68), UNRECOVERED_JUMPTABLE == (code *)0x0))
  {
    ERR_put_error(6,0x96,0x93,"pmeth_lib.c",0x1a7);
    return -2;
  }
  iVar1 = (*(code *)PTR_strcmp_006aac20)(type,"digest");
  if (iVar1 != 0) {
                    /* WARNING: Could not recover jumptable at 0x005489ec. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    iVar1 = (*UNRECOVERED_JUMPTABLE)(ctx,type,value);
    return iVar1;
  }
  if ((value == (char *)0x0) || (pEVar2 = EVP_get_digestbyname(value), pEVar2 == (EVP_MD *)0x0)) {
    ERR_put_error(6,0x96,0x98,"pmeth_lib.c",0x1b0);
    return 0;
  }
  if ((*(int *)ctx == 0) ||
     (UNRECOVERED_JUMPTABLE = *(code **)(*(int *)ctx + 100), UNRECOVERED_JUMPTABLE == (code *)0x0))
  {
    iVar1 = 0x186;
LAB_00548a08:
    iVar3 = -2;
    ERR_put_error(6,0x89,0x93,"pmeth_lib.c",iVar1);
  }
  else {
    if (*(uint *)(ctx + 0x10) == 0) {
      reason = 0x95;
      iVar1 = 0x18e;
    }
    else {
      if ((*(uint *)(ctx + 0x10) & 0xf8) != 0) {
        iVar1 = (*UNRECOVERED_JUMPTABLE)(ctx,1,0,pEVar2);
        if (iVar1 != -2) {
          return iVar1;
        }
        iVar1 = 0x19b;
        goto LAB_00548a08;
      }
      reason = 0x94;
      iVar1 = 0x194;
    }
    iVar3 = -1;
    ERR_put_error(6,0x89,reason,"pmeth_lib.c",iVar1);
  }
  return iVar3;
}

