
void * ASN1_dup(undefined1 *i2d,undefined1 *d2i,void *x)

{
  int iVar1;
  void *ptr;
  undefined4 uVar2;
  void *pvVar3;
  int in_GS_OFFSET;
  void *local_28;
  void *local_24;
  int local_20;
  
  local_20 = *(int *)(in_GS_OFFSET + 0x14);
  if (x == (void *)0x0) {
    pvVar3 = (void *)0x0;
  }
  else {
    iVar1 = (*(code *)i2d)(x,0);
    ptr = CRYPTO_malloc(iVar1 + 10,"a_dup.c",0x4c);
    if (ptr == (void *)0x0) {
      ERR_put_error(0xd,0x6f,0x41,"a_dup.c",0x4e);
      pvVar3 = (void *)0x0;
    }
    else {
      local_28 = ptr;
      uVar2 = (*(code *)i2d)(x,&local_28);
      local_24 = ptr;
      pvVar3 = (void *)(*(code *)d2i)(0,&local_24,uVar2);
      CRYPTO_free(ptr);
    }
  }
  if (local_20 == *(int *)(in_GS_OFFSET + 0x14)) {
    return pvVar3;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}

