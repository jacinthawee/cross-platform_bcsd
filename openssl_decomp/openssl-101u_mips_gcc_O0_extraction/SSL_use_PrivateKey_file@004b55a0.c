
int SSL_use_PrivateKey_file(SSL *ssl,char *file,int type)

{
  undefined4 uVar1;
  int iVar2;
  int iVar3;
  undefined4 uVar4;
  int iVar5;
  
  uVar1 = (*(code *)PTR_BIO_s_file_006a6ea0)();
  iVar2 = (*(code *)PTR_BIO_new_006a6ea4)(uVar1);
  if (iVar2 == 0) {
    (*(code *)PTR_ERR_put_error_006a7f34)(0x14,0xcb,7,&DAT_00649450,0x139);
    return 0;
  }
  iVar3 = (*(code *)PTR_BIO_ctrl_006a6e18)(iVar2,0x6c,3,file);
  if (iVar3 < 1) {
    uVar4 = 2;
    uVar1 = 0x13e;
LAB_004b5638:
    iVar5 = 0;
    (*(code *)PTR_ERR_put_error_006a7f34)(0x14,0xcb,uVar4,&DAT_00649450,uVar1);
  }
  else {
    if (type == 1) {
      iVar3 = (*(code *)PTR_PEM_read_bio_PrivateKey_006a7b8c)
                        (iVar2,0,*(undefined4 *)(ssl->psk_server_callback + 0x6c),
                         *(undefined4 *)(ssl->psk_server_callback + 0x70));
      uVar1 = 9;
    }
    else {
      if (type != 2) {
        uVar4 = 0x7c;
        uVar1 = 0x14b;
        goto LAB_004b5638;
      }
      iVar3 = (*(code *)PTR_d2i_PrivateKey_bio_006a7b88)(iVar2,0);
      uVar1 = 0xd;
    }
    if (iVar3 == 0) {
      iVar5 = 0;
      (*(code *)PTR_ERR_put_error_006a7f34)(0x14,0xcb,uVar1,&DAT_00649450,0x14f);
    }
    else {
      iVar5 = ssl_cert_inst(&ssl->cert);
      if (iVar5 == 0) {
        iVar5 = 0;
        (*(code *)PTR_ERR_put_error_006a7f34)(0x14,0xc9,0x41,&DAT_00649450,0x129);
      }
      else {
        iVar5 = ssl_set_pkey(ssl->cert,iVar3);
      }
      (*(code *)PTR_EVP_PKEY_free_006a6e78)(iVar3);
    }
  }
  (*(code *)PTR_BIO_free_006a6e70)(iVar2);
  return iVar5;
}

