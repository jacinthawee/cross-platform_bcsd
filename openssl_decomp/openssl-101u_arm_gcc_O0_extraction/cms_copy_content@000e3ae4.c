
void cms_copy_content(BIO *param_1,BIO *param_2,uint param_3)

{
  BIO *bp;
  BIO *pBVar1;
  int iVar2;
  BIO_METHOD *pBVar3;
  long lVar4;
  BIO *in;
  uint uVar5;
  undefined auStack_1024 [4096];
  int local_24;
  
  local_24 = __stack_chk_guard;
  if (param_1 == (BIO *)0x0) {
    pBVar3 = BIO_s_null();
    bp = BIO_new(pBVar3);
LAB_000e3b88:
    if (bp == (BIO *)0x0) {
      ERR_put_error(0x2e,0x6b,0x41,"cms_smime.c",0x4e);
      goto LAB_000e3b40;
    }
    uVar5 = (int)bp - (int)param_1;
    in = bp;
    if (uVar5 != 0) {
      uVar5 = 1;
    }
  }
  else {
    uVar5 = param_3 & 1;
    in = param_1;
    if (uVar5 != 0) {
      pBVar3 = BIO_s_mem();
      bp = BIO_new(pBVar3);
      BIO_ctrl(bp,0x82,0,(void *)0x0);
      goto LAB_000e3b88;
    }
  }
  do {
    bp = (BIO *)BIO_read(param_2,auStack_1024,0x1000);
    if ((int)bp < 1) {
      iVar2 = BIO_method_type(param_2);
      if (((iVar2 != 0x20a) || (lVar4 = BIO_ctrl(param_2,0x71,0,(void *)0x0), lVar4 != 0)) &&
         (bp == (BIO *)0x0)) {
        if (((int)(param_3 << 0x1f) < 0) && (iVar2 = SMIME_text(in,param_1), iVar2 == 0)) {
          ERR_put_error(0x2e,0x6b,0x8c,"cms_smime.c",0x65);
        }
        else {
          bp = (BIO *)0x1;
        }
        goto LAB_000e3b34;
      }
      break;
    }
    pBVar1 = (BIO *)BIO_write(in,auStack_1024,(int)bp);
  } while (bp == pBVar1);
  bp = (BIO *)0x0;
LAB_000e3b34:
  if (uVar5 != 0) {
    BIO_free(in);
  }
LAB_000e3b40:
  if (local_24 == __stack_chk_guard) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail(bp);
}

