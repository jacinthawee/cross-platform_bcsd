
long bio_to_mem(void *param_1,int param_2,BIO *param_3)

{
  BIO_METHOD *type;
  BIO *b;
  int iVar1;
  int iVar2;
  long lVar3;
  int in_GS_OFFSET;
  undefined local_420 [1024];
  int local_20;
  
  local_20 = *(int *)(in_GS_OFFSET + 0x14);
  type = BIO_s_mem();
  b = BIO_new(type);
  if (b == (BIO *)0x0) {
    lVar3 = -1;
  }
  else {
    do {
      if ((param_2 == -1) || (iVar1 = param_2, 0x3ff < param_2)) {
        iVar1 = 0x400;
      }
      iVar1 = BIO_read(param_3,local_420,iVar1);
      if (iVar1 < 1) break;
      iVar2 = BIO_write(b,local_420,iVar1);
      if (iVar1 != iVar2) {
        BIO_free(b);
        lVar3 = -1;
        goto LAB_0807db32;
      }
      param_2 = param_2 - iVar1;
    } while (param_2 != 0);
    lVar3 = BIO_ctrl(b,3,0,param_1);
    BIO_set_flags(b,0x200);
    BIO_free(b);
  }
LAB_0807db32:
  if (local_20 == *(int *)(in_GS_OFFSET + 0x14)) {
    return lVar3;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}

