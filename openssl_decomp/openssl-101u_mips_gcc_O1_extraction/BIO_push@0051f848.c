
BIO * BIO_push(BIO *b,BIO *append)

{
  bio_st *pbVar1;
  long lVar2;
  BIO *pBVar3;
  _func_603 *p_Var4;
  _func_599 *p_Var5;
  
  pbVar1 = b;
  if (b == (BIO *)0x0) {
    return append;
  }
  do {
    pBVar3 = pbVar1;
    pbVar1 = pBVar3->next_bio;
  } while (pBVar3->next_bio != (bio_st *)0x0);
  pBVar3->next_bio = append;
  if (append != (BIO *)0x0) {
    append->prev_bio = pBVar3;
  }
  if ((b->method != (BIO_METHOD *)0x0) && (p_Var5 = b->method->ctrl, p_Var5 != (_func_599 *)0x0)) {
    p_Var4 = b->callback;
    if (p_Var4 == (_func_603 *)0x0) {
      (*p_Var5)(b,6,0,pBVar3);
    }
    else {
      lVar2 = (*p_Var4)(b,6,(char *)pBVar3,6,0,1);
      if (0 < lVar2) {
        lVar2 = (*b->method->ctrl)(b,6,0,pBVar3);
        (*p_Var4)(b,0x86,(char *)pBVar3,6,0,lVar2);
        return b;
      }
    }
    return b;
  }
  ERR_put_error(0x20,0x67,0x79,"bio_lib.c",0x15d);
  return b;
}

