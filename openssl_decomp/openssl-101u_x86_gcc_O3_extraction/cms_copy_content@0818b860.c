
undefined4 __regparm3 cms_copy_content(BIO *param_1,BIO *param_2,uint param_3)

{
  int iVar1;
  int iVar2;
  BIO_METHOD *pBVar3;
  BIO *bp;
  long lVar4;
  undefined4 uVar5;
  int in_GS_OFFSET;
  bool bVar6;
  undefined local_1020 [4096];
  int local_20;
  
  local_20 = *(int *)(in_GS_OFFSET + 0x14);
  if (param_1 == (BIO *)0x0) {
    pBVar3 = BIO_s_null();
    bp = BIO_new(pBVar3);
LAB_0818b962:
    if (bp == (BIO *)0x0) {
      uVar5 = 0;
      ERR_put_error(0x2e,0x6b,0x41,"cms_smime.c",0x4e);
      goto LAB_0818b8d9;
    }
    bVar6 = bp != param_1;
  }
  else {
    bVar6 = false;
    bp = param_1;
    if ((param_3 & 1) != 0) {
      pBVar3 = BIO_s_mem();
      bp = BIO_new(pBVar3);
      BIO_ctrl(bp,0x82,0,(void *)0x0);
      goto LAB_0818b962;
    }
  }
  do {
    iVar1 = BIO_read(param_2,local_1020,0x1000);
    if (iVar1 < 1) {
      iVar2 = BIO_method_type(param_2);
      if (((iVar2 != 0x20a) || (lVar4 = BIO_ctrl(param_2,0x71,0,(void *)0x0), lVar4 != 0)) &&
         (iVar1 == 0)) {
        if (((param_3 & 1) == 0) || (iVar1 = SMIME_text(bp,param_1), iVar1 != 0)) {
          uVar5 = 1;
          goto joined_r0x0818b92c;
        }
        ERR_put_error(0x2e,0x6b,0x8c,"cms_smime.c",0x65);
      }
      break;
    }
    iVar2 = BIO_write(bp,local_1020,iVar1);
  } while (iVar1 == iVar2);
  uVar5 = 0;
joined_r0x0818b92c:
  if (bVar6) {
    BIO_free(bp);
  }
LAB_0818b8d9:
  if (local_20 == *(int *)(in_GS_OFFSET + 0x14)) {
    return uVar5;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}

