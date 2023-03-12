
int CMS_final(CMS_ContentInfo *cms,BIO *data,BIO *dcont,uint flags)

{
  BIO *out;
  int iVar1;
  BIO *pBVar2;
  int iVar3;
  
  out = CMS_dataInit(cms,dcont);
  if (out != (BIO *)0x0) {
    SMIME_crlf_copy(data,out,flags);
    BIO_ctrl(out,0xb,0,(void *)0x0);
    iVar1 = CMS_dataFinal(cms,out);
    iVar3 = 1;
    if (iVar1 == 0) {
      ERR_put_error(0x2e,0x7f,0x67,"cms_smime.c",0x2d6);
      iVar3 = iVar1;
    }
    if (dcont == (BIO *)0x0) {
      BIO_free_all(out);
    }
    else {
      do {
        pBVar2 = BIO_pop(out);
        BIO_free(out);
        out = pBVar2;
      } while (dcont != pBVar2 && pBVar2 != (BIO *)0x0);
    }
    return iVar3;
  }
  ERR_put_error(0x2e,0x7f,0x68,"cms_smime.c",0x2cd);
  return 0;
}

