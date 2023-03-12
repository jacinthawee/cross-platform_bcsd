
BIO * BIO_pop(BIO *b)

{
  _func_599 *p_Var1;
  _func_603 *p_Var2;
  bio_st *pbVar3;
  long lVar4;
  BIO *pBVar5;
  
  if (b == (BIO *)0x0) {
    pBVar5 = (BIO *)0x0;
  }
  else {
    pBVar5 = b->next_bio;
    if ((b->method == (BIO_METHOD *)0x0) || (p_Var1 = b->method->ctrl, p_Var1 == (_func_599 *)0x0))
    {
      ERR_put_error(0x20,0x67,0x79,"bio_lib.c",0x168);
    }
    else {
      p_Var2 = b->callback;
      if (p_Var2 == (_func_603 *)0x0) {
        (*p_Var1)(b,7,0,b);
      }
      else {
        lVar4 = (*p_Var2)(b,6,(char *)b,7,0,1);
        if (0 < lVar4) {
          lVar4 = (*b->method->ctrl)(b,7,0,b);
          (*p_Var2)(b,0x86,(char *)b,7,0,lVar4);
        }
      }
    }
    pbVar3 = b->prev_bio;
    if (pbVar3 != (bio_st *)0x0) {
      pbVar3->next_bio = b->next_bio;
    }
    if (b->next_bio != (bio_st *)0x0) {
      b->next_bio->prev_bio = pbVar3;
    }
    b->next_bio = (bio_st *)0x0;
    b->prev_bio = (bio_st *)0x0;
  }
  return pBVar5;
}

