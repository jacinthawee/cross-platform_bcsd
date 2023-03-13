
void * PEM_ASN1_read_bio(undefined1 *d2i,char *name,BIO *bp,void **x,undefined1 *cb,void *u)

{
  int iVar1;
  void *pvVar2;
  int in_GS_OFFSET;
  uchar *local_1c;
  uchar *local_18;
  long local_14;
  int local_10;
  
  local_10 = *(int *)(in_GS_OFFSET + 0x14);
  local_1c = (uchar *)0x0;
  local_18 = (uchar *)0x0;
  iVar1 = PEM_bytes_read_bio(&local_18,&local_14,(char **)0x0,name,bp,cb,u);
  pvVar2 = (void *)0x0;
  if (iVar1 != 0) {
    local_1c = local_18;
    pvVar2 = (void *)(*(code *)d2i)(x,&local_1c,local_14);
    if (pvVar2 == (void *)0x0) {
      ERR_put_error(9,0x67,0xd,"pem_oth.c",0x53);
    }
    CRYPTO_free(local_18);
  }
  if (local_10 == *(int *)(in_GS_OFFSET + 0x14)) {
    return pvVar2;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}

