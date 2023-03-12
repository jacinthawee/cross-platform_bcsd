
int EVP_PKEY_CTX_ctrl(EVP_PKEY_CTX *ctx,int keytype,int optype,int cmd,int p1,void *p2)

{
  int iVar1;
  int *piVar2;
  
  if (((ctx == (EVP_PKEY_CTX *)0x0) || (piVar2 = *(int **)ctx, piVar2 == (int *)0x0)) ||
     ((code *)piVar2[0x19] == (code *)0x0)) {
    ERR_put_error(6,0x89,0x93,"pmeth_lib.c",0x17e);
    iVar1 = -2;
  }
  else if ((keytype == -1) || (*piVar2 == keytype)) {
    if (*(uint *)(ctx + 0x10) == 0) {
      ERR_put_error(6,0x89,0x95,"pmeth_lib.c",0x185);
      iVar1 = -1;
    }
    else if ((optype == -1) || ((optype & *(uint *)(ctx + 0x10)) != 0)) {
      iVar1 = (*(code *)piVar2[0x19])(ctx,cmd,p1,p2);
      if (iVar1 == -2) {
        ERR_put_error(6,0x89,0x93,"pmeth_lib.c",0x191);
        return -2;
      }
    }
    else {
      ERR_put_error(6,0x89,0x94,"pmeth_lib.c",0x18a);
      iVar1 = -1;
    }
  }
  else {
    iVar1 = -1;
  }
  return iVar1;
}

