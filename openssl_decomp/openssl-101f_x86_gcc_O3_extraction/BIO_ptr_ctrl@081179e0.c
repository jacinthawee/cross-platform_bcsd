
char * BIO_ptr_ctrl(BIO *bp,int cmd,long larg)

{
  _func_599 *p_Var1;
  _func_603 *p_Var2;
  long lVar3;
  int iVar4;
  char *pcVar5;
  int in_GS_OFFSET;
  char *local_24;
  int local_20;
  
  local_20 = *(int *)(in_GS_OFFSET + 0x14);
  local_24 = (char *)0x0;
  if (bp != (BIO *)0x0) {
    if ((bp->method == (BIO_METHOD *)0x0) || (p_Var1 = bp->method->ctrl, p_Var1 == (_func_599 *)0x0)
       ) {
      ERR_put_error(0x20,0x67,0x79,"bio_lib.c",0x168);
    }
    else {
      p_Var2 = bp->callback;
      if (p_Var2 == (_func_603 *)0x0) {
        iVar4 = (*p_Var1)(bp,cmd,larg,&local_24);
      }
      else {
        lVar3 = (*p_Var2)(bp,6,(char *)&local_24,cmd,larg,1);
        if (lVar3 < 1) goto LAB_08117aa0;
        lVar3 = (*bp->method->ctrl)(bp,cmd,larg,&local_24);
        iVar4 = (*p_Var2)(bp,0x86,(char *)&local_24,cmd,larg,lVar3);
      }
      pcVar5 = local_24;
      if (0 < iVar4) goto LAB_08117a66;
    }
  }
LAB_08117aa0:
  pcVar5 = (char *)0x0;
LAB_08117a66:
  if (local_20 != *(int *)(in_GS_OFFSET + 0x14)) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return pcVar5;
}

