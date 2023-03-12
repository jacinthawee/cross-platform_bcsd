
int OCSP_REQ_CTX_set1_req(OCSP_REQ_CTX *rctx,OCSP_REQUEST *req)

{
  int iVar1;
  long lVar2;
  BIO *bio;
  
  bio = *(BIO **)(rctx + 0x10);
  iVar1 = i2d_OCSP_REQUEST(req,(uchar **)0x0);
  iVar1 = BIO_printf(bio,"Content-Type: application/ocsp-request\r\nContent-Length: %d\r\n\r\n",
                     iVar1);
  if ((0 < iVar1) &&
     (iVar1 = ASN1_i2d_bio((undefined1 *)0xdf159,*(BIO **)(rctx + 0x10),(uchar *)req), 0 < iVar1)) {
    *(undefined4 *)rctx = 0x1006;
    lVar2 = BIO_ctrl(*(BIO **)(rctx + 0x10),3,0,(void *)0x0);
    *(long *)(rctx + 0x14) = lVar2;
    return 1;
  }
  return 0;
}

