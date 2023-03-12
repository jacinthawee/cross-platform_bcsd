
int X509_PURPOSE_add(int id,int trust,int flags,ck *ck,char *name,char *sname,void *arg)

{
  char *pcVar1;
  int iVar2;
  int *data;
  uint uVar3;
  int local_3c [8];
  
  uVar3 = id - 1;
  if (uVar3 < 9) {
LAB_000d4e02:
    if ((int)uVar3 < 9) {
      data = (int *)(&xstandard + uVar3 * 0x1c);
    }
    else {
      data = (int *)sk_value(xptable,uVar3 - 9);
    }
LAB_000d4e16:
    if (data[2] << 0x1e < 0) {
      CRYPTO_free((void *)data[4]);
      CRYPTO_free((void *)data[5]);
    }
  }
  else {
    local_3c[0] = id;
    if (((xptable != (_STACK *)0x0) && (iVar2 = sk_find(xptable,local_3c), iVar2 != -1)) &&
       (uVar3 = iVar2 + 9, iVar2 != -10)) {
      if (-1 < (int)uVar3) goto LAB_000d4e02;
      data = (int *)0x0;
      goto LAB_000d4e16;
    }
    data = (int *)CRYPTO_malloc(0x1c,"v3_purp.c",0xd6);
    iVar2 = 0xd7;
    if (data == (int *)0x0) goto LAB_000d4ea4;
    uVar3 = 0xffffffff;
    data[2] = 1;
  }
  pcVar1 = BUF_strdup(name);
  data[4] = (int)pcVar1;
  pcVar1 = BUF_strdup(sname);
  data[5] = (int)pcVar1;
  if ((data[4] != 0) && (pcVar1 != (char *)0x0)) {
    *data = id;
    data[1] = trust;
    data[3] = (int)ck;
    data[6] = (int)arg;
    data[2] = flags & 0xfffffffeU | data[2] & 1U | 2;
    if (uVar3 == 0xffffffff) {
      if (xptable == (_STACK *)0x0) {
        xptable = sk_new(xp_cmp + 1);
        iVar2 = 0xf7;
        if (xptable == (_STACK *)0x0) goto LAB_000d4f08;
      }
      data = (int *)sk_push(xptable,data);
      if (data == (int *)0x0) {
        iVar2 = 0xfb;
LAB_000d4ea4:
        ERR_put_error(0x22,0x89,0x41,"v3_purp.c",iVar2);
        return (int)data;
      }
    }
    return 1;
  }
  iVar2 = 0xe7;
LAB_000d4f08:
  ERR_put_error(0x22,0x89,0x41,"v3_purp.c",iVar2);
  return 0;
}

