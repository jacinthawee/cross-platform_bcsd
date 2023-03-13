
int X509_PURPOSE_add(int id,int trust,int flags,ck *ck,char *name,char *sname,void *arg)

{
  char *pcVar1;
  int iVar2;
  int *data;
  uint uVar3;
  int in_GS_OFFSET;
  int local_3c [7];
  int local_20;
  
  local_20 = *(int *)(in_GS_OFFSET + 0x14);
  uVar3 = id - 1;
  if (uVar3 < 9) {
LAB_081729b4:
    if ((int)uVar3 < 9) {
      data = (int *)(xstandard + uVar3 * 0x1c);
    }
    else {
      data = (int *)sk_value(xptable,uVar3 - 9);
    }
    if ((*(byte *)(data + 2) & 2) != 0) {
      CRYPTO_free((void *)data[4]);
      CRYPTO_free((void *)data[5]);
    }
LAB_081729eb:
    pcVar1 = BUF_strdup(name);
    data[4] = (int)pcVar1;
    pcVar1 = BUF_strdup(sname);
    data[5] = (int)pcVar1;
    if ((data[4] != 0) && (pcVar1 != (char *)0x0)) {
      data[3] = (int)ck;
      data[2] = data[2] & 1U | 2 | flags & 0xfffffffeU;
      *data = id;
      data[1] = trust;
      data[6] = (int)arg;
      if (uVar3 == 0xffffffff) {
        if ((xptable == (_STACK *)0x0) && (xptable = sk_new(xp_cmp), xptable == (_STACK *)0x0)) {
          iVar2 = 0xf7;
          goto LAB_08172b68;
        }
        iVar2 = sk_push(xptable,data);
        if (iVar2 == 0) {
          ERR_put_error(0x22,0x89,0x41,"v3_purp.c",0xfb);
          goto LAB_08172a49;
        }
      }
      iVar2 = 1;
      goto LAB_08172a49;
    }
    iVar2 = 0xe7;
  }
  else {
    local_3c[0] = id;
    if (((xptable != (_STACK *)0x0) && (iVar2 = sk_find(xptable,local_3c), iVar2 != -1)) &&
       (uVar3 = iVar2 + 9, uVar3 != 0xffffffff)) {
      if ((int)uVar3 < 0) {
        do {
          invalidInstructionException();
        } while( true );
      }
      goto LAB_081729b4;
    }
    data = (int *)CRYPTO_malloc(0x1c,"v3_purp.c",0xd6);
    if (data != (int *)0x0) {
      data[2] = 1;
      uVar3 = 0xffffffff;
      goto LAB_081729eb;
    }
    iVar2 = 0xd7;
  }
LAB_08172b68:
  ERR_put_error(0x22,0x89,0x41,"v3_purp.c",iVar2);
  iVar2 = 0;
LAB_08172a49:
  if (local_20 != *(int *)(in_GS_OFFSET + 0x14)) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return iVar2;
}

