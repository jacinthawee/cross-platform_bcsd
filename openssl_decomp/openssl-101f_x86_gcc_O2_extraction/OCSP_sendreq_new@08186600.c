
OCSP_REQ_CTX * OCSP_sendreq_new(BIO *io,char *path,OCSP_REQUEST *req,int maxline)

{
  undefined4 *puVar1;
  BIO_METHOD *type;
  BIO *pBVar2;
  void *pvVar3;
  int iVar4;
  long lVar5;
  
  puVar1 = (undefined4 *)CRYPTO_malloc(0x18,"ocsp_ht.c",0xa0);
  *puVar1 = 0x1000;
  type = BIO_s_mem();
  pBVar2 = BIO_new(type);
  puVar1[4] = pBVar2;
  puVar1[5] = 0;
  puVar1[3] = io;
  iVar4 = 0x1000;
  if (0 < maxline) {
    iVar4 = maxline;
  }
  puVar1[2] = iVar4;
  pvVar3 = CRYPTO_malloc(iVar4,"ocsp_ht.c",0xa9);
  puVar1[1] = pvVar3;
  if (pvVar3 != (void *)0x0) {
    if (path == (char *)0x0) {
      path = "/";
    }
    iVar4 = BIO_printf((BIO *)puVar1[4],"POST %s HTTP/1.0\r\n",path);
    if (0 < iVar4) {
      if (req == (OCSP_REQUEST *)0x0) {
        return (OCSP_REQ_CTX *)puVar1;
      }
      iVar4 = i2d_OCSP_REQUEST(req,(uchar **)0x0);
      iVar4 = BIO_printf((BIO *)puVar1[4],
                         "Content-Type: application/ocsp-request\r\nContent-Length: %d\r\n\r\n",
                         iVar4);
      if ((0 < iVar4) &&
         (iVar4 = ASN1_i2d_bio(i2d_OCSP_REQUEST,(BIO *)puVar1[4],(uchar *)req), 0 < iVar4)) {
        *puVar1 = 0x1006;
        lVar5 = BIO_ctrl((BIO *)puVar1[4],3,0,(void *)0x0);
        puVar1[5] = lVar5;
        return (OCSP_REQ_CTX *)puVar1;
      }
    }
  }
  return (OCSP_REQ_CTX *)0x0;
}

