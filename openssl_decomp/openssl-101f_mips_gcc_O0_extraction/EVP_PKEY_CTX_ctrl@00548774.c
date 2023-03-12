
int EVP_PKEY_CTX_ctrl(EVP_PKEY_CTX *ctx,int keytype,int optype,int cmd,int p1,void *p2)

{
  int iVar1;
  int *piVar2;
  int reason;
  
  if (((ctx != (EVP_PKEY_CTX *)0x0) && (piVar2 = *(int **)ctx, piVar2 != (int *)0x0)) &&
     ((code *)piVar2[0x19] != (code *)0x0)) {
    if ((keytype == -1) || (keytype == *piVar2)) {
      if (*(uint *)(ctx + 0x10) == 0) {
        reason = 0x95;
        iVar1 = 0x18e;
      }
      else {
        if ((optype == -1) || ((*(uint *)(ctx + 0x10) & optype) != 0)) {
          iVar1 = (*(code *)piVar2[0x19])(ctx,cmd,p1,p2);
          if (iVar1 != -2) {
            return iVar1;
          }
          iVar1 = 0x19b;
          goto LAB_00548814;
        }
        reason = 0x94;
        iVar1 = 0x194;
      }
      ERR_put_error(6,0x89,reason,"pmeth_lib.c",iVar1);
    }
    return -1;
  }
  iVar1 = 0x186;
LAB_00548814:
  ERR_put_error(6,0x89,0x93,"pmeth_lib.c",iVar1);
  return -2;
}

