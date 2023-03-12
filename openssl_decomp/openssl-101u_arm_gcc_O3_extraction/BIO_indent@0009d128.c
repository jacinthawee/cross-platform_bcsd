
int BIO_indent(BIO *b,int indent,int max)

{
  long lVar1;
  int iVar2;
  _func_597 *p_Var3;
  _func_603 *p_Var4;
  uint uVar5;
  
  uVar5 = indent & ~(indent >> 0x1f);
  if (max <= (int)uVar5) {
    uVar5 = max;
  }
  do {
    if (uVar5 == 0) {
      return 1;
    }
    if (((b == (BIO *)0x0) || (b->method == (BIO_METHOD *)0x0)) ||
       (b->method->bputs == (_func_597 *)0x0)) {
      ERR_put_error(0x20,0x6e,0x79,"bio_lib.c",0x103);
      return 0;
    }
    p_Var4 = b->callback;
    if ((p_Var4 != (_func_603 *)0x0) && (lVar1 = (*p_Var4)(b,4," ",0,0,1), lVar1 < 1)) {
      return 0;
    }
    if (b->init == 0) {
      ERR_put_error(0x20,0x6e,0x78,"bio_lib.c",0x10d);
      return 0;
    }
    p_Var3 = b->method->bputs;
    iVar2 = (*p_Var3)(b," ");
    if (0 < iVar2) {
      p_Var3 = (_func_597 *)(b->num_write + iVar2);
    }
    if (0 < iVar2) {
      b->num_write = (ulong)p_Var3;
    }
    if (p_Var4 != (_func_603 *)0x0) {
      iVar2 = (*p_Var4)(b,0x84," ",0,0,iVar2);
    }
    uVar5 = uVar5 - 1;
  } while (iVar2 == 1);
  return 0;
}

