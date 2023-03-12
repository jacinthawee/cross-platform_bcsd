
BIO * BIO_pop(BIO *b)

{
  long lVar1;
  bio_st *pbVar2;
  BIO *pBVar3;
  _func_603 *p_Var4;
  _func_599 *p_Var5;
  
  if (b != (BIO *)0x0) {
    pBVar3 = b->next_bio;
    if ((b->method == (BIO_METHOD *)0x0) || (p_Var5 = b->method->ctrl, p_Var5 == (_func_599 *)0x0))
    {
      ERR_put_error(0x20,0x67,0x79,"bio_lib.c",0x168);
      pbVar2 = b->prev_bio;
    }
    else {
      p_Var4 = b->callback;
      if (p_Var4 == (_func_603 *)0x0) {
        (*p_Var5)(b,7,0,b);
        pbVar2 = b->prev_bio;
      }
      else {
        lVar1 = (*p_Var4)(b,6,(char *)b,7,0,1);
        if (0 < lVar1) {
          lVar1 = (*b->method->ctrl)(b,7,0,b);
          (*p_Var4)(b,0x86,(char *)b,7,0,lVar1);
        }
        pbVar2 = b->prev_bio;
      }
    }
    if (pbVar2 != (bio_st *)0x0) {
      pbVar2->next_bio = b->next_bio;
    }
    if (b->next_bio != (bio_st *)0x0) {
      b->next_bio->prev_bio = pbVar2;
    }
    b->next_bio = (bio_st *)0x0;
    b->prev_bio = (bio_st *)0x0;
    return pBVar3;
  }
  return (BIO *)0x0;
}

