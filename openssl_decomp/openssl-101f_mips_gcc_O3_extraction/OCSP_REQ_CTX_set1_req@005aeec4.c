
int OCSP_REQ_CTX_set1_req(OCSP_REQ_CTX *rctx,OCSP_REQUEST *req)

{
  undefined *puVar1;
  int iVar2;
  undefined4 uVar3;
  
  uVar3 = *(undefined4 *)(rctx + 0x10);
  iVar2 = i2d_OCSP_REQUEST(req,(uchar **)0x0);
  iVar2 = (*(code *)PTR_BIO_printf_006a7f38)
                    (uVar3,"Content-Type: application/ocsp-request\r\nContent-Length: %d\r\n\r\n",
                     iVar2);
  if (0 < iVar2) {
    iVar2 = (*(code *)PTR_ASN1_i2d_bio_006a8298)
                      (PTR_i2d_OCSP_REQUEST_006a8eb8,*(undefined4 *)(rctx + 0x10),req);
    puVar1 = PTR_BIO_ctrl_006a7f18;
    if (0 < iVar2) {
      *(undefined4 *)rctx = 0x1006;
      uVar3 = (*(code *)puVar1)(*(undefined4 *)(rctx + 0x10),3,0,0);
      *(undefined4 *)(rctx + 0x14) = uVar3;
      return 1;
    }
  }
  return 0;
}

