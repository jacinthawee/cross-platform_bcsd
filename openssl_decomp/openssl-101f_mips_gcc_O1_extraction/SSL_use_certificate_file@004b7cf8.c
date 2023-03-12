
int SSL_use_certificate_file(SSL *ssl,char *file,int type)

{
  undefined4 uVar1;
  int iVar2;
  int iVar3;
  undefined4 uVar4;
  int iVar5;
  
  uVar1 = (*(code *)PTR_BIO_s_file_006a7fa0)();
  iVar2 = (*(code *)PTR_BIO_new_006a7fa4)(uVar1);
  if (iVar2 == 0) {
    (*(code *)PTR_ERR_put_error_006a9030)(0x14,200,7,&DAT_00649ed0,0x5f);
    return 0;
  }
  iVar3 = (*(code *)PTR_BIO_ctrl_006a7f18)(iVar2,0x6c,3,file);
  if (iVar3 < 1) {
    uVar4 = 2;
    uVar1 = 0x65;
LAB_004b7d90:
    (*(code *)PTR_ERR_put_error_006a9030)(0x14,200,uVar4,&DAT_00649ed0,uVar1);
  }
  else {
    if (type == 2) {
      iVar3 = (*(code *)PTR_d2i_X509_bio_006a8c60)(iVar2,0);
      uVar1 = 0xd;
    }
    else {
      if (type != 1) {
        uVar4 = 0x7c;
        uVar1 = 0x74;
        goto LAB_004b7d90;
      }
      iVar3 = (*(code *)PTR_PEM_read_bio_X509_006a80cc)
                        (iVar2,0,*(undefined4 *)(ssl->psk_server_callback + 0x6c),
                         *(undefined4 *)(ssl->psk_server_callback + 0x70));
      uVar1 = 9;
    }
    if (iVar3 != 0) {
      iVar5 = ssl_cert_inst(&ssl->cert);
      if (iVar5 == 0) {
        iVar5 = 0;
        (*(code *)PTR_ERR_put_error_006a9030)(0x14,0xc6,0x41,&DAT_00649ed0,0x4e);
      }
      else {
        iVar5 = ssl_set_cert(ssl->cert,iVar3);
      }
      (*(code *)PTR_X509_free_006a7f90)(iVar3);
      goto LAB_004b7da8;
    }
    (*(code *)PTR_ERR_put_error_006a9030)(0x14,200,uVar1,&DAT_00649ed0,0x7a);
  }
  iVar5 = 0;
LAB_004b7da8:
  (*(code *)PTR_BIO_free_006a7f70)(iVar2);
  return iVar5;
}

