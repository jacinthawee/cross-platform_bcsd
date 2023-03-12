
int EVP_PKEY_CTX_ctrl(EVP_PKEY_CTX *ctx,int keytype,int optype,int cmd,int p1,void *p2)

{
  int *piVar1;
  int iVar2;
  int line;
  
  if (((ctx == (EVP_PKEY_CTX *)0x0) || (piVar1 = *(int **)ctx, piVar1 == (int *)0x0)) ||
     ((code *)piVar1[0x19] == (code *)0x0)) {
    ERR_put_error(6,0x89,0x93,"pmeth_lib.c",0x186);
    iVar2 = -2;
  }
  else if ((keytype == -1) || (keytype == *piVar1)) {
    if (*(uint *)(ctx + 0x10) == 0) {
      line = 0x18e;
      iVar2 = 0x95;
    }
    else {
      if ((optype == -1) || ((*(uint *)(ctx + 0x10) & optype) != 0)) {
        iVar2 = (*(code *)piVar1[0x19])(ctx,cmd,p1,p2);
        if (iVar2 != -2) {
          return iVar2;
        }
        ERR_put_error(6,0x89,0x93,"pmeth_lib.c",0x19b);
        return -2;
      }
      line = 0x194;
      iVar2 = 0x94;
    }
    ERR_put_error(6,0x89,iVar2,"pmeth_lib.c",line);
    iVar2 = -1;
  }
  else {
    iVar2 = -1;
  }
  return iVar2;
}

