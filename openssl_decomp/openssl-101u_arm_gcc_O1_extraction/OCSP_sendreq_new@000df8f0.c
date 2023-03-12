
OCSP_REQ_CTX * OCSP_sendreq_new(BIO *io,char *path,OCSP_REQUEST *req,int maxline)

{
  undefined4 *ptr;
  BIO_METHOD *type;
  BIO *pBVar1;
  void *ptr_00;
  int iVar2;
  long lVar3;
  char *pcVar4;
  
  ptr = (undefined4 *)CRYPTO_malloc(0x18,"ocsp_ht.c",0x9f);
  if (ptr == (undefined4 *)0x0) {
    return (OCSP_REQ_CTX *)0x0;
  }
  *ptr = 0x1000;
  type = BIO_s_mem();
  pBVar1 = BIO_new(type);
  if (maxline < 1) {
    maxline = 0x1000;
  }
  ptr[2] = maxline;
  ptr[3] = io;
  ptr[5] = 0;
  ptr[4] = pBVar1;
  ptr_00 = CRYPTO_malloc(maxline,"ocsp_ht.c",0xaa);
  pBVar1 = (BIO *)ptr[4];
  ptr[1] = ptr_00;
  if (pBVar1 == (BIO *)0x0) goto LAB_000df9ce;
  if (ptr_00 == (void *)0x0) {
LAB_000df9c6:
    BIO_free(pBVar1);
  }
  else {
    pcVar4 = "/";
    if (path != (char *)0x0) {
      pcVar4 = path;
    }
    iVar2 = BIO_printf(pBVar1,PTR_post_hdr_16829_000df9e4,pcVar4);
    if (0 < iVar2) {
      if (req == (OCSP_REQUEST *)0x0) {
        return (OCSP_REQ_CTX *)ptr;
      }
      pBVar1 = (BIO *)ptr[4];
      iVar2 = i2d_OCSP_REQUEST(req,(uchar **)0x0);
      iVar2 = BIO_printf(pBVar1,
                         "Content-Type: application/ocsp-request\r\nContent-Length: %d\r\n\r\n",
                         iVar2);
      if ((0 < iVar2) &&
         (iVar2 = ASN1_i2d_bio((undefined1 *)0xdf159,(BIO *)ptr[4],(uchar *)req), 0 < iVar2)) {
        *ptr = 0x1006;
        lVar3 = BIO_ctrl((BIO *)ptr[4],3,0,(void *)0x0);
        ptr[5] = lVar3;
        return (OCSP_REQ_CTX *)ptr;
      }
    }
    pBVar1 = (BIO *)ptr[4];
    if (pBVar1 != (BIO *)0x0) goto LAB_000df9c6;
  }
  ptr_00 = (void *)ptr[1];
LAB_000df9ce:
  if (ptr_00 != (void *)0x0) {
    CRYPTO_free(ptr_00);
  }
  CRYPTO_free(ptr);
  return (OCSP_REQ_CTX *)0x0;
}

