
int BIO_indent(BIO *b,int indent,int max)

{
  long lVar1;
  int iVar2;
  int reason;
  _func_603 *p_Var3;
  
  if (indent < 0) {
    indent = 0;
  }
  if (max <= indent) {
    indent = max;
  }
  do {
    if (indent == 0) {
      return 1;
    }
    if (((b == (BIO *)0x0) || (b->method == (BIO_METHOD *)0x0)) ||
       (b->method->bputs == (_func_597 *)0x0)) {
      reason = 0x79;
      iVar2 = 0x108;
LAB_00521008:
      ERR_put_error(0x20,0x6e,reason,"bio_lib.c",iVar2);
      return 0;
    }
    p_Var3 = b->callback;
    if ((p_Var3 != (_func_603 *)0x0) &&
       (lVar1 = (*p_Var3)(b,4,(char *)&DAT_0063f0b8,0,0,1), lVar1 < 1)) {
      return 0;
    }
    if (b->init == 0) {
      reason = 0x78;
      iVar2 = 0x114;
      goto LAB_00521008;
    }
    iVar2 = (*b->method->bputs)(b,(char *)&DAT_0063f0b8);
    if (0 < iVar2) {
      b->num_write = b->num_write + iVar2;
    }
    if (p_Var3 != (_func_603 *)0x0) {
      iVar2 = (*p_Var3)(b,0x84,(char *)&DAT_0063f0b8,0,0,iVar2);
    }
    indent = indent + -1;
    if (iVar2 != 1) {
      return 0;
    }
  } while( true );
}

