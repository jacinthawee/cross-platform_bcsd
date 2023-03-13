
OCSP_REQ_CTX * OCSP_sendreq_new(BIO *io,char *path,OCSP_REQUEST *req,int maxline)

{
  undefined4 *ptr;
  BIO_METHOD *type;
  BIO *pBVar1;
  void *pvVar2;
  int iVar3;
  long lVar4;
  
  ptr = (undefined4 *)CRYPTO_malloc(0x18,"ocsp_ht.c",0x9f);
  if (ptr == (undefined4 *)0x0) {
    return (OCSP_REQ_CTX *)0x0;
  }
  *ptr = 0x1000;
  type = BIO_s_mem();
  pBVar1 = BIO_new(type);
  ptr[4] = pBVar1;
  ptr[5] = 0;
  ptr[3] = io;
  if (maxline < 1) {
    maxline = 0x1000;
  }
  ptr[2] = maxline;
  pvVar2 = CRYPTO_malloc(maxline,"ocsp_ht.c",0xaa);
  ptr[1] = pvVar2;
  pBVar1 = (BIO *)ptr[4];
  if ((pvVar2 != (void *)0x0) && (pBVar1 != (BIO *)0x0)) {
    if (path == (char *)0x0) {
      path = "/";
    }
    iVar3 = BIO_printf(pBVar1,"POST %s HTTP/1.0\r\n",path);
    if (0 < iVar3) {
      if (req == (OCSP_REQUEST *)0x0) {
        return (OCSP_REQ_CTX *)ptr;
      }
      iVar3 = i2d_OCSP_REQUEST(req,(uchar **)0x0);
      iVar3 = BIO_printf((BIO *)ptr[4],
                         "Content-Type: application/ocsp-request\r\nContent-Length: %d\r\n\r\n",
                         iVar3);
      if ((0 < iVar3) &&
         (iVar3 = ASN1_i2d_bio(i2d_OCSP_REQUEST,(BIO *)ptr[4],(uchar *)req), 0 < iVar3)) {
        *ptr = 0x1006;
        lVar4 = BIO_ctrl((BIO *)ptr[4],3,0,(void *)0x0);
        ptr[5] = lVar4;
        return (OCSP_REQ_CTX *)ptr;
      }
    }
    pBVar1 = (BIO *)ptr[4];
  }
  if (pBVar1 != (BIO *)0x0) {
    BIO_free(pBVar1);
  }
  if ((void *)ptr[1] != (void *)0x0) {
    CRYPTO_free((void *)ptr[1]);
  }
  CRYPTO_free(ptr);
  return (OCSP_REQ_CTX *)0x0;
}

