
void lh_stats(_LHASH *lh,FILE *out)

{
  BIO_METHOD *type;
  BIO *bp;
  
  type = BIO_s_file();
  bp = BIO_new(type);
  if (bp != (BIO *)0x0) {
    BIO_ctrl(bp,0x6a,0,out);
    lh_stats_bio(lh,bp);
    BIO_free(bp);
    return;
  }
  return;
}

