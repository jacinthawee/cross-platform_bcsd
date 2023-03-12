
int SSL_CTX_use_certificate_ASN1(SSL_CTX *ctx,int len,uchar *d)

{
  int iVar1;
  int iVar2;
  uchar *local_res8 [2];
  
  local_res8[0] = d;
  iVar1 = (*(code *)PTR_d2i_X509_006a7fe0)(0,local_res8,len);
  if (iVar1 != 0) {
    iVar2 = ssl_cert_inst(&ctx->cert);
    if (iVar2 == 0) {
      (*(code *)PTR_ERR_put_error_006a7f34)(0x14,0xab,0x41,&DAT_00649450,0x174);
    }
    else {
      iVar2 = ssl_set_cert(ctx->cert,iVar1);
    }
    (*(code *)PTR_X509_free_006a6e90)(iVar1);
    return iVar2;
  }
  (*(code *)PTR_ERR_put_error_006a7f34)(0x14,0xac,0xd,&DAT_00649450,0x1ec);
  return 0;
}

