
int SSL_use_certificate_ASN1(SSL *ssl,uchar *d,int len)

{
  int iVar1;
  int iVar2;
  uchar *local_res4 [3];
  
  local_res4[0] = d;
  iVar1 = (*(code *)PTR_d2i_X509_006a7fe0)(0,local_res4);
  if (iVar1 != 0) {
    iVar2 = ssl_cert_inst(&ssl->cert);
    if (iVar2 == 0) {
      (*(code *)PTR_ERR_put_error_006a7f34)(0x14,0xc6,0x41,&DAT_00649450,0x4c);
    }
    else {
      iVar2 = ssl_set_cert(ssl->cert,iVar1);
    }
    (*(code *)PTR_X509_free_006a6e90)(iVar1);
    return iVar2;
  }
  (*(code *)PTR_ERR_put_error_006a7f34)(0x14,199,0xd,&DAT_00649450,0x86);
  return 0;
}
