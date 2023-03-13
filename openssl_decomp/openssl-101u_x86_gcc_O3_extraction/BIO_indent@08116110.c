
int BIO_indent(BIO *b,int indent,int max)

{
  _func_603 *p_Var1;
  long lVar2;
  int iVar3;
  
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
      ERR_put_error(0x20,0x6e,0x79,"bio_lib.c",0x103);
      return 0;
    }
    p_Var1 = b->callback;
    if ((p_Var1 != (_func_603 *)0x0) && (lVar2 = (*p_Var1)(b,4," ",0,0,1), lVar2 < 1)) {
      return 0;
    }
    if (b->init == 0) {
      ERR_put_error(0x20,0x6e,0x78,"bio_lib.c",0x10d);
      return 0;
    }
    iVar3 = (*b->method->bputs)(b," ");
    if (0 < iVar3) {
      b->num_write = b->num_write + iVar3;
    }
    if (p_Var1 != (_func_603 *)0x0) {
      iVar3 = (*p_Var1)(b,0x84," ",0,0,iVar3);
    }
    indent = indent + -1;
  } while (iVar3 == 1);
  return 0;
}

