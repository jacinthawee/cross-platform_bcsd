
int X509_TRUST_add(int id,int flags,ck *ck,char *name,int arg1,void *arg2)

{
  char *pcVar1;
  int iVar2;
  int *data;
  uint uVar3;
  int in_GS_OFFSET;
  int local_38 [6];
  int local_20;
  
  local_20 = *(int *)(in_GS_OFFSET + 0x14);
  uVar3 = id - 1;
  if (uVar3 < 8) {
LAB_08167800:
    if ((int)uVar3 < 8) {
      data = (int *)(trstandard + uVar3 * 0x18);
    }
    else {
      data = (int *)sk_value(trtable,uVar3 - 8);
    }
    if ((*(byte *)(data + 1) & 2) != 0) {
      CRYPTO_free((void *)data[3]);
    }
LAB_08167827:
    pcVar1 = BUF_strdup(name);
    data[3] = (int)pcVar1;
    if (pcVar1 != (char *)0x0) {
      data[2] = (int)ck;
      data[1] = flags & 0xfffffffeU | data[1] & 1U | 2;
      *data = id;
      data[4] = arg1;
      data[5] = (int)arg2;
      if (uVar3 == 0xffffffff) {
        if ((trtable == (_STACK *)0x0) && (trtable = sk_new(tr_cmp), trtable == (_STACK *)0x0)) {
          iVar2 = 199;
          goto LAB_08167998;
        }
        iVar2 = sk_push(trtable,data);
        if (iVar2 == 0) {
          ERR_put_error(0xb,0x85,0x41,"x509_trs.c",0xcb);
          goto LAB_08167871;
        }
      }
      iVar2 = 1;
      goto LAB_08167871;
    }
    iVar2 = 0xb7;
  }
  else {
    local_38[0] = id;
    if (((trtable != (_STACK *)0x0) && (iVar2 = sk_find(trtable,local_38), iVar2 != -1)) &&
       (uVar3 = iVar2 + 8, uVar3 != 0xffffffff)) {
      if ((int)uVar3 < 0) {
        do {
          invalidInstructionException();
        } while( true );
      }
      goto LAB_08167800;
    }
    data = (int *)CRYPTO_malloc(0x18,"x509_trs.c",0xac);
    if (data != (int *)0x0) {
      data[1] = 1;
      uVar3 = 0xffffffff;
      goto LAB_08167827;
    }
    iVar2 = 0xad;
  }
LAB_08167998:
  ERR_put_error(0xb,0x85,0x41,"x509_trs.c",iVar2);
  iVar2 = 0;
LAB_08167871:
  if (local_20 != *(int *)(in_GS_OFFSET + 0x14)) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return iVar2;
}

