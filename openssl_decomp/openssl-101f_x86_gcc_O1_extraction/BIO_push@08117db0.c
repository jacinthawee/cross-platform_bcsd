
BIO * BIO_push(BIO *b,BIO *append)

{
  _func_599 *p_Var1;
  _func_603 *p_Var2;
  BIO *pBVar3;
  long lVar4;
  BIO *pBVar5;
  
  pBVar3 = b;
  if (b != (BIO *)0x0) {
    do {
      pBVar5 = pBVar3;
      pBVar3 = pBVar5->next_bio;
    } while (pBVar5->next_bio != (bio_st *)0x0);
    pBVar5->next_bio = append;
    if (append != (BIO *)0x0) {
      append->prev_bio = pBVar5;
    }
    append = b;
    if ((b->method == (BIO_METHOD *)0x0) || (p_Var1 = b->method->ctrl, p_Var1 == (_func_599 *)0x0))
    {
      ERR_put_error(0x20,0x67,0x79,"bio_lib.c",0x168);
    }
    else {
      p_Var2 = b->callback;
      if (p_Var2 == (_func_603 *)0x0) {
        (*p_Var1)(b,6,0,pBVar5);
        return b;
      }
      lVar4 = (*p_Var2)(b,6,(char *)pBVar5,6,0,1);
      if (0 < lVar4) {
        lVar4 = (*b->method->ctrl)(b,6,0,pBVar5);
        (*p_Var2)(b,0x86,(char *)pBVar5,6,0,lVar4);
      }
    }
  }
  return append;
}

