
BIO * BIO_push(BIO *b,BIO *append)

{
  BIO *pBVar1;
  long lVar2;
  _func_603 *p_Var3;
  BIO *pBVar4;
  _func_599 *p_Var5;
  
  pBVar1 = b;
  if (b == (BIO *)0x0) {
    return append;
  }
  do {
    pBVar4 = pBVar1;
    pBVar1 = pBVar4->next_bio;
  } while (pBVar4->next_bio != (bio_st *)0x0);
  pBVar4->next_bio = append;
  if (append != (BIO *)0x0) {
    append->prev_bio = pBVar4;
  }
  if ((b->method != (BIO_METHOD *)0x0) && (p_Var5 = b->method->ctrl, p_Var5 != (_func_599 *)0x0)) {
    p_Var3 = b->callback;
    if (p_Var3 == (_func_603 *)0x0) {
      (*p_Var5)(b,6,0,pBVar4);
    }
    else {
      lVar2 = (*p_Var3)(b,6,(char *)pBVar4,6,0,1);
      if (0 < lVar2) {
        lVar2 = (*b->method->ctrl)(b,6,0,pBVar4);
        (*p_Var3)(b,0x86,(char *)pBVar4,6,0,lVar2);
        return b;
      }
    }
    return b;
  }
  ERR_put_error(0x20,0x67,0x79,"bio_lib.c",0x168);
  return b;
}

