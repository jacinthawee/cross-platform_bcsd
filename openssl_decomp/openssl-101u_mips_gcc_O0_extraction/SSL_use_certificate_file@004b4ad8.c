
int SSL_use_certificate_file(SSL *ssl,char *file,int type)

{
  undefined4 uVar1;
  int iVar2;
  int iVar3;
  undefined4 uVar4;
  int iVar5;
  
  uVar1 = (*(code *)PTR_BIO_s_file_006a6ea0)();
  iVar2 = (*(code *)PTR_BIO_new_006a6ea4)(uVar1);
  if (iVar2 == 0) {
    (*(code *)PTR_ERR_put_error_006a7f34)(0x14,200,7,&DAT_00649450,0x5c);
    return 0;
  }
  iVar3 = (*(code *)PTR_BIO_ctrl_006a6e18)(iVar2,0x6c,3,file);
  if (iVar3 < 1) {
    uVar4 = 2;
    uVar1 = 0x61;
LAB_004b4b70:
    (*(code *)PTR_ERR_put_error_006a7f34)(0x14,200,uVar4,&DAT_00649450,uVar1);
  }
  else {
    if (type == 2) {
      iVar3 = (*(code *)PTR_d2i_X509_bio_006a7b74)(iVar2,0);
      uVar1 = 0xd;
    }
    else {
      if (type != 1) {
        uVar4 = 0x7c;
        uVar1 = 0x6c;
        goto LAB_004b4b70;
      }
      iVar3 = (*(code *)PTR_PEM_read_bio_X509_006a6fcc)
                        (iVar2,0,*(undefined4 *)(ssl->psk_server_callback + 0x6c),
                         *(undefined4 *)(ssl->psk_server_callback + 0x70));
      uVar1 = 9;
    }
    if (iVar3 != 0) {
      iVar5 = ssl_cert_inst(&ssl->cert);
      if (iVar5 == 0) {
        iVar5 = 0;
        (*(code *)PTR_ERR_put_error_006a7f34)(0x14,0xc6,0x41,&DAT_00649450,0x4c);
      }
      else {
        iVar5 = ssl_set_cert(ssl->cert,iVar3);
      }
      (*(code *)PTR_X509_free_006a6e90)(iVar3);
      goto LAB_004b4b88;
    }
    (*(code *)PTR_ERR_put_error_006a7f34)(0x14,200,uVar1,&DAT_00649450,0x71);
  }
  iVar5 = 0;
LAB_004b4b88:
  (*(code *)PTR_BIO_free_006a6e70)(iVar2);
  return iVar5;
}

