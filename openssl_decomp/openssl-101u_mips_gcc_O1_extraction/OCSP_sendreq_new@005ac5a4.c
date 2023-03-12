
OCSP_REQ_CTX * OCSP_sendreq_new(BIO *io,char *path,OCSP_REQUEST *req,int maxline)

{
  undefined *puVar1;
  undefined4 *puVar2;
  undefined4 uVar3;
  int iVar4;
  
  puVar2 = (undefined4 *)(*(code *)PTR_CRYPTO_malloc_006a7008)(0x18,"ocsp_ht.c",0x9f);
  puVar1 = PTR_BIO_s_mem_006a7c18;
  if (puVar2 == (undefined4 *)0x0) {
    return (OCSP_REQ_CTX *)0x0;
  }
  *puVar2 = 0x1000;
  uVar3 = (*(code *)puVar1)();
  uVar3 = (*(code *)PTR_BIO_new_006a6ea4)(uVar3);
  iVar4 = 0x1000;
  if (0 < maxline) {
    iVar4 = maxline;
  }
  puVar2[4] = uVar3;
  puVar2[3] = io;
  puVar2[5] = 0;
  puVar1 = PTR_CRYPTO_malloc_006a7008;
  puVar2[2] = iVar4;
  iVar4 = (*(code *)puVar1)(iVar4,"ocsp_ht.c",0xaa);
  puVar2[1] = iVar4;
  if (puVar2[4] == 0) goto LAB_005ac760;
  if (iVar4 == 0) {
LAB_005ac750:
    (*(code *)PTR_BIO_free_006a6e70)();
  }
  else {
    if (path == (char *)0x0) {
      path = "/";
    }
    iVar4 = (*(code *)PTR_BIO_printf_006a6e38)(puVar2[4],"POST %s HTTP/1.0\r\n",path);
    if (0 < iVar4) {
      if (req == (OCSP_REQUEST *)0x0) {
        return (OCSP_REQ_CTX *)puVar2;
      }
      uVar3 = puVar2[4];
      iVar4 = i2d_OCSP_REQUEST(req,(uchar **)0x0);
      iVar4 = (*(code *)PTR_BIO_printf_006a6e38)
                        (uVar3,
                         "Content-Type: application/ocsp-request\r\nContent-Length: %d\r\n\r\n",
                         iVar4);
      if ((0 < iVar4) &&
         (iVar4 = (*(code *)PTR_ASN1_i2d_bio_006a7198)(PTR_i2d_OCSP_REQUEST_006a7dc8,puVar2[4],req),
         puVar1 = PTR_BIO_ctrl_006a6e18, 0 < iVar4)) {
        *puVar2 = 0x1006;
        uVar3 = (*(code *)puVar1)(puVar2[4],3,0,0);
        puVar2[5] = uVar3;
        return (OCSP_REQ_CTX *)puVar2;
      }
    }
    if (puVar2[4] != 0) goto LAB_005ac750;
  }
  iVar4 = puVar2[1];
LAB_005ac760:
  if (iVar4 != 0) {
    (*(code *)PTR_CRYPTO_free_006a6e88)();
  }
  (*(code *)PTR_CRYPTO_free_006a6e88)(puVar2);
  return (OCSP_REQ_CTX *)0x0;
}

