
int EVP_PKEY_CTX_ctrl_str(EVP_PKEY_CTX *ctx,char *type,char *value)

{
  code *UNRECOVERED_JUMPTABLE;
  EVP_MD *pEVar1;
  int iVar2;
  byte *pbVar3;
  bool bVar4;
  bool bVar5;
  int line;
  
  if ((ctx != (EVP_PKEY_CTX *)0x0) && (*(int *)ctx != 0)) {
    UNRECOVERED_JUMPTABLE = *(code **)(*(int *)ctx + 0x68);
    bVar4 = false;
    bVar5 = UNRECOVERED_JUMPTABLE == (code *)0x0;
    if (!bVar5) {
      iVar2 = 7;
      pbVar3 = (byte *)0x8238fde;
      do {
        if (iVar2 == 0) break;
        iVar2 = iVar2 + -1;
        bVar4 = (byte)*type < *pbVar3;
        bVar5 = *type == *pbVar3;
        type = (char *)((byte *)type + 1);
        pbVar3 = pbVar3 + 1;
      } while (bVar5);
      if ((!bVar4 && !bVar5) != bVar4) {
                    /* WARNING: Could not recover jumptable at 0x08133c2f. Too many branches */
                    /* WARNING: Treating indirect jump as call */
        iVar2 = (*UNRECOVERED_JUMPTABLE)();
        return iVar2;
      }
      if ((value != (char *)0x0) && (pEVar1 = EVP_get_digestbyname(value), pEVar1 != (EVP_MD *)0x0))
      {
        if ((*(int *)ctx != 0) &&
           (UNRECOVERED_JUMPTABLE = *(code **)(*(int *)ctx + 100),
           UNRECOVERED_JUMPTABLE != (code *)0x0)) {
          if (*(uint *)(ctx + 0x10) == 0) {
            line = 0x185;
            iVar2 = 0x95;
          }
          else {
            if ((*(uint *)(ctx + 0x10) & 0xf8) != 0) {
              iVar2 = (*UNRECOVERED_JUMPTABLE)(ctx,1,0,pEVar1);
              if (iVar2 != -2) {
                return iVar2;
              }
              ERR_put_error(6,0x89,0x93,"pmeth_lib.c",0x191);
              return -2;
            }
            line = 0x18a;
            iVar2 = 0x94;
          }
          ERR_put_error(6,0x89,iVar2,"pmeth_lib.c",line);
          return -1;
        }
        ERR_put_error(6,0x89,0x93,"pmeth_lib.c",0x17e);
        return -2;
      }
      ERR_put_error(6,0x96,0x98,"pmeth_lib.c",0x1a1);
      return 0;
    }
  }
  ERR_put_error(6,0x96,0x93,"pmeth_lib.c",0x19b);
  return -2;
}

