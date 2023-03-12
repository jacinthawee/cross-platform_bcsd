
int X509_TRUST_add(int id,int flags,ck *ck,char *name,int arg1,void *arg2)

{
  _STACK *p_Var1;
  int iVar2;
  int *data;
  uint uVar3;
  int local_38 [7];
  
  uVar3 = id - 1;
  if (uVar3 < 8) {
LAB_000ccdd6:
    if ((int)uVar3 < 8) {
      data = (int *)(PTR_trstandard_000ccefc + uVar3 * 0x18);
    }
    else {
      data = (int *)sk_value(trtable,uVar3 - 8);
    }
LAB_000ccde4:
    if (data[1] << 0x1e < 0) {
      CRYPTO_free((void *)data[3]);
    }
  }
  else {
    local_38[0] = id;
    if (((trtable != (_STACK *)0x0) && (iVar2 = sk_find(trtable,local_38), iVar2 != -1)) &&
       (uVar3 = iVar2 + 8, iVar2 != -9)) {
      if (-1 < (int)uVar3) goto LAB_000ccdd6;
      data = (int *)0x0;
      goto LAB_000ccde4;
    }
    data = (int *)CRYPTO_malloc(0x18,"x509_trs.c",0xb9);
    if (data == (int *)0x0) {
      ERR_put_error(0xb,0x85,0x41,"x509_trs.c",0xba);
      return 0;
    }
    uVar3 = 0xffffffff;
    data[1] = 1;
  }
  p_Var1 = (_STACK *)BUF_strdup(name);
  iVar2 = 0xc6;
  data[3] = (int)p_Var1;
  if (p_Var1 == (_STACK *)0x0) {
LAB_000cce62:
    ERR_put_error(0xb,0x85,0x41,"x509_trs.c",iVar2);
    return (int)p_Var1;
  }
  *data = id;
  data[4] = arg1;
  data[2] = (int)ck;
  data[1] = data[1] & 1U | 2 | flags & 0xfffffffeU;
  data[5] = (int)arg2;
  if (uVar3 == 0xffffffff) {
    if (trtable == (_STACK *)0x0) {
      p_Var1 = sk_new(tr_cmp + 1);
      iVar2 = 0xd6;
      trtable = p_Var1;
      if (p_Var1 == (_STACK *)0x0) goto LAB_000cce62;
    }
    p_Var1 = (_STACK *)sk_push(trtable,data);
    if (p_Var1 == (_STACK *)0x0) {
      iVar2 = 0xda;
      goto LAB_000cce62;
    }
  }
  return 1;
}

