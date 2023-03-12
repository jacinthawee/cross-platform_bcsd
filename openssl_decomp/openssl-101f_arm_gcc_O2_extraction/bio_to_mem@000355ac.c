
void bio_to_mem(void *param_1,int param_2,BIO *param_3)

{
  BIO_METHOD *type;
  BIO *b;
  int iVar1;
  int iVar2;
  long lVar3;
  undefined auStack_424 [1024];
  int local_24;
  
  local_24 = __TMC_END__;
  type = BIO_s_mem();
  b = BIO_new(type);
  if (b == (BIO *)0x0) {
    lVar3 = -1;
  }
  else {
    do {
      iVar2 = param_2;
      if (param_2 == -1 || 0x3ff < param_2) {
        iVar2 = 0x400;
      }
      iVar2 = BIO_read(param_3,auStack_424,iVar2);
      if (iVar2 < 1) break;
      iVar1 = BIO_write(b,auStack_424,iVar2);
      if (iVar1 != iVar2) {
        BIO_free(b);
        lVar3 = -1;
        goto LAB_00035634;
      }
      param_2 = param_2 - iVar1;
    } while (param_2 != 0);
    lVar3 = BIO_ctrl(b,3,0,param_1);
    BIO_set_flags(b,0x200);
    BIO_free(b);
  }
LAB_00035634:
  if (local_24 != __TMC_END__) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(lVar3);
  }
  return;
}

